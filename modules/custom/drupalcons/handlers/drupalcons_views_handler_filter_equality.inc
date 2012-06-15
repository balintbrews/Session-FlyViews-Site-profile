<?php

/**
 * @file drupalcons_views_handler_filter_equality.inc
 * Basic "DrupalCon" equality filter handler.
 */

/**
 * Simple filter to handle equality.
 */
class drupalcons_views_handler_filter_equality extends views_handler_filter_equality {

  /**
   * Provide simple equality operator
   */
  function operator_options() {
    return array(
      '=' => t('Is equal to'),
    );
  }

  /**
   * Add this filter to the request.
   */
  function query() {
    $this->query->request_arguments[$this->real_field] = $this->value;
  }

}

