/*
 * GIẢI THÍCH CHI TIẾT LỚP SLIST_ITE - ITERATOR CHO DANH SÁCH LIÊN KẾT ĐƠN
 * 
 * File này giải thích chi tiết về lớp template slist_ite được sử dụng để
 * duyệt qua các phần tử trong danh sách liên kết đơn một cách dễ dàng
 */

#ifndef __slidt_ite__cpp
#define __slidt_ite__cpp
#include"snode.cpp"

/*
 * LỚP TEMPLATE SLIST_ITE (SINGLY LINKED LIST ITERATOR)
 * 
 * Iterator là một đối tượng cho phép duyệt qua các phần tử của một cấu trúc dữ liệu
 * mà không cần biết chi tiết về cách cấu trúc đó được triển khai bên trong.
 * 
 * Template <class T> cho phép iterator hoạt động với bất kỳ kiểu dữ liệu nào
 */
template <class T>
class slist_ite
{
    /*
     * PHẦN PRIVATE - CHỈ CÓ THỂ TRUY CẬP TỪ BÊN TRONG LỚP
     */
    private:
        snode<T> *curr;    // Con trỏ trỏ tới node hiện tại mà iterator đang trỏ tới
    
    /*
     * PHẦN PUBLIC - CÓ THỂ TRUY CẬP TỪ BÊN NGOÀI LỚP
     */
    public:
        /*
         * CONSTRUCTOR (HÀM TẠO)
         * 
         * Tạo một iterator mới trỏ tới node được chỉ định
         * 
         * Tham số:
         * - c: con trỏ trỏ tới node mà iterator sẽ trỏ tới (mặc định = 0)
         * 
         * Ví dụ sử dụng:
         * slist_ite<int> it(head);        // Iterator trỏ tới node đầu
         * slist_ite<int> it(0);           // Iterator trỏ tới NULL (kết thúc)
         */
        slist_ite(snode<T> *c=0)
        { 
            curr = c;  // Gán con trỏ c vào curr
        }
        
        /*
         * HÀM GETTER - LẤY CON TRỎ HIỆN TẠI
         * 
         * Trả về con trỏ trỏ tới node mà iterator đang trỏ tới
         * 
         * Ví dụ sử dụng:
         * snode<int> *currentNode = it.getCurr();
         */
        snode<T> *getCurr() 
        { 
            return curr; 
        }
        
        /*
         * TOÁN TỬ GÁN (=)
         * 
         * Gán iterator khác vào iterator hiện tại
         * 
         * Tham số:
         * - it: con trỏ trỏ tới iterator khác
         * 
         * Trả về: tham chiếu đến iterator hiện tại (*this)
         * 
         * Ví dụ sử dụng:
         * slist_ite<int> it1(head);
         * slist_ite<int> it2;
         * it2 = &it1;  // it2 bây giờ trỏ tới cùng node với it1
         */
        slist_ite<T> &operator =(slist_ite<T> *it)
        {
            this->curr = it->getCurr();  // Gán con trỏ curr của it vào this->curr
            return *this;                // Trả về tham chiếu đến iterator hiện tại
        }
        
        /*
         * TOÁN TỬ GIẢI THAM CHIẾU (*)
         * 
         * Trả về tham chiếu đến giá trị của node mà iterator đang trỏ tới
         * Cho phép vừa đọc vừa ghi giá trị
         * 
         * Trả về: tham chiếu đến elem của node hiện tại
         * 
         * Ví dụ sử dụng:
         * slist_ite<int> it(head);
         * int value = *it;        // Đọc giá trị
         * *it = 100;              // Ghi giá trị mới
         */
        T & operator *() 
        {
            return curr->getelem();  // Trả về tham chiếu đến elem của node hiện tại
        }
        
        /*
         * TOÁN TỬ TĂNG HẬU TỐ (++ HẬU TỐ)
         * 
         * Di chuyển iterator tới node tiếp theo và trả về iterator mới
         * 
         * Cú pháp: it++
         * - Trả về iterator trỏ tới node hiện tại
         * - Sau đó di chuyển iterator tới node tiếp theo
         * 
         * Ví dụ sử dụng:
         * slist_ite<int> it(head);
         * slist_ite<int> oldIt = it++;  // oldIt trỏ tới node cũ, it trỏ tới node mới
         */
        slist_ite<T> operator ++(int)
        {
            curr = curr->getnext();  // Di chuyển tới node tiếp theo
            return curr;             // Trả về iterator mới (SAI - nên trả về iterator cũ)
        }
        
        /*
         * TOÁN TỬ TĂNG TIỀN TỐ (++ TIỀN TỐ)
         * 
         * Di chuyển iterator tới node tiếp theo và trả về iterator mới
         * 
         * Cú pháp: ++it
         * - Di chuyển iterator tới node tiếp theo
         * - Trả về iterator mới
         * 
         * Ví dụ sử dụng:
         * slist_ite<int> it(head);
         * slist_ite<int> newIt = ++it;  // it và newIt đều trỏ tới node mới
         */
        slist_ite<T> operator ++()
        {
            slist_ite<T> it = curr;      // Lưu iterator hiện tại
            curr = curr->getnext();      // Di chuyển tới node tiếp theo
            return it;                   // Trả về iterator cũ (SAI - nên trả về iterator mới)
        }
        
