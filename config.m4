dnl $Id$
dnl config.m4 for extension chumash

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(chumash, for chumash support,
dnl Make sure that the comment is aligned:
dnl [  --with-chumash             Include chumash support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(chumash, whether to enable chumash support,
dnl Make sure that the comment is aligned:
[  --enable-chumash           Enable chumash support])

if test "$PHP_CHUMASH" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-chumash -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/chumash.h"  # you most likely want to change this
  dnl if test -r $PHP_CHUMASH/$SEARCH_FOR; then # path given as parameter
  dnl   CHUMASH_DIR=$PHP_CHUMASH
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for chumash files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       CHUMASH_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$CHUMASH_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the chumash distribution])
  dnl fi

  dnl # --with-chumash -> add include path
  dnl PHP_ADD_INCLUDE($CHUMASH_DIR/include)

  dnl # --with-chumash -> check for lib and symbol presence
  dnl LIBNAME=chumash # you may want to change this
  dnl LIBSYMBOL=chumash # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $CHUMASH_DIR/lib, CHUMASH_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_CHUMASHLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong chumash lib version or lib not found])
  dnl ],[
  dnl   -L$CHUMASH_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(CHUMASH_SHARED_LIBADD)

  PHP_NEW_EXTENSION(chumash, chumash.c, $ext_shared)
fi
