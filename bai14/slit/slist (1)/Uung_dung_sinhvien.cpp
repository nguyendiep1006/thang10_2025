#include"Uung_dung_sinhvien.h"
#include<fstream>
#include<iomanip>
#include<algorithm>

/*
 * =====================================================================================
 * FILE: ung_dung_sinhvien.cpp
 * MÔ TẢ: Implementation file cho lớp ứng dụng quản lý sinh viên
 * TÁC GIẢ: AI Assistant
 * NGÀY TẠO: 2025
 * =====================================================================================
 * 
 * IMPLEMENTATION CÁC PHƯƠNG THỨC CỦA LỚP UNGDUNGSINHVIEN
 * 
 * CÁC CHỨC NĂNG CHÍNH:
 * - Thêm sinh viên vào cuối/đầu danh sách
 * - Xóa sinh viên tại vị trí i
 * - Thay thế sinh viên tại vị trí i
 * - Hiển thị, tìm kiếm, thống kê
 * - Giao diện menu tương tác
 */

// ==================== IMPLEMENTATION CLASS SINHVIEN ====================

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
    MaSV = ma;
    Hoten = ht;
    Ngay = ngay;
    Thang = thang;
    Nam = nam;
    GioiTinh = gt;
    QueQuan = qq;
}

// Getter methods
int SinhVien::getMaSV() const { return MaSV; }
string SinhVien::getHoten() const { return Hoten; }
int SinhVien::getNgay() const { return Ngay; }
int SinhVien::getThang() const { return Thang; }
int SinhVien::getNam() const { return Nam; }
string SinhVien::getGioiTinh() const { return GioiTinh; }
string SinhVien::getQueQuan() const { return QueQuan; }

// Setter methods
void SinhVien::setMaSV(int ma) { MaSV = ma; }
void SinhVien::setHoten(string ht) { Hoten = ht; }
void SinhVien::setNgay(int ngay) { Ngay = ngay; }
void SinhVien::setThang(int thang) { Thang = thang; }
void SinhVien::setNam(int nam) { Nam = nam; }
void SinhVien::setGioiTinh(string gt) { GioiTinh = gt; }
void SinhVien::setQueQuan(string qq) { QueQuan = qq; }

void SinhVien::nhapThongTin() {
    cout << "\n--- NHAP THONG TIN SINH VIEN ---" << endl;
    
    do {
        cout << "Nhap ma sinh vien: ";
        cin >> MaSV;
        if(MaSV <= 0) {
            cout << "Ma sinh vien phai la so duong! Vui long nhap lai." << endl;
        }
    } while(MaSV <= 0);
    
    cin.ignore(); // Xóa buffer
    cout << "Nhap ho ten: ";
    getline(cin, Hoten);
    
    do {
        cout << "Nhap ngay sinh (1-31): ";
        cin >> Ngay;
        cout << "Nhap thang sinh (1-12): ";
        cin >> Thang;
        cout << "Nhap nam sinh: ";
        cin >> Nam;
        
        if(!kiemTraNgaySinh()) {
            cout << "Ngay sinh khong hop le! Vui long nhap lai." << endl;
        }
    } while(!kiemTraNgaySinh());
    
    cin.ignore();
    cout << "Nhap gioi tinh (Nam/Nu): ";
    getline(cin, GioiTinh);
    
    cout << "Nhap que quan: ";
    getline(cin, QueQuan);
}

void SinhVien::xuatThongTin() const {
    cout << "| " << setw(8) << MaSV 
         << " | " << setw(20) << Hoten 
         << " | " << setw(2) << Ngay << "/" << setw(2) << Thang << "/" << setw(4) << Nam
         << " | " << setw(6) << GioiTinh 
         << " | " << setw(15) << QueQuan << " |" << endl;
}

bool SinhVien::kiemTraNgaySinh() const {
    if(Nam < 1900 || Nam > 2024) return false;
    if(Thang < 1 || Thang > 12) return false;
    if(Ngay < 1) return false;
    
    int ngayTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Kiểm tra năm nhuận
    if((Nam % 4 == 0 && Nam % 100 != 0) || (Nam % 400 == 0)) {
        ngayTrongThang[1] = 29;
    }
    
    return Ngay <= ngayTrongThang[Thang - 1];
}

