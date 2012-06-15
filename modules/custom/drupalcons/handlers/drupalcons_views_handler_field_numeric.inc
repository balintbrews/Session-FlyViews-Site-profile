<?php

/**
 * @file drupalcons_views_handler_field_numeric.inc
 * "DrupalCon" numeric field handler.
 */

/**
 * Field handler to render a field as a numeric value.
 */
class drupalcons_views_handler_field_numeric extends views_handler_field_numeric {

  /**
   * Called to add the field to a query.
   */
  function query() {
    $this->field_alias = $this->real_field;
  }

}

