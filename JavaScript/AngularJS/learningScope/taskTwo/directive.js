/**
 * Created by Emtiaj on 3/16/2017.
 */

var app = angular.module('myApp', []);

app.directive('myForm', function () {
    return {
        restrict:'A',
        controllerUrl: 'controller.js',
        scope: {},
        templateUrl: 'form.html'
    }
});