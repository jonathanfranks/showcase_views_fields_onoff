<?php
/**
 * Created by PhpStorm.
 * User: jfranks
 * Date: 8/17/14
 * Time: 6:00 PM
 */

function views_fields_onoff_views_plugins() {
  $plugins = array(
      'style' => array(
        // Default settings for all style plugins.
          'onoff_table' => array(
              'title' => t('Table with Switchable Fields'),
              'help' => t('Displays rows in a table. The user can show or hide fields at view-time.'),
              'handler' => 'views_fields_onoff_plugin_style_table_onoff',
              'theme' => 'views_view_table',
              'uses row plugin' => FALSE,
              'uses row class' => TRUE,
              'uses fields' => TRUE,
              'uses options' => TRUE,
              'type' => 'normal',
              'help topic' => 'style-table',
          ),
      ),
  );
  return $plugins;
}

/**
 * Implements hook_views_data().
 */
function views_fields_onoff_views_data() {

    $data['views']['views_fields_onoff_form'] = array(
        'title' => t('On/Off Form'),
        'help' => t('Display fields to be switched on and off.'),
        'field' => array(
            'handler' => 'views_fields_onoff_form',
        ),
    );


  return $data;
}
