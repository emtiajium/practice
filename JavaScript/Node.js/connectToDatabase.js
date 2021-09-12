var mysql = require('mysql');

var db = mysql.createConnection({
	host: '127.0.0.1',
	user: 'root',
	password: '',
	database: 'online_reg'
});

db.connect(function(err){
	if(err) {
		console.log(err);    
		return;
	}
	console.log('Connected to database');
	// console.log("Connected " + Object.keys(db));
	// console.log("Connected " + db['state']);
});

var t;

function queryFromDatabase(callback) {
	db.query('SELECT * FROM login LIMIT 5', function(err, rows) {
		db.end();
		if(err) {
			console.log(err);    
			return;
		}
		for(var i = 0; i < rows.length; i++)
			console.log('The ID is: ', rows[i].id);
		t = rows[0].id;
		callback();
	});
}

queryFromDatabase(function logMyNumber() {
	console.log('The 0\'th ID is: ', t);
});

console.log(t);