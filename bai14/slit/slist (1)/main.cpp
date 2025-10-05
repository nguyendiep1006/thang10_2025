#include<iostream>
#include"sinhvien.h"
#include"node.h"
#include"danhsachsinhvien.h"

using namespace std;

// Hàm hiển thị menu
void hienThiMenu(){
	cout << "\n========== MENU QUAN LY SINH VIEN ==========" << endl;
	cout << "1. Them sinh vien vao cuoi danh sach" << endl;
	cout << "2. Them sinh vien vao dau danh sach" << endl;
	cout << "3. Xoa sinh vien thu i khoi danh sach" << endl;
	cout << "4. Thay the sinh vien thu i bang sinh vien moi" << endl;
	cout << "5. Hien thi danh sach sinh vien" << endl;
	cout << "6. Tim kiem sinh vien theo ma" << endl;
	cout << "7. Them sinh vien tai vi tri i" << endl;
	cout << "8. Dem so luong sinh vien" << endl;
	cout << "9. Xoa toan bo danh sach" << endl;
	cout << "10. Demo cac chuc nang" << endl;
	cout << "0. Thoat chuong trinh" << endl;
	cout << "===========================================" << endl;
	cout << "Nhap lua chon: ";
}

// Hàm demo các chức năng
void demoChucNang(){
	cout << "\n=== DEMO CAC CHUC NANG ===" << endl;
	
	DanhSachSinhVien ds;
	
	// Tạo một số sinh viên mẫu
	SinhVien sv1(123, "Nguyen Van A", 15, 3, 2000, "Nam", "Ha Noi");
	SinhVien sv2(124, "Tran Thi B", 20, 7, 2001, "Nu", "TP.HCM");
	SinhVien sv3(125, "Le Van C", 10, 12, 1999, "Nam", "Da Nang");
	SinhVien sv4(126, "Pham Thi D", 25, 5, 2002, "Nu", "Hai Phong");
	
	cout << "\n1. Them sinh vien vao cuoi danh sach:" << endl;
	ds.themVaoCuoi(sv1);
	ds.themVaoCuoi(sv2);
	ds.hienThiDanhSach();
	
	cout << "\n2. Them sinh vien vao dau danh sach:" << endl;
	ds.themVaoDau(sv3);
	ds.hienThiDanhSach();
	
	cout << "\n3. Them sinh vien tai vi tri 2:" << endl;
	ds.themTaiViTri(2, sv4);
	ds.hienThiDanhSach();
	
	cout << "\n4. Thay the sinh vien thu 3:" << endl;
	SinhVien sv5(127, "Hoang Van E", 30, 8, 2003, "Nam", "Can Tho");
	ds.thayTheSinhVien(3, sv5);
	ds.hienThiDanhSach();
	
	cout << "\n5. Tim kiem sinh vien co ma 124:" << endl;
	Node* found = ds.timSinhVienTheoMa(124);
	if(found != nullptr){
		cout << "Tim thay sinh vien: ";
		found->getData().xuatThongTin();
	} else {
		cout << "Khong tim thay sinh vien co ma 124!" << endl;
	}
	
	cout << "\n6. Xoa sinh vien thu 2:" << endl;
	if(ds.xoaSinhVien(2)){
		cout << "Xoa thanh cong!" << endl;
	} else {
		cout << "Xoa that bai!" << endl;
	}
	ds.hienThiDanhSach();
	
	cout << "\n7. So luong sinh vien hien tai: " << ds.demSoLuong() << endl;
}

