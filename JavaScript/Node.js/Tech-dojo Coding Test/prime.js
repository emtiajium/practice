// generate prime upto 100005

var n = 100005;
var flag = [0, 0, 1, 1];
for(var i = 4; i < n; i++) {
  flag[i] = 1;
}
for(var i = 4; i < n; i += 2) {
  flag[i] = 0;
}
var condition = parseInt(Math.sqrt(n) + 1);
for(var i = 3; i < condition; i += 2) {
  if(flag[i] == 1) {
    var r = i * 2;
    for(var j = i * i; j < n; j += r) {
      flag[j] = 0;
    }
  }
}

var prime = [2];
for(var i = 3, j = 1; i < n; i += 2) {
  if(flag[i] == 1) {
    prime[j] = i;
    j++;
  }
}

// three functions

var primeSieve = function(n) {
  console.log('[0, ');
  for(var i = 1; i < n; i++) {
    console.log(flag[i] + ', ');
  }
  console.log(flag[i] + ']');
};

var nthPrime = function(n) {
  console.log(prime[n-1]);
};

var sumOfPrime =  function(n) {
  var sum = 0;
  for(var i = 0; i < n; i++) {
    if(flag[i] == 1) {
      sum += i;
    }
  }
  console.log(sum);
};

// function calling

primeSieve(10);
nthPrime(3);
sumOfPrime(9);