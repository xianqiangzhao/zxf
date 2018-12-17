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

ZEND_BEGIN_MODULE_GLOBALS(zxf)
	zend_long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(zxf)

#if !defined(__GNUC__) || __GNUC__ < 3
#define __builtin_expect(x, expected_value) (x)
#endif
#ifndef likely
#define likely(x)        __builtin_expect(!!(x), 1)
#endif
#ifndef unlikely
#define unlikely(x)      __builtin_expect(!!(x), 0)
#endif

enum Bool_type
{
    ZXF_TRUE = 1,
    ZXF_FALSE = 0,
};

static inline int zxf_call_user_function_ex(HashTable *function_table, zval* object_p, zval *function_name, zval *retval_ptr_ptr, uint32_t param_count, zval *params, int no_separation, HashTable* ymbol_table)
{
    return call_user_function_ex(function_table, object_p, function_name, retval_ptr_ptr, param_count, param_count ? params : NULL, no_separation, ymbol_table);
}

static inline int zxf_call_user_function_fast_ex(zval *function_name, zend_fcall_info_cache *fci_cache, zval *retval, uint32_t param_count, zval *params)
{
    zend_fcall_info fci;
    ZEND_ASSERT(retval);
    fci.size = sizeof(fci);
#if PHP_MAJOR_VERSION == 7 && PHP_MINOR_VERSION == 0
    fci.function_table = EG(function_table);
    fci.symbol_table = NULL;
#endif
    fci.object = NULL;
    if (!fci_cache || !fci_cache->function_handler)
    {
        ZVAL_COPY_VALUE(&fci.function_name, function_name);
    }
    else
    {
        ZVAL_UNDEF(&fci.function_name);
    }
    fci.retval = retval;
    fci.param_count = param_count;
    fci.params = params;
    fci.no_separation = 0;

    return zend_call_function(&fci, fci_cache);
}

static inline int zxf_zend_is_callable(zval *cb, int a, char **name)
{
    zend_string *key = NULL;
    int ret = zend_is_callable(cb, a, &key);
    char *tmp = estrndup(key->val, key->len);
    zend_string_release(key);
    *name = tmp;
    return ret;
}

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
