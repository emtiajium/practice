'use strict';

angular.module('dataTableDemo')
	.directive('myCustomTable', function () {
		return {
			restrict: 'A',
			scope: false,
			link: function (scope, el, attrs) {
				el.dataTable({
					data: scope.data.values,
					responsive: true,
					columns: scope.data.columns
				});
			}
		};
	});
