<?php

$data = array(
    'key1' => 'value1',
    'key2' => 'value2',
    'key3' => array(
        'hello' => 'world'
    ),
);
var_dump(zxf_find_arr($data, 'key'));
echo zxf_find_arr($data, 'key1') . PHP_EOL;
print_r(zxf_find_arr($data, 'key3'));
