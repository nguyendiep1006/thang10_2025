/*
 * FILE TEST DANH SÁCH LIÊN KẾT ĐƠN
 * 
 * File này test các chức năng của lớp slist (singly linked list)
 * và minh họa cách sử dụng iterator để duyệt qua các phần tử
 */

#include"slist.cpp"        // Include file định nghĩa lớp slist
#include<bits/stdc++.h>    // Include thư viện chuẩn C++
using namespace std;

int main()
{
	/*
	 * TẠO ĐỐI TƯỢNG DANH SÁCH LIÊN KẾT
	 * 
	 * slist<int> s: Tạo một danh sách liên kết đơn chứa các số nguyên
	 * - s là tên biến
	 * - int là kiểu dữ liệu của các phần tử
	 * - Danh sách ban đầu rỗng
	 */
	slist<int> s;
	
	/*
	 * THÊM PHẦN TỬ VÀO CUỐI DANH SÁCH
	 * 
	 * push_back(): Thêm phần tử vào cuối danh sách
	 * - Thứ tự thêm: 100 -> 200 -> 300 -> 1000
	 * - Danh sách sau khi thêm: [100, 200, 300, 1000]
	 */
	s.push_back(100);   // Thêm 100 vào cuối
	s.push_back(200);   // Thêm 200 vào cuối
	s.push_back(300);   // Thêm 300 vào cuối
	s.push_back(1000);  // Thêm 1000 vào cuối
	
	/*
	 * THÊM PHẦN TỬ VÀO ĐẦU DANH SÁCH
	 * 
	 * push_front(): Thêm phần tử vào đầu danh sách
	 * - Thêm 5000 vào đầu
	 * - Danh sách sau khi thêm: [5000, 100, 200, 300, 1000]
	 */
	s.push_front(5000);
	
	/*
	 * CÁC DÒNG CODE BỊ COMMENT (ĐÃ BỊ VÔ HIỆU HÓA)
	 * 
	 * Những dòng này minh họa các chức năng khác của danh sách:
	 */
	
	// Lấy phần tử đầu và cuối danh sách
	//cout<<s.front()<<"\n"<<s.back();
	// - s.front(): Trả về phần tử đầu tiên (5000)
	// - s.back(): Trả về phần tử cuối cùng (1000)
	
	// Sử dụng iterator để chèn và xóa phần tử
	//slist<int>::iterator it1 = s.begin();  // Tạo iterator trỏ tới phần tử đầu
	//it1++;                                  // Di chuyển iterator tới phần tử thứ 2
	//s.insert(it1, 500);                    // Chèn 500 vào vị trí iterator đang trỏ
	//s.erase(it1);                          // Xóa phần tử tại vị trí iterator đang trỏ
	
	/*
	 * DUYỆT DANH SÁCH BẰNG ITERATOR
	 * 
	 * Vòng lặp for sử dụng iterator để duyệt qua tất cả phần tử:
	 * 
	 * for(slist<int>::iterator it = s.begin(); it!=s.end(); it++)
	 * 
	 * Giải thích từng phần:
	 * - slist<int>::iterator: Kiểu iterator cho danh sách slist<int>
	 * - it: Tên biến iterator
	 * - s.begin(): Iterator trỏ tới phần tử đầu tiên
	 * - it!=s.end(): Điều kiện dừng (khi iterator chưa đến cuối)
	 * - s.end(): Iterator trỏ tới vị trí sau phần tử cuối cùng
	 * - it++: Di chuyển iterator tới phần tử tiếp theo
	 * - *it: Lấy giá trị của phần tử mà iterator đang trỏ tới
	 */
	for(slist<int>::iterator it = s.begin(); it!=s.end(); it++)
		cout<< *it<<"\t";  // In giá trị phần tử hiện tại, cách nhau bởi tab
	
	/*
	 * KẾT QUẢ MONG ĐỢI:
	 * 5000    100     200     300     1000
	 * 
	 * Giải thích thứ tự:
	 * 1. 5000 được thêm vào đầu bằng push_front()
	 * 2. 100, 200, 300, 1000 được thêm vào cuối bằng push_back()
	 * 3. Iterator duyệt từ đầu đến cuối danh sách
	 */
	
	return 0;  // Kết thúc chương trình
}

/*
 * TÓM TẮT CÁC CHỨC NĂNG ĐƯỢC SỬ DỤNG:
 * 
 * 1. slist<int> s: Tạo danh sách liên kết đơn
 * 2. s.push_back(value): Thêm phần tử vào cuối
 * 3. s.push_front(value): Thêm phần tử vào đầu
 * 4. s.begin(): Iterator trỏ tới phần tử đầu
 * 5. s.end(): Iterator trỏ tới vị trí sau phần tử cuối
 * 6. *it: Lấy giá trị phần tử mà iterator đang trỏ
 * 7. it++: Di chuyển iterator tới phần tử tiếp theo
 * 8. it!=s.end(): So sánh iterator với vị trí kết thúc
 * 
 * CÁC CHỨC NĂNG KHÁC (ĐÃ BỊ COMMENT):
 * - s.front(): Lấy phần tử đầu tiên
 * - s.back(): Lấy phần tử cuối cùng
 * - s.insert(it, value): Chèn phần tử tại vị trí iterator
 * - s.erase(it): Xóa phần tử tại vị trí iterator
 */
