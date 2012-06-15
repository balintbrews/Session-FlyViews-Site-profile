<?php

/**
 * @file drupalcons_views_handler_field_link.inc
 * "DrupalCon" link field handler.
 */

/**
 * Field handler to render a field as a link.
 */
class drupalcons_views_handler_field_link extends views_handler_field {

  function render($values) {
    $value = $this->get_value($values);
    return $this->render_link($this->sanitize_value($value), $values);
  }

  function render_link($data, $values) {
    if ($data !== NULL && $data !== '') {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = $this->get_value($values);
    }
    return $data;
  }

  /**
   * Called to add the field to a query.
   */
  function query() {
    $this->field_alias = $this->real_field;
  }

}

