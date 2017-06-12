<?php

function revslider_wp_import($name,$source){
    $slide_export = file_get_contents($source.'/slider_export.txt');
    $slide_export = unserialize($slide_export);
    $dp_slider = new stdClass();
    $dp_slider->name = '';
    $dp_slider->slides = new stdClass();
    $dp_slider->slides->items = array();
    $dp_slider->options = new stdClass();

    $wp_params = $slide_export['params'];
    $dp_slider->options->delay = $wp_params['delay'];
    $dp_slider->options->{'shuffle'} = $wp_params['shuffle'];
    $dp_slider->options->startheight = $wp_params['height'];
    $dp_slider->options->startwidth = $wp_params['width'];
    $dp_slider->options->startWithSlide = isset($wp_params['start_with_slide'])?($wp_params['start_with_slide']-1):0;
    $dp_slider->options->onHoverStop = $wp_params['stop_on_hover'];
    $dp_slider->options->keyboardNavigation = isset($wp_params['keyboard_navigation'])?$wp_params['keyboard_navigation']:'off';
    $dp_slider->options->navigationType = $wp_params['navigaion_type'];
    $dp_slider->options->navigationArrows = $wp_params['navigation_arrows'];
    $dp_slider->options->navigationStyle = $wp_params['navigation_style'];
    $dp_slider->options->navigationHAlign = $wp_params['navigaion_align_hor'];
    $dp_slider->options->naigationVAlign = $wp_params['navigaion_align_vert'];
    $dp_slider->options->navigationHOffset = $wp_params['navigaion_offset_hor'];
    $dp_slider->options->navigationVOffset = $wp_params['navigaion_offset_vert'];
    $dp_slider->options->soloArrowLeftHalign = $wp_params['leftarrow_align_hor'];
    $dp_slider->options->soloArrowLeftValign = $wp_params['leftarrow_align_vert'];
    $dp_slider->options->soloArrowLeftHOffset = $wp_params['leftarrow_offset_hor'];
    $dp_slider->options->soloArrowLeftVOffset = $wp_params['leftarrow_offset_vert'];
    $dp_slider->options->soloArrowRightHalign = $wp_params['rightarrow_align_hor'];
    $dp_slider->options->soloArrowRightValign = $wp_params['rightarrow_align_vert'];
    $dp_slider->options->soloArrowRightHOffset = $wp_params['rightarrow_offset_hor'];
    $dp_slider->options->soloArrowRightVOffset = $wp_params['rightarrow_offset_vert'];
    $dp_slider->options->touchenabled = $wp_params['touchenabled'];
    $dp_slider->options->swipe_velocity = isset($wp_params['swipe_velocity'])?$wp_params['swipe_velocity']:'';
    $dp_slider->options->swipe_max_touches = isset($wp_params['swipe_max_touches'])?$wp_params['swipe_max_touches']:1;
    $dp_slider->options->swipe_min_touches = isset($wp_params['swipe_min_touches'])?$wp_params['swipe_min_touches']:1;
    $dp_slider->options->drag_block_vertical = isset($wp_params['drag_block_vertical'])?$wp_params['drag_block_vertical']:false;
    $dp_slider->options->stopAtSlide = 0-$wp_params['stop_at_slide'];
    $dp_slider->options->stopAfterLoops = $wp_params['stop_after_loops'];
    $dp_slider->options->loopSingleSlide = true;
    $dp_slider->options->thumbWidth = $wp_params['thumb_width'];
    $dp_slider->options->thumbHeight = $wp_params['thumb_height'];
    $dp_slider->options->thumbAmount = $wp_params['thumb_amount'];
    $dp_slider->options->google_fonts = '';
    if(isset($wp_params['google_font'])){
        //print_r($wp_params['google_font']);die;
        $fonts = array();
        foreach($wp_params['google_font'] as $font){
            $font = stripslashes($font);
            preg_match('/href=["\'](.*?)["\']/', $font, $match);
            if(isset($match[1])){
                $fonts[] = $match[1];
            }
        }
        $dp_slider->options->google_fonts = implode("|",$fonts);
    }

    //Custom css
    $custom_css = "";
    if(file_exists($source.'/dynamic-captions.css')){
        $custom_css .= file_get_contents($source.'/dynamic-captions.css');
    }
    if(file_exists($source.'/static-captions.css')){
        $custom_css .= file_get_contents($source.'/static-captions.css');
    }
    $dp_slider->options->custom_css = $custom_css;
    $slider_type = array('fixed'=>'fixed','responsitive'=>'custom','fullwidth'=>'auto','fullscreen'=>'full');
    $dp_slider->options->slider_layout = $slider_type[$wp_params['slider_type']];
    //$dp_slider->options->hideTimerBar = $wp_params['xx'];
    //$dp_slider->options->fullWidth = $wp_params['xx'];
    $dp_slider->options->autoHeight = $wp_params['auto_height'];
    $dp_slider->options->minHeight = $wp_params['fullscreen_min_height'];
    $dp_slider->options->fullScreenAlignForce = $wp_params['full_screen_align_force'];
    $dp_slider->options->forceFullWidth = $wp_params['force_full_width'];
    $dp_slider->options->shadow = $wp_params['shadow_type'];
    $dp_slider->options->dottedOverlay = $wp_params['background_dotted_overlay'];
    $dp_slider->options->parallax_enabled = isset($wp_params['use_parallax'])?$wp_params['use_parallax']:'off';
    $dp_slider->options->parallaxDisableOnMobile = isset($wp_params['disable_parallax_mobile'])?$wp_params['disable_parallax_mobile']:'on';
    $dp_slider->options->parallax = isset($wp_params['parallax_type'])?$wp_params['parallax_type']:'mouse+scroll';
    $dp_slider->options->parallaxBgFreeze = isset($wp_params['parallax_bg_freeze'])?$wp_params['parallax_bg_freeze']:'on';
    $parallaxLevels = array();
    for($i=1;$i<=10; $i++){
        $key = 'parallax_level_'.$i;
        if(isset($wp_params[$key])){
            $parallaxLevels[] = $wp_params[$key];
        }else{
            $parallaxLevels[] = 0;
        }
    }
    //$parallaxLevels = array(parallaxLevels);
    $dp_slider->options->parallaxLevels = '['.implode(',',$parallaxLevels).']';

    foreach($slide_export['slides'] as $slide){
        $dp_slide = _rs_wp_import_slide($source, $slide);
        $dp_slide->{'#weight'} = $slide['slide_order'];
        $dp_slider->slides->items[] = $dp_slide;
    }
    global $user;

    $id = db_insert('revolution_slides')
    ->fields(array(
      'title' => $name,
      'uid' => $user->uid,
      'data' => json_encode($dp_slider),
      'status' => 1,
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
    ))
    ->execute();
    if($id) return true;
    return false;
}

