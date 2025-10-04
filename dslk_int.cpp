#include <bits/stdc++.h>
using namespace std;

// Lớp Node đại diện cho một nút trong danh sách liên kết
class Node {
    private:
        int data;      // Giá trị của nút
        Node *next;    // Con trỏ trỏ đến nút tiếp theo
    public:
        // Hàm tạo với tham số x là giá trị, n là con trỏ next (mặc định là NULL)
        Node(int x, Node *n = NULL) {
            data = x;
            next = n;
        }
        int getData() { return data; }         // Lấy giá trị của nút
        void setData(int x) { data = x; }      // Gán giá trị cho nút
        Node* getNext() { return next; }       // Lấy con trỏ next
        void setNext(Node *n) { next = n; }    // Gán con trỏ next
};

// Lớp SinglyLinkedList đại diện cho danh sách liên kết đơn
class SinglyLinkedList {
    private:
        Node *head;    // Con trỏ trỏ đến nút đầu
        Node *tail;    // Con trỏ trỏ đến nút cuối
        int sz;        // Số lượng phần tử trong danh sách
    
    public:
        // Hàm tạo khởi tạo danh sách rỗng
        SinglyLinkedList() {
            head = NULL;
            tail = NULL;
            sz = 0;
        }
        
        // Kiểm tra danh sách rỗng
        bool empty() { return head == NULL; }
        // Trả về số lượng phần tử
        int count() { return sz; }
        
        // Thêm phần tử x vào đầu danh sách
        void push_front(int x) {
            Node *p = new Node(x, head);   // Tạo nút mới p trỏ đến head
            head = p;                      // Cập nhật head là p
            if(tail == NULL) tail = p;     // Nếu danh sách rỗng thì tail cũng là p
            sz++;                          // Tăng số lượng phần tử
        }
        
        // Thêm phần tử x vào cuối danh sách
        void push_back(int x) {
            // Tạo node mới p với giá trị x và con trỏ next là NULL
            Node *p = new Node(x, NULL);
            
            // Nếu danh sách rỗng (head == NULL)
            if(!head) {
                // Gán cả head và tail cùng trỏ tới node mới p
                head = tail = p;
            }
            // Nếu danh sách không rỗng
            else {
                // Nối node cuối cùng (tail) với node mới p
                tail->setNext(p);
                // Cập nhật tail trỏ tới node mới p
                tail = p;
            }
            // Tăng số lượng phần tử
            sz++;
        }

        // Xóa phần tử đầu danh sách
        bool pop_front() {
            if(!head) return false;        // Nếu rỗng thì không xóa được
            Node *t = head;                // Lưu lại nút đầu để giải phóng
            head = head->getNext();        // Cập nhật head là nút tiếp theo
            if(head == NULL) tail = NULL;  // Nếu sau khi xóa danh sách rỗng thì tail = NULL
            delete t;                      // Giải phóng nút đầu cũ
            sz--;                          // Giảm số lượng phần tử
            return true;                   // Xóa thành công
        }
        
        // Xóa phần tử cuối danh sách
        bool pop_back() {
            if(!head) return false;        // Nếu rỗng thì không xóa được
            if(head == tail) {             // Nếu chỉ có 1 phần tử
                delete head;               // Giải phóng nút duy nhất
                head = tail = NULL;        // Cập nhật head, tail là NULL
                sz--;                      // Giảm số lượng phần tử
                return true;               // Xóa thành công
            }
            Node *c = head;                // Duyệt từ đầu
            while(c->getNext() != tail)    // Tìm nút trước tail
                c = c->getNext();
            delete tail;                   // Giải phóng tail
            tail = c;                      // Cập nhật tail mới
            tail->setNext(NULL);           // Cập nhật next của tail là NULL
            sz--;                          // Giảm số lượng phần tử
            return true;                   // Xóa thành công
        }
        
        // Tìm kiếm phần tử có giá trị x
        Node* find(int x) {
            for(Node *it = head; it; it = it->getNext())
                if(it->getData() == x) return it;    // Trả về nút chứa x
            return NULL;    // Không tìm thấy
        }
        
        // In danh sách
        void print() {
            for(Node *it = head; it; it = it->getNext())
                cout << it->getData() << " ";    // In giá trị của từng nút
            cout << "\n";
        }
        
