# HƯỚNG DẪN CHẠY CHƯƠNG TRÌNH QUẢN LÝ SINH VIÊN

## 🚀 CÁCH CHẠY CHƯƠNG TRÌNH

### **Cách 1: Sử dụng F5 trong VS Code (Khuyến nghị)**

1. **Mở file `test_ung_dung.cpp`** trong VS Code
2. **Nhấn F5** hoặc vào menu **Run → Start Debugging**
3. **Chọn "Run Ung Dung Sinh Vien"** từ dropdown
4. Chương trình sẽ tự động compile và chạy

### **Cách 2: Sử dụng batch file (Đơn giản nhất)**

1. **Double-click** vào file `compile_and_run.bat`
2. Chương trình sẽ tự động compile và chạy

### **Cách 3: Sử dụng Command Line**

```bash
# Mở Command Prompt trong thư mục hiện tại
cd "C:\hoccplus\.vscode\bai14\slit\slist (1)"

# Compile chương trình
g++ -std=c++11 -o ung_dung_sinhvien.exe test_ung_dung.cpp ung_dung_sinhvien.cpp

# Chạy chương trình
ung_dung_sinhvien.exe
```

### **Cách 4: Sử dụng Makefile (nếu có make)**

```bash
make
make run-win
```

## 📋 CÁC CHỨC NĂNG CỦA CHƯƠNG TRÌNH

### **Chức năng chính (theo yêu cầu):**
- ✅ **1.** Thêm sinh viên vào cuối danh sách
- ✅ **2.** Thêm sinh viên vào đầu danh sách  
- ✅ **3.** Xóa sinh viên tại vị trí i
- ✅ **4.** Thay thế sinh viên tại vị trí i

### **Chức năng bổ sung:**
- ✅ **5.** Hiển thị danh sách sinh viên
- ✅ **6.** Tìm kiếm sinh viên theo mã
- ✅ **7.** Đếm số lượng sinh viên
- ✅ **8.** Thêm sinh viên tại vị trí i
- ✅ **9.** Tạo dữ liệu mẫu (5 sinh viên)
- ✅ **10.** Thống kê theo giới tính
- ✅ **11.** Thống kê theo quê quán
- ✅ **12.** Xóa toàn bộ danh sách

## 🎯 HƯỚNG DẪN SỬ DỤNG

### **Lần đầu chạy:**
1. Chọn **"9. Tao du lieu mau"** để tạo 5 sinh viên mẫu
2. Chọn **"5. Hien thi danh sach sinh vien"** để xem danh sách

### **Thao tác cơ bản:**
- **Thêm sinh viên:** Chọn 1 hoặc 2, nhập thông tin
- **Xóa sinh viên:** Chọn 3, nhập vị trí cần xóa
- **Thay thế sinh viên:** Chọn 4, nhập vị trí và thông tin mới
- **Tìm kiếm:** Chọn 6, nhập mã sinh viên

### **Thông tin sinh viên:**
- **MaSV:** Mã số sinh viên (số nguyên dương)
- **Hoten:** Họ và tên đầy đủ
- **Ngay sinh:** Ngày (1-31), tháng (1-12), năm (1900-2024)
- **Gioi tinh:** Nam hoặc Nu
- **Que quan:** Quê quán

## 🔧 XỬ LÝ LỖI

### **Lỗi compile:**
- Kiểm tra đường dẫn g++ có đúng không
- Đảm bảo các file .h và .cpp có trong cùng thư mục

### **Lỗi runtime:**
- Kiểm tra input có đúng định dạng không
- Mã sinh viên phải là số dương
- Ngày sinh phải hợp lệ (kiểm tra năm nhuận)

### **F5 không chạy được:**
- Đảm bảo đã cài đặt C/C++ Extension trong VS Code
- Kiểm tra file launch.json và tasks.json
- Thử cách 2 (batch file) hoặc cách 3 (command line)

## 📁 CẤU TRÚC FILE

```
slist (1)/
├── ung_dung_sinhvien.h      # Header file chính
├── ung_dung_sinhvien.cpp    # Implementation file
├── test_ung_dung.cpp        # File main để chạy
├── compile_and_run.bat      # Script tự động compile và chạy
├── Makefile                 # Makefile để build
└── HUONG_DAN_CHAY.md        # File hướng dẫn này
```

## 💡 MẸO SỬ DỤNG

1. **Luôn chọn 9 trước** để có dữ liệu mẫu
2. **Dùng 5 để xem** danh sách sau mỗi thao tác
3. **Nhập 0 để thoát** chương trình
4. **Nếu gặp lỗi**, thử chạy lại bằng batch file

---

**Chúc bạn sử dụng thành công! 🎉**

