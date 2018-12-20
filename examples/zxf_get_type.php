<?php

$stdin = fopen('php://stdin', 'r');
$data = array(null, false, true, 11111111111111, 1.1, "hello world", ['key' => 'value'], new stdClass, $stdin);

foreach ($data as $value) {
    echo zxf_get_type($value) . PHP_EOL;
}
