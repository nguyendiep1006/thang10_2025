#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Lớp Student để lưu trữ thông tin sinh viên
class Student{
    private:
        // Các thuộc tính của sinh viên
        string maSv;      // Mã số sinh viên
        string hoTen;     // Họ tên sinh viên  
        int ngay;        // Ngày sinh
        int thang;       // Tháng sinh
        int nam;         // Năm sinh
        string gioiTinh; // Giới tính
        string queQuan;  // Quê quán
    
    public:
        // Các phương thức của lớp
        // Hàm khởi tạo mặc định - thiết lập giá trị ban đầu
        Student(){
            maSv = "";      // Khởi tạo mã số rỗng
            hoTen = "";     // Khởi tạo họ tên rỗng
            ngay = 1;       // Ngày mặc định là 1
            thang = 1;      // Tháng mặc định là 1
            nam = 2000;     // Năm mặc định là 2000
            gioiTinh = "";  // Khởi tạo giới tính rỗng
            queQuan = "";   // Khởi tạo quê quán rỗng
        }
        
        // Hàm khởi tạo có tham số
        Student(string ma, string ten, int d, int m, int y, string gt, string qq){
            maSv = ma;
            hoTen = ten;
            ngay = d;
            thang = m;
            nam = y;
            gioiTinh = gt;
            queQuan = qq;
        } 
        
        // Các hàm getter
        string getMaSv() { return maSv; }
        string getHoTen() { return hoTen; }
        int getNgay() { return ngay; }
        int getThang() { return thang; }
        int getNam() { return nam; }
        string getGioiTinh() { return gioiTinh; }
        string getQueQuan() { return queQuan; }
        
        // Các hàm setter
        void setMaSv(string ma) { maSv = ma; }
        void setHoTen(string ten) { hoTen = ten; }
        void setNgay(int d) { ngay = d; }
        void setThang(int m) { thang = m; }
        void setNam(int y) { nam = y; }
        void setGioiTinh(string gt) { gioiTinh = gt; }  
        void setQueQuan(string qq) { queQuan = qq; }
        
        // Hàm hiển thị thông tin sinh viên
        void hienThi(){
            cout << "MSSV: " << maSv << " | ";
            cout << "Ho ten: " << hoTen << " | ";
            cout << "Ngay sinh: " << ngay << "/" << thang << "/" << nam << " | ";
            cout << "Gioi tinh: " << gioiTinh << " | ";
            cout << "Que quan: " << queQuan << endl;
        }
        
        // Hàm nhập thông tin sinh viên từ bàn phím
        void nhap(){
            cout << "Nhap MSSV: ";
            cin.ignore();
            getline(cin, maSv);
            cout << "Nhap ho ten: ";
            getline(cin, hoTen);
            cout << "Nhap ngay sinh: ";
            cin >> ngay;
            cout << "Nhap thang sinh: ";
            cin >> thang;
            cout << "Nhap nam sinh: ";
            cin >> nam;
            cout << "Nhap gioi tinh: ";
            cin.ignore();
            getline(cin, gioiTinh);
            cout << "Nhap que quan: ";
            getline(cin, queQuan);
        }
};

// Lớp StudentNode để tạo node trong danh sách liên kết
// (Bỏ dùng Node liên kết đơn; chuyển sang vector<Student>)

// Lớp StudentList để quản lý danh sách sinh viên
class StudentList{
    private:
        vector<Student> ds;
    
    public:
        // Hàm khởi tạo
        StudentList(){}
        
        // Hàm thêm sinh viên vào cuối danh sách
        void themCuoi(Student student){
            ds.push_back(student);
            cout << "Da them sinh vien vao cuoi danh sach!" << endl;
        }
        
        // Hàm thêm sinh viên vào đầu danh sách
        void themDau(Student student){
            ds.insert(ds.begin(), student);
            cout << "Da them sinh vien vao dau danh sach!" << endl;
        }
        
        // Hàm xóa sinh viên thứ i (đếm từ 0)
        // Hàm xóa sinh viên tại vị trí chỉ định (đếm từ 0)
        // Input: viTri - vị trí sinh viên cần xóa
        // Output: true nếu xóa thành công, false nếu thất bại
        bool xoaSinhVien(int viTri){
            // Kiểm tra điều kiện không hợp lệ:
            // - Danh sách rỗng
            // - Vị trí âm (viTri < 0) 
            // - Vị trí vượt quá số lượng (viTri >= ds.size())
            if(ds.empty() || viTri < 0 || viTri >= (int)ds.size()){
                cout << "Vi tri khong hop le hoac danh sach rong!" << endl;
                return false;
            }
            
            ds.erase(ds.begin() + viTri);
            cout << "Da xoa sinh vien tai vi tri " << viTri << "!" << endl;
            return true;
        }
        
