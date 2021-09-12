function Person(first, last) {
	this.first = first;
	this.last = last;
}

Person.prototype.fullName = function() {
	//console.log(this.first + ' ' + this.last);
	return this.first + ' ' + this.last;
};

Person.prototype.fullNameReversed = function() {
	//console.log(this.first + ' ' + this.last);
	return this.last + ' ' + this.first;
};

var s = new Person('Simon', 'Willison');
console.log(s.fullName());
console.log(s.fullNameReversed());
