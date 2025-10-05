#include<iostream>
#include<string>
using namespace std;

class NhanVien{
private:
    string HoTen;
    int mucLuong;
    string ChucVu;
    string QueQuan;
    
public:
    NhanVien(){
        HoTen = "";
        mucLuong = 1;
        ChucVu = "";
        QueQuan = "";
    }
    
    NhanVien(string ht, int ml, string cv, string qq){
        HoTen = ht;
        mucLuong = ml;
        ChucVu = cv;
        QueQuan = qq;
    }
    
    // Getter methods
    string getHoTen() const {
        return HoTen;
    }
    
    int getMucLuong() const {
        return mucLuong;
    }
    
    string getChucVu() const {
        return ChucVu;
    }
    
    string getQueQuan() const {
        return QueQuan;
    }
    
    // Setter methods
    void setHoTen(string ht) {
        HoTen = ht;
    }
    
    void setMucLuong(int ml) {
        mucLuong = ml;
    }
    
    void setChucVu(string cv) {
        ChucVu = cv;
    }
    
    void setQueQuan(string qq) {
        QueQuan = qq;
    }
    
    void nhapTT() {
        cout << "Nhap ho ten: "; 
        cin.ignore();
        getline(cin, HoTen);
        cout << "Nhap muc luong: "; 
        cin >> mucLuong;
        cout << "Nhap chuc vu: ";
        cin.ignore();
        getline(cin, ChucVu);
        cout << "Nhap que quan: "; 
        getline(cin, QueQuan);
    }
    
    void inTT() {
        cout << "Ho ten: " << HoTen << " | Muc Luong: " << mucLuong 
             << " | Chuc Vu: " << ChucVu << " | Que Quan: " << QueQuan << endl;
    }
};

class Node {
private:
    NhanVien data;
    Node* next;
    
public:
    Node() {
        next = nullptr;
    }
    
    Node(NhanVien nv) {
        data = nv;
        next = nullptr;
    }
    
    NhanVien getData() {
        return data;
    }
    
    Node* getNext() {
        return next;
    }
    
    void setData(NhanVien nv) {
        data = nv;
    }
    
    void setNext(Node* n) {
        next = n;
    }
};

class UngDung {
private:
    Node* head;
    Node* tail;
    int size;
    
public:
    UngDung() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    ~UngDung() {
        // Giải phóng bộ nhớ
        while (head != nullptr) {
            Node* temp = head;
            head = head->getNext();
            delete temp;
        }
    }
    
