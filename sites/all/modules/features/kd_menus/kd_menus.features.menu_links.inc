<?php
/**
 * @file
 * kd_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function kd_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_fieldy-switcher:fieldy-switcher
  $menu_links['main-menu_fieldy-switcher:fieldy-switcher'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'fieldy-switcher',
    'router_path' => 'fieldy-switcher',
    'link_title' => 'Fieldy Switcher',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_fieldy-switcher:fieldy-switcher',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_in-grid:with-teasers
  $menu_links['main-menu_in-grid:with-teasers'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'with-teasers',
    'router_path' => 'with-teasers',
    'link_title' => 'In Grid',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_in-grid:with-teasers',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_menu-items:menu-items
  $menu_links['main-menu_menu-items:menu-items'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'menu-items',
    'router_path' => 'menu-items',
    'link_title' => 'Menu Items',
    'options' => array(
      'identifier' => 'main-menu_menu-items:menu-items',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: main-menu_new-format:with-new-format
  $menu_links['main-menu_new-format:with-new-format'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'with-new-format',
    'router_path' => 'with-new-format',
    'link_title' => 'New Format',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_new-format:with-new-format',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Fieldy Switcher');
  t('Home');
  t('In Grid');
  t('Menu Items');
  t('New Format');


  return $menu_links;
}
