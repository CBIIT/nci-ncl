<?php

/**
 * SLider Object
 */
class rsElement {
  protected $value;
  protected $conditions = array(
    'navigationType' => array(
      array(
        '#values' => array('', 'none'),
        '#childrens' => array('navigationHAlign', 'naigationVAlign', 'navigationHOffset', 'navigationVOffset'),
        '#operate' => '#',
        '#setting' => 'destroy',
        '#form' => 'hide',
      )
    ),
    'slider_layout' => array(
      array(
        '#values' => array('fixed'),
        '#childrens' => array('minHeight'),
        '#operate' => '=',
        '#setting' => 'destroy',
        '#form' => 'hide',
      ),
      array(
        '#values' => array('custom'),
        '#childrens' => array('minHeight'),
        '#operate' => '=',
        '#setting' => 'destroy',
        '#form' => 'hide',
      ),
      array(
        '#values' => array('auto'),
        '#childrens' => array('fullWidth', 'autoHeight', 'minHeight', 'forceFullWidth'),
        '#operate' => '=',
        '#setting' => 'destroy',
        '#form' => 'hide',
      ),
      array(
        '#values' => array('full'),
        '#childrens' => array('fullWidth', 'autoHeight', 'minHeight', 'fullScreenAlignForce', 'forceFullWidth', 'fullScreen', 'fullScreenOffsetContainer', 'fullScreenOffset'),
        '#operate' => '=',
        '#setting' => 'destroy',
        '#form' => 'hide',
      ),

    ),
    'parallax_enabled' => array(
      array(
        '#values' => array('on'),
        '#childrens' => array('parallaxDisableOnMobile', 'parallax', 'parallaxBgFreeze', 'parallaxLevels'),
        '#operate' => '=',
        '#setting' => 'destroy',
        '#form' => 'disable',
      ),
      array(
        '#values' => array('', 'off'),
        '#childrens' => array(),
        '#setting' => 'destroy',
        '#form' => 'disable',
      )
    ),
    'data-kenburns' => array(
      array(
        '#values' => array('on'),
        '#childrens' => array('data-bgposition', 'data-bgpositionend', 'data-bgfit', 'data-bgfitend', 'data-ease', 'data-duration'),
        '#operate' => '=',
        '#setting' => 'destroy',
        '#form' => 'hide',
      ),
      array(
        '#values' => array('', 'off'),
        '#childrens' => array('data-bgposition', 'data-bgfit'),
        '#operate' => '=',
        '#setting' => 'destroy',
        '#form' => 'hide',
      ),
    ),
    'video-type' => array(
      array(
        '#values' => array('youtube'),
        '#childrens' => array('data-autoplay', 'data-autoplayonlyfirsttime', 'data-nextslideatend', 'data-ytid', 'data-videoattributes', 'data-videocontrols', 'data-videowidth', 'data-videoheight', 'data-aspectratio'),
        '#setting' => 'destroy',
        '#form' => 'hide',
      ),
      array(
        '#values' => array('vimeo'),
        '#childrens' => array('data-autoplay', 'data-autoplayonlyfirsttime', 'data-nextslideatend', 'data-vimeoid', 'data-videoattributes', 'data-videocontrols', 'data-videowidth', 'data-videoheight', 'data-aspectratio'),
        '#setting' => 'destroy',
        '#form' => 'hide',
      ),
      array(
        '#values' => array('html5'),
        '#childrens' => array('data-autoplay', 'data-autoplayonlyfirsttime', 'data-nextslideatend', 'data-videopreload', 'data-videomp4', 'data-videoogv', 'data-videowebm', 'data-videocontrols', 'data-videowidth', 'data-videoheight', 'data-forcecover', 'data-forcerewind', 'data-aspectratio', 'data-volume', 'data-videoposter', 'data-videoloop'),
        '#setting' => 'destroy',
        '#form' => 'hide',
      ),
      array(
        '#values' => array(''),
        '#childrens' => array(),
        '#setting' => 'destroy',
        '#form' => 'hide',
      ),
    ),
    'video-fullscreen' => array(
      array(
        '#values' => array('off'),
        '#childrens' => array('data-videowidth', 'data-videoheight'),
        '#setting' => '',
        '#form' => 'hide'
      ),
      array(
        '#values' => array('on', ''),
        '#childrens' => array(),
        '#setting' => '',
        '#form' => 'hide'
      )
    ),

    'data-forcecover' => array(
      array(
        '#values' => array('false', ''),
        '#childrens' => array(),
        '#setting' => 'destroy',
        '#form' => 'hide'
      ),
      array(
        '#values' => array('true'),
        '#childrens' => array('data-dottedoverlay', 'data-aspectratio'),
        '#setting' => 'destroy',
        '#form' => 'hide'
      )
    ),
    'data-bgfit' => array(
      array(
        '#values' => array('percentage'),
        '#childrens' => array('bgfit-percentage-width', 'bgfit-percentage-height'),
        '#setting' => 'destroy',
        '#form' => 'hide',
      ),
      array(
        '#values' => array('cover', 'contain', 'normal', ''),
        '#childrens' => array(),
        '#setting' => 'destroy',
        '#form' => 'hide',
      ),
    ),
  );
  protected $attributes = array();
  protected $excludes;
  protected $group;
  protected $settings;

