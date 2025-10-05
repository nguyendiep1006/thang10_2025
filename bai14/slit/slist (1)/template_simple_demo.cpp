/*
 * =====================================================================================
 * FILE: template_simple_demo.cpp
 * MÔ TẢ: Demo đơn giản về template<T> - dễ hiểu cho người mới học
 * TÁC GIẢ: AI Assistant
 * NGÀY TẠO: 2025
 * =====================================================================================
 * 
 * DEMO ĐƠN GIẢN VỀ TEMPLATE<T>
 * 
 * MỤC ĐÍCH:
 * - Giải thích template một cách đơn giản, dễ hiểu
 * - So sánh code có template và không có template
 * - Minh họa lợi ích của template
 */

#include<iostream>
#include<string>
using namespace std;

// ==================== KHÔNG SỬ DỤNG TEMPLATE ====================
// Phải viết nhiều class tương tự cho các kiểu dữ liệu khác nhau

class NodeInt{
	private:
		int data;
		NodeInt* next;
	public:
		NodeInt(int d = 0) { data = d; next = nullptr; }
		int getData() { return data; }
		void setData(int d) { data = d; }
		void print() { cout << "NodeInt: " << data << endl; }
};

class NodeFloat{
	private:
		float data;
		NodeFloat* next;
	public:
		NodeFloat(float d = 0.0) { data = d; next = nullptr; }
		float getData() { return data; }
		void setData(float d) { data = d; }
		void print() { cout << "NodeFloat: " << data << endl; }
};

class NodeString{
	private:
		string data;
		NodeString* next;
	public:
		NodeString(string d = "") { data = d; next = nullptr; }
		string getData() { return data; }
		void setData(string d) { data = d; }
		void print() { cout << "NodeString: " << data << endl; }
};

// ==================== SỬ DỤNG TEMPLATE ====================
// Chỉ cần viết 1 lần, dùng cho nhiều kiểu dữ liệu

template <class T>
class NodeTemplate{
	private:
		T data;
		NodeTemplate<T>* next;
	public:
		NodeTemplate(T d = T()) { data = d; next = nullptr; }
		T getData() { return data; }
		void setData(T d) { data = d; }
		void print() { cout << "NodeTemplate<" << typeid(T).name() << ">: " << data << endl; }
};

// Template function
template <class T>
T getMax(T a, T b){
	return (a > b) ? a : b;
}

// Template function với nhiều tham số
template <class T, class U>
void printPair(T first, U second){
	cout << "Cap (" << first << ", " << second << ")" << endl;
}

int main(){
	cout << "=== DEMO TEMPLATE<T> DON GIAN ===" << endl;
	
	// ==================== SO SÁNH CODE ====================
	cout << "\n1. SO SANH CODE:" << endl;
	cout << "KHONG TEMPLATE - Phai viet 3 class rieng:" << endl;
	cout << "- NodeInt (cho so nguyen)" << endl;
	cout << "- NodeFloat (cho so thuc)" << endl;
	cout << "- NodeString (cho chuoi)" << endl;
	cout << "=> Code trung lap nhieu!" << endl;
	
	cout << "\nCO TEMPLATE - Chi can 1 class:" << endl;
	cout << "- NodeTemplate<T> (cho tat ca kieu du lieu)" << endl;
	cout << "=> Code ngan gon!" << endl;
	
	// ==================== DEMO KHÔNG TEMPLATE ====================
	cout << "\n2. DEMO KHONG TEMPLATE:" << endl;
	
	NodeInt nodeInt(100);
	NodeFloat nodeFloat(3.14f);
	NodeString nodeString("Hello");
	
	nodeInt.print();
	nodeFloat.print();
	nodeString.print();
	
	// ==================== DEMO CÓ TEMPLATE ====================
	cout << "\n3. DEMO CO TEMPLATE:" << endl;
	
	// Sử dụng template với các kiểu dữ liệu khác nhau
	NodeTemplate<int> nodeIntT(200);
	NodeTemplate<float> nodeFloatT(2.71f);
	NodeTemplate<string> nodeStringT("World");
	NodeTemplate<char> nodeCharT('A');
	
	nodeIntT.print();
	nodeFloatT.print();
	nodeStringT.print();
	nodeCharT.print();
	
	// ==================== DEMO TEMPLATE FUNCTION ====================
	cout << "\n4. DEMO TEMPLATE FUNCTION:" << endl;
	
	// Function getMax có thể dùng với nhiều kiểu
	cout << "Max(10, 20) = " << getMax(10, 20) << endl;
	cout << "Max(3.14, 2.71) = " << getMax(3.14, 2.71) << endl;
	cout << "Max('A', 'B') = " << getMax('A', 'B') << endl;
	
	// Function printPair với 2 kiểu dữ liệu khác nhau
	cout << "\nDemo printPair:" << endl;
	printPair(123, "abc");
	printPair(3.14, 'X');
	printPair("Hello", 456);
	
	// ==================== DEMO TÍNH LINH HOẠT ====================
	cout << "\n5. DEMO TINH LINH HOAT:" << endl;
	
	// Có thể dùng với kiểu dữ liệu tùy chỉnh
	struct Point{
		int x, y;
		Point(int x = 0, int y = 0) : x(x), y(y) {}
		
		// Override operator<< để có thể in
		friend ostream& operator<<(ostream& os, const Point& p){
			os << "(" << p.x << "," << p.y << ")";
			return os;
		}
		
		// Override operator> để có thể so sánh
		bool operator>(const Point& other) const{
			return (x*x + y*y) > (other.x*other.x + other.y*other.y);
		}
	};
	
	// Sử dụng template với kiểu Point
	NodeTemplate<Point> nodePoint(Point(3, 4));
	nodePoint.print();
	
	// Sử dụng getMax với Point
	Point p1(1, 2), p2(3, 4);
	cout << "Max distance: " << getMax(p1, p2) << endl;
	
	// ==================== KẾT LUẬN ====================
	cout << "\n6. KET LUAN:" << endl;
	cout << "Template<T> giup:" << endl;
	cout << "✓ Giam code trung lap" << endl;
	cout << "✓ Code ngan gon, de doc" << endl;
	cout << "✓ Linh hoat voi nhieu kieu du lieu" << endl;
	cout << "✓ Type safety (an toan kieu du lieu)" << endl;
	cout << "✓ Performance cao" << endl;
	
	cout << "\nCach su dung:" << endl;
	cout << "template <class T>  // Khai bao template" << endl;
	cout << "class TenClass {     // Viet class nhu binh thuong" << endl;
	cout << "    T data;          // Su dung T thay cho kieu cu the" << endl;
	cout << "};" << endl;
	
	cout << "\nKhi su dung:" << endl;
	cout << "TenClass<int> obj1;      // T = int" << endl;
	cout << "TenClass<float> obj2;    // T = float" << endl;
	cout << "TenClass<string> obj3;   // T = string" << endl;
	
	return 0;
}
