# 🔧 HƯỚNG DẪN SỬA LỖI CHẠY CHƯƠNG TRÌNH

## ✅ **CHƯƠNG TRÌNH ĐÃ HOẠT ĐỘNG!**

Chương trình đã được compile và chạy thành công. Dưới đây là các cách chạy chương trình:

## 🚀 **CÁCH CHẠY CHƯƠNG TRÌNH**

### **Cách 1: Sử dụng Batch File (Đơn giản nhất)**
1. **Double-click** vào file `compile_and_run.bat`
2. Chương trình sẽ tự động compile và chạy

### **Cách 2: Sử dụng PowerShell Script**
1. **Right-click** vào file `run_program.ps1`
2. Chọn **"Run with PowerShell"**
3. Hoặc mở PowerShell và chạy: `.\run_program.ps1`

### **Cách 3: Sử dụng Command Line**
```powershell
# Mở PowerShell trong thư mục hiện tại
cd "C:\hoccplus\.vscode\bai14\slit\slist (1)"

# Compile
g++ -std=c++11 -Wall -g -o ung_dung_sinhvien.exe test_ung_dung.cpp ung_dung_sinhvien.cpp

# Chạy
.\ung_dung_sinhvien.exe
```

### **Cách 4: Sử dụng F5 trong VS Code**
1. Mở file `test_ung_dung.cpp`
2. Nhấn **F5**
3. Chọn **"Run Ung Dung Sinh Vien"**

## 🔍 **KIỂM TRA LỖI**

### **Nếu F5 không chạy được:**
1. **Kiểm tra C/C++ Extension** đã được cài đặt chưa
2. **Kiểm tra đường dẫn g++** có trong PATH không
3. **Thử cách khác** (batch file hoặc command line)

### **Nếu compile lỗi:**
```bash
# Kiểm tra g++ có hoạt động không
g++ --version

# Nếu không có, cần cài đặt MinGW hoặc MSYS2
```

### **Nếu chạy lỗi:**
- Đảm bảo file `.exe` đã được tạo
- Kiểm tra quyền thực thi
- Thử chạy từ Command Prompt thay vì PowerShell

## 📋 **HƯỚNG DẪN SỬ DỤNG CHƯƠNG TRÌNH**

### **Lần đầu chạy:**
1. Chọn **"9. Tao du lieu mau"** để tạo 5 sinh viên mẫu
2. Chọn **"5. Hien thi danh sach sinh vien"** để xem danh sách

### **Các chức năng chính:**
- **1-2:** Thêm sinh viên vào đầu/cuối danh sách
- **3:** Xóa sinh viên tại vị trí i
- **4:** Thay thế sinh viên tại vị trí i
- **5:** Hiển thị danh sách
- **6:** Tìm kiếm theo mã
- **9:** Tạo dữ liệu mẫu
- **0:** Thoát

### **Ví dụ sử dụng:**
```
=== HE THONG QUAN LY SINH VIEN ===
1. Them sinh vien vao cuoi danh sach
2. Them sinh vien vao dau danh sach
3. Xoa sinh vien tai vi tri i
4. Thay the sinh vien tai vi tri i
5. Hien thi danh sach sinh vien
...
So luong sinh vien hien tai: 0
============================================================
Nhap lua chon cua ban: 9
```

## 🛠️ **SỬA LỖI VS CODE**

### **Nếu F5 không hoạt động:**

1. **Kiểm tra file launch.json:**
   - Đảm bảo có cấu hình "Run Ung Dung Sinh Vien"
   - Kiểm tra đường dẫn program đúng

2. **Kiểm tra file tasks.json:**
   - Đảm bảo có task "build ung dung sinh vien"
   - Kiểm tra đường dẫn g++ đúng

3. **Thử reset VS Code:**
   - Đóng VS Code
   - Mở lại và thử F5

### **Nếu vẫn lỗi:**
- Sử dụng **batch file** (cách đơn giản nhất)
- Hoặc chạy **command line** trực tiếp

## 📁 **FILE QUAN TRỌNG**

```
slist (1)/
├── ung_dung_sinhvien.h      # Header file
├── ung_dung_sinhvien.cpp    # Implementation
├── test_ung_dung.cpp        # File main
├── compile_and_run.bat      # Script tự động
├── run_program.ps1          # PowerShell script
└── ung_dung_sinhvien.exe    # File executable
```

## 🎯 **KẾT LUẬN**

Chương trình đã hoạt động hoàn hảo! Nếu F5 không chạy được, hãy sử dụng **batch file** hoặc **command line**. Đây là cách đơn giản và đáng tin cậy nhất.

**Chúc bạn sử dụng thành công! 🎉**

