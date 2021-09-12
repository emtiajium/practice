'use strict';

angular.module('ModalDemo')
  .factory('Modal', function ($rootScope, $modal) {

    var selected = {
      item: ''
    };

    /**
     * set selected data into `selected` object
     * execute callback function, i.e.,
     * now data is available in parent controller
     * @param value
     * @param dismissFunction
     * @param callback
     */

    var actionActivitySetter = function (value, dismissFunction, callback) {
      selected.item = value;
      dismissFunction();
      callback();
    };

    var openModal = function (scope) {
      var modalScope = $rootScope.$new();
      scope = scope || {};
      angular.extend(modalScope, scope);
      return $modal.open({
        templateUrl: modalScope.modal.templateURL,
        windowClass: modalScope.modal.modalType,
        scope: modalScope
      });
    };

    return {
      confirm: {
        showModal: function(modalInfo) {
          return function() {
            openModal({
              modal: {
                headerTitle: modalInfo.headerTitle,
                headerDismiss: modalInfo.headerDismiss,
                templateURL: modalInfo.templateURL,
                bodyText: modalInfo.bodyText,
                footerActionButton: {
                  class: modalInfo.footerActionButton.class,
                  text: modalInfo.footerActionButton.text,
                  actionActivity: actionActivitySetter
                },
                footerDismissButton: {
                  class: modalInfo.footerDismissButton.class,
                  text: modalInfo.footerDismissButton.text
                },
                modalClass: modalInfo.modalType,
                returnDataToParentController: modalInfo.getDataFromModal
              }
            });
          };
        }
      },
      actionActivityGetter: function () {
        return selected;
      }
    };
  });
