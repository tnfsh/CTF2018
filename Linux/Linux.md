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

解題步驟1:列出當前系統正在執行的程序

>ps aux
>更多ps指令(pstree):http://www.linfo.org/ps.html

解題步驟2:

>/bin/flag
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(6).png)

解答:

>BreakALLCTF{YUA7D5D0k4elbQ1XqH14}


## LinuxCTF 7

解題步驟1:列出當前系統正在執行的網路服務

>netstat -ano

解題步驟2:發現localhost:80
==>取得localhost網頁內容(使用curl工具)

>curl http://127.0.0.1/
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(7(1)).png)
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(7(2)).png)

解答:
    
>BreakALLCTF{Ef94iSQPRI66Ws4ECqV9}



## LinuxCTF 8

解題步驟1:進入/tmp目錄

>cd tmo/

解題步驟2:創建自己的目錄(如學號:610123)

>mkdir 610123/

解題步驟3:進入自己的目錄

cd /tmp/610123/

解題步驟4:下載ForYou.tar.gz壓縮檔

>wget http://120.114.62.39/ForYou.tar.gz

解題步驟5:解壓縮檔案

>tar zxvf ForYou.tar.gz

解題步驟6:查看ForYou檔案格式

>file ForYou

解題步驟7:發現為ASCII檔==>打開使用cat

>cat ForYou
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(8).png)

解答:

>BreakALLCTF{U6TLCzQsk73HwcW7rqAW}


## LinuxCTF 9

解題步驟1:進入tmp目錄下自己創建的學號目錄

>cd tmp/610123/

解題步驟2:下載TobeExe檔案

>wget http://120.114.62.39/TobeExe

解題步驟3:查看TobeExe檔案格式

>file TobeExe

解題步驟4:發現為ELF 32位元執行檔
==>賦予TobeExe檔案執行權限

>chmod +x TobeExe

解題步驟5:執行TobeExe檔案

>./TobeExe
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(9).png)

解答:

>BreakALLCTF{UvB3IUqxCCiTVxeOuWrL}


## LinuxCTF 10

解題步驟1:進入tmp目錄下自己創建的學號目錄

>cd tmp/610123/

解題步驟2:下載reverse檔案

>wget http://120.114.62.39/reverse

解題步驟3:查看reverse檔案格式

>file reverse

解題步驟4:發現為ELF 64位元執行檔
==>賦予reverse檔案執行權限

>chomd +x reverse

解題步驟5:執行reverse檔案

>./reverse

解題步驟6:Do you know strings tool?
==>使用strings工具

>strings reverse
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(10(1)).png)
>![image](https://github.com/saho-yu/CTF2018/blob/master/Linux/pictures/linuxctf(10(2)).png)

解答:
>BreakALLCTF{VLJekKONoWld7ari6HHJ}
