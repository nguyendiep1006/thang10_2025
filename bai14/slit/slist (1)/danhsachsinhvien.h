#ifndef DANHSACHSINHVIEN_H
#define DANHSACHSINHVIEN_H

#include"node.h"

/*
 * LỚP DANHSACHSINHVIEN - QUẢN LÝ DANH SÁCH SINH VIÊN BẰNG DANH SÁCH LIÊN KẾT ĐƠN
 * 
 * Thuộc tính:
 * - head: Con trỏ trỏ đến node đầu tiên
 * - tail: Con trỏ trỏ đến node cuối cùng
 * - size: Số lượng sinh viên trong danh sách
 * 
 * Các chức năng yêu cầu:
 * - Thêm sinh viên vào cuối danh sách
 * - Thêm sinh viên vào đầu danh sách
 * - Xóa sinh viên thứ i khỏi danh sách
 * - Thay thế sinh viên thứ i bằng sinh viên mới
 * 
 * Các chức năng bổ sung:
 * - Hiển thị danh sách sinh viên
 * - Tìm kiếm sinh viên theo mã
 * - Đếm số lượng sinh viên
 * - Kiểm tra danh sách rỗng
 */

class DanhSachSinhVien{
	private:
		Node* head;  // Con trỏ đến node đầu tiên
		Node* tail;  // Con trỏ đến node cuối cùng
		int size;    // Số lượng sinh viên
		
	public:
		// Constructor
		DanhSachSinhVien();
		
		// Destructor
		~DanhSachSinhVien();
		
		// Copy constructor
		DanhSachSinhVien(const DanhSachSinhVien &ds);
		
		// Assignment operator
		DanhSachSinhVien& operator=(const DanhSachSinhVien &ds);
		
		// Các chức năng chính yêu cầu
		
		// 1. Thêm sinh viên vào cuối danh sách
		void themVaoCuoi(SinhVien sv);
		
		// 2. Thêm sinh viên vào đầu danh sách
		void themVaoDau(SinhVien sv);
		
		// 3. Xóa sinh viên thứ i khỏi danh sách
		bool xoaSinhVien(int viTri);
		
		// 4. Thay thế sinh viên thứ i bằng sinh viên mới
		bool thayTheSinhVien(int viTri, SinhVien svMoi);
		
		// Các chức năng bổ sung
		
		// Hiển thị danh sách sinh viên
		void hienThiDanhSach() const;
		
		// Tìm kiếm sinh viên theo mã
		Node* timSinhVienTheoMa(int maSV) const;
		
		// Đếm số lượng sinh viên
		int demSoLuong() const;
		
		// Kiểm tra danh sách rỗng
		bool kiemTraRong() const;
		
		// Lấy sinh viên tại vị trí i
		SinhVien laySinhVien(int viTri) const;
		
		// Xóa toàn bộ danh sách
		void xoaToanBo();
		
		// Thêm sinh viên tại vị trí i
		bool themTaiViTri(int viTri, SinhVien sv);
		
	private:
		// Phương thức hỗ trợ
		Node* layNodeTaiViTri(int viTri) const;
		void giaiPhongBoNho();
		void saoChepDanhSach(const DanhSachSinhVien &ds);
};

#endif

