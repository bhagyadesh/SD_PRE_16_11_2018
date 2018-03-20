/**
 * @file
 * Intel EA Training Center Approved Nouns JS.
 */

/**
 * Provide the HTML to create the modal dialog.
 */
Drupal.theme.prototype.intel_ea_training_center = function () {
  var html = '';

  html += '<div id="ctools-modal" class="popups-box">';
  html += '  <div class="ctools-modal-content ctools-modal-intel-ea-training-center">';
  html += '    <span class="popups-close"><a class="close" href="#">' + Drupal.CTools.Modal.currentSettings.closeImage + '</a></span>';
  html += '    <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body"></div></div>';
  html += '  </div>';
  html += '</div>';

  return html;
}
