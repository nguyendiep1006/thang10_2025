#include<iostream>
#include<list>
#include<string>
using namespace std;

// Template class có thể dùng với nhiều kiểu số khác nhau
template <class T>
class SinhVien{
	private:
		int masv;        // Mã sinh viên luôn là int
		string hoten;    // Họ tên luôn là string
		T diemly;        // Điểm dùng template T
	public:
		// Constructor
		SinhVien(int m = 0, string ht = ""){
			masv = m;
			hoten = ht;
			diemly = 0;
		}
		
		// Phương thức in thông tin
		void In(){
			cout << masv << "\t" << hoten << "\t" << diemly << endl;
		}
		
		// Setter cho điểm
		void set_Diemly(T d){
			diemly = d;
		}
		
		// Getter cho điểm
		T get_Diemly(){
			return diemly;
		}
		
		// Phương thức tính điểm trung bình (chỉ dùng với số)
		T tinhTrungBinh(T diemToan, T diemVan){
			return (diemly + diemToan + diemVan) / 3;
		}
};

// Template function in danh sách
template <class T>
void in(list<SinhVien<T>> &l, string kieuDuLieu)
{
	cout << "\n=== DANH SACH SINH VIEN (Kieu: " << kieuDuLieu << ") ===" << endl;
	cout << "MaSV\tHo Ten\t\tDiem Ly" << endl;
	cout << "--------------------------------" << endl;
	for(typename list<SinhVien<T>>::iterator it = l.begin(); it != l.end(); it++){
		(*it).In();
	}
}

int main(){
	cout << "=== DEMO TEMPLATE VOI CAC KIEU SO KHAC NHAU ===" << endl;
	
	// 1. Sử dụng với kiểu INT
	cout << "\n1. SU DUNG VOI KIEU INT:" << endl;
	list<SinhVien<int>> ds_int;
	
	SinhVien<int> sv1(123, "Nguyen Van A");
	sv1.set_Diemly(8);  // Điểm là số nguyên
	
	SinhVien<int> sv2(124, "Tran Thi B");
	sv2.set_Diemly(9);
	
	ds_int.push_back(sv1);
	ds_int.push_back(sv2);
	
	in(ds_int, "int");
	
	// Tính điểm trung bình với int
	cout << "\nDiem trung binh cua sinh vien A: " << sv1.tinhTrungBinh(7, 8) << endl;
	
	// 2. Sử dụng với kiểu FLOAT
	cout << "\n2. SU DUNG VOI KIEU FLOAT:" << endl;
	list<SinhVien<float>> ds_float;
	
	SinhVien<float> sv3(125, "Le Van C");
	sv3.set_Diemly(8.5);  // Điểm có thể là số thập phân
	
	SinhVien<float> sv4(126, "Pham Thi D");
	sv4.set_Diemly(9.25);
	
	ds_float.push_back(sv3);
	ds_float.push_back(sv4);
	
	in(ds_float, "float");
	
	// Tính điểm trung bình với float
	cout << "\nDiem trung binh cua sinh vien C: " << sv3.tinhTrungBinh(7.5, 8.0) << endl;
	
	// 3. Sử dụng với kiểu DOUBLE
	cout << "\n3. SU DUNG VOI KIEU DOUBLE:" << endl;
	list<SinhVien<double>> ds_double;
	
	SinhVien<double> sv5(127, "Hoang Van E");
	sv5.set_Diemly(8.75);  // Độ chính xác cao hơn
	
	SinhVien<double> sv6(128, "Vu Thi F");
	sv6.set_Diemly(9.125);
	
	ds_double.push_back(sv5);
	ds_double.push_back(sv6);
	
	in(ds_double, "double");
	
	// Tính điểm trung bình với double
	cout << "\nDiem trung binh cua sinh vien E: " << sv5.tinhTrungBinh(7.75, 8.25) << endl;
	
	// 4. Demo so sánh kích thước dữ liệu
	cout << "\n=== SO SANH KICH THUOC DU LIEU ===" << endl;
	cout << "Kich thuoc int: " << sizeof(int) << " bytes" << endl;
	cout << "Kich thuoc float: " << sizeof(float) << " bytes" << endl;
	cout << "Kich thuoc double: " << sizeof(double) << " bytes" << endl;
	
	// 5. Demo với kiểu số nguyên lớn
	cout << "\n=== DEMO VOI KIEU LONG LONG ===" << endl;
	SinhVien<long long> sv7(129, "Nguyen Van G");
	sv7.set_Diemly(1000000000);  // Số rất lớn
	cout << "Sinh vien G co diem: " << sv7.get_Diemly() << endl;
	
	// 6. Demo với kiểu số không dấu
	cout << "\n=== DEMO VOI KIEU UNSIGNED INT ===" << endl;
	SinhVien<unsigned int> sv8(130, "Tran Van H");
	sv8.set_Diemly(10);  // Chỉ số dương
	cout << "Sinh vien H co diem: " << sv8.get_Diemly() << endl;
	
	return 0;
}

