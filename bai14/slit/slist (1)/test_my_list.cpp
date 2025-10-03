#include"slist.cpp"
#include<bits/stdc++.h>
using namespace std;
int main()
{
	slist<int> s;
	s.push_back(100);
	s.push_back(200);
	s.push_back(300);
	s.push_back(1000);
	s.push_front(5000);
	//cout<<s.front()<<"\n"<<s.back();
//	slist<int>::iterator it1 = s.begin();
//	it1++;
//	s.insert(it1, 500);
//	s.erase(it1);
	for(slist<int>::iterator it = s.begin(); it!=s.end(); it++)
		cout<< *it<<"\t";
}
