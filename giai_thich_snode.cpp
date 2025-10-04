/*
 * GIẢI THÍCH CHI TIẾT LỚP SNODE - NODE CHO DANH SÁCH LIÊN KẾT ĐƠN
 * 
 * File này giải thích chi tiết về lớp template snode được sử dụng để tạo
 * các node trong danh sách liên kết đơn (singly linked list)
 */

#ifndef __node_slist_cpp__
#define __node_slist_cpp__

/*
 * LỚP TEMPLATE SNODE
 * 
 * Đây là một lớp template, có nghĩa là có thể sử dụng với bất kỳ kiểu dữ liệu nào
 * (int, float, string, class, struct, ...)
 * 
 * Template <class T> cho phép T là kiểu dữ liệu bất kỳ
 */
template <class T>
class snode
{
    /*
     * PHẦN PRIVATE - CHỈ CÓ THỂ TRUY CẬP TỪ BÊN TRONG LỚP
     */
    private:
        T elem;           // Phần tử dữ liệu (element) - lưu trữ giá trị thực tế
        snode *next;      // Con trỏ trỏ tới node tiếp theo trong danh sách
    
    /*
     * PHẦN PUBLIC - CÓ THỂ TRUY CẬP TỪ BÊN NGOÀI LỚP
     */
    public:
        /*
         * CONSTRUCTOR MẶC ĐỊNH (HÀM TẠO KHÔNG THAM SỐ)
         * 
         * Tạo một node mới với:
         * - elem: giá trị mặc định của kiểu T (0 cho số, rỗng cho string, ...)
         * - next: trỏ tới NULL (0) - nghĩa là không có node tiếp theo
         */
        snode<T>()
        {
            next = 0;  // Khởi tạo con trỏ next = NULL
        }
        
        /*
         * CONSTRUCTOR CÓ THAM SỐ (HÀM TẠO CÓ THAM SỐ)
         * 
         * Tạo một node mới với:  
         * - elem: nhận giá trị x
         * - next: nhận con trỏ Next (mặc định là 0 nếu không truyền vào)
         * 
         * Tham số:
         * - x: giá trị cần lưu trong node
         * - Next: con trỏ trỏ tới node tiếp theo (tùy chọn, mặc định = 0)
         */
        snode<T>(T x, snode<T> *Next=0)
        {
            elem = x;      // Gán giá trị x vào elem
            next = Next;   // Gán con trỏ Next vào next
        }
        
        /* 
         * HÀM GETTER - LẤY GIÁ TRỊ ELEM
         * 
         * Trả về tham chiếu (&) đến elem
         * Tham chiếu cho phép vừa đọc vừa ghi giá trị
         * 
         * Ví dụ sử dụng:
         * snode<int> node(5);
         * int value = node.getelem();  // Đọc giá trị
         * node.getelem() = 10;         // Ghi giá trị mới
         */
        T & getelem() 
        { 
            return elem;
        }
        
        /*
         * HÀM GETTER - LẤY CON TRỎ NEXT
         * 
         * Trả về con trỏ trỏ tới node tiếp theo
         * 
         * Ví dụ sử dụng:
         * snode<int> *nextNode = node.getnext();
         */
        snode<T> * getnext()
        {
            return next;
        }
        
        /*
         * HÀM SETTER - THIẾT LẬP GIÁ TRỊ ELEM
         * 
         * Gán giá trị mới cho elem
         * 
         * Tham số:
         * - x: giá trị mới cần gán
         * 
         * Ví dụ sử dụng:
         * node.setelem(100);
         */
        void setelem(T x) 
        {
            elem = x;
        }
        
        /*
         * HÀM SETTER - THIẾT LẬP CON TRỎ NEXT
         * 
         * Gán con trỏ mới cho next
         * 
         * Tham số:
         * - Next: con trỏ mới trỏ tới node tiếp theo
         * 
         * Ví dụ sử dụng:
         * snode<int> *newNode = new snode<int>(50);
         * node.setnext(newNode);
         */
        void setnext(snode<T> *Next)
        {
            next = Next;
        }
        
