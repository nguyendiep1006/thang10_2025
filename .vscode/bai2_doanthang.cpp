 // Bài 2: Lớp biểu diễn đoạn thẳng bởi 2 điểm đầu và cuối
// Các constructor: không đối, có đủ đối. Phương thức nhập, in, và tính độ dài.

#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
	double x;
	double y;
public:
	// Constructor là phương thức khởi tạo đối tượng của lớp
	// Constructor không đối số - tự động khởi tạo điểm tại (0,0)
	// khi tạo đối tượng mà không truyền tham số
	Point() : x(0), y(0) {}
	
	// Constructor có 2 đối số - cho phép khởi tạo điểm tại tọa độ tùy chọn
	// bằng cách truyền vào 2 giá trị x, y khi tạo đối tượng
	Point(double xValue, double yValue) : x(xValue), y(yValue) {}

	void input() {
		cin >> x >> y;
	}

	void print() const {
		cout << "(" << x << ", " << y << ")";
	}

	double getX() const { return x; }
	double getY() const { return y; }
};

// Lớp Segment biểu diễn một đoạn thẳng trong mặt phẳng tọa độ
// được xác định bởi 2 điểm đầu và cuối
class Segment {
private:
	Point startPoint;
	Point endPoint;
public:
	Segment() : startPoint(), endPoint() {}
	Segment(const Point &s, const Point &e) : startPoint(s), endPoint(e) {}

	void input() {
		cout << "Nhap diem dau (x y): ";
		startPoint.input();
		cout << "Nhap diem cuoi (x y): ";
		endPoint.input();
	}

	void print() const {
		cout << "Doan thang: ";
		startPoint.print();
		cout << " -> ";
		endPoint.print();
	}

	double length() const {
		double dx = endPoint.getX() - startPoint.getX();
		double dy = endPoint.getY() - startPoint.getY();
		return sqrt(dx * dx + dy * dy);
	}
};

int main() {
	Segment s; // ctor không đối
	cout << "Nhap doan thang (2 diem):\n";
	s.input();
	cout << "\n";
	s.print();
	cout << "\nDo dai: " << s.length() << '\n';
	return 0;
}




