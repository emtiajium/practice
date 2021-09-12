<?php
	
	require 'core.inc.php';
	$id = $_SESSION['user_id'];
	$year = intval($id/100000);
	$code = ($id/1000)%100;
	$roll = $id%100;
	$name = $_SESSION['user_name'];
	$dept = $_SESSION['user_dept'];
	$father_name = $_SESSION['father_name'];
	$mother_name = $_SESSION['mother_name'];
	$nationality = $_SESSION['nationality'];
	$course1 = $_SESSION['course1'];
	$course2 = $_SESSION['course2'];
	$course3 = $_SESSION['course3'];
	$course4 = $_SESSION['course4'];
	$course5 = $_SESSION['course5'];
	$course6 = $_SESSION['course6'];
	$course7 = $_SESSION['course7'];
	$course8 = $_SESSION['course8'];
	$course1_title = $_SESSION['course1_title'];
	$course2_title = $_SESSION['course2_title'];
	$course3_title = $_SESSION['course3_title'];
	$course4_title = $_SESSION['course4_title'];
	$course5_title = $_SESSION['course5_title'];
	$course6_title = $_SESSION['course6_title'];
	$course7_title = $_SESSION['course7_title'];
	$course8_title = $_SESSION['course8_title'];
	$credit1 = $_SESSION['credit1'];
	$credit2 = $_SESSION['credit2'];
	$credit3 = $_SESSION['credit3'];
	$credit4 = $_SESSION['credit4'];
	$credit5 = $_SESSION['credit5'];
	$credit6 = $_SESSION['credit6'];
	$credit7 = $_SESSION['credit7'];
	$credit8 = $_SESSION['credit8'];
	$hall_name = $_SESSION['hall_name'];
	$total_credit = $_SESSION['total_credit'];
	$amount = $_SESSION['amount'];
	$donation = $_SESSION['donation'];
	$total_amount = $amount + $donation;
	$registered = $_SESSION['registered'];
	echo '<a href="javascript:demo1()" style="position:absolute;top:250px;left:250px;font-size:14px"><ul><li>Print Admit Card</li></ul></a><br/>';
	echo '<a href="javascript:demo2()" style="position:absolute;top:280px;left:250px;font-size:14px"><ul><li>Print Money Receipt</li></ul></a><br/>';
	echo '<a href="javascript:demo3()" style="position:absolute;top:310px;left:250px;font-size:14px"><ul><li>Print Registration form</li></ul></a>';
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
    <script src="JS/jspdf.js"></script> 
	
	</head>
	
	<body>
		
        <div id="logo">
			
            <div id="h5">
            	<h5 style="font-size:500%; text-align:center;color:white; height: 38px;">Chittagong University of Engineering & Technology</h5>
            </div>
            
<div id="text1" style="position:absolute; overflow:hidden; left:0px; top:150px; width:1348px; height:35px; background:#ddd; z-index:0">
		   <p style="position:absolute;left:67%;top:3%;z-index:100"><script type="text/javascript">var username="<?php echo $name?>"; document.write("Welcome, "+ username);</script></p>     </div>
        <div id="baseline">
                  <div style="position:absolute; left:360px; top:20px;">
                        <p style="float:left;">&#169 <a href=http://www.cuet.ac.bd target="_blank" style="color:#EEE; text-decoration:none">CHITTAGONG UNIVERSITY OF ENGINEERING & TECHNOLOGY</a></p>
                    </div>
        </div>
<script type="text/javascript">

