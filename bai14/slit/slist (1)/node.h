#ifndef NODE_H
#define NODE_H

#include"sinhvien.h"

/*
 * LỚP NODE - NODE CỦA DANH SÁCH LIÊN KẾT ĐƠN
 * 
 * Thuộc tính:
 * - data: Dữ liệu kiểu SinhVien
 * - next: Con trỏ trỏ đến node kế tiếp
 * 
 * Phương thức:
 * - Constructor, destructor
 * - Getter/Setter cho data và next
 * - Phương thức khởi tạo node
 */

class Node{
	private:
		SinhVien data;
		Node* next;
		
	public:
		// Constructor mặc định
		Node();
		
		// Constructor với dữ liệu
		Node(SinhVien sv);
		
		// Destructor
		~Node();
		
		// Getter methods
		SinhVien getData() const;
		Node* getNext() const;
		
		// Setter methods
		void setData(SinhVien sv);
		void setNext(Node* n);
		
		// Phương thức khởi tạo node
		void khoiTaoNode(SinhVien sv);
};

#endif
