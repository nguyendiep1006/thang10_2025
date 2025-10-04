#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student{
    private:
        string maSv, hoTen, gioiTinh, queQuan;
        int ngay, thang, nam;
    
    public:
        Student(){
            maSv = hoTen = gioiTinh = queQuan = "";
            ngay = thang = 1;
            nam = 2000;
        }
        
        Student(string ma, string ten, int d, int m, int y, string gt, string qq){
            maSv = ma; hoTen = ten; ngay = d; thang = m; nam = y; gioiTinh = gt; queQuan = qq;
        } 
        
        string getMaSv() { return maSv; }
        string getHoTen() { return hoTen; }
        
        void hienThi(){
            cout << "MSSV: " << maSv << " | Ho ten: " << hoTen << " | ";
            cout << "Ngay sinh: " << ngay << "/" << thang << "/" << nam << " | ";
            cout << "Gioi tinh: " << gioiTinh << " | Que quan: " << queQuan << endl;
        }
        
        void nhap(){
            cout << "Nhap MSSV: "; cin.ignore(); getline(cin, maSv);
            cout << "Nhap ho ten: "; getline(cin, hoTen);
            cout << "Nhap ngay sinh: "; cin >> ngay;
            cout << "Nhap thang sinh: "; cin >> thang;
            cout << "Nhap nam sinh: "; cin >> nam;
            cout << "Nhap gioi tinh: "; cin.ignore(); getline(cin, gioiTinh);
            cout << "Nhap que quan: "; getline(cin, queQuan);
        }
};

class StudentList{
    private:
        vector<Student> ds;
    
    public:
        StudentList(){}
        
        void themCuoi(Student student){
            ds.push_back(student);
            cout << "Da them sinh vien vao cuoi danh sach!" << endl;
        }
        
        void themDau(Student student){
            ds.insert(ds.begin(), student);
            cout << "Da them sinh vien vao dau danh sach!" << endl;
        }
        
        bool xoaSinhVien(int viTri){
            if(ds.empty() || viTri < 0 || viTri >= (int)ds.size()){
                cout << "Vi tri khong hop le hoac danh sach rong!" << endl;
                return false;
            }
            ds.erase(ds.begin() + viTri);
            cout << "Da xoa sinh vien tai vi tri " << viTri << "!" << endl;
            return true;
        }
        
        bool thayTheSinhVien(int viTri, Student studentMoi){
            if(ds.empty() || viTri < 0 || viTri >= (int)ds.size()){
                cout << "Vi tri khong hop le hoac danh sach rong!" << endl;
                return false;
            }
            ds[viTri] = studentMoi;
            cout << "Da thay the sinh vien tai vi tri " << viTri << "!" << endl;
            return true;
        }
        
        void hienThiDanhSach(){
            if(ds.empty()){
                cout << "Danh sach sinh vien rong!" << endl;
                return;
            }
            cout << "\n=== DANH SACH SINH VIEN ===" << endl;
            cout << "So luong sinh vien: " << ds.size() << endl;
            cout << "----------------------------------------" << endl;
            for(size_t i = 0; i < ds.size(); i++){
                cout << "STT " << i << ": ";
                ds[i].hienThi();
            }
            cout << "----------------------------------------" << endl;
        }
        
        int timKiemTheoMSSV(string maSv){
            for(size_t i = 0; i < ds.size(); i++)
                if(ds[i].getMaSv() == maSv) return (int)i;
            return -1;
        }
        
        int getSoLuong(){ return (int)ds.size(); }
        bool laRong(){ return ds.empty(); }
        
        void taoDuLieuMau(){
            themCuoi(Student("SV001", "Nguyen Van A", 15, 3, 2000, "Nam", "Ha Noi"));
            themCuoi(Student("SV002", "Tran Thi B", 20, 7, 1999, "Nu", "Ho Chi Minh")); 
            themCuoi(Student("SV003", "Le Van C", 10, 12, 2001, "Nam", "Da Nang"));
        }
};

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
                if(viTri != -1)
                    cout << "Tim thay sinh vien tai vi tri: " << viTri << endl;
                else
                    cout << "Khong tim thay sinh vien co MSSV: " << maSv << endl;
                break;
            }
            
            case 7: {
                cout << "\n--- TAO DU LIEU MAU ---" << endl;
                danhSach.taoDuLieuMau();
                break;
            }
            
            case 8: {
                cout << "\n--- KIEM TRA DANH SACH RONG ---" << endl;
                if(danhSach.laRong())
                    cout << "Danh sach rong!" << endl;
                else
                    cout << "Danh sach co " << danhSach.getSoLuong() << " sinh vien." << endl;
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
