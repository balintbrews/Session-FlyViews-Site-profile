<?php

/**
 * @file drupalcons.views.inc
 */

/**
 * Implements hook_views_data().
 */
function drupalcons_views_data() {
  $data = array();

  $data['drupalcons']['table'] = array(
    'group' => t('DrupalCons'),
    'base' => array(
      'title' => t('DrupalCons'),
      'help' => t('Information about DrupalCons fetched from an external website.'),
      'query class' => 'drupalcons_views_plugin_query',
    ),
  );

  return $data;
}

