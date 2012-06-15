<?php

/**
 * @file drupalcons_views_plugin_query.inc
 */

/**
 * Class for implementing a simple Views query backend plugin, that uses our custom class
 * to execute requests to get information about DrupalCons.
 *
 * Possible improvement: implementing pager functionality.
 * See the EntityFieldQuery Views Backend module for an example:
 * http://drupalcode.org/project/efq_views.git/blob/refs/heads/7.x-1.x:/efq_views_plugin_query.inc
 */
class drupalcons_views_plugin_query extends views_plugin_query {

  /**
   * The DrupalConsAPIRequest object.
   */
  var $request;

  /**
   * Constructor; Create the basic request object.
   */
  function init($base_table, $base_field, $options) {
    parent::init($base_table, $base_field, $options);
    $this->request = new DrupalConsAPIRequest();
  }

  /**
   * Builds the necessary info to execute the query.
   */
  function build(&$view) {
    $view->build_info['drupalcons_request'] = $this->request;

    // Adding arguments to the request.
    if (isset($view->query->request_arguments)) {
      foreach ($view->query->request_arguments as $arg_key => $arg_value) {
        $view->build_info['drupalcons_request']->addArgument($arg_key, $arg_value);
      }
    }
  }

  /**
   * Executes the request and fills the associated view object with according
   * values.
   */
  function execute(&$view) {
    $request = $view->build_info['drupalcons_request'];

    $start = microtime(true);

    $view->result = array();
    $view->result = $request->execute();

    $view->execute_time = microtime(true) - $start;
  }
}
