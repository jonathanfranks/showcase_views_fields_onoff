<?php
/**
 * @file
 * kd_node_types.features.inc
 */

/**
 * Implements hook_node_info().
 */
function kd_node_types_node_info() {
  $items = array(
    'fieldy_content' => array(
      'name' => t('Fieldy Content'),
      'base' => 'node_content',
      'description' => t('Just a type with a lot of fields'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
