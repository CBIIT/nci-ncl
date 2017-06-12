<?php

/**
 * @file
 */

function revslider_admin_page() {
  $output = '';
  $output .= '<ul class="action-links"><li>'. l(t('Add new slider'), 'admin/content/revslider/add') .'</li><li>'. l(t('Import slider'), 'admin/content/revslider/import') .'</li></ul>';

  $rows = array();
  $select = db_select('revolution_slides', 's')
    ->fields('s', array('id', 'title', 'changed'))
    ->extend('PagerDefault')
    ->limit(20)
    ->execute();

  while ($rs = $select->fetchObject()) {
    $links = array(
      'items' => array(
        l(t('Edit'), 'admin/content/revslider/' . $rs->id . '/edit'),
        l(t('Delete'), 'admin/content/revslider/' . $rs->id . '/delete'),
        l(t('Clone'), 'admin/content/revslider/' . $rs->id . '/clone'),
        l(t('Export'), 'admin/content/revslider/' . $rs->id . '/export')
      ),
      'attributes' => array('class' => array('links', 'inline'),)
    );
    $rows[] = array($rs->id, l($rs->title, 'admin/content/revslider/'. $rs->id .'/edit'), format_date($rs->changed), theme('item_list', $links));
  }

  $header = array(t('ID'), t('Title'), t('Updated'), t('Operations'));
  if (!empty($rows)) {
    $output .= theme('table', array(
      'header' => $header, 'rows' => $rows
    ));
  }

  return $output;
}

function revslider_admin_edit_form($form, $form_state, $id = NULL) {
  module_load_include('inc', 'revslider', 'revslider.default');

  $path = drupal_get_path('module', 'revslider');
  drupal_add_css($path .'/css/builder.css');
  drupal_add_css($path .'/font-awesome/css/font-awesome.min.css');
  drupal_add_js($path .'/js/media.js');
  drupal_add_js($path .'/js/builder.js');
  drupal_add_js($path .'/js/revslider-settings.js');
  drupal_add_library('system', 'drupal.ajax');
  drupal_add_library('system', 'ui.draggable');
  drupal_add_library('system', 'ui.sortable');
  drupal_add_library('system', 'ui.dialog');
  drupal_add_library('system', 'ui.tooltip');
  drupal_add_library('system', 'ui.slider');
  drupal_add_library('field_group', 'horizontal-tabs');
  drupal_add_library('revslider', 'revslider');

  $values = isset($form_state['input']) ? $form_state['input'] : array();
  $settings = revslider_get_settings();
  drupal_add_js(array('rs' => array(
    'default' => $settings,
  )), 'setting');

  $form = array(
    '#attributes' => array('class' => 'slider-revolution-form'),
  );

  module_load_include('inc', 'media', 'wysiwyg_plugins/media');
  module_load_include('module', 'media_wysiwyg');
  if (function_exists('media_include_browser_js')){
    media_include_browser_js();
  }
  elseif (function_exists('media_wysiwyg_include_browser_js')){
    media_wysiwyg_include_browser_js();
  }
  else{
    $form['#attached']['library'][] = array('media', 'media_browser');
    $form['#attached']['library'][] = array('media', 'media_browser_settings');
  }

  if ($id) {
    $slider = revslider_get_slider($id);
    $slider = array_shift($slider);
    if (!empty($slider)) {
      $values['title']  = $slider->title;
      $values['data']  = $slider->data;
      if ($slider->data) {
        drupal_add_js(array('rs' => array(
          'builder' => drupal_json_decode($slider->data),
        )), 'setting');
      }
    }
  }

  $form['id'] = array(
    '#type' => 'value',
    '#value' => $id,
  );

  $form['info'] = array(
    '#type' => 'fieldset',
    '#title' => t('Basic information'),
    '#collapsible' => TRUE,
    '#collapsed' => $id ? TRUE : FALSE,
  );

  $form['info']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => isset($values['title']) ? $values['title'] : '',
    '#required' => TRUE,
  );

  $form['info']['data'] = array(
    '#type' => 'textarea',
    '#title' => t('Data'),
    '#default_value' => isset($values['data']) ? $values['data'] : '{"name":"","slides":{},"options":{}}',
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Processing form submission
 *
 * @param $form
 * @param $form_state
 */
function revslider_admin_edit_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $slider = revslider_save_slider($values);

  $form_state['redirect'] = 'admin/content/revslider/'. $slider .'/edit';
}

