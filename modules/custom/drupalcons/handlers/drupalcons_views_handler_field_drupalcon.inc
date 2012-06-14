<?php

/**
 * @file drupalcons_views_handler_field_drupalcon.inc
 * Basic "DrupalCon" field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a DrupalCon.
 */
class drupalcons_views_handler_field_drupalcon extends views_handler_field {

  function init(&$view, &$options) {
    parent::init($view, $options);
    if (!empty($this->options['link_to_drupalcon'])) {
      $this->additional_fields['id'] = array('table' => 'drupalcons', 'field' => 'id');
    }
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_drupalcon'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Provide link.
   */
  function options_form(&$form, &$form_state) {
    $form['link_to_drupalcon'] = array(
      '#title' => t('Link this field to the DrupalCon page.'),
      '#description' => t("Enable to override this field's links."),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_drupalcon']),
    );
    parent::options_form($form, $form_state);
  }

  /**
   * Render whatever the data is as a link to the DrupalCon page.
   * Data should be made XSS safe prior to calling this function.
   */
  function render_link($data, $values) {
    if (!empty($this->options['link_to_drupalcon']) && $data !== NULL && $data !== '') {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "drupalcon/" . $this->get_value($values);
    }
    return $data;
  }

  function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }

  /**
   * Called to add the field to a query.
   */
  function query() {
    $this->field_alias = $this->real_field;
  }

}

