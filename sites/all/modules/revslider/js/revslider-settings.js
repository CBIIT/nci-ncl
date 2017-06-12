(function ($) {
    var $rsdialog = $('<div id="rs-global-settings-dialog"><div class="inner"></div></div>');
    Drupal.ajax.prototype.commands.rs_global_settings = function (ajax, response, status) {
        if (response.data) {
            $('.inner', $rsdialog).html(response.data);
            Drupal.attachBehaviors($('.inner', $rsdialog), Drupal.settings);
        }
    };
    Drupal.ajax.prototype.commands.rs_preview = function (ajax, response, status) {
        if (response.data) {
            $('#revolution-builder').html(response.data);
            var $exitpreview = $('<a href="#">Exit preview</a>');
            $exitpreview.click(function(){
                $(this).remove();
                $('#revolution-builder').html('');
            });
            $('#revolution-builder').before($exitpreview);
            $('html, body').animate({
                scrollTop: '0px'
            }, 800);
            $('.rs-banner').css('display','block');
            Drupal.attachBehaviors($('#revolution-builder'));
        }
    };
    Drupal.behaviors.revslider_global_settings = {
        attach: function (context, settings) {
            //Attach font and custom css
            settings.rs.builder.options.google_fonts = settings.rs.builder.options.google_fonts || '';
            settings.rs.builder.options.custom_css = settings.rs.builder.options.custom_css || '';
            $('head').find('link.google_fonts').remove();
            $('head').find('style.custom_css').remove();
            var fonts = settings.rs.builder.options.google_fonts.split('|');
            $(fonts).each(function(){
                $('head').append('<link class="google_fonts" rel="stylesheet" href="'+this+'" type="text/css" />');
            });
            $('head').append('<style type="text/css" class="custom_css">'+settings.rs.builder.options.custom_css+'</style>');
            $rsdialog.dialog({
                width: '90%',
                height: '600',
                autoOpen: false,
                modal: true,
                title: Drupal.t('Global Settings'),
                buttons: [
                    {
                        text: Drupal.t('Save'),
                        click: function(){
                            var data = $rsdialog.find('form').serializeArray();
                            var ignore = ['form_token','form_build_id','form_id'];
                            $('head').find('link.google_fonts').remove();
                            $(data).each(function(){
                                if(ignore.indexOf(this.name) < 0){
                                    settings.rs.builder.options[this.name] = this.value;
                                    if(this.name == 'google_fonts' && this.value != ''){
                                        var fonts = this.value.split('|');
                                        $(fonts).each(function(){
                                            $('head').append('<link class="google_fonts" rel="stylesheet" href="'+this+'" type="text/css" />');
                                        });
                                    }
                                    if(this.name == 'custom_css'){
                                        $('head').find('style.custom_css').remove();
                                        $('head').append('<style type="text/css" class="custom_css">'+this.value+'</style>');
                                    }
                                }
                            });
                            $(this).dialog('close');
                        }
                    },
                    {
                        text: Drupal.t('Cancel'),
                        click: function(){
                            $(this).dialog('close');
                        }
                    }
                ]
            })
            $('[data-trigger=global-settings]').once('revslider', function () {
                $(this).click(function () {
                    var ajax = new Drupal.ajax(true, '#no_master', {
                        url: Drupal.settings.basePath + '?q=admin/content/revslider/global_settings'
                    });
                    ajax.options.data = $.extend(ajax.options.data, settings.rs.builder.options);
                    ajax.eventResponse(ajax, {})
                    $rsdialog.dialog('open');
                    return false;
                });
            });
            $('[data-trigger=slide-preview]').once('revslider', function() {
                $(this).click(function(){
                    var ajax = new Drupal.ajax(true, '#ui-preview', {
                        url: Drupal.settings.basePath + '?q=admin/content/revslider/preview'
                    });
                    var data = JSON.stringify(settings.rs.builder);
                    ajax.options.data = $.extend(ajax.options.data, {data:data});
                    ajax.eventResponse(ajax, {})
                    return false;
                });
            });
        }
    }
})(jQuery);
