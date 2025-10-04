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

void in(list<Sinhvien> &l)
{
	for(list<Sinhvien>::iterator it = l.begin(); it!=l.end(); it++)
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
