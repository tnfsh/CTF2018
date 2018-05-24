# Web101

## Web-1:source code

解題步驟1:按下鍵盤F12/滑鼠右鍵=>檢查

>

解答:

>BreakALLCTF{3xjVYR8dMetWQbwzYsLJ}


## web-2:Robots.txt

解題步驟1:在網址後方打上/robots.txt

>

解題步驟2:按下Enter後，出現文字<br>
User-agent: *
Disallow: /images
Disallow: /secret
==>在網址後方打上/secret

>

解題步驟3:點下flag.txt

>

解題步驟4:hex to string

>echo 516e4a6c595774425445784456455a374e31463053304979546a5655624846425155563651334a36546b3939 | xxd -r -p

解題步驟5:base64 decode

>echo QnJlYWtBTExDVEZ7N1F0S0IyTjVUbHFBQUV6Q3J6Tk99 | base64 --decode

解答:

>BreakALLCTF{7QtKB2N5TlqAAEzCrzNO}

也可使用線上解碼工具:
>https://codebeautify.org/hex-string-converter<br>
>https://www.base64decode.org/<br>


## Web-3:Curl-1

解題步驟1:在'GO!'圖示上按下滑鼠右鍵檢查

>

解題步驟2:發現網頁將引導至index.php
==>使用curl工具

>curl http://120.114.62.89:2014/index.php

解答:

>
