<?php
	require 'core.inc.php';
	require 'connect.inc.php';
	$username = $_SESSION['user_name'];
	
	if(isloggedin()){
		echo '	<p style="position:relative;left:62%;top:144px;z-index:100"><script type="text/javascript"> document.write("Welcome, ");</script></p>
<a href = "pdf.php" target="_blank" style="position:absolute;left:250px;top:250px;" ><ul><li>download your forms from here</li><ul></a><br>';

		echo '<div id="text1" style="position:absolute; overflow:hidden; left:0px; top:150px; width:1348px; height:35px; background:#ddd; z-index:0">
<a href = "logout.php" style="position:absolute;left:78%;top:20%; text-decoration:none"><button>Log out</button></a>		
	</div>';
	}else{
		include 'form.php';
	}
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
		
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
		
	<head>

	<meta name="description" content="Cuet Online Term Registration" />
	<meta name="keywords" content="cuet,online registration,term registration,rabiul hasan ronok,golam hossain himu,emtiaj hasan" />

	<title>CUET Online Registration</title>

	<link rel="shortcut icon" href="images/background.ico">
	<link rel="stylesheet" type="text/css" href="CSS/home css.css" />
  	<link rel="stylesheet" type="text/css" href="CSS/responsiveslides.css" />
  	<link rel="stylesheet" href="CSS/themes.css" />
  	<link rel="stylesheet" href="CSS/form.css" />
	<script src="JS/jquery.min.js"></script>
  	<script src="JS/responsiveslides.min.js"></script>
         
	</head>
	
	<body>
		
        <div id="logo">
			
            <div id="h5">
            	<h5 style="font-size:500%; text-align:center;color:white; height: 38px;"><a href="index.html" style="color:#EEE; text-decoration:none"> Chittagong University of Engineering & Technology </a></h5>
            </div>
            
		   <p style="position:absolute;left:67%;top:144px;z-index:100"><script type="text/javascript">var username="<?php echo $username?>"; document.write(username);</script></p>     
        <div id="baseline">
                  <div style="position:absolute; left:360px; top:20px;">
                        <p style="float:left;">&#169 <a href=http://www.cuet.ac.bd target="_blank" style="color:#EEE; text-decoration:none">CHITTAGONG UNIVERSITY OF ENGINEERING & TECHNOLOGY</a></p>
                    </div>
        </div>
    </body>
	
</html>