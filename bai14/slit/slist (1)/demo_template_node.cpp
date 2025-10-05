/*
 * =====================================================================================
 * FILE: demo_template_node.cpp
 * MÔ TẢ: Demo sử dụng template class Node với các kiểu dữ liệu khác nhau
 * TÁC GIẢ: AI Assistant
 * NGÀY TẠO: 2025
 * =====================================================================================
 * 
 * DEMO TEMPLATE CLASS NODE
 * 
 * MỤC ĐÍCH:
 * - Minh họa cách sử dụng template class Node với nhiều kiểu dữ liệu khác nhau
 * - So sánh giữa Node thông thường và Node template
 * - Demo các thao tác cơ bản với Node template
 * 
 * CÁC KIỂU DỮ LIỆU ĐƯỢC DEMO:
 * - int: Số nguyên
 * - float: Số thực
 * - string: Chuỗi ký tự
 * - SinhVien: Đối tượng sinh viên (nếu có)
 * 
 * CÁC THAO TÁC DEMO:
 * - Tạo node với các kiểu dữ liệu khác nhau
 * - Thiết lập và lấy dữ liệu
 * - Kết nối các node với nhau
 * - In thông tin node
 */

#include<iostream>
#include<string>
using namespace std;

// Include template Node
#include"node_template.h"

// Class SinhVien đơn giản để demo
class SinhVien{
	private:
		int masv;
		string hoten;
		float diem;
	public:
		SinhVien(int m = 0, string ht = "", float d = 0.0){
			masv = m;
			hoten = ht;
			diem = d;
		}
		
		// Override operator<< để có thể in SinhVien
		friend ostream& operator<<(ostream& os, const SinhVien& sv){
			os << "SV" << sv.masv << " - " << sv.hoten << " - " << sv.diem << "diem";
			return os;
		}
		
		// Override operator== để có thể so sánh SinhVien
		bool operator==(const SinhVien& other) const{
			return masv == other.masv;
		}
		
		int getMaSV() const { return masv; }
		string getHoTen() const { return hoten; }
		float getDiem() const { return diem; }
};

// Template function để in danh sách các node
template <class T>
void printNodeList(Node<T>* head, string typeName){
	cout << "\n=== DANH SACH NODE KIEU " << typeName << " ===" << endl;
	
	Node<T>* current = head;
	int count = 1;
	
	while(current != nullptr){
		cout << "Node " << count << ": ";
		current->printNode();
		cout << endl;
		current = current->getNext();
		count++;
	}
	
	if(count == 1){
		cout << "Danh sach rong!" << endl;
	}
}

// Template function để tìm kiếm trong danh sách node
template <class T>
Node<T>* searchNode(Node<T>* head, T searchData){
	Node<T>* current = head;
	
	while(current != nullptr){
		if(current->equals(searchData)){
			return current;
		}
		current = current->getNext();
	}
	
	return nullptr; // Không tìm thấy
}

