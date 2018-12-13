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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_zxf.h"


ZEND_DECLARE_MODULE_GLOBALS(zxf)


/* True global resources - no need for thread safety here */
static int le_zxf;

/* {{{ PHP_INI
 */
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("zxf.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_zxf_globals, zxf_globals)
    STD_PHP_INI_ENTRY("zxf.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_zxf_globals, zxf_globals)
PHP_INI_END()
 
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_zxf_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_zxf_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "zxf", arg);

	RETURN_STR(strg);
}
/* }}} */

/* {{{zxf_echo
*/
PHP_FUNCTION(zxf_echo)
{
	char *arg = NULL;
	size_t arg_len, len;
	zval *z;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "z", &z) == FAILURE) {
		return;
	}
 	if (z == NULL)
    {
        RETURN_FALSE;
    }

 	RETURN_ZVAL(z, 0, NULL);
}


/* }}} */

/* {{{zxf_get_type
*/
PHP_FUNCTION(zxf_get_type)
{
	char *arg = NULL;
	size_t arg_len, len;
	zval *z;
	zend_string *ret;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "z", &z) == FAILURE) {
		return;
	}
 	switch(Z_TYPE_P(z)) {
 		case IS_UNDEF:
	 		ret = zend_string_init("IS_UNDEF", strlen("IS_UNDEF"), 0);
	 		break;
	 	case IS_NULL:
	 		ret = zend_string_init("IS_NULL", strlen("IS_NULL"), 0);
	 		break;
	 	case IS_FALSE:
	 		ret = zend_string_init("IS_FALSE", strlen("IS_FALSE"), 0);
	 		break;
	 	case IS_TRUE:
	 		ret = zend_string_init("IS_TRUE", strlen("IS_TRUE"), 0);
	 		break;
	 	case IS_LONG:
	 		ret = zend_string_init("IS_LONG", strlen("IS_LONG"), 0);
	 		break;
	 	case IS_DOUBLE:
	 		ret = zend_string_init("IS_DOUBLE", strlen("IS_DOUBLE"), 0);
	 		break;
	 	case IS_STRING:
	 		ret = zend_string_init("IS_STRING", strlen("IS_STRING"), 0);
	 		break;
	 	case IS_ARRAY:
	 		ret = zend_string_init("IS_ARRAY", strlen("IS_ARRAY"), 0);
	 		break;
	 	case IS_OBJECT:
	 		ret = zend_string_init("IS_OBJECT", strlen("IS_OBJECT"), 0);
	 		break;
	 	case IS_RESOURCE:
	 		ret = zend_string_init("IS_RESOURCE", strlen("IS_RESOURCE"), 0);
	 		break;
	 	case IS_REFERENCE:
	 		ret = zend_string_init("IS_REFERENCE", strlen("IS_REFERENCE"), 0);
	 		break;
	 	default:
	 		ret = zend_string_init("UN_DEFINE", strlen("UN_DEFINE"), 0);
	 		break;
 	}
  	RETURN_STR(ret);
}
/* }}} */


/* {{{zxf_get_arr
*/
PHP_FUNCTION(zxf_get_arr)
{
  	zval z;
    array_init(&z);
 	add_assoc_string(&z, "key", "value01");
 	add_next_index_string(&z, "value02");
 	add_next_index_string(&z, "value03");
 	add_next_index_string(&z, "value04");
 	add_next_index_string(&z, "value05");

   	RETURN_ARR(Z_ARR(z));
}
/* }}} */

/* {{{zxf_find_arr
*/
PHP_FUNCTION(zxf_find_arr)
{
  	zval *z;
  	char *s = NULL;
  	size_t len;
  	if (zend_parse_parameters(ZEND_NUM_ARGS(), "as", &z, &s, &len) == FAILURE) {
		return;
	}
	if (!s) {
		RETURN_FALSE;
	}
 	zval *find = zend_hash_str_find(Z_ARR_P(z), s, len);
 	if (find) {
 	  RETURN_ZVAL(find, 0, NULL);
 	} else {
 	 RETURN_FALSE;
 	}
   	
}
/* }}} */

/* {{{zxf_test
*/
PHP_FUNCTION(zxf_test)
{
  	zval *z;
	if (zend_parse_parameters(ZEND_NUM_ARGS(), "a", &z) == FAILURE) {
		return;
	}
 	Z_ADDREF_P(z);
 	RETURN_ARR(Z_ARR_P(z));
}