        // Hàm thay thế sinh viên thứ i bằng sinh viên mới
        // Hàm thay thế sinh viên tại vị trí chỉ định bằng sinh viên mới
        // Tham số:
        // - viTri: vị trí cần thay thế (0 -> soLuong-1)
        // - studentMoi: đối tượng sinh viên mới để thay thế
        // Trả về: true nếu thay thế thành công, false nếu thất bại
        bool thayTheSinhVien(int viTri, Student studentMoi){
            // Kiểm tra điều kiện không hợp lệ:
            // - Danh sách rỗng
            // - Vị trí âm (viTri < 0)
            // - Vị trí vượt quá số lượng (viTri >= ds.size())
            if(ds.empty() || viTri < 0 || viTri >= (int)ds.size()){
                cout << "Vi tri khong hop le hoac danh sach rong!" << endl;
                return false;
            }
            
            ds[viTri] = studentMoi;
            cout << "Da thay the sinh vien tai vi tri " << viTri << "!" << endl;
            return true;
        }
        
        // Hàm hiển thị toàn bộ danh sách sinh viên ra màn hình
        void hienThiDanhSach(){
            // Kiểm tra danh sách rỗng
            if(ds.empty()){
                cout << "Danh sach sinh vien rong!" << endl;
                return;
            }
            
            // In tiêu đề và thông tin số lượng
            cout << "\n=== DANH SACH SINH VIEN ===" << endl;
            cout << "So luong sinh vien: " << ds.size() << endl;
            cout << "----------------------------------------" << endl;
            
            // Duyệt và hiển thị từng sinh viên trong danh sách
            for(size_t i = 0; i < ds.size(); i++){
                cout << "STT " << i << ": ";
                ds[i].hienThi();
            }
            cout << "----------------------------------------" << endl;
        }
        
        // Hàm tìm kiếm sinh viên theo mã số sinh viên
        // Tham số: maSv - mã số sinh viên cần tìm
        // Trả về: vị trí tìm thấy (0 -> soLuong-1) hoặc -1 nếu không tìm thấy
        int timKiemTheoMSSV(string maSv){
            for(size_t i = 0; i < ds.size(); i++){
                if(ds[i].getMaSv() == maSv) return (int)i;
            }
            return -1; // Không tìm thấy
        }
        
        // Hàm lấy số lượng sinh viên hiện có trong danh sách
        // Trả về: số lượng sinh viên
        int getSoLuong(){
            return (int)ds.size();
        }
        
        // Hàm kiểm tra danh sách có rỗng không
        // Trả về: true nếu danh sách rỗng, false nếu không rỗng
        bool laRong(){
            return ds.empty();
        }
        
        // Hàm tạo sinh viên mẫu để test
        void taoDuLieuMau(){
            Student sv1("SV001", "Nguyen Van A", 15, 3, 2000, "Nam", "Ha Noi");
            Student sv2("SV002", "Tran Thi B", 20, 7, 1999, "Nu", "Ho Chi Minh");
            Student sv3("SV003", "Le Van C", 10, 12, 2001, "Nam", "Da Nang");
            
            themCuoi(sv1);
            themCuoi(sv2);
            themCuoi(sv3);
        }
};

// Hàm hiển thị menu
void hienThiMenu(){
    cout << "\n=== MENU QUAN LY SINH VIEN ===" << endl;
    cout << "1. Them sinh vien vao cuoi danh sach" << endl;
    cout << "2. Them sinh vien vao dau danh sach" << endl;
    cout << "3. Xoa sinh vien tai vi tri i" << endl;
    cout << "4. Thay the sinh vien tai vi tri i" << endl;
    cout << "5. Hien thi danh sach sinh vien" << endl;
    cout << "6. Tim kiem sinh vien theo MSSV" << endl;
    cout << "7. Tao du lieu mau" << endl;
    cout << "8. Kiem tra danh sach rong" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Nhap lua chon: ";
}