        // Sắp xếp giảm dần
        void sort_desc() {
            if(sz < 2) return;     // Nếu có ít hơn 2 phần tử thì không cần sắp xếp
            // Sắp xếp nổi bọt
            for(Node *i = head; i; i = i->getNext())
                for(Node *j = i->getNext(); j; j = j->getNext())
                    if(i->getData() < j->getData()) {    // Nếu i < j thì đổi chỗ
                        int a = i->getData(), b = j->getData();
                        i->setData(b);
                        j->setData(a);
                    }
        }
        
        // Chèn giữ thứ tự giảm dần
        // Hàm chèn một phần tử mới vào danh sách sao cho danh sách vẫn giữ thứ tự giảm dần
        void insert_keep_desc(int x) {
            // Bước 1: Tạo nút mới chứa giá trị x
            Node *p = new Node(x);     
            
            // Bước 2: Xử lý trường hợp danh sách rỗng
            if(!head) {                
                head = tail = p;       // Nút mới sẽ là nút duy nhất
                sz++;                  // Tăng số lượng phần tử
                return;
            }
            
            // Bước 3: Xử lý trường hợp chèn vào đầu (x >= giá trị đầu)
            if(x >= head->getData()) { 
                p->setNext(head);      // Trỏ next của p đến head cũ
                head = p;              // Cập nhật head mới
                sz++;                  // Tăng số lượng phần tử
                return;
            }
            
            // Bước 4: Xử lý trường hợp chèn vào cuối (x <= giá trị cuối)
            if(x <= tail->getData()) { 
                tail->setNext(p);      // Trỏ next của tail cũ đến p
                tail = p;              // Cập nhật tail mới
                sz++;                  // Tăng số lượng phần tử
                return;
            }
            
            // Bước 5: Tìm vị trí chèn ở giữa danh sách
            Node *c = head;            
            // Tìm nút c sao cho: c->getData() >= x > c->next->getData()
            while(c->getNext() && c->getNext()->getData() > x)
                c = c->getNext();
                
            // Bước 6: Chèn p vào sau nút c
            p->setNext(c->getNext());  // Trỏ next của p đến nút sau c
            c->setNext(p);             // Trỏ next của c đến p
            sz++;                      // Tăng số lượng phần tử
        }
};

int main() {
    // Tắt đồng bộ hóa với stdio để tăng tốc độ nhập xuất 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Tạo danh sách liên kết đơn mới
    SinglyLinkedList lst;
    
    // Yêu cầu người dùng nhập các số
    cout << "Nhap cac so nguyen duong, ket thuc khi nhap so am:\n";
    
    // Vòng lặp nhập số
    while(true) {
        int x;
        // Kiểm tra nếu nhập không thành công (ví dụ: nhập chữ)
        if(!(cin >> x)) return 0;
        // Nếu nhập số âm thì dừng nhập
        if(x < 0) break;
        // Thêm số vừa nhập vào cuối danh sách
        lst.push_back(x);
    }

    int ch;
    do {
        cout << "\n1 push_front | 2 push_back | 3 print\n";
        cout << "4 count | 5 find X | 6 pop_front | 7 pop_back\n";
        cout << "8 sort_desc | 9 insert X (desc) | 0 exit\nChon: ";
        cin >> ch;
        
        switch(ch) {
            case 1: {
                int x;
                cout << "x: ";
                cin >> x;
                if(x >= 0) lst.push_front(x);
                else cout << "x>=0\n";
                break;
            }
            case 2: {
                int x;
                cout << "x: ";
                cin >> x;
                if(x >= 0) lst.push_back(x);
                else cout << "x>=0\n";
                break;
            }
            case 3: {
                lst.print();
                break;
            }
            case 4: {
                cout << lst.count() << "\n";
                break;
            }
            case 5: {
                int x;
                cout << "X: ";
                cin >> x;
                cout << (lst.find(x) ? "Found\n" : "Not found\n");
                break;
            }
            case 6: {
                cout << (lst.pop_front() ? "OK\n" : "Empty\n");
                break;
            }
            case 7: {
                cout << (lst.pop_back() ? "OK\n" : "Empty\n");
                break;
            }
            case 8: {
                lst.sort_desc();
                cout << "Sorted\n";
                break;
            }
            case 9: {
                int x;
                cout << "X: ";
                cin >> x;
                if(x >= 0) {
                    lst.insert_keep_desc(x);
                    cout << "Inserted\n";
                } else cout << "X>=0\n";
                break;
            }
            case 0:
                break;
            default:
                cout << "?\n";
        }
    } while(ch != 0);
    
    return 0;
}
