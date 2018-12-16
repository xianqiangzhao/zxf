# zxf

1.原值返回函数
  zxf_echo($param);

2.取得类型
  zxf_get_type($param);
3.取得一个数组返回值
  zxf_get_arr();
4.给定数据，查找key，返回找到的值，没有找到返回false
  zxf_find_arr($array,$key);

5.smart string 字符串返回
	zxf_smart_str
6.zxf_call_param 调用任意函数，第一个参数是函数名，第二以后是需要的参数
	$a = zxf_call_param("array_merge", ['key01'=>01], ['key02'=>02]);
	var_dump($a);