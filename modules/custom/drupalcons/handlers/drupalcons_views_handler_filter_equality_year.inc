<?php

/**
 * @file drupalcons_views_handler_filter_equality_year.inc
 * Basic "DrupalCon" equality filter handler specifically for years.
 */

/**
 * Simple filter to handle equality for the year field.
 */
class drupalcons_views_handler_filter_equality_year extends drupalcons_views_handler_filter_equality {

  /**
   * Provide the form for choosing a year.
   */
  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'radios',
      '#title' => t('Year'),
      '#default_value' => (!empty($this->value)) ? $this->value : 'All',
      '#options' => array(
        'All' => '-Any-',
        '2005' => '2005',
        '2006' => '2006',
        '2007' => '2007',
        '2008' => '2008',
        '2009' => '2009',
        '2010' => '2010',
        '2011' => '2011',
        '2012' => '2012',
      ),
    );

    if (!empty($form_state['exposed'])) {
      $identifier = $this->options['expose']['identifier'];
      if (!isset($form_state['input'][$identifier])) {
        $form_state['input'][$identifier] = $this->value;
      }
    }
  }

}

