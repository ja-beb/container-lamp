<?php
    define('_VIEW_BASE', realpath('/site/view'));
    define('_CONFIG_BASE', realpath('/site/config'));
    define('_INClUDE_BASE', realpath('/site/include'));

    $GLOBALS['._dispatcher_request'] = $_GET;
    $GLOBALS['._dispatcher_request_path'] = $GLOBALS['._dispatcher_request']['__execution_path'] ?? 'index';
    unset($GLOBALS['._dispatcher_request']['__execution_path']);

    __database(_CONFIG_BASE);

    $_view = sprintf('%s/%s.phtml', _VIEW_BASE, $GLOBALS['._dispatcher_request_path']);

    ob_start();
    require($_view);
    $GLOBALS['._view_content'] = ob_get_clean();

    $_page_view = sprintf('%s/_page.phtml', _VIEW_BASE);
    require($_page_view);


