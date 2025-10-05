#include"ung_dung_sinhvien.h"
#include<iomanip>

SinhVien::SinhVien() {
    MaSV = 0;
    Hoten = "";
    Ngay = 1;
    Thang = 1;
    Nam = 2000;
    GioiTinh = "Nam";
    QueQuan = "";
}

SinhVien::SinhVien(int ma, string ht, int ngay, int thang, int nam, string gt, string qq) {
    MaSV = ma; Hoten = ht; Ngay = ngay; Thang = thang; Nam = nam; GioiTinh = gt; QueQuan = qq;
}

int SinhVien::getMaSV() const { return MaSV; }
string SinhVien::getHoten() const { return Hoten; }
int SinhVien::getNgay() const { return Ngay; }
int SinhVien::getThang() const { return Thang; }
int SinhVien::getNam() const { return Nam; }
string SinhVien::getGioiTinh() const { return GioiTinh; }
string SinhVien::getQueQuan() const { return QueQuan; }

void SinhVien::nhapThongTin() {
    cout << "Nhap ma sinh vien: "; cin >> MaSV;
    cin.ignore();
    cout << "Nhap ho ten: "; getline(cin, Hoten);
    cout << "Nhap ngay sinh: "; cin >> Ngay;
    cout << "Nhap thang sinh: "; cin >> Thang;
    cout << "Nhap nam sinh: "; cin >> Nam;
    cin.ignore();
    cout << "Nhap gioi tinh: "; getline(cin, GioiTinh);
    cout << "Nhap que quan: "; getline(cin, QueQuan);
}

void SinhVien::xuatThongTin() const {
    cout << "| " << setw(8) << MaSV << " | " << setw(20) << Hoten 
         << " | " << Ngay << "/" << Thang << "/" << Nam
         << " | " << setw(6) << GioiTinh << " | " << setw(15) << QueQuan << " |" << endl;
}

bool SinhVien::kiemTraNgaySinh() const {
    return Nam >= 1900 && Nam <= 2024 && Thang >= 1 && Thang <= 12 && Ngay >= 1 && Ngay <= 31;
}

Node::Node() { next = nullptr; }
Node::Node(SinhVien sv) { data = sv; next = nullptr; }
SinhVien Node::getData() const { return data; }
Node* Node::getNext() const { return next; }
void Node::setData(SinhVien sv) { data = sv; }
void Node::setNext(Node* n) { next = n; }

UngDungSinhVien::UngDungSinhVien() { head = tail = nullptr; size = 0; }
UngDungSinhVien::~UngDungSinhVien() { giaiPhongBoNho(); }

bool UngDungSinhVien::themVaoCuoi() {
    SinhVien sv; sv.nhapThongTin();
    Node* newNode = new Node(sv);
    if(head == nullptr) head = tail = newNode;
    else { tail->setNext(newNode); tail = newNode; }
    size++; cout << "Da them sinh vien vao cuoi!" << endl;
    return true;
}

bool UngDungSinhVien::themVaoDau() {
    SinhVien sv; sv.nhapThongTin();
    Node* newNode = new Node(sv);
    if(head == nullptr) head = tail = newNode;
    else { newNode->setNext(head); head = newNode; }
    size++; cout << "Da them sinh vien vao dau!" << endl;
    return true;
}

bool UngDungSinhVien::xoaSinhVien(int viTri) {
    if(!kiemTraViTriHopLe(viTri)) { cout << "Vi tri khong hop le!" << endl; return false; }
    
    if(viTri == 1) {
        Node* temp = head; head = head->getNext();
        if(head == nullptr) tail = nullptr; delete temp;
    } else {
        Node* prev = layNodeTaiViTri(viTri - 1);
        Node* current = prev->getNext();
        prev->setNext(current->getNext());
        if(current == tail) tail = prev; delete current;
    }
    size--; cout << "Da xoa sinh vien tai vi tri " << viTri << "!" << endl;
    return true;
}

bool UngDungSinhVien::thayTheSinhVien(int viTri) {
    if(!kiemTraViTriHopLe(viTri)) { cout << "Vi tri khong hop le!" << endl; return false; }
    cout << "Thay the sinh vien tai vi tri " << viTri << ":" << endl;
    SinhVien svMoi; svMoi.nhapThongTin();
    layNodeTaiViTri(viTri)->setData(svMoi);
    cout << "Da thay the thanh cong!" << endl; return true;
}

void UngDungSinhVien::hienThiDanhSach() const {
    if(kiemTraRong()) { cout << "Danh sach rong!" << endl; return; }
    hienThiTieuDe();
    Node* current = head; int stt = 1;
    while(current != nullptr) {
        hienThiSinhVien(current->getData(), stt++);
        current = current->getNext();
    }
    cout << "Tong cong: " << size << " sinh vien" << endl;
}

