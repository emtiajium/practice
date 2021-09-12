$('#upload').click(function(){
	var val=0;
	var interval=setInterval(function(){
		val=val+2;
		$('#pb').progressbar({value:val});
		$('#percent').text(val+'%');
		if(val==100){
			document.getElementById("myForm").submit();
			clearInterval(interval);
		}
	},50);
});
