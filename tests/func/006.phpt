--TEST--
zxf_call_param() function test
--FILE--
<?php
    $a = zxf_call_param("array_merge", ['key01' => 01], ['key02' => 02]);
    var_dump($a);
?>
--EXPECT--
array(2) {
  ["key01"]=>
  int(1)
  ["key02"]=>
  int(2)
}