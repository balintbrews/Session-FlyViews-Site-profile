<?php

/**
 * @file drupalcons.views.inc
 */

/**
 * Implements hook_views_data().
 */
function drupalcons_views_data() {
  $data = array();

  // Base table definition.
  $data['drupalcon']['table'] = array(
    'group' => t('DrupalCon'),
    'base' => array(
      'title' => t('DrupalCon'),
      'help' => t('Information about DrupalCons fetched from an external website.'),
      'query class' => 'drupalcons_query',
    ),
  );

  // ID
  $data['drupalcon']['id'] = array(
    'title' => t('ID'),
    'help' => t('Identifier of the DrupalCon.'),
    'field' => array(
      'handler' => 'drupalcons_views_handler_field',
    ),
  );

  // City
  $data['drupalcon']['city'] = array(
    'title' => t('City'),
    'help' => t('City of the DrupalCon.'),
    'field' => array(
      'handler' => 'drupalcons_views_handler_field',
    ),
  );

  // Country
  $data['drupalcon']['country'] = array(
    'title' => t('Country'),
    'help' => t('Country of the DrupalCon.'),
    'field' => array(
      'handler' => 'drupalcons_views_handler_field',
    ),
  );

  // Year
  $data['drupalcon']['year'] = array(
    'title' => t('Year'),
    'help' => t('Year of the DrupalCon.'),
    'field' => array(
      'handler' => 'drupalcons_views_handler_field',
    ),
    'filter' => array(
      'handler' => 'drupalcons_views_handler_filter_equality_year',
    ),
    'sort' => array(
      'handler' => 'drupalcons_views_handler_sort_year',
    ),
  );

  // Month
  $data['drupalcon']['month'] = array(
    'title' => t('Month'),
    'help' => t('Month of the DrupalCon.'),
    'field' => array(
      'handler' => 'drupalcons_views_handler_field',
    ),
  );

  // Attendees
  $data['drupalcon']['attendees'] = array(
    'title' => t('Attendees'),
    'help' => t('Number of attendees of the DrupalCon.'),
    'field' => array(
      'handler' => 'drupalcons_views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'drupalcons_views_handler_filter_numeric',
    ),
  );

  // About the city
  $data['drupalcon']['about_the_city'] = array(
    'title' => t('About the city'),
    'help' => t('About the city of the DrupalCon.'),
    'field' => array(
      'handler' => 'drupalcons_views_handler_field',
    ),
  );

  // Photo
  $data['drupalcon']['photo'] = array(
    'title' => t('Photo'),
    'help' => t('A photo about the city.'),
    'field' => array(
      'handler' => 'drupalcons_views_handler_field_image',
    ),
  );

  // Photo credit
  $data['drupalcon']['photo_credit'] = array(
    'title' => t('Photo credit'),
    'help' => t('Credit of the photo about the city.'),
    'field' => array(
      'handler' => 'drupalcons_views_handler_field_link',
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

