var movieList = [
	{title : 'star wars episod 7', year : '1977', length : 125, rating : 8.7, genre : 'sci-fi'},
	{title : 'The Matrix Revolutions', year : '2003', length : 129, rating : 6.7, genre : 'sci-fi'},
	{title : 'Omen : The Final Conflict', year : '1981', length : 108, rating : 6.7, genre : 'horror'},
	{title : 'Gladiator', year : '2000', length : 155, rating : 8.5, genre : 'historical'},
	{title : 'The Patriot', year : '2000', length : 165, rating : 7.1, genre : 'historical'},
	{title : 'The Matrix Reloaded', year : '2003', length : 138, rating : 7.2, genre : 'sci-fi'},
];

var findByTitle = function(title) {
	var array = [];
	title = title.toUpperCase();
	for(var i = 0; i < movieList.length; i++) {
		getTitle = movieList[i].title.toUpperCase();
		var index = getTitle.indexOf(title);
		if(index != -1) {
			array.push(i);
		}
	}
	for(var i = 0; i < array.length; i++) {
		var j = array[i];
		console.log(movieList[j]);
	}
};

var findByGenre = function(genre) {
	genre = genre.toUpperCase();
	var array = [];
	for(var i = 0; i < movieList.length; i++) {
		getGenre = movieList[i].genre.toUpperCase();
		var index = getGenre.indexOf(genre);
		if(index != -1) {
			array.push(i);
		}
	}
	for(var i = 0; i < array.length; i++) {
		console.log(movieList[array[i]]);
	}	
};

var listAllMoviesByTitleAndYear = function() {
	copyMovieList = movieList;
	function sorting(callback) {
		var compare = function(a, b) {
			var yearA = a.year.toUpperCase(); // ignore upper and lowercase
			var yearB = b.year.toUpperCase(); // ignore upper and lowercase
		  	if (yearA < yearB) {
		    	return -1;
		  	}
		  	if (yearA > yearB) {
		    	return 1;
		  	}
		  	return 0;
		};
		copyMovieList.sort(compare);
		callback();
	}
	sorting(function logMyNumber() {
		for(i = 0; i < copyMovieList.length; i++) {
			console.log(copyMovieList[i].title + ' ' + copyMovieList[i].year);
		}
	});
};

var findByYear = function(lowerLimit, upperLimit) {
	copyMovieList = movieList;
	function sorting(callback) {
		var compare = function(a, b) {
			var yearA = a.year.toUpperCase(); // ignore upper and lowercase
			var yearB = b.year.toUpperCase(); // ignore upper and lowercase
		  	if (yearA < yearB) {
		    	return -1;
		  	}
		  	if (yearA > yearB) {
		    	return 1;
		  	}
		  	return 0;
		};
		copyMovieList.sort(compare);
		callback();
	}
	sorting(function logMyNumber() {
		for(var i = 0; i < copyMovieList.length; i++) {
			if(parseInt(copyMovieList[i].year) >= lowerLimit && parseInt(copyMovieList[i].year) <= upperLimit) {
				console.log(copyMovieList[i]);
			}
		}
	});
};

var findByRating =  function(lowerLimit, upperLimit) {
	copyMovieList = movieList;
	function sorting(callback) {
		var compare = function(a, b) {
			if (a.rating < b.rating) {
		    	return -1;
		  	}
		  	if (a.rating > b.rating) {
		    	return 1;
		  	}
		  	return 0;
		};
		copyMovieList.sort(compare);
		callback();
	}
	sorting(function logMyNumber() {
		for(var i = 0; i < copyMovieList.length; i++) {
			if(copyMovieList[i].rating >= lowerLimit && copyMovieList[i].rating <= upperLimit) {
				console.log(copyMovieList[i]);
			}
		}
	});
};

var taskSeven = function() {
	var copyMovieList = [];
	var array = [];
	for(var i = 0; i < movieList.length; i++) {
		if(movieList[i].year < 2000 && movieList[i].genre == 'sci-fi' && parseFloat(movieList[i].rating) > 8) {
			copyMovieList.push(movieList[i]);
		}
	}
	for(var i = 0; i < copyMovieList.length; i++) {
		array[i] = copyMovieList[i];
	}
	function sorting(callback) {
		var compare = function(a, b) {
			if (a.rating < b.rating) {
		    	return -1;
		  	}
		  	if (a.rating > b.rating) {
		    	return 1;
		  	}
		  	return 0;
		};
		array.sort(compare);
		callback();
	}
	sorting(function logMyNumber() {
		console.log(array);
	});
};

var taskEight = function() {
	var sum = 0;
	var count = 0;
	for(var i = 0; i < movieList.length; i++) {
		if(movieList[i].genre == 'sci-fi') {
			sum += movieList[i].rating;
			count++;
		}
	}
	var average = sum / count;
	console.log(average);
};

// console.log('Task 1');
console.log(movieList[3].title);
console.log();
// console.log('Task 2');
findByTitle('matrix');
console.log();
// console.log('Task 3');
findByGenre('sci-fi');
console.log();
// console.log('Task 4');
listAllMoviesByTitleAndYear();
console.log();
// console.log('Task 5');
findByYear(2000, 2003);
console.log();
// console.log('Task 6');
findByRating(6.7, 7.1);
console.log();
// console.log('Task 7');
taskSeven();
console.log();
// console.log('Task 8');
taskEight();
console.log();