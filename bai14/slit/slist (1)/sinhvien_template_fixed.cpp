#include<iostream>
#include<list>
#include<string>
using namespace std;

template <class T>
class SinhVien{
	private:
		int masv;        // Mã sinh viên luôn là int
		string hoten;    // Họ tên luôn là string
		T diemly;        // Chỉ điểm mới dùng template
	public:
		// Constructor với tham số mặc định
		SinhVien(int m = 0, string ht = ""){
			masv = m;
			hoten = ht;
			diemly = 0; // Khởi tạo điểm lý thuyết
		}
		
		// Phương thức in thông tin sinh viên
		void In(){
			cout << masv << "\t" << hoten << "\t" << diemly << endl;
		}
		
		// Setter cho điểm lý thuyết
		void set_Diemly(T d){
			if(d >= 0 && d <= 10)
				diemly = d;
			else
				cout << "Loi: Diem phai trong khoang [0,10]" << endl;
		}
		
		// Getter cho điểm lý thuyết - trả về giá trị, không phải con trỏ
		T get_Diemly(){
			return diemly;
		}
};

// Template function để in danh sách sinh viên
template <class T>
void in(list<SinhVien<T>> &l)
{
	cout << "Danh sach sinh vien:" << endl;
	cout << "MaSV\tHo Ten\tDiem Ly" << endl;
	cout << "------------------------" << endl;
	for(typename list<SinhVien<T>>::iterator it = l.begin(); it != l.end(); it++){
		(*it).In();
	}
}

int main(){
	// Tạo danh sách sinh viên với kiểu float cho điểm
	list<SinhVien<float>> ds_sinhvien;
	
	// Tạo các đối tượng sinh viên
	SinhVien<float> sv1(123, "Nguyen Van A");
	sv1.set_Diemly(8.5);
	
	SinhVien<float> sv2(124, "Tran Thi B");
	sv2.set_Diemly(9.0);
	
	SinhVien<float> sv3(125, "Le Van C");
	sv3.set_Diemly(7.5);
	
	// Thêm sinh viên vào danh sách
	ds_sinhvien.push_back(sv1);
	ds_sinhvien.push_back(sv2);
	ds_sinhvien.push_back(sv3);
	
	// In danh sách sinh viên
	in(ds_sinhvien);
	
	// Demo thêm một số thao tác khác
	cout << "\n=== DEMO CAC THAO TAC KHAC ===" << endl;
	
	// Chèn sinh viên mới vào vị trí thứ 2
	SinhVien<float> sv4(126, "Pham Thi D");
	sv4.set_Diemly(8.0);
	
	typename list<SinhVien<float>>::iterator it = ds_sinhvien.begin();
	it++; // Di chuyển đến vị trí thứ 2
	ds_sinhvien.insert(it, sv4);
	
	cout << "\nDanh sach sau khi chen sinh vien moi:" << endl;
	in(ds_sinhvien);
	
	// Xóa sinh viên đầu tiên
	ds_sinhvien.pop_front();
	cout << "\nDanh sach sau khi xoa sinh vien dau tien:" << endl;
	in(ds_sinhvien);
	
	// Tìm và hiển thị sinh viên có điểm cao nhất
	typename list<SinhVien<float>>::iterator max_it = ds_sinhvien.begin();
	typename list<SinhVien<float>>::iterator current_it = ds_sinhvien.begin();
	
	for(current_it = ds_sinhvien.begin(); current_it != ds_sinhvien.end(); current_it++){
		if((*current_it).get_Diemly() > (*max_it).get_Diemly()){
			max_it = current_it;
		}
	}
	
	cout << "\nSinh vien co diem cao nhat:" << endl;
	(*max_it).In();
	
	return 0;
}