int main(){
    StudentList danhSach;
    int luaChon;
    
    cout << "=== CHUONG TRINH QUAN LY SINH VIEN ===" << endl;
    cout << "Su dung danh sach lien ket don" << endl;
    
    do{
        hienThiMenu();
        cin >> luaChon;
        
        switch(luaChon){
            case 1: {
                cout << "\n--- THEM SINH VIEN VAO CUOI DANH SACH ---" << endl;
                Student svMoi;
                svMoi.nhap();
                danhSach.themCuoi(svMoi);
                break;
            }
            
            case 2: {
                cout << "\n--- THEM SINH VIEN VAO DAU DANH SACH ---" << endl;
                Student svMoi;
                svMoi.nhap();
                danhSach.themDau(svMoi);
                break;
            }
            
            case 3: {
                cout << "\n--- XOA SINH VIEN TAI VI TRI i ---" << endl;
                if(danhSach.laRong()){
                    cout << "Danh sach rong, khong the xoa!" << endl;
                }
                else{
                    danhSach.hienThiDanhSach();
                    int viTri;
                    cout << "Nhap vi tri can xoa (tu 0 den " << danhSach.getSoLuong()-1 << "): ";
                    cin >> viTri;
                    danhSach.xoaSinhVien(viTri);
                }
                break;
            }
            
            case 4: {
                cout << "\n--- THAY THE SINH VIEN TAI VI TRI i ---" << endl;
                if(danhSach.laRong()){
                    cout << "Danh sach rong, khong the thay the!" << endl;
                }
                else{
                    danhSach.hienThiDanhSach();
                    int viTri;
                    cout << "Nhap vi tri can thay the (tu 0 den " << danhSach.getSoLuong()-1 << "): ";
                    cin >> viTri;
                    
                    cout << "Nhap thong tin sinh vien moi:" << endl;
                    Student svMoi;
                    svMoi.nhap();
                    
                    danhSach.thayTheSinhVien(viTri, svMoi);
                }
                break;
            }
            
            case 5: {
                cout << "\n--- HIEN THI DANH SACH SINH VIEN ---" << endl;
                danhSach.hienThiDanhSach();
                break;
            }
            
            case 6: {
                cout << "\n--- TIM KIEM SINH VIEN THEO MSSV ---" << endl;
                string maSv;
                cout << "Nhap MSSV can tim: ";
                cin.ignore();
                getline(cin, maSv);
                
                int viTri = danhSach.timKiemTheoMSSV(maSv);
                if(viTri != -1){
                    cout << "Tim thay sinh vien tai vi tri: " << viTri << endl;
                }
                else{
                    cout << "Khong tim thay sinh vien co MSSV: " << maSv << endl;
                }
                break;
            }
            
            case 7: {
                cout << "\n--- TAO DU LIEU MAU ---" << endl;
                danhSach.taoDuLieuMau();
                break;
            }
            
            case 8: {
                cout << "\n--- KIEM TRA DANH SACH RONG ---" << endl;
                if(danhSach.laRong()){
                    cout << "Danh sach rong!" << endl;
                }
                else{
                    cout << "Danh sach co " << danhSach.getSoLuong() << " sinh vien." << endl;
                }
                break;
            }
            
            case 0: {
                cout << "\nCam on ban da su dung chuong trinh!" << endl;
                break;
            }
            
            default: {
                cout << "Lua chon khong hop le! Vui long chon lai." << endl;
                break;
            }
        }
        
    } while(luaChon != 0);
    
    return 0;
}

/*
=== GIAI THICH CAC LOP VA PHUONG THUC ===

1. LOP STUDENT:
   - Luu tru thong tin cua mot sinh vien
   - Co cac thuoc tinh: maSv, hoTen, ngay, thang, nam, gioiTinh, queQuan
   - Co cac phuong thuc getter, setter va hienThi(), nhap()

2. LOP STUDENTNODE:
   - Node trong danh sach lien ket
   - Chua mot doi tuong Student va con tro next
   - Co cac phuong thuc de truy cap va thay doi du lieu

3. LOP STUDENTLIST:
   - Quan ly danh sach sinh vien bang danh sach lien ket don
   - Co cac phuong thuc:
     * themCuoi(): Them sinh vien vao cuoi danh sach
     * themDau(): Them sinh vien vao dau danh sach  
     * xoaSinhVien(): Xoa sinh vien tai vi tri i
     * thayTheSinhVien(): Thay the sinh vien tai vi tri i
     * hienThiDanhSach(): Hien thi toan bo danh sach
     * timKiemTheoMSSV(): Tim kiem sinh vien theo MSSV

=== CAC TINH NANG CHINH ===

1. Them sinh vien vao cuoi danh sach
2. Them sinh vien vao dau danh sach
3. Xoa sinh vien tai vi tri i
4. Thay the sinh vien tai vi tri i bang sinh vien moi
5. Hien thi danh sach sinh vien
6. Tim kiem sinh vien theo MSSV
7. Tao du lieu mau de test
8. Kiem tra danh sach rong

=== LUU Y QUAN TRONG ===

- Luon kiem tra danh sach rong truoc khi thao tac
- Cap nhat lai head, tail va soLuong khi can thiet
- Giai phong bo nho bang delete sau khi xoa node
- Su dung con tro tam thoi de luu tru gia tri
- Kiem tra vi tri hop le truoc khi thao tac

=== CAC BAI TAP MO RONG ===

1. Sap xep danh sach sinh vien theo MSSV
2. Sap xep danh sach sinh vien theo ho ten
3. Loc sinh vien theo gioi tinh
4. Loc sinh vien theo que quan
5. Tinh tuoi cua sinh vien
6. Tim sinh vien co tuoi lon nhat/nho nhat
7. Xoa sinh vien theo MSSV
8. Sua thong tin sinh vien theo MSSV
9. Luu danh sach vao file
10. Doc danh sach tu file
*/

