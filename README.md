# CTF2018-王紹宇

# Steg-1: STEG(必) 20

# sCTF 2016 Q1 : banana-boy-20

解題步驟1:查看檔案格式

file /root/Desktop/img.jpg


解題步驟2:查看檔案內藏的字串

strings /root/Desktop/img.jpg

解題步驟3:安裝工具並學習使用技術

google搜尋jpg metadata linux
>* http://xahlee.info/img/metadata_in_image_files.html
>* http://libre-software.net/edit-image-metadata-on-linux/


sudo apt-get install exiftool


解題步驟4:查看檔案並讀出答案



exiftool img.jpg

