#ifndef __node_slist_cpp__
#define __node_slist_cpp__
template <class T>
class snode
{
	private:
		T elem;
		snode *next;
	public:
		snode<T>()
		{
			next = 0;
		}
		snode<T>(T x, snode<T> *Next=0)
		{
			elem = x;
			next = Next;
		}
		T & getelem() 
		{ 
			return elem;
		}
		snode<T> * getnext()
		{
			return next;
		}		
		void setelem(T x) 
		{
			elem = x;
		}
		void setnext(snode<T> *Next)
		{
		 	next = Next;
		}
//		snode<T>* operator ++(int)
//		{
//			return next;
//		} 
};
#endif