        /*
         * HÀM TOÁN TỬ TĂNG (ĐÃ BỊ COMMENT)
         * 
         * Hàm này đã bị comment vì có thể gây nhầm lẫn
         * Nó định nghĩa toán tử ++ để trả về node tiếp theo
         * 
         * Nếu sử dụng, có thể viết:
         * snode<int> *nextNode = node++;  // Tương đương node.getnext()
         */
        //		snode<T>* operator ++(int)
        //		{
        //			return next;
        //		} 
};

#endif

/*
 * VÍ DỤ SỬ DỤNG LỚP SNODE
 * 
 * Dưới đây là ví dụ minh họa cách sử dụng lớp snode:
 */

/*
#include <iostream>
using namespace std;

int main() {
    // Tạo node đầu tiên với giá trị 10
    snode<int> *head = new snode<int>(10);
    
    // Tạo node thứ hai với giá trị 20
    snode<int> *second = new snode<int>(20);
    
    // Tạo node thứ ba với giá trị 30
    snode<int> *third = new snode<int>(30);
    
    // Liên kết các node với nhau
    head->setnext(second);      // head -> second
    second->setnext(third);     // second -> third
    third->setnext(0);          // third -> NULL (kết thúc danh sách)
    
    // Duyệt và in danh sách
    cout << "Danh sach lien ket: ";
    snode<int> *current = head;
    while (current != 0) {
        cout << current->getelem() << " ";
        current = current->getnext();
    }
    cout << endl;
    
    // Kết quả: Danh sach lien ket: 10 20 30
    
    // Giải phóng bộ nhớ
    delete head;
    delete second;
    delete third;
    
    return 0;
}
*/

/*
 * CẤU TRÚC CỦA MỘT NODE TRONG DANH SÁCH LIÊN KẾT ĐƠN
 * 
 * Mỗi node có cấu trúc như sau:
 * 
 * +--------+    +--------+    +--------+
 * |  elem  |    |  elem  |    |  elem  |
 * |  next  |--->|  next  |--->|  next  |---> NULL
 * +--------+    +--------+    +--------+
 *    Node 1        Node 2        Node 3
 * 
 * - elem: chứa dữ liệu thực tế
 * - next: con trỏ trỏ tới node tiếp theo
 * - Node cuối cùng có next = NULL
 */

/*
 * ƯU ĐIỂM CỦA DANH SÁCH LIÊN KẾT ĐƠN:
 * 
 * 1. Linh hoạt về kích thước: có thể thêm/xóa phần tử dễ dàng
 * 2. Tiết kiệm bộ nhớ: chỉ cấp phát khi cần thiết
 * 3. Thao tác chèn/xóa nhanh: O(1) nếu biết vị trí
 * 
 * NHƯỢC ĐIỂM:
 * 
 * 1. Không truy cập trực tiếp: phải duyệt từ đầu để tìm phần tử
 * 2. Tốn bộ nhớ cho con trỏ: mỗi node cần thêm 1 con trỏ
 * 3. Không cache-friendly: các node có thể nằm rải rác trong bộ nhớ
 */

/*
 * CÁC THAO TÁC CƠ BẢN VỚI DANH SÁCH LIÊN KẾT ĐƠN:
 * 
 * 1. Tạo node mới:
 *    snode<int> *newNode = new snode<int>(value);
 * 
 * 2. Chèn vào đầu:
 *    newNode->setnext(head);
 *    head = newNode;
 * 
 * 3. Chèn vào cuối:
 *    tail->setnext(newNode);
 *    tail = newNode;
 * 
 * 4. Xóa node:
 *    prev->setnext(current->getnext());
 *    delete current;
 * 
 * 5. Duyệt danh sách:
 *    snode<int> *current = head;
 *    while (current != 0) {
 *        // Xử lý current->getelem()
 *        current = current->getnext();
 *    }
 */
