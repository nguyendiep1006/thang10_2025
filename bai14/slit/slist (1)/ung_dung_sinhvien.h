#ifndef UNG_DUNG_SINHVIEN_H
#define UNG_DUNG_SINHVIEN_H

#include<iostream>
#include<string>
using namespace std;

/*
 * =====================================================================================
 * FILE: ung_dung_sinhvien.h
 * MÔ TẢ: Header file cho lớp ứng dụng quản lý sinh viên sử dụng danh sách liên kết đơn
 * TÁC GIẢ: AI Assistant
 * NGÀY TẠO: 2025
 * =====================================================================================
 * 
 * LỚP UNGDUNGSINHVIEN - LỚP ỨNG DỤNG QUẢN LÝ SINH VIÊN
 * 
 * MỤC ĐÍCH:
 * - Xây dựng lớp ứng dụng sử dụng danh sách liên kết đơn để lưu trữ sinh viên
 * - Cung cấp giao diện thân thiện để thao tác với danh sách sinh viên
 * - Quản lý thông tin sinh viên: MaSV, Hoten, Ngay, Thang, Nam sinh, gioi tinh, que quan
 * 
 * CÁC CHỨC NĂNG CHÍNH:
 * - Thêm sinh viên vào cuối danh sách
 * - Thêm sinh viên vào đầu danh sách  
 * - Xóa sinh viên thứ i khỏi danh sách
 * - Thay thế sinh viên thứ i bằng sinh viên mới
 * 
 * CÁC CHỨC NĂNG BỔ SUNG:
 * - Hiển thị danh sách sinh viên
 * - Tìm kiếm sinh viên theo mã
 * - Đếm số lượng sinh viên
 * - Menu tương tác với người dùng
 * - Nhập/xuất dữ liệu từ file
 */

// Khai báo trước class SinhVien
class SinhVien {
private:
    int MaSV;        // Mã sinh viên
    string Hoten;    // Họ tên
    int Ngay;        // Ngày sinh
    int Thang;       // Tháng sinh
    int Nam;         // Năm sinh
    string GioiTinh; // Giới tính
    string QueQuan;  // Quê quán
    
public:
    // Constructor
    SinhVien();
    SinhVien(int ma, string ht, int ngay, int thang, int nam, string gt, string qq);
    
    // Getter methods
    // const ở đây có nghĩa là các phương thức này không thay đổi dữ liệu của đối tượng
    // Nó đảm bảo tính toàn vẹn dữ liệu khi gọi các hàm getter
    int getMaSV() const;      // Trả về mã sinh viên, không thay đổi dữ liệu
    string getHoten() const;  // Trả về họ tên, không thay đổi dữ liệu  
    int getNgay() const;      // Trả về ngày sinh, không thay đổi dữ liệu
    int getThang() const;     // Trả về tháng sinh, không thay đổi dữ liệu
    int getNam() const;       // Trả về năm sinh, không thay đổi dữ liệu
    string getGioiTinh() const; // Trả về giới tính, không thay đổi dữ liệu
    string getQueQuan() const;
    
    // Setter methods
    void setMaSV(int ma);
    void setHoten(string ht);
    void setNgay(int ngay);
    void setThang(int thang);
    void setNam(int nam);
    void setGioiTinh(string gt);
    void setQueQuan(string qq);
    
    // Methods
    void nhapThongTin();
    void xuatThongTin() const;
    bool kiemTraNgaySinh() const;
    int tinhTuoi() const;
    bool operator==(const SinhVien &sv) const; // Toán tử so sánh bằng để kiểm tra hai sinh viên có giống nhau không
 };

// Khai báo trước class Node
class Node {
private:
    SinhVien data;
    Node* next;
    
public:
    Node();
    Node(SinhVien sv);
    ~Node();
    
    SinhVien getData() const;
    Node* getNext() const;
    void setData(SinhVien sv);
    void setNext(Node* n);
    void khoiTaoNode(SinhVien sv);
};

// Lớp ứng dụng chính
class UngDungSinhVien {
private:
    Node* head;  // Con trỏ đến node đầu tiên
    Node* tail;  // Con trỏ đến node cuối cùng
    int size;    // Số lượng sinh viên
    
