<?php

class SiteFeaturesBuilder extends FeaturesBuilderBase {

  protected $variables = array(
    'admin_theme',
    'block_cache',
    'cache',
    'cache_lifetime',
    'date_default_timezone',
    'node_admin_theme',
    'page_cache_maximum_age',
    'page_compression',
    'preprocess_css',
    'preprocess_js',
    'site_default_country',
    'site_403',
    'site_404',
    'site_frontpage',
    'site_mail',
    'site_name',
    'site_slogan',
    'theme_default',
    'theme_settings',
    'update_notify_emails',
  );

  public static function listFeatures() {
    return array('site' => t('Site'));
  }

  /**
   * {@inheritdoc}
   */
  public function package() {
    return 'Configuration';
  }

  protected function setComponents() {
    $this->setNamedComponents('variable', $this->variables);
    $this->setRegexComponents('variable', '/^theme_[a-z0-9_]*_settings$/');

    if (features_builder_get_exportables('environment_indicator_environment')) {
      $this->setAllComponents('environment_indicator_environment');
    }
  }

}
