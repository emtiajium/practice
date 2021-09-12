<?php

	if(isset($_POST['id']) && isset($_POST['password'])){
		$id = $_POST['id'];
		$password = $_POST['password'];


		if(!empty($id) && !empty($password)){

			$query = "SELECT `id` FROM `login` WHERE `id` = '".$id."' AND `password` = '".$password."'";
			if($query_run = mysql_query($query)){
				$query_num_rows = mysql_num_rows($query_run);

				if($query_num_rows==0){
					echo 'wrong';
				}else if($query_num_rows==1){
					$user_id = mysql_result($query_run, 0,'id');
					$_SESSION['user_id'] = $user_id;

					$query = "SELECT `name`,`dept_name` FROM `academic_info` WHERE `id` = ' ".$id."'";
					if($query_run = mysql_query($query)){
						$query_num_rows = mysql_num_rows($query_run);
						if($query_num_rows==0){
							echo 'no such data';
						}else if($query_num_rows==1){
							$user_name = mysql_result($query_run, 0,'name');
							$_SESSION['user_name'] = $user_name;
							$user_dept = mysql_result($query_run, 0,'dept_name');
							$_SESSION['user_dept'] = $user_dept;
						}
					}

					$query = "SELECT `father_name`,`mother_name`,`nationality` FROM `personal_info` WHERE `id` = '".$id."'";
					if($query_run = mysql_query($query)){
						$query_num_rows = mysql_num_rows($query_run);
						if($query_num_rows==0){
							echo 'no such data';
						}else if($query_num_rows==1){
							$father_name = mysql_result($query_run, 0,'father_name');
							$_SESSION['father_name'] = $father_name;
							$mother_name = mysql_result($query_run, 0,'mother_name');
							$_SESSION['mother_name'] = $mother_name;
							$nationality = mysql_result($query_run, 0,'nationality');
							$_SESSION['nationality'] = $nationality;
						}
					}


					$query = "SELECT  `course1` ,  `course2` ,  `course3` ,  `course4` ,  `course5` ,  `course6` ,  `course7` ,  `course8` 
FROM  `termcourse` 
WHERE  `level_term` =31";
					if($query_run = mysql_query($query)){
						$query_num_rows = mysql_num_rows($query_run);
						if($query_num_rows==0){
							echo 'no such data';
						}else if($query_num_rows==1){
							$course1 = mysql_result($query_run, 0,'course1');
							$_SESSION['course1'] = $course1;
							$course2 = mysql_result($query_run, 0,'course2');
							$_SESSION['course2'] = $course2;
							$course3 = mysql_result($query_run, 0,'course3');
							$_SESSION['course3'] = $course3;
							$course4 = mysql_result($query_run, 0,'course4');
							$_SESSION['course4'] = $course4;
							$course5 = mysql_result($query_run, 0,'course5');
							$_SESSION['course5'] = $course5;
							$course6 = mysql_result($query_run, 0,'course6');
							$_SESSION['course6'] = $course6;
							$course7 = mysql_result($query_run, 0,'course7');
							$_SESSION['course7'] = $course7;
							$course8 = mysql_result($query_run, 0,'course8');
							$_SESSION['course8'] = $course8;
						}
					}




					$query = "SELECT  `hall_name` 
FROM  `hall_info` 
WHERE  `id` = '".$id."'";
					if($query_run = mysql_query($query)){
						$query_num_rows = mysql_num_rows($query_run);
						if($query_num_rows==0){
							echo 'no such data';
						}else if($query_num_rows==1){
							$hall_name = mysql_result($query_run, 0,'hall_name');
							$_SESSION['hall_name'] = $hall_name;
				}
					}
					$query = "SELECT SUM(  `credit` ) AS  `total_credit` 
FROM  `level-3term-1`";
					if($query_run = mysql_query($query)){
						$query_num_rows = mysql_num_rows($query_run);
						if($query_num_rows==0){
							echo 'no such data';
						}else if($query_num_rows==1){
							$total_credit = mysql_result($query_run, 0,'total_credit');
							$_SESSION['total_credit'] = $total_credit;
						}
					}
					$query = "SELECT * 
FROM  `level-3term-1`";
					if($query_run = mysql_query($query)){
						$query_num_rows = mysql_num_rows($query_run);
						if($query_num_rows==0){
							echo 'no such data';
						}else {
					$_SESSION['course1_title'] = mysql_result($query_run, 0,'course_title');
					$_SESSION['course2_title'] = mysql_result($query_run, 1,'course_title');
					$_SESSION['course3_title'] = mysql_result($query_run, 2,'course_title');
					$_SESSION['course4_title'] = mysql_result($query_run, 3,'course_title');
					$_SESSION['course5_title'] = mysql_result($query_run, 4,'course_title');
					$_SESSION['course6_title'] = mysql_result($query_run, 5,'course_title');
					$_SESSION['course7_title'] = mysql_result($query_run, 6,'course_title');
					$_SESSION['course8_title'] = mysql_result($query_run, 7,'course_title');
					$_SESSION['credit1'] = mysql_result($query_run, 0,'credit');
					$_SESSION['credit2'] = mysql_result($query_run, 1,'credit');
					$_SESSION['credit3'] = mysql_result($query_run, 2,'credit');
					$_SESSION['credit4'] = mysql_result($query_run, 3,'credit');
					$_SESSION['credit5'] = mysql_result($query_run, 4,'credit');
					$_SESSION['credit6'] = mysql_result($query_run, 5,'credit');
					$_SESSION['credit7'] = mysql_result($query_run, 6,'credit');
					$_SESSION['credit8'] = mysql_result($query_run, 7,'credit');
						}
					}




					$query = "SELECT  `amount` 
FROM  `termcourse` 
WHERE  `level_term` =31";
					if($query_run = mysql_query($query)){
						$query_num_rows = mysql_num_rows($query_run);
						if($query_num_rows==0){
							echo 'no such data';
						}else if($query_num_rows==1){
					$_SESSION['amount'] = mysql_result($query_run, 0,'amount');
						}
					}




					$query = "SELECT `donation` FROM `eco_info` WHERE `id` = '".$id."'";
					if($query_run = mysql_query($query)){
						$query_num_rows = mysql_num_rows($query_run);
						if($query_num_rows==0){
							echo 'no such data';
						}else if($query_num_rows==1){
				$_SESSION['donation'] = mysql_result($query_run, 0,'donation');
						}
					}

					header('Location: loginform.php');
				}
			}
		}else{
			echo 'Insert your ID and Password';
		}
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
            	<h5 style="font-size:500%; text-align:center;color:white; height: 38px;">Chittagong University of Engineering & Technology</h5>
            </div>
            
            <div id="navcontainer">
				<ul id="navlist">
	                <li style="position:relative;left:0%;width:5%"><a href="index.html">Home</a></li>
					<li id="active" style="position:relative;left:5%;width:5%"><a href="#" id="current">Faculty</a> 
						<ul id="subnavlist">
							<li id="subactive"><a href="http://www.cuet.ac.bd/faculties.php" id="subcurrent">Civil Engineering</a></li>
							<li><a href="http://www.cuet.ac.bd/faculties.php">Mechanical Engineering</a></li>
							<li><a href="http://www.cuet.ac.bd/faculties.php">Electrical & Computer Engineering</a></li>
							<li><a href="http://www.cuet.ac.bd/faculties.php">Architecture & Planning</a></li>
                    		<li><a href="http://www.cuet.ac.bd/faculties.php">Engineering & Technology</a></li>
						</ul>
					</li>
					<li style="position:relative;left:10%;width:5%"><a href="notice.html">Notice</a></li>
					<li style="position:relative;left:15%;width:15%"><a href="http://www.cuet.ac.bd/contactus.php" target="_blank">Contact Us</a></li>
					<li style="position:relative;left:15%;width:15%"><a href="developer.html">Developers</a></li>
				</ul>
			</div>

		</div>
		
		<div id="form" style="position:absolute;left:25%;top:250px;">
			<form class="form" action = "<?php echo $current_file; ?>" method = "POST">
			    <p class="name">  
					<input type="text" name="id" id="id"/>  
					<label for="id">ID</label>  
				</p>  
  
				<p class="email">  
					<input type="password" name="password" id="password"/>  
					<label for="password">Password</label>  
				</p>  
  
				<p class="submit">  
					<input type="submit" value="Submit" />  
				</p>  
			
			</form>
		</div>
        
        <div id="baseline">
                  <div style="position:absolute; left:360px; top:20px;">
                        <p style="float:left;">&#169 <a href=http://www.cuet.ac.bd target="_blank" style="color:#EEE; text-decoration:none">CHITTAGONG UNIVERSITY OF ENGINEERING & TECHNOLOGY</a></p>
                    </div>
        </div>
    </body>
	
</html>