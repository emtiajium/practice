/**
 * Created by Emtiaj on 3/13/2017.
 */

var app = angular.module('myApp', []);

app.controller('MainController', function($scope) {
    $scope.data =  {
        firstName: 'Emtiaj',
        lastName: 'Hasan',
        email: '271emtiaj@gmail.com'
    };
});
