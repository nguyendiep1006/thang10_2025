/*
 * =====================================================================================
 * FILE: node_template.h
 * MÔ TẢ: Template class Node - Node của danh sách liên kết đơn với template
 * TÁC GIẢ: AI Assistant
 * NGÀY TẠO: 2025
 * =====================================================================================
 * 
 * TEMPLATE CLASS NODE - NODE CỦA DANH SÁCH LIÊN KẾT ĐƠN VỚI TEMPLATE
 * 
 * MỤC ĐÍCH:
 * - Đại diện cho một phần tử trong danh sách liên kết đơn
 * - Lưu trữ dữ liệu kiểu T (có thể là bất kỳ kiểu nào) và con trỏ đến node kế tiếp
 * - Cung cấp giao diện để truy cập và thay đổi dữ liệu
 * - Có thể sử dụng với nhiều kiểu dữ liệu khác nhau (int, float, string, SinhVien, v.v.)
 * 
 * CẤU TRÚC:
 * [data: T] -> [next: Node<T>*] -> [data: T] -> [next: Node<T>*] -> NULL
 * 
 * CÁC THUỘC TÍNH:
 * - data (T): Dữ liệu được lưu trữ trong node (kiểu T có thể là bất kỳ kiểu nào)
 * - next (Node<T>*): Con trỏ trỏ đến node kế tiếp trong danh sách
 * 
 * CÁC PHƯƠNG THỨC:
 * - Constructor: Khởi tạo node với dữ liệu mặc định hoặc cụ thể
 * - Destructor: Giải phóng bộ nhớ
 * - Getter/Setter: Truy cập và thay đổi dữ liệu
 * - khoiTaoNode(): Khởi tạo node với dữ liệu mới
 * 
 * VÍ DỤ SỬ DỤNG:
 * - Node<int> nodeInt;           // Node chứa số nguyên
 * - Node<float> nodeFloat;       // Node chứa số thực
 * - Node<string> nodeString;     // Node chứa chuỗi
 * - Node<SinhVien> nodeSinhVien; // Node chứa đối tượng SinhVien
 * 
 * LƯU Ý:
 * - Node không tự quản lý bộ nhớ của next (do DanhSach quản lý)
 * - Mỗi node chỉ chứa một đối tượng kiểu T
 * - Template cho phép sử dụng với bất kỳ kiểu dữ liệu nào
 */

#ifndef NODE_TEMPLATE_H
#define NODE_TEMPLATE_H

template <class T>
class Node{
	private:
		// Các thuộc tính private - chỉ có thể truy cập từ trong class
		T data;          // Dữ liệu được lưu trữ trong node (kiểu T)
		Node<T>* next;   // Con trỏ trỏ đến node kế tiếp (NULL nếu là node cuối)
		
	public:
		// ==================== CONSTRUCTOR & DESTRUCTOR ====================
		
		// Constructor mặc định - khởi tạo node rỗng
		Node(){
			next = nullptr;
		}
		
		// Constructor với dữ liệu - khởi tạo node với dữ liệu cụ thể
		Node(T data){
			this->data = data;
			next = nullptr;
		}
		
		// Destructor - giải phóng bộ nhớ khi node bị hủy
		~Node(){
			// Không delete next vì danh sách sẽ quản lý
		}
		
		// ==================== GETTER METHODS ====================
		// Các phương thức lấy dữ liệu (read-only)
		
		T getData() const{
			return data;
		}
		
		Node<T>* getNext() const{
			return next;
		}
		
		// ==================== SETTER METHODS ====================
		// Các phương thức thay đổi dữ liệu
		
		void setData(T data){
			this->data = data;
		}
		
		void setNext(Node<T>* n){
			next = n;
		}
		
		// ==================== PHƯƠNG THỨC KHỞI TẠO ====================
		
		void khoiTaoNode(T data){
			this->data = data;
			next = nullptr;
		}
		
		// ==================== PHƯƠNG THỨC BỔ SUNG ====================
		
		// Phương thức in thông tin node (chỉ dùng được với kiểu có operator<<)
		void printNode() const{
			cout << data;
		}
		
		// Phương thức so sánh dữ liệu (chỉ dùng được với kiểu có operator==)
		bool equals(T otherData) const{
			return data == otherData;
		}
};

#endif
