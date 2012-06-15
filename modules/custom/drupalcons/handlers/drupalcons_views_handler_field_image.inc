<?php

/**
 * @file drupalcons_views_handler_field_image.inc
 * "DrupalCon" image field handler.
 */

/**
 * Field handler to render a field as an image.
 */
class drupalcons_views_handler_field_image extends drupalcons_views_handler_field {

  function render($values) {
    $url = $this->get_value($values);
    return $this->render_link(theme('image', array('path' => $url)), $values);
  }

  /**
   * Called to add the field to a query.
   */
  function query() {
    $this->field_alias = $this->real_field;
  }

}

