/*
 * =====================================================================================
 * FILE: sinhvien.h
 * MÔ TẢ: Header file định nghĩa class SinhVien - Lưu trữ thông tin sinh viên
 * TÁC GIẢ: AI Assistant
 * NGÀY TẠO: 2025
 * =====================================================================================
 * 
 * LỚP SINHVIEN - LƯU TRỮ THÔNG TIN SINH VIÊN
 * 
 * MỤC ĐÍCH:
 * - Lưu trữ và quản lý thông tin cơ bản của một sinh viên
 * - Cung cấp các phương thức để thao tác với dữ liệu sinh viên
 * - Kiểm tra tính hợp lệ của dữ liệu nhập vào
 * 
 * CÁC THUỘC TÍNH:
 * - MaSV (int): Mã số sinh viên - định danh duy nhất
 * - Hoten (string): Họ và tên đầy đủ của sinh viên
 * - Ngay, Thang, Nam (int): Ngày, tháng, năm sinh
 * - GioiTinh (string): Giới tính (Nam/Nu)
 * - QueQuan (string): Quê quán của sinh viên
 * 
 * CÁC PHƯƠNG THỨC CHÍNH:
 * - Constructor: Khởi tạo đối tượng sinh viên
 * - Destructor: Giải phóng bộ nhớ
 * - Getter/Setter: Truy cập và thay đổi dữ liệu
 * - nhapThongTin(): Nhập thông tin từ bàn phím
 * - xuatThongTin(): Hiển thị thông tin ra màn hình
 * - kiemTraNgaySinh(): Kiểm tra tính hợp lệ của ngày sinh
 * - tinhTuoi(): Tính tuổi của sinh viên
 * - Operator: So sánh hai đối tượng sinh viên
 */

#ifndef SINHVIEN_H
#define SINHVIEN_H

#include<iostream>    // Thư viện nhập/xuất chuẩn (cin, cout, endl)
#include<string>      // Thư viện xử lý chuỗi string
using namespace std;  // Sử dụng namespace std để không cần viết std::

class SinhVien{
	private:
		// Các thuộc tính private - chỉ có thể truy cập từ trong class
		int MaSV;        // Mã sinh viên - số nguyên dương
		string Hoten;    // Họ tên - chuỗi ký tự
		int Ngay;        // Ngày sinh - từ 1 đến 31
		int Thang;       // Tháng sinh - từ 1 đến 12
		int Nam;         // Năm sinh - từ 1900 đến 2024
		string GioiTinh; // Giới tính - "Nam" hoặc "Nu"
		string QueQuan;  // Quê quán - chuỗi ký tự
		
	public:
		// ==================== CONSTRUCTOR & DESTRUCTOR ====================
		
		// Constructor mặc định - khởi tạo với giá trị mặc định
		SinhVien();
		
		// Constructor với tham số - khởi tạo với dữ liệu cụ thể
		SinhVien(int ma, string ht, int ngay, int thang, int nam, string gt, string qq);
		
		// Destructor - giải phóng bộ nhớ khi đối tượng bị hủy
		~SinhVien();
		
		// Copy constructor - tạo bản sao từ đối tượng khác
		SinhVien(const SinhVien &sv);
		
		// Assignment operator - gán dữ liệu từ đối tượng khác
		SinhVien& operator=(const SinhVien &sv);
		
		// ==================== GETTER METHODS ====================
		// Các phương thức lấy dữ liệu (read-only)
		
		int getMaSV() const;        // Lấy mã sinh viên
		string getHoten() const;    // Lấy họ tên
		int getNgay() const;        // Lấy ngày sinh
		int getThang() const;       // Lấy tháng sinh
		int getNam() const;         // Lấy năm sinh
		string getGioiTinh() const; // Lấy giới tính
		string getQueQuan() const;  // Lấy quê quán
		
		// ==================== SETTER METHODS ====================
		// Các phương thức thay đổi dữ liệu
		
		void setMaSV(int ma);       // Đặt mã sinh viên
		void setHoten(string ht);   // Đặt họ tên
		void setNgay(int ngay);     // Đặt ngày sinh
		void setThang(int thang);   // Đặt tháng sinh
		void setNam(int nam);       // Đặt năm sinh
		void setGioiTinh(string gt); // Đặt giới tính
		void setQueQuan(string qq); // Đặt quê quán
		 
		// ==================== PHƯƠNG THỨC CHỨC NĂNG ====================
		
		// Kiểm tra tính hợp lệ của ngày sinh (năm nhuận, số ngày theo tháng...)
		bool kiemTraNgaySinh() const;
		
		// Nhập thông tin sinh viên từ bàn phím với kiểm tra dữ liệu
		void nhapThongTin();
		
		// Hiển thị thông tin sinh viên ra màn hình
		void xuatThongTin() const;
		
		// Tính tuổi dựa trên năm sinh và năm hiện tại
		int tinhTuoi() const;
		
		// ==================== OPERATOR OVERLOADING ====================
		
		// So sánh bằng - kiểm tra hai sinh viên có giống nhau không
		bool operator==(const SinhVien &sv) const;
		
		// So sánh khác - kiểm tra hai sinh viên có khác nhau không
		bool operator!=(const SinhVien &sv) const;
};

#endif
