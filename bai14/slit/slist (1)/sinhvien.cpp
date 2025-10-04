/*
 * =====================================================================================
 * FILE: sinhvien.cpp
 * MÔ TẢ: Implementation file cho class SinhVien
 * TÁC GIẢ: AI Assistant
 * NGÀY TẠO: 2025
 * =====================================================================================
 * 
 * NỘI DUNG:
 * - Định nghĩa tất cả các phương thức đã khai báo trong sinhvien.h
 * - Xử lý logic nghiệp vụ cho class SinhVien
 * - Kiểm tra tính hợp lệ của dữ liệu
 * - Cung cấp giao diện tương tác với người dùng
 */

#include"sinhvien.h"  // Include header file để có thể sử dụng các khai báo

// ==================== CONSTRUCTOR & DESTRUCTOR ====================

/*
 * CONSTRUCTOR MẶC ĐỊNH
 * Mục đích: Khởi tạo đối tượng SinhVien với các giá trị mặc định
 * Sử dụng: Khi tạo đối tượng mà chưa có dữ liệu cụ thể
 */
SinhVien::SinhVien(){
	MaSV = 0;        // Mã sinh viên mặc định = 0
	Hoten = "";      // Họ tên rỗng
	Ngay = 1;        // Ngày mặc định = 1
	Thang = 1;       // Tháng mặc định = 1
	Nam = 2000;      // Năm mặc định = 2000
	GioiTinh = "";   // Giới tính rỗng
	QueQuan = "";    // Quê quán rỗng
}

/*
 * CONSTRUCTOR VỚI THAM SỐ
 * Mục đích: Khởi tạo đối tượng SinhVien với dữ liệu cụ thể
 * Tham số:
 * - ma: Mã sinh viên
 * - ht: Họ tên
 * - ngay, thang, nam: Ngày tháng năm sinh
 * - gt: Giới tính
 * - qq: Quê quán
 */
SinhVien::SinhVien(int ma, string ht, int ngay, int thang, int nam, string gt, string qq){
	MaSV = ma;        // Gán mã sinh viên
	Hoten = ht;       // Gán họ tên
	Ngay = ngay;      // Gán ngày sinh
	Thang = thang;    // Gán tháng sinh
	Nam = nam;        // Gán năm sinh
	GioiTinh = gt;    // Gán giới tính
	QueQuan = qq;     // Gán quê quán
}

/*
 * DESTRUCTOR
 * Mục đích: Giải phóng bộ nhớ khi đối tượng bị hủy
 * Lưu ý: Class này không sử dụng con trỏ nên không cần delete
 */
SinhVien::~SinhVien(){
	// Không cần giải phóng bộ nhớ vì không có con trỏ
	// Các biến string sẽ tự động được giải phóng
}

/*
 * COPY CONSTRUCTOR
 * Mục đích: Tạo bản sao từ đối tượng SinhVien khác
 * Tham số: sv - đối tượng SinhVien cần sao chép
 * Sử dụng: Khi truyền đối tượng theo giá trị hoặc khởi tạo từ đối tượng khác
 */
SinhVien::SinhVien(const SinhVien &sv){
	MaSV = sv.MaSV;        // Sao chép mã sinh viên
	Hoten = sv.Hoten;      // Sao chép họ tên
	Ngay = sv.Ngay;        // Sao chép ngày sinh
	Thang = sv.Thang;      // Sao chép tháng sinh
	Nam = sv.Nam;          // Sao chép năm sinh
	GioiTinh = sv.GioiTinh; // Sao chép giới tính
	QueQuan = sv.QueQuan;  // Sao chép quê quán
}

/*
 * ASSIGNMENT OPERATOR (TOÁN TỬ GÁN)
 * Mục đích: Gán dữ liệu từ đối tượng SinhVien khác
 * Tham số: sv - đối tượng SinhVien cần gán
 * Trả về: Tham chiếu đến đối tượng hiện tại (để có thể chain assignment)
 * Lưu ý: Kiểm tra self-assignment để tránh gán chính nó
 */
SinhVien& SinhVien::operator=(const SinhVien &sv){
	if(this != &sv){        // Kiểm tra không phải gán chính nó
		MaSV = sv.MaSV;        // Gán mã sinh viên
		Hoten = sv.Hoten;      // Gán họ tên
		Ngay = sv.Ngay;        // Gán ngày sinh
		Thang = sv.Thang;      // Gán tháng sinh
		Nam = sv.Nam;          // Gán năm sinh
		GioiTinh = sv.GioiTinh; // Gán giới tính
		QueQuan = sv.QueQuan;  // Gán quê quán
	}
	return *this;           // Trả về tham chiếu đến đối tượng hiện tại
}

// ==================== GETTER METHODS ====================
// Các phương thức lấy dữ liệu - chỉ đọc, không thay đổi đối tượng

/*
 * GETTER CHO MÃ SINH VIÊN
 * Mục đích: Lấy mã sinh viên
 * Trả về: int - mã sinh viên
 * const: Đảm bảo không thay đổi đối tượng
 */
int SinhVien::getMaSV() const{
	return MaSV;  // Trả về mã sinh viên
}

