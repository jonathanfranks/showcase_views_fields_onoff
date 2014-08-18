<?php
/**
 * Created by PhpStorm.
 * User: jfranks
 * Date: 8/18/14
 * Time: 2:41 PM
 */

class views_fields_onoff_plugin_style_table_onoff extends views_plugin_style_table {
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
}