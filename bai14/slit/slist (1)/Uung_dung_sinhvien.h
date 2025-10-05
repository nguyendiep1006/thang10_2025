#ifndef UNG_DUNG_SINHVIEN_H
#define UNG_DUNG_SINHVIEN_H

#include<iostream>
#include<string>
using namespace std;

// Lớp quản lý sinh viên sử dụng danh sách liên kết đơn

class SinhVien {
private:
    int MaSV;
    string Hoten;
    int Ngay, Thang, Nam;
    string GioiTinh, QueQuan;
    
public:
    SinhVien();
    SinhVien(int ma, string ht, int ngay, int thang, int nam, string gt, string qq);
    
    int getMaSV() const;
    string getHoten() const;
    int getNgay() const;
    int getThang() const;
    int getNam() const;
    string getGioiTinh() const;
    string getQueQuan() const;
    
    void nhapThongTin();
    void xuatThongTin() const;
    bool kiemTraNgaySinh() const;
};

class Node {
private:
    SinhVien data;
    Node* next;
    
public:
    Node();
    Node(SinhVien sv);
    
    SinhVien getData() const;
    Node* getNext() const;
    void setData(SinhVien sv);
    void setNext(Node* n);
};

class UngDungSinhVien {
private:
    Node* head;
    Node* tail;
    int size;
    
    Node* layNodeTaiViTri(int viTri) const;
    void giaiPhongBoNho();
    bool kiemTraViTriHopLe(int viTri) const;
    void hienThiTieuDe() const;
    void hienThiSinhVien(const SinhVien &sv, int stt) const;
    
public:
    UngDungSinhVien();
    ~UngDungSinhVien();
    
    // Các chức năng chính
    bool themVaoCuoi();
    bool themVaoDau();
    bool xoaSinhVien(int viTri);
    bool thayTheSinhVien(int viTri);
    
    // Chức năng bổ sung
    void hienThiDanhSach() const;
    void timKiemSinhVien() const;
    int demSoLuong() const;
    bool kiemTraRong() const;
    
    // Giao diện
    void hienThiMenu() const;
    void xuLyLuaChon(int luaChon);
    void chayUngDung();
    
    // Dữ liệu mẫu
    void taoDuLieuMau();
};

#endif