int main(){
	cout << "=== DEMO TEMPLATE CLASS NODE ===" << endl;
	cout << "Minh hoa su dung template Node voi cac kieu du lieu khac nhau" << endl;
	
	// ==================== DEMO VỚI KIỂU INT ====================
	cout << "\n" << string(50, '=') << endl;
	cout << "1. DEMO VOI KIEU INT" << endl;
	cout << string(50, '=') << endl;
	
	// Tạo các node kiểu int
	Node<int>* headInt = new Node<int>(10);
	Node<int>* node2Int = new Node<int>(20);
	Node<int>* node3Int = new Node<int>(30);
	
	// Kết nối các node
	headInt->setNext(node2Int);
	node2Int->setNext(node3Int);
	
	// In danh sách
	printNodeList(headInt, "INT");
	
	// Thao tác với dữ liệu
	cout << "\nGia tri node dau tien: " << headInt->getData() << endl;
	cout << "Thay doi gia tri node dau tien thanh 100..." << endl;
	headInt->setData(100);
	cout << "Gia tri moi: " << headInt->getData() << endl;
	
	// Tìm kiếm
	Node<int>* foundNode = searchNode(headInt, 20);
	if(foundNode != nullptr){
		cout << "Tim thay node co gia tri 20!" << endl;
	} else {
		cout << "Khong tim thay node co gia tri 20!" << endl;
	}
	
	// ==================== DEMO VỚI KIỂU FLOAT ====================
	cout << "\n" << string(50, '=') << endl;
	cout << "2. DEMO VOI KIEU FLOAT" << endl;
	cout << string(50, '=') << endl;
	
	// Tạo các node kiểu float
	Node<float>* headFloat = new Node<float>(3.14f);
	Node<float>* node2Float = new Node<float>(2.71f);
	Node<float>* node3Float = new Node<float>(1.41f);
	
	// Kết nối các node
	headFloat->setNext(node2Float);
	node2Float->setNext(node3Float);
	
	// In danh sách
	printNodeList(headFloat, "FLOAT");
	
	// Thao tác với dữ liệu
	cout << "\nGia tri node dau tien: " << headFloat->getData() << endl;
	cout << "Thay doi gia tri node dau tien thanh 9.99..." << endl;
	headFloat->setData(9.99f);
	cout << "Gia tri moi: " << headFloat->getData() << endl;
	
	// ==================== DEMO VỚI KIỂU STRING ====================
	cout << "\n" << string(50, '=') << endl;
	cout << "3. DEMO VOI KIEU STRING" << endl;
	cout << string(50, '=') << endl;
	
	// Tạo các node kiểu string
	Node<string>* headString = new Node<string>("Hello");
	Node<string>* node2String = new Node<string>("World");
	Node<string>* node3String = new Node<string>("C++");
	
	// Kết nối các node
	headString->setNext(node2String);
	node2String->setNext(node3String);
	
	// In danh sách
	printNodeList(headString, "STRING");
	
	// Thao tác với dữ liệu
	cout << "\nGia tri node dau tien: " << headString->getData() << endl;
	cout << "Thay doi gia tri node dau tien thanh 'Template'..." << endl;
	headString->setData("Template");
	cout << "Gia tri moi: " << headString->getData() << endl;
	
	// ==================== DEMO VỚI KIỂU SINHVIEN ====================
	cout << "\n" << string(50, '=') << endl;
	cout << "4. DEMO VOI KIEU SINHVIEN" << endl;
	cout << string(50, '=') << endl;
	
	// Tạo các node kiểu SinhVien
	Node<SinhVien>* headSV = new Node<SinhVien>(SinhVien(123, "Nguyen Van A", 8.5f));
	Node<SinhVien>* node2SV = new Node<SinhVien>(SinhVien(124, "Tran Thi B", 9.0f));
	Node<SinhVien>* node3SV = new Node<SinhVien>(SinhVien(125, "Le Van C", 7.5f));
	
	// Kết nối các node
	headSV->setNext(node2SV);
	node2SV->setNext(node3SV);
	
	// In danh sách
	printNodeList(headSV, "SINHVIEN");
	
	// Thao tác với dữ liệu
	cout << "\nSinh vien dau tien: " << headSV->getData() << endl;
	cout << "Thay doi sinh vien dau tien..." << endl;
	headSV->setData(SinhVien(999, "Hoang Van D", 10.0f));
	cout << "Sinh vien moi: " << headSV->getData() << endl;
	
	// Tìm kiếm sinh viên
	SinhVien searchSV(124, "", 0.0f); // Chỉ cần mã sinh viên để tìm
	Node<SinhVien>* foundSV = searchNode(headSV, searchSV);
	if(foundSV != nullptr){
		cout << "Tim thay sinh vien co ma 124!" << endl;
		cout << "Thong tin: " << foundSV->getData() << endl;
	} else {
		cout << "Khong tim thay sinh vien co ma 124!" << endl;
	}
	
	// ==================== DEMO SO SÁNH VỚI NODE THÔNG THƯỜNG ====================
	cout << "\n" << string(50, '=') << endl;
	cout << "5. SO SANH VOI NODE THONG THUONG" << endl;
	cout << string(50, '=') << endl;
	
	cout << "VOI NODE THONG THUONG (khong template):" << endl;
	cout << "- Chi co the luu tru 1 kieu du lieu cu the (vi du: SinhVien)" << endl;
	cout << "- Phai viet lai class Node cho moi kieu du lieu khac nhau" << endl;
	cout << "- Code trung lap nhieu, kho maintain" << endl;
	
	cout << "\nVOI TEMPLATE NODE:" << endl;
	cout << "- Co the luu tru bat ky kieu du lieu nao (int, float, string, SinhVien, ...)" << endl;
	cout << "- Chi can viet 1 lan, su dung cho nhieu kieu du lieu" << endl;
	cout << "- Code ngan gon, de maintain, type-safe" << endl;
	cout << "- Compiler tu dong tao code phu hop cho moi kieu du lieu" << endl;
	
	// ==================== DEMO CÁC THAO TÁC NÂNG CAO ====================
	cout << "\n" << string(50, '=') << endl;
	cout << "6. DEMO CAC THAO TAC NANG CAO" << endl;
	cout << string(50, '=') << endl;
	
	// Demo với kiểu int
	cout << "Tao danh sach so nguyen tu 1 den 5:" << endl;
	Node<int>* head = new Node<int>(1);
	Node<int>* current = head;
	
	for(int i = 2; i <= 5; i++){
		Node<int>* newNode = new Node<int>(i);
		current->setNext(newNode);
		current = newNode;
	}
	
	printNodeList(head, "INT (1-5)");
	
	// Tính tổng các số
	int sum = 0;
	current = head;
	while(current != nullptr){
		sum += current->getData();
		current = current->getNext();
	}
	cout << "Tong cac so: " << sum << endl;
	
	// Tìm số lớn nhất
	int max = head->getData();
	current = head->getNext();
	while(current != nullptr){
		if(current->getData() > max){
			max = current->getData();
		}
		current = current->getNext();
	}
	cout << "So lon nhat: " << max << endl;
	
	// ==================== KẾT LUẬN ====================
	cout << "\n" << string(50, '=') << endl;
	cout << "KET LUAN" << endl;
	cout << string(50, '=') << endl;
	
	cout << "Template<T> giup:" << endl;
	cout << "1. VIET CODE 1 LAN, DUNG NHIEU KIEU DU LIEU" << endl;
	cout << "2. CODE GON GANG, DE DOC, DE MAINTAIN" << endl;
	cout << "3. TYPE SAFETY - COMPILER KIEM TRA KIEU DU LIEU" << endl;
	cout << "4. PERFORMANCE CAO - KHONG OVERHEAD" << endl;
	cout << "5. LINH HOAT - SU DUNG VOI BAT KY KIEU DU LIEU NAO" << endl;
	
	cout << "\nVi du su dung:" << endl;
	cout << "Node<int> nodeInt;           // Node chua so nguyen" << endl;
	cout << "Node<float> nodeFloat;       // Node chua so thuc" << endl;
	cout << "Node<string> nodeString;     // Node chua chuoi" << endl;
	cout << "Node<SinhVien> nodeSV;       // Node chua doi tuong SinhVien" << endl;
	
	// Giải phóng bộ nhớ (trong thực tế nên có class quản lý danh sách)
	cout << "\nGiai phong bo nho..." << endl;
	
	// Giải phóng danh sách int
	current = head;
	while(current != nullptr){
		Node<int>* next = current->getNext();
		delete current;
		current = next;
	}
	
	// Giải phóng các danh sách khác (tương tự)
	// ... (code giải phóng bộ nhớ cho các danh sách khác)
	
	cout << "Hoan thanh demo template Node!" << endl;
	
	return 0;
}
