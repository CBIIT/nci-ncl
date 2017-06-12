//(function ($, Drupal) {
//
//  Drupal.behaviors.STARTER = {
//    attach: function(context, settings) {
//      // Get your Yeti started.
//	  
//	  $( " | " ).insertAfter( ".leaf a" );
//	  
//    }
//  };
//})(jQuery, Drupal);

jQuery(document).ready(function ($) {
	
	// splitter in footer, hides last bar
	$('.footer .menu li.leaf:not(:last)').after('<li class="footer-divider">|</li>');
	
	// toggle function to show/hide
	$(document).ready(function(){
	  $(".toggler").click(function(){
		$(this).next().slideToggle("fast");
		return false;
	  }).next().hide();
	  
	  $(".toggler-show").click(function(){
		$(this).next().slideToggle("fast");
		return false;
	  }).next().show();

	});
	
	
	jQuery(".abstract").hide();
	jQuery(".showhide").click(function(event) {
		event.preventDefault();
		jQuery(this).closest('tr').next().find('.abstract').toggle();
	});
	


});


// shows all items at once
jQuery(function(){
	jQuery('.showall').click(function(){
		jQuery('.abstract').toggle();
	});
});