function _rs_wp_import_slide($source,$wp_slide){
    $slide = new stdClass();
    $slide->mainImage = new stdClass();
    $slide->settings = new stdClass();
    $slide->layers = array();

    //Settings
    $slide->name = isset($wp_slide['params']['title'])?$wp_slide['params']['title']:'New Slide';
    $slide->settings->state = isset($wp_slide['params']['state'])?$wp_slide['params']['state']:'published';
    $slide->settings->{'data-transition'} = isset($wp_slide['params']['slide_transition'])?$wp_slide['params']['slide_transition']:'random';
    //$slide->settings->{'data-randomtransition'} = $wp_slide['params']['slide_transition'];
    $slide->settings->{'data-slotamount'} = isset($wp_slide['params']['slot_amount'])?$wp_slide['params']['slot_amount']:7;
    $slide->settings->{'data-masterspeed'} = isset($wp_slide['params']['transition_duration'])?$wp_slide['params']['transition_duration']:500;
    $slide->settings->{'data-delay'} = isset($wp_slide['params']['delay'])?$wp_slide['params']['delay']:'';
    //$slide->settings->{'data-link'} = $wp_slide['params']['slide_link'];
    $slide->settings->{'data-title'} = isset($wp_slide['params']['title'])?$wp_slide['params']['title']:'New Slide';
    $slide->settings->{'data-slideindex'} = $wp_slide['slide_order'];

    //Kenburns
    $slide->mainImage->{'data-kenburns'} = isset($wp_slide['params']['kenburn_effect'])?$wp_slide['params']['kenburn_effect']:'off';
    $slide->mainImage->{'data-bgrepeat'} = isset($wp_slide['params']['bg_repeat'])?$wp_slide['params']['bg_repeat']:'no-repeat';
    $slide->mainImage->{'data-bgfit'} = isset($wp_slide['params']['bg_fit'])?$wp_slide['params']['bg_fit']:'cover';
    $slide->mainImage->{'bgfit-percentage-width'} = isset($wp_slide['params']['bg_fit_x'])?$wp_slide['params']['bg_fit_x']:'';
    $slide->mainImage->{'bgfit-percentage-height'} = isset($wp_slide['params']['bg_fit_y'])?$wp_slide['params']['bg_fit_y']:'';
    //$slide->mainImage->{'data-bgfitend'} =
    $slide->mainImage->{'data-bgposition'} = isset($wp_slide['params']['bg_position'])?$wp_slide['params']['bg_position']:'center center';
    $slide->mainImage->{'data-bgpositionend'} = isset($wp_slide['params']['bg_end_position'])?$wp_slide['params']['bg_end_position']:'center center';
    $slide->mainImage->{'data-duration'} = isset($wp_slide['params']['kb_duration'])?$wp_slide['params']['kb_duration']:10000;
    $slide->mainImage->{'data-ease'} = isset($wp_slide['params']['kb_easing'])?$wp_slide['params']['kb_easing']:'Linear.easeNone';
    $slide->mainImage->{'data-bgfitstart'} = isset($wp_slide['params']['kb_start_fit'])?$wp_slide['params']['kb_start_fit']:'130%';
    $slide->mainImage->{'data-bgfitend'} = isset($wp_slide['params']['kb_end_fit'])?$wp_slide['params']['kb_end_fit']:'100%';
    //$slide->mainImage->{'data-bgfitstart'} = $wp_slide['params']['kb_easing'];
    //data-kenburns
    //data-kenburns

    if($wp_slide['params']['background_type'] == 'image'){
        $file = _rs_wp_import_mv_file($source.'/images/'.$wp_slide['params']['image']);
        $slide->mainImage->src = $file->uri;
    }else{
        $slide->mainImage->src = '';
    }
    $slide->mainImage->{'data-lazyload'} = '';
    if(isset($wp_slide['params']['slide_thumb']) && !empty($wp_slide['params']['slide_thumb'])){
        $file = _rs_wp_import_mv_file($wp_slide['params']['slide_thumb']);
        $slide->settings->{'data-thumb'} = $file->uri;
    }
    if(is_array($wp_slide['layers'])){
        foreach($wp_slide['layers'] as $k => $wp_layer){
            $layer = _rs_wp_import_layer($source, $wp_layer);
            $layer->{'#weight'} = $k;
            $slide->layers[] = $layer;
        }
    }
    return $slide;
}

