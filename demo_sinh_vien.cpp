#include<iostream>
#include<string>
using namespace std;

// Lớp Student để lưu trữ thông tin sinh viên
class Student{
    private:
        string maSv;
        string hoTen;
        int ngay;
        int thang;
        int nam;
        string gioiTinh;
        string queQuan;
    
    public:
        // Hàm khởi tạo mặc định
        Student(){
            maSv = "";
            hoTen = "";
            ngay = 1;
            thang = 1;
            nam = 2000;
            gioiTinh = "";
            queQuan = "";
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
        
        // Hàm hiển thị thông tin sinh viên
        void hienThi(){
            cout << "MSSV: " << maSv << " | ";
            cout << "Ho ten: " << hoTen << " | ";
            cout << "Ngay sinh: " << ngay << "/" << thang << "/" << nam << " | ";
            cout << "Gioi tinh: " << gioiTinh << " | ";
            cout << "Que quan: " << queQuan << endl;
        }
};

// Lớp StudentNode để tạo node trong danh sách liên kết
class StudentNode{
    private:
        Student student;
        StudentNode* next;
    
    public:
        // Hàm khởi tạo
        StudentNode(Student s): student(s), next(NULL){
        }
        
        // Các hàm getter
        Student getStudent() { return student; }
        StudentNode* getNext() { return next; }
        
        // Các hàm setter
        void setStudent(Student s) { student = s; }
        void setNext(StudentNode* n) { next = n; }
        
        // Hàm hiển thị thông tin node
        void hienThi(){
            student.hienThi();
        }
};

// Lớp StudentList để quản lý danh sách sinh viên
class StudentList{
    private:
        StudentNode* head;
        StudentNode* tail;
        int soLuong;
    
    public:
        // Hàm khởi tạo
        StudentList(): head(NULL), tail(NULL), soLuong(0){
        }
        
        // Hàm thêm sinh viên vào cuối danh sách
        void themCuoi(Student student){
            StudentNode* newNode = new StudentNode(student);
            if(head == NULL){
                head = tail = newNode;
            }
            else{
                tail->setNext(newNode);
                tail = newNode;
            }
            soLuong++;
            cout << "Da them sinh vien vao cuoi danh sach!" << endl;
        }
        
        // Hàm thêm sinh viên vào đầu danh sách
        void themDau(Student student){
            StudentNode* newNode = new StudentNode(student);
            if(head == NULL){
                head = tail = newNode;
            }
            else{
                newNode->setNext(head);
                head = newNode;
            }
            soLuong++;
            cout << "Da them sinh vien vao dau danh sach!" << endl;
        }
        
        // Hàm xóa sinh viên thứ i (đếm từ 0)
        bool xoaSinhVien(int viTri){
            if(head == NULL || viTri < 0 || viTri >= soLuong){
                cout << "Vi tri khong hop le hoac danh sach rong!" << endl;
                return false;
            }
            
            if(viTri == 0){
                // Xóa sinh viên đầu
                StudentNode* temp = head;
                head = head->getNext();
                if(head == NULL){
                    tail = NULL;
                }
                delete temp;
            }
            else{
                // Tìm node trước vị trí cần xóa
                StudentNode* current = head;
                for(int i = 0; i < viTri - 1; i++){
                    current = current->getNext();
                }
                
                StudentNode* temp = current->getNext();
                current->setNext(temp->getNext());
                
                if(temp == tail){
                    tail = current;
                }
                
                delete temp;
            }
            
            soLuong--;
            cout << "Da xoa sinh vien tai vi tri " << viTri << "!" << endl;
            return true;
        }
        
        // Hàm thay thế sinh viên thứ i bằng sinh viên mới
        bool thayTheSinhVien(int viTri, Student studentMoi){
            if(head == NULL || viTri < 0 || viTri >= soLuong){
                cout << "Vi tri khong hop le hoac danh sach rong!" << endl;
                return false;
            }
            
            StudentNode* current = head;
            for(int i = 0; i < viTri; i++){
                current = current->getNext();
            }
            
            current->setStudent(studentMoi);
            cout << "Da thay the sinh vien tai vi tri " << viTri << "!" << endl;
            return true;
        }
        
        // Hàm hiển thị toàn bộ danh sách sinh viên
        void hienThiDanhSach(){
            if(head == NULL){
                cout << "Danh sach sinh vien rong!" << endl;
                return;
            }
            
            cout << "\n=== DANH SACH SINH VIEN ===" << endl;
            cout << "So luong sinh vien: " << soLuong << endl;
            cout << "----------------------------------------" << endl;
            
            StudentNode* current = head;
            int stt = 0;
            while(current != NULL){
                cout << "STT " << stt << ": ";
                current->hienThi();
                current = current->getNext();
                stt++;
            }
            cout << "----------------------------------------" << endl;
        }
        
