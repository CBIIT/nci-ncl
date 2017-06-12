function mediaParse($url) {
    var media = {};
    // http://youtube.com/watch/*
    // http://youtube.com/embed/*
    // http://youtube.com/v/*
    // http://youtube.com/?v=*
    // http://youtu.be/*
    // http://gdata.youtube.com/feeds/api/videos/*
    var youtube = [
        /youtube\.com\/watch[#\?].*?v=([^"\& ]+)/i,
        /youtube\.com\/embed\/([^"\&\? ]+)/i,
        /youtube\.com\/v\/([^"\&\? ]+)/i,
        /youtube\.com\/\?v=([^"\& ]+)/i,
        /youtu\.be\/([^"\&\? ]+)/i,
        /gdata\.youtube\.com\/feeds\/api\/videos\/([^"\&\? ]+)/i,
    ];

    var vimeo = [
        /vimeo\.com\/(\d+)/i,
        /vimeo\.com\/video\/(\d+)/i,
        /vimeo\.com\/groups\/.+\/videos\/(\d+)/i,
        /vimeo\.com\/channels\/.+#(\d+)/i,
        /vimeo\.com\/channels\/.+\/(\d+)/i,
    ];

    youtube.forEach(function (pattern) {
        var yt = pattern.exec($url);
        if (yt !== null) {
            media.type = 'youtube';
            media.id = yt[1];
            media.key = 'ytid';
        }
    });

    if (typeof media.type != 'undefined')
        return media;

    vimeo.forEach(function (pattern) {
        var vm = pattern.exec($url);
        if (vm !== null) {
            media.type = 'vimeo';
            media.id = vm[1];
            media.key = 'vimeoid';
        }
    });

    return media;
};