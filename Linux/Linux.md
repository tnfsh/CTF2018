# Linux

## Linux CTF 1

解題步驟:

>ssh -p2200 lab@120.114.62.89<br>
>ls (查看目前資料夾內的檔案)<br>
>cat flag (打開flag)<br>
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(1).png)

解答:

>BreakALLCTF{Sobkjgd14VuIFBUtgVts}


## Linux CTF 2

解題步驟1:查看目前資料夾所有詳細內容

>ls -a

解題步驟2:打開隱藏檔案

>cat .hidden
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(2).png)

解答:

>BreakALLCTF{WucLSg4cxPNYuXFF5XxJ}


## Linux CTF 3

解題步驟1:查看目前資料夾內的檔案

>ls

解題步驟2:打開hex.txt

>ls hex.txt

解題步驟3:使用xxd工具

>xxd -r -p hex.txt
>echo | xxd -r -p
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(3).png)
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(3(2)).png)

解答:

>BreakALLCTF{GIUWO1rpMhJCJpACvVwr}


## LinuxCTF 4

解題步驟1:查看目前資料夾內的檔案

>ls

解題步驟2:打開base64.txt

>ls base64.txt

解題步驟3:base64解碼

>base64 --decode base64.txt
>echo | base64 --decode
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(4(1)).png)
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(4(2)).png)

解答:

>BreakALLCTF{XvXeVX5Ae9FwnYmDV2jU}


## LinuxCTF 5

解題步驟1:退到根目錄

>cd ..

解題步驟2:使用find工具

>find -name secret

解題步驟3:大部分為permission denied 但其中一個不是，打開./opt/secret

>cat ./opt/secret
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(5(1)).png)
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(5(2)).png)

解答:

>BreakALLCTF{TPLGKbWxmutGtecSSpo1}



## LinuxCTF 6

>BreakALLCTF{YUA7D5D0k4elbQ1XqH14}

## LinuxCTF 7

解答:
    
>BreakALLCTF{Ef94iSQPRI66Ws4ECqV9}



## LinuxCTF 8

>BreakALLCTF{U6TLCzQsk73HwcW7rqAW}


## LinuxCTF 9

>BreakALLCTF{UvB3IUqxCCiTVxeOuWrL}


## LinuxCTF 10

>BreakALLCTF{VLJekKONoWld7ari6HHJ}
