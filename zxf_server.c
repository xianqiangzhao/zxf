/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2018 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:zhaoxianqiang                                                 |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_zxf.h"

zend_class_entry *zxf_server_ce;

/** zxf_server __construct
*/
PHP_METHOD(zxf_server, __construct) {
    size_t host_len = 0;
    char *serv_host;
    zend_long serv_port = 0;
    zend_update_property_long(zxf_server_ce,getThis(), ZEND_STRL("port"), 80);
}

/** zxf_server on
*/
PHP_METHOD(zxf_server, on) {

}

/**  zxf_server start
*/
PHP_METHOD(zxf_server, start) {

}

/** zxf_server_methods
*/
zend_function_entry zxf_server_methods[] = {
    PHP_ME(zxf_server, __construct, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(zxf_server, on, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(zxf_server, start, NULL, ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};


/**  zxf_STARTUP_FUNCTION
*/
ZXF_STARTUP_FUNCTION(server) {
    zend_class_entry ce;

    INIT_CLASS_ENTRY(ce, "zxf_server", zxf_server_methods);
    zxf_server_ce = zend_register_internal_class_ex(&ce, NULL);
    zend_declare_property_null(zxf_server_ce, ZEND_STRL("onConnect"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(zxf_server_ce, ZEND_STRL("onReceive"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(zxf_server_ce, ZEND_STRL("onClose"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(zxf_server_ce, ZEND_STRL("setting"), ZEND_ACC_PUBLIC);
    zend_declare_property_null(zxf_server_ce, ZEND_STRL("connections"), ZEND_ACC_PUBLIC);
    zend_declare_property_null(zxf_server_ce, ZEND_STRL("host"), ZEND_ACC_PUBLIC);
    zend_declare_property_long(zxf_server_ce, ZEND_STRL("port"), 0, ZEND_ACC_PUBLIC);
    zend_declare_property_long(zxf_server_ce, ZEND_STRL("type"), 0, ZEND_ACC_PUBLIC);
    zend_declare_property_long(zxf_server_ce, ZEND_STRL("master_pid"), 0, ZEND_ACC_PUBLIC);
    zend_declare_property_long(zxf_server_ce, ZEND_STRL("manager_pid"), 0, ZEND_ACC_PUBLIC);

    return SUCCESS;
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