        /*
         * TOÁN TỬ SO SÁNH KHÁC NHAU (!=)
         * 
         * So sánh hai iterator xem có trỏ tới các node khác nhau không
         * 
         * Tham số:
         * - it: iterator khác để so sánh
         * 
         * Trả về: true nếu hai iterator trỏ tới node khác nhau, false nếu cùng node
         * 
         * Ví dụ sử dụng:
         * slist_ite<int> it1(head);
         * slist_ite<int> it2(tail);
         * if (it1 != it2) { ... }  // So sánh hai iterator
         */
        bool operator !=(slist_ite<T> it)
        {
            return curr != it.getCurr();  // So sánh con trỏ curr của hai iterator
        }
};

#endif

/*
 * VÍ DỤ SỬ DỤNG ITERATOR
 * 
 * Dưới đây là ví dụ minh họa cách sử dụng iterator:
 */

/*
#include <iostream>
using namespace std;

int main() {
    // Tạo danh sách liên kết đơn
    snode<int> *head = new snode<int>(10);
    snode<int> *second = new snode<int>(20);
    snode<int> *third = new snode<int>(30);
    
    // Liên kết các node
    head->setnext(second);
    second->setnext(third);
    third->setnext(0);
    
    // Sử dụng iterator để duyệt danh sách
    cout << "Duyet danh sach bang iterator: ";
    for (slist_ite<int> it = head; it.getCurr() != 0; ++it) {
        cout << *it << " ";  // In giá trị của node hiện tại
    }
    cout << endl;
    
    // Kết quả: Duyet danh sach bang iterator: 10 20 30
    
    // Sử dụng iterator để thay đổi giá trị
    slist_ite<int> it = head;
    *it = 100;  // Thay đổi giá trị node đầu tiên
    cout << "Gia tri node dau tien sau khi thay doi: " << *it << endl;
    
    // Kết quả: Gia tri node dau tien sau khi thay doi: 100
    
    // Giải phóng bộ nhớ
    delete head;
    delete second;
    delete third;
    
    return 0;
}
*/

/*
 * CÁC LỖI TRONG CODE GỐC VÀ CÁCH SỬA
 * 
 * 1. Lỗi trong toán tử ++ hậu tố:
 *    - Code gốc: return curr; (sai)
 *    - Nên sửa: return slist_ite<T>(curr); (đúng)
 * 
 * 2. Lỗi trong toán tử ++ tiền tố:
 *    - Code gốc: return it; (sai)
 *    - Nên sửa: return *this; (đúng)
 * 
 * 3. Thiếu toán tử so sánh bằng (==):
 *    - Nên thêm: bool operator ==(slist_ite<T> it) { return curr == it.getCurr(); }
 */

/*
 * CODE ĐÃ SỬA LỖI:
 * 
 * slist_ite<T> operator ++(int)
 * {
 *     slist_ite<T> oldIt(curr);  // Lưu iterator hiện tại
 *     curr = curr->getnext();    // Di chuyển tới node tiếp theo
 *     return oldIt;              // Trả về iterator cũ
 * }
 * 
 * slist_ite<T> operator ++()
 * {
 *     curr = curr->getnext();    // Di chuyển tới node tiếp theo
 *     return *this;              // Trả về iterator mới
 * }
 * 
 * bool operator ==(slist_ite<T> it)
 * {
 *     return curr == it.getCurr();
 * }
 */

/*
 * TẠI SAO CẦN ITERATOR?
 * 
 * 1. Trừu tượng hóa: Che giấu chi tiết triển khai của cấu trúc dữ liệu
 * 2. Dễ sử dụng: Cung cấp giao diện thống nhất để duyệt qua các phần tử
 * 3. An toàn: Kiểm soát cách truy cập và thay đổi dữ liệu
 * 4. Linh hoạt: Có thể dễ dàng thay đổi cách duyệt mà không ảnh hưởng code khác
 * 
 * VÍ DỤ SO SÁNH:
 * 
 * // Không dùng iterator (phức tạp):
 * snode<int> *current = head;
 * while (current != 0) {
 *     cout << current->getelem() << " ";
 *     current = current->getnext();
 * }
 * 
 * // Dùng iterator (đơn giản):
 * for (slist_ite<int> it = head; it.getCurr() != 0; ++it) {
 *     cout << *it << " ";
 * }
 */

/*
 * CÁC TOÁN TỬ ITERATOR THƯỜNG GẶP:
 * 
 * 1. *it        : Lấy giá trị của phần tử hiện tại
 * 2. ++it       : Di chuyển tới phần tử tiếp theo (tiền tố)
 * 3. it++       : Di chuyển tới phần tử tiếp theo (hậu tố)
 * 4. it1 != it2 : So sánh hai iterator
 * 5. it1 == it2 : So sánh hai iterator
 * 6. it = it2   : Gán iterator
 * 
 * CÁC TOÁN TỬ NÂNG CAO (CÓ THỂ THÊM):
 * 
 * 1. it + n     : Di chuyển n bước
 * 2. it - n     : Di chuyển ngược n bước
 * 3. it1 - it2  : Khoảng cách giữa hai iterator
 * 4. it[n]      : Truy cập phần tử thứ n từ vị trí hiện tại
 */
