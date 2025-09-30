@echo off
echo Building bai1.cpp...
C:\msys64\ucrt64\bin\g++.exe -g bai1.cpp -o bai1.exe
if %errorlevel% equ 0 (
    echo Build successful!
    echo Running bai1.exe...
    bai1.exe
) else (
    echo Build failed!
)
pause
