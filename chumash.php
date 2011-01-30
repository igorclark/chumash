<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('chumash')) {
	dl('chumash.' . PHP_SHLIB_SUFFIX);
}
$module = 'chumash';
$functions = get_extension_funcs($module);
echo "Functions available in the test extension:$br\n";
foreach($functions as $func) {
    echo $func."$br\n";
}
echo "$br\n";
$str="piiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiisssssssssssssssspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissspiiiiiiiiiiiiiiiiissssssssssssssss";

echo chumash_djb2($str) . "\n";
echo chumash_djb2_with_range($str, 30) . "\n";
?>
