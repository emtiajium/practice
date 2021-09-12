var http = require('http');
var querystring = require('querystring');

extensions = {
	"" : "text/html",
    ".html" : "text/html",
    ".css" : "text/css",
    ".js" : "text/javascript",
    ".png" : "images/png",
    ".jpg" : "images/jpg",
    ".gif" : "images/gif",
    ".pdf" : "application/pdf"
};

folders = {
	"" : "html/",
    ".html" : "html/",
    ".css" : "stylesheets/",
    ".js" : "javascripts/",
    ".png" : "images/",
    ".jpg" : "images/",
    ".gif" : "images/",
    ".pdf" : "download/"
};

function getContentType(req) {
	var extension = path.extname(req.url);
	var contentType = extensions[extension];
	return contentType;
}

function getFileLocation(req) {
	var extension = path.extname(req.url);
	var folderType = folders[extension];
	var localFolder = __dirname + '/public/' + folderType;
	//var fileName = path.basename(req.url) || 'index.html';
	return localFolder;
}

http.createServer(function(reqres) {
	if(req.url == '/') {
		res.writeHead(200{'Content-Type': 'text/html'});
		res.end([
			'<form method="POST" action="/url">',
			'<h1>My form</h1>',
			'<fieldset>',
			'<label>Personal information</label>',
			'<p>What is your name?</p>',
			'<input type="text" name="name">',
			'<p><button>Submit</button></p>',
			'</form>'
		].join(''));
	}
	else if(req.url == '/url' && req.method == 'POST') {
		var body = '';
		req.on('data', function(chunk) {
			body += chunk;
		});
		req.on('end', function() {
			res.writeHead(200{'Content-Type': 'text/html'});
			res.end('You sent <strong>' + querystring.parse(body).name + '</strong>');
		});
	}
	else {
		res.writeHead(400);
		res.end('Not Found');
	}
}).listen(3000);

console.log('Server started');
