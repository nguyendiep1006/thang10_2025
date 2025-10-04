#ifndef __slidt_ite__cpp
#define __slidt_ite__cpp
#include"snode.cpp"
template <class T>
class slist_ite
{
	private:
		snode<T> *curr;
	public:
		slist_ite(snode<T> *c=0)
		{ 
			curr = c;
		}
		snode<T> *getCurr() 
		{ 
			return curr; 
		}
		
		slist_ite<T> &operator =(slist_ite<T> *it)
		{
			this->curr = it->getCurr();
			return *this;
		}
		T & operator *() 
		{
		 	return curr->getelem();	
		}
		slist_ite<T> operator ++(int)
		{
			curr = curr->getnext();
			return curr;
		}
		slist_ite<T> operator ++()
		{
			slist_ite<T> it = curr; 
			curr = curr->getnext();
			return it;
		}
		bool operator !=(slist_ite<T> it)
		{
			return curr != it.getCurr();
		}
};
#endif
