#ifndef __slist__cpp__
#define __slist__cpp__
#include"snode.cpp"
#include"slistiterator.cpp"
template <class T>
class slist
{
	private:
		snode<T> *head;
		snode<T> *trail;
		int num; //So phan tu hien co cua list
	public:
		slist<T>()
		{
			head = trail = 0; //NULL
			num = 0;
		}	
		slist<T>(int n, T x)
		{
			head = trail = 0; //NULL
			num = 0;
			while(n>0)
			{
				push_back(x);
				n--;
			}
		}	
		bool empty()
		{
			return num == 0;
		}
		int size() 
		{
			return num;
		}
		T & front() 
		{ 
			return head->getelem();
		}
		T & back() 
		{ 
			return trail->getelem();
		}
		void push_front(T x)
		{
			snode<T>* newnode = new snode<T>(x);
			if(newnode==0)
				return;
			if(empty())
				head = trail = newnode;
			else
			{			
				newnode->setnext(head);
				head =  newnode;
			}
			num++;
		}
		void push_back(T x)
		{
			snode<T>* newnode = new snode<T>(x);
			if(newnode==0)
				return;
			if(empty())
				head = trail = newnode;
			else
			{
				trail->setnext(newnode);
				trail = newnode;
			}
			num++;	
		}
		void pop_front()
		{
			if(num==1)
			{
				delete head;
				head = trail = 0;
				num--;
			}
			else
			{
				snode<T> *p = head;
				head = head->getnext();
				delete p;
				num--;
			}
						
		}	
		void pop_back()
		{
			if(num==1)
			{
				delete trail;
				head = trail = 0;
				num--;
			}
			else
			{
				snode<T> *p = head;
				while(p->getnext()!=trail)
					p = p->getnext();
				p->setnext(0);
				delete trail;
				trail = p;
				num--;
			}
				
		}
			
		typedef slist_ite<T> iterator;
		
		iterator begin() 
		{
			return head;
		}
		iterator end()
		{
			return iterator(0);
		}	
		
		void insert(iterator it,T x)
		{
			snode<T>* newnode =  new snode<T>(x);
			if(newnode==0)
				return ;
			if(it.getCurr()==trail)
			{
				trail->setnext(newnode);
				trail = newnode;			
			}
			else
			{
				snode<T> *p= it.getCurr();	
				newnode->setnext(p->getnext());
				p->setnext(newnode);			
			}
			num++;
		}
		void erase(iterator it)
		{
			if(it.getCurr()==head)
				pop_front();
			if(it.getCurr()==trail)
				pop_back();
			snode<T> *p = head;
			while(p->getnext()!=it.getCurr()) 
				p = p->getnext();
			p->setnext(it.getCurr()->getnext());
			num--;	
			
		}	
};

#endif
