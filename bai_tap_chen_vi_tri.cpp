#include <bits/stdc++.h>
using namespace std;

// Lớp Node cho danh sách liên kết
class Node {
    private:
        int data;
        Node *next;
    public:
        Node(int x, Node *n = NULL) { data = x; next = n; }
        int getData() { return data; }
        void setData(int x) { data = x; }
        Node* getNext() { return next; }
        void setNext(Node *n) { next = n; }
};

// Lớp danh sách liên kết đơn
class SinglyLinkedList {
    private:
        Node *head;
        Node *tail;
        int sz;
    public:
        SinglyLinkedList() { head = NULL; tail = NULL; sz = 0; }
        bool empty() { return head == NULL; }
        int count() { return sz; }
        
        void push_back(int x) {
            Node *p = new Node(x, NULL);
            if(!head) { head = tail = p; }
            else { tail->setNext(p); tail = p; }
            sz++;
        }
        
        void print() {
            for(Node *it = head; it; it = it->getNext())
                cout << it->getData() << " ";
            cout << "\n";
        }
        
        // BÀI TẬP 1: Chèn phần tử x vào vị trí pos (đếm từ 0)
        // Nếu pos < 0: chèn vào đầu
        // Nếu pos >= size: chèn vào cuối
        void insert_at(int pos, int x) {
            // Tạo node mới chứa giá trị x
            Node *p = new Node(x);
            
            // Nếu danh sách rỗng thì node mới là head và tail
            if(!head) { head = tail = p; sz++; return; }
            
            // Nếu vị trí chèn <= 0 thì chèn vào đầu
            if(pos <= 0){
                p->setNext(head); // Trỏ next của p tới head cũ
                head = p; // Cập nhật head mới
                sz++;
                return;
            }
            
            // Nếu vị trí chèn >= size thì chèn vào cuối
            if(pos >= sz){ 
                tail->setNext(p); // Trỏ next của tail tới p
                tail = p; // Cập nhật tail mới
                sz++;
                return;
            }
            
            // Duyệt tới vị trí pos-1
            Node *cur = head; int idx = 0;
            while(cur && idx < pos - 1){ cur = cur->getNext(); idx++; }
            
            // Chèn node p vào sau node cur
            p->setNext(cur->getNext()); // Trỏ next của p tới node sau cur
            cur->setNext(p); // Trỏ next của cur tới p
            sz++; // Tăng kích thước
        }
        
        // BÀI TẬP 2: Chèn x vào sau phần tử có giá trị val
        // Nếu không tìm thấy val: chèn vào cuối
        void insert_after_value(int val, int x) {
            Node *cur = head;
            while(cur && cur->getData() != val) cur = cur->getNext();
            if(!cur){ push_back(x); return; }
            Node *p = new Node(x, cur->getNext());
            cur->setNext(p);
            if(cur == tail) tail = p;
            sz++;
        }
        
        // BÀI TẬP 3: Chèn x vào trước phần tử có giá trị val
        // Nếu không tìm thấy val: chèn vào đầu
        void insert_before_value(int val, int x) {
            // Tạo node mới chứa giá trị x
 
            Node *p = new Node(x);
            
            // Nếu danh sách rỗng thì node mới là head và tail
            if(!head){ head = tail = p; sz++; return; }
            
            // Nếu phần tử đầu tiên có giá trị val thì chèn vào đầu
            if(head->getData() == val){ 
                p->setNext(head);
                head = p;
                sz++;
                return;
            }
            
            // Duyệt tìm node trước node có giá trị val
            Node *cur = head;
            while(cur->getNext() && cur->getNext()->getData() != val) {
                cur = cur->getNext();
            }
            
            // Nếu không tìm thấy val thì chèn vào đầu
            if(!cur->getNext()){ 
                p->setNext(head);
                head = p;
                sz++;
                return;
            }
            
            // Chèn p vào trước node có giá trị val
            p->setNext(cur->getNext());
            cur->setNext(p);
            sz++;
        }
        
        // BÀI TẬP 4: Chèn x vào vị trí thứ k từ cuối (k=1 là cuối cùng)
        // Nếu k > size: chèn vào đầu
        void insert_kth_from_end(int k, int x) {
            if(k <= 0){ push_back(x); return; }
            int pos = sz - k;
            if(pos <= 0){ insert_at(0, x); return; }
            if(pos >= sz){ push_back(x); return; }
            insert_at(pos, x);
        }
        
        // BÀI TẬP 5: Chèn x vào giữa danh sách (vị trí sz/2)
        void insert_middle(int x) {
            int pos = sz / 2;
            insert_at(pos, x);
        }
        
