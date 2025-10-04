#ifndef SINHVIEN_H
#define SINHVIEN_H

#include<iostream>
#include<string>
using namespace std;

/*
 * LỚP SINHVIEN - LƯU TRỮ THÔNG TIN SINH VIÊN
 * 
 * Các thuộc tính:
 * - MaSV: Mã sinh viên (int)
 * - Hoten: Họ tên (string)
 * - Ngay: Ngày sinh (int)
 * - Thang: Tháng sinh (int)
 * - Nam: Năm sinh (int)
 * - GioiTinh: Giới tính (string)
 * - QueQuan: Quê quán (string)
 * 
 * Các phương thức:
 * - Constructor, destructor
 * - Getter/Setter cho các thuộc tính
 * - Phương thức nhập/xuất thông tin
 * - Phương thức kiểm tra tính hợp lệ của ngày sinh
 */

class SinhVien{
	private:
		int MaSV;
		string Hoten;
		int Ngay, Thang, Nam;
		string GioiTinh;
		string QueQuan;
		
	public:
		// Constructor mặc định
		SinhVien();
		
		// Constructor với tham số
		SinhVien(int ma, string ht, int ngay, int thang, int nam, string gt, string qq);
		
		// Destructor
		~SinhVien();
		
		// Copy constructor
		SinhVien(const SinhVien &sv);
		
		// Assignment operator
		SinhVien& operator=(const SinhVien &sv);
		
		// Getter methods
		int getMaSV() const;
		string getHoten() const;
		int getNgay() const;
		int getThang() const;
		int getNam() const;
		string getGioiTinh() const;
		string getQueQuan() const;
		
		// Setter methods
		void setMaSV(int ma);
		void setHoten(string ht);
		void setNgay(int ngay);
		void setThang(int thang);
		void setNam(int nam);
		void setGioiTinh(string gt);
		void setQueQuan(string qq);
		
		// Phương thức kiểm tra tính hợp lệ của ngày sinh
		bool kiemTraNgaySinh() const;
		
		// Phương thức nhập thông tin sinh viên
		void nhapThongTin();
		
		// Phương thức xuất thông tin sinh viên
		void xuatThongTin() const;
		
		// Phương thức tính tuổi
		int tinhTuoi() const;
		
		// Operator so sánh
		bool operator==(const SinhVien &sv) const;
		bool operator!=(const SinhVien &sv) const;
};

#endif
