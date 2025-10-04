#include<iostream>
#include<list>
#include<string>
using namespace std;

// Template class có thể dùng với kiểu string
template <class T>
class SinhVien{
	private:
		int masv;        // Mã sinh viên luôn là int
		string hoten;    // Họ tên luôn là string
		T diemly;        // Điểm dùng template T (có thể là string)
	public:
		// Constructor
		SinhVien(int m = 0, string ht = ""){
			masv = m;
			hoten = ht;
		}
		
		// Phương thức in thông tin
		void In(){
			cout << masv << "\t" << hoten << "\t" << diemly << endl;
		}
		
		// Setter cho điểm (có thể là string)
		void set_Diemly(T d){
			diemly = d;
		}
		
		// Getter cho điểm
		T get_Diemly(){
			return diemly;
		}
		
		// Phương thức kiểm tra điểm (chỉ dùng với string)
		bool kiemTraDiem(){
			if(diemly == "A" || diemly == "B" || diemly == "C" || diemly == "D" || diemly == "F"){
				return true;
			}
			return false;
		}
		
		// Phương thức chuyển đổi điểm chữ thành số
		float chuyenDoiDiem(){
			if(diemly == "A") return 4.0;
			if(diemly == "B") return 3.0;
			if(diemly == "C") return 2.0;
			if(diemly == "D") return 1.0;
			if(diemly == "F") return 0.0;
			return -1; // Điểm không hợp lệ
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
	cout << "=== DEMO TEMPLATE VOI KIEU STRING ===" << endl;
	
	// 1. Sử dụng với kiểu STRING (điểm chữ)
	cout << "\n1. SU DUNG VOI KIEU STRING - DIEM CHU:" << endl;
	list<SinhVien<string>> ds_string;
	
	SinhVien<string> sv1(123, "Nguyen Van A");
	sv1.set_Diemly("A");  // Điểm là chữ cái
	
	SinhVien<string> sv2(124, "Tran Thi B");
	sv2.set_Diemly("B");
	
	SinhVien<string> sv3(125, "Le Van C");
	sv3.set_Diemly("C");
	
	SinhVien<string> sv4(126, "Pham Thi D");
	sv4.set_Diemly("A");
	
	ds_string.push_back(sv1);
	ds_string.push_back(sv2);
	ds_string.push_back(sv3);
	ds_string.push_back(sv4);
	
	in(ds_string, "string");
	
	// Kiểm tra và chuyển đổi điểm
	cout << "\n=== KIEM TRA VA CHUYEN DOI DIEM ===" << endl;
	for(typename list<SinhVien<string>>::iterator it = ds_string.begin(); it != ds_string.end(); it++){
		cout << "Sinh vien " << (*it).get_Diemly();
		if((*it).kiemTraDiem()){
			cout << " - Hop le - Diem so: " << (*it).chuyenDoiDiem() << endl;
		} else {
			cout << " - Khong hop le" << endl;
		}
	}
	
	// 2. Demo với string mô tả chi tiết
	cout << "\n2. SU DUNG VOI STRING MO TA CHI TIET:" << endl;
	list<SinhVien<string>> ds_mota;
	
	SinhVien<string> sv5(127, "Hoang Van E");
	sv5.set_Diemly("Xuat sac");
	
	SinhVien<string> sv6(128, "Vu Thi F");
	sv6.set_Diemly("Gioi");
	
	SinhVien<string> sv7(129, "Nguyen Van G");
	sv7.set_Diemly("Kha");
	
	SinhVien<string> sv8(130, "Tran Thi H");
	sv8.set_Diemly("Trung binh");
	
	ds_mota.push_back(sv5);
	ds_mota.push_back(sv6);
	ds_mota.push_back(sv7);
	ds_mota.push_back(sv8);
	
	in(ds_mota, "string (mo ta)");
	
	// 3. Demo với string điểm số dạng text
	cout << "\n3. SU DUNG VOI STRING DIEM SO:" << endl;
	list<SinhVien<string>> ds_diem_text;
	
	SinhVien<string> sv9(131, "Le Van I");
	sv9.set_Diemly("9.5/10");
	
	SinhVien<string> sv10(132, "Pham Thi J");
	sv10.set_Diemly("8.0/10");
	
	SinhVien<string> sv11(133, "Hoang Van K");
	sv11.set_Diemly("7.5/10");
	
	ds_diem_text.push_back(sv9);
	ds_diem_text.push_back(sv10);
	ds_diem_text.push_back(sv11);
	
	in(ds_diem_text, "string (diem so)");
	
	// 4. Demo so sánh với các kiểu khác
	cout << "\n=== SO SANH VOI CAC KIEU KHAC ===" << endl;
	
	// Sử dụng với float
	SinhVien<float> sv_float(134, "Nguyen Van L");
	sv_float.set_Diemly(8.5);
	cout << "Sinh vien float: " << sv_float.get_Diemly() << endl;
	
	// Sử dụng với int
	SinhVien<int> sv_int(135, "Tran Thi M");
	sv_int.set_Diemly(85);
	cout << "Sinh vien int: " << sv_int.get_Diemly() << endl;
	
	// Sử dụng với string
	SinhVien<string> sv_str(136, "Le Van N");
	sv_str.set_Diemly("8.5");
	cout << "Sinh vien string: " << sv_str.get_Diemly() << endl;
	
	// 5. Demo tìm kiếm trong danh sách string
	cout << "\n=== TIM KIEM SINH VIEN CO DIEM A ===" << endl;
	for(typename list<SinhVien<string>>::iterator it = ds_string.begin(); it != ds_string.end(); it++){
		if((*it).get_Diemly() == "A"){
			cout << "Tim thay sinh vien co diem A: ";
			(*it).In();
		}
	}
	
	return 0;
}
