@echo off
chcp 65001 > nul
echo ============================================
echo    COMPILE VA CHAY CHUONG TRINH QUAN LY SINH VIEN
echo ============================================
echo.

echo Dang compile chuong trinh...
g++ -std=c++11 -Wall -g -o ung_dung_sinhvien.exe test_ung_dung.cpp ung_dung_sinhvien.cpp

if %errorlevel% == 0 (
    echo.
    echo ✓ Compile thanh cong!
    echo.
    echo Dang chay chuong trinh...
    echo ============================================
    echo.
    ung_dung_sinhvien.exe
    echo.
    echo Chuong trinh da ket thuc.
) else (
    echo.
    echo ✗ Co loi khi compile! Vui long kiem tra lai code.
    echo.
)

echo.
echo Nhan Enter de dong cua so...
pause > nul
