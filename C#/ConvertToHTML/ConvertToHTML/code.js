$(function(){
	$("h2").click(function(event){
	alert("Hello!");
	$("h2").css('color','red');
	event.preventDefault();
	})

});

