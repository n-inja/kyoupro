@echo off
chcp 65001
cd /d %~dp0
IF exist %1 (
  echo %1.exe
  g++ %1 -Wall -static -std=c++11 -o %1.exe
  %1.exe
  del %1.exe
  pause
) else (
  echo %1 ないです
)
