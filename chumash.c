/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2010 The PHP Group                                |
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

/* $Id: header 297205 2010-03-30 21:09:07Z johannes $ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_chumash.h"

/* If you declare any globals in php_chumash.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(chumash)
*/

/* True global resources - no need for thread safety here */
static int le_chumash;

/* {{{ chumash_functions[]
 *
 * Every user visible function must have an entry in chumash_functions[].
 */
const zend_function_entry chumash_functions[] = {
	PHP_FE(chumash_djb2, NULL)
	PHP_FE(chumash_djb2_with_range, NULL)
	{NULL, NULL, NULL}	/* Must be the last line in chumash_functions[] */
};
/* }}} */

/* {{{ chumash_module_entry
 */
zend_module_entry chumash_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"chumash",
	chumash_functions,
	PHP_MINIT(chumash),
	PHP_MSHUTDOWN(chumash),
	PHP_RINIT(chumash),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(chumash),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(chumash),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_CHUMASH
ZEND_GET_MODULE(chumash)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("chumash.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_chumash_globals, chumash_globals)
    STD_PHP_INI_ENTRY("chumash.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_chumash_globals, chumash_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_chumash_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_chumash_init_globals(zend_chumash_globals *chumash_globals)
{
	chumash_globals->global_value = 0;
	chumash_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(chumash)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(chumash)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(chumash)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(chumash)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(chumash)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "chumash support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */



/* {{{ proto unsigned long do_djb2_hash(char *str)
*   Compute djb2 hash of string */
unsigned long do_djb2_hash(unsigned char *str) {
	unsigned long hash = 5381;
	int c;
	while(c = *str++) {
		hash = ((hash << 5) + hash) + c;
	}
	return hash;
}
/* }}} */

/* {{{ proto unsigned long do_djb2_hash(char *str)
*   Compute djb2 hash of string, modulo range */
unsigned long do_djb2_hash_with_range(unsigned char *str, long range) {
	return do_djb2_hash(str) % range;
}
/* }}} */

/* {{{ proto long chumash_djb2(char *str)
*   Compute djb2 hash of string */
PHP_FUNCTION(chumash_djb2)
{
	unsigned char *str = NULL;
	int str_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &str, &str_len) == FAILURE) {
        return;
    }

    RETURN_LONG(do_djb2_hash(str));
}
/* }}} */

/* {{{ proto long chumash_djb2_with_range(char *str, long range)
*   Compute djb2 hash of string modulo range */
PHP_FUNCTION(chumash_djb2_with_range)
{
	unsigned char *str = NULL;
	int str_len;
	long range;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sl", &str, &str_len, &range) == FAILURE) {
        return;
    }

    RETURN_LONG(do_djb2_hash_with_range(str, range));
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