  private function __construct() {
  }

  public function getValue() {
    return $this->value;
  }

  protected function setValue($value) {
    return $this->value = $value;
  }

  public function getCondition($key = 'all') {
    if ($key == 'all') return $this->conditions;

    return isset($this->conditions[$key]) ? $this->conditions[$key] : false;
  }

  protected function setAttr($key, $value, $field = 'attributes') {
    $this->attributes[$field][$key] = $value;
  }

  public function getAttr($field = 'all') {
    if ($field == 'all') return $this->attributes;
    return isset($this->attributes[$field]) ? $this->attributes[$field] : false;
  }

  protected function removeAttr($attr, $field = 'attributes') {
    if (isset($this->attributes[$field][$attr])) {
      unset($this->attributes[$field][$attr]);
    }
  }

  protected function setExclude($value) {
    $this->excludes[] = $value;
  }

  public function getExclude() {
    return $this->excludes;
  }

  public function getGroup($field = 'all') {
    if ($field == 'all') return $this->group;
    return isset($this->group[$field]) ? $this->group[$field] : false;
  }

  protected function setGroup($field, $value) {
    return $this->group[$field][] = $value;
  }

  public function getSetting($key = 'all') {
    if ($key == 'all') return $this->settings;
    return isset($this->settings[$key]) ? $this->settings[$key] : false;
  }

  protected function setSetting($key, $value) {
    return $this->settings[$key] = $value;
  }

  protected function preExcludes($key, $value) {
    $condition = $this->getCondition($key);
    if ($condition === false) return array();

    $conditionId = NULL;
    $conditionList = array();
    foreach ($condition as $k => $v) {
      if (!isset($v['#operate']) || $v['#operate'] == '=' || $v['#operate'] == '') {
        if (in_array($value, $v['#values']) || in_array(json_encode($value), $v['#values'])) {
          $conditionId = $k;
        } else {
          $conditionList = array_merge($conditionList, $v['#childrens']);
        }
      } else if ($v['#operate'] == '#') {
        if (in_array($value, $v['#values']) || in_array(json_encode($value), $v['#values'])) {
          $conditionId = $k;
        } else {
          $conditionList = array_merge($conditionList, $v['#childrens']);
        }
      } else {
        throw new Exception('Operator is not defined!');
      }

      if ($conditionId !== NULL && $condition[$conditionId]['#setting'] == 'destroy') {
        foreach ($conditionList as $i => $j) {
          if (!in_array($j, $condition[$conditionId]['#childrens'])) {
            $this->setExclude($j);
          }
        }
      }
    }

  }

