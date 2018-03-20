<?php

/**
 * @file
 * Definition of views_handler_field_locale_language.
 */

/**
 * Field handler to translate a language into its readable form.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_locale_language extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);

    // Convert old language display information new format.
    // @todo Remove for next major version.
    if (isset($this->options['native_language'])) {
      $this->options['language_display'] = 'native';
      unset($this->options['language_display']);
    }
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['language_display'] = array('default' => 'name');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['language_display'] = array(
      '#title' => t('Language display'),
      '#type' => 'radios',
      '#options' => array(
        'name' => t('Language name in English'),
        'native' => t('Native language name'),
        'langcode' => t('Language code'),
      ),
      '#default_value' => $this->options['language_display'],
      '#description' => t('The type of language information will be displayed'),
    );
  }

  function render($values) {
    $value = $this->get_value($values);

    if (!isset($this->options['language_display'])) {
      $this->options['language_display'] = 'name';
    }

    if ($this->options['language_display'] == 'langcode') {
      $value = check_plain($value);
    }
    else {
      $languages = views_language_list($this->options['language_display']);
      $value = isset($languages[$value]) ? $languages[$value] : '';
    }

    return isset($value) ? $value : '';
  }
}
