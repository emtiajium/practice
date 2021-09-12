<!DOCTYPE HTML>
<html xmlns="http://www.w3.org/1999/xhtml">
    <head>
	    <title>DATA Upload and Download Interface</title>
		<link rel="stylesheet" type="text/css" href="indexCSS.css">
    </head>
    
    <body>
		<div class="wrap">
			<?php
				if ($_FILES["file"]["error"] > 0)
				{
					echo "Error" ."<br>";
				}
				else
				{
					echo "Upload: " . $_FILES["file"]["name"] . "<br>";
					echo "Type: " . $_FILES["file"]["type"] . "<br>";
					echo "Size: " . ($_FILES["file"]["size"] / 1024) . " KB<br>";
				}
				move_uploaded_file($_FILES["file"]["tmp_name"],"upload/" . $_FILES["file"]["name"]);
			?>
		</div>
		<div class="wrap">
			<a href='index.php'> 
				<input class="button" type="submit" value="Back to Previous Page"/> 
			</a>
		</div>
    </body>
</html>