function demo1() {
	var doc = new jsPDF();
	var id = "<?php echo $id?>";
	var name = "<?php echo $name?>";
	var dept = "<?php echo $dept?>";
	var father_name = "<?php echo $father_name?>";
	var mother_name = "<?php echo $mother_name?>";
	var nationality = "<?php echo $nationality?>";
	var course1 = "<?php echo $course1?>";
	var course2 = "<?php echo $course2?>";
	var course3 = "<?php echo $course3?>";
	var course4 = "<?php echo $course4?>";
	var course5 = "<?php echo $course5?>";
	var course6 = "<?php echo $course6?>";
	var course7 = "<?php echo $course7?>";
	var course8 = "<?php echo $course8?>";
	var amount = "<?php echo $amount?>";

	doc.text(173, 8, 'Office copy');
	doc.setLineWidth(.7);
	doc.line(172, 10, 202, 10); // horizontal line		
	doc.text(18, 18,dept);
	doc.text(10, 20, '...................');
	doc.text(175, 18,id);
	doc.text(170, 20, '......................');
	doc.text(10, 25, 'Department');
	doc.text(170, 25, 'Class Roll No');
	doc.setFontSize(20);
	doc.setFontType("bold");
	doc.text(20, 35, 'Chittagong University of Engineering & Technology');
	doc.setFontSize(16);
	doc.setFontType("normal");
	doc.rect(87, 38, 36, 10);//rectangle
	doc.text(91, 45, 'Admit Card');
	doc.text(10, 55, 'Level:  		3, Term:  				I  Exam, 201 ');
	doc.text(10, 65, 'Opening Date of Exam:');
	doc.text(10, 75, 'Exam Roll No:');
	doc.text(50, 75, id);
	doc.text(10, 85, 'Registration No:');
	doc.text(53, 85, id);
	doc.text(100, 85, 'Session:	2012-13');
	doc.text(10, 95, 'Name of Examinee:');
	doc.text(60, 95, name);
	doc.text(10, 115, '................................................');
	doc.text(125, 115, '..................................................');
	doc.text(10, 120, 'Signature of Head of the Dept');
	doc.text(125, 120, 'Signature of Controller of Exam');
	doc.text(0,135,'........................................................................................................................................................');
	
	doc.text(170, 145, 'Student copy');
	doc.setLineWidth(.7);
	doc.line(168, 147, 205, 147); // horizontal line		
	doc.text(15, 158, dept);
	doc.text(175, 158, id);
	doc.text(10, 160, '...................');
	doc.text(170, 160, '......................');
	doc.text(10, 165, 'Department');
	doc.text(170, 165, 'Class Roll No');
	doc.setFontSize(20);
	doc.setFontType("bold");
	doc.text(20, 175, 'Chittagong University of Engineering & Technology');
	doc.setFontSize(16);
	doc.setFontType("normal");
	doc.rect(87, 178, 36, 10);//rectangle
	doc.text(90, 185, 'Admit Card');
	doc.text(10, 195, 'Level:  			3, Term:  				I     Exam, 201 ');
	doc.text(10, 205, 'Opening Date of Exam:');
	doc.text(58, 215, id);
	doc.text(10, 215, 'Exam Roll No:');
	doc.text(58, 225, id);
	doc.text(10, 225, 'Registration No:');
	doc.text(100, 225, 'Session:	2012-13');
	doc.text(60, 235, name);
	doc.text(10, 235, 'Name of Examinee:');
	doc.text(10, 245, 'Courses Taken:');
	doc.setFontSize(12);
	doc.text(50, 255, course1 +', ');
	doc.text(70, 255, course2 +', ');
	doc.text(90, 255, course3 +', ');
	doc.text(110, 255, course4 +', ');
	doc.text(130, 255, course5 +', ');
	doc.text(150, 255, course6 +', ');
	doc.text(170, 255, course7 +', ');
	doc.text(190, 255, course8);
	doc.setFontSize(16);
	doc.text(20, 255, 'I) Regular:');
	doc.text(20, 265, 'II) Self Study:');
	doc.text(10, 280, '................................................');
	doc.text(125, 280, '..................................................');
	doc.text(10, 285, 'Signature of Head of the Dept');
	doc.text(125, 285, 'Signature of Controller of Exam');
	
	doc.addPage();

	doc.text(85, 15, name);	
	doc.text(10, 15, '1. Name of the Examinee:');
	doc.text(85, 25, father_name);
	doc.text(10, 25, '2. Father\'s Name:');
	doc.text(85, 35, mother_name);
	doc.text(10, 35, '3. Mother\'s Name:');
	doc.text(55, 45, nationality);
	doc.text(10, 45, '4. Nationality:');
	doc.text(10, 55, '5. Courses Taken:');
	doc.setFontSize(12);
	doc.text(50, 65, course1 +', ');
	doc.text(70, 65, course2 +', ');
	doc.text(90, 65, course3 +', ');
	doc.text(110, 65, course4 +', ');
	doc.text(130, 65, course5 +', ');
	doc.text(150, 65, course6 +', ');
	doc.text(170, 65, course7 +', ');
	doc.text(190, 65, course8);
	doc.setFontSize(16);
	doc.text(20, 65, 'I) Regular:');
	doc.text(20, 75, 'II) Self Study:');
	doc.text(10, 85, '6. Full description of the punishment given during exam (if any):');
	doc.text(17,98,'........');
	doc.text(17, 103, 'Date');
	doc.text(136,98,'....................................');
	doc.text(136, 103, 'Signature of Examinee');
	doc.text(17, 114, 'Applicant Should Pay '+amount+' (tk) to University through Bank.');
	doc.text(17,130,'........');
	doc.text(17, 135, 'Date');
	doc.text(135,130,'......................................');
	doc.text(135, 135, 'Signature of Accountant');
	doc.text(0,140,'........................................................................................................................................................');
	
	doc.text(75, 150, 'Rules & Regulations');
	doc.text(75, 153, '.................................');
	doc.text(10, 163, 'Rules of taking steps against practising unfairmeans in exam:');
	doc.text(10, 173, 'Following actions will be considered to be unfair in exam hall:');
	doc.text(10, 183, '(a) Talking with another examinee in the exam hall.');
	doc.text(10, 193, '(b) Keeping cell phone in the exam hall.');
	doc.text(10, 203, '(c) Smoking in the exam hall.');
	doc.text(10, 213, '(d) Keeping illegal papers.');
	doc.text(10, 223, '(e) Copying from illegal papers or other examinee.');
	doc.text(10, 233, '(f) Misbehaving with or threatening to any invigilator or stuff.');
	doc.text(10, 243, '(g) Keeping any book or paper in toilet.');
	doc.text(10, 253, '(h) Any other action that is considered to be crime by the invigilators.');
	doc.text(10,263,'Student committing any of the given miscreants can be expelled from the hall');
	doc.text(10,273, 'or expelled and restricted from giving all other exam.');
	doc.text(150, 279, '.....................');
	doc.text(150, 284, ' Comptroller ');
	doc.text(150, 290, '     CUET ');
	// Output as Data URI
	
	doc.output('datauri');
}

