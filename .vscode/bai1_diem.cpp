// Bài 1: Lớp điểm trong mặt phẳng
// Yêu cầu: một constructor không đối, một constructor có đủ đối,
// hai phương thức nhập và in tọa độ của điểm.

#include <iostream>
using namespace std;

class Point {
private:
	double x;
	double y;
public:
	// Constructor không đối: khởi tạo gốc tọa độ
	Point() : x(0), y(0) {}

	// Constructor có đủ đối
	Point(double xValue, double yValue) : x(xValue), y(yValue) {}

	// Phương thức nhập tọa độ
	void input() {
		cout << "Nhap x y: ";
		cin >> x >> y;
	}

	// Phương thức in tọa độ
	void print() const {
		cout << "(" << x << ", " << y << ")";
	}
};

int main() {
	// Minh họa yêu cầu
	Point A;            // dùng ctor không đối
	Point B(3, 4);      // dùng ctor đủ đối

	cout << "Nhap diem A\n";
	A.input();

	cout << "Toa do A: ";
	A.print();
	cout << "\nToa do B: ";
	B.print();
	cout << '\n';

	return 0;
}




