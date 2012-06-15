<?php

/**
 * @file drupalcons_views_handler_sort_year.inc
 * Basic "DrupalCon" sort handler for years.
 */

/**
 * Simple sort handler specifically for sorting by years. Since the only sorting
 * option in the DrupalCon REST API is to sort by years, the only thing what we
 * can control here is the sorting order.
 */
class drupalcons_views_handler_sort_year extends views_handler_sort {

  function query() {
    $this->query->request_arguments['sort_order'] = $this->options['order'];
  }

}

