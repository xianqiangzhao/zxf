--TEST--
zxf_get_arr() function test
--FILE--
<?php
    $data = array(
        'key1' => 'value1',
        'key2' => 'value2',
    );
    print_r(zxf_get_arr($data));
?>
--EXPECT--
Array
(
    [key] => Array
        (
            [key1] => value1
            [key2] => value2
        )

    [0] => value02
    [1] => value03
    [2] => value04
    [3] => value05
    [key01] => 88888
)