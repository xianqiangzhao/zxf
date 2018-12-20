# zxf php extension

## Function

### zxf_echo

(PHP7)

zxf_echo — Original value return function

Description

```php
mixed zxf_echo(mixed $var)
```

Returns the value of the PHP variable `var`.

### zxf_get_type

(PHP7)

zxf_get_type — Get the type of a variable

Description

```php
string zxf_get_type(mixed $var)
```

Returns the type of the PHP variable `var`. 

### zxf_get_arr()

(PHP7)

zxf_get_arr — Get an array return value

Description

```php
mixed zxf_get_arr(array $arr);
```

### zxf_find_arr

(PHP7)

zxf_find_arr — Given the data, find the key.

Description

```php
zxf_find_arr(array $arr, key);
```

return the found value, not found return false.

### zxf_smart_str

(PHP7)

zxf_smart_str —Splice string 'zxq' after the given string.

Description

```php
string zxf_smart_str(string $str);
```

### zxf_call_param

(PHP7)

zxf_call_param — Call any function, the first parameter is the function name, the second is the required parameter.

Description

```php
mixed zxf_call_param(string functinonName, ...params);
```

### zxf_call_param_yaf

(PHP7)

zxf_call_param_yaf — Call any function, the first parameter is the function name, the second is the required parameter.

Description

```php
mixed zxf_call_param_yaf(string functinonName, ...params);
```

### zxf_server

Open service class (in operation)