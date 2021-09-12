angular.module('dataTableDemo')
  .controller('MainController', ['$scope', function ($scope) {
    $scope.data = {
      columns: [
        { title: 'A' },
        { title: 'B' },
        { title: 'C' }
      ],
      values: [
        ['1', '2', '3'],
        ['4', '5', '6']
      ]
    };

  }]);