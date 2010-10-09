/*
 * JSONP Plugin for jQuery 1.2.3
 */
(function($) {
  $.jsonp = {};
  $.fn.jsonp = function(url, fn) {
    var self = this;
    var key = 'fn' + (new Date()).getTime();
    var script = $(document.createElement('script'))
      .attr('type', 'text/javascript')
      .attr('src', url.replace(/{fn}/, 'jQuery.jsonp.' + key));
    $.jsonp[key] = function(json) {
      setTimeout(function() { script.remove(); }, 10);
      self.each(fn, [json]);
    };
    jQuery('head', document)[0].appendChild(script[0]);
    return self;
  };
})(jQuery);