/*
 * GETTER CHO HỌ TÊN
 * Mục đích: Lấy họ tên sinh viên
 * Trả về: string - họ tên
 */
string SinhVien::getHoten() const{
	return Hoten;  // Trả về họ tên
}

/*
 * GETTER CHO NGÀY SINH
 * Mục đích: Lấy ngày sinh
 * Trả về: int - ngày sinh (1-31)
 */
int SinhVien::getNgay() const{
	return Ngay;  // Trả về ngày sinh
}

/*
 * GETTER CHO THÁNG SINH
 * Mục đích: Lấy tháng sinh
 * Trả về: int - tháng sinh (1-12)
 */
int SinhVien::getThang() const{
	return Thang;  // Trả về tháng sinh
}

/*
 * GETTER CHO NĂM SINH
 * Mục đích: Lấy năm sinh
 * Trả về: int - năm sinh
 */
int SinhVien::getNam() const{
	return Nam;  // Trả về năm sinh
}

/*
 * GETTER CHO GIỚI TÍNH
 * Mục đích: Lấy giới tính
 * Trả về: string - giới tính
 */
string SinhVien::getGioiTinh() const{
	return GioiTinh;  // Trả về giới tính
}

/*
 * GETTER CHO QUÊ QUÁN
 * Mục đích: Lấy quê quán
 * Trả về: string - quê quán
 */
string SinhVien::getQueQuan() const{
	return QueQuan;  // Trả về quê quán
}

// ==================== SETTER METHODS ====================
// Các phương thức thay đổi dữ liệu - có thể sửa đổi đối tượng

/*
 * SETTER CHO MÃ SINH VIÊN
 * Mục đích: Đặt mã sinh viên mới
 * Tham số: ma - mã sinh viên mới
 */
void SinhVien::setMaSV(int ma){
	MaSV = ma;  // Gán mã sinh viên mới
}

/*
 * SETTER CHO HỌ TÊN
 * Mục đích: Đặt họ tên mới
 * Tham số: ht - họ tên mới
 */
void SinhVien::setHoten(string ht){
	Hoten = ht;  // Gán họ tên mới
}

/*
 * SETTER CHO NGÀY SINH
 * Mục đích: Đặt ngày sinh mới
 * Tham số: ngay - ngày sinh mới (1-31)
 * Lưu ý: Nên kiểm tra tính hợp lệ trước khi gán
 */
void SinhVien::setNgay(int ngay){
	Ngay = ngay;  // Gán ngày sinh mới
}

/*
 * SETTER CHO THÁNG SINH
 * Mục đích: Đặt tháng sinh mới
 * Tham số: thang - tháng sinh mới (1-12)
 * Lưu ý: Nên kiểm tra tính hợp lệ trước khi gán
 */
void SinhVien::setThang(int thang){
	Thang = thang;  // Gán tháng sinh mới
}

/*
 * SETTER CHO NĂM SINH
 * Mục đích: Đặt năm sinh mới
 * Tham số: nam - năm sinh mới
 * Lưu ý: Nên kiểm tra tính hợp lệ trước khi gán
 */
void SinhVien::setNam(int nam){
	Nam = nam;  // Gán năm sinh mới
}

/*
 * SETTER CHO GIỚI TÍNH
 * Mục đích: Đặt giới tính mới
 * Tham số: gt - giới tính mới
 */
void SinhVien::setGioiTinh(string gt){
	GioiTinh = gt;  // Gán giới tính mới
}

/*
 * SETTER CHO QUÊ QUÁN
 * Mục đích: Đặt quê quán mới
 * Tham số: qq - quê quán mới
 */
void SinhVien::setQueQuan(string qq){
	QueQuan = qq;  // Gán quê quán mới
}

// ==================== PHƯƠNG THỨC CHỨC NĂNG ====================

/*
 * KIỂM TRA TÍNH HỢP LỆ CỦA NGÀY SINH
 * Mục đích: Kiểm tra ngày sinh có hợp lệ hay không
 * Trả về: true nếu hợp lệ, false nếu không hợp lệ
 * Kiểm tra:
 * - Năm: từ 1900 đến 2024
 * - Tháng: từ 1 đến 12
 * - Ngày: theo từng tháng (có xét năm nhuận)
 * 
 * Logic kiểm tra năm nhuận:
 * - Năm chia hết cho 4 và không chia hết cho 100
 * - Hoặc năm chia hết cho 400
 */