function revslider_render_form($settings = array()) {
  $form = array();
  $childs = element_children($settings);
  if (!empty($childs)) {
    foreach ($childs as $child) {
      // Check if element is form item
      if (isset($settings[$child]['#options']) || isset($settings[$child]['#default_value'])) {
        $form[$child] = revslider_render_form_element($settings[$child], $child);
      } else {
        // Render childrens
        if (is_array($settings[$child])) {
          $deep_childs = element_children($settings[$child]);
          if (!empty($deep_childs)) {
            $form[$child] = array();
            if (isset($settings[$child]['#name'])) {
              $form[$child] = array(
                '#type' => 'fieldset',
                '#title' => $settings[$child]['#name'],
                '#collapsible' => TRUE,
                '#collapsed' => FALSE,
              );
            }
            $form[$child] += revslider_render_form($settings[$child]);
          }
        }
      }

      $form[$child]['#title'] = isset($settings[$child]['#name']) ? $settings[$child]['#name'] : $child;
      $form[$child]['#description'] = isset($settings[$child]['#description']) ? $settings[$child]['#description'] : '';
    }
  }

  return $form;
}

/**
 * Delete form
 */
function revslider_admin_delete_form($form, $form_state, $sid) {
  $form = array();

  $form['slider_id'] = array(
    '#tyle' => 'value',
    '#value' => $sid,
  );

  return confirm_form(
    $form,
    t('Are you sure you want to delete this slider?'),
    'admin/content/revslider',
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Delete form submission
 */
function revslider_admin_delete_form_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    db_delete('revolution_slides')
      ->condition('id', $form['slider_id']['#value'])
      ->execute();
  }
  drupal_set_message('Successed!');
  $form_state['redirect'] = 'admin/content/revslider';
}

/**
 * Render form element
 */
function revslider_render_form_element($element = array(), $key) {
  $form_element = array();
  if (isset($element['#default_value'])) {
    $form_element['#default_value'] = variable_get($key, $element['#default_value']);
    $form_element['#type'] = 'textfield';
  }
  if (isset($element['#options'])) {
    $type = 'select';
    if (isset($element['#type'])) {
      $type = $element['#type'];
    } elseif (count($element['#options']) <=3 ) {
      $type = 'radios';
      $options = $element['#options'];
      foreach ($options as $opt) {
        if (is_array($opt)) {
          $type = 'select';
          break;
        }
      }
    }
    $form_element['#type'] = $type;
    $form_element['#options'] = $element['#options'];
  }
  return $form_element;
}

/**
 * Export slider options
 */
function revslider_admin_export_form($form, $form_state, $sid) {
  $form = array();

  $form['information'] = array(
    '#markup' => t('Select options to export'),
  );

  $form['sid'] = array(
    '#type' => 'value',
    '#value' => $sid,
  );

  $form['files'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include files'),
    '#default_value' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Download')
  );

  return $form;
}

/**
 * Validation
 */
function revslider_admin_export_form_validate($form, &$form_state) {
  $slider = revslider_get_slider($form_state['values']['sid']);
  if (empty($slider)) {
    form_set_error('', 'Somethings wrong or Slider does not exist.');
    return;
  }

  $form_state['slider'] = array_shift($slider);
}

/**
 * Processing export form submission.
 */
