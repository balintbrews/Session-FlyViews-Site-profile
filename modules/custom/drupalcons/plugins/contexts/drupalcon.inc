<?php

/**
 * @file drupalcons_context.inc
 * Plugin to provide a DrupalCon context.
 */

$plugin = array(
  'title' => t('DrupalCon'),
  'description' => t('A DrupalCon object.'),
  'context' => 'drupalcon_context_create',
  'edit form' => 'drupalcon_context_settings_form',
  'keyword' => 'drupalcon',
  'context name' => 'drupalcon',
  'convert list' => 'drupalcon_context_convert_list',
  'convert' => 'drupalcon_context_convert',
  'placeholder form' => array(
    '#type' => 'textfield',
    '#description' => t('Enter the ID of the DrupalCon'),
  ),
);

function drupalcon_context_create($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('drupalcon');
  $context->plugin = 'drupalcon';

  if ($empty) {
    return $context;
  }

  if ($conf) {
    $request = new DrupalConsAPIRequest();
    $data = $request
      ->getItem($data['drupalcon'])
      ->execute();
  }

  if (!empty($data)) {
    $context->data = $data;
    $context->argument = check_plain($data->id);
    $context->title = t('DrupalCon @city', array('@city' => $data->city));
    return $context;
  }

  return FALSE;
}

function drupalcon_context_settings_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['drupalcon'] = array(
    '#title' => t('DrupalCon ID'),
    '#description' => t('Enter a DrupalCon identifier'),
    '#default_value' => $conf['drupalcon'],
    '#type' => 'textfield',
  );
  return $form;
}

function drupalcon_context_settings_form_submit($form, &$form_state) {
  $form_state['conf']['drupalcon'] = $form_state['values']['drupalcon'];
}

/**
 * Provides a list of keywords for use in a content type, pane etc.
 */
function drupalcon_context_convert_list() {
  return array(
    'city' => t('City'),
    'country' => t('Country'),
    'year' => t('Year'),
    'month' => t('Month'),
    'attendees' => t('Attendees'),
    'about_the_city' => t('About the city'),
    'photo' => t('Photo'),
    'photo_credit' => t('Photo credit'),
  );
}

function drupalcon_context_convert($context, $type) {
  return $context->data->{$type};
}