int SinhVien::tinhTuoi() const {
    return 2024 - Nam;
}

bool SinhVien::operator==(const SinhVien &sv) const {
    return MaSV == sv.MaSV;
}

// ==================== IMPLEMENTATION CLASS NODE ====================

Node::Node() {
    next = nullptr;
}

Node::Node(SinhVien sv) {
    data = sv;
    next = nullptr;
}

Node::~Node() {
    // Không delete next vì danh sách sẽ quản lý
}

SinhVien Node::getData() const { return data; }
Node* Node::getNext() const { return next; }
void Node::setData(SinhVien sv) { data = sv; }
void Node::setNext(Node* n) { next = n; }
void Node::khoiTaoNode(SinhVien sv) {
    data = sv;
    next = nullptr;
}

// ==================== IMPLEMENTATION CLASS UNGDUNGSINHVIEN ====================

UngDungSinhVien::UngDungSinhVien() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

UngDungSinhVien::~UngDungSinhVien() {
    giaiPhongBoNho();
}

UngDungSinhVien::UngDungSinhVien(const UngDungSinhVien &app) {
    head = nullptr;
    tail = nullptr;
    size = 0;
    saoChepDanhSach(app);
}

UngDungSinhVien& UngDungSinhVien::operator=(const UngDungSinhVien &app) {
    if(this != &app) {d
        giaiPhongBoNho();
        saoChepDanhSach(app);
    }
    return *this;
}

// ==================== CÁC CHỨC NĂNG CHÍNH YÊU CẦU ====================

