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

#ifndef EXT_ZXF_WRAPPER_H_
#define EXT_ZXF_WRAPPER_H_

#define PHP_MAX_PARAMS_NUM 10
static inline char* zxf_php_format_date(char *format, size_t format_len, time_t ts, int localtime)
{
    zend_string *time = php_format_date(format, format_len, ts, localtime);
    char *return_str = estrndup(time->val, time->len);
    zend_string_release(time);
    return return_str;
}


static inline int zxf_call_user_function_ex(HashTable *function_table, zval** object_pp, zval *function_name, zval **retval_ptr_ptr, uint32_t param_count, zval ***params, int no_separation, HashTable* ymbol_table)
{
    zval real_params[PHP_MAX_PARAMS_NUM];
    uint32_t i = 0;
    for (; i < param_count; i++)
    {
        real_params[i] = **params[i];
    }
    zval phpng_retval;
    *retval_ptr_ptr = &phpng_retval;
    zval *object_p = (object_pp == NULL) ? NULL : *object_pp;
    return call_user_function_ex(function_table, object_p, function_name, &phpng_retval, param_count, real_params, no_separation, NULL);
}


static inline int zxf_call_user_function_fast(zval *function_name, zend_fcall_info_cache *fci_cache, zval **retval_ptr_ptr, uint32_t param_count, zval **params)
{
    zval real_params[PHP_MAX_PARAMS_NUM];
    uint32_t i = 0;
    for (; i < param_count; i++)
    {
        real_params[i] = *params[i];
    }

    zval phpng_retval;
    *retval_ptr_ptr = &phpng_retval;

    zend_fcall_info fci;
    fci.size = sizeof(fci);
#if PHP_MAJOR_VERSION == 7 && PHP_MINOR_VERSION == 0
    fci.function_table = EG(function_table);
    fci.symbol_table = NULL;
#endif
    fci.object = NULL;
    ZVAL_COPY_VALUE(&fci.function_name, function_name);
    fci.retval = &phpng_retval;
    fci.param_count = param_count;
    fci.params = real_params;
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




#endif
