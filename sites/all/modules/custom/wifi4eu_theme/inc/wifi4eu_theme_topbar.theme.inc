<?php

/**
 * @file
 * WiFi4Eu user menu.
 */

/**
 * Returns HTML for the element.
 *
 * @return string
 *   The markup itself.
 */
function _wifi4eu_theme_user_menu() {
  // Check if the ecas module is installed.
  if (module_exists('ecas')) {
    $login_url = 'ecas';
    $logout_url = 'ecaslogout';
  }
  else {
    $login_url = 'user';
    $logout_url = 'user/logout';
  }

  if (user_is_logged_in()) {
    $items = [];
    $items[] = [
      'data' => t('Logged in as @username', ['@username' => format_username($GLOBALS['user'])]),
      'class' => ['site-user-menu__option'],
    ];
    $items[] = [
      'data' => l(t('Log out'), $logout_url),
      'class' => ['site-user-menu__option'],
    ];

    $variables = [
      'items' => $items,
      'attributes' => [
        'class' => ['site-user-menu__list'],
      ],
    ];
    return theme('item_list', $variables);
  }
  else {
    return l(t('Log in'), $login_url, [
      'attributes' => [
        'class' => ['site-user-menu__list'],
      ],
    ]);
  }
}
