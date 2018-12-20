--TEST--
zxf_get_type() function test
--FILE--
<?php
    $stdin = fopen('php://stdin', 'r');
    $data = array(null, false, true, 11111111111111, 1.1, "hello world", ['key' => 'value'], new stdClass, $stdin);

    foreach ($data as $value) {
        echo zxf_get_type($value) . PHP_EOL;
    }
?>
--EXPECT--
IS_NULL
IS_FALSE
IS_TRUE
IS_LONG
IS_DOUBLE
IS_STRING
IS_ARRAY
IS_OBJECT
IS_RESOURCE