bool UngDungSinhVien::themVaoCuoi() {
    SinhVien sv;
    sv.nhapThongTin();
    
    Node* newNode = new Node(sv);
    
    if(head == nullptr) {
        head = tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
    
    size++;
    cout << "\n✓ Da them sinh vien vao cuoi danh sach thanh cong!" << endl;
    return true;
}

bool UngDungSinhVien::themVaoDau() {
    SinhVien sv;
    sv.nhapThongTin();
    
    Node* newNode = new Node(sv);
    
    if(head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->setNext(head);
        head = newNode;
    }
    
    size++;
    cout << "\n✓ Da them sinh vien vao dau danh sach thanh cong!" << endl;
    return true;
}

bool UngDungSinhVien::xoaSinhVien(int viTri) {
    if(!kiemTraViTriHopLe(viTri)) {
        cout << "\n✗ Vi tri khong hop le!" << endl;
        return false;
    }
    
    if(viTri == 1) {
        // Xóa node đầu
        Node* temp = head;
        head = head->getNext();
        if(head == nullptr) tail = nullptr;
        delete temp;
    } else {
        // Xóa node ở giữa hoặc cuối
        Node* prev = layNodeTaiViTri(viTri - 1);
        Node* current = prev->getNext();
        
        prev->setNext(current->getNext());
        if(current == tail) tail = prev;
        delete current;
    }
    
    size--;
    cout << "\n✓ Da xoa sinh vien tai vi tri " << viTri << " thanh cong!" << endl;
    return true;
}

bool UngDungSinhVien::thayTheSinhVien(int viTri) {
    if(!kiemTraViTriHopLe(viTri)) {
        cout << "\n✗ Vi tri khong hop le!" << endl;
        return false;
    }
    
    cout << "\nThong tin sinh vien hien tai tai vi tri " << viTri << ":" << endl;
    SinhVien svCu = laySinhVien(viTri);
    svCu.xuatThongTin();
    
    cout << "\nNhap thong tin sinh vien moi:" << endl;
    SinhVien svMoi;
    svMoi.nhapThongTin();
    
    Node* node = layNodeTaiViTri(viTri);
    node->setData(svMoi);
    
    cout << "\n✓ Da thay the sinh vien tai vi tri " << viTri << " thanh cong!" << endl;
    return true;
}

// ==================== CÁC CHỨC NĂNG BỔ SUNG ====================

void UngDungSinhVien::hienThiDanhSach() const {
    if(kiemTraRong()) {
        cout << "\nDanh sach sinh vien rong!" << endl;
        return;
    }
    
    hienThiTieuDe();
    
    Node* current = head;
    int stt = 1;
    
    while(current != nullptr) {
        hienThiSinhVien(current->getData(), stt++);
        current = current->getNext();
    }
    
    cout << "+" << string(78, '-') << "+" << endl;
    cout << "Tong cong: " << size << " sinh vien" << endl;
}

void UngDungSinhVien::timKiemSinhVien() const {
    if(kiemTraRong()) {
        cout << "\nDanh sach sinh vien rong!" << endl;
        return;
    }
    
    int maSV;
    cout << "\nNhap ma sinh vien can tim: ";
    cin >> maSV;
    
    Node* current = head;
    int viTri = 1;
    bool timThay = false;
    
    while(current != nullptr) {
        if(current->getData().getMaSV() == maSV) {
            cout << "\n✓ Tim thay sinh vien tai vi tri " << viTri << ":" << endl;
            hienThiTieuDe();
            hienThiSinhVien(current->getData(), viTri);
            cout << "+" << string(78, '-') << "+" << endl;
            timThay = true;
            break;
        }
        current = current->getNext();
        viTri++;
    }
    
    if(!timThay) {
        cout << "\n✗ Khong tim thay sinh vien co ma " << maSV << "!" << endl;
    }
}

int UngDungSinhVien::demSoLuong() const {
    return size;
}

bool UngDungSinhVien::kiemTraRong() const {
    return head == nullptr;
}

SinhVien UngDungSinhVien::laySinhVien(int viTri) const {
    Node* node = layNodeTaiViTri(viTri);
    return (node != nullptr) ? node->getData() : SinhVien();
}

void UngDungSinhVien::xoaToanBo() {
    giaiPhongBoNho();
    head = tail = nullptr;
    size = 0;
    cout << "\n✓ Da xoa toan bo danh sach sinh vien!" << endl;
}

bool UngDungSinhVien::themTaiViTri(int viTri) {
    if(viTri < 1 || viTri > size + 1) {
        cout << "\n✗ Vi tri khong hop le!" << endl;
        return false;
    }
    
    if(viTri == 1) {
        return themVaoDau();
    } else if(viTri == size + 1) {
        return themVaoCuoi();
    }
    
    SinhVien sv;
    sv.nhapThongTin();
    
    Node* newNode = new Node(sv);
    Node* prev = layNodeTaiViTri(viTri - 1);
    
    newNode->setNext(prev->getNext());
    prev->setNext(newNode);
    
    size++;
    cout << "\n✓ Da them sinh vien tai vi tri " << viTri << " thanh cong!" << endl;
    return true;
}

// ==================== GIAO DIỆN NGƯỜI DÙNG ====================

void UngDungSinhVien::hienThiMenu() const {
    cout << "\n" << string(60, '=') << endl;
    cout << "           HE THONG QUAN LY SINH VIEN" << endl;
    cout << string(60, '=') << endl;
    cout << "1.  Them sinh vien vao cuoi danh sach" << endl;
    cout << "2.  Them sinh vien vao dau danh sach" << endl;
    cout << "3.  Xoa sinh vien tai vi tri i" << endl;
    cout << "4.  Thay the sinh vien tai vi tri i" << endl;
    cout << "5.  Hien thi danh sach sinh vien" << endl;
    cout << "6.  Tim kiem sinh vien theo ma" << endl;
    cout << "7.  Dem so luong sinh vien" << endl;
    cout << "8.  Them sinh vien tai vi tri i" << endl;
    cout << "9.  Tao du lieu mau" << endl;
    cout << "10. Thong ke theo gioi tinh" << endl;
    cout << "11. Thong ke theo que quan" << endl;
    cout << "12. Xoa toan bo danh sach" << endl;
    cout << "0.  Thoat chuong trinh" << endl;
    cout << string(60, '=') << endl;
    cout << "So luong sinh vien hien tai: " << size << endl;
    cout << string(60, '=') << endl;
}

void UngDungSinhVien::xuLyLuaChon(int luaChon) {
    switch(luaChon) {
        case 1: {
            themVaoCuoi();
            break;
        }
        case 2: {
            themVaoDau();
            break;
        }
        case 3: {
            if(kiemTraRong()) {
                cout << "\nDanh sach rong, khong the xoa!" << endl;
                break;
            }
            int viTri;
            cout << "\nNhap vi tri can xoa (1-" << size << "): ";
            cin >> viTri;
            xoaSinhVien(viTri);
            break;
        }
        case 4: {
            if(kiemTraRong()) {
                cout << "\nDanh sach rong, khong the thay the!" << endl;
                break;
            }
            int viTri;
            cout << "\nNhap vi tri can thay the (1-" << size << "): ";
            cin >> viTri;
            thayTheSinhVien(viTri);
            break;
        }
        case 5: {
            hienThiDanhSach();
            break;
        }
        case 6: {
            timKiemSinhVien();
            break;
        }
        case 7: {
            cout << "\nSo luong sinh vien trong danh sach: " << demSoLuong() << endl;
            break;
        }
        case 8: {
            int viTri;
            cout << "\nNhap vi tri can them (1-" << (size + 1) << "): ";
            cin >> viTri;
            themTaiViTri(viTri);
            break;
        }
        case 9: {
            taoDuLieuMau();
            break;
        }
        case 10: {
            thongKeTheoGioiTinh();
            break;
        }
        case 11: {
            thongKeTheoQueQuan();
            break;
        }
        case 12: {
            if(!kiemTraRong()) {
                char confirm;
                cout << "\nBan co chac chan muon xoa toan bo danh sach? (y/n): ";
                cin >> confirm;
                if(confirm == 'y' || confirm == 'Y') {
                    xoaToanBo();
                } else {
                    cout << "Huy thao tac!" << endl;
                }
            } else {
                cout << "\nDanh sach da rong!" << endl;
            }
            break;
        }
        case 0: {
            cout << "\nCam on ban da su dung chuong trinh!" << endl;
            break;
        }
        default: {
            cout << "\n✗ Lua chon khong hop le! Vui long chon lai." << endl;
            break;
        }
    }
}

void UngDungSinhVien::chayUngDung() {
    int luaChon;
    
    cout << "Chao mung ban den voi he thong quan ly sinh vien!" << endl;
    
    do {
        hienThiMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        xuLyLuaChon(luaChon);
        
        if(luaChon != 0) {
            cout << "\nNhan Enter de tiep tuc...";
            cin.ignore();
            cin.get();
        }
    } while(luaChon != 0);
}

// ==================== QUẢN LÝ DỮ LIỆU ====================

void UngDungSinhVien::taoDuLieuMau() {
    // Tạo một số sinh viên mẫu
    SinhVien sv1(1001, "Nguyen Van An", 15, 3, 2000, "Nam", "Ha Noi");
    SinhVien sv2(1002, "Tran Thi Binh", 22, 7, 2001, "Nu", "TP.HCM");
    SinhVien sv3(1003, "Le Van Cuong", 8, 12, 1999, "Nam", "Da Nang");
    SinhVien sv4(1004, "Pham Thi Dung", 30, 5, 2002, "Nu", "Hue");
    SinhVien sv5(1005, "Hoang Van Em", 14, 9, 2000, "Nam", "Can Tho");
    
    // Thêm vào danh sách
    Node* newNode1 = new Node(sv1);
    Node* newNode2 = new Node(sv2);
    Node* newNode3 = new Node(sv3);
    Node* newNode4 = new Node(sv4);
    Node* newNode5 = new Node(sv5);
    
    if(head == nullptr) {
        head = newNode1;
        newNode1->setNext(newNode2);
        newNode2->setNext(newNode3);
        newNode3->setNext(newNode4);
        newNode4->setNext(newNode5);
        tail = newNode5;
    } else {
        tail->setNext(newNode1);
        newNode1->setNext(newNode2);
        newNode2->setNext(newNode3);
        newNode3->setNext(newNode4);
        newNode4->setNext(newNode5);
        tail = newNode5;
    }
    
    size += 5;
    cout << "\n✓ Da tao " << 5 << " sinh vien mau thanh cong!" << endl;
}

// ==================== THỐNG KÊ ====================

void UngDungSinhVien::thongKeTheoGioiTinh() const {
    if(kiemTraRong()) {
        cout << "\nDanh sach sinh vien rong!" << endl;
        return;
    }
    
    int nam = 0, nu = 0;
    Node* current = head;
    
    while(current != nullptr) {
        if(current->getData().getGioiTinh() == "Nam") {
            nam++;
        } else {
            nu++;
        }
        current = current->getNext();
    }
    
    cout << "\n=== THONG KE THEO GIOI TINH ===" << endl;
    cout << "Nam: " << nam << " sinh vien (" << fixed << setprecision(1) 
         << (double)nam * 100 / size << "%)" << endl;
    cout << "Nu: " << nu << " sinh vien (" << fixed << setprecision(1) 
         << (double)nu * 100 / size << "%)" << endl;
}

void UngDungSinhVien::thongKeTheoQueQuan() const {
    if(kiemTraRong()) {
        cout << "\nDanh sach sinh vien rong!" << endl;
        return;
    }
    
    cout << "\n=== THONG KE THEO QUE QUAN ===" << endl;
    
    Node* current = head;
    while(current != nullptr) {
        string queQuan = current->getData().getQueQuan();
        int dem = 1;
        
        // Đếm số sinh viên có cùng quê quán
        Node* temp = current->getNext();
        while(temp != nullptr) {
            if(temp->getData().getQueQuan() == queQuan) {
                dem++;
            }
            temp = temp->getNext();
        }
        
        cout << queQuan << ": " << dem << " sinh vien" << endl;
        
        // Bỏ qua các node đã đếm
        current = current->getNext();
    }
}

// ==================== PHƯƠNG THỨC HỖ TRỢ PRIVATE ====================

Node* UngDungSinhVien::layNodeTaiViTri(int viTri) const {
    if(viTri < 1 || viTri > size) return nullptr;
    
    Node* current = head;
    for(int i = 1; i < viTri; i++) {
        current = current->getNext();
    }
    return current;
}

void UngDungSinhVien::giaiPhongBoNho() {
    Node* current = head;
    while(current != nullptr) {
        Node* next = current->getNext();
        delete current;
        current = next;
    }
}

void UngDungSinhVien::saoChepDanhSach(const UngDungSinhVien &app) {
    Node* current = app.head;
    while(current != nullptr) {
        themVaoCuoi();
        tail->setData(current->getData());
        current = current->getNext();
    }
}

bool UngDungSinhVien::kiemTraViTriHopLe(int viTri) const {
    return viTri >= 1 && viTri <= size;
}

void UngDungSinhVien::hienThiTieuDe() const {
    cout << "\n+" << string(78, '-') << "+" << endl;
    cout << "| " << setw(8) << "Ma SV" 
         << " | " << setw(20) << "Ho Ten" 
         << " | " << setw(10) << "Ngay Sinh"
         << " | " << setw(6) << "GT" 
         << " | " << setw(15) << "Que Quan" << " |" << endl;
    cout << "+" << string(78, '-') << "+" << endl;
}

void UngDungSinhVien::hienThiSinhVien(const SinhVien &sv, int stt) const {
    cout << "| " << setw(8) << sv.getMaSV() 
         << " | " << setw(20) << sv.getHoten() 
         << " | " << setw(2) << sv.getNgay() << "/" << setw(2) << sv.getThang() << "/" << setw(4) << sv.getNam()
         << " | " << setw(6) << sv.getGioiTinh() 
         << " | " << setw(15) << sv.getQueQuan() << " |" << endl;
}
