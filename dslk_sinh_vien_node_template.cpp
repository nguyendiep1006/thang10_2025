#include <bits/stdc++.h>
using namespace std;

template<class T>
class node{
	T elem;
	node *next;
	public:
		node(){
			next = NULL;
		}
		node(T x,node<T> *N=NULL){
			elem = x;
			next = N;
		}
		void setelem(T x){
			elem = x;
		}
		void setnext(node<T> *N=NULL){
			next = N;
		}
		T &getelem(){
			return elem;
		}
		node<T> *&getnext(){ 
			return next;
		}
};

class Student{
	string maSv;
	string hoTen;
	int ngay;
	int thang;
	int nam;
	string gioiTinh;
	string queQuan;
	public:
		Student(){
			maSv = "";
			hoTen = "";
			ngay = 1;
			thang = 1;
			nam = 2000;
			gioiTinh = "";
			queQuan = "";
		}
		Student(string ma, string ten, int d, int m, int y, string gt, string qq){
			maSv = ma;
			hoTen = ten;
			ngay = d;
			thang = m;
			nam = y;
			gioiTinh = gt;
			queQuan = qq;
		}
		string getMaSv() const { return maSv; }
		string getHoTen() const { return hoTen; }
		int getNgay() const { return ngay; }
		int getThang() const { return thang; }
		int getNam() const { return nam; }
		string getGioiTinh() const { return gioiTinh; }
		string getQueQuan() const { return queQuan; }
};

class StudentList{
	node<Student> *head;
	node<Student> *tail;
	int soLuong;
	public:
		StudentList(){
			head = NULL;
			tail = NULL;
			soLuong = 0;
		}
		bool empty(){ return head == NULL; }
		int size(){ return soLuong; }
		void push_back(const Student &s){
			node<Student> *p = new node<Student>(s,NULL);
			if(!head){
				head = tail = p;
			}else{
				tail->setnext(p);
				tail = p;
			}
			soLuong++;
		}
		void push_front(const Student &s){
			node<Student> *p = new node<Student>(s,head);
			head = p;
			if(tail == NULL) tail = p;
			soLuong++;
		}
		bool erase_at(int pos){
			if(pos < 0 || pos >= soLuong || head == NULL) return false;
			if(pos == 0){
				node<Student> *tmp = head;
				head = head->getnext();
				if(head == NULL) tail = NULL;
				delete tmp;
				soLuong--;
				return true;
			}
			node<Student> *cur = head;
			for(int i=0;i<pos-1;i++) cur = cur->getnext();
			node<Student> *tmp = cur->getnext();
			cur->setnext(tmp->getnext());
			if(tmp == tail) tail = cur;
			delete tmp;
			soLuong--;
			return true;
		}
		int find_by_mssv(const string &ma){
			node<Student> *it = head;
			int idx = 0;
			while(it){
				if(it->getelem().getMaSv() == ma) return idx;
				it = it->getnext();
				idx++;
			}
			return -1;
		}
		void print(){
			if(!head){
				cout << "Danh sach sinh vien rong!\n";
				return;
			}
			int stt = 0;
			for(node<Student> *it = head; it!=NULL; it = it->getnext()){
				Student &sv = it->getelem();
				cout << "STT " << stt++ << ": ";
				cout << "MSSV: " << sv.getMaSv() << " | ";
				cout << "Ho ten: " << sv.getHoTen() << " | ";
				cout << "Ngay sinh: " << sv.getNgay() << "/" << sv.getThang() << "/" << sv.getNam() << " | ";
				cout << "Gioi tinh: " << sv.getGioiTinh() << " | ";
				cout << "Que quan: " << sv.getQueQuan() << "\n";
			}
		}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	StudentList ds;
	Student sv1("SV001","Nguyen Van A",15,3,2000,"Nam","Ha Noi");
	Student sv2("SV002","Tran Thi B",20,7,1999,"Nu","Ho Chi Minh");
	Student sv3("SV003","Le Van C",10,12,2001,"Nam","Da Nang");
	ds.push_back(sv1);
	ds.push_back(sv2);
	ds.push_front(sv3);
	cout << "\n--- DANH SACH BAN DAU ---\n";
	ds.print();
	cout << "\nVi tri MSSV SV002: " << ds.find_by_mssv("SV002") << "\n";
	ds.erase_at(1);
	cout << "\n--- SAU KHI XOA VI TRI 1 ---\n";
	ds.print();
	return 0;
}