    // Các phương thức hỗ trợ private
    Node* layNodeTaiViTri(int viTri) const;
    void giaiPhongBoNho();
    void saoChepDanhSach(const UngDungSinhVien &app);
    bool kiemTraViTriHopLe(int viTri) const;
    void hienThiTieuDe() const;
    void hienThiSinhVien(const SinhVien &sv, int stt) const;
    
public:
    // ==================== CONSTRUCTOR & DESTRUCTOR ====================
    
    // Constructor mặc định
    UngDungSinhVien();
    
    // Destructor
    ~UngDungSinhVien();
    
    // Copy constructor
    // Copy constructor - tạo một bản sao của đối tượng UngDungSinhVien
    // Tham số app là tham chiếu hằng đến đối tượng cần sao chép
    // Được gọi khi khởi tạo một đối tượng mới từ đối tượng đã tồn tại
    // Ví dụ: UngDungSinhVien app2(app1);
    UngDungSinhVien(const UngDungSinhVien &app);
    
    // Assignment operator
    // Toán tử gán (assignment operator) - gán dữ liệu từ một đối tượng UngDungSinhVien khác
    // Tham số app là tham chiếu hằng đến đối tượng cần sao chép dữ liệu
    // Trả về tham chiếu đến đối tượng hiện tại (*this) để hỗ trợ phép gán liên tiếp
    // Ví dụ: app1 = app2 = app3;
    // Được gọi khi thực hiện phép gán giữa 2 đối tượng đã tồn tại
    // Ví dụ: app1 = app2;
    UngDungSinhVien& operator=(const UngDungSinhVien &app);
    
    // ==================== CÁC CHỨC NĂNG CHÍNH YÊU CẦU ====================
    
    // 1. Thêm sinh viên vào cuối danh sách
    bool themVaoCuoi();
    
    // 2. Thêm sinh viên vào đầu danh sách
    bool themVaoDau();
    
    // 3. Xóa sinh viên thứ i khỏi danh sách
    bool xoaSinhVien(int viTri);
    
    // 4. Thay thế sinh viên thứ i bằng sinh viên mới
    bool thayTheSinhVien(int viTri);
    
    // ==================== CÁC CHỨC NĂNG BỔ SUNG ====================
    
    // Hiển thị toàn bộ danh sách sinh viên
    void hienThiDanhSach() const;
    
    // Tìm kiếm sinh viên theo mã
    void timKiemSinhVien() const;
    
    // Đếm số lượng sinh viên
    int demSoLuong() const;
    
    // Kiểm tra danh sách rỗng
    bool kiemTraRong() const;
    
    // Lấy sinh viên tại vị trí i
    SinhVien laySinhVien(int viTri) const;
    
    // Xóa toàn bộ danh sách
    void xoaToanBo();
    
    // Thêm sinh viên tại vị trí i
    bool themTaiViTri(int viTri);
    
    // ==================== GIAO DIỆN NGƯỜI DÙNG ====================
    
    // Hiển thị menu chính
    void hienThiMenu() const;
    
    // Xử lý lựa chọn từ menu
    void xuLyLuaChon(int luaChon);
    
    // Chạy ứng dụng
    void chayUngDung();
    
    // ==================== QUẢN LÝ DỮ LIỆU ====================
    
    // Tạo dữ liệu mẫu
    void taoDuLieuMau();
    
    // Nhập danh sách sinh viên từ bàn phím
    void nhapDanhSach();
    
    // Xuất danh sách ra file
    void xuatRaFile(const string &tenFile) const;
    
    // Nhập danh sách từ file
    void nhapTuFile(const string &tenFile);
    
    // ==================== THỐNG KÊ ====================
    
    // Thống kê theo giới tính
    void thongKeTheoGioiTinh() const;
    
    // Thống kê theo quê quán
    void thongKeTheoQueQuan() const;
    
    // Hiển thị sinh viên có tuổi lớn nhất
    void hienThiSinhVienLonTuoi() const;
    
    // Hiển thị sinh viên có tuổi nhỏ nhất
    void hienThiSinhVienNhoTuoi() const;
};

#endif
