<?php
/**
 * @file
 * page_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function page_content_type_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => t('A content type used to create pages on the website.'),
      'has_title' => '1',
      'title_label' => t('Page Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
