var mysql = require('mysql');

function serveForm() {

	var id = 1004050;

	var db = mysql.createConnection({
		host : '127.0.0.1',
		user : 'root',
		password : '',
		database : 'online_reg'
	});
	//console.log('databaseConnection ' + Object.keys(db));
	db.connect(function(err) {
		if(err) {
			db.end();
			console.log(err.message);
			return;
		}
		console.log('Connected to database successfully from serveForm');
	});

	var year, code, roll;
	var password;
	var name, departmentName;
	var fatherName, motherName, nationality;
	var course1, course2, course3, course4, course5, course6, course7, course8;
	var hallName;
	var totalCredit;
	var course1Title, course2Title, course3Title, course4Title, course5Title, course6Title, course7Title, course8Title;
	var credit1, credit2, credit3, credit4, credit5, credit6, credit7, credit8;
	var amount;
	var donation;
	var totalAmount;

	year = parseInt(id / 100000);
	code = parseInt(id / 1000) % 100;
	roll = id % 100;

	function queryFromDatabase(callback) {
		var sqlStatement = "SELECT `password` FROM `login` WHERE `id` = " + id;
		db.query(sqlStatement, function(err, rows) {
			password = rows[0].password;
		});
		
		sqlStatement = "SELECT `name`, `dept_name` FROM `academic_info` WHERE `id` = " + id;
		db.query(sqlStatement, function(err, rows) {
			name = rows[0].name;
			departmentName = rows[0].dept_name;
		});
		
		sqlStatement = "SELECT `father_name`, `mother_name`, `nationality` FROM `personal_info` WHERE `id` = " + id;
		db.query(sqlStatement, function(err, rows) {
			fatherName = rows[0].father_name;
			motherName = rows[0].mother_name;
			nationality = rows[0].nationality;
		});

		sqlStatement = "SELECT `course1`, `course2`, `course3`, `course4`, `course5`, `course6`, `course7`, `course8` FROM `termcourse` WHERE `level_term` =31";
		db.query(sqlStatement, function(err, rows) {
			course1 = rows[0].course1;
			course2 = rows[0].course2;
			course3 = rows[0].course3;
			course4 = rows[0].course4;
			course5 = rows[0].course5;
			course6 = rows[0].course6;
			course7 = rows[0].course7;
			course8 = rows[0].course8;
			// console.log(course1);
			// console.log(course2);
			// console.log(course3);
			// console.log(course4);
			// console.log(course5);
			// console.log(course6);
			// console.log(course7);
			// console.log(course8);
		});

		sqlStatement = "SELECT `hall_name` FROM `hall_info` WHERE `id` = " + id;
		db.query(sqlStatement, function(err, rows) {
			hallName = rows[0].hall_name;
		});

		sqlStatement = "SELECT SUM(`credit`) AS `total_credit` FROM `level-3term-1`";
		db.query(sqlStatement, function(err, rows) {
			totalCredit = rows[0].total_credit;
		});

		sqlStatement = "SELECT * FROM `level-3term-1`";
		db.query(sqlStatement, function(err, rows) {
			course1Title = rows[0].course_title;
			course2Title = rows[1].course_title;
			course3Title = rows[2].course_title;
			course4Title = rows[3].course_title;
			course5Title = rows[4].course_title;
			course6Title = rows[5].course_title;
			course7Title = rows[6].course_title;
			course8Title = rows[7].course_title;

			credit1 = rows[0].credit;
			credit2 = rows[1].credit;
			credit3 = rows[2].credit;
			credit4 = rows[3].credit;
			credit5 = rows[4].credit;
			credit6 = rows[5].credit;
			credit7 = rows[6].credit;
			credit8 = rows[7].credit;
		});

		sqlStatement = "SELECT `amount` FROM `termcourse` WHERE `level_term` =31";
		db.query(sqlStatement, function(err, rows) {
			amount = rows[0].amount;
		});

		sqlStatement = "SELECT `donation` FROM `eco_info` WHERE `id` = " + id;
		db.query(sqlStatement, function(err, rows) {
			donation = rows[0].donation;
			callback();
		});

	}
	queryFromDatabase(function logMyNumber() {

		totalAmount = amount + donation;

		db.end();

		console.log(name + ' ' + departmentName + ' ' + hallName);
	});
}

serveForm();