function revslider_admin_export_form_submit($form, &$form_state) {
  if (!isset($form_state['slider']) || !isset($form_state['slider']->data)) {
    drupal_set_message('An error occurred when processing.', 'error');
    return;
  }
  $slider = drupal_json_decode($form_state['slider']->data);

  $clean = array('activeSlide', 'activeLayer', 'newLayer', 'newSlide', 'UI', 'attachBehavior', 'uiCleanUp', 'layerType', 'cloneSlide', 'uiCleanUp', 'cloneLayer', 'delSlide', 'delLayer');
  foreach ($clean as $v) {
    if (isset($slider[$v])) {
      unset($slider[$v]);
    }
  }

  $files = array();
  if ($form_state['values']['files']) {
    foreach ($slider['slides']['items'] as $k => $v) {
      if (isset($v['mainImage']['src']) && $v['mainImage']['src'] != '') {
        $key = md5($v['mainImage']['src']);
        $destination = revslider_file_exist($v['mainImage']['src']);
        if ($destination !== FALSE) {
          $files[$key] = $destination;
        }
      }
      if (isset($v['settings']['data-thumb']) && $v['settings']['data-thumb'] != '') {
        $key = md5($v['settings']['data-thumb']);
        $destination = revslider_file_exist($v['settings']['data-thumb']);
        if ($destination !== FALSE) {
          $files[$key] = $destination;
        }
      }
      if (isset($v['mainImage']['data-lazyload']) && $v['mainImage']['data-lazyload'] != '') {
        $key = md5($v['mainImage']['data-lazyload']);
        $destination = revslider_file_exist($v['mainImage']['data-lazyload']);
        if ($destination !== FALSE) {
          $files[$key] = $destination;
        }
      }
      if (!empty($v['layers'])) {
        foreach ($v['layers'] as $i => $j) {
          if ($j['type'] == 'image' && $j['value'] != '') {
            $key = md5($j['value']);
            $destination = revslider_file_exist($j['value']);
            if ($destination !== FALSE) {
              $files[$key] = $destination;
            }
          } else if ($j['type'] == 'video') {
            if ($j['settings']['data-videoposter'] != '') {
              $key = md5($j['settings']['data-videoposter']);
              $destination = revslider_file_exist($j['settings']['data-videoposter']);
              if ($destination !== FALSE) {
                $files[$key] = $destination;
              }
            }
            if ($j['settings']['video-type'] == 'html5') {
              if ($j['settings']['data-videomp4'] != '') {
                $key = md5($j['settings']['data-videomp4']);
                $destination = revslider_file_exist($j['settings']['data-videomp4']);
                if ($destination !== FALSE) {
                  $files[$key] = $destination;
                }
              }
              if ($j['settings']['data-videowebm'] != '') {
                $key = md5($j['settings']['data-videowebm']);
                $destination = revslider_file_exist($j['settings']['data-videowebm']);
                if ($destination !== FALSE) {
                  $files[$key] = $destination;
                }
              }
              if ($j['settings']['data-videoogv'] != '') {
                $key = md5($j['settings']['data-videoogv']);
                $destination = revslider_file_exist($j['settings']['data-videoogv']);
                if ($destination !== FALSE) {
                  $files[$key] = $destination;
                }
              }
            }

          }
        }
      }
    }
  }

  // Compress files
  $file_name = 'temporary://rs-export-slider-'. $form_state['values']['sid'].'.zip';
  $file_name = drupal_realpath($file_name);

  $archiver = new ZipArchive();
  if ($archiver->open($file_name, ZIPARCHIVE::CREATE) !== TRUE) {
    throw new Exception(t('Cannot open %file_path', array('%file_path' => $file_name)));
  }
  $archiver->addFromString('settings.txt', drupal_json_encode($slider));

  if (!empty($files)) {
    $archiver->addEmptyDir('files');
    foreach ($files as $k => $f) {
      $archiver->addFile(drupal_realpath($f), 'files/'.$k);
    }
  }

  $archiver->close();

  $headers['Content-Type'] = mime_content_type($file_name);
  $headers['Content-Length'] = filesize($file_name);
  $headers['Content-Disposition'] = 'attachment; filename="' . urlencode(drupal_basename($file_name)) . '"';
  $headers['Pragma'] = 'no-cache';
  $headers['Expires'] = 0;

  foreach ($headers as $name => $value) {
    drupal_add_http_header($name, $value);
  }
  drupal_send_headers();
  readfile($file_name);
  file_unmanaged_delete($file_name);
  exit;
}

