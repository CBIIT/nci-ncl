<?php

/**
 * @file
 */

/**
 * Get default slider revolution settings
 */
function revslider_get_settings($key = NULL) {
  $easings = array(
    'New Easings' => array(
      'Linear.easeNone' => 'Linear.easeNone',
      'Power0.easeIn' => 'Power0.easeIn',
      'Power0.easeInOut' => 'Power0.easeInOut',
      'Power0.easeOut' => 'Power0.easeOut',
      'Power1.easeIn' => 'Power1.easeIn',
      'Power1.easeInOut' => 'Power1.easeInOut',
      'Power1.easeOut' => 'Power1.easeOut',
      'Power2.easeIn' => 'Power2.easeIn',
      'Power2.easeInOut' => 'Power2.easeInOut',
      'Power2.easeOut' => 'Power2.easeOut',
      'Power3.easeIn' => 'Power3.easeIn',
      'Power3.easeInOut' => 'Power3.easeInOut',
      'Power3.easeOut' => 'Power3.easeOut',
      'Power4.easeIn' => 'Power4.easeIn',
      'Power4.easeInOut' => 'Power4.easeInOut',
      'Power4.easeOut' => 'Power4.easeOut',
      'Quad.easeIn' => 'Quad.easeIn',
      'Quad.easeInOut' => 'Quad.easeInOut',
      'Quad.easeOut' => 'Quad.easeOut',
      'Cubic.easeIn' => 'Cubic.easeIn',
      'Cubic.easeInOut' => 'Cubic.easeInOut',
      'Cubic.easeOut' => 'Cubic.easeOut',
      'Quart.easeIn' => 'Quart.easeIn',
      'Quart.easeInOut' => 'Quart.easeInOut',
      'Quart.easeOut' => 'Quart.easeOut',
      'Quint.easeIn' => 'Quint.easeIn',
      'Quint.easeInOut' => 'Quint.easeInOut',
      'Quint.easeOut' => 'Quint.easeOut',
      'Strong.easeIn' => 'Strong.easeIn',
      'Strong.easeInOut' => 'Strong.easeInOut',
      'Strong.easeOut' => 'Strong.easeOut',
      'Back.easeIn' => 'Back.easeIn',
      'Back.easeInOut' => 'Back.easeInOut',
      'Back.easeOut' => 'Back.easeOut',
      'Bounce.easeIn' => 'Bounce.easeIn',
      'Bounce.easeInOut' => 'Bounce.easeInOut',
      'Bounce.easeOut' => 'Bounce.easeOut',
      'Circ.easeIn' => 'Circ.easeIn',
      'Circ.easeInOut' => 'Circ.easeInOut',
      'Circ.easeOut' => 'Circ.easeOut',
      'Elastic.easeIn' => 'Elastic.easeIn',
      'Elastic.easeInOut' => 'Elastic.easeInOut',
      'Elastic.easeOut' => 'Elastic.easeOut',
      'Expo.easeIn' => 'Expo.easeIn',
      'Expo.easeInOut' => 'Expo.easeInOut',
      'Expo.easeOut' => 'Expo.easeOut',
      'Sine.easeIn' => 'Sine.easeIn',
      'Sine.easeInOut' => 'Sine.easeInOut',
      'Sine.easeOut' => 'Sine.easeOut',
      'SlowMo.ease' => 'SlowMo.ease',
    ),
    'Old Easings' => array(
      'easeOutBack' => 'easeOutBack',
      'easeInQuad' => 'easeInQuad',
      'easeOutQuad' => 'easeOutQuad',
      'easeInOutQuad' => 'easeInOutQuad',
      'easeInCubic' => 'easeInCubic',
      'easeOutCubic' => 'easeOutCubic',
      'easeInOutCubic' => 'easeInOutCubic',
      'easeInQuart' => 'easeInQuart',
      'easeOutQuart' => 'easeOutQuart',
      'easeInOutQuart' => 'easeInOutQuart',
      'easeInQuint' => 'easeInQuint',
      'easeOutQuint' => 'easeOutQuint',
      'easeInOutQuint' => 'easeInOutQuint',
      'easeInSine' => 'easeInSine',
      'easeOutSine' => 'easeOutSine',
      'easeInOutSine' => 'easeInOutSine',
      'easeInExpo' => 'easeInExpo',
      'easeOutExpo' => 'easeOutExpo',
      'easeInOutExpo' => 'easeInOutExpo',
      'easeInCirc' => 'easeInCirc',
      'easeOutCirc' => 'easeOutCirc',
      'easeInOutCirc' => 'easeInOutCirc',
      'easeInElastic' => 'easeInElastic',
      'easeOutElastic' => 'easeOutElastic',
      'easeInOutElastic' => 'easeInOutElastic',
      'easeInBack' => 'easeInBack',
      'easeOutBack' => 'easeOutBack',
      'easeInOutBack' => 'easeInOutBack',
      'easeInBounce' => 'easeInBounce',
      'easeOutBounce' => 'easeOutBounce',
      'easeInOutBounce' => 'easeInOutBounce',
    )
  );

  $transitions = array(
    'Flat Transitions' => array(
      'slideup' => 'Slide To Top',
      'slidedown' => 'Slide To Bottom',
      'slideright' => 'Slide To Right',
      'slideleft' => 'Slide To Left',
      'slidehorizontal' => 'Slide Horizontal (depending on Next/Previous)',
      'slidevertical' => 'Slide Vertical (depending on Next/Previous)',
      'boxslide' => 'Slide Boxes',
      'slotslide-horizontal' => 'Slide Slots Horizontal',
      'slotslide-vertical' => 'Slide Slots Vertical',
      'boxfade' => 'Fade Boxes',
      'slotfade-horizontal' => 'Fade Slots Horizontal',
      'slotfade-vertical' => 'Fade Slots Vertical',
      'fadefromright' => 'Fade and Slide from Right',
      'fadefromleft' => 'Fade and Slide from Left',
      'fadefromtop' => 'Fade and Slide from Top',
      'fadefrombottom' => 'Fade and Slide from Bottom',
      'fadetoleftfadefromright' => 'Fade To Left and Fade From Right',
      'fadetorightfadefromleft' => 'Fade To Right and Fade From Left',
      'fadetotopfadefrombottom' => 'Fade To Top and Fade From Bottom',
      'fadetobottomfadefromtop' => 'Fade To Bottom and Fade From Top',
      'parallaxtoright' => 'Parallax to Right',
      'parallaxtoleft' => 'Parallax to Left',
      'parallaxtotop' => 'Parallax to Top',
      'parallaxtobottom' => 'Parallax to Bottom',
      'scaledownfromright' => 'Zoom Out and Fade From Right',
      'scaledownfromleft' => 'Zoom Out and Fade From Left',
      'scaledownfromtop' => 'Zoom Out and Fade From Top',
      'scaledownfrombottom' => 'Zoom Out and Fade From Bottom',
      'zoomout' => 'ZoomOut',
      'zoomin' => 'ZoomIn',
      'slotzoom-horizontal' => 'Zoom Slots Horizontal',
      'slotzoom-vertical' => 'Zoom Slots Vertical',
      'fade' => 'Fade',
      'random-static' => 'Random Flat',
      'random' => 'Random Flat and Premium'
    ),
    'Premium Transitions' => array(
      'curtain-1' => 'Curtain from Left',
      'curtain-2' => 'Curtain from Right',
      'curtain-3' => 'Curtain from Middle',
      '3dcurtain-horizontal' => '3D Curtain Horizontal',
      '3dcurtain-vertical' => '3D Curtain Vertical',
      'cube' => 'Cube Vertical',
      'cube-horizontal' => 'Cube Horizontal',
      'incube' => 'In Cube Vertical',
      'incube-horizontal' => 'In Cube Horizontal',
      'turnoff' => 'TurnOff Horizontal',
      'papercut' => 'Paper Cut',
      'flyin' => 'Fly In',
      'random-premium' => 'Random Premium',
      'random' => 'Random Flat and Premium',
    ),
  );

  $styling_cations = array(
    "" => t('None'),
    "big_organic_white_transparent" => "big_organic_white_transparent",
    "black" => "black",
    "black-organic" => "black-organic",
    "boxshadow" => "boxshadow",
    "excerpt" => "excerpt",
    "grassfloor" => "grassfloor",
    "large_bg_black" => "large_bg_black",
    "large_bold_black" => "large_bold_black",
    "large_bold_darkblue" => "large_bold_darkblue",
    "large_bold_grey" => "large_bold_grey",
    "large_bold_white" => "large_bold_white",
    "large_text" => "large_text",
    "largeblackbg" => "largeblackbg",
    "largegreenbg" => "largegreenbg",
    "largepinkbg" => "largepinkbg",
    "largewhitebg" => "largewhitebg",
    "lightgrey_divider" => "lightgrey_divider",
    "medium_bg_asbestos" => "medium_bg_asbestos",
    "medium_bg_darkblue" => "medium_bg_darkblue",
    "medium_bg_orange" => "medium_bg_orange",
    "medium_bg_red" => "medium_bg_red",
    "medium_bold_orange" => "medium_bold_orange",
    "medium_bold_red" => "medium_bold_red",
    "medium_grey" => "medium_grey",
    "medium_light_black" => "medium_light_black",
    "medium_light_red" => "medium_light_red",
    "medium_light_white" => "medium_light_white",
    "medium_text" => "medium_text",
    "medium_thin_grey" => "medium_thin_grey",
    "mediumlarge_light_darkblue" => "mediumlarge_light_darkblue",
    "mediumlarge_light_white" => "mediumlarge_light_white",
    "mediumlarge_light_white_center" => "mediumlarge_light_white_center",
    "mediumwhitebg" => "mediumwhitebg",
    "modern_big_bluebg" => "modern_big_bluebg",
    "modern_big_redbg" => "modern_big_redbg",
    "modern_medium_fat" => "modern_medium_fat",
    "modern_medium_fat_white" => "modern_medium_fat_white",
    "modern_medium_light" => "modern_medium_light",
    "modern_small_text_dark" => "modern_small_text_dark",
    "noshadow" => "noshadow",
    "roundedimage" => "roundedimage",
    "small_light_white" => "small_light_white",
    "small_text" => "small_text",
    "small_thin_grey" => "small_thin_grey",
    "thinheadline_dark" => "thinheadline_dark",
    "thintext_dark" => "thintext_dark",
    "very_big_black" => "very_big_black",
    "very_big_white" => "very_big_white",
    "very_large_text" => "very_large_text",
  );

  $positions = array(
    'left top' => 'left top',
    'left center' => 'left center',
    'left bottom' => 'left bottom',
    'center top' => 'center top',
    'center center' => 'center center',
    'center bottom' => 'center bottom',
    'right top' => 'right top',
    'right center' => 'right center',
    'right bottom' => 'right bottom'
  );

  $incoming_animation = array(
    'sft' => t('Short from Top'),
    'sfb' => t('Short from Bottom'),
    'sfr' => t('Short from Right'),
    'sfl' => t('Short from Left'),
    'lft' => t('Long from Top'),
    'lfb' => t('Long from Bottom'),
    'lfr' => t('Long from Right'),
    'lfl' => t('Long from Left'),
    'skewfromleft' => t('Skew from Left'),
    'skewfromright' => t('Skew from Right'),
    'skewfromleftshort' => t('Skew Short from Left'),
    'skewfromrightshort' => t('Skew Short from Right'),
    'fade' => t('Fading'),
    'randomrotate' => t('Fade in, Rotate from a Random position and Degree'),
    'customin' => t('Custom Incoming Animation - see below all data settings'),
  );
  $outgoing_animation = array(
    '' => t('None'),
    'stt' => t('Short to Top'),
    'stb' => t('Short to Bottom'),
    'str' => t('Short to Right'),
    'stl' => t('Short to Left'),
    'ltt' => t('Long to Top'),
    'ltb' => t('Long to Bottom'),
    'ltr' => t('Long to Right'),
    'ltl' => t('Long to Left'),
    'skewtoleft' => t('Skew to Left'),
    'skewtoright' => t('Skew to Right'),
    'skewtoleftshort' => t('Skew Short to Left'),
    'skewtorightshort' => t('Skew Short to Right'),
    'fadeout' => t('fading'),
    'randomrotateout' => t('Fade in, Rotate from a Random position and Degree'),
    'customout' => t('Custom Outgoing Animation'),
  );

  $dottedoverlay = array(
    "none" => t("None"),
    "twoxtwo" => t("2 x 2 Black"),
    "threexthree" => t("3 x 3 Black"),
    "twoxtwowhite" => t("2 x 2 White"),
    "threexthreewhite" => t("3 x 3 White")
  );

  $light = array(
    'on' => t('On'),
    'off' => t('Off')
  );

  $boolean = array(
    'true' => t('True'),
    'false' => t('False')
  );

  $split = array(
    'none' => 'None',
    "words" => t("words"),
    "chars" => t("chars"),
    "lines" => t("lines"),
  );

  $corners = array(
    '' => 'No Corner',
    'curved' => t('Sharp'),
    'reverced' => t('Sharp Reversed'),
  );

  $links = array(
    '' => t('None'),
    'next' => t('-- Next slide --'),
    'back' => t('-- Previous slide --'),
  );

  $loop_animate = array(
    '' => t('Disabled'),
    'rs-wave' => t('rs-wave'),
    'rs-pulse' => t('rs-pulse'),
    'rs-pendulum' => t('rs-pendulum'),
    'rs-slideloop' => t('rs-slideloop'),
    'rs-rotate' => t('rs-rotate'),
  );

  $parallax_level = array('' => t('No Movement'));
  for ($i = 1; $i <= 10; $i++) {
    $parallax_level['rs-parallaxlevel-'. $i] = $i;
  }

  $settings['options'] = array(
    '#name' => t('Options'),
    '#type' => 'horizontal',
    'global' => array(
      '#name' => t('General Settings'),
      'delay' => array(
        '#name' => t('Delay'),
        '#default_value' => '9000',
        '#description' => 'The time one slide stays on the screen in Milliseconds. Global Setting. You can set per Slide extra local delay time via the data-delay in the &lt;li&gt; element (Default: 9000)'
      ),
      'shuffle' => array(
        '#name' => t('Shuffle Mode'),
        '#default_value' => 'off',
        '#options' => $light,
        '#description' => t('Turn Shuffle Mode on and off! Will be randomized only once at the start.'),
      ),
      'startheight' => array(
        '#name' => t('Grid Height'),
        '#default_value' => '500',
        '#description' => 'This Height of the Grid where the Captions are displayed in Pixel. This Height is the Max height of Slider in Fullwidth Layout and in Responsive Layout.  In Fullscreen Layout the Gird will be centered Vertically in case the Slider is higher then this value.'
      ),
      'startwidth' => array(
        '#name' => t('Grid Width'),
        '#default_value' => '960',
        '#description' => 'This Height of the Grid where the Captions are displayed in Pixel. This Width is the Max Width of Slider in Responsive Layout.  In Fullscreen and in FullWidth Layout the Gird will be centered Horizontally in case the Slider is wider then this value.'
      ),
      'startWithSlide' => array(
        '#name' => t('Start Width Slide'),
        '#default_value' => 0,
        '#description' => 'Start with a Predefined Slide (index of the slide)'
      ),
    ),
    'navigation' => array(
      '#name' => t('Navigation'),
      'onHoverStop' => array(
        '#name' => t('Stop On Hover'),
        '#default_value' => 'on',
        '#options' => $light,
        '#description' => 'Stop the Timer if mouse is hovering the Slider.  Caption animations are not stopped !! They will just play to the end.'
      ),
      'keyboardNavigation' => array(
        '#name' => t('Keyboard Navigation'),
        '#default_value' => 'on',
        '#options' => $light,
        '#description' => 'Allows to use the Left/Right Arrow for Keyboard navigation when Slider is in Focus.'
      ),
      'navigationType' => array(
        '#name' => t('Bullet Type'),
        '#default_value' => 'bullet',
        '#options' => array(
          'none' => t('None'),
          'bullet' => t('Bullet'),
          'thumb' => t('Thumb'),
        ),
        '#description' => 'Display type of the \'bullet/thumbnail\' bar (Default:\'none\')'
      ),
      'navigationArrows' => array(
        '#name' => t('Navigation Arrows'),
        '#default_value' => 'solo',
        '#options' => array(
          'none' => t('None'),
          'nexttobullets' => t('Next To Bullets'),
          'solo' => t('Solo')
        ),
        '#description' => 'Display position of the Navigation Arrows (Default: \'nexttobullets\'). Possible values are \'nexttobullets\', \'solo\'. Nexttobullets - arrows added next to the bullets left and right, solo - arrows can be independent positioned, see further options'
      ),
      'navigationStyle' => array(
        '#name' => t('Navigation Style'),
        '#default_value' => 'round',
        '#options' => array(
          'preview1' => t('preview1'),
          'preview2' => t('preview2'),
          'preview3' => t('preview3'),
          'preview4' => t('preview4'),
          'round' => t('round'),
          'square' => t('square'),
          'round-old' => t('round-old'),
          'square-old' => t('square-old'),
          'navbar-old' => t('navbar-old')
        ),
        '#description' => 'Look of the navigation bullets if navigationType \'bullet\' selected.'
      ),

      'bullet_type_position' => array(
        'navigationHAlign' => array(
          '#name' => t('Navigation Horizontal Align'),
          '#default_value' => 'center',
          '#options' => array(
            'left' => t('Left'),
            'center' => t('Center'),
            'right' => t('Right')
          ),
          '#description' => 'Vertical and Horizontal Align of the Navigation bullets / thumbs (depending on which Style has been selected).  Possible values navigationHAlign: \'left\',\'center\',\'right\''
        ),
        'naigationVAlign' => array(
          '#name' => t('Navigation Vertical Align'),
          '#default_value' => 'bottom',
          '#options' => array(
            'top' => t('Top'),
            'center' => t('Center'),
            'bottom' => t('Bottom')
          ),
          '#description' => 'Vertical and Horizontal Align of the Navigation bullets / thumbs (depending on which Style has been selected).  Possible values naigationVAlign: \'top\',\'center\',\'bottom\''
        ),
        'navigationHOffset' => array(
          '#name' => t('Navigation Horizontal Offset'),
          '#default_value' => '30',
          '#description' => 'The Offset position of the navigation depending on the aligned position.  from -1000 to +1000 any value in px.   i.e. -30'
        ),
        'navigationVOffset' => array(
          '#name' => t('Navigation Vertical Offset'),
          '#default_value' => '30',
          '#description' => 'The Offset position of the navigation depending on the aligned position.  from -1000 to +1000 any value in px.   i.e. -30'
        ),
      ),

      'left_arrow_position' => array(
        '#name' => t('Left Arrow Position'),
        'soloArrowLeftHalign' => array(
          '#name' => t('Left Arrow Horizontal Align'),
          '#default_value' => 'left',
          '#description' => 'Vertical and Horizontal Align of the Navigation Arrows (left and right independent!) Possible values navigationHAlign: \'left\',\'center\',\'right\'  and naigationVAlign: \'top\',\'center\',\'bottom\' '
        ),
        'soloArrowLeftValign' => array(
          '#name' => t('Left Arrow Vertical Align'),
          '#default_value' => 'center',
          '#description' => 'Vertical and Horizontal Align of the Navigation Arrows (left and right independent!) Possible values navigationHAlign: \'left\',\'center\',\'right\'  and naigationVAlign: \'top\',\'center\',\'bottom\' '
        ),
        'soloArrowLeftHOffset' => array(
          '#name' => t('Left Arrow Horizontal Offset'),
          '#default_value' => '20',
          '#description' => 'The Offset position of the navigation depending on the aligned position.  from -1000 to +1000 any value in px.   i.e. -30   Each Arrow independent'
        ),
        'soloArrowLeftVOffset' => array(
          '#name' => t('Left Arrow Vertical Offset'),
          '#default_value' => 0,
          '#description' => 'The Offset position of the navigation depending on the aligned position.  from -1000 to +1000 any value in px.   i.e. -30   Each Arrow independent'
        ),
      ),

      'right_arrow_position' => array(
        '#name' => t('Right Arrow Position'),
        'soloArrowRightHalign' => array(
          '#name' => t('Right Arrow Horizontal Align'),
          '#default_value' => 'right',
          '#description' => 'Vertical and Horizontal Align of the Navigation Arrows (left and right independent!) Possible values navigationHAlign: \'left\',\'center\',\'right\'  and naigationVAlign: \'top\',\'center\',\'bottom\' '
        ),

        'soloArrowRightValign' => array(
          '#name' => t('Right Arrow Vertical Align'),
          '#default_value' => 'center',
          '#description' => 'Vertical and Horizontal Align of the Navigation Arrows (left and right independent!) Possible values navigationHAlign: \'left\',\'center\',\'right\'  and naigationVAlign: \'top\',\'center\',\'bottom\' '
        ),

        'soloArrowRightHOffset' => array(
          '#name' => t('Right Arrow Horizontal Offset'),
          '#default_value' => '20',
          '#description' => 'The Offset position of the navigation depending on the aligned position.  from -1000 to +1000 any value in px.   i.e. -30   Each Arrow independent'
        ),
        'soloArrowRightVOffset' => array(
          '#name' => t('Right Arrow Vertical Offset'),
          '#default_value' => 0,
          '#description' => 'The Offset position of the navigation depending on the aligned position.  from -1000 to +1000 any value in px.   i.e. -30   Each Arrow independent'
        ),
      ),

      'touchenabled' => array(
        '#default_value' => 'on',
        '#options' => $light,
        '#description' => 'Enable Swipe Function on touch devices (Default: \'on\')'
      ),
      'swipe_velocity' => array(
        '#default_value' => '0.7',
        '#description' => 'The Sensibility of Swipe Gesture (lower is more sensible) (Default: 0.7)'
      ),
      'swipe_max_touches' => array(
        '#default_value' => 1,
        '#options' => array_combine(range(1,5), range(1,5)),
        '#description' => 'Max Amount of Fingers to touch (Default: 1)'
      ),
      'swipe_min_touches' => array(
        '#default_value' => 1,
        '#options' => array_combine(range(1,5), range(1,5)),
        '#description' => 'Min Amount of Fingers to touch (Default: 1)'
      ),
      'drag_block_vertical' => array(
        '#default_value' => false,
        '#options' => $boolean,
        '#description' => 'Prevent Vertical Scroll on Drag (Default: false)'
      )
    ),

    'loops' => array(
      '#name' => t('Loops'),
      //
      'stopAtSlide' => array(
        '#name' => t('Stop At Slide'),
        '#default_value' => '-1',
        '#description' => 'Stop Timer if Slide \'x\' has been Reached. If stopAfterLoops set to 0, then it stops already in the first Loop at slide X which defined. -1 means do not stop at any slide. stopAfterLoops has no sinn in this case.'
      ),
      'stopAfterLoops' => array(
        '#name' => t('Stop After Loops'),
        '#default_value' => '-1',
        '#description' => 'Stop Timer if All slides has been played \'x\' times. IT will stop at THe slide which is defined via stopAtSlide:x, if set to -1 slide never stop automatic'
      ),
      'loopSingleSlide' => array(
        '#name' => t('Loop Single Slide'),
        '#default_value' => 'true',
        '#options' => $boolean,
        '#description' => ''
      )
    ),

    'thumbnails' => array(
      '#name' => t('Thumbnails'),
      'thumbWidth' => array(
        '#name' => t('Thumb Width'),
        '#default_value' => '100',
        '#description' => 'The width and height of the thumbs in pixel. Thumbs are not responsive from basic. For Responsive Thumbs you will need to create media qury based thumb sizes.'
      ),
      'thumbHeight' => array(
        '#name' => t('Thumb Height'),
        '#default_value' => '50',
        '#description' => 'The width and height of the thumbs in pixel. Thumbs are not responsive from basic. For Responsive Thumbs you will need to create media qury based thumb sizes.'
      ),
      'thumbAmount' => array(
        '#name' => t('Thumb Amount'),
        '#default_value' => '3',
        '#description' => 'The Amount of visible Thumbs in the same time.  The rest of the thumbs are only visible on hover, or at slide change.'
      ),
      'hideThumbs' => array(
        '#name' => t('Hide Thumb'),
        '#default_value' => 0,
        '#description' => '0 - Never hide Thumbs.  1000- 100000 (ms) hide thumbs and navigation arrows, bullets after the predefined ms  (1000ms == 1 sec,  1500 == 1,5 sec etc..)'
      ),
    ),

    'mobile' => array(
      '#name' => t('Mobile Visibility'),
      'hideSliderAtLimit' => array(
        '#name' => t('Hide Slider Under Width'),
        '#default_value' => 0,
        '#description' => 'Hide the whole slider, and stop also functions if Width of Browser is less than this value'
      ),
      'hideCaptionAtLimit' => array(
        '#name' => t('Hide Defined Layers Under Width'),
        '#default_value' => 0,
        '#description' => 'It Defines if a caption should be shown under a Screen Resolution ( Basod on The Width of Browser)'
      ),
      'hideAllCaptionAtLimit' => array(
        '#name' => t('Hide All Layers Under Width'),
        '#default_value' => 0,
        '#description' => 'Hide all The Captions if Width of Browser is less then this value'
      ),

      'hideArrowsOnMobile' => array(
        '#name' => t('Hide Arrows on Mobile'),
        '#default_value' => 'off',
        '#options' => $light,
        '#description' => 'If set to \'on\', Arrows are not shown on Mobile Devices'
      ),
      'hideBulletsOnMobile' => array(
        '#name' => t('Hide Bullets on Mobile'),
        '#default_value' => 'off',
        '#options' => $light,
        '#description' => 'If set to \'on\', Bullets are not shown on Mobile Devices'
      ),
      'hideThumbsOnMobile' => array(
        '#name' => t('Hide Thumbnails on Mobile'),
        '#default_value' => 'off',
        '#options' => $light,
        '#description' => 'If set to \'on\', Thumbs are not shown on Mobile Devices'
      ),
      'hideThumbsUnderResoluition' => array(
        '#name' => t('Hide Thumbs Under Mobile'),
        '#default_value' => 0,
        '#description' => 'Possible Values: 0 - 1900 - defines under which resolution the Thumbs should be hidden. (only if hideThumbonMobile set to off'
      ),
      'hideNavDelayOnMobile' => array(
        '#name' => t('Hide Mobile Nav After'),
        '#default_value' => '1500',
        '#description' => 'Hide all navigation after a while on Mobile (touch and release events based)'
      ),
    ),

    'layout_tyles' => array(
      '#name' => t('Layout & Styles'),
      'spinner' => array(
        '#name' => t('Spinner'),
        '#default_value' => '',
        '#options' => array(
          "spinner1" => t("spinner1"),
          "spinner2" => t("spinner2"),
          "spinner3" => t("spinner3"),
          "spinner4" => t("spinner4"),
          "spinner5" => t("spinner5")
        ),
        '#description' => 'The Layout of Loader. If not defined, it will use the basic spinner.'
      ),
      'slider_layout' => array(
        '#name' => t('Slider Layout'),
        '#default_value' => 'auto',
        '#options' => array(
          'auto' => 'Auto Responsive',
          'fixed' => 'Fixed',
          'custom' => 'Custom',
          'full' => 'Full Screen',
        ),
      ),

      'hideTimerBar' => array(
        '#name' => t('Hide Time Bar'),
        '#default_value' => 'off',
        '#options' => $light,
        '#description' => 'It will hide or show the banner timer'
      ),
      'timer ' => array(
        '#name' => t('Timer'),
        '#default_value' => 'top',
        '#options' => array('top'=>'Top','bottom'=>'Bottom'),
        //'#description' => 'It will hide or show the banner timer'
      ),
      'fullWidth' => array(
        '#name' => t('Full Width'),
        '#default_value' => 'on',
        '#options' => $light,
        '#description' => 'Defines if the fullwidth/autoresponsive mode is activated'
      ),
      'autoHeight' => array(
        '#name' => t('Unlimited Height'),
        '#default_value' => 'off',
        '#options' => $light,
        '#description' => 'Defines if in fullwidth mode the height of the Slider proportional always can grow. If it is set to \'off\' the max height is == startheight'
      ),
      'minHeight' => array(
        '#name' => t('Min. Height'),
        '#default_value' => '0',
        '#description' => 'Possible Values: 0 - 9999 - defines the min height of the Slider. The Slider container height will never be smaller than this value. The Content container is still shrinks linear to the browser width and original width of COntainer, and will be centered vertically in the Slider'
      ),
      'fullScreenAlignForce' => array(
        '#name' => t('Force FullScreen Align'),
        '#default_value' => 'off',
        '#options' => $light,
        '#description' => 'Allowed only in FullScreen Mode. It lets the Caption Grid to be the full screen, means all position should happen with aligns and offsets. This allow you to use the faresst corner of the slider to present any caption there.'
      ),
      'forceFullWidth' => array(
        '#name' => t('Force Full Width'),
        '#default_value' => 'off',
        '#options' => $light,
        '#description' => 'Force the FullWidth Size even if the slider embeded in a boxed container. It can provide higher Performance usage on CPU. Try first set it to \'off\' and use fullwidth container instead of using this option.'
      ),
      'fullScreen' => array(
        '#name' => t('Full Screen'),
        '#default_value' => 'off',
        '#options' => $light,
        '#description' => 'Defines if the fullscreen mode is activated'
      ),
      'fullScreenOffsetContainer' => array(
        '#name' => t('Offset Containers'),
        '#default_value' => '',
        '#description' => 'The value is a Container ID or Class i.e. \'#topheader\'  - The Height of Fullheight will be increased with this Container height !'
      ),
      'fullScreenOffset' => array(
        '#name' => t('Offset Size'),
        '#default_value' => '0px',
        '#description' => 'A px or % value which will be added/reduced of the Full Height Container calculation.'
      ),
      'shadow' => array(
        '#name' => t('Shadow'),
        '#default_value' => 0,
        '#options' => range(0, 3),
        '#description' => 'Possible values: 0,1,2,3  (0 == no Shadow, 1,2,3 - Different Shadow Types)'
      ),
      'dottedOverlay' => array(
        '#name' => t('Dotted Overlay'),
        '#default_value' => 'none',
        '#options' => $dottedoverlay,
        '#description' => 'Creates a Dotted Overlay for the Background images extra. Best use for FullScreen / fullwidth sliders, where images are too pixaleted.'
      )
    ),

    'parallax' => array(
      '#name' => t('Parallax Settings'),
      'parallax_enabled' => array(
        '#name' => t('Enable Parallax'),
        '#default_value' => 'off',
        '#options' => $light,
      ),
      'parallaxDisableOnMobile' => array(
        '#name' => t('Disable on Mobile'),
        '#default_value' => 'off',
        '#options' => $light,
        '#description' => 'Turn on/ off Parallax Effect on Mobile Devices'
      ),
      'parallax' => array(
        '#type' => 'select',
        '#name' => 'Type',
        '#default_value' => 'mouse',
        '#options' => array(
          'mouse' => t('Mouse'),
          'scroll' => t('Scroll'),
          'mouse+scroll' => t('Mouse & Scroll'),
        ),
        '#description' => 'How the Parallax should act. On Mouse Hover movements and Tilts on Mobile Devices, or on Scroll (scroll is disabled on Mobiles !)'
      ),
      'parallaxBgFreeze' => array(
        '#name' => t('BG Freeze'),
        '#default_value' => 'on',
        '#options' => $light,
        '#description' => 'If it is off, the Main slide images will also move with Parallax Level 1 on Scroll.'
      ),

      'parallaxLevels' => array(
        '#default_value' => '[10,7,4,3,2,5,4,3,2,1]',
        '#description' => 'An array which defines the Parallax depths (0 - 10). Depending on the value it will define the Strength of the Parallax offsets on mousemove or scroll. In Layers you can use the class like rs-parallaxlevel-1 for the different levels. If one tp-caption layer has rs-parallaxlevel-X (x 1-10) then it activates the Parallax movements on that layer. - Creates a Dotted Overlay for the Background images extra. Best use for FullScreen / fullwidth sliders, where images are too pixaleted.'
      ),
    ),
    'pan_zoom' => array(
      '#name' => t('Pan Zoom Settings'),
      'panZoomDisableOnMobile' => array(
        '#default_value' => 'off',
        '#options' => $light,
        '#description' => 'Turn on/ off Pan Zoom Effects on Mobile Devices'
      )
    ),
    'further' => array(
      '#name' => t('Further Options'),
      'simplifyAll' => array(
        '#default_value' => 'off',
        '#options' => $light,
        '#description' => 'Set all Animation on older Browsers like IE8 and iOS4 Safari to Fade, without splitting letters to save performance'
      )
    )
  );

  $settings['slides'] = array(
    '#type' => 'horizontal',
    // Main image
    'main_image' => array(
      '#name' => t('Slider Main Image / Background'),
      'src' => array(
        '#name' => t('Background'),
        '#default_value' => '',
        '#data_type' => 'media',
      ),
      'data-lazyload' => array(
        '#name' => t('Lazy Loading'),
        '#default_value' => '',
        '#description' => t('Here you need to declare the Path and File name of the image you wish to load as Main Image in Slide'),
        '#data_type' => 'media',
      ),
      'data-kenburns' => array(
        '#name' => t('Ken Burns Effect'),
        '#default_value' => 'off',
        '#options' => $light,
        '#description' => 'on/off to turn on Ken Burns Effect or keep it disabled.',
      ),
      'data-bgrepeat' => array(
        '#name' => t('Background Repeat'),
        '#default_value' => '',
        '#options' => array(
          'no-repeat' => t('no-repeat'),
          'repeat' => t('repeat'),
          'repeat-x' => t('repeat-x'),
          'repeat-y' => t('repeat-y')
        ),
        '#description' => 'The way the image is shown in the slide main container'
      ),
      'data-bgfitstart' => array(
        '#name' => t('Background Fit Start'),
        '#default_value' => '',
        '#description' => 'Use only a Number . i.e. 300 will be a 300% Zoomed image where the basic 100% is fitting with width or height.',
        '#surfix' => '%',
      ),
      'data-bgfit' => array(
        '#name' => t('Background Fit'),
        '#default_value' => '',
        '#options' => array(
          'cover' => t('cover'),
          'contain' => t('contain'),
          'percentage' => t('percentage'),
          'normal' => t('normal')
        ),
        '#description' => 'Select one to decide how the image should fit in the Slide Main Container. For Ken Burn use only a Number, which is the % Zoom at start. 100 will fit with Width or height automatically, 200 will be double sized etc..'
      ),
      'bgfit-percentage-width' => array(
        '#name' => t('Background Width'),
        '#default_value' => '100',
        '#surfix' => '%',
      ),
      'bgfit-percentage-height' => array(
        '#name' => t('Background Height'),
        '#default_value' => '100',
        '#surfix' => '%',
      ),
      'data-bgfitend' => array(
        '#name' => t('Background Fit End'),
        '#default_value' => '',
        '#description' => 'Use only a Number . i.e. 300 will be a 300% Zoomed image where the basic 100% is fitting with width or height.',
        '#surfix' => '%',
      ),
      'data-bgposition' => array(
        '#name' => t('Background Position'),
        '#default_value' => '',
        '#options' => $positions,
      ),
      'data-bgpositionend' => array(
        '#name' => t('Background Position End'),
        '#default_value' => '',
        '#options' => $positions,
        '#description' => 'For Ken Burns Animation. This is where the IMG will be animatied'
      ),
      'data-duration' => array(
        '#name' => t('Duration for Ken Burns'),
        '#default_value' => '',
        '#description' => 'The value in ms how long the animation of ken burns effect should go. i.e. 3000 will make a 3s zoom and movement.'
      ),
      'data-ease' => array(
        '#name' => t('Easing of Ken Burns Effect'),
        '#default_value' => '',
        '#options' => $easings,
        '#description' => 'Same values as by Caption Easings available. The Movement Easing.'
      ),
    ),
    // End main image
    'general_slide_settings' => array(
      '#name' => t('General Slide Settings'),
      // Admin settings - without revolution
      'admin' => array(
        'name' => array(
          '#name' => t('Slide Title'),
          '#default_value' => t('New slide'),
          '#description' => t("The title of the slide, will be shown in the slides list."),
        ),

        'state' => array(
          '#name' => t('Slide state'),
          '#default_value' => 'published',
          '#options' => array(
            'published' => t("Published"),
            'unpublished' => t("Unpublished"),
          ),
          '#description' => t(" The state of the slide. The unpublished slide will be excluded from the slider."),
        ),
      ),
      // End admin settings

      // Transition Effects
      'transition' => array(
        '#name' => t('Transition Effects'),
        'data-transition' => array(
          '#name' => t('Transition'),
          '#default_value' => 'random',
          '#options' => $transitions,
          '#description' => t('The appearance transition of this slide.'),
        ),

        'data-randomtransition' => array(
          '#name' =>  t('Rotation'),
          '#default_value' => 0,
          '#description' => t('Rotation (-720 -> 720, 999 = random) Only for Simple Transitions.'),
        ),

        'data-slotamount' => array(
          '#name' => t('Slot Amount'),
          '#default_value' => 7,
          '#description' => t('The number of slots or boxes the slide is divided into. If you use boxfade, over 7 slots can be juggy.'),
        ),
        'data-masterspeed' => array(
          '#name' => t('Transition Duration'),
          '#default_value' => '300',
          '#description' => t('The speed of the transition in \'ms\'.'),
        ),
        'data-delay' => array(
          '#name' => t('Delay'),
          '#default_value' => '',
          '#description' => t('A new delay value for the Slide. If no delay defined per slide, the delay defined via Options (9000ms) will be used.'),
        ),
      ),

      // Links
      'links' => array(
        '#name' => t('Full Slide Links'),
        'data-link' => array(
          '#name' => t('Link'),
          '#default_value' => '',
          '#description' => 'A link on the whole slide pic'
        ),
        'data-target' => array(
          '#name' => t('Target'),
          '#default_value' => '',
          '#description' => 'The target of the Link for the whole slide pic. (i.e. \'_blank\', \'_self\')'
        ),
        'data-slideindex' => array(
          '#type' => 'select',
          '#name' => t('Link to slide'),
          '#default_value' => '',
          '#options' => $links,
          '#description' => 'If this value is set, click on slide will call the next / previous, or  n th Slide.'
        )

      ),

      // Slide thumbnail
      'thumbnail' => array(
        '#name' => t('Thumbnail'),
        'data-thumb' => array(
          '#name' => t('Thumbnail'),
          '#default_value' => '',
          '#data_type' => 'media',
          '#description' => 'An Alternative Source for thumbs. If not defined a copy of the background image will be used in resized form'
        ),
        'data-title' => array(
          '#name' => t('Title'),
          '#default_value' => '',
          '#description' => 'In Navigation Style Preview1- preview4 mode you can show the Title of the Slides also. Due this option you can define for each slide its own Title'
        )
      ),

      // Custom settings
      'class' => array(
        '#name' => t('Class'),
        '#default_value' => '',
        '#description' => t('Adds a unique class to the li of the Slide like class=\'rev_special_class\' (add only the classnames, seperated by space)'),
      ),

      'id' => array(
        '#name' => t('ID'),
        '#default_value' => '',
        '#description' => t('Adds a unique class to the li of the Slide like class=\'rev_special_class\' (add only the classnames, seperated by space)'),
      ),

      'attribute' => array(
        '#name' => t('Attribute'),
        '#default_value' => '',
        '#description' => t(' Adds a unique Attribute to the li of the Slide like attr=\'rev_special_attr\' (add only the attribute)'),
      ),

    ),
    // End general settings

  );

  $settings['layers'] = array(
    // Text slider
    'text' => array(
      //'#name' => t('Text layer'),
      '#type' => 'horizontal',
      'general_parameters' => array(
        '#name' => t('General'),
        'static_layer' => array(
          '#name' => t('Static Layer'),
          'data-startslide' => array(
            '#name' => t('Start Slide'),
            '#default_value' => '1',
          ),
          'data-endslide' => array(
            '#name' => t('End Slide'),
            '#default_value' => '1',
          ),
        ),
        'layer' => array(
          '#name' => t('Layer'),
          'layer_content' => array(
            'value' => array(
              '#name' => t('Value'),
              '#type' => 'textarea',
              '#default_value' => 'New layer',
            ),
            'custom_style' => array(
              '#type' => 'textarea',
              '#name' => t('Custom style'),
              '#default_value' => '',
            ),
            'styling-captions' => array(
              '#name' => t('Styling Captions'),
              '#default_value' => '',
              '#options' => $styling_cations,
              '#description' => t('These are Styling classes created in the settings.css. You can add unlimited amount of Styles in your own css file, to style your captions at the top level already'),
            ),
            'width' => array(
              '#name' => t('Width'),
              '#default_value' => '',
            ),
            'height' => array(
              '#name' => t('Height'),
              '#default_value' => '',
            ),
            'class' => array(
              '#name' => t('Custom class'),
              '#default_value' => '',
            ),
          ),
        ),
        // Align, Position & Styling
        'align_position_styling' => array(
          '#name' => t('Align, Position & Styling'),
          'data-x' => array(
            '#name' => t("X"),
            '#default_value' => 10,
            '#description' => t("Possible values are 'top', 'center', 'bottom', or any Value between -2500  and 2500."),
            //"Possible values are 'top', 'center', 'bottom', or any Value between -2500  and 2500. If left/center/right is set, the caption will be siple aligned to the position.  Any other 'number' will simple set the left position in px of tha caption. At 'left' the left side of the caption is aligned to the left side of the slider. At 'center' the center of caption is aligned to the center of slide. At 'right' the caption right side is aligned to the right side of the Slider."
          ),
          'data-hoffset' => array(
            '#name' => t("OffsetX"),
            '#default_value' => 0,
            '#description' => t("Only works if data-x set to left/center/right."),
            //"Only works if data-x set to left/center/right. It will move the Caption with the defined 'px' from the aligned position.  i.e.  data-x='center' data-hoffset='-100' will put the caption 100px left from the slide center  horizontaly.",
            '#surfix' => 'px',
          ),
          'data-y' => array(
            '#name' => t("Y"),
            '#default_value' => 10,
            '#description' => t("Possible values are 'top', 'center', 'bottom', or any Value between -2500  and 2500."),
            //"Possible Values are 'top', 'center', 'bottom', or any Value between -2500  and 2500. If top/center/bottom is set, the caption will be siple aligned to the position.  Any other 'number' will simple set the top position in px of tha caption. At 'top' the top side of the caption is aligned to the top side of the slider. At 'center' the center of caption is aligned to the center of slide. At 'bottom' the caption bottom side is aligned to the bottom side of the Slider.",
          ),
          'data-voffset' => array(
            '#name' => t("OffsetY"),
            '#default_value' => 0,
            '#description' => t("Only works if data-y set to top/center/bottom."),
            '#surfix' => 'px',
            //"Only works if data-y set to top/center/bottom. It will move the Caption with the defined 'px' from the aligned position.  i.e.  data-x='center' data-hoffset='-100' will put the caption 100px left from the slide center  vertically.",
          ),
        ),

        // Final Rotation
        'final_rotation' => array(
          '#name' => t('Final Rotation'),
          '2d-rotation' => array(
            '#name' => t('2D Rotation'),
            '#default_value' => 0,
            '#description' => t('Possible values(deg): -360 to 360'),
          ),
          '2d-rotation-origin-x' => array(
            '#name' => t('Rotation Origin X'),
            '#default_value' => 50,
            '#description' => t('Possible values(%): -100 to 200'),
          ),
          '2d-rotation-origin-y' => array(
            '#name' => t('Rotation Origin Y'),
            '#default_value' => 50,
            '#description' => t('Possible values(%): -100 to 200'),
          )
        ),

        // Parallax Settings
        'layer_parallax' => array(
          '#name' => t('Parallax Settings'),
          'layer_parallax_level' => array(
            '#name' => t('Level'),
            '#default_value' => '',
            '#options' => $parallax_level,
          ),
        ),

      ), // End general

      'layer_animation' => array(
        '#name' => t('Layer Animation'),
        'start_transition' => array(
          '#name' => t('Start Animation'),
          'incoming-classes' => array(
            '#name' => t('Incoming animation'),
            '#default_value' => 'fade',
            '#options' => $incoming_animation,
            '#surfix' => '<a class="button button-animate" href="#"  data-trigger="incoming">Custom Animation</a>',
          ),
          // Custom incoming settings
          'data-customin' => array(
            '#name' => t('Custom Incoming'),
            '#default_value' => '',
            '#description' => 'How the Caption is Transformed before animation starts. All value will be animated to 0 or 1 to remove all transoformation of the Caption.',
            '#child-options' => array(

            ),
          ),
          'data-speed' => array(
            '#name' => t('Speed'),
            '#default_value' => '300',
            '#description' => 'The speed in milliseconds of the transition to move the Caption in the Slide at the defined  timepoint.'
          ),
          'data-start' => array(
            '#name' => t('Start'),
            '#default_value' => '500',
            '#description' => 'The timepoint in millisecond when/at the Caption should move in to the slide.'
          ),
          'data-easing' => array(
            '#name' => t('Easing'),
            '#default_value' => 'Power3.easeInOut',
            '#options' => $easings,
            '#description' => 'The Easing Art how the caption is moved in to the slide (note! Animation art set via Classes !). Possible Values are:',
          ),
          'data-splitin' => array(
            '#name' => t('Split Text per'),
            '#default_value' => 'none',
            '#options' => $split,
            '#description' => 'Split Text Animation (incoming transition) to \'words\', \'chars\' or \'lines\'. This will create amazing Animation Effects on one go, without the needs to create more captions.'
          ),
          'data-elementdelay' => array(
            '#name' => t('Split Delay'),
            '#default_value' => '0.1',
            '#description' => 'A Value between 0 and 1 like 0.1 to make delays between the Splitted Text Element (start) Animations. Higher the amount of words or chars, you should decrease that number!'
          ),

        ),
        'end_transition' => array(
          '#name' => t('End Transition'),
          'outgoing-classes' => array(
            '#name' => t('End Animation'),
            '#default_value' => 'randomrotateout',
            '#options' => $outgoing_animation,
            '#surfix' => '<a class="button button-animate" href="#"  data-trigger="outgoing">Custom Animation</a>',
          ),
          // Custom outgoing settings
          'data-customout' => array(
            '#name' => t('Custom Outgoing'),
            '#default_value' => '',
            '#description' => 'The End Transformed Style after the animation finnished. All value will be animated from 0 or 1 to the selected transformation.'
          ),
          'data-endeasing' => array(
            '#name' => t('End Easing'),
            '#default_value' => '',
            '#options' => array_merge(array('' => t('No Change')), $easings),
            '#description' => 'The Easing Art how the caption is moved out from the slide (note! Animation art set via Classes !). Possible Values are:',
          ),
          'data-endspeed' => array(
            '#name' => t('Speed'),
            '#default_value' => '300',
            '#description' => 'The speed in milliseconds of the transition to move the Caption out from the Slide at the defined  timepoint.'
          ),
          'data-end' => array(
            '#name' => t('End'),
            '#default_value' => 0,
            '#description' => 'The timepoint in millisecond when/at the Caption should move out from the slide.'
          ),
          'data-splitout' => array(
            '#name' => t('Split Text Out'),
            '#default_value' => 'none',
            '#options' => $split,
            '#description' => 'Split Text Animation (outgoing transition) to \'words\', \'chars\' or \'lines\'. Only available if data-end is set !'
          ),
          'data-endelementdelay' => array(
            '#name' => t('End Split Delay'),
            '#default_value' => '0.1',
            '#description' => 'A Value between 0 and 1 like 0.1 to make delays between the Splitted Text Element (end) Animations. Higher the amount of words or chars, you should decrease that number!'
          ),

        ),
        'loop_aminiation' => array(
          '#name' => t('Loop Animation'),
          // Loop Animations Within the Layers
          'caption-loop' => array(
            '#name' => t('Animation'),
            '#default_value' => '',
            '#options' => $loop_animate,
            '#description' => t('To Define Loop animations, everything which comes inside the Layer need to be wrapped with a div container where you can set the different Loop Animation Details'),
          ),

          'caption_loop_data-speed' => array(
            '#name' => t('Speed'),
            '#default_value' => '2.5',
            '#surfix' => '(0.00 - 10.00)'
          ),
          'caption_loop_data-easing' => array(
            '#name' => t('Easing'),
            '#default_value' => '',
            '#options' => $easings,
          ),
          'caption_loop_data-startdeg' => array(
            '#name' => t('Start Degree'),
            '#default_value' => -20,
          ),
          'caption_loop_data-enddeg' => array(
            '#name' => t('End Degree'),
            '#default_value' => 20,
            '#surfix' => '(-720 - 720)',
          ),
          'caption_loop_data-xs' => array(
            '#name' => t('Start Position X'),
            '#default_value' => '',
          ),
          'caption_loop_data-xe' => array(
            '#name' => t('End Position X'),
            '#default_value' => '',
            '#surfix' => 'px (-2000px - 2000px)'
          ),
          'caption_loop_data-ys' => array(
            '#name' => t('Start Position Y'),
            '#default_value' => '-4',
            '#surfix' => 'px'
          ),
          'caption_loop_data-ye' => array(
            '#name' => t('End Position Y'),
            '#default_value' => '3',
            '#surfix' => 'px (-2000px - 2000px)'
          ),
          'caption_loop_data-zoomstart' => array(
            '#name' => t('Start Zoom'),
            '#default_value' => '1',
          ),
          'caption_loop_data-zoomend' => array(
            '#name' => t('End Zoom'),
            '#default_value' => '1',
            '#surfix' => '(0.00 - 20.00)',
          ),
          'caption_loop_data-origin-x' => array(
            '#name' => t('Origin X'),
            '#default_value' => '50',
            '#surfix' => '%',
          ),
          'caption_loop_data-origin-y' => array(
            '#name' => t('Origin Y'),
            '#default_value' => '50',
            '#surfix' => '% (-250% - 250%)',
          ),
          'caption_loop_data-angle' => array(
            '#name' => t('Angle'),
            '#default_value' => '0',
            '#surfix' => '° (0° - 360°)',
          ),
          'caption_loop_data-radius' => array(
            '#name' => t('Radius'),
            '#default_value' => '10',
            '#surfix' => 'px (0px - 2000px)',
          ),

        ),
      ),
      'layer_links_advanced' => array(
        '#name' => t('Layer Links & Advanced Params'),
        'links' => array(
          '#name' => t('Links (optional)'),
          'data-slideindex' => array(
            '#type' => 'select',
            '#name' => t('Link to slide'),
            '#default_value' => '',
            '#options' => $links,
            '#description' => 'Possible values:  next,back, 1-x (where x is the max. Amount of slide) If this value is set, click on slide will call the next / previous, or  n th Slide.'
          )
        ),
        'caption_sharp' => array(
          '#name' => t('Caption Sharp Corners (optional only with BG color)'),
          'left-corner' => array(
            '#type' => 'select',
            '#name' => t('Left Corner'),
            '#options' => $corners,
          ),
          'right-corner' => array(
            '#type' => 'select',
            '#name' => t('Right Corner'),
            '#options' => $corners,
          ),
        ),
        'advanced_responsive' => array(
          '#name' => t('Advanced Responsive Settings'),
          'tp-resizeme' => array(
            '#type' => 'select',
            '#name' => t('Responsive Through All Levels'),
            '#default_value' => 'yes',
            '#options' => array(
              'yes' => t('Yes'),
              'no' => t('No'),
            ),
          ),
          'data-captionhidden' => array(
            '#type' => 'select',
            '#name' => t('Hide Under Width'),
            '#default_value' => 'on',
            '#options' => $light,
          ),
        ),
        'attributes' => array(
          '#name' => t('Attributes (optional)'),
          'id' => array(
            '#name' => t('ID'),
            '#default_value' => '',
          ),
          'classes' => array(
            '#name' => t('Classes'),
            '#default_value' => '',
          ),
          'title' => array(
            '#name' => t('Title'),
            '#default_value' => '',
          ),
          'rel' => array(
            '#name' => t('Rel'),
            '#default_value' => '',
          ),
        ), // End Layer Links & Advanced Params

      ),
    ),
    // End text slider

    // Image slider
    'image' => array(
      //'#name' => t('Text layer'),
      '#type' => 'horizontal',
      'general_parameters' => array(
        '#name' => t('General'),
        'static_layer' => array(
          '#name' => t('Static Layer'),
          'data-startslide' => array(
            '#name' => t('Start Slide'),
            '#default_value' => '1',
          ),
          'data-endslide' => array(
            '#name' => t('End Slide'),
            '#default_value' => '1',
          ),
        ),
        'layer' => array(
          '#name' => t('Layer'),
          'layer_content' => array(
            'value' => array(
              '#name' => t('Image'),
              '#default_value' => '',
              '#data_type' => 'media',
            ),
            'custom_style' => array(
              '#type' => 'textarea',
              '#name' => t('Custom style'),
              '#default_value' => '',
            ),
            'styling-captions' => array(
              '#name' => t('Styling Captions'),
              '#default_value' => '',
              '#options' => $styling_cations,
              '#description' => t('These are Styling classes created in the settings.css. You can add unlimited amount of Styles in your own css file, to style your captions at the top level already'),
            ),
            'width' => array(
              '#name' => t('Width'),
              '#default_value' => '',
            ),
            'height' => array(
              '#name' => t('Height'),
              '#default_value' => '',
            ),
            'class' => array(
              '#name' => t('Custom class'),
              '#default_value' => '',
            ),
          ),
        ),
        // Align, Position & Styling
        'align_position_styling' => array(
          '#name' => t('Align, Position & Styling'),
          'data-x' => array(
            '#name' => t("X"),
            '#default_value' => 10,
            '#description' => t("Possible values are 'top', 'center', 'bottom', or any Value between -2500  and 2500."),
            //"Possible values are 'top', 'center', 'bottom', or any Value between -2500  and 2500. If left/center/right is set, the caption will be siple aligned to the position.  Any other 'number' will simple set the left position in px of tha caption. At 'left' the left side of the caption is aligned to the left side of the slider. At 'center' the center of caption is aligned to the center of slide. At 'right' the caption right side is aligned to the right side of the Slider."
          ),
          'data-hoffset' => array(
            '#name' => t("OffsetX"),
            '#default_value' => 0,
            '#description' => t("Only works if data-x set to left/center/right."),
            //"Only works if data-x set to left/center/right. It will move the Caption with the defined 'px' from the aligned position.  i.e.  data-x='center' data-hoffset='-100' will put the caption 100px left from the slide center  horizontaly.",
            '#surfix' => 'px',
          ),
          'data-y' => array(
            '#name' => t("Y"),
            '#default_value' => 10,
            '#description' => t("Possible values are 'top', 'center', 'bottom', or any Value between -2500  and 2500."),
            //"Possible Values are 'top', 'center', 'bottom', or any Value between -2500  and 2500. If top/center/bottom is set, the caption will be siple aligned to the position.  Any other 'number' will simple set the top position in px of tha caption. At 'top' the top side of the caption is aligned to the top side of the slider. At 'center' the center of caption is aligned to the center of slide. At 'bottom' the caption bottom side is aligned to the bottom side of the Slider.",
          ),
          'data-voffset' => array(
            '#name' => t("OffsetY"),
            '#default_value' => 0,
            '#description' => t("Only works if data-y set to top/center/bottom."),
            '#surfix' => 'px',
            //"Only works if data-y set to top/center/bottom. It will move the Caption with the defined 'px' from the aligned position.  i.e.  data-x='center' data-hoffset='-100' will put the caption 100px left from the slide center  vertically.",
          ),
        ),

        // Final Rotation
        'final_rotation' => array(
          '#name' => t('Final Rotation'),
          '2d-rotation' => array(
            '#name' => t('2D Rotation'),
            '#default_value' => 0,
            '#description' => t('Possible values(deg): -360 to 360'),
          ),
          '2d-rotation-origin-x' => array(
            '#name' => t('Rotation Origin X'),
            '#default_value' => 50,
            '#description' => t('Possible values(%): -100 to 200'),
          ),
          '2d-rotation-origin-y' => array(
            '#name' => t('Rotation Origin Y'),
            '#default_value' => 50,
            '#description' => t('Possible values(%): -100 to 200'),
          )
        ),

        // Parallax Settings
        'layer_parallax' => array(
          '#name' => t('Parallax Settings'),
          'layer_parallax_level' => array(
            '#name' => t('Level'),
            '#default_value' => '',
            '#options' => $parallax_level,
          ),
        ),

      ), // End general

      'layer_animation' => array(
        '#name' => t('Layer Animation'),
        'start_transition' => array(
          '#name' => t('Start Animation'),
          'incoming-classes' => array(
            '#name' => t('Incoming animation'),
            '#default_value' => 'fade',
            '#options' => $incoming_animation,
            '#surfix' => '<a class="button button-animate" href="#"  data-trigger="incoming">Custom Animation</a>',
          ),
          // Custom incoming settings
          'data-customin' => array(
            '#name' => t('Custom Incoming'),
            '#default_value' => '',
            '#description' => 'How the Caption is Transformed before animation starts. All value will be animated to 0 or 1 to remove all transoformation of the Caption.',
            '#child-options' => array(

            ),
          ),
          'data-speed' => array(
            '#name' => t('Speed'),
            '#default_value' => '300',
            '#description' => 'The speed in milliseconds of the transition to move the Caption in the Slide at the defined  timepoint.'
          ),
          'data-start' => array(
            '#name' => t('Start'),
            '#default_value' => '500',
            '#description' => 'The timepoint in millisecond when/at the Caption should move in to the slide.'
          ),
          'data-easing' => array(
            '#name' => t('Easing'),
            '#default_value' => 'Power3.easeInOut',
            '#options' => $easings,
            '#description' => 'The Easing Art how the caption is moved in to the slide (note! Animation art set via Classes !). Possible Values are:',
          ),
          'data-elementdelay' => array(
            '#name' => t('Delay'),
            '#default_value' => '0.1',
            '#description' => 'A Value between 0 and 1 like 0.1 to make delays between the Splitted Text Element (start) Animations. Higher the amount of words or chars, you should decrease that number!'
          ),

        ),
        'end_transition' => array(
          '#name' => t('End Transition'),
          'outgoing-classes' => array(
            '#name' => t('End Animation'),
            '#default_value' => 'randomrotateout',
            '#options' => $outgoing_animation,
            '#surfix' => '<a class="button button-animate" href="#"  data-trigger="outgoing">Custom Animation</a>',
          ),
          // Custom outgoing settings
          'data-customout' => array(
            '#name' => t('Custom Outgoing'),
            '#default_value' => '',
            '#description' => 'The End Transformed Style after the animation finnished. All value will be animated from 0 or 1 to the selected transformation.'
          ),
          'data-endeasing' => array(
            '#name' => t('End Easing'),
            '#default_value' => '',
            '#options' => array_merge(array('' => t('No Change')), $easings),
            '#description' => 'The Easing Art how the caption is moved out from the slide (note! Animation art set via Classes !). Possible Values are:',
          ),
          'data-endspeed' => array(
            '#name' => t('Speed'),
            '#default_value' => '300',
            '#description' => 'The speed in milliseconds of the transition to move the Caption out from the Slide at the defined  timepoint.'
          ),
          'data-end' => array(
            '#name' => t('End'),
            '#default_value' => 0,
            '#description' => 'The timepoint in millisecond when/at the Caption should move out from the slide.'
          ),
          'data-endelementdelay' => array(
            '#name' => t('End Split Delay'),
            '#default_value' => '0.1',
            '#description' => 'A Value between 0 and 1 like 0.1 to make delays between the Splitted Text Element (end) Animations. Higher the amount of words or chars, you should decrease that number!'
          ),

        ),
        'loop_aminiation' => array(
          '#name' => t('Loop Animation'),
          // Loop Animations Within the Layers
          'caption-loop' => array(
            '#name' => t('Animation'),
            '#options' => $loop_animate,
            '#description' => t('To Define Loop animations, everything which comes inside the Layer need to be wrapped with a div container where you can set the different Loop Animation Details'),
          ),

          'caption_loop_data-speed' => array(
            '#name' => t('Speed'),
            '#default_value' => '2.5',
            '#surfix' => '(0.00 - 10.00)'
          ),
          'caption_loop_data-easing' => array(
            '#name' => t('Easing'),
            '#default_value' => '',
            '#options' => $easings,
          ),
          'caption_loop_data-startdeg' => array(
            '#name' => t('Start Degree'),
            '#default_value' => -20,
          ),
          'caption_loop_data-enddeg' => array(
            '#name' => t('End Degree'),
            '#default_value' => 20,
            '#surfix' => '(-720 - 720)',
          ),
          'caption_loop_data-xs' => array(
            '#name' => t('Start Position X'),
            '#default_value' => '',
          ),
          'caption_loop_data-xe' => array(
            '#name' => t('End Position X'),
            '#default_value' => '',
            '#surfix' => 'px (-2000px - 2000px)'
          ),
          'caption_loop_data-ys' => array(
            '#name' => t('Start Position Y'),
            '#default_value' => '-4',
            '#surfix' => 'px'
          ),
          'caption_loop_data-ye' => array(
            '#name' => t('End Position Y'),
            '#default_value' => '3',
            '#surfix' => 'px (-2000px - 2000px)'
          ),
          'caption_loop_data-zoomstart' => array(
            '#name' => t('Start Zoom'),
            '#default_value' => '1',
          ),
          'caption_loop_data-zoomend' => array(
            '#name' => t('End Zoom'),
            '#default_value' => '1',
            '#surfix' => '(0.00 - 20.00)',
          ),
          'caption_loop_data-origin-x' => array(
            '#name' => t('Origin X'),
            '#default_value' => '50',
            '#surfix' => '%',
          ),
          'caption_loop_data-origin-y' => array(
            '#name' => t('Origin Y'),
            '#default_value' => '50',
            '#surfix' => '% (-250% - 250%)',
          ),
          'caption_loop_data-angle' => array(
            '#name' => t('Angle'),
            '#default_value' => '0',
            '#surfix' => '° (0° - 360°)',
          ),
          'caption_loop_data-radius' => array(
            '#name' => t('Radius'),
            '#default_value' => '10',
            '#surfix' => 'px (0px - 2000px)',
          ),

        ),
      ),
      'layer_links_advanced' => array(
        '#name' => t('Layer Links & Advanced Params'),
        'links' => array(
          '#name' => t('Links (optional)'),
          'data-slideindex' => array(
            '#type' => 'select',
            '#name' => t('Link to slide'),
            '#default_value' => '',
            '#options' => $links,
            '#description' => 'Possible values:  next,back, 1-x (where x is the max. Amount of slide) If this value is set, click on slide will call the next / previous, or  n th Slide.'
          )
        ),
        'advanced_responsive' => array(
          '#name' => t('Advanced Responsive Settings'),
          'tp-resizeme' => array(
            '#name' => t('Responsive Through All Levels'),
            '#default_value' => 'yes',
            '#options' => array(
              'yes' => t('Yes'),
              'no' => t('No'),
            ),
          ),
        ),
        'attributes' => array(
          '#name' => t('Attributes (optional)'),
          'id' => array(
            '#name' => t('ID'),
            '#default_value' => '',
          ),
          'classes' => array(
            '#name' => t('Classes'),
            '#default_value' => '',
          ),
          'title' => array(
            '#name' => t('Title'),
            '#default_value' => '',
          ),
          'rel' => array(
            '#name' => t('Rel'),
            '#default_value' => '',
          ),
        ), // End Layer Links & Advanced Params

      ),
    ),
    // End Image slider

    // Video slider
    'video' => array(
      //'#name' => t('Text layer'),
      '#type' => 'horizontal',
      'general_parameters' => array(
        '#name' => t('General'),
        'static_layer' => array(
          '#name' => t('Static Layer'),
          'data-startslide' => array(
            '#name' => t('Start Slide'),
            '#default_value' => '0',
          ),
          'data-endslide' => array(
            '#name' => t('End Slide'),
            '#default_value' => '1',
          ),
        ),
        'layer' => array(
          '#name' => t('Layer'),
          'layer_content' => array(
            'video-type' => array(
              '#name' => t('Video type'),
              '#default_value' => '',
              '#options' => array(
                'youtube' => t('Youtube'),
                'vimeo' => t('Vimeo'),
                'html5' => t('HTML5')
              ),
              '#description' => t('will play the Video Directly when slider has been loaded'),
            ),
            'value' => array(
              '#name' => t('Video URL'),
              '#default_value' => '',
            ),
            'data-videomp4' => array(
              '#name' => t('Video mp4'),
              '#default_value' => '',
              '#description' => t('The MP4 Source for the HTML5 Video'),
            ),
            'data-videowebm' => array(
              '#name' => t('Video webm'),
              '#default_value' => '',
              '#description' => t('The WEBM Source for the HTML5 Video'),
            ),
            'data-videoogv' => array(
              '#name' => t('Video ogv'),
              '#default_value' => '',
              '#description' => t('The OGV Source for the HTML5 Video'),
            ),
            'data-videoposter' => array(
              '#name' => t('Video poster'),
              '#default_value' => '',
              '#description' => t('The full path to an image which will be shown as Thumbnail for the Video.'),
            ),
            'data-ytid' => array(
              '#name' => t('Youtube id'),
              '#default_value' => '',
              '#description' => t('The YouTube ID of the Video'),
              '#attributes' => 'readonly',
            ),
            'data-vimeoid' => array(
              '#name' => t('Vimeo id'),
              '#default_value' => '',
              '#description' => t('The Vimeo ID of the Video'),
              '#attributes' => 'readonly',
            ),
            'custom_style' => array(
              '#name' => t('Custom style'),
              '#default_value' => '',
            ),
            'styling-captions' => array(
              '#name' => t('Styling Captions'),
              '#default_value' => '',
              '#options' => $styling_cations,
              '#description' => t('These are Styling classes created in the settings.css. You can add unlimited amount of Styles in your own css file, to style your captions at the top level already'),
            ),
            'class' => array(
              '#name' => t('Custom class'),
              '#default_value' => '',
            ),
          ),
        ),
        // Addition video settings
        'video-settings' => array(
          '#name' => t('Video settings'),
          'video-size' => array(
            '#name' => t("Video Size"),
            // Full Screen
            'video-fullscreen' => array(
              '#name' => t('Full Screen'),
              '#default_value' => 'off',
              '#options' => $light,
            ),
            'data-videowidth' => array(
              '#name' => t('Video width'),
              '#default_value' => '100%',
              '#description' => t('Width of Video (i.e. 500 for 500px, or 100% for 100%'),
            ),
            'data-videoheight' => array(
              '#name' => t('Video height'),
              '#default_value' => '100%',
              '#description' => t('Width of Video (i.e. 500 for 500px, or 100% for 100%'),
            ),
            // End full screen
            // Force cover
            'data-forcecover' => array(
              '#name' => t('Force cover'),
              '#default_value' => 0,
              '#options' => $boolean,
              '#description' => t('In case it is selected, the Videos will be resized to cover the full Slider size.'),
              //t('used only at HTML5 Videos. In case it is selected, the Videos will be resized to cover the full Slider size.'),
            ),
            'data-dottedoverlay' => array(
              '#name' => t('Dotted Overlay'),
              '#default_value' => 'none',
              '#options' => $dottedoverlay,
            ),
            'data-aspectratio' => array(
              '#type' => 'select',
              '#name' => t('Aspect ratio'),
              '#default_value' => '16:9',
              '#options' => array(
                '16:9' => '16:9',
                '4:3' => '4:3',
              ),
            ),
            // End force cover
          ),
          'data-autoplay' => array(
            '#name' => t('Auto play'),
            '#default_value' => 'false',
            '#options' => $boolean,
            '#description' => t('will play the Video Directly when slider has been loaded'),
          ),
          'data-autoplayonlyfirsttime' => array(
            '#name' => t('Auto play only first time'),
            '#default_value' => 'false',
            '#options' => $boolean,
            '#description' => t('after first Autplay the video will not be played automatically'),
          ),
          'data-nextslideatend' => array(
            '#name' => t('Next slide at end'),
            '#default_value' => 'true',
            '#options' => $boolean,
            '#description' => t('After video come to the end position, it swaps to the next slide automatically.'),
          ),

          'data-forcerewind' => array(
            '#name' => t('Force rewind'),
            '#default_value' => 'off',
            '#options' => $boolean,
            '#description' => t('Every time the Slide is shown, the Video will rewind to the start.'),
          ),
          'data-volume' => array(
            '#name' => t('Volume'),
            '#default_value' => '',
            '#options' => array(
              '' => t('Default'),
              'mute' => t('Mute'),
            ),
            '#description' => t('If value set to "mute", video will be played muted.'),
          ),
          'data-videopreload' => array(
            '#name' => t('Video preload'),
            '#default_value' => 'meta',
            '#options' => array(
              "none" => t("None"),
              "meta" => t("Meta"),
              "auto" => t("Auto"),
            ),
            '#description' => t('Which content of Video should be preloaded.'),
          ),
          'data-videocontrols' => array(
            '#name' => t('Video controls'),
            '#default_value' => 'none',
            '#options' => array(
              'none' => t('None'),
              'controls' => t('Controls'),
            ),
            '#description' => t('Show/Hide the controls of the Video.'),
          ),
          'data-videoloop' => array(
            '#name' => t('Video loop'),
            '#default_value' => 'none',
            '#options' => array(
              "none" => 'Disable',
              "loop" => t('Loop'),
              "loopandnoslidestop" => t('Loop, Slide does not stop'),
            ),
            '#description' => t('Loop HTML5 Videos'),
          ),
          'data-videoattributes' => array(
            '#name' => t('Video attributes'),
            '#default_value' => 'enablejsapi=1&html5=1&hd=1&wmode=opaque&showinfo=0&rel=0',
            '#description' => t('Further Video Attributes for not listed Options and Settings of Video.'),
          ),
        ),
        // End addition video settings
        // Align, Position & Styling
        'align_position_styling' => array(
          '#name' => t('Align, Position & Styling'),
          'data-x' => array(
            '#name' => t("X"),
            '#default_value' => 10,
            '#description' => t("Possible values are 'top', 'center', 'bottom', or any Value between -2500  and 2500."),
            //"Possible values are 'top', 'center', 'bottom', or any Value between -2500  and 2500. If left/center/right is set, the caption will be siple aligned to the position.  Any other 'number' will simple set the left position in px of tha caption. At 'left' the left side of the caption is aligned to the left side of the slider. At 'center' the center of caption is aligned to the center of slide. At 'right' the caption right side is aligned to the right side of the Slider."
          ),
          'data-hoffset' => array(
            '#name' => t("OffsetX"),
            '#default_value' => 0,
            '#description' => t("Only works if data-x set to left/center/right."),
            //"Only works if data-x set to left/center/right. It will move the Caption with the defined 'px' from the aligned position.  i.e.  data-x='center' data-hoffset='-100' will put the caption 100px left from the slide center  horizontaly.",
            '#surfix' => 'px',
          ),
          'data-y' => array(
            '#name' => t("Y"),
            '#default_value' => 10,
            '#description' => t("Possible values are 'top', 'center', 'bottom', or any Value between -2500  and 2500."),
            //"Possible Values are 'top', 'center', 'bottom', or any Value between -2500  and 2500. If top/center/bottom is set, the caption will be siple aligned to the position.  Any other 'number' will simple set the top position in px of tha caption. At 'top' the top side of the caption is aligned to the top side of the slider. At 'center' the center of caption is aligned to the center of slide. At 'bottom' the caption bottom side is aligned to the bottom side of the Slider.",
          ),
          'data-voffset' => array(
            '#name' => t("OffsetY"),
            '#default_value' => 0,
            '#description' => t("Only works if data-y set to top/center/bottom."),
            '#surfix' => 'px',
            //"Only works if data-y set to top/center/bottom. It will move the Caption with the defined 'px' from the aligned position.  i.e.  data-x='center' data-hoffset='-100' will put the caption 100px left from the slide center  vertically.",
          ),
        ),

        // Parallax Settings
        'layer_parallax' => array(
          '#name' => t('Parallax Settings'),
          'layer_parallax_level' => array(
            '#name' => t('Level'),
            '#default_value' => '',
            '#options' => $parallax_level,
          ),
        ),

      ), // End general

      'layer_animation' => array(
        '#name' => t('Layer Animation'),
        'start_transition' => array(
          '#name' => t('Start Animation'),
          'incoming-classes' => array(
            '#name' => t('Incoming animation'),
            '#default_value' => 'fade',
            '#options' => $incoming_animation,
            '#surfix' => '<a class="button button-animate" href="#"  data-trigger="incoming">Custom Animation</a>',
          ),
          // Custom incoming settings
          'data-customin' => array(
            '#name' => t('Custom Incoming'),
            '#default_value' => '',
            '#description' => 'How the Caption is Transformed before animation starts. All value will be animated to 0 or 1 to remove all transoformation of the Caption.',
            '#child-options' => array(

            ),
          ),
          'data-speed' => array(
            '#name' => t('Speed'),
            '#default_value' => '300',
            '#description' => 'The speed in milliseconds of the transition to move the Caption in the Slide at the defined  timepoint.'
          ),
          'data-start' => array(
            '#name' => t('Start'),
            '#default_value' => '500',
            '#description' => 'The timepoint in millisecond when/at the Caption should move in to the slide.'
          ),
          'data-easing' => array(
            '#name' => t('Easing'),
            '#default_value' => 'Power3.easeInOut',
            '#options' => $easings,
            '#description' => 'The Easing Art how the caption is moved in to the slide (note! Animation art set via Classes !). Possible Values are:',
          ),
          'data-elementdelay' => array(
            '#name' => t('Delay'),
            '#default_value' => '0.1',
            '#description' => 'A Value between 0 and 1 like 0.1 to make delays between the Splitted Text Element (start) Animations. Higher the amount of words or chars, you should decrease that number!'
          ),

        ),
        'end_transition' => array(
          '#name' => t('End Transition'),
          'outgoing-classes' => array(
            '#name' => t('End Animation'),
            '#default_value' => 'randomrotateout',
            '#options' => $outgoing_animation,
            '#surfix' => '<a class="button button-animate" href="#"  data-trigger="outgoing">Custom Animation</a>',
          ),
          // Custom outgoing settings
          'data-customout' => array(
            '#name' => t('Custom Outgoing'),
            '#default_value' => '',
            '#description' => 'The End Transformed Style after the animation finnished. All value will be animated from 0 or 1 to the selected transformation.'
          ),
          'data-endeasing' => array(
            '#name' => t('End Easing'),
            '#default_value' => '',
            '#options' => array_merge(array('' => t('No Change')), $easings),
            '#description' => 'The Easing Art how the caption is moved out from the slide (note! Animation art set via Classes !). Possible Values are:',
          ),
          'data-endspeed' => array(
            '#name' => t('Speed'),
            '#default_value' => '300',
            '#description' => 'The speed in milliseconds of the transition to move the Caption out from the Slide at the defined  timepoint.'
          ),
          'data-end' => array(
            '#name' => t('End'),
            '#default_value' => '',
            '#description' => 'The timepoint in millisecond when/at the Caption should move out from the slide.'
          ),
          'data-endelementdelay' => array(
            '#name' => t('End Split Delay'),
            '#default_value' => '0.1',
            '#description' => 'A Value between 0 and 1 like 0.1 to make delays between the Splitted Text Element (end) Animations. Higher the amount of words or chars, you should decrease that number!'
          ),
        ),
        'loop_aminiation' => array(
          '#name' => t('Loop Animation'),
          // Loop Animations Within the Layers
          'caption-loop' => array(
            '#name' => t('Animation'),
            '#options' => $loop_animate,
            '#description' => t('To Define Loop animations, everything which comes inside the Layer need to be wrapped with a div container where you can set the different Loop Animation Details'),
          ),

          'caption_loop_data-speed' => array(
            '#name' => t('Speed'),
            '#default_value' => '2.5',
            '#surfix' => '(0.00 - 10.00)'
          ),
          'caption_loop_data-easing' => array(
            '#name' => t('Easing'),
            '#default_value' => '',
            '#options' => $easings,
          ),
          'caption_loop_data-startdeg' => array(
            '#name' => t('Start Degree'),
            '#default_value' => -20,
          ),
          'caption_loop_data-enddeg' => array(
            '#name' => t('End Degree'),
            '#default_value' => 20,
            '#surfix' => '(-720 - 720)',
          ),
          'caption_loop_data-xs' => array(
            '#name' => t('Start Position X'),
            '#default_value' => '',
          ),
          'caption_loop_data-xe' => array(
            '#name' => t('End Position X'),
            '#default_value' => '',
            '#surfix' => 'px (-2000px - 2000px)'
          ),
          'caption_loop_data-ys' => array(
            '#name' => t('Start Position Y'),
            '#default_value' => '-4',
            '#surfix' => 'px'
          ),
          'caption_loop_data-ye' => array(
            '#name' => t('End Position Y'),
            '#default_value' => '3',
            '#surfix' => 'px (-2000px - 2000px)'
          ),
          'caption_loop_data-zoomstart' => array(
            '#name' => t('Start Zoom'),
            '#default_value' => '1',
          ),
          'caption_loop_data-zoomend' => array(
            '#name' => t('End Zoom'),
            '#default_value' => '1',
            '#surfix' => '(0.00 - 20.00)',
          ),
          'caption_loop_data-origin-x' => array(
            '#name' => t('Origin X'),
            '#default_value' => '50',
            '#surfix' => '%',
          ),
          'caption_loop_data-origin-y' => array(
            '#name' => t('Origin Y'),
            '#default_value' => '50',
            '#surfix' => '% (-250% - 250%)',
          ),
          'caption_loop_data-angle' => array(
            '#name' => t('Angle'),
            '#default_value' => '0',
            '#surfix' => '° (0° - 360°)',
          ),
          'caption_loop_data-radius' => array(
            '#name' => t('Radius'),
            '#default_value' => '10',
            '#surfix' => 'px (0px - 2000px)',
          ),

        ),
      ),
      'layer_links_advanced' => array(
        '#name' => t('Layer Links & Advanced Params'),
        'links' => array(
          '#name' => t('Links (optional)'),
          'data-slideindex' => array(
            '#type' => 'select',
            '#name' => t('Link to slide'),
            '#default_value' => '',
            '#options' => $links,
            '#description' => 'Possible values:  next,back, 1-x (where x is the max. Amount of slide) If this value is set, click on slide will call the next / previous, or  n th Slide.'
          )
        ),
        'advanced_responsive' => array(
          '#name' => t('Advanced Responsive Settings'),
          'tp-resizeme' => array(
            '#name' => t('Responsive Through All Levels'),
            '#default_value' => 'yes',
            '#options' => array(
              'yes' => t('Yes'),
              'no' => t('No'),
            ),
          ),
        ),
        'attributes' => array(
          '#name' => t('Attributes (optional)'),
          'id' => array(
            '#name' => t('ID'),
            '#default_value' => '',
          ),
          'classes' => array(
            '#name' => t('Classes'),
            '#default_value' => '',
          ),
          'title' => array(
            '#name' => t('Title'),
            '#default_value' => '',
          ),
          'rel' => array(
            '#name' => t('Rel'),
            '#default_value' => '',
          ),
        ), // End Layer Links & Advanced Params

      ),

    ),
    // End Video slider
  );

  return $key ? $settings[$key] : $settings;
}

