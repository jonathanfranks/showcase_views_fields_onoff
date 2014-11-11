<?php

class NodeFeaturesBuilder extends FeaturesBuilderBase {

  protected $type;

  public function __construct($name) {
    parent::__construct($name);
    $this->type = substr($this->name, 5);
  }

  public static function listFeatures() {
    $features = array();
    foreach (features_builder_get_exportables('node') as $name => $label) {
      $features["node_$name"] = $label;
    }
    return $features;
  }

  /**
   * {@inheritdoc}
   */
  public function package() {
    return 'Content';
  }

  protected function setComponents() {
    $this->setNamedComponents('node', array($this->type));
    $this->setRegexComponents('field_instance', '/^node-' . $this->type . '-/');
    $this->setNamedComponents('variable', array('field_bundle_settings_node__' . $this->type));
    $this->setNamedComponents('variable', array('menu_options_' . $this->type));
    $this->setNamedComponents('variable', array('menu_parent_' . $this->type));
    $this->setNamedComponents('variable', array('node_options_' . $this->type));
    $this->setNamedComponents('variable', array('node_preview_' . $this->type));
    $this->setNamedComponents('variable', array('node_submitted_' . $this->type));

    $dependencies = array();
    $dependencies[] = $this->prefix . '_fields';

    // Add dependencies to all modules exposing a field widget or formatter on
    // the bundle.
    $info = field_info_instances('node');
    $bundle = substr($this->name, 5);
    foreach ($info[$bundle] as $bundleInfo) {
      $dependencies[] = $bundleInfo['widget']['module'];
      foreach ($bundleInfo['display'] as $display) {
        $dependencies[] = !empty($display['module']) ? $display['module'] : NULL;
      }
    }

    // Add field groups.
    $this->setRegexComponents('field_group', "/^group_[a-z0-9_]*\|node\|$bundle\|/");
    if (!empty($this->components['field_group'])) {
      $dependencies[] = 'field_group';
    }
    $dependencies = array_filter(array_unique($dependencies));
    $this->setNamedComponents('dependencies', $dependencies);
  }

}
