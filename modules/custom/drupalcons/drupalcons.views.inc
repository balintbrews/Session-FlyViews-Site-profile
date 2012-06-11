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
      'query class' => 'drupalcons_query',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_plugins().
 */
function drupalcons_views_plugins() {
  $plugins = array(
    'query' => array(
      'drupalcons_query' => array(
        'title' => t('DrupalConsAPIRequest'),
        'help' => t('Uses DrupalConsAPIRequest for querying information about DrupalCons from an external website.'),
        'handler' => 'drupalcons_views_plugin_query',
      ),
    ),
  );

  return $plugins;
}

