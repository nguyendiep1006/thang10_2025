// Bài 3: Lớp biểu diễn các thí sinh
// Thuộc tính: SBD, Họ tên, Năm sinh, Giới tính, điểm Toán/Lý/Hóa
// Có các constructor, phương thức nhập, in, lấy tổng điểm, lấy điểm từng môn

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class ThiSinh {
private:
	string soBaoDanh;
	string hoTen;
	int namSinh;
	string gioiTinh; // "Nam"/"Nu" hoặc tùy người dùng nhập
	double diemToan;
	double diemLy;
	double diemHoa;
public:
	// Constructor không đối - khởi tạo tất cả các thuộc tính về giá trị mặc định
	// soBaoDanh, hoTen, gioiTinh: chuỗi rỗng ""
	// namSinh: 0 
	// diemToan, diemLy, diemHoa: 0.0
	ThiSinh()
		: soBaoDanh(""), hoTen(""), namSinh(0), gioiTinh(""),
		diemToan(0), diemLy(0), diemHoa(0) {}

	// Constructor có đủ đối
	ThiSinh(const string &sbd, const string &name, int year, const string &gender,
			double toan, double ly, double hoa)
		: soBaoDanh(sbd), hoTen(name), namSinh(year), gioiTinh(gender),
		diemToan(toan), diemLy(ly), diemHoa(hoa) {}

	void nhap() {
		cout << "Nhap SBD: ";
		cin >> soBaoDanh;
		cout << "Nhap ho ten: ";
		cin.ignore(); // Xóa bộ đệm sau khi đọc SBD bằng cin
		getline(cin, hoTen); // Đọc cả dòng cho họ tên vì có thể chứa dấu cách
		cout << "Nhap nam sinh: ";
		cin >> namSinh;
		cout << "Nhap gioi tinh: ";
		cin >> gioiTinh;
		cout << "Nhap diem Toan, Ly, Hoa: ";
		cin >> diemToan >> diemLy >> diemHoa;
	}

	void in() const {
		cout << "SBD: " << soBaoDanh << '\n';
		cout << "Ho ten: " << hoTen << '\n';
		cout << "Nam sinh: " << namSinh << '\n';
		cout << "Gioi tinh: " << gioiTinh << '\n';
		cout << fixed << setprecision(2);
		cout << "Diem Toan: " << diemToan << ", Ly: " << diemLy
			 << ", Hoa: " << diemHoa << '\n';
		cout << "Tong diem: " << tongDiem() << '\n';
	}

	double tongDiem() const { return diemToan + diemLy + diemHoa; }
	double getDiemToan() const { return diemToan; }
	double getDiemLy() const { return diemLy; }
	double getDiemHoa() const { return diemHoa; }
};

int main() {
	ThiSinh ts; // dùng ctor không đối
	cout << "Nhap thong tin thi sinh:\n";
	ts.nhap();
	cout << "\nThong tin vua nhap:\n";
	ts.in();
	return 0;
}