/* {{{zxf_smart_str
*/
PHP_FUNCTION(zxf_smart_str)
{
	smart_str buf = {0};
	zend_string *ret, *s;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(s)
	ZEND_PARSE_PARAMETERS_END();
	smart_str_appendl(&buf, ZSTR_VAL(s), ZSTR_LEN(s));
	smart_str_appendl(&buf, "zxq", 3);
	ret = zend_string_init(buf.s->val,buf.s->len, 0);
	smart_str_free(&buf);
 	RETURN_STR(ret);
}

/* {{{zxf_php_json_encode
*/
PHP_FUNCTION(zxf_php_json_encode)
{
	zval *parameter;
 	smart_str buf = {0};
	zend_long options = 0;
 	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(parameter)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(options)
 	ZEND_PARSE_PARAMETERS_END();

	php_json_encode(&buf, parameter, options);
	smart_str_0(&buf);
	if (buf.s) {
		RETURN_NEW_STR(buf.s);
	}
	RETURN_EMPTY_STRING();

}
/* {{{zxf_php_json_decode
*/
PHP_FUNCTION(zxf_php_json_decode)
{
	char *str;
	size_t str_len;
	zend_bool assoc = 0;  
	zend_bool assoc_null = 1;
	zend_long depth = PHP_JSON_PARSER_DEFAULT_DEPTH;
	zend_long options = 0;

	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STRING(str, str_len)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL_EX(assoc, assoc_null, 1, 0)
		Z_PARAM_LONG(depth)
		Z_PARAM_LONG(options)
	ZEND_PARSE_PARAMETERS_END();
	if (!str_len) {
		JSON_G(error_code) = PHP_JSON_ERROR_SYNTAX;
		RETURN_NULL();
	}

	if (depth <= 0) {
		php_error_docref(NULL, E_WARNING, "Depth must be greater than zero");
		RETURN_NULL();
	}

	if (depth > INT_MAX) {
		php_error_docref(NULL, E_WARNING, "Depth must be lower than %d", INT_MAX);
		RETURN_NULL();
	}

	/* For BC reasons, the bool $assoc overrides the long $options bit for PHP_JSON_OBJECT_AS_ARRAY */
	if (!assoc_null) {
		if (assoc) {
			options |=  PHP_JSON_OBJECT_AS_ARRAY;
		} else {
			options &= ~PHP_JSON_OBJECT_AS_ARRAY;
		}
	}
 	php_json_decode(return_value, str, str_len, options, depth);
 
}



/* {{{ php_zxf_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_zxf_init_globals(zend_zxf_globals *zxf_globals)
{
	zxf_globals->global_value = 0;
	zxf_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(zxf)
{
	
	REGISTER_INI_ENTRIES();
	REGISTER_STRINGL_CONSTANT("ZXF_VERSION", PHP_ZXF_VERSION, sizeof(PHP_ZXF_VERSION)-1, CONST_CS|CONST_PERSISTENT);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(zxf)
{
 	UNREGISTER_INI_ENTRIES();
 	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(zxf)
{
#if defined(COMPILE_DL_ZXF) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(zxf)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(zxf)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "zxf support", "enabled");
	php_info_print_table_row(2, "Version", PHP_ZXF_VERSION);
	php_info_print_table_end();	 
	DISPLAY_INI_ENTRIES();
	 
}
/* }}} */

/* {{{ zxf_functions[]
 *
 * Every user visible function must have an entry in zxf_functions[].
 */
const zend_function_entry zxf_functions[] = {
	PHP_FE(confirm_zxf_compiled,	NULL)
	PHP_FE(zxf_echo,	NULL)
	PHP_FE(zxf_get_type, NULL)
	PHP_FE(zxf_get_arr, NULL)
	PHP_FE(zxf_test, NULL)
	PHP_FE(zxf_smart_str, NULL)
	PHP_FE(zxf_php_json_encode, NULL)
    PHP_FE(zxf_php_json_decode, NULL)
    PHP_FE(zxf_find_arr, NULL)
	PHP_FE_END	/* Must be the last line in zxf_functions[] */
};
/* }}} */

/* {{{ zxf_module_entry
 */
zend_module_entry zxf_module_entry = {
	STANDARD_MODULE_HEADER,
	"zxf",
	zxf_functions,
	PHP_MINIT(zxf),
	PHP_MSHUTDOWN(zxf),
	PHP_RINIT(zxf),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(zxf),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(zxf),
	PHP_ZXF_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_ZXF
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(zxf)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
