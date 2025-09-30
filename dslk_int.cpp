#include <bits/stdc++.h>
using namespace std;

class Node{
	int data;
	Node *next;
	public:
		Node(int x, Node *n=NULL){ data = x; next = n; }
		int getData(){ return data; }
		void setData(int x){ data = x; }
		Node* getNext(){ return next; }
		void setNext(Node *n){ next = n; }
};

class SinglyLinkedList{
	Node *head;
	Node *tail;
	int sz;
	public:
		SinglyLinkedList(){ head = NULL; tail = NULL; sz = 0; }
		bool empty(){ return head == NULL; }
		int count(){ return sz; }
		void push_front(int x){ Node *p = new Node(x, head); head = p; if(tail == NULL) tail = p; sz++; }
		void push_back(int x){ Node *p = new Node(x,NULL); if(!head){ head = tail = p; } else { tail->setNext(p); tail = p; } sz++; }
		bool pop_front(){ if(!head) return false; Node *t=head; head=head->getNext(); if(head==NULL) tail=NULL; delete t; sz--; return true; }
		bool pop_back(){ if(!head) return false; if(head==tail){ delete head; head=tail=NULL; sz--; return true; } Node *c=head; while(c->getNext()!=tail) c=c->getNext(); delete tail; tail=c; tail->setNext(NULL); sz--; return true; }
		Node* find(int x){ for(Node *it=head; it; it=it->getNext()) if(it->getData()==x) return it; return NULL; }
		void print(){ for(Node *it=head; it; it=it->getNext()) cout<<it->getData()<<" "; cout<<"\n"; }
		void sort_desc(){ if(sz<2) return; for(Node *i=head;i;i=i->getNext()) for(Node *j=i->getNext();j;j=j->getNext()) if(i->getData()<j->getData()){ int a=i->getData(), b=j->getData(); i->setData(b); j->setData(a); } }
		void insert_keep_desc(int x){ Node *p=new Node(x); if(!head){ head=tail=p; sz++; return; } if(x>=head->getData()){ p->setNext(head); head=p; sz++; return; } if(x<=tail->getData()){ tail->setNext(p); tail=p; sz++; return; } Node *c=head; while(c->getNext() && c->getNext()->getData()>x) c=c->getNext(); p->setNext(c->getNext()); c->setNext(p); sz++; }
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	SinglyLinkedList lst;
	cout << "Nhap cac so nguyen duong, ket thuc khi nhap so am:\n";
	while(true){ int x; if(!(cin>>x)) return 0; if(x<0) break; lst.push_back(x); }

	int ch;
	do{
		cout<<"\n1 push_front | 2 push_back | 3 print\n";
		cout<<"4 count | 5 find X | 6 pop_front | 7 pop_back\n";
		cout<<"8 sort_desc | 9 insert X (desc) | 0 exit\nChon: ";
		cin>>ch;
		switch(ch){
			case 1:{ int x; cout<<"x: "; cin>>x; if(x>=0) lst.push_front(x); else cout<<"x>=0\n"; break; }
			case 2:{ int x; cout<<"x: "; cin>>x; if(x>=0) lst.push_back(x); else cout<<"x>=0\n"; break; }
			case 3:{ lst.print(); break; }
			case 4:{ cout<<lst.count()<<"\n"; break; }
			case 5:{ int x; cout<<"X: "; cin>>x; cout<<(lst.find(x)?"Found\n":"Not found\n"); break; }
			case 6:{ cout<<(lst.pop_front()?"OK\n":"Empty\n"); break; }
			case 7:{ cout<<(lst.pop_back()?"OK\n":"Empty\n"); break; }
			case 8:{ lst.sort_desc(); cout<<"Sorted\n"; break; }
			case 9:{ int x; cout<<"X: "; cin>>x; if(x>=0){ lst.insert_keep_desc(x); cout<<"Inserted\n"; } else cout<<"X>=0\n"; break; }
			case 0: break;
			default: cout<<"?\n";
		}
	} while(ch!=0);
	return 0;
}
