#include"danhsachsinhvien.h"
#include<iostream>
#include<iomanip>
using namespace std;

// Constructor
DanhSachSinhVien::DanhSachSinhVien(){
	head = nullptr;
	tail = nullptr;
	size = 0;
}

// Destructor
DanhSachSinhVien::~DanhSachSinhVien(){
	giaiPhongBoNho();
}

// Copy constructor
DanhSachSinhVien::DanhSachSinhVien(const DanhSachSinhVien &ds){
	head = nullptr;
	tail = nullptr;
	size = 0;
	saoChepDanhSach(ds);
}

// Assignment operator
DanhSachSinhVien& DanhSachSinhVien::operator=(const DanhSachSinhVien &ds){
	if(this != &ds){
		giaiPhongBoNho();
		saoChepDanhSach(ds);
	}
	return *this;
}

// 1. Thêm sinh viên vào cuối danh sách
void DanhSachSinhVien::themVaoCuoi(SinhVien sv){
	Node* newNode = new Node(sv);
	
	if(head == nullptr){
		// Danh sách rỗng
		head = tail = newNode;
	} else {
		// Danh sách không rỗng
		tail->setNext(newNode);
		tail = newNode;
	}
	size++;
}

// 2. Thêm sinh viên vào đầu danh sách
void DanhSachSinhVien::themVaoDau(SinhVien sv){
	Node* newNode = new Node(sv);
	
	if(head == nullptr){
		// Danh sách rỗng
		head = tail = newNode;
	} else {
		// Danh sách không rỗng
		newNode->setNext(head);
		head = newNode;
	}
	size++;
}

// 3. Xóa sinh viên thứ i khỏi danh sách
bool DanhSachSinhVien::xoaSinhVien(int viTri){
	if(viTri < 1 || viTri > size || kiemTraRong()){
		return false;
	}
	
	Node* nodeToDelete;
	
	if(viTri == 1){
		// Xóa node đầu tiên
		nodeToDelete = head;
		head = head->getNext();
		if(head == nullptr){
			tail = nullptr;
		}
	} else {
		// Xóa node ở vị trí i
		Node* prevNode = layNodeTaiViTri(viTri - 1);
		nodeToDelete = prevNode->getNext();
		prevNode->setNext(nodeToDelete->getNext());
		
		if(viTri == size){
			tail = prevNode;
		}
	}
	
	delete nodeToDelete;
	size--;
	return true;
}

// 4. Thay thế sinh viên thứ i bằng sinh viên mới
bool DanhSachSinhVien::thayTheSinhVien(int viTri, SinhVien svMoi){
	if(viTri < 1 || viTri > size || kiemTraRong()){
		return false;
	}
	
	Node* nodeToReplace = layNodeTaiViTri(viTri);
	nodeToReplace->setData(svMoi);
	return true;
}

// Hiển thị danh sách sinh viên
void DanhSachSinhVien::hienThiDanhSach() const{
	if(kiemTraRong()){
		cout << "Danh sach sinh vien rong!" << endl;
		return;
	}
	
	cout << "\n=== DANH SACH SINH VIEN ===" << endl;
	cout << "So luong sinh vien: " << size << endl;
	cout << "----------------------------------------" << endl;
	cout << left << setw(8) << "Ma SV" 
		 << setw(20) << "Ho Ten" 
		 << setw(15) << "Ngay Sinh" 
		 << setw(10) << "Gioi Tinh" 
		 << setw(15) << "Que Quan" << endl;
	cout << "----------------------------------------" << endl;
	
	Node* current = head;
	int stt = 1;
	while(current != nullptr){
		cout << left << setw(8) << current->getData().getMaSV()
			 << setw(20) << current->getData().getHoten()
			 << setw(15) << (to_string(current->getData().getNgay()) + "/" + 
							to_string(current->getData().getThang()) + "/" + 
							to_string(current->getData().getNam()))
			 << setw(10) << current->getData().getGioiTinh()
			 << setw(15) << current->getData().getQueQuan() << endl;
		current = current->getNext();
		stt++;
	}
	cout << "----------------------------------------" << endl;
}

// Tìm kiếm sinh viên theo mã
Node* DanhSachSinhVien::timSinhVienTheoMa(int maSV) const{
	Node* current = head;
	while(current != nullptr){
		if(current->getData().getMaSV() == maSV){
			return current;
		}
		current = current->getNext();
	}
	return nullptr;
}

// Đếm số lượng sinh viên
int DanhSachSinhVien::demSoLuong() const{
	return size;
}

// Kiểm tra danh sách rỗng
bool DanhSachSinhVien::kiemTraRong() const{
	return (head == nullptr);
}

// Lấy sinh viên tại vị trí i
SinhVien DanhSachSinhVien::laySinhVien(int viTri) const{
	if(viTri < 1 || viTri > size || kiemTraRong()){
		// Trả về sinh viên mặc định nếu vị trí không hợp lệ
		return SinhVien();
	}
	
	Node* node = layNodeTaiViTri(viTri);
	return node->getData();
}

// Xóa toàn bộ danh sách
void DanhSachSinhVien::xoaToanBo(){
	giaiPhongBoNho();
	head = nullptr;
	tail = nullptr;
	size = 0;
}

// Thêm sinh viên tại vị trí i
bool DanhSachSinhVien::themTaiViTri(int viTri, SinhVien sv){
	if(viTri < 1 || viTri > size + 1){
		return false;
	}
	
	if(viTri == 1){
		themVaoDau(sv);
	} else if(viTri == size + 1){
		themVaoCuoi(sv);
	} else {
		Node* newNode = new Node(sv);
		Node* prevNode = layNodeTaiViTri(viTri - 1);
		newNode->setNext(prevNode->getNext());
		prevNode->setNext(newNode);
		size++;
	}
	return true;
}

// Phương thức hỗ trợ - Lấy node tại vị trí i
Node* DanhSachSinhVien::layNodeTaiViTri(int viTri) const{
	if(viTri < 1 || viTri > size){
		return nullptr;
	}
	
	Node* current = head;
	for(int i = 1; i < viTri; i++){
		current = current->getNext();
	}
	return current;
}

// Phương thức hỗ trợ - Giải phóng bộ nhớ
void DanhSachSinhVien::giaiPhongBoNho(){
	while(head != nullptr){
		Node* temp = head;
		head = head->getNext();
		delete temp;
	}
}

// Phương thức hỗ trợ - Sao chép danh sách
void DanhSachSinhVien::saoChepDanhSach(const DanhSachSinhVien &ds){
	Node* current = ds.head;
	while(current != nullptr){
		themVaoCuoi(current->getData());
		current = current->getNext();
	}
}
