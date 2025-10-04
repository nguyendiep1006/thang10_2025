#include"sinhvien.h"

// Constructor mặc định
SinhVien::SinhVien(){
	MaSV = 0;
	Hoten = "";
	Ngay = 1;
	Thang = 1;
	Nam = 2000;
	GioiTinh = "";
	QueQuan = "";
}

// Constructor với tham số
SinhVien::SinhVien(int ma, string ht, int ngay, int thang, int nam, string gt, string qq){
	MaSV = ma;
	Hoten = ht;
	Ngay = ngay;
	Thang = thang;
	Nam = nam;
	GioiTinh = gt;
	QueQuan = qq;
}

// Destructor
SinhVien::~SinhVien(){
	// Không cần giải phóng bộ nhớ vì không có con trỏ
}

// Copy constructor
SinhVien::SinhVien(const SinhVien &sv){
	MaSV = sv.MaSV;
	Hoten = sv.Hoten;
	Ngay = sv.Ngay;
	Thang = sv.Thang;
	Nam = sv.Nam;
	GioiTinh = sv.GioiTinh;
	QueQuan = sv.QueQuan;
}

// Assignment operator
SinhVien& SinhVien::operator=(const SinhVien &sv){
	if(this != &sv){
		MaSV = sv.MaSV;
		Hoten = sv.Hoten;
		Ngay = sv.Ngay;
		Thang = sv.Thang;
		Nam = sv.Nam;
		GioiTinh = sv.GioiTinh;
		QueQuan = sv.QueQuan;
	}
	return *this;
}

// Getter methods
int SinhVien::getMaSV() const{
	return MaSV;
}

string SinhVien::getHoten() const{
	return Hoten;
}

int SinhVien::getNgay() const{
	return Ngay;
}

int SinhVien::getThang() const{
	return Thang;
}

int SinhVien::getNam() const{
	return Nam;
}

string SinhVien::getGioiTinh() const{
	return GioiTinh;
}

string SinhVien::getQueQuan() const{
	return QueQuan;
}

// Setter methods
void SinhVien::setMaSV(int ma){
	MaSV = ma;
}

void SinhVien::setHoten(string ht){
	Hoten = ht;
}

void SinhVien::setNgay(int ngay){
	Ngay = ngay;
}

void SinhVien::setThang(int thang){
	Thang = thang;
}

void SinhVien::setNam(int nam){
	Nam = nam;
}

void SinhVien::setGioiTinh(string gt){
	GioiTinh = gt;
}

void SinhVien::setQueQuan(string qq){
	QueQuan = qq;
}

// Phương thức kiểm tra tính hợp lệ của ngày sinh
bool SinhVien::kiemTraNgaySinh() const{
	// Kiểm tra năm
	if(Nam < 1900 || Nam > 2024) return false;
	
	// Kiểm tra tháng
	if(Thang < 1 || Thang > 12) return false;
	
	// Kiểm tra ngày
	if(Ngay < 1 || Ngay > 31) return false;
	
	// Kiểm tra ngày theo tháng
	if(Thang == 2){
		// Năm nhuận
		if((Nam % 4 == 0 && Nam % 100 != 0) || (Nam % 400 == 0)){
			if(Ngay > 29) return false;
		} else {
			if(Ngay > 28) return false;
		}
	} else if(Thang == 4 || Thang == 6 || Thang == 9 || Thang == 11){
		if(Ngay > 30) return false;
	}
	
	return true;
}

// Phương thức nhập thông tin sinh viên
void SinhVien::nhapThongTin(){
	cout << "Nhap ma sinh vien: ";
	cin >> MaSV;
	cin.ignore(); // Xóa ký tự xuống dòng
	
	cout << "Nhap ho ten: ";
	getline(cin, Hoten);
	
	do{
		cout << "Nhap ngay sinh: ";
		cin >> Ngay;
		cout << "Nhap thang sinh: ";
		cin >> Thang;
		cout << "Nhap nam sinh: ";
		cin >> Nam;
		
		if(!kiemTraNgaySinh()){
			cout << "Ngay sinh khong hop le! Vui long nhap lai.\n";
		}
	} while(!kiemTraNgaySinh());
	
	cin.ignore(); // Xóa ký tự xuống dòng
	
	cout << "Nhap gioi tinh: ";
	getline(cin, GioiTinh);
	
	cout << "Nhap que quan: ";
	getline(cin, QueQuan);
}

// Phương thức xuất thông tin sinh viên
void SinhVien::xuatThongTin() const{
	cout << MaSV << "\t" << Hoten << "\t" 
		 << Ngay << "/" << Thang << "/" << Nam << "\t" 
		 << GioiTinh << "\t" << QueQuan << endl;
}

// Phương thức tính tuổi
int SinhVien::tinhTuoi() const{
	// Lấy năm hiện tại (có thể cải thiện bằng cách sử dụng thư viện time)
	int namHienTai = 2024;
	return namHienTai - Nam;
}

// Operator so sánh
bool SinhVien::operator==(const SinhVien &sv) const{
	return (MaSV == sv.MaSV && Hoten == sv.Hoten && 
			Ngay == sv.Ngay && Thang == sv.Thang && Nam == sv.Nam &&
			GioiTinh == sv.GioiTinh && QueQuan == sv.QueQuan);
}

bool SinhVien::operator!=(const SinhVien &sv) const{
	return !(*this == sv);
}
