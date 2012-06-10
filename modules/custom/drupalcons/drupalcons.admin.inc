<?php

/**
 * @file drupalcons.admin.inc
 */

/**
 * Form builder; administration form.
 */
function drupalcons_admin_form($form) {
  $form = array();
  $form['drupalcons_api_url'] = array(
    '#title' => t('API URL'),
    '#description' => t('Enter the URL where the DrupalCon information can be fetched from. Do not include trailing slash.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('drupalcons_api_url', DRUPALCONS_DEFAULT_API_URL),
  );
  return system_settings_form($form);
}

