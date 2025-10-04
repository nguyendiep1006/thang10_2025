#include"node.h"

// Constructor mặc định
Node::Node(){
	next = nullptr;
}

// Constructor với dữ liệu
Node::Node(SinhVien sv){
	data = sv;
	next = nullptr;
}

// Destructor
Node::~Node(){
	// Không cần giải phóng bộ nhớ vì next sẽ được quản lý bởi DanhSachSinhVien
}

// Getter methods
SinhVien Node::getData() const{
	return data;
}

Node* Node::getNext() const{
	return next;
}   

// Setter methods
void Node::setData(SinhVien sv){
	data = sv;
}

void Node::setNext(Node* n){
	next = n;
}

// Phương thức khởi tạo node
void Node::khoiTaoNode(SinhVien sv){
	data = sv;
	next = nullptr;
}