    void themDau() {
        NhanVien nv;
        nv.nhapTT();
        Node* newNode = new Node(nv);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->setNext(head);
            head = newNode;
        }
        size++;
        cout << "Da them nhan vien vao dau danh sach!\n";
    }
    
    void themCuoi() {
        NhanVien nv;
        nv.nhapTT();
        Node* newNode = new Node(nv);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->setNext(newNode);
            tail = newNode;
        }
        size++;
        cout << "Da them nhan vien vao cuoi danh sach!\n";
    }
    
    void xoaNhanVien(int vitri) {
        if (vitri < 1 || vitri > size) {
            cout << "Vi tri khong hop le!\n";
            return;
        }
        
        // Nếu xóa phần tử đầu tiên
        if (vitri == 1) {
            Node* tmp = head; // Lưu lại node đầu để xóa
            head = head->getNext(); // Cập nhật head mới
            if (head == nullptr) tail = nullptr; // Nếu list rỗng thì tail cũng null
            delete tmp; // Xóa node cũ
        } else {
            // Tìm node trước node cần xóa
            Node* prev = head;
            for (int i = 1; i < vitri - 1; i++) {
                prev = prev->getNext();
            }
            // Lưu node cần xóa
            Node* temp = prev->getNext();
            // Cập nhật con trỏ next của node trước
            prev->setNext(temp->getNext());
            // Nếu xóa node cuối thì cập nhật tail
            if (temp == tail) tail = prev;
            // Xóa node
            delete temp;
        }
        size--;
        cout << "Da xoa nhan vien tai vi tri " << vitri << "!\n";
    }
    
    // Ham tim kiem nhan vien theo ten
    // Input: ten - chuoi can tim kiem trong ho ten nhan vien
    // Output: in ra thong tin cac nhan vien co ho ten chua chuoi tim kiem
    void timKiemTheoTen(string ten) {
        // Con tro duyet qua tung node trong danh sach
        Node* current = head;
        // Bien dem vi tri hien tai
        int dem = 0;
        // Co danh dau xem co tim thay ket qua nao khong
        bool timThay = false;
        
        // In tieu de ket qua tim kiem
        cout << "\n=== KET QUA TIM KIEM THEO TEN: " << ten << " ===\n";
        
        // Duyet qua tung node trong danh sach
        while (current != nullptr) {
            dem++; // Tang bien dem vi tri
            // Kiem tra neu ho ten cua nhan vien hien tai co chua chuoi tim kiem
            if (current->getData().getHoTen().find(ten) != string::npos) {
                cout << "Vi tri " << dem << ": ";
                current->getData().inTT(); // In thong tin nhan vien tim thay
                timThay = true; // Danh dau da tim thay ket qua
            }
            current = current->getNext(); // Chuyen sang node tiep theo
        }
        
        // Neu khong tim thay ket qua nao thi thong bao
        if (!timThay) {
            cout << "Khong tim thay nhan vien nao co ten chua '" << ten << "'!\n";
        }
    }
    
    void timKiemTheoChucVu(string chucVu) {
        Node* current = head;
        int dem = 0;
        bool timThay = false;
        
        cout << "\n=== KET QUA TIM KIEM THEO CHUC VU: " << chucVu << " ===\n";
        while (current != nullptr) {
            dem++;
            if (current->getData().getChucVu() == chucVu) {
                cout << "Vi tri " << dem << ": ";
                current->getData().inTT();
                timThay = true;
            }
            current = current->getNext();
        }
        
        if (!timThay) {
            cout << "Khong tim thay nhan vien nao co chuc vu '" << chucVu << "'!\n";
        }
    }
    
    void hienThiDanhSach() {
        if (head == nullptr) {
            cout << "Danh sach rong!\n";
            return;
        }
        
        cout << "\n=== DANH SACH NHAN VIEN ===\n";
        Node* current = head;
        int dem = 0;
        while (current != nullptr) {
            dem++;
            cout << "Vi tri " << dem << ": ";
            current->getData().inTT();
            current = current->getNext();
        }
        cout << "Tong cong: " << size << " nhan vien\n";
    }
    
    int getSize() {
        return size;
    }
};

void menu() {
    cout << "\n=== QUAN LY NHAN VIEN ===\n";
    cout << "1. Them nhan vien vao dau danh sach\n";
    cout << "2. Them nhan vien vao cuoi danh sach\n";
    cout << "3. Xoa nhan vien theo vi tri\n";
    cout << "4. Tim kiem theo ten\n";
    cout << "5. Tim kiem theo chuc vu\n";
    cout << "6. Hien thi danh sach\n";
    cout << "7. Thoat\n";
    cout << "Lua chon cua ban: ";
}

int main() {
    UngDung danhSach;
    int luaChon;
    string ten, chucVu;
    int vitri;
    
    do {
        menu();
        cin >> luaChon;
        
        switch (luaChon) {
            case 1:
                danhSach.themDau();
                break;
            case 2:
                danhSach.themCuoi();
                break;
            case 3:
                if (danhSach.getSize() == 0) {
                    cout << "Danh sach rong, khong the xoa!\n";
                } else {
                    cout << "Nhap vi tri can xoa (1-" << danhSach.getSize() << "): ";
                    cin >> vitri;
                    danhSach.xoaNhanVien(vitri);
                }
                break;
            case 4:
                cout << "Nhap ten can tim: ";
                cin.ignore();
                getline(cin, ten);
                danhSach.timKiemTheoTen(ten);
                break;
            case 5:
                cout << "Nhap chuc vu can tim: ";
                cin.ignore();
                getline(cin, chucVu);
                danhSach.timKiemTheoChucVu(chucVu);
                break;
            case 6:
                danhSach.hienThiDanhSach();
                break;
            case 7:
                cout << "Cam on ban da su dung chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (luaChon != 7);
    
    return 0;
}
