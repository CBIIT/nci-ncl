(function ($) {
    Drupal.behaviors.rs = {
        attach: function (context, settings) {
            // If no revolution exist on this part of the page, work no further.
            if (!settings.rs || !settings.rs.render) {
                return;
            }
            $.each(settings.rs.render, function (key, value) {
                var data = $.extend(true, {}, value);
                $('#rs-wrapper-' + data.id, context).once('rs-render', function () {
                    $.each(data.options, function (k, v) {
                        if (k == 'parallaxLevels') {
                            // Do nothing
                        } else if (v === '') {
                            //delete options[k];
                        } else if (isNaN(v)) {
                            data.options[k] = v.trim();
                        } else {
                            data.options[k] = $.parseJSON(v);
                        }
                    });
                    if (data.options.timer == 'bottom') {
                        $('.tp-bannertimer', $(this)).addClass('tp-bottom');
                    }
                    $('.rs-banner', $(this)).show().revolution(data.options);
                });
            });
        }
    }
})(jQuery);