/**
 * @return
 *   Themed import form
 */
function revslider_admin_import_form() {
  $form = array();

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Slider name'),
    '#required' => TRUE,
  );

  $form['url'] = array(
    '#type' => 'textfield',
    '#title' => t('Import from a URL'),
    '#description' => t('For example: %name', array('%name' => url('name.tar.gz', array('absolute' => TRUE)))),
  );

  $form['or'] = array(
    '#prefix' => '<strong>',
    '#markup' => t('Or'),
    '#suffix' => '</strong>',
  );

  $form['upload'] = array(
    '#type' => 'file',
    '#title' => t('Choose a file'),
    '#description' => t('For example: name.tar.gz from your local computer. The following file extensions are supported: zip tar tgz gz bz2.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import')
  );

  return $form;
}

/**
 * Form validation handler for revslider_admin_import_form().
 *
 * @see revslider_admin_import_form_submit()
 */
function revslider_admin_import_form_validate($form, &$form_state) {
  if (!($form_state['values']['url'] XOR !empty($_FILES['files']['name']['upload']))) {
    form_set_error('url', t('You must either provide a URL or upload an archive file to import.'));
  }

  if ($form_state['values']['url']) {
    if (!valid_url($form_state['values']['url'], TRUE)) {
      form_set_error('url', t('The provided URL is invalid.'));
    }
  }
}

