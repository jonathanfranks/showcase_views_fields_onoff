<?php

/**
 * @file
 * Definition of views_fields_onoff_form.
 */

/**
 * Provides a handler that adds the form for Fields On/Off.
 */
class views_fields_onoff_form extends views_handler_field {
  function can_expose() {
    return TRUE;
  }

  function is_exposed() {
    return TRUE;
  }

  function exposed_form(&$form, &$form_state) {
    $fields = $this->options['fields'];
    $options = array();
    $checked = array();

    $all_fields = $this->get_field_labels_no_relationship_names($this->view->display_handler);

    // Grab the fields_onoff values that have been submitted already
    $onoff_submitted = array_key_exists('fields_onoff_hidden_submitted', $_GET);
    $checked_fields = array_key_exists('fields_onoff', $_GET) ? $_GET['fields_onoff'] : array();

    // Now loop through the fields defined in the view
    foreach ($fields as $field) {
      if ($field) {
        $id = $field; //$field['id'];
        if (array_key_exists($id, $all_fields)) {
          $label = $all_fields[$id];
          $options[$id] = $label;

          // If the field is included on the querystring...
          $check_me = (!count($checked_fields) && !$onoff_submitted) || array_key_exists($id, $checked_fields);
          if ($check_me) {
            // Check it because it has already been selected
            $checked[$id] = TRUE;
          }
        }
      }
    }

    // Form API to build the checkboxes
    $form['fields_onoff'] = array(
        '#type' => 'checkboxes',
        '#title' => 'Show Fields',
        '#description' => 'Select the fields you want to display',
        '#options' => $options,
        '#value' => $options, // I don't know why we have to include #options and #value, but it doesn't work if we don't...
    );

      $form["fields_onoff_hidden_submitted"] = array(
        '#type' => 'hidden',
        '#default_value' => 1,
      );

    // Have to use $form_state['input'] because setting the default values on the form field itself doesn't work.
    // At all.
    // No idea why. Setting #default_value does absolutely nothing.
    $form_state['input']['fields_onoff'] = $checked;
  }


  function option_definition() {
    $options = parent::option_definition();

    $options['fields'] = array('default' => array());

    return $options;
  }

  /**
   * Retrieve a list of fields for the current display with the
   * relationship associated if it exists.
   *
   * @param $groupable_only
   *  Return only an array of field labels from handler that return TRUE
   *  from use_string_group_by method.
   */
  function get_field_labels_no_relationship_names($display_handler) {
    $groupable_only = FALSE;

    $options = array();
    foreach ($display_handler->get_handlers('relationship') as $relationship => $handler) {
      if ($label = $handler->label()) {
        $relationships[$relationship] = $label;
      }
      else {
        $relationships[$relationship] = $handler->ui_name();
      }
    }

    foreach ($display_handler->get_handlers('field') as $id => $handler) {
      if ($groupable_only && !$handler->use_string_group_by()) {
        // Continue to next handler if it's not groupable.
        continue;
      }
      if ($label = $handler->label()) {
        $options[$id] = $label;
      }
      else {
        $options[$id] = $handler->ui_name();
      }
    }
    return $options;
  }


  function options_form(&$form, &$form_state) {
    $all_fields = $this->get_field_labels_no_relationship_names($this->view->display_handler);
    // Remove any field that have been excluded from the display from the list.
    foreach($all_fields as $key => $field) {
      $exclude = $this->view->display_handler->handlers['field'][$key]->options['exclude'];
      if ($exclude) {
        unset($all_fields[$key]);
      }
    }

    // Offer to include only those fields that follow this one.
    $field_options = array_slice($all_fields, 0, array_search($this->options['id'], array_keys($all_fields)));
    $form['fields'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Fields'),
      '#description' => t('Fields to be turned on and off.'),
      '#options' => $field_options,
      '#default_value' => $this->options['fields'],
    );
  }

  function query() { }
}
