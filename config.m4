 

PHP_ARG_ENABLE(zxf, whether to enable zxf support,
[  --enable-zxf           Enable zxf support])

if test "$PHP_ZXF" != "no"; then
  PHP_NEW_EXTENSION(zxf, zxf.c        \
    zxf_server.c\
  , $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