function revslider_admin_import_form_submit($form, &$form_state) {
  if ($form_state['values']['url']) {
    $field = 'url';
    // Check url
    $file = $form_state['values']['url'];
    $parsed_url = parse_url($file);
    $remote_schemes = array('http', 'https', 'ftp', 'ftps', 'smb', 'nfs');
    if (!in_array($parsed_url['scheme'], $remote_schemes)) {
      // This is a local file, just return the path.
      $file = drupal_realpath($file);
    } else {
      $file = system_retrieve_file($file);
    }

    if (!$file) {
      form_set_error($field, t('Unable to retrieve import file from %url.', array('%url' => $form_state['values']['url'])));
      return;
    }
  }
  elseif ($_FILES['files']['name']['upload']) {
    $validators = array('file_validate_extensions' => array(archiver_get_extensions()));
    $field = 'upload';
    if (!($finfo = file_save_upload($field, $validators))) {
      // Failed to upload the file. file_save_upload() calls form_set_error() on
      // failure.
      return;
    }
    $file = $finfo->uri;
  }

  $directory = _revslider_admin_extract_directory();
  try {
    $archive = revslider_archive_extract($file, $directory);
  }
  catch (Exception $e) {
    form_set_error($field, $e->getMessage());
    return;
  }

  $files = $archive->listContents();
  if (!$files) {
    form_set_error($field, t('Provided archive contains no files.'));
    return;
  }
  if (in_array('slider_export.txt', $files)){//Import from WP source
        module_load_include('inc', 'revslider', 'revslider-wp');
        $result = revslider_wp_import($form_state['values']['name'],$directory);
      if($result){
        drupal_set_message(t('Import successed!'));
      }else{
        form_set_error(t('Import unsuccessed!'));
          return;
      }
      if (isset($finfo)) {
        file_delete($finfo);
      } else {
        file_unmanaged_delete($file);
      }
      file_unmanaged_delete_recursive($directory);
      drupal_goto('admin/content/revslider');
    }elseif (!in_array('settings.txt', $files)) {
    form_set_error($field, t('Provided archive contains no %file file.', array('%file' => 'settings.txt')));
    return;
  }

  $import_contents = file_get_contents(drupal_realpath($directory) .'/settings.txt');
  $import = drupal_json_decode(trim($import_contents));
  if (empty($import)) {
    form_set_error($field, t('Something wrong! Import data failure occurs.'));
    return;
  }

  $import_files = array();
  foreach ($files as $k => $v) {
    if ($v != 'settings.txt') {
      $v = $directory .'/'. $v;
      if (is_file($v)) {
        $path = pathinfo($v);
        $ext = pathinfo($v, PATHINFO_EXTENSION);
        if (in_array($ext, array('php5', 'php4', 'php', 'php3', 'php2', 'phtml'))) {
          throw new Exception(t('Security errors! Import data failure occurs.'));
        }
        $import_files[$path['filename']] = $v;
      }
    }
  }

  if (!empty($import_files) && !empty($import['slides']['items'])) {
    $media_dir = 'public://rs_media';
    if (file_prepare_directory($media_dir, FILE_CREATE_DIRECTORY) === FALSE) {
      drupal_set_message(t('%rs_dir could not be created.', array('%rs_dir' => 'rs_media')), 'error');
      return;
    }
    $file_keys = array_keys($import_files);
    while (count($import_files)) {
      // Start
      foreach ($import['slides']['items'] as $k => $v) {
        $key = md5($v['mainImage']['src']);
        if (in_array($key, $file_keys)) {
          $destination = $media_dir .'/'.basename($v['mainImage']['src']);
          $move_file = revslider_admin_move_file($import_files[$key], $destination);
          if ($move_file !== FALSE) {
            $import['slides']['items'][$k]['mainImage']['src'] = $move_file;
          }
          unset($import_files[$key]);
        }

        $key = md5($v['mainImage']['data-lazyload']);
        if (in_array($key, $file_keys)) {
          $destination = $media_dir .'/'.basename($v['mainImage']['data-lazyload']);
          $move_file = revslider_admin_move_file($import_files[$key], $destination);
          if ($move_file !== FALSE) {
            $import['slides']['items'][$k]['mainImage']['data-lazyload'] = $move_file;
          }
          unset($import_files[$key]);
        }

        $key = md5($v['settings']['data-thumb']);
        if (in_array($key, $file_keys)) {
          $destination = $media_dir .'/'.basename($v['settings']['data-thumb']);
          $move_file = revslider_admin_move_file($import_files[$key], $destination);
          if ($move_file !== FALSE) {
            $import['slides']['items'][$k]['settings']['data-thumb'] = $move_file;
          }
          unset($import_files[$key]);
        }

        if (!empty($v['layers'])) {
          foreach ($v['layers'] as $i => $j) {
            if ($j['type'] == 'image' && $j['value'] != '') {
              $key = md5($j['value']);
              if (in_array($key, $file_keys)) {
                $destination = $media_dir .'/'.basename($j['value']);
                $move_file = revslider_admin_move_file($import_files[$key], $destination);
                if ($move_file !== FALSE) {
                  $import['slides']['items'][$k]['layers'][$i]['value'] = $move_file;
                }
                unset($import_files[$key]);
              }
            } else if ($j['type'] == 'video') {
              if ($j['settings']['data-videoposter'] != '') {
                $key = md5($j['settings']['data-videoposter']);
                if (in_array($key, $file_keys)) {
                  $destination = $media_dir .'/'.basename($j['settings']['data-videoposter']);
                  $move_file = revslider_admin_move_file($import_files[$key], $destination);
                  if ($move_file !== FALSE) {
                    $import['slides']['items'][$k]['layers'][$i]['settings']['data-videoposter'] = $move_file;
                  }
                }
                unset($import_files[$key]);
              }
              if ($j['settings']['video-type'] == 'html5') {
                if ($j['settings']['data-videomp4'] != '') {
                  $key = md5($j['settings']['data-videomp4']);
                  if (in_array($key, $file_keys)) {
                    $destination = $media_dir .'/'.basename($j['settings']['data-videomp4']);
                    $move_file = revslider_admin_move_file($import_files[$key], $destination);
                    if ($move_file !== FALSE) {
                      $import['slides']['items'][$k]['layers'][$i]['settings']['data-videomp4'] = $move_file;
                    }
                  }
                  unset($import_files[$key]);
                }
                if ($j['settings']['data-videowebm'] != '') {
                  $key = md5($j['settings']['data-videowebm']);
                  if (in_array($key, $file_keys)) {
                    $destination = $media_dir .'/'.basename($j['settings']['data-videowebm']);
                    $move_file = revslider_admin_move_file($import_files[$key], $destination);
                    if ($move_file !== FALSE) {
                      $import['slides']['items'][$k]['layers'][$i]['settings']['data-videowebm'] = $move_file;
                    }
                  }
                  unset($import_files[$key]);
                }
                if ($j['settings']['data-videoogv'] != '') {
                  $key = md5($j['settings']['data-videoogv']);
                  if (in_array($key, $file_keys)) {
                    $destination = $media_dir .'/'.basename($j['settings']['data-videoogv']);
                    $move_file = revslider_admin_move_file($import_files[$key], $destination);
                    if ($move_file !== FALSE) {
                      $import['slides']['items'][$k]['layers'][$i]['settings']['data-videoogv'] = $move_file;
                    }
                  }
                  unset($import_files[$key]);
                }
              }

            }
          }
        }
      }
      // End
    }
  }

  $values = array(
    'id' => 0,
    'title' => $form_state['values']['name'],
    'data' => drupal_json_encode($import),
  );

  revslider_save_slider($values);

  drupal_set_message(t('Import successed!'));

  if (isset($finfo)) {
    file_delete($finfo);
  } else {
    file_unmanaged_delete($file);
  }
  file_unmanaged_delete_recursive($directory);

  drupal_goto('admin/content/revslider');
}

