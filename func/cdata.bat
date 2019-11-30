@echo off
cd func\info
if exist data.txt erase /F data.txt
set d=%date:~0,2%
echo %d%>> data.txt
set d=%date:~3,2%
echo %d%>> data.txt
set d=%date:~6,4%
echo %d%>> data.txt
exit