  protected function preAttributes() {
    $group = $this->getGroup();
    // Set attributes value.
    $settings = $this->getSetting();
    if($settings == false){
      $settings = array();
    }
    foreach ($settings as $k => $v) {
      if (is_string($v)) {
        $v = trim($v);
      }

      if (in_array($k, array('data-thumb', 'data-lazyload')) && trim($v) != '') {
        $v = file_create_url($v);
      }

      $this->preExcludes($k, $v);
      if ($v === '' || $v === NULL) continue;

      // Set bg-fit manualy when kenburn on
      if ($k == 'data-bgfitstart' || $k == 'data-bgfit') {
        if ($settings['data-kenburns'] == 'on') {
          $this->setAttr('data-bgfit', $settings['data-bgfitstart']);
        } else if ($k == 'data-bgfit') {
          $this->setAttr($k, $v);
        }
      } else if (in_array($k, array('width', 'height')) && $v != '') {
        if (strpos($v, '%') === false || strpos($v, 'px') === false) {
          $this->setAttr($k, $k . ':' . $v . 'px', 'innerStyle');
        } else {
          $this->setAttr($k, $k . ':' . $v, 'innerStyle');
        }
      } else if ($k == 'custom_style') {
        $this->setAttr($k, $v . ';', 'style');
      } else {
        if (!empty($group)) {
          foreach ($group as $i => $j) {
            if (in_array($k, $j)) {
              if ($i != 'attributes') $this->setExclude($k);
              if ($i == 'loops') {
                $k = str_replace('caption_loop_', '', $k);
              }
              $this->setAttr($k, $v, $i);
            } else {
              $this->setAttr($k, $v);
            }
          }
        } else {
          $this->setAttr($k, $v);
        }
      }
    }

    // Remove exclude attributes.
    $attrs = $this->getAttr('attributes');
    $excludes = $this->getExclude();
    if (!empty($attrs) && !empty($excludes)) {
      foreach ($attrs as $k => $v) {
        if (in_array($k, $excludes)) {
          $this->removeAttr($k);
        }
      }
    }
  }

}

class rsLayer extends rsElement {

  protected $type;
  protected $weight;
  public $settings;
  public function __construct($layer) {
    $this->setType($layer['type']);
    if (!isset($layer['#weight'])) {
      $layer['#weight'] = 0;
    }

    if (isset($layer['settings']['data-x']) && is_numeric($layer['settings']['data-x'])) {
      $layer['settings']['data-hoffset'] = '';
    }

    if (isset($layer['settings']['data-y']) && is_numeric($layer['settings']['data-y'])) {
      $layer['settings']['data-voffset'] = '';
    }

    $this->setWeight($layer['#weight'] + 1);

    $this->setValue($layer['value']);

    if ($layer['type'] == 'video') {
      $this->setAttr('video-caption', 'tp-videolayer', 'wrapper_classes');
      if (isset($layer['settings']['video-fullscreen']) && $layer['settings']['video-fullscreen'] == 'on') {
        $this->setAttr('video-screen', 'fullscreenvideo', 'wrapper_classes');
        $layer['settings']['data-x'] = 0;
        $layer['settings']['data-hoffset'] = '';
        $layer['settings']['data-x'] = 0;
        $layer['settings']['data-voffset'] = '';
        $layer['settings']['data-x'] = 0;
        $layer['settings']['data-videowidth'] = '100%';
        $layer['settings']['data-videoheight'] = '100%';
      }
    }

    if (!empty($layer['settings'])) {
      foreach ($layer['settings'] as $k => $v) {
        $this->setSetting($k, $v);
      }
    }

    $ex = array('tp-resizeme', 'ui-eye', 'ui-lock', 'left-corner', 'right-corner', '2d-rotation', '2d-rotation-origin-x', '2d-rotation-origin-y', 'width', 'height', 'custom_style', 'video-type', 'styling-captions');
    foreach ($ex as $v) {
      $this->setExclude($v);
    }

    $group = array(
      'wrapper_classes' => array('incoming-classes', 'outgoing-classes', 'layer_parallax_level','class', 'classes', 'styling-captions'),
      'inner_classes' => array(),
      'attributes' => array(),
      'loops' => array('caption_loop_data-speed', 'caption_loop_data-easing', 'caption_loop_data-startdeg', 'caption_loop_data-enddeg', 'caption_loop_data-xs', 'caption_loop_data-xe', 'caption_loop_data-ys', 'caption_loop_data-ye', 'caption_loop_data-zoomstart', 'caption_loop_data-zoomend', 'caption_loop_data-origin-x', 'caption_loop_data-origin-y', 'caption_loop_data-angle', 'caption_loop_data-radius'),
    );

    if (!in_array('layer_parallax_level', $this->getExclude())) {
      $group['wrapper_classes'][] = 'layer_parallax_level';
    }

    if ($layer['type'] != 'video') {
      $group['inner_classes'][] = 'caption-loop';
    }

    foreach ($group as $k => $v) {
      foreach ($v as $m => $n) {
        $this->setGroup($k, $n, $k);
      }
    }

    $this->setAttr('caption', 'tp-caption', 'wrapper_classes');

    $this->preAttributes();
    $index = $layer['#weight'] + 5;
    $this->setAttr('weight', 'z-index:'. $index.';', 'style');
  }

