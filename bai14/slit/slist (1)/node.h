/*
 * =====================================================================================
 * FILE: node.h
 * MÔ TẢ: Header file định nghĩa class Node - Node của danh sách liên kết đơn
 * TÁC GIẢ: AI Assistant
 * NGÀY TẠO: 2025
 * =====================================================================================
 * 
 * LỚP NODE - NODE CỦA DANH SÁCH LIÊN KẾT ĐƠN
 * 
 * MỤC ĐÍCH:
 * - Đại diện cho một phần tử trong danh sách liên kết đơn
 * - Lưu trữ dữ liệu kiểu SinhVien và con trỏ đến node kế tiếp
 * - Cung cấp giao diện để truy cập và thay đổi dữ liệu
 * 
 * CẤU TRÚC:
 * [data: SinhVien] -> [next: Node*] -> [data: SinhVien] -> [next: Node*] -> NULL
 * 
 * CÁC THUỘC TÍNH:
 * - data (SinhVien): Dữ liệu sinh viên được lưu trữ trong node
 * - next (Node*): Con trỏ trỏ đến node kế tiếp trong danh sách
 * 
 * CÁC PHƯƠNG THỨC:
 * - Constructor: Khởi tạo node với dữ liệu mặc định hoặc cụ thể
 * - Destructor: Giải phóng bộ nhớ
 * - Getter/Setter: Truy cập và thay đổi dữ liệu
 * - khoiTaoNode(): Khởi tạo node với dữ liệu mới
 * 
 * LƯU Ý:
 * - Node không tự quản lý bộ nhớ của next (do DanhSachSinhVien quản lý)
 * - Mỗi node chỉ chứa một đối tượng SinhVien
 */

#ifndef NODE_H
#define NODE_H

#include"sinhvien.h"  // Include class SinhVien để sử dụng làm kiểu dữ liệu

class Node{
	private:
		// Các thuộc tính private - chỉ có thể truy cập từ trong class
		SinhVien data;  // Dữ liệu sinh viên được lưu trữ trong node
		Node* next;     // Con trỏ trỏ đến node kế tiếp (NULL nếu là node cuối)
		
	public:
		// ==================== CONSTRUCTOR & DESTRUCTOR ====================
		
		// Constructor mặc định - khởi tạo node rỗng
		Node();
		
		// Constructor với dữ liệu - khởi tạo node với sinh viên cụ thể
		Node(SinhVien sv);
		
		// Destructor - giải phóng bộ nhớ khi node bị hủy
		~Node();
		
		// ==================== GETTER METHODS ====================
		// Các phương thức lấy dữ liệu (read-only)
		
		SinhVien getData() const;  // Lấy dữ liệu sinh viên
		Node* getNext() const;     // Lấy con trỏ đến node kế tiếp
		
		// ==================== SETTER METHODS ====================
		// Các phương thức thay đổi dữ liệu
		
		void setData(SinhVien sv);  // Đặt dữ liệu sinh viên mới
		void setNext(Node* n);      // Đặt con trỏ đến node kế tiếp
		
		// ==================== PHƯƠNG THỨC KHỞI TẠO ====================
		
		void khoiTaoNode(SinhVien sv);  // Khởi tạo lại node với dữ liệu mới
};

#endif
