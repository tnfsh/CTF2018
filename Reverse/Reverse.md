# Reverse

## Reverse

解題方法1:下載後使用記事本查看

>![image](https://github.com/saho-yu/CTF2018/blob/master/Reverse/pictures/reverse(1).png)

解題方法2:
        
        解題步驟1:查看檔案格式
        
>file reverese
        
        解題步驟2:reverse為32位員執行檔，使用strings工具查看內容

>strings reverse<br>
>![image](https://github.com/saho-yu/CTF2018/blob/master/Reverse/pictures/reverse(2).png)
>![image](https://github.com/saho-yu/CTF2018/blob/master/Reverse/pictures/reverse(3).png)

解答:

>BreakALLCTF{4U49uY7OJCrJL0vtbXjd}


## alexctf-2017: RE1: Gifted

解題方法1:下載後使用記事本查看

>![image](https://github.com/saho-yu/CTF2018/blob/master/Reverse/pictures/alexctf%202017%20RE1%20Gifted(1).png)

解題方法2:
        
        解題步驟1:查看檔案格式
        
>file gifted
        
        解題步驟2:reverse為32位元執行檔，使用strings工具查看內容

>strings gifted<br>
>![image](https://github.com/saho-yu/CTF2018/blob/master/Reverse/pictures/alexctf%202017%20RE1Gifted(2).png)

解答:

>AlexCTF{Y0u_h4v3_45t0n15h1ng_futur3_1n_r3v3r5ing}


## HITCON CTF 2016 : welcome

解題方法1:直解倒著拼回來

>hitcon{Welcome to HITCON CTF}

解題方法2:

>https://github.com/saho-yu/CTF2018/blob/master/Reverse/welcome.cpp
>![image](https://github.com/saho-yu/CTF2018/blob/master/Reverse/pictures/welcome(1).png)
>![image](https://github.com/saho-yu/CTF2018/blob/master/Reverse/pictures/welcome(2).png)

解答:

>hitcon{Welcome to HITCON CTF}


## Java! Java!

解題方法1:暴力破解
        
        解題步驟1:下載後先解壓縮
        
>unzip tmpBPWe7T.zip
        
        解題步驟2:檢視檔案格式
        
>file Authenticator.class
        
        解題步驟3:發現為java執行檔==>使用strings工具
        
>strings Authenticator.class
        
        解題步驟4:發現password==>執行Authenticator
        
>java Authenticator
        
        解題步驟5:輸入passowrd後得到解答

>![image](https://github.com/saho-yu/CTF2018/blob/master/Reverse/pictures/java(1).png)
>![image](https://github.com/saho-yu/CTF2018/blob/master/Reverse/pictures/java(2).png)

解題方法2:使用jad反編譯工具

        解題步驟1:下載後先解壓縮
        
>unzip tmpBPWe7T.zip
        
        解題步驟2:檢視檔案格式
        
>file Authenticator.class
        
        解題步驟3:發現為java執行檔==>使用jad反編譯工具
        
>jad Authenticator.class
        
        解題步驟4:檢視Authenticator.jad檔案格式
        
>file Authenticator.jad
        
        解題步驟5:發現為C++且為ASCII格式==>開啟檢視檔案
        
>nano/gedit/vim Authenticator.jad
>cat Authenticator.jad
        
        解題步驟6:發現password(ThisIsth3mag1calString4458)和解答<br>
        ==>執行Authenticator並輸入passwotd或直接輸入解答
        
>java Authenticator
        
        解題步驟7:輸入password並得到解答
        
>![image](https://github.com/saho-yu/CTF2018/blob/master/Reverse/pictures/java(3).png)
>![image](https://github.com/saho-yu/CTF2018/blob/master/Reverse/pictures/java(4).png)
>![image](https://github.com/saho-yu/CTF2018/blob/master/Reverse/pictures/java(5).png)

解答:
        
>AoJkVhLwUR