bool SinhVien::kiemTraNgaySinh() const{
	// Kiểm tra năm - phải từ 1900 đến 2024
	if(Nam < 1900 || Nam > 2024) return false;
	
	// Kiểm tra tháng - phải từ 1 đến 12
	if(Thang < 1 || Thang > 12) return false;
	
	// Kiểm tra ngày cơ bản - phải từ 1 đến 31
	if(Ngay < 1 || Ngay > 31) return false;
	
	// Kiểm tra ngày theo từng tháng
	if(Thang == 2){
		// Tháng 2 - xét năm nhuận
		if((Nam % 4 == 0 && Nam % 100 != 0) || (Nam % 400 == 0)){
			// Năm nhuận - tháng 2 có tối đa 29 ngày
			if(Ngay > 29) return false;
		} else {
			// Năm không nhuận - tháng 2 có tối đa 28 ngày
			if(Ngay > 28) return false;
		}
	} else if(Thang == 4 || Thang == 6 || Thang == 9 || Thang == 11){
		// Tháng 4, 6, 9, 11 - có tối đa 30 ngày
		if(Ngay > 30) return false;
	}
	// Các tháng khác (1, 3, 5, 7, 8, 10, 12) có 31 ngày - đã kiểm tra ở trên
	
	return true;  // Ngày sinh hợp lệ
}

/*
 * NHẬP THÔNG TIN SINH VIÊN TỪ BÀN PHÍM
 * Mục đích: Cho phép người dùng nhập thông tin sinh viên từ bàn phím
 * Quy trình:
 * 1. Nhập mã sinh viên (số nguyên)
 * 2. Nhập họ tên (chuỗi ký tự)
 * 3. Nhập ngày sinh với kiểm tra tính hợp lệ
 * 4. Nhập giới tính (chuỗi ký tự)
 * 5. Nhập quê quán (chuỗi ký tự)
 * 
 * Lưu ý: Sử dụng cin.ignore() để xử lý ký tự xuống dòng
 */
void SinhVien::nhapThongTin(){
	// Nhập mã sinh viên
	cout << "Nhap ma sinh vien: ";
	cin >> MaSV;
	cin.ignore(); // Xóa ký tự xuống dòng còn sót lại trong buffer
	
	// Nhập họ tên
	cout << "Nhap ho ten: ";
	getline(cin, Hoten); // Sử dụng getline để đọc cả dòng (bao gồm khoảng trắng)
	
	// Nhập ngày sinh với kiểm tra tính hợp lệ
	do{
		cout << "Nhap ngay sinh: ";
		cin >> Ngay;
		cout << "Nhap thang sinh: ";
		cin >> Thang;
		cout << "Nhap nam sinh: ";
		cin >> Nam;
		
		// Kiểm tra tính hợp lệ của ngày sinh
		if(!kiemTraNgaySinh()){
			cout << "Ngay sinh khong hop le! Vui long nhap lai.\n";
		}
	} while(!kiemTraNgaySinh()); // Lặp lại nếu ngày sinh không hợp lệ
	
	cin.ignore(); // Xóa ký tự xuống dòng còn sót lại
	
	// Nhập giới tính
	cout << "Nhap gioi tinh: ";
	getline(cin, GioiTinh);
	
	// Nhập quê quán
	cout << "Nhap que quan: ";
	getline(cin, QueQuan);
}

/*
 * XUẤT THÔNG TIN SINH VIÊN RA MÀN HÌNH
 * Mục đích: Hiển thị thông tin sinh viên theo định dạng cố định
 * Format: MaSV | HoTen | Ngay/Thang/Nam | GioiTinh | QueQuan
 * const: Đảm bảo không thay đổi đối tượng khi xuất thông tin
 */
void SinhVien::xuatThongTin() const{
	cout << MaSV << "\t" << Hoten << "\t" 
		 << Ngay << "/" << Thang << "/" << Nam << "\t" 
		 << GioiTinh << "\t" << QueQuan << endl;
}

/*
 * TÍNH TUỔI SINH VIÊN
 * Mục đích: Tính tuổi dựa trên năm sinh và năm hiện tại
 * Trả về: int - tuổi của sinh viên
 * Lưu ý: Năm hiện tại được hard-code, nên cải thiện bằng thư viện time
 */
int SinhVien::tinhTuoi() const{
	int namHienTai = 2024; // Năm hiện tại (có thể cải thiện bằng time.h)
	return namHienTai - Nam; // Tuổi = năm hiện tại - năm sinh
}

// ==================== OPERATOR OVERLOADING ====================

/*
 * OPERATOR SO SÁNH BẰNG (==)
 * Mục đích: So sánh hai đối tượng SinhVien có giống nhau không
 * Tham số: sv - đối tượng SinhVien cần so sánh
 * Trả về: true nếu tất cả thuộc tính giống nhau, false nếu khác nhau
 * Logic: So sánh tất cả các thuộc tính của hai đối tượng
 */
bool SinhVien::operator==(const SinhVien &sv) const{
	return (MaSV == sv.MaSV && Hoten == sv.Hoten && 
			Ngay == sv.Ngay && Thang == sv.Thang && Nam == sv.Nam &&
			GioiTinh == sv.GioiTinh && QueQuan == sv.QueQuan);
}

/*
 * OPERATOR SO SÁNH KHÁC (!=)
 * Mục đích: So sánh hai đối tượng SinhVien có khác nhau không
 * Tham số: sv - đối tượng SinhVien cần so sánh
 * Trả về: true nếu khác nhau, false nếu giống nhau
 * Logic: Sử dụng operator == và phủ định kết quả
 */
bool SinhVien::operator!=(const SinhVien &sv) const{
	return !(*this == sv); // Phủ định của operator ==
}
