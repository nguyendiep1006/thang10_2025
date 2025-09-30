#include<iostream>
using namespace std;

class Node{
    private:
        int data;
        Node* next;
    public:
        Node(int value): data(value), next(NULL){
        }
        Node* getNext(){
            return next;
        }
        int getData(){
            return data;
        }
        void setNext(Node* n){
            next = n;
        }
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
        
        void printList(){
            cout << "Danh sach: ";
            for(Node* p = head; p != NULL; p = p->getNext()){
                cout << p->getData() << " ";
            }
            cout << endl;
        }
        
        // TODO: Dao nguoc danh sach lien ket
        // Su dung con tro de thay doi cac lien ket
        void reverse(){
            // Viet code tai day
            
        }
        
        // TODO: Tao ban sao dao nguoc cua danh sach hien tai
        // Khong thay doi danh sach goc, tao danh sach moi
        LinkedList createReverseCopy(){
            // Viet code tai day
            
        }
        
        // TODO: Kiem tra danh sach co doi xung hay khong
        // Danh sach doi xung neu doc tu trai qua phai bang doc tu phai qua trai
        bool isPalindrome(){
            // Viet code tai day
            
        }
        
        // Ham de tao danh sach mau cho test
        void createSampleList1(){
            addTail(1);
            addTail(2);
            addTail(3);
            addTail(4);
            addTail(5);
        }
        
        void createSampleList2(){
            addTail(1);
            addTail(2);
            addTail(3);
            addTail(2);
            addTail(1);
        }
        
        void createSampleList3(){
            addTail(1);
            addTail(2);
            addTail(2);
            addTail(1);
        }
};

int main(){
    LinkedList list;
    
    cout << "=== BAI TAP 4: DAO NGUOC DANH SACH LIEN KET ===" << endl;
    
    // Test dao nguoc danh sach
    cout << "1. Test dao nguoc danh sach:" << endl;
    list.createSampleList1();
    cout << "Danh sach ban dau: ";
    list.printList();
    list.reverse();
    cout << "Sau khi dao nguoc: ";
    list.printList();
    cout << endl;
    
    // Test tao ban sao dao nguoc
    cout << "2. Test tao ban sao dao nguoc:" << endl;
    LinkedList list2;
    list2.createSampleList1();
    cout << "Danh sach goc: ";
    list2.printList();
    
    LinkedList reversedCopy = list2.createReverseCopy();
    cout << "Ban sao dao nguoc: ";
    reversedCopy.printList();
    cout << "Danh sach goc (khong doi): ";
    list2.printList();
    cout << endl;
    
    // Test kiem tra doi xung
    cout << "3. Test kiem tra doi xung:" << endl;
    
    LinkedList list3;
    list3.createSampleList2();
    cout << "Danh sach: ";
    list3.printList();
    cout << "Co doi xung khong? " << (list3.isPalindrome() ? "Co" : "Khong") << endl;
    
    LinkedList list4;
    list4.createSampleList3();
    cout << "Danh sach: ";
    list4.printList();
    cout << "Co doi xung khong? " << (list4.isPalindrome() ? "Co" : "Khong") << endl;
    
    LinkedList list5;
    list5.createSampleList1();
    cout << "Danh sach: ";
    list5.printList();
    cout << "Co doi xung khong? " << (list5.isPalindrome() ? "Co" : "Khong") << endl;
    
    return 0;
}

/*
YEU CAU BAI TAP:
1. Hoan thanh ham reverse():
   - Dao nguoc thu tu cac phan tu trong danh sach
   - Su dung cac con tro prev, current, next
   - Cap nhat lai head va tail
   - Thay doi danh sach goc

2. Hoan thanh ham createReverseCopy():
   - Tao mot ban sao dao nguoc cua danh sach hien tai
   - Khong thay doi danh sach goc
   - Tra ve LinkedList moi
   - Su dung addHead() de tao danh sach dao nguoc

3. Hoan thanh ham isPalindrome():
   - Kiem tra danh sach co doi xung hay khong
   - Tao ban sao dao nguoc va so sanh
   - Tra ve true neu doi xung, false neu khong

THUAT TOAN DAO NGUOC:
Buoc 1: Khoi tao prev = NULL, current = head
Buoc 2: Lap qua danh sach:
   - Luu next = current->next
   - current->next = prev
   - prev = current
   - current = next
Buoc 3: Cap nhat head = prev

GOI Y:
- Luon kiem tra truong hop danh sach rong
- Luu y cap nhat tail sau khi dao nguoc
- Su dung con tro tam thoi de luu tru gia tri

CAC BAI TAP MO RONG:
- Dao nguoc n phan tu dau tien
- Dao nguoc n phan tu cuoi cung
- Dao nguoc cac phan tu tu vi tri i den vi tri j
- Kiem tra danh sach co tang dan hay giam dan
- So sanh hai danh sach lien ket
*/