function demo2() {
	var doc = new jsPDF();
	var id = "<?php echo $id?>";
	var name = "<?php echo $name?>";
	var dept = "<?php echo $dept?>";
	var amount = "<?php echo $amount?>";
	var donation = "<?php echo $donation?>";
	var total_amount = "<?php echo $total_amount?>";

	doc.setLineWidth(.7);
	doc.line(10, 125, 10, 238); // vertical line
	doc.line(80, 125, 80, 238); // vertical line
	doc.line(100, 125, 100, 238); // vertical line
	doc.line(115, 125, 115, 238); // vertical line
	doc.line(185, 125, 185, 238); // vertical line
	doc.line(205, 125, 205, 238); // vertical line
	doc.setFontType("bold");
	doc.text(8, 10, 'Chittagong University of Engineering');
	doc.text(55,16,'&')
	doc.text(43,21,'Technology');
	doc.setFontType("normal");
	doc.text(10,30,'Money Receipt');
	doc.text(10,40,'Bank Copy (1)');

	doc.setFontSize(13);
	doc.text(50,50,name);
	doc.text(50,60,id);
	doc.text(50,70,dept);

	doc.text(155,50,name);
	doc.text(155,60,id);
	doc.text(155,70,dept);

	doc.setFontSize(16);
	doc.text(10,50,'Name: ');
	doc.text(10,60,'ID No: ');
	doc.text(10,70,'Dept: ');
	doc.text(10,80,'Level: 3');
	doc.text(10,90,'Term: I');
	doc.text(10,100,'Session: 2012-13');
	doc.text(10,110,'Submission Date: ');
	doc.line(10, 115, 100, 115); // horizontal line
	doc.text(30,121,'ACC No: 34129302');
	doc.line(10,123,100,123);
	doc.line(10,125,100,125);
	doc.text(30,130,'Description');
	doc.text(82,131,'TAKA');
	doc.line(10,133,100,133);
	doc.text(12,138,'Student fees');
	doc.line(10,141,100,141);
	doc.text(12,146,'Admission fees');
	doc.line(10,149,100,149);
	doc.text(12,154,'Bus rent');
	doc.line(10,157,100,157);
	doc.text(12,162,'Student welfare fees');
	doc.line(12,165,100,165);
	doc.text(12,170,'Religious program');
	doc.line(10,173,100,173);
	doc.text(12,178,'Library fees');
	doc.line(10,181,100,181);
	doc.text(12,186,'Convocation');
	doc.line(10,189,100,189);
	doc.text(12,194,'Medical fees');
	doc.line(10,197,100,197);
	doc.text(12,202,'Registration');
	doc.text(82,202,amount);
	doc.line(10,205,100,205);
	doc.text(12,210,'Character certificate');
	doc.line(10,213,100,213);
	doc.text(12,218,'Course duration certificate');
	doc.line(10,220,100,220);
	doc.text(12,225,'Donation');
	doc.text(82,225,donation);
	doc.line(10,228,100,228);
	doc.line(10,230,100,230);
	doc.text(12,235,'Total amount');
	doc.text(82,235,total_amount);
	doc.line(10,238,100,238);
	doc.text(10,248,'Signature')
	doc.text(15,260,'.............');
	doc.text(15,265,'Student');
	doc.text(75,260,'.............');
	doc.text(75,265,'Cashier');
	
	doc.setFontType("bold");
	doc.text(110, 10, 'Chittagong University of Engineering');
	doc.text(155,16,'&')
	doc.text(143,21,'Technology');
	doc.setFontType("normal");
	doc.text(115,30,'Money Receipt');
	doc.text(115,40,'Bank Copy (2)');
	doc.text(115,50,'Name: ')
	doc.text(115,60,'ID No: ');
	doc.text(115,70,'Dept: ');
	doc.text(115,80,'Level: 3');
	doc.text(115,90,'Term: I');
	doc.text(115,100,'Session: 2012-13');
	doc.text(115,110,'Submission Date: ');
	doc.line(115, 115, 205, 115); // horizontal line
	doc.text(135,121,'ACC No: 34129302');
	doc.line(115,123,205,123);
	doc.line(115,125,205,125);
	doc.text(135,130,'Description');
	doc.text(187,131,'TAKA');
	doc.line(115,133,205,133);
	doc.text(117,138,'Student fees');
	doc.line(115,141,205,141);
	doc.text(117,146,'Admission fees');
	doc.line(115,149,205,149);
	doc.text(117,154,'Bus rent');
	doc.line(115,157,205,157);
	doc.text(117,162,'Student welfare fees');
	doc.line(115,165,205,165);
	doc.text(117,170,'Religious program');
	doc.line(115,173,205,173);
	doc.text(117,178,'Library fees');
	doc.line(115,181,205,181);
	doc.text(117,186,'Convocation');
	doc.line(115,189,205,189);
	doc.text(117,194,'Medical fees');
	doc.line(115,197,205,197);
	doc.text(117,202,'Registration');
	doc.text(187,202,amount);
	doc.line(115,205,205,205);
	doc.text(117,210,'Character certificate');
	doc.line(115,213,205,213);
	doc.text(117,218,'Course duration certificate');
	doc.line(115,220,205,220);
	doc.text(117,225,'Donation');
	doc.text(187,225,donation);
	doc.line(115,228,205,228);
	doc.line(115,230,205,230);
	doc.text(117,235,'Total amount');
	doc.text(187,235,total_amount);
	doc.line(115,238,205,238);
	doc.text(115,248,'Signature')
	doc.text(120,260,'.............');
	doc.text(120,265,'Student');
	doc.text(175,260,'.............');
	doc.text(175,265,'Cashier');

	doc.addPage();
	
	doc.setLineWidth(.7);
	doc.line(10, 125, 10, 238); // vertical line
	doc.line(80, 125, 80, 238); // vertical line
	doc.line(100, 125, 100, 238); // vertical line
	doc.line(115, 125, 115, 238); // vertical line
	doc.line(185, 125, 185, 238); // vertical line
	doc.line(205, 125, 205, 238); // vertical line
	doc.setFontType("bold");
	doc.text(8, 10, 'Chittagong University of Engineering');
	doc.text(55,16,'&')
	doc.text(43,21,'Technology');
	doc.setFontType("normal");

	doc.setFontSize(13);
	doc.text(50,50,name);
	doc.text(50,60,id);
	doc.text(50,70,dept);

	doc.text(155,50,name);
	doc.text(155,60,id);
	doc.text(155,70,dept);

	doc.setFontSize(16);
	doc.setFontType("normal");
	doc.text(10,30,'Money Receipt');
	doc.text(10,40,'Academic Copy');
	doc.text(10,50,'Name: ')
	doc.text(10,60,'ID No: ');
	doc.text(10,70,'Dept: ');
	doc.text(10,80,'Level: 3');
	doc.text(10,90,'Term: I');
	doc.text(10,100,'Session: 2012-13');
	doc.text(10,110,'Submission Date: ');
	doc.line(10, 115, 100, 115); // horizontal line
	doc.text(30,121,'ACC No: 34129302');
	doc.line(10,123,100,123);
	doc.line(10,125,100,125);
	doc.text(30,130,'Description');
	doc.text(82,131,'TAKA');
	doc.line(10,133,100,133);
	doc.text(12,138,'Student fees');
	doc.line(10,141,100,141);
	doc.text(12,146,'Admission fees');
	doc.line(10,149,100,149);
	doc.text(12,154,'Bus rent');
	doc.line(10,157,100,157);
	doc.text(12,162,'Student welfare fees');
	doc.line(12,165,100,165);
	doc.text(12,170,'Religious program');
	doc.line(10,173,100,173);
	doc.text(12,178,'Library fees');
	doc.line(10,181,100,181);
	doc.text(12,186,'Convocation');
	doc.line(10,189,100,189);
	doc.text(12,194,'Medical fees');
	doc.line(10,197,100,197);
	doc.text(12,202,'Registration');
	doc.text(82,202,amount);
	doc.line(10,205,100,205);
	doc.text(12,210,'Character certificate');
	doc.line(10,213,100,213);
	doc.text(12,218,'Course duration certificate');
	doc.line(10,220,100,220);
	doc.text(12,225,'Donation');
	doc.text(82,225,donation);
	doc.line(10,228,100,228);
	doc.line(10,230,100,230);
	doc.text(12,235,'Total amount');
	doc.text(82,235,total_amount);
	doc.line(10,238,100,238);
	doc.text(10,248,'Signature')
	doc.text(15,260,'.............');
	doc.text(15,265,'Student');
	doc.text(75,260,'.............');
	doc.text(75,265,'Cashier');
	
	doc.setFontType("bold");
	doc.text(110, 10, 'Chittagong University of Engineering');
	doc.text(155,16,'&')
	doc.text(143,21,'Technology');
	doc.setFontType("normal");
	doc.text(115,30,'Money Receipt');
	doc.text(115,40,'Student Copy');
	doc.text(115,50,'Name: ')
	doc.text(115,60,'ID No: ');
	doc.text(115,70,'Dept: ');
	doc.text(115,80,'Level: 3');
	doc.text(115,90,'Term: I');
	doc.text(115,100,'Session: 2012-13');
	doc.text(115,110,'Submission Date: ');
	doc.line(115, 115, 205, 115); // horizontal line
	doc.text(135,121,'ACC No: 34129302');
	doc.line(115,123,205,123);
	doc.line(115,125,205,125);
	doc.text(135,130,'Description');
	doc.text(187,131,'TAKA');
	doc.line(115,133,205,133);
	doc.text(117,138,'Student fees');
	doc.line(115,141,205,141);
	doc.text(117,146,'Admission fees');
	doc.line(115,149,205,149);
	doc.text(117,154,'Bus rent');
	doc.line(115,157,205,157);
	doc.text(117,162,'Student welfare fees');
	doc.line(115,165,205,165);
	doc.text(117,170,'Religious program');
	doc.line(115,173,205,173);
	doc.text(117,178,'Library fees');
	doc.line(115,181,205,181);
	doc.text(117,186,'Convocation');
	doc.line(115,189,205,189);
	doc.text(117,194,'Medical fees');
	doc.line(115,197,205,197);
	doc.text(117,202,'Registration');
	doc.text(187,202,amount);
	doc.line(115,205,205,205);
	doc.text(117,210,'Character certificate');
	doc.line(115,213,205,213);
	doc.text(117,218,'Course duration certificate');
	doc.line(115,220,205,220);
	doc.text(117,225,'Donation');
	doc.text(187,225,donation);
	doc.line(115,228,205,228);
	doc.line(115,230,205,230);
	doc.text(117,235,'Total amount');
	doc.text(187,235,total_amount);
	doc.line(115,238,205,238);
	doc.text(115,248,'Signature')
	doc.text(120,260,'.............');
	doc.text(120,265,'Student');
	doc.text(175,260,'.............');
	doc.text(175,265,'Cashier');
	// Output as Data URI
	
	doc.output('datauri');
}

