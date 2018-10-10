<?php

/**
 * Implements hook_block_info().
 */
function wifi4eu_theme_block_info() {
  // Block to display user name and the option to login/logout.
  $blocks['wifi4eu_theme_user_menu'] = [
    'info' => t('WiFi4EU User Menu'),
  ];

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function wifi4eu_theme_block_view($delta = '') {
  $block = [];

  switch ($delta) {
    case 'wifi4eu_theme_user_menu':
      $block['content'] = _wifi4eu_theme_user_menu();
      break;
  }

  return $block;
}


/**
 * Implements hook_theme_registry_alter().
 */
// function wifi4eu_theme_theme_registry_alter(&$theme_registry) {
//   $module_path = drupal_get_path('module', 'wifi4eu_theme');
//   $template_file_objects = drupal_find_theme_templates($theme_registry, '.tpl.php', $module_path);

//   foreach ($template_file_objects as $key => $template_file_object) {
//     // If the template has not already been overridden by a theme.
//     if (!isset($theme_registry[$key]['theme path'])
//       || !preg_match('#/themes/#', $theme_registry[$key]['theme path'])
//     ) {
//       // Alter the theme path and template elements.
//       $theme_registry[$key]['theme path'] = $module_path;
//       $theme_registry[$key] = array_merge($theme_registry[$key], $template_file_object);
//       $theme_registry[$key]['type'] = 'module';
//     }
//   }
// }

/**
 * Implements hook_theme().
 */
function wifi4eu_theme_theme() {
  return [
    'wifi4eu_user_menu' => [],
  ];
}

/**
 * Implements hook_preprocess_block().
 */
function wifi4eu_theme_preprocess_block(&$variables) {
  $block = $variables['block'];

  switch ($block->delta) {
    case 'menu-nexteuropa-site-links':
      if ($block->region == 'header_top') {
        $variables['classes_array'][] = 'nexteuropa_site_switcher';

        if ($links = menu_navigation_links('menu-nexteuropa-site-links')) {
          foreach ($links as $key => $link) {
            $links[$key]['attributes']['class'][] = 'site-switcher__option';

            if (isset($links[$key]['attributes']['name']) && theme_get_setting('ec_europa_site_switcher') == $links[$key]['attributes']['name']) {
              $links[$key]['attributes']['class'][] = 'is-selected';
            }
          }

          $content = theme('links', [
            'links' => $links,
            'attributes' => [
              'class' => [
                'site-switcher__list',
              ],
            ],
          ]);

          $variables['content'] = $content;
        }
      }
      break;
  }
}

/**
 * Implements hook_context_default_contexts_alter().
 */
// function wifi4eu_theme_context_default_contexts_alter(&$contexts) {
//   $context = module_invoke('context', 'load', 'ec_europa_topbar');

//   if (!empty($context->reactions['block']['blocks']['nexteuropa_topbar-nexteuropa_user_menu'])
//     && !empty($contexts['ec_europa_topbar'])
//   ) {
//     $contexts['ec_europa_topbar']->reactions['block']['blocks']['nexteuropa_topbar-nexteuropa_user_menu'] = _nexteuropa_topbar_user_menu_info();
//   }
// }
