<?php

function revslider_global_settings(){
    $form = drupal_get_form('revslider_global_settings_form');
    $result = array('#type' => 'ajax');
    $result['#commands'][] = array(
        'command' => 'rs_global_settings',
        'method' => NULL,
        'data' => render($form),
    );
    return $result;
}

function revslider_global_settings_form(){
    $form = array();
    $form['global_settings'] = array(
        '#type' => 'vertical_tabs',
    );
    //General Settings
    $form['general_settings'] = array(
        '#type' => 'fieldset',
        '#title' => 'General Settings',
        '#group' => 'global_settings',
        '#weight' => 0,
    );
    $form['general_settings']['delay'] = array(
        '#type' => 'textfield',
        '#title' => t('Delay'),
        '#value' => _revslider_default_value('delay',9000),
        '#field_suffix' => 'ms',
        '#description' => t('The time one slide stays on the screen in Milliseconds. Global Setting. You can set per Slide extra local delay time via the data-delay in the slide element (Default: 9000)'),
    );
    $form['general_settings']['startwidth'] = array(
        '#type' => 'textfield',
        '#title' => t('Slider Width'),
        '#field_suffix' => 'px',
        '#value' => _revslider_default_value('startwidth',1170),
        '#description' => t('This Width of the Grid where the Captions are displayed in Pixel. This Width is the Max Width of Slider in Responsive Layout.  In Fullscreen and in FullWidth Layout the Gird will be centered Horizontally in case the Slider is wider then this value.'),
    );
    $form['general_settings']['startheight'] = array(
        '#type' => 'textfield',
        '#title' => t('Slider Height'),
        '#value' => _revslider_default_value('startheight',550),
        '#field_suffix' => 'px',
        '#description' => t('This Height of the Grid where the Captions are displayed in Pixel. This Height is the Max Height of Slider in Responsive Layout.  In Fullscreen and in FullWidth Layout the Gird will be centered Horizontally in case the Slider is wider then this value.'),
    );
    $form['general_settings']['shuffle'] = array(
        '#type' => 'select',
        '#title' => t('Shuffle'),
        '#value' => _revslider_default_value('shuffle','off'),
        '#options' => array('on' => 'Yes', 'off' => 'No'),
    );
    $form['general_settings']['startWithSlide'] = array(
        '#type' => 'textfield',
        '#title' => t('Start width slide'),
        '#value' => _revslider_default_value('startWithSlide',0),
        '#states' => array(
            'visible' => array(
                ':input[name="shuffle"]' => array('value' => 'off'),
            ),
        ),
        '#description' => t('Start with a Predefined Slide (index of the slide, 0 is first slide)'),
    );
    $form['general_settings']['stopAtSlide'] = array(
        '#type' => 'textfield',
        '#title' => t('Stop At Slide'),
        '#value' => _revslider_default_value('stopAtSlide',-1),
        '#description' => t(' Stop Timer if Slide "x" has been Reached. If stopAfterLoops set to 0, then it stops already in the first Loop at slide X which defined. -1 means do not stop at any slide. stopAfterLoops has no sinn in this case.)'),
    );
    $form['layout_settings'] = array(
        '#type' => 'fieldset',
        '#title' => t('Layout'),
        '#group' => 'global_settings',
        '#weight' => 1,
    );
    $form['layout_settings']['slider_layout'] = array(
        '#title' => t('Slider Layout'),
        '#type' => 'select',
        '#options' => array('auto' => 'Auto Responsive', 'fixed' => 'Fixed', 'custom' => 'Custom', 'full' => 'Full Screen'),
        '#value' => _revslider_default_value('slider_layout','auto'),
    );
    $form['layout_settings']['fullWidth'] = array(
        '#title' => t('Fullwidth'),
        '#type' => 'select',
        '#options' => array('on' => 'Yes', 'off' => 'No'),
        '#value' => _revslider_default_value('fullWidth','on'),
        '#description' => t('Defines if the fullwidth/autoresponsive mode is activated'),
    );
    $form['layout_settings']['forceFullWidth'] = array(
        '#title' => t('Force Full Width'),
        '#type' => 'select',
        '#options' => array('on' => 'Yes', 'off' => 'No'),
        '#value' => _revslider_default_value('forceFullWidth','off'),
        '#description' => t('Force the FullWidth Size even if the slider embeded in a boxed container. It can provide higher Performance usage on CPU. Try first set it to \'No\' and use fullwidth container instead of using this option.'),
    );
    $form['layout_settings']['autoHeight'] = array(
        '#title' => t('Auto Height'),
        '#type' => 'select',
        '#options' => array('on' => 'Yes', 'off' => 'No'),
        '#value' => _revslider_default_value('autoHeight','off'),
    );
    $form['layout_settings']['timer'] = array(
        '#title' => t('Timer Bar'),
        '#type' => 'select',
        '#options' => array('none'=>'Hide','top' => 'Top', 'bottom' => 'Bottom'),
        '#value' => _revslider_default_value('timer','top'),
    );
    $form['layout_settings']['shadow'] = array(
        '#title' => t('Box Shadow'),
        '#type' => 'select',
        '#options' => array(0,1,2,3),
        '#value' => _revslider_default_value('shadow',0),
    );
    $form['layout_settings']['dottedOverlay'] = array(
        '#title' => t('Dotted Overlay Size'),
        '#type' => 'select',
        '#options' => array('none' => 'None','twoxtwo'=>'2 x 2 Black','twoxtwowhite'=>'2 x 2 White','threexthree'=>'3 x 3 Black','threexthreewhite'=>'3 x 3 White'),
        '#value' => _revslider_default_value('dottedOverlay','none'),
    );
    $form['layout_settings']['spinner'] = array(
        '#title' => t('Spinner'),
        '#type' => 'select',
        '#options' => array('-1'=>'Off', 'spinner0' => 0, 'spinner1'=>'1','spinner2'=>2,'spinner3'=>3,'spinner4'=>4,'spinner5'=>5),
        '#value' => _revslider_default_value('spinner','spinner1'),
    );
    $form['navigation_settings'] = array(
        '#type' => 'fieldset',
        '#title' => 'Navigation',
        '#group' => 'global_settings',
        '#weight' => 2,
    );
    $form['navigation_settings']['onHoverStop'] = array(
        '#type' => 'select',
        '#title' => t('Stop on hover'),
        '#options' => array('on' => 'Yes', 'off' => 'No'),
        '#value' => _revslider_default_value('onHoverStop','on'),
        '#description' => t('Stop the Timer if mouse is hovering the Slider.  Caption animations are not stopped !! They will just play to the end.'),
    );
    $form['navigation_settings']['onHoverStop'] = array(
        '#type' => 'select',
        '#title' => t('Stop on hover'),
        '#options' => array('on' => 'Yes', 'off' => 'No'),
        '#value' => _revslider_default_value('onHoverStop','on'),
        '#description' => t('Stop the Timer if mouse is hovering the Slider.  Caption animations are not stopped !! They will just play to the end.'),
    );
    $form['navigation_settings']['keyboardNavigation'] = array(
        '#type' => 'select',
        '#title' => t('Keyboard Navigation'),
        '#options' => array('on' => 'Yes', 'off' => 'No'),
        '#value' => _revslider_default_value('keyboardNavigation','on'),
        '#description' => t('Allows to use the Left/Right Arrow for Keyboard navigation when Slider is in Focus.'),
    );
    $form['navigation_settings']['navigationType'] = array(
        '#type' => 'select',
        '#title' => t('Navigation type'),
        '#options' => array('none' => 'None', 'bullet' => 'Bullet','thumb' => 'Thumbnail'),
        '#value' => _revslider_default_value('navigationType','on'),
        '#description' => t('Display type of the "bullet/thumbnail" bar (Default:"none")'),
    );
    $form['navigation_settings']['navigationStyle'] = array(
        '#type' => 'select',
        '#title' => t('Navigation Style'),
        '#options' => array(
            'round' => 'Round',
            'navbar' => 'Navbar',
            'preview1' => 'Preview 1',
            'preview2' => 'Preview 2',
            'preview3' => 'Preview 3',
            'preview4' => 'Preview 4',
            'custom' => 'Custom',
            'round-old' => 'Old Round',
            'square-old' => 'Old Square',
            'navbar-old' => 'Old Navbar',
        ),
        '#states' => array(
            'visible' => array(
                ':input[name="navigationType"]' => array('value' => 'bullet'),
            ),
        ),
        '#value' => _revslider_default_value('navigationStyle','nexttobullets'),
        '#description' => t('Look of the navigation bullets  ** If you choose navbar, we recommend to choose Navigation Arrows to nexttobullets.'),
    );
    $form['navigation_settings']['navigationArrows'] = array(
        '#type' => 'select',
        '#title' => t('Navigation Arrows'),
        '#options' => array('none' => 'None', 'solo' => 'Solo','nexttobullets' => 'With Bullets'),
        '#value' => _revslider_default_value('navigationArrows','nexttobullets'),
        '#description' => t('Display position of the Navigation Arrows (Default: "With Bullets")'),
    );

    $form['navigation_settings']['bullets_thumbnail_position'] = array(
        '#type' => 'fieldset',
        '#title' => t('Bullets / Thumbnail Position'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['navigation_settings']['bullets_thumbnail_position']['navigationHAlign'] = array(
        '#title' => t('Navigation Horizontal Align'),
        '#type' => 'select',
        '#options' => array('left' => 'Left', 'center' => 'Center', 'right' => 'Right'),
        '#value' => _revslider_default_value('navigationHAlign','center'),
        '#description' => t('Horizontal Align of Bullets / Thumbnails'),
    );
    $form['navigation_settings']['bullets_thumbnail_position']['naigationVAlign'] = array(
        '#title' => t('Navigation Vertical Align'),
        '#type' => 'select',
        '#options' => array('top' => 'Top', 'center' => 'Center', 'bottom' => 'Bottom'),
        '#value' => _revslider_default_value('naigationVAlign','bottom'),
        '#description' => t('Vertical Align of Bullets / Thumbnails'),
    );
    $form['navigation_settings']['bullets_thumbnail_position']['navigationHOffset'] = array(
        '#title' => t('Navigation Horizontal Offset'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('navigationHOffset',0),
        '#description' => t('Offset from current Horizontal position of Bullets / Thumbnails negative and positive direction'),
    );
    $form['navigation_settings']['bullets_thumbnail_position']['navigationVOffset'] = array(
        '#title' => t('Navigation Vertical Offset'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('navigationVOffset',0),
        '#description' => t('Offset from current Vertical  position of Bullets / Thumbnails negative and positive direction'),
    );
    //Left arrow position
    $form['navigation_settings']['left_arrow_position'] = array(
        '#type' => 'fieldset',
        '#title' => t('Left Arrow Position'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['navigation_settings']['left_arrow_position']['soloArrowLeftHalign'] = array(
        '#title' => t('Left Arrow Horizontal Align'),
        '#type' => 'select',
        '#options' => array('left' => 'Left', 'center' => 'Center', 'right' => 'Right'),
        '#value' => _revslider_default_value('soloArrowLeftHalign','left'),
        '#description' => t('Horizontal Align of left Arrow (only if arrow is not next to bullets)'),
    );
    $form['navigation_settings']['left_arrow_position']['soloArrowLeftValign'] = array(
        '#title' => t('Left Arrow Vertical Align'),
        '#type' => 'select',
        '#options' => array('top' => 'Top', 'center' => 'Center', 'bottom' => 'Bottom'),
        '#value' => _revslider_default_value('soloArrowLeftValign','center'),
        '#description' => t('Vertical Align of left Arrow (only if arrow is not next to bullets)'),
    );
    $form['navigation_settings']['left_arrow_position']['soloArrowLeftHOffset'] = array(
        '#title' => t('Left Arrow Horizontal Offset'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('soloArrowLeftHOffset',0),
        '#description' => t('Offset from current Horizontal position of of left Arrow  negative and positive direction'),
        '#field_suffix' => 'px',
    );
    $form['navigation_settings']['left_arrow_position']['soloArrowLeftVOffset'] = array(
        '#title' => t('Left Arrow Vertical Offset'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('soloArrowLeftVOffset',0),
        '#description' => t('Offset from current Vertical position of of left Arrow negative and positive direction'),
        '#field_suffix' => 'px',
    );
    //Right arrow position
    $form['navigation_settings']['right_arrow_position'] = array(
        '#type' => 'fieldset',
        '#title' => t('Right Arrow Position'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
    );
    $form['navigation_settings']['right_arrow_position']['soloArrowRightHalign'] = array(
        '#title' => t('Right Arrow Horizontal Align'),
        '#type' => 'select',
        '#options' => array('left' => 'Left', 'center' => 'Center', 'right' => 'Right'),
        '#value' => _revslider_default_value('soloArrowRightHalign','left'),
        '#description' => t('Horizontal Align of right Arrow (only if arrow is not next to bullets)'),
    );
    $form['navigation_settings']['right_arrow_position']['soloArrowRightValign'] = array(
        '#title' => t('Right Arrow Vertical Align'),
        '#type' => 'select',
        '#options' => array('top' => 'Top', 'center' => 'Center', 'bottom' => 'Bottom'),
        '#value' => _revslider_default_value('soloArrowRightValign','center'),
        '#description' => t('Vertical Align of right Arrow (only if arrow is not next to bullets)'),
    );
    $form['navigation_settings']['right_arrow_position']['soloArrowRightHOffset'] = array(
        '#title' => t('Right Arrow Horizontal Offset'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('soloArrowRightHOffset',0),
        '#description' => t('Offset from current Horizontal position of of right Arrow  negative and positive direction'),
        '#field_suffix' => 'px',
    );
    $form['navigation_settings']['right_arrow_position']['soloArrowRightVOffset'] = array(
        '#title' => t('Right Arrow Vertical Offset'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('soloArrowRightVOffset',0),
        '#description' => t('Offset from current Vertical position of of right Arrow negative and positive direction'),
        '#field_suffix' => 'px',
    );

    //Thumbnails tab
    $form['thumbnail_settings'] = array(
        '#type' => 'fieldset',
        '#title' => 'Thumbnails',
        '#group' => 'global_settings',
        '#weight' => 3,
    );
    $form['thumbnail_settings']['thumbWidth'] = array(
        '#title' => t('Thumb Width'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('thumbWidth',100),
    );
    $form['thumbnail_settings']['thumbHeight'] = array(
        '#title' => t('Thumb Height'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('thumbHeight',50),
    );
    $form['thumbnail_settings']['thumbAmount'] = array(
        '#title' => t('Number of thumbnails'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('thumbAmount',5),
    );
    $form['thumbnail_settings']['hideThumbs'] = array(
        '#title' => t('Hide thumbnails'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('hideThumbs', 0),
        '#description' => t('0 - Never hide Thumbs.  1000- 100000 (ms) hide thumbs and navigation arrows, bullets after the predefined ms  (1000ms == 1 sec,  1500 == 1,5 sec etc..)'),
    );

    //Parallax tab
    $form['parallax_settings'] = array(
        '#type' => 'fieldset',
        '#title' => 'Parallax',
        '#group' => 'global_settings',
        '#weight' => 4,
    );
    $form['parallax_settings']['parallax_enabled'] = array(
        '#title' => t('Enable Parallax'),
        '#type' => 'select',
        '#options' => array('on' => 'Yes', 'off' => 'No'),
        '#value' => _revslider_default_value('parallax_enabled', 'on'),
    );
    $form['parallax_settings']['parallaxDisableOnMobile'] = array(
        '#title' => t('Disable on Mobile'),
        '#type' => 'select',
        '#options' => array('on' => 'Yes', 'off' => 'No'),
        '#value' => _revslider_default_value('parallaxDisableOnMobile', 'on'),
        '#description' => t('If set to yes, parallax will be disabled on mobile devices to save performance'),
    );
    $form['parallax_settings']['parallax'] = array(
        '#title' => t('Type'),
        '#type' => 'select',
        '#options' => array('mouse' => 'Mouse', 'scroll' => 'Scroll','mouse+scroll' => 'Both'),
        '#value' => _revslider_default_value('parallax', 'mouse'),
        '#description' => t('Defines on what input type the parallax should react to'),
    );
    $form['parallax_settings']['parallaxBgFreeze'] = array(
        '#title' => t('BG Freeze'),
        '#type' => 'select',
        '#options' => array('on' => 'On', 'off' => 'Off'),
        '#value' => _revslider_default_value('parallaxBgFreeze', 'on'),
        '#description' => t('Setting this to on will freeze the background so that it is not affected by the parallax effect'),
    );
    $form['parallax_settings']['parallaxLevels'] = array(
        '#title' => t('Levels'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('parallaxLevels', '[1,2,3,4,5,6,7,8,9,10]'),
        '#description' => t('An array which defines the Parallax depths (0 - 10). Depending on the value it will define the Strength of the Parallax offsets on mousemove or scroll.'),
    );
    $form['mobile_settings'] = array(
        '#type' => 'fieldset',
        '#title' => 'Mobile Visibility',
        '#group' => 'global_settings',
        '#weight' => 5,
    );
    $form['mobile_settings']['hideSliderAtLimit'] = array(
        '#title' => t('Hide Slider Under Width'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('hideSliderAtLimit',0),
        '#description' => t('Hide the slider under some slider width. Works only in Responsive Style. Not available for Fullwidth.'),
    );
    $form['mobile_settings']['hideCaptionAtLimit'] = array(
        '#title' => t('Hide Slider Under Width'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('hideCaptionAtLimit',0),
        '#description' => t('Hide some defined layers in the layer properties under some slider width.'),
    );
    $form['mobile_settings']['hideAllCaptionAtLimit'] = array(
        '#title' => t('Hide All Layers Under Width'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('hideAllCaptionAtLimit',0),
        '#description' => t('Hide all layers under some slider width.'),
    );
    $form['mobile_settings']['hideArrowsOnMobile'] = array(
        '#title' => t('Hide Arrows on Mobile'),
        '#type' => 'select',
        '#options' => array('on' => 'Yes', 'off' => 'No'),
        '#value' => _revslider_default_value('hideArrowsOnMobile','on'),
        '#description' => t('Show/Hide the Navigation Arrows on Mobile Devices.'),
    );
    $form['mobile_settings']['hideBulletsOnMobile'] = array(
        '#title' => t('Hide Bullets on Mobile'),
        '#type' => 'select',
        '#options' => array('on' => 'Yes', 'off' => 'No'),
        '#value' => _revslider_default_value('hideBulletsOnMobile','on'),
        '#description' => t('Show/Hide the Navigation Bullets on Mobile Devices.'),
    );
    $form['mobile_settings']['hideThumbsOnMobile'] = array(
        '#title' => t('Hide Thumbnails on Mobile'),
        '#type' => 'select',
        '#options' => array('on' => 'Yes', 'off' => 'No'),
        '#value' => _revslider_default_value('hideThumbsOnMobile','on'),
        '#description' => t('Show/Hide the Thumbnail on Mobile Devices.'),
    );
    $form['mobile_settings']['hideThumbsUnderResoluition'] = array(
        '#title' => t('Hide Thumbs Under Width'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('hideThumbsUnderResoluition',0),
        '#field_suffix' => 'px',
        '#description' => t('Hide the Thumbnails on Mobile Devices under some slider width'),
    );
    $form['mobile_settings']['hideNavDelayOnMobile'] = array(
        '#title' => t('Hide Mobile Nav After'),
        '#type' => 'textfield',
        '#value' => _revslider_default_value('hideNavDelayOnMobile',1500),
        '#field_suffix' => 'ms',
        '#description' => t('Time after that the Navigation and the Thumbs will be hidden on mobile devices(Default: 1500 ms)'),
    );
    $form['custom_font_css'] = array(
        '#type' => 'fieldset',
        '#title' => 'Custom fonts/CSS',
        '#group' => 'global_settings',
        '#weight' => 6,
    );

    $form['custom_font_css']['google_fonts'] = array(
        '#type' => 'textfield',
        '#title' => t('Import Google Fonts'),
        '#value' => _revslider_default_value('google_fonts', ''),
        '#description' => t('Enter google font url. Example: http://fonts.googleapis.com/css?family=Open+Sans:300,400,600,700,800'),
    );
    $form['custom_font_css']['custom_css'] = array(
        '#type' => 'textarea',
        '#title' => t('Custom CSS'),
        '#value' => _revslider_default_value('custom_css', ''),
    );
    return $form;
}

function _revslider_default_value($name, $default){
    return isset($_REQUEST[$name])?$_REQUEST[$name]:$default;
}
/*
autoHeight

	"off"
dottedOverlay

	"none"
drag_block_vertical

	"false"
forceFullWidth

	"on"
fullScreen

	"on"
fullScreenAlignForce

	"off"
fullScreenOffset

	"0px"
fullScreenOffsetContainer

	""
fullWidth

	"on"
hideAllCaptionAtLimit

	0
hideArrowsOnMobile

	"on"
hideBulletsOnMobile

	"on"
hideCaptionAtLimit

	0
hideNavDelayOnMobile

	1500
hideSliderAtLimit

	0
hideThumbs

	0
hideThumbsOnMobile

	"on"
hideThumbsUnderResoluition

	0
hideTimerBar

	"off"
keyboardNavigation

	"off"
loopSingleSlide

	true
minHeight

	"400"
naigationVAlign

	"bottom"
navigationArrows

	"solo"
navigationHAlign

	"center"
navigationHOffset

	"0"
navigationStyle

	"preview4"
navigationType

	"bullet"
navigationVOffset

	20
onHoverStop

	"on"
panZoomDisableOnMobile

	"on"
parallax

	"mouse"
parallaxBgFreeze

	"on"
parallaxDisableOnMobile

	"on"
parallaxLevels

	"[7,4,3,2,5,4,3,2,1,0]"
parallax_enabled

	"on"
shadow

	"0"
simplifyAll

	"on"
slider_layout

	"full"
soloArrowLeftHOffset

	20
soloArrowLeftHalign

	"left"
soloArrowLeftVOffset

	0
soloArrowLeftValign

	"center"
soloArrowRightHOffset

	20
soloArrowRightHalign

	"right"
soloArrowRightVOffset

	0
soloArrowRightValign

	"center"
spinner

	"spinner1"
startWithSlide

	"1"
startheight

	"700"
startwidth

	"1170"
stopAfterLoops

	0
stopAtSlide

	1
swipe_max_touches

	1
swipe_min_touches

	1
swipe_velocity

	0.7
thumbAmount

	5
thumbHeight

	50
thumbWidth

	100
timer

	"bottom"
touchenabled

	"on"
*/
