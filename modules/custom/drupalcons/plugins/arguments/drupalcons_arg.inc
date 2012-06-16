<?php

/**
 * @file drupalcons_arg.inc
 * Plugin to provide an argument handler for the DrupalCon context.
 */

$plugin = array(
  'title' => t('DrupalCon'),
  'keyword' => 'drupalcon',
  'description' => t('Creates a DrupalCon context from the argument.'),
  'context' => 'drupalcon_argument_context',
  'placeholder form' => array(
    '#type' => 'textfield',
    '#description' => t('Enter the DrupalCon argument'),
  ),
);


function drupalcon_argument_context($arg, $conf = NULL, $empty = FALSE) {
  if ($empty) {
    return ctools_context_create_empty('drupalcon');
  }
  if (!is_numeric($arg)) {
    return FALSE;
  }

  // @todo: Do the request here.

  return ctools_context_create('drupalcon', $drupalcon);
}