function demo3() {
	var doc = new jsPDF();
	var year = "<?php echo $year?>";
	var code = "<?php echo $code?>";
	var roll = "<?php echo $roll?>";
	var name = "<?php echo $name?>";
	var dept = "<?php echo $dept?>";
	var hall_name = "<?php echo $hall_name?>";
	var course1 = "<?php echo $course1?>";
	var course2 = "<?php echo $course2?>";
	var course3 = "<?php echo $course3?>";
	var course4 = "<?php echo $course4?>";
	var course5 = "<?php echo $course5?>";
	var course6 = "<?php echo $course6?>";
	var course7 = "<?php echo $course7?>";
	var course8 = "<?php echo $course8?>";
	var course1_title = "<?php echo $course1_title?>";
	var course2_title = "<?php echo $course2_title?>";
	var course3_title = "<?php echo $course3_title?>";
	var course4_title = "<?php echo $course4_title?>";
	var course5_title = "<?php echo $course5_title?>";
	var course6_title = "<?php echo $course6_title?>";
	var course7_title = "<?php echo $course7_title?>";
	var course8_title = "<?php echo $course8_title?>";
	var credit1 = "<?php echo $credit1?>";
	var credit2 = "<?php echo $credit2?>";
	var credit3 = "<?php echo $credit3?>";
	var credit4 = "<?php echo $credit4?>";
	var credit5 = "<?php echo $credit5?>";
	var credit6 = "<?php echo $credit6?>";
	var credit7 = "<?php echo $credit7?>";
	var credit8 = "<?php echo $credit8?>";
	var total_credit = "<?php echo $total_credit?>";

	doc.setFontSize(22);
	doc.setFontType("bold");
	doc.text(11, 15, 'Chittagong University of Engineering & Technology');
	doc.setFontType("normal");
	doc.setFontSize(16);
	doc.text(80,25,'Chittagong - 4349');
	doc.text(70,35,'Course Registration Form');
	doc.setLineWidth(.8);
	doc.line(10, 100, 10, 215); // vertical line
	doc.line(54, 100, 54, 215); // vertical line
	doc.line(164, 100, 164, 215); // vertical line
	doc.line(200, 100, 200, 215); // vertical line
	
	doc.line(10, 40, 200, 40); // horizontal line
	doc.text(10,52,'Student No. ');
	doc.text(45,51,'.................');
	doc.text(53,56,'Year');
	doc.text(53,50,year);
	doc.text(75,51,'..................');
	doc.text(75,56,'Dept. Code');
	doc.text(85,50,'0'+code);
	doc.text(105,51,'.................');
	doc.text(110,56,'Roll No');
	doc.text(112,50,'0'+roll);
	doc.text(10,68,'Name of the Student: ');
	doc.text(70,68,name);
	doc.text(50,78,dept);
	doc.text(10,78,'Department:');
	doc.text(70,78,'Level:		3');
	doc.text(110,78,'Term:		I');
	doc.text(150,78,'Session:	2012-13');
	doc.line(10, 81, 200, 81); // horizontal line
	doc.text(10,91,'Name of the Hall: ');
	doc.text(70,91,hall_name);
	doc.line(10, 100, 200, 100); // horizontal line
	doc.text(20,110,'Course No');
	doc.text(20, 122, course1);
	doc.text(20, 132, course2);
	doc.text(20, 142, course3);
	doc.text(20, 152, course4);
	doc.text(20, 162, course5);
	doc.text(20, 172, course6);
	doc.text(20, 182, course7);
	doc.text(20, 192, course8);
	doc.text(90,110,'Course Title');
	doc.setFontSize(10);
	doc.text(57,122,course1_title);
	doc.text(57,133,course2_title);
	doc.text(57,142,course3_title);
	doc.text(57,152,course4_title);
	doc.text(57,161,course5_title);
	doc.text(57,171,course6_title);
	doc.text(57,181,course7_title);
	doc.text(57,192,course8_title);
	doc.setFontSize(16);
	doc.text(167,110,'Credit Hours');
	doc.text(177,122,credit1);
	doc.text(177,132,credit2);
	doc.text(177,142,credit3);
	doc.text(177,152,credit4);
	doc.text(177,162,credit5);
	doc.text(177,172,credit6);
	doc.text(177,182,credit7);
	doc.text(177,192,credit8);
	doc.line(10, 115, 200, 115); // horizontal line
	doc.line(10, 125, 200, 125); // horizontal line
	doc.line(10, 135, 200, 135); // horizontal line
	doc.line(10, 145, 200, 145); // horizontal line
	doc.line(10, 155, 200, 155); // horizontal line
	doc.line(10, 165, 200, 165); // horizontal line
	doc.line(10, 175, 200, 175); // horizontal line
	doc.line(10, 185, 200, 185); // horizontal line
	doc.line(10, 195, 200, 195); // horizontal line
	doc.line(10, 205, 200, 205); // horizontal line
	doc.line(10, 215, 200, 215); // horizontal line
	doc.text(10,230,'Credit Hours Taken(Current Term) ');
	doc.text(105,230,total_credit);
	doc.rect(100, 223, 25, 10); // empty square
	//doc.text(105,232,'.................');
	doc.text(140,245,'........................................');
	doc.text(140,251,'Signature of the Student');
	doc.text(140,258,'Date: ');
	doc.text(20,280,'............')
	doc.text(20,285,'Provost');
	doc.text(90,280,'............');
	doc.text(90,285,'Advisor');
	doc.text(160,280,'..........');
	doc.text(160,285,'Head');

	// Output as Data URI
	
	doc.output('datauri');
}

</script>


<script type="text/javascript">
// Google Analytics

var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
</script>
<script type="text/javascript">
try {
var pageTracker = _gat._getTracker("UA-2746979-4");
pageTracker._trackPageview();
} catch(err) {}</script>
</body>
</html>