        // Hàm lấy số lượng sinh viên
        int getSoLuong(){
            return soLuong;
        }
        
        // Hàm kiểm tra danh sách có rỗng không
        bool laRong(){
            return head == NULL;
        }
};

int main(){
    StudentList danhSach;
    
    cout << "=== DEMO CHUONG TRINH QUAN LY SINH VIEN ===" << endl;
    cout << "Su dung danh sach lien ket don" << endl << endl;
    
    // Tạo một số sinh viên mẫu
    Student sv1("SV001", "Nguyen Van A", 15, 3, 2000, "Nam", "Ha Noi");
    Student sv2("SV002", "Tran Thi B", 20, 7, 1999, "Nu", "Ho Chi Minh");
    Student sv3("SV003", "Le Van C", 10, 12, 2001, "Nam", "Da Nang");
    Student sv4("SV004", "Pham Thi D", 5, 9, 2000, "Nu", "Can Tho");
    Student sv5("SV005", "Hoang Van E", 25, 11, 1998, "Nam", "Hue");
    
    cout << "1. Them sinh vien vao cuoi danh sach:" << endl;
    danhSach.themCuoi(sv1);
    danhSach.themCuoi(sv2);
    danhSach.themCuoi(sv3);
    
    cout << "\n2. Hien thi danh sach sau khi them vao cuoi:" << endl;
    danhSach.hienThiDanhSach();
    
    cout << "\n3. Them sinh vien vao dau danh sach:" << endl;
    danhSach.themDau(sv4);
    
    cout << "\n4. Hien thi danh sach sau khi them vao dau:" << endl;
    danhSach.hienThiDanhSach();
    
    cout << "\n5. Xoa sinh vien tai vi tri 2:" << endl;
    danhSach.xoaSinhVien(2);
    
    cout << "\n6. Hien thi danh sach sau khi xoa:" << endl;
    danhSach.hienThiDanhSach();
    
    cout << "\n7. Thay the sinh vien tai vi tri 1 bang sinh vien moi:" << endl;
    danhSach.thayTheSinhVien(1, sv5);
    
    cout << "\n8. Hien thi danh sach sau khi thay the:" << endl;
    danhSach.hienThiDanhSach();
    
    cout << "\n9. Them them mot sinh vien vao cuoi:" << endl;
    Student sv6("SV006", "Vo Thi F", 18, 6, 2002, "Nu", "Nha Trang");
    danhSach.themCuoi(sv6);
    
    cout << "\n10. Hien thi danh sach cuoi cung:" << endl;
    danhSach.hienThiDanhSach();
    
    cout << "\n=== KET THUC DEMO ===" << endl;
    cout << "Tong so sinh vien trong danh sach: " << danhSach.getSoLuong() << endl;
    
    return 0;
}

/*
=== GIAI THICH DEMO ===

Chuong trinh demo nay se thuc hien cac thao tac sau:

1. Tao 6 sinh vien mau voi day du thong tin
2. Them 3 sinh vien vao cuoi danh sach
3. Hien thi danh sach
4. Them 1 sinh vien vao dau danh sach
5. Hien thi danh sach
6. Xoa sinh vien tai vi tri 2
7. Hien thi danh sach
8. Thay the sinh vien tai vi tri 1
9. Hien thi danh sach
10. Them 1 sinh vien vao cuoi
11. Hien thi danh sach cuoi cung

=== CAC TINH NANG DA TRIEN KHAI ===

1. themCuoi(): Them sinh vien vao cuoi danh sach
2. themDau(): Them sinh vien vao dau danh sach
3. xoaSinhVien(): Xoa sinh vien tai vi tri i
4. thayTheSinhVien(): Thay the sinh vien tai vi tri i
5. hienThiDanhSach(): Hien thi toan bo danh sach
6. getSoLuong(): Lay so luong sinh vien
7. laRong(): Kiem tra danh sach rong

=== CAC LOP CHINH ===

1. Student: Luu tru thong tin sinh vien
2. StudentNode: Node trong danh sach lien ket
3. StudentList: Quan ly danh sach sinh vien

=== LUU Y ===

- Su dung danh sach lien ket don de luu tru
- Luon kiem tra dieu kien truoc khi thao tac
- Cap nhat head, tail va soLuong khi can thiet
- Giai phong bo nho bang delete sau khi xoa node
*/

