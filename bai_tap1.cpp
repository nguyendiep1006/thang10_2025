#include<iostream>
using namespace std;

class Node{
    private:
        int data;
        Node* next;
    public:
        // Hàm khởi tạo Node với tham số value
        // value: giá trị số nguyên cần lưu trong node
        // Khởi tạo data = value và next = NULL để tránh trỏ đến vùng nhớ không xác định
        Node(int value): data(value), next(NULL){
        }

        // Hàm trả về con trỏ next trỏ đến node tiếp theo
        // Trả về: con trỏ kiểu Node* trỏ đến node kế tiếp trong danh sách
        Node* getNext(){
            return next;
        }

        // Hàm trả về giá trị data được lưu trong node
        // Trả về: giá trị số nguyên được lưu trong node
        int getData(){
            return data;
        }

        // Hàm cập nhật con trỏ next
        // n: con trỏ kiểu Node* trỏ đến node mới sẽ là node kế tiếp
        void setNext(Node* n){
            next = n;
        }

        // Hàm cập nhật giá trị data
        // value: giá trị số nguyên mới cần gán cho data
        void setData(int value){
            data = value;
        }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
    public:    
        LinkedList(): head(NULL), tail(NULL){
        }
        
        // Thêm phần tử vào đầu danh sách
        void addHead(int value){
            Node* newNode = new Node(value);
            if(head == NULL){
                head = tail = newNode;
            }
            else{
                newNode->setNext(head);
                head = newNode;
            }
        }
        
        // Thêm phần tử vào cuối danh sách
        void addTail(int value){
            Node* newNode = new Node(value);
            if(head == NULL){
                head = tail = newNode;
            }
            else{
                tail->setNext(newNode);
                tail = newNode;
            }
        }
        
        // In danh sách
        void printList(){
            cout << "Danh sach: ";
            for(Node* p = head; p != NULL; p = p->getNext()){
                cout << p->getData() << " ";
            }
            cout << endl;
        }
        
        // Đếm số phần tử trong danh sách
        int countElements(){
            int count = 0;
            for(Node* p = head; p != NULL; p = p->getNext()){
                count++;
            }
            return count;
        }
};

int main(){
    LinkedList list;
    
    cout << "=== BAI TAP 1: THEM PHAN TU VAO DAU/CUOI DANH SACH ===" << endl;
    
    // Thêm phần tử vào cuối danh sách
    cout << "Them phan tu vao cuoi danh sach:" << endl;
    list.addTail(10);
    list.addTail(20);
    list.addTail(30);
    list.printList();
    cout << "So phan tu: " << list.countElements() << endl << endl;
    
    // Thêm phần tử vào đầu danh sách
    cout << "Them phan tu vao dau danh sach:" << endl;
    list.addHead(5);
    list.addHead(1);
    list.printList();
    cout << "So phan tu: " << list.countElements() << endl << endl;
    
    // Tạo danh sách mới và thêm hỗn hợp
    LinkedList list2;
    cout << "Tao danh sach moi va them hon hop:" << endl;
    list2.addTail(100);
    list2.addHead(50);
    list2.addTail(200);
    list2.addHead(25);
    list2.addTail(300);
    list2.printList();
    cout << "So phan tu: " << list2.countElements() << endl;
    
    return 0;
}

/*
YEU CAU BAI TAP:
1. Hoan thanh cac ham addHead() va addTail()
2. Viet ham printList() de in danh sach
3. Viet ham countElements() de dem so phan tu
4. Test cac truong hop:
   - Danh sach rong
   - Them vao dau
   - Them vao cuoi
   - Them hon hop

CAC BAI TAP MO RONG:
- Them phan tu tai vi tri k bat ky
- Them phan tu sau phan tu co gia tri x
- Them phan tu truoc phan tu co gia tri x
*/