void UngDungSinhVien::timKiemSinhVien() const {
    if(kiemTraRong()) { cout << "Danh sach rong!" << endl; return; }
    int maSV; cout << "Nhap ma sinh vien: "; cin >> maSV;
    Node* current = head; int viTri = 1;
    while(current != nullptr) {
        if(current->getData().getMaSV() == maSV) {
            cout << "Tim thay tai vi tri " << viTri << ":" << endl;
            hienThiTieuDe(); hienThiSinhVien(current->getData(), viTri); return;
        }
        current = current->getNext(); viTri++;
    }
    cout << "Khong tim thay!" << endl;
}

int UngDungSinhVien::demSoLuong() const { return size; }
bool UngDungSinhVien::kiemTraRong() const { return head == nullptr; }

void UngDungSinhVien::hienThiMenu() const {
    cout << "\n=== HE THONG QUAN LY SINH VIEN ===" << endl;
    cout << "1. Them vao cuoi" << endl;
    cout << "2. Them vao dau" << endl;
    cout << "3. Xoa tai vi tri" << endl;
    cout << "4. Thay the tai vi tri" << endl;
    cout << "5. Hien thi danh sach" << endl;
    cout << "6. Tim kiem" << endl;
    cout << "7. Dem so luong" << endl;
    cout << "8. Tao du lieu mau" << endl;
    cout << "0. Thoat" << endl;
    cout << "So luong: " << size << endl;
}

void UngDungSinhVien::xuLyLuaChon(int luaChon) {
    switch(luaChon) {
        case 1: themVaoCuoi(); break;
        case 2: themVaoDau(); break;
        case 3: {
            if(kiemTraRong()) { cout << "Danh sach rong!" << endl; break; }
            int viTri; cout << "Nhap vi tri xoa (1-" << size << "): "; cin >> viTri;
            xoaSinhVien(viTri); break;
        }
        case 4: {
            if(kiemTraRong()) { cout << "Danh sach rong!" << endl; break; }
            int viTri; cout << "Nhap vi tri thay the (1-" << size << "): "; cin >> viTri;
            thayTheSinhVien(viTri); break;
        }
        case 5: hienThiDanhSach(); break;
        case 6: timKiemSinhVien(); break;
        case 7: cout << "So luong: " << demSoLuong() << endl; break;
        case 8: taoDuLieuMau(); break;
        case 0: cout << "Cam on!" << endl; break;
        default: cout << "Lua chon khong hop le!" << endl; break;
    }
}

void UngDungSinhVien::chayUngDung() {
    int luaChon;
    do {
        hienThiMenu();
        cout << "Nhap lua chon: "; cin >> luaChon;
        xuLyLuaChon(luaChon);
        if(luaChon != 0) { cout << "Nhan Enter..."; cin.ignore(); cin.get(); }
    } while(luaChon != 0);
}

void UngDungSinhVien::taoDuLieuMau() {
    SinhVien sv1(1001, "Nguyen Van An", 15, 3, 2000, "Nam", "Ha Noi");
    SinhVien sv2(1002, "Tran Thi Binh", 22, 7, 2001, "Nu", "TP.HCM");
    SinhVien sv3(1003, "Le Van Cuong", 8, 12, 1999, "Nam", "Da Nang");
    
    Node* n1 = new Node(sv1);
    Node* n2 = new Node(sv2);
    Node* n3 = new Node(sv3);
    
    if(head == nullptr) {
        head = n1; n1->setNext(n2); n2->setNext(n3); tail = n3;
    } else {
        tail->setNext(n1); n1->setNext(n2); n2->setNext(n3); tail = n3;
    }
    size += 3; cout << "Da tao 3 sinh vien mau!" << endl;
}

Node* UngDungSinhVien::layNodeTaiViTri(int viTri) const {
    if(viTri < 1 || viTri > size) return nullptr;
    Node* current = head;
    for(int i = 1; i < viTri; i++) current = current->getNext();
    return current;
}

void UngDungSinhVien::giaiPhongBoNho() {
    Node* current = head;
    while(current != nullptr) {
        Node* next = current->getNext(); delete current; current = next;
    }
}

bool UngDungSinhVien::kiemTraViTriHopLe(int viTri) const {
    return viTri >= 1 && viTri <= size;
}

void UngDungSinhVien::hienThiTieuDe() const {
    cout << "| Ma SV   | Ho Ten              | Ngay Sinh  | GT    | Que Quan       |" << endl;
    cout << "|---------|---------------------|------------|-------|----------------|" << endl;
}

void UngDungSinhVien::hienThiSinhVien(const SinhVien &sv, int stt) const {
    cout << "| " << setw(8) << sv.getMaSV() << " | " << setw(19) << sv.getHoten() 
         << " | " << sv.getNgay() << "/" << sv.getThang() << "/" << sv.getNam()
         << "   | " << setw(5) << sv.getGioiTinh() << " | " << setw(14) << sv.getQueQuan() << " |" << endl;
}
