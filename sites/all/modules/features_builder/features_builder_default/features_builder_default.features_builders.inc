<?php

/**
 * @file
 * Features Builder definitions.
 */

/**
 * Implements hook_features_builders_info().
 */
function features_builder_default_features_builders_info() {
  $builders = array(
    'features_builder_context' => array(
      'label' => t('Context'),
      'class' => 'ContextFeaturesBuilder',
    ),
    'features_builder_field' => array(
      'label' => t('Fields'),
      'class' => 'FieldFeaturesBuilder',
    ),
    'features_builder_media' => array(
      'label' => t('Media'),
      'class' => 'MediaFeaturesBuilder',
    ),
    'features_builder_menu' => array(
      'label' => t('Menu'),
      'class' => 'MenuFeaturesBuilder',
    ),
    'features_builder_node' => array(
      'label' => t('Nodes'),
      'class' => 'NodeFeaturesBuilder',
    ),
    'features_builder_panels' => array(
      'label' => t('Panels'),
      'class' => 'PanelsFeaturesBuilder',
    ),
    'features_builder_seo' => array(
      'label' => t('SEO'),
      'class' => 'SeoFeaturesBuilder',
    ),
    'features_builder_site' => array(
      'label' => t('Site'),
      'class' => 'SiteFeaturesBuilder',
    ),
    'features_builder_taxonomy' => array(
      'label' => t('Taxonomy'),
      'class' => 'TaxonomyFeaturesBuilder',
    ),
    'features_builder_user' => array(
      'label' => t('Users'),
      'class' => 'UserFeaturesBuilder',
    ),
    'features_builder_views' => array(
      'label' => t('Views'),
      'class' => 'ViewsFeaturesBuilder',
    ),
  );
  return $builders;
}