  private function setType($type) {
    return $this->type = $type;
  }

  public function getType() {
    return $this->type;
  }

  private function setWeight($weight) {
    return $this->weight = $weight;
  }

  public function getWeight() {
    return $this->weight;
  }

  public function renderCorner() {
    $conner = '';
    $leftCorner = $this->getSetting('left-corner');
    $rightCorner = $this->getSetting('right-corner');
    if ($leftCorner !== false) {
      if ($leftCorner == 'curved') {
        $conner .= '<div class="frontcorner"></div>';
      } else if ($leftCorner == 'reverced') {
        $conner .= '<div class="frontcornertop"></div>';
      }
    }

    if ($rightCorner !== false) {
      if ($rightCorner == 'curved') {
        $conner .= '<div class="backcorner"></div>';
      } else if ($rightCorner == 'reverced') {
        $conner .= '<div class="backcornertop"></div>';
      }
    }

    return $conner;
  }

  public function rotation() {
    $rotation = array(
      '-moz-transfor' => '',
      '-ms-transform' => '',
      '-o-transform' => '',
      '-webkit-transform' => '',
      'transform' => '',
      '-moz-transform-origin' => '',
      '-ms-transform-origin' => '',
      '-o-transform-origin' => '',
      '-webkit-transform-origin' => '',
      'transform-origin' => ''
    );

    if ($this->getSetting('2d-rotation') !== false && $this->getSetting('2d-rotation') != 0) {
      $rotation = array(
        '-moz-transform' => 'rotate(' . $this->getSetting('2d-rotation') . 'deg)',
        '-ms-transform' => 'rotate(' . $this->getSetting('2d-rotation') . 'deg)',
        '-o-transform' => 'rotate(' . $this->getSetting('2d-rotation') . 'deg)',
        '-webkit-transform' => 'rotate(' . $this->getSetting('2d-rotation') . 'deg)',
        'transform' => 'rotate(' . $this->getSetting('2d-rotation') . 'deg)',
        '-moz-transform-origin' => $this->getSetting('2d-rotation-origin-x') . '% ' . $this->getSetting('2d-rotation-origin-y') . '%',
        '-ms-transform-origin' => $this->getSetting('2d-rotation-origin-x') . '% ' . $this->getSetting('2d-rotation-origin-y') . '%',
        '-o-transform-origin' => $this->getSetting('2d-rotation-origin-x') . '% ' . $this->getSetting('2d-rotation-origin-y') . '%',
        '-webkit-transform-origin' => $this->getSetting('2d-rotation-origin-x') . '% ' . $this->getSetting('2d-rotation-origin-y') . '%',
        'transform-origin' => $this->getSetting('2d-rotation-origin-x') . '% ' . $this->getSetting('2d-rotation-origin-y') . '%',
      );

      return $rotation;
    }

    return false;
  }
}

class rsSlide extends rsElement {

