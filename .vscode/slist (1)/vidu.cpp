/*
* GIẢI THÍCH CODE:
*
* 1. Class Sinhvien:
* - Chứa các thuộc tính: masv (mã sinh viên), hoten (họ tên), diemly (điểm lý)
* - Constructor khởi tạo với mã và họ tên, mặc định là 0 và chuỗi rỗng
* - Phương thức In() để hiển thị mã và họ tên
* - set_Diemly() kiểm tra và gán điểm lý trong khoảng [0,10]
* - get_Diemly() trả về điểm lý
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

class Sinhvien
{
	int masv;
	string hoten;
	float diemly; //[0,10]
	
	public:
		Sinhvien(int m=0, string ht="")
		{
			masv = m;
			hoten = ht;		
		}
		void In()
		{
			cout<<masv<<"\t"<<hoten;
		}
		void set_Diemly(float d)
		{
			if(d>=0 && d<=10)
				diemly = d;
			else
				cout<<"Loi gan du lieu";
		}
		float get_Diemly() { return diemly; }		
};

// &l là tham chiếu đến một list chứa các đối tượng Sinhvien
// Dùng tham chiếu để tránh sao chép toàn bộ list khi truyền vào hàm 
// và cho phép thay đổi trực tiếp trên list gốc nếu cần
// Hàm in() nhận tham số là một tham chiếu đến list chứa các đối tượng Sinhvien
// Dùng tham chiếu & để:
// - Tránh sao chép toàn bộ list khi truyền vào hàm (tối ưu bộ nhớ)
// - Cho phép thay đổi trực tiếp trên list gốc nếu cần
void in(list<Sinhvien> &l)
{
    // Dùng iterator để duyệt qua từng phần tử trong list
    // list<Sinhvien>::iterator khai báo một iterator cho list chứa Sinhvien
    // begin() trả về iterator đến phần tử đầu tiên
    // end() trả về iterator sau phần tử cuối cùng
    for(list<Sinhvien>::iterator it = l.begin(); it!=l.end(); it++)
    {
        cout<<"\n"; // Xuống dòng trước khi in mỗi sinh viên
        (*it).In(); // Dùng toán tử * để truy cập đối tượng Sinhvien
                    // và gọi phương thức In() để hiển thị thông tin
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
	
//	list<Sinhvien> l;
//	Sinhvien x(123,"Nguyen Van X");
//	Sinhvien y(124,"Nguyen Thi Y");
//	Sinhvien z(124,"Nguyen Thi z");
//	l.push_back(x);
//	l.push_back(y);
//	l.push_back(z);
//	
//	in(l);
//	list<Sinhvien>::iterator it = l.begin();
//	cout<<"\n*it";
//	(*it).In();
//	
//	Sinhvien t(124,"Nguyen Van T");
//	it++;
//	l.insert(it, t);
//	//l.pop_front();
//	cout<<"\n List sau khi chen phan tu:";
//	in(l);
//	
	
}