        // BÀI TẬP 6: Chèn x vào vị trí thứ k của phần tử có giá trị lớn nhất
        // Nếu có nhiều phần tử max, chèn vào vị trí đầu tiên (k=1), nếu k vượt quá số lần xuất hiện thì chèn sau lần xuất hiện cuối
        void insert_at_kth_max(int k, int x) {
            if(k <= 0) k = 1;
            if(!head){ push_back(x); return; }
            int maxVal = head->getData();
            for(Node *it=head; it; it=it->getNext()) if(it->getData() > maxVal) maxVal = it->getData();
            // tìm vị trí lần xuất hiện thứ k của maxVal
            int occ = 0, pos = -1, idx = 0; Node *it = head;
            while(it){
                if(it->getData() == maxVal){ occ++; pos = idx; if(occ == k) break; }
                it = it->getNext(); idx++;
            }
            if(pos == -1) { push_back(x); return; }
            if(occ < k){ // ít hơn k lần, dùng lần xuất hiện cuối (pos đã là cuối cùng)
                insert_at(pos, x);
            } else {
                insert_at(pos, x);
            }
        }
        
        // BÀI TẬP 7: Chèn x vào sau mỗi phần tử chẵn
        void insert_after_even(int x) {
            if(!head) return;
            Node *cur = head;
            while(cur){
                if(cur->getData() % 2 == 0){
                    Node *p = new Node(x, cur->getNext());
                    cur->setNext(p);
                    if(cur == tail) tail = p;
                    sz++;
                    cur = p->getNext(); // bỏ qua nút vừa chèn để tránh vòng lặp vô hạn
                } else {
                    cur = cur->getNext();
                }
            }
        }
        
        // BÀI TẬP 8: Chèn x vào vị trí sao cho danh sách vẫn tăng dần
        void insert_keep_ascending(int x) {
            Node *p = new Node(x);
            if(!head){ head = tail = p; sz++; return; }
            if(x <= head->getData()){ p->setNext(head); head = p; sz++; return; }
            if(x >= tail->getData()){ tail->setNext(p); tail = p; sz++; return; }
            Node *cur = head;
            while(cur->getNext() && cur->getNext()->getData() < x) cur = cur->getNext();
            p->setNext(cur->getNext());
            cur->setNext(p);
            sz++;
        }
        
        // BÀI TẬP 9: Chèn x vào vị trí thứ k của phần tử có giá trị gần x nhất
        void insert_at_kth_closest(int k, int x) {
            if(k <= 0) k = 1;
            if(!head){ push_back(x); return; }
            // Tìm sai khác nhỏ nhất
            int bestDiff = INT_MAX;
            for(Node *it=head; it; it=it->getNext()) bestDiff = min(bestDiff, abs(it->getData() - x));
            // tìm lần xuất hiện thứ k của các phần tử có diff == bestDiff
            int occ = 0, pos = -1, idx = 0; Node *it = head;
            while(it){
                if(abs(it->getData() - x) == bestDiff){ occ++; pos = idx; if(occ == k) break; }
                it = it->getNext(); idx++;
            }
            if(pos < 0) { push_back(x); return; }
            insert_at(pos, x);
        }
        
        // BÀI TẬP 10: Chèn x vào vị trí thứ k của phần tử có giá trị trung bình
        void insert_at_kth_average(int k, int x) {
            if(k <= 0) k = 1;
            if(!head){ push_back(x); return; }
            // Tính trung bình
            long long sum = 0; for(Node *it=head; it; it=it->getNext()) sum += it->getData();
            double avg = (double)sum / (double)sz;
            // Tìm sai khác nhỏ nhất với trung bình
            double best = 1e100;
            for(Node *it=head; it; it=it->getNext()) best = min(best, fabs((double)it->getData() - avg));
            // Tìm lần xuất hiện thứ k của khoảng cách tốt nhất
            int occ = 0, pos = -1, idx = 0; Node *it2 = head;
            while(it2){
                if(fabs((double)it2->getData() - avg) == best){ occ++; pos = idx; if(occ == k) break; }
                it2 = it2->getNext(); idx++;
            }
            if(pos < 0) { push_back(x); return; }
            insert_at(pos, x);
        }
};