  protected $name;
  protected $bg;
  protected $layers = array();
  protected $settings;

  public function __construct($slide) {
    $this->setName($slide['name']);
    $this->setBg($slide['mainImage']);

    $this->setExclude('state');

    foreach ($slide['settings'] as $k => $v) {
      $this->setSetting($k, $v);
    }

    if (!empty($slide['layers'])) {
      foreach ($slide['layers'] as $k => $v) {
        $this->setLayer($k, $v);
      }
    }

    $this->preAttributes();
  }

  public function getName() {
    return $this->name;
  }

  private function setName($name) {
    $this->name = $name;
  }

  public function getBg() {
    return $this->bg;
  }

  private function setBg($bg) {
    $this->bg = new rsBg($bg);
  }

  public function getLayer($key = 'all') {
    if ($key == 'all') {
      return $this->layers;
    }
    return isset($this->layers[$key]) ? $this->layers[$key] : false;
  }

  private function setLayer($key, $layer) {
    $this->layers[$key] = new rsLayer($layer);
    if ($this->getSetting('parallax_enabled' == 'off')) {
      $this->layers[$key]->setSetting('layer_parallax_level', '');
    }
    return $this->layers[$key];
  }

}

class rsBg extends rsElement {

  public function __construct($bg) {
      if(empty($bg['src'])){
          global $base_url;
          $bg['src'] = $base_url.'/'.drupal_get_path('module','revslider').'/images/transparent.png';
      }
    $bg['src'] = file_create_url($bg['src']);
    foreach ($bg as $k => $v) {
      $this->setSetting($k, $v);
    }

    $this->preAttributes();
  }
}

class RS extends rsElement {

  protected $id;
  protected $slides;
  protected $container;
  protected $staticLayers = array();

  public function __construct($slider) {
    $this->setId($slider['id']);
    foreach ($slider['options'] as $k => $v) {
      if ($k == 'parallaxLevels') {
        if (trim($v) != '') $v = drupal_json_decode($v);
      }
      $this->setSetting($k, $v);
    }

    foreach ($slider['slides']['items'] as $k => $v) {
      $this->setSlide($k, $v);
    }

    if (isset($slider['slides']['static']['layers']) && !empty($slider['slides']['static']['layers'])) {
      foreach ($slider['slides']['static']['layers'] as $k => $v) {
        $this->setStaticLayer($k, $v);
      }
    }

    switch ($slider['options']['slider_layout']) {
      case 'full':
        $this->setAttr('wrapper', 'fullscreen-container', 'wrapper_classes');
        $this->setAttr('banner', 'fullscreenbanner', 'inner_classes');
        break;
      case 'auto':
        $this->setAttr('wrapper', 'fullwidth-container', 'wrapper_classes');
        $this->setAttr('banner', 'fullwidthbanner', 'inner_classes');
        break;
      case 'custom':
        $this->setAttr('wrapper', 'custom-container', 'wrapper_classes');
        $this->setAttr('banner', 'custombanner', 'inner_classes');
        break;
      case 'fixed':
        $this->setAttr('wrapper', 'fixed-container', 'wrapper_classes');
        $this->setAttr('banner', 'fixedbanner', 'inner_classes');
        break;
    }

    $this->preAttributes();
  }

  public function getId() {
    return $this->id;
  }

  private function setId($id) {
    return $this->id = $id;
  }

  public function getContainer() {
    return $this->container;
  }

  public function getSlide($id = 'all') {
    if ($id == 'all') return $this->slides;
    return isset($this->slides[$id]) ? $this->slides[$id] : false;
  }

  public function setSlide($id, $slide) {
    return $this->slides[$id] = new rsSlide($slide);
  }

  public function setStaticLayer($id, $layer) {
    return $this->staticLayers[$id] = new rsLayer($layer);
  }

  public function getStaticLayer($id = 'all') {
    if ($id == 'all') return $this->staticLayers;
    return isset($this->staticLayers[$id]) ? $this->staticLayers[$id] : false;
  }

}
