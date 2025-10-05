# PowerShell script để compile và chạy chương trình quản lý sinh viên

Write-Host "============================================" -ForegroundColor Green
Write-Host "   COMPILE VA CHAY CHUONG TRINH QUAN LY SINH VIEN" -ForegroundColor Green  
Write-Host "============================================" -ForegroundColor Green
Write-Host ""

Write-Host "Dang compile chuong trinh..." -ForegroundColor Yellow
g++ -std=c++11 -Wall -g -o ung_dung_sinhvien.exe test_ung_dung.cpp ung_dung_sinhvien.cpp

if ($LASTEXITCODE -eq 0) {
    Write-Host ""
    Write-Host "✓ Compile thanh cong!" -ForegroundColor Green
    Write-Host ""
    Write-Host "Dang chay chuong trinh..." -ForegroundColor Yellow
    Write-Host "============================================" -ForegroundColor Green
    Write-Host ""
    
    # Chạy chương trình
    .\ung_dung_sinhvien.exe
    
    Write-Host ""
    Write-Host "Chuong trinh da ket thuc." -ForegroundColor Green
} else {
    Write-Host ""
    Write-Host "✗ Co loi khi compile! Vui long kiem tra lai code." -ForegroundColor Red
    Write-Host ""
}

Write-Host ""
Write-Host "Nhan Enter de dong cua so..." -ForegroundColor Cyan
Read-Host
