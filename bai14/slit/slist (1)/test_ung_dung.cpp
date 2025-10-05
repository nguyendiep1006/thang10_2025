/*
 * =====================================================================================
 * FILE: test_ung_dung.cpp
 * MÔ TẢ: Chương trình test để chạy lớp ứng dụng quản lý sinh viên
 * TÁC GIẢ: AI Assistant
 * NGÀY TẠO: 2025
 * =====================================================================================
 * 
 * CHƯƠNG TRÌNH TEST LỚP ỨNG DỤNG QUẢN LÝ SINH VIÊN
 * 
 * MỤC ĐÍCH:
 * - Test các chức năng của lớp UngDungSinhVien
 * - Demo cách sử dụng danh sách liên kết đơn
 * - Minh họa các thao tác cơ bản với sinh viên
 * 
 * CÁCH CHẠY:
 * - Compile: g++ -o test_ung_dung test_ung_dung.cpp ung_dung_sinhvien.cpp
 * - Run: ./test_ung_dung (Linux/Mac) hoặc test_ung_dung.exe (Windows)
 */

#include"ung_dung_sinhvien.h"

int main() {
    cout << "=== CHUONG TRINH TEST LOP UNG DUNG QUAN LY SINH VIEN ===" << endl;
    cout << "Su dung danh sach lien ket don de luu tru sinh vien" << endl;
    
    // Tạo đối tượng ứng dụng
    UngDungSinhVien app;
    
    // Chạy ứng dụng
    app.chayUngDung();
    
    return 0;
}
