
<?php

ini_set('display_startup_errors', 1);
ini_set('display_errors', 1);
error_reporting(-1);
print 1;
# An HTTP GET request example
/**
$service_url = 'https://test-solutionsdirectory.intel.com';


$curl = curl_init($service_url);
curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
 curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);
$curl_response = curl_exec($curl);
if ($curl_response === false) {
    $info = curl_getinfo($curl);
    curl_close($curl);
    die('error occured during curl exec. Additioanl info: ' . var_export($info));
}
curl_close($curl);
$decoded = json_decode($curl_response);
if (isset($decoded->response->status) && $decoded->response->status == 'ERROR') {
    die('error occured: ' . $decoded->response->errormessage);
}
echo 'response ok!';
print_r($curl_response);
**/
$domain = "https://solutionsdirectory-origin-14360.intel.com";
$google  = "https://www.google.co.in/";
$test = "https://test-solutionsdirectory.intel.com/v1/mail.json?uid=testsave3005@mailinator.com&pwd=intel1234";
$service_url = "https://solutionsdirectory.intel.com/v1/mail.json?uid=testsave3005%40mailinator.com&pwd=intel1234";
$service_url = "https://45.33.29.80/v1/mail.json?uid=testsave3005%40mailinator.com&pwd=intel1234";
$service_url = "https://solutionsdirectory-origin-14360.intel.com/v1/mail.json?uid=testsave3005%40mailinator.com&pwd=intel1234";
$curl = curl_init();

$w1 = "http://104.237.137.90/v1/mail.json?uid=testsave3005%40mailinator.com&pwd=intel1234";

curl_setopt_array($curl, array(
  CURLOPT_URL => $domain,
  CURLOPT_RETURNTRANSFER => true,
  CURLOPT_ENCODING => "",
  CURLOPT_MAXREDIRS => 10,
  CURLOPT_TIMEOUT => 30,
  CURLOPT_SSL_VERIFYPEER => false, 
  CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
  CURLOPT_CUSTOMREQUEST => "GET",
  CURLOPT_HTTPHEADER => array(
    "cache-control: no-cache",
    "postman-token: ae5161ed-668c-c100-227b-590837c7868d"
  ),
));

$response = curl_exec($curl);
$err = curl_error($curl);

curl_close($curl);

if ($err) {
  echo "cURL Error #:" . $err;
} else {
  echo $response;
}


?>
