<!DOCTYPE HTML>
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
	    <title>DATA Upload and Download Interface</title>
		<link rel="stylesheet" type="text/css" href="indexCSS.css">
		<link rel="stylesheet" type="text/css" href="style.css">
		<link rel="stylesheet" type="text/css" href="jquery-ui-1.10.4.custom.css">
    </head>
    
    <body>
        <div class="wrap">
            <h1>Upload your desired file</h1></br>
			<form id="myForm" action="upload_file.php" method="post" enctype="multipart/form-data">
                <input name="file" type="file"/>
                <input id="upload" class="button" type="button"  value="Upload"/>
			</form>
			</br>
			
			<div id="pb"> </div>
			<div id="percent"> </div>
			
			<script type="text/javascript" src="jquery.js"> </script>
			<script type="text/javascript" src="jquery-ui.js"> </script>
			<script type="text/javascript" src="ui.js"> </script>
			<br />
        </div>
		<div class="wrap">
			<a href='download_file.php'> 
				<input class="button" type="submit" value="Download Available Files"/> 
			</a>
		</div>
    </body>
</html>
