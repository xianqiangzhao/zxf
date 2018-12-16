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
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_ZXF_H
#define PHP_ZXF_H
#include "zend_smart_str.h"
 
extern zend_module_entry zxf_module_entry;
#define phpext_zxf_ptr &zxf_module_entry

#define PHP_ZXF_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_ZXF_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_ZXF_API __attribute__ ((visibility("default")))
#else
#	define PHP_ZXF_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif
#include "ext/json/php_json.h"
#include "php_wrapper.h"

ZEND_BEGIN_MODULE_GLOBALS(zxf)
	zend_long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(zxf)


enum Bool_type
{
    ZXF_TRUE = 1,
    ZXF_FALSE = 0,
};

/**
check is callable
*/
static inline int php_zxf_is_callable(zval *callback TSRMLS_DC)
{
    if (!callback || ZVAL_IS_NULL(callback))
    {
    }
    char *func_name = NULL;
    if (!zxf_zend_is_callable(callback, 0, &func_name TSRMLS_CC))
    {
        php_error_docref(NULL, E_WARNING, "Function '%s' is not callable", func_name);
        efree(func_name);
        return ZXF_FALSE;
    }
    else
    {
        efree(func_name);
        return ZXF_TRUE;
    }
}

/* Always refer to the globals in your function as ZXF_G(variable).
   You are encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/
#define ZXF_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(zxf, v)
 
#if defined(ZTS) && defined(COMPILE_DL_ZXF)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif	/* PHP_ZXF_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
