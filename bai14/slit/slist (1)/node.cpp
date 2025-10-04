/*
 * =====================================================================================
 * FILE: node.cpp
 * MÔ TẢ: Implementation file cho class Node
 * TÁC GIẢ: AI Assistant
 * NGÀY TẠO: 2025
 * =====================================================================================
 * 
 * NỘI DUNG:
 * - Định nghĩa tất cả các phương thức đã khai báo trong node.h
 * - Xử lý logic cơ bản cho node trong danh sách liên kết
 * - Quản lý dữ liệu và con trỏ next
 */

#include"node.h"  // Include header file để có thể sử dụng các khai báo

// ==================== CONSTRUCTOR & DESTRUCTOR ====================

/*
 * CONSTRUCTOR MẶC ĐỊNH
 * Mục đích: Khởi tạo node rỗng với next = nullptr
 * Sử dụng: Khi tạo node mà chưa có dữ liệu cụ thể
 */
Node::Node(){
	next = nullptr;  // Khởi tạo con trỏ next = nullptr (không trỏ đến đâu)
}

/*
 * CONSTRUCTOR VỚI DỮ LIỆU
 * Mục đích: Khởi tạo node với dữ liệu sinh viên cụ thể
 * Tham số: sv - đối tượng SinhVien cần lưu trữ trong node
 */
Node::Node(SinhVien sv){
	data = sv;       // Gán dữ liệu sinh viên
	next = nullptr;  // Khởi tạo con trỏ next = nullptr
}

/*
 * DESTRUCTOR
 * Mục đích: Giải phóng bộ nhớ khi node bị hủy
 * Lưu ý: Node không tự quản lý bộ nhớ của next, do DanhSachSinhVien quản lý
 */
Node::~Node(){
	// Không cần giải phóng bộ nhớ vì:
	// - data (SinhVien) sẽ tự động được giải phóng
	// - next sẽ được quản lý bởi DanhSachSinhVien
}

// ==================== GETTER METHODS ====================
// Các phương thức lấy dữ liệu - chỉ đọc, không thay đổi đối tượng

/*
 * GETTER CHO DỮ LIỆU SINH VIÊN
 * Mục đích: Lấy dữ liệu sinh viên được lưu trữ trong node
 * Trả về: SinhVien - đối tượng sinh viên
 * const: Đảm bảo không thay đổi đối tượng
 */
SinhVien Node::getData() const{
	return data;  // Trả về dữ liệu sinh viên
}

/*
 * GETTER CHO CON TRỎ NEXT
 * Mục đích: Lấy con trỏ trỏ đến node kế tiếp
 * Trả về: Node* - con trỏ đến node kế tiếp (có thể là nullptr)
 * const: Đảm bảo không thay đổi đối tượng
 */
Node* Node::getNext() const{
	return next;  // Trả về con trỏ next
}   

// ==================== SETTER METHODS ====================
// Các phương thức thay đổi dữ liệu - có thể sửa đổi đối tượng

/*
 * SETTER CHO DỮ LIỆU SINH VIÊN
 * Mục đích: Thay đổi dữ liệu sinh viên trong node
 * Tham số: sv - đối tượng sinh viên mới
 */
void Node::setData(SinhVien sv){
	data = sv;  // Gán dữ liệu sinh viên mới
}

/*
 * SETTER CHO CON TRỎ NEXT
 * Mục đích: Thay đổi con trỏ trỏ đến node kế tiếp
 * Tham số: n - con trỏ đến node kế tiếp (có thể là nullptr)
 * Lưu ý: Cần cẩn thận khi thay đổi next để không làm mất liên kết
 */
void Node::setNext(Node* n){
	next = n;  // Gán con trỏ next mới
}

// ==================== PHƯƠNG THỨC KHỞI TẠO ====================

/*
 * KHỞI TẠO LẠI NODE
 * Mục đích: Khởi tạo lại node với dữ liệu sinh viên mới
 * Tham số: sv - đối tượng sinh viên mới
 * Lưu ý: Phương thức này reset cả data và next về trạng thái ban đầu
 */
void Node::khoiTaoNode(SinhVien sv){
	data = sv;       // Gán dữ liệu sinh viên mới
	next = nullptr;  // Reset con trỏ next về nullptr
}
