<?php
$count=0;
if ($handle = opendir('upload/')) {
    while (false !== ($file = readdir($handle))) {
        if($file == '.' || $file == '..') continue;
        $count++;
    }
    closedir($handle);
}
?>

<html>

<head>
	<title>Files Available for Downloading</title>
    <link rel="stylesheet" type="text/css" href="indexCSS.css">
</head>

<body>
	<div class="wrap">
		<h1>Download your desired file</h1>
		<?php
			for ($i=1; $i<=$count; $i++)
			{
			?>
			<a href="upload/<?php
				if($handle=opendir('upload/'))
				{
					$j=1;
					while(false!==($file=readdir($handle))) 
					{
						if($file=='.'||$file=='..') continue;
						if($j==$i)
							echo $file;
						$j++;
					}
					closedir($handle);
				}
			?>" download="<?php
				if($handle=opendir('upload/'))
				{
					$j=1;
					while(false!==($file=readdir($handle))) 
					{
						if($file=='.'||$file=='..') continue;
						if($j==$i)
							echo $file;
						$j++;
					}
					closedir($handle);
				}
			?>"> 
			</br> 
			<?php
				if($handle=opendir('upload/')){
					$j=1;
					while(false!==($file=readdir($handle))){
						if($file=='.'||$file=='..') continue;
						if($j==$i)
							echo $file;
						$j++;
					}
					closedir($handle);
				}
			?></a>
			<?php
		}
		?>
		</br></br>
		<a href="index.php"> 
			<input class="button" type="submit" value="Back to Previous Page"/>
		</a>
    </div>
</body>
</html>