/**
 * Unpacks a downloaded archive file.
 *
 * @param string $file
 *   The filename of the archive you wish to extract.
 * @param string $directory
 *   The directory you wish to extract the archive into.
 *
 * @return Archiver
 *   The Archiver object used to extract the archive.
 *
 * @throws Exception
 */
function revslider_archive_extract($file, $directory) {
  $archiver = archiver_get_archiver($file);
  if (!$archiver) {
    throw new Exception(t('Cannot extract %file, not a valid archive.', array ('%file' => $file)));
  }

  // Remove the directory if it exists, otherwise it might contain a mixture of
  // old files mixed with the new files (e.g. in cases where files were removed
  // from a later release).
  $files = $archiver->listContents();

  // Unfortunately, we can only use the directory name to determine the import name.
  $project = strtok($files[0], '/\\');

  $extract_location = $directory . '/' . $project;
  if (file_exists($extract_location)) {
    file_unmanaged_delete_recursive($extract_location);
  }

  $archiver->extract($directory);
  return $archiver;
}

/**
 * Returns the directory where update archive files should be extracted.
 *
 * @param $create
 *   (optional) Whether to attempt to create the directory if it does not
 *   already exist. Defaults to TRUE.
 *
 * @return
 *   The full path to the temporary directory where update file archives should
 *   be extracted.
 */
function _revslider_admin_extract_directory($create = TRUE) {
  $directory = &drupal_static(__FUNCTION__, '');
  if (empty($directory)) {
    $directory = 'temporary://rs-import-extraction-' . substr(hash('sha256', drupal_get_hash_salt()), 0, 8);
    if ($create && !file_exists($directory)) {
      mkdir($directory);
    }
  }
  return $directory;
}

// Check slider file exist
function revslider_file_exist($destination) {
  if (!file_destination($destination, FILE_EXISTS_ERROR)) {
    return $destination;
  } else if (!file_destination(DRUPAL_ROOT . $destination, FILE_EXISTS_ERROR)) {
    return DRUPAL_ROOT . $destination;
  }

  return FALSE;
}

// Move tmp file to public
function revslider_admin_move_file($source, $destination) {
  $move_file = file_unmanaged_move($source, $destination, FILE_EXISTS_RENAME);
  if ($move_file === FALSE) {
    drupal_set_message(t('File: %rs_file could not be import.', array('%rs_file' => $destination)), 'error');
  }

  return $move_file;
}
