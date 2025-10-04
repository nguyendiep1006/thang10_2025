/*
* GIẢI THÍCH CODE:
*
* 1. Class Sinhvien:
* - Chứa các thuộc tính: masv (mã sinh viên), hoten (họ tên), diemly (điểm lý)
* - Constructor khởi tạo với mã và họ tên, mặc định là 0 và chuỗi rỗng
* - Phương thức In() để hiển thị mã và họ tên
* - set_Diemly() kiểm tra và gán điểm lý theo kiểu T
* - get_Diemly() trả về điểm lý kiểu T
*
* 2. Hàm in():
* - Nhận tham chiếu đến list sinh viên
* - Duyệt list bằng iterator và in thông tin từng sinh viên
*
* 3. Hàm main():
* - Khai báo mảng 2 chiều a[10][100]
* - Tạo list chứa list số nguyên (ls) và vector chứa list số nguyên (v)
* 
* - Tạo và thêm dữ liệu vào 2 list l1, l2:
*   + l1: 100, 200
*   + l2: 300, 500, 1000
*
* - Thêm l1, l2 vào ls
* 
* - Duyệt và in ls (list chứa các list):
*   + Dùng iterator lồng nhau để duyệt từng list con
*   + In các phần tử của từng list con
*
* - Phần code bị comment:
*   + Tạo list sinh viên và thêm 3 sinh viên x,y,z
*   + In danh sách sinh viên
*   + Chèn thêm sinh viên t vào sau phần tử đầu tiên
*   + In lại danh sách sau khi chèn
*/
 
#include<bits/stdc++.h>
using namespace std;

template <class T>
class Sinhvien
{
	int masv;
	string hoten;
	T diemly;
	
	public:
		Sinhvien(int m=0, string ht="")
		{
			masv = m;
			hoten = ht;		
		}
		void In()
		{
			cout<<masv<<"\t"<<hoten<<"\t"<<diemly;
		}
		void set_Diemly(T d)
		{
			diemly = d;
		}
		T get_Diemly() { return diemly; }		
};

template <class T>
void in(list<Sinhvien<T>> &l)
{
    for(typename list<Sinhvien<T>>::iterator it = l.begin(); it!=l.end(); it++)
    {
        cout<<"\n";
        (*it).In();
    }
}

int main()
{
	int a[10][100];
	list<list<int>> ls;
	vector<list<int>> v;
	
	list<int> l1, l2;
	l1.push_back(100);
	l1.push_back(200);	
	
	l2.push_back(300);
	l2.push_back(500);	
	l2.push_back(1000);	
	
	ls.push_back(l1);
	ls.push_back(l2);
	
	for(list<list<int>>::iterator it=ls.begin(); it!=ls.end();it++)
	{
		cout<<"\n";
		for(list<int>::iterator it2 = (*it).begin(); it2!=(*it).end(); it2++)
			cout<<*it2<<"\t";
	}
	
//	list<Sinhvien<float>> l;
//	Sinhvien<float> x(123,"Nguyen Van X");
//	Sinhvien<float> y(124,"Nguyen Thi Y"); 
//	Sinhvien<float> z(124,"Nguyen Thi Z");
//	x.set_Diemly(8.5);
//	y.set_Diemly(7.5);
//	z.set_Diemly(9.0);
//	l.push_back(x);
//	l.push_back(y);
//	l.push_back(z);
//	
//	in(l);
//	list<Sinhvien<float>>::iterator it = l.begin();
//	cout<<"\n*it";
//	(*it).In();
//	
//	Sinhvien<float> t(124,"Nguyen Van T");
//	t.set_Diemly(8.0);
//	it++;
//	l.insert(it, t);
//	cout<<"\n List sau khi chen phan tu:";
//	in(l);
	
}