// Hàm test cho từng bài tập
void test_bai_tap() {
    SinglyLinkedList lst;
    
    // Tạo dữ liệu mẫu
    for(int i = 1; i <= 5; i++) {
        lst.push_back(i * 2); // 2, 4, 6, 8, 10
    }
    
    cout << "Danh sach ban dau: ";
    lst.print();
    
    // Ví dụ demo nhanh
    lst.insert_at(2, 99); cout << "Chen 99 tai pos=2: "; lst.print();
    lst.insert_after_value(4, 55); cout << "Chen 55 sau gia tri 4: "; lst.print();
    lst.insert_before_value(6, 33); cout << "Chen 33 truoc gia tri 6: "; lst.print();
    lst.insert_kth_from_end(1, 77); cout << "Chen 77 vao vi tri 1 tu cuoi: "; lst.print();
    lst.insert_middle(44); cout << "Chen 44 vao giua: "; lst.print();
    lst.insert_at_kth_max(1, 66); cout << "Chen 66 tai lan xuat hien thu 1 cua max: "; lst.print();
    lst.insert_after_even(22); cout << "Chen 22 sau moi so chan: "; lst.print();
    // Sắp xếp tăng rồi chèn giữ tăng để minh hoạ
    // (Tạo nhanh danh sách tăng bằng cách chèn thủ công)
    SinglyLinkedList inc; inc.push_back(1); inc.push_back(3); inc.push_back(7); inc.push_back(9);
    cout << "Danh sach tang: "; inc.print();
    inc.insert_keep_ascending(5); cout << "Chen 5 giu tang dan: "; inc.print();
    
    SinglyLinkedList closeLst; closeLst.push_back(1); closeLst.push_back(8); closeLst.push_back(5); closeLst.push_back(11);
    closeLst.insert_at_kth_closest(1, 6); cout << "Gan 6 nhat (k=1): "; closeLst.print();
    
    SinglyLinkedList avgLst; avgLst.push_back(2); avgLst.push_back(10); avgLst.push_back(6);
    avgLst.insert_at_kth_average(1, 7); cout << "Gan TB nhat (k=1): "; avgLst.print();
}

int main() {
    cout << "=== BAI TAP CHEN VAO VI TRI BAT KY TRONG DSLK ===\n\n";
    
    cout << "BAI TAP 1: Chen vao vi tri pos\n";
    cout << "BAI TAP 2: Chen sau phan tu co gia tri val\n";
    cout << "BAI TAP 3: Chen truoc phan tu co gia tri val\n";
    cout << "BAI TAP 4: Chen vao vi tri thu k tu cuoi\n";
    cout << "BAI TAP 5: Chen vao giua danh sach\n";
    cout << "BAI TAP 6: Chen vao vi tri thu k cua phan tu max\n";
    cout << "BAI TAP 7: Chen sau moi phan tu chan\n";
    cout << "BAI TAP 8: Chen giu thu tu tang dan\n";
    cout << "BAI TAP 9: Chen vao vi tri thu k cua phan tu gan x nhat\n";
    cout << "BAI TAP 10: Chen vao vi tri thu k cua phan tu gan trung binh nhat\n\n";
    
    test_bai_tap();
    
    return 0;
}

/*
=== DE BAI CHI TIET ===

BAI TAP 1: Chen vao vi tri pos
- Input: pos (int), x (int)
- Neu pos <= 0: chen vao dau
- Neu pos >= size: chen vao cuoi
- Neu 0 < pos < size: chen vao vi tri pos

BAI TAP 2: Chen sau phan tu co gia tri val
- Input: val (int), x (int)
- Tim phan tu co gia tri = val
- Chen x vao sau phan tu do
- Neu khong tim thay: chen vao cuoi

BAI TAP 3: Chen truoc phan tu co gia tri val
- Input: val (int), x (int)
- Tim phan tu co gia tri = val
- Chen x vao truoc phan tu do
- Neu khong tim thay: chen vao dau

BAI TAP 4: Chen vao vi tri thu k tu cuoi
- Input: k (int), x (int)
- Vi tri tu cuoi: pos = size - k
- Neu pos <= 0: chen vao dau
- Neu pos >= size: chen vao cuoi

BAI TAP 5: Chen vao giua danh sach
- Input: x (int)
- Vi tri giua: pos = size / 2
- Chen x vao vi tri pos

BAI TAP 6: Chen vao vi tri thu k cua phan tu max
- Input: k (int), x (int)
- Tim gia tri max trong danh sach
- Tim vi tri thu k cua phan tu max
- Chen x vao vi tri do

BAI TAP 7: Chen sau moi phan tu chan
- Input: x (int)
- Duyet danh sach, neu gap phan tu chan thi chen x vao sau

BAI TAP 8: Chen giu thu tu tang dan
- Input: x (int)
- Chen x vao vi tri thich hop de danh sach van tang dan

BAI TAP 9: Chen vao vi tri thu k cua phan tu gan x nhat
- Input: k (int), x (int)
- Tim phan tu co |val - x| nho nhat
- Tim vi tri thu k cua phan tu do
- Chen x vao vi tri do

BAI TAP 10: Chen vao vi tri thu k cua phan tu gan trung binh nhat
- Input: k (int), x (int)
- Tinh gia tri trung binh cua danh sach
- Tim phan tu gan gia tri trung binh nhat
- Tim vi tri thu k cua phan tu do
- Chen x vao vi tri do
*/
 