function _rs_wp_import_layer($source, $wp_layer){
    $animations = array();
    if(file_exists($source.'/custom_animations.txt')){
        $animations = file_get_contents($source.'/custom_animations.txt');
        $animations = unserialize($animations);
    }
    $layer = new stdClass();
    $layer->settings = new stdClass();

    switch ($wp_layer['align_hor']) {
        default:
        case 'left':
            $layer->settings->{'data-x'} = $wp_layer['left'];
            break;
        case 'center':
            $layer->settings->{'data-x'} ="center";
            $layer->settings->{'data-hoffset'} = $wp_layer['left'];
            break;
        case 'right':
            $left = (int)$left*-1;
            $layer->settings->{'data-x'} = 'right';
            $layer->settings->{'data-hoffset'} = 0 -  (int)$wp_layer['left'];
            break;
    }

    switch ($wp_layer['align_vert']) {
        default:
        case 'top':
            $layer->settings->{'data-y'} = $wp_layer['top'];
            break;
        case 'middle':
            $layer->settings->{'data-y'} = "center";
            $layer->settings->{'data-voffset'} = $wp_layer['top'];
            break;
        case 'bottom':
            $top = (int)$top*-1;
            $layer->settings->{'data-y'} = "bottom";
            $layer->settings->{'data-voffset'} = 0 - (int)$wp_layer['top'];
            break;
    }

    $layer->settings->{'data-speed'} = $wp_layer['speed'];
    $layer->settings->{'data-start'} = $wp_layer['time'];
    $layer->settings->{'data-end'} = $wp_layer['endtime'];
    $layer->settings->{'data-easing'} = $wp_layer['easing'];
    $layer->settings->{'class'} = $wp_layer['style'];
    $layer->settings->classes = $wp_layer['attrClasses'];
    $layer->settings->{'styling-captions'} = $wp_layer['style'];
    if($wp_layer['type'] != 'text'){
        $layer->settings->width = $wp_layer['width'];
        $layer->settings->height = $wp_layer['height'];
    }
    $layer->settings->{'2d-rotation'} = isset($wp_layer['2d_rotation'])?$wp_layer['2d_rotation']:'';
    $layer->settings->{'2d-rotation-origin-x'} = isset($wp_layer['2d_origin_x'])?$wp_layer['2d_origin_x']:'';
    $layer->settings->{'2d-rotation-origin-y'} = isset($wp_layer['2d_origin_y'])?$wp_layer['2d_origin_y']:'';
    $layer->settings->{'layer_parallax_level'} = (isset($wp_layer['parallax_level']) && $wp_layer['parallax_level'] != '-')?'rs-parallaxlevel-'.$wp_layer['parallax_level']:'';

    if(isset($wp_layer['split'])){
        $layer->settings->{'data-splitin'} = $wp_layer['split'];
    }
    if(isset($wp_layer['endsplit'])){
        $layer->settings->{'data-splitout'} = $wp_layer['endsplit'];
    }
    if(isset($wp_layer['splitdelay'])){
        $layer->settings->{'data-elementdelay'} = $wp_layer['splitdelay']/100;
    }
    if(isset($wp_layer['endsplitdelay'])){
        $layer->settings->{'data-endelementdelay'} = $wp_layer['endsplitdelay']/100;
    }
    $animation = str_replace('customin-','',$wp_layer['animation']);
    if($animation != $wp_layer['animation']){
        foreach($animations as $a){
            if($a['id'] == $animation){
                $layer->settings->{'data-customin'} = _rs_wp_import_custom_animation($a['params']);
                break;
            }
        }
        $layer->settings->{'incoming-classes'} = 'customin';
    }else{
        $layer->settings->{'incoming-classes'} = $wp_layer['animation'];
    }

    $endanimation = str_replace('customout-','',$wp_layer['endanimation']);
    if($endanimation != $wp_layer['endanimation']){
        foreach($animations as $a){
            if($a['id'] == $endanimation){
                $layer->settings->{'data-customout'} = _rs_wp_import_custom_animation($a['params']);
                break;
            }
        }
        $layer->settings->{'outgoing-classes'} = 'customout';
    }else{
        $layer->settings->{'outgoing-classes'} = $wp_layer['endanimation'];
    }


    $layer->settings->{'data-easing'} = $wp_layer['easing'];
    $layer->settings->{'data-speed'} = $wp_layer['speed'];

    $layer->type = $wp_layer['type'];
    if($layer->type == 'text'){
        $layer->value = $wp_layer['text'];
    }
    if($layer->type == 'image'){
        $file = _rs_wp_import_mv_file($source.'/images/'.$wp_layer['image_url']);
        $layer->value = $file->uri;
    }
    if($layer->type == 'video'){
        $layer->value = '';
        if($wp_layer['video_type'] == 'vimeo'){
            $layer->value = "https://vimeo.com/{$wp_layer['video_id']}";
            $layer->settings->{'video-type'} = 'vimeo';
        }
        $layer->settings->{'data-videoposter'} = $wp_layer['video_image_url'];
        $layer->settings->{'data-vimeoid'} = $wp_layer['video_id'];
        $layer->settings->{'data-videoattributes'} = 'enablejsapi=1&html5=1&hd=1&wmode=opaque&showinfo=0&rel=0';
        $layer->settings->{'data-videowidth'} = $wp_layer['video_width'];
        $layer->settings->{'data-videoheight'} = $wp_layer['video_height'];
        $layer->settings->{'data-aspectratio'} = '16:9';
        $layer->settings->{'video-fullscreen'} = ($wp_layer['width'] == -1)?'on':'off';
    }
    return $layer;
}

function _rs_wp_import_custom_animation($animation){
    $animation['scalex'] = $animation['scalex']/100;
    $animation['scaley'] = $animation['scaley']/100;
    return "x:{$animation['movex']};y:{$animation['movey']};z:{$animation['movez']};rotationX:{$animation['rotationx']};rotationY:{$animation['rotationy']};rotationZ:{$animation['rotationz']};scaleX:{$animation['scalex']};scaleY:{$animation['scaley']};skewX:{$animation['skewx']};skewY:{$animation['skewy']};opacity:{$animation['captionopacity']};transformPerspective:{$animation['captionperspective']};transformOrigin:{$animation['originx']}% {$animation['originy']}%;";
}

function _rs_wp_import_mv_file($source){
    $file_name = 'public://'.basename($source);
    $data = file_get_contents($source);
    $file = file_save_data($data,$file_name);
    return $file;
}
