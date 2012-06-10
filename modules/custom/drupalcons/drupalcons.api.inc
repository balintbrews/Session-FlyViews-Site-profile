<?php

/**
 * @file drupalcons.api.inc
 */

/**
 * Simple class for puttig together a URL for the API call, and doing an HTTP request
 * for retrieving information about DrupalCons.
 * All public methods return $this and can be chained together.
 *
 * Possible and recommended improvement: implement a caching logic.
 * See the Last.FM module for a smart example:
 * http://drupalcode.org/project/lastfm.git/blob/refs/heads/7.x-2.x:/lastfm.api.inc
 */
class drupalconsAPIRequest {

  // Default API URL for the request.
  private $api_url;

  // Flag to designate whether we are in debug mode.
  private $debug_mode;

  // API arguments. Use drupalconsAPIRequest->set_argument() to set.
  private $arguments = array();

  // API response, can be retrieved by drupalconsAPIRequest->get_response().
  private $response;

  /**
   * Constructor.
   */
  public function __construct() {
    $this->api_url = variable_get('drupalcons_api_url', DRUPALCONS_DEFAULT_API_URL);
    $this->debug_mode = variable_get('drupalcons_debug_mode', DRUPALCONS_DEFAULT_DEBUG_MODE);
  }

  /**
   * Set an argument for the request.
   */
  public function set_argument($key, $value) {
    $this->arguments[$key] = $value;
    return $this;
  }

  /**
   * Executes the request. The result of the call can be retrieved with
   * using drupalconsAPIRequest->get_response().
   */
  public function execute() {
    $options = array(
      'query' => $this->arguments,
      'absolute' => TRUE
    );
    $request_url = url($this->api_url, $options);
    if ($this->debug_mode) {
      drupal_set_message(t('Request URL: !url', array('!url' => $request_url)));
    }
    $this->response = $this->request($request_url);
    return $this;
  }

  /**
   * Actual HTTP request.
   */
  private function request($request_url) {
    $response = drupal_http_request($request_url);
    if ($response->code != 200) {
      watchdog('drupalcons', 'HTTP error !code received.', array('!code' => $response->code), WATCHDOG_ERROR);
      return FALSE;
    }
    $data = json_decode($response->data);
    if (!is_object($data)) {
      watchdog('drupalcons', 'Did not receive valid API response (invalid JSON).', array(), WATCHDOG_ERROR);
      return FALSE;
    }
    if (isset($data->error)) {
      watchdog('drupalcons', 'Error !code received: %message', array('!code' => $data->error, '%message' => $data->message), WATCHDOG_ERROR);
      return FALSE;
    }
    return $data;
  }

  /**
   * Returns the API response.
   */
  public function get_response() {
    return $this->response;
  }

}
