<?php

/**
 * @file drupalcons_views_handler_filter_numeric.inc
 * Basic "DrupalCon" numeric filter handler.
 */

/**
 * Simple filter to handle numeric filtering. Supports only the "between" operator.
 */
class drupalcons_views_handler_filter_numeric extends drupalcons_views_handler_filter_equality {

  /**
   * Provide simple equality operator
   */
  function operator_options() {
    return array(
      'between' => t('Is between'),
    );
  }

  function value_form(&$form, &$form_state) {
    $form['value']['#tree'] = TRUE;

    $form['value']['min'] = array(
      '#type' => 'textfield',
      '#title' => empty($form_state['exposed']) ? t('Min') : '',
      '#size' => 30,
      '#default_value' => $this->value['min'],
    );
    $form['value']['max'] = array(
      '#type' => 'textfield',
      '#title' => empty($form_state['exposed']) ? t('And max') : t('And'),
      '#size' => 30,
      '#default_value' => $this->value['max'],
    );

    if (!empty($form_state['exposed']) && !isset($form_state['input'][$identifier]['min'])) {
      $form_state['input'][$identifier]['min'] = $this->value['min'];
    }
    if (!empty($form_state['exposed']) && !isset($form_state['input'][$identifier]['max'])) {
      $form_state['input'][$identifier]['max'] = $this->value['max'];
    }

    if (!isset($form['value'])) {
      // Ensure there is something in the 'value'.
      $form['value'] = array(
        '#type' => 'value',
        '#value' => NULL
      );
    }
  }

}

