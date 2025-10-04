/*
 * LỚP TEMPLATE SLIST - DANH SÁCH LIÊN KẾT ĐƠN
 *
 * Đây là cài đặt của một danh sách liên kết đơn (singly linked list) sử dụng template.
 * Cho phép lưu trữ dữ liệu của bất kỳ kiểu nào.
 * 
 * Các tính năng chính:
 * - Thêm/xóa phần tử ở đầu và cuối danh sách
 * - Truy cập phần tử đầu và cuối
 * - Duyệt danh sách bằng iterator
 * - Chèn/xóa phần tử tại vị trí bất kỳ
 * 
 * Cấu trúc dữ liệu:
 * - head: Con trỏ đến node đầu tiên
 * - trail: Con trỏ đến node cuối cùng
 * - num: Số phần tử trong danh sách
 * - Mỗi node chứa dữ liệu kiểu T và con trỏ đến node kế tiếp
 */

#ifndef __slist__cpp__
#define __slist__cpp__
#include"snode.cpp"
#include"slistiterator.cpp"

template <class T>
class slist
{
	private:
		snode<T> *head;    // Con trỏ trỏ đến node đầu tiên
		snode<T> *trail;   // Con trỏ trỏ đến node cuối cùng  
		int num;           // Số phần tử hiện có trong danh sách

	public:
		// Constructor mặc định - khởi tạo danh sách rỗng
		// Các con trỏ được gán NULL và số phần tử = 0
		slist<T>()
		{
			head = trail = 0; // NULL
			num = 0;
		}	

		// Constructor với n phần tử có giá trị x
		// Tạo danh sách có n node, mỗi node chứa giá trị x
		slist<T>(int n, T x)
		{
			head = trail = 0;
			num = 0;
			while(n>0)
			{
				push_back(x);
				n--;
			}
		}	

		// Kiểm tra danh sách rỗng
		// Trả về true nếu danh sách không có phần tử nào
		bool empty()
		{
			return num == 0;
		}

		// Trả về số phần tử trong danh sách
		int size() 
		{
			return num;
		}

		// Trả về tham chiếu đến phần tử đầu tiên
		// Cho phép đọc và ghi giá trị của node đầu
		T & front() 
		{ 
			return head->getelem();
		}

		// Trả về tham chiếu đến phần tử cuối cùng
		// Cho phép đọc và ghi giá trị của node cuối
		T & back() 
		{ 
			return trail->getelem();
		}

		// Thêm phần tử vào đầu danh sách
		// Tạo node mới chứa x và nối vào đầu danh sách
		void push_front(T x)
		{
			snode<T>* newnode = new snode<T>(x);
			if(newnode==0) // Kiểm tra cấp phát thành công
				return;
			if(empty())
				head = trail = newnode;
			else
			{			
				newnode->setnext(head);
				head = newnode;
			}
			num++;
		}

		// Thêm phần tử vào cuối danh sách
		// Tạo node mới chứa x và nối vào cuối danh sách
		void push_back(T x)
		{
			snode<T>* newnode = new snode<T>(x);
			if(newnode==0) // Kiểm tra cấp phát thành công
				return;
			if(empty() || num==1)
				head = trail = newnode;
			else
			{
				trail->setnext(newnode);
				trail = newnode;
			}
			num++;	
		}

		// Xóa phần tử đầu tiên
		// Giải phóng node đầu và cập nhật head
		void pop_front()
		{
			if(num==1) // Trường hợp chỉ có 1 phần tử
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

		// Xóa phần tử cuối cùng
		// Giải phóng node cuối và cập nhật trail
		void pop_back()
		{
			if(num==1) // Trường hợp chỉ có 1 phần tử
			{
				delete trail;
				head = trail = 0;
				num--;
			}
			else
			{
				snode<T> *p = head;
				while(p->getnext()!=trail) // Tìm node kế cuối
					p = p->getnext();
				p->setnext(0);
				delete trail;
				trail = p;
				num--;
			}
				
		}
			
		// Định nghĩa kiểu iterator để duyệt danh sách
		/*
		 * ĐỊNH NGHĨA KIỂU ITERATOR VÀ CÁC PHƯƠNG THỨC LIÊN QUAN
		 */
		
		// Định nghĩa kiểu iterator để duyệt danh sách
		// slist_ite<T> là lớp iterator được định nghĩa riêng
		typedef slist_ite<T> iterator;
		
		/*
		 * PHƯƠNG THỨC BEGIN() - LẤY ITERATOR ĐẦU TIÊN
		 * 
		 * Trả về iterator trỏ đến node đầu tiên (head) của danh sách
		 * Dùng để bắt đầu duyệt danh sách từ đầu
		 * 
		 * Ví dụ:
		 * for(iterator it = list.begin(); it != list.end(); it++)
		 */
		iterator begin() 
		{
			return head;  // Trả về iterator trỏ tới head
		}

		/*
		 * PHƯƠNG THỨC END() - LẤY ITERATOR KẾT THÚC
		 * 
		 * Trả về iterator trỏ đến NULL (sau node cuối)
		 * Dùng làm điểm dừng khi duyệt danh sách
		 * 
		 * Ví dụ:
		 * while(it != list.end()) {...}
		 */
		iterator end()
		{
			return iterator(0);  // Trả về iterator trỏ tới NULL
		}	
		
		/*
		 * PHƯƠNG THỨC INSERT() - CHÈN PHẦN TỬ
		 * 
		 * Chèn phần tử x vào sau vị trí iterator it
		 * Tham số:
		 * - it: vị trí chèn (chèn sau vị trí này)
		 * - x: giá trị cần chèn
		 * 
		 * Các bước:
		 * 1. Tạo node mới chứa giá trị x
		 * 2. Kiểm tra nếu chèn sau node cuối
		 * 3. Nếu không thì chèn vào giữa danh sách
		 * 4. Tăng số lượng phần tử
		 */
		void insert(iterator it,T x)
		{
			snode<T>* newnode = new snode<T>(x);  // Tạo node mới
			if(newnode==0)  // Kiểm tra cấp phát thành công
				return ;
			if(it.getCurr()==trail)  // Chèn sau node cuối
			{
				trail->setnext(newnode);  // Nối node cuối với node mới
				trail = newnode;  // Cập nhật trail         			
			}
			else  // Chèn vào giữa danh sách
			{
				snode<T> *p = it.getCurr();	
				newnode->setnext(p->getnext());  // Nối node mới với node sau
				p->setnext(newnode);  // Nối node hiện tại với node mới		
			}
			num++;  // Tăng số lượng phần tử
		}

		/*
		 * PHƯƠNG THỨC ERASE() - XÓA PHẦN TỬ
		 * 
		 * Xóa phần tử tại vị trí iterator it
		 * Tham số:
		 * - it: vị trí cần xóa
		 * 
		 * Các bước:
		 * 1. Kiểm tra nếu xóa node đầu/cuối -> gọi hàm tương ứng
		 * 2. Nếu xóa node giữa:
		 *    - Tìm node trước node cần xóa
		 *    - Nối node trước với node sau node cần xóa
		 * 3. Giảm số lượng phần tử
		 */
		void erase(iterator it)
		{
			if(it.getCurr()==head)  // Xóa node đầu
				pop_front();
			if(it.getCurr()==trail)  // Xóa node cuối  
				pop_back();
			snode<T> *p = head;
			while(p->getnext()!=it.getCurr())  // Tìm node trước node cần xóa
				p = p->getnext();
			p->setnext(it.getCurr()->getnext());  // Nối lại các liên kết
			num--;  // Giảm số lượng phần tử
		}	
};

#endif
