/**
 * Created by Emtiaj on 3/17/2017.
 */

'use strict';

angular.module('ModalDemo')
  .controller('ModalDemoController', ['$scope', 'Modal', function ($scope, Modal) {

    $scope.items = ['item1', 'item2', 'item3'];

    $scope.open = function () {
      var modalInfo = {
        headerTitle: 'Available Packages',
        headerDismiss: true,
        templateURL: 'modal.template.html',
        bodyText: $scope.items,
        footerActionButton: {
          class: 'btn-primary',
          text: 'Send request'
        },
        footerDismissButton: {
          class: 'btn-warning',
          text: 'Cancel'
        },
        modalType: 'modal-primary',
        getDataFromModal: getDataFromModal
      };
      var modal = Modal.confirm.showModal(modalInfo);
      modal();
    };

    var getDataFromModal = function () {
      $scope.data = Modal.actionActivityGetter();
      console.log('selectedItem', $scope.data.item);
    };

  }]);