int main(){
	DanhSachSinhVien danhSach;
	int luaChon;
	
	cout << "=== CHUONG TRINH QUAN LY SINH VIEN ===" << endl;
	cout << "Su dung danh sach lien ket don" << endl;
	
	// Demo ban đầu
	demoChucNang();
	
	do{
		hienThiMenu();
		cin >> luaChon;
		
		switch(luaChon){
			case 1: {
				cout << "\n--- THEM SINH VIEN VAO CUOI DANH SACH ---" << endl;
				SinhVien sv;
				sv.nhapThongTin();
				danhSach.themVaoCuoi(sv);
				cout << "Them thanh cong!" << endl;
				break;
			}
			
			case 2: {
				cout << "\n--- THEM SINH VIEN VAO DAU DANH SACH ---" << endl;
				SinhVien sv;
				sv.nhapThongTin();
				danhSach.themVaoDau(sv);
				cout << "Them thanh cong!" << endl;
				break;
			}
			
			case 3: {
				cout << "\n--- XOA SINH VIEN THU I ---" << endl;
				int viTri;
				cout << "Nhap vi tri sinh vien can xoa (1-" << danhSach.demSoLuong() << "): ";
				cin >> viTri;
				
				if(danhSach.xoaSinhVien(viTri)){
					cout << "Xoa thanh cong!" << endl;
				} else {
					cout << "Xoa that bai! Vi tri khong hop le." << endl;
				}
				break;
			}
			
			case 4: {
				cout << "\n--- THAY THE SINH VIEN THU I ---" << endl;
				int viTri;
				cout << "Nhap vi tri sinh vien can thay the (1-" << danhSach.demSoLuong() << "): ";
				cin >> viTri;
				
				SinhVien svMoi;
				cout << "Nhap thong tin sinh vien moi:" << endl;
				svMoi.nhapThongTin();
				
				if(danhSach.thayTheSinhVien(viTri, svMoi)){
					cout << "Thay the thanh cong!" << endl;
				} else {
					cout << "Thay the that bai! Vi tri khong hop le." << endl;
				}
				break;
			}
			
			case 5: {
				cout << "\n--- HIEN THI DANH SACH SINH VIEN ---" << endl;
				danhSach.hienThiDanhSach();
				break;
			}
			
			case 6: {
				cout << "\n--- TIM KIEM SINH VIEN THEO MA ---" << endl;
				int maSV;
				cout << "Nhap ma sinh vien can tim: ";
				cin >> maSV;
				
				Node* found = danhSach.timSinhVienTheoMa(maSV);
				if(found != nullptr){
					cout << "Tim thay sinh vien: " << endl;
					cout << "Ma SV\tHo Ten\t\tNgay Sinh\tGioi Tinh\tQue Quan" << endl;
					cout << "-------------------------------------------------------" << endl;
					found->getData().xuatThongTin();
				} else {
					cout << "Khong tim thay sinh vien co ma " << maSV << "!" << endl;
				}
				break;
			}
			
			case 7: {
				cout << "\n--- THEM SINH VIEN TAI VI TRI I ---" << endl;
				int viTri;
				cout << "Nhap vi tri muon them (1-" << (danhSach.demSoLuong() + 1) << "): ";
				cin >> viTri;
				
				SinhVien sv;
				sv.nhapThongTin();
				
				if(danhSach.themTaiViTri(viTri, sv)){
					cout << "Them thanh cong!" << endl;
				} else {
					cout << "Them that bai! Vi tri khong hop le." << endl;
				}
				break;
			}
			
			case 8: {
				cout << "\n--- DEM SO LUONG SINH VIEN ---" << endl;
				cout << "So luong sinh vien hien tai: " << danhSach.demSoLuong() << endl;
				break;
			}
			
			case 9: {
				cout << "\n--- XOA TOAN BO DANH SACH ---" << endl;
				char xacNhan;
				cout << "Ban co chac chan muon xoa toan bo danh sach? (y/n): ";
				cin >> xacNhan;
				
				if(xacNhan == 'y' || xacNhan == 'Y'){
					danhSach.xoaToanBo();
					cout << "Da xoa toan bo danh sach!" << endl;
				} else {
					cout << "Huy thao tac xoa!" << endl;
				}
				break;
			}
			
			case 10: {
				demoChucNang();
				break;
			}
			
			case 0: {
				cout << "Cam on ban da su dung chuong trinh!" << endl;
				break;
			}
			
			default: {
				cout << "Lua chon khong hop le! Vui long chon lai." << endl;
				break;
			}
		}
		
		if(luaChon != 0){
			cout << "\nNhan Enter de tiep tuc...";
			cin.ignore();
			cin.get();
		}
		
	} while(luaChon != 0);
	
	return 0;
}

