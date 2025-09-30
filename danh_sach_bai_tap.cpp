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
        
        // Cac ham co ban da hoan thanh
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
        
        void printList(){
            cout << "Danh sach: ";
            for(Node* p = head; p != NULL; p = p->getNext()){
                cout << p->getData() << " ";
            }
            cout << endl;
        }
        
        // TODO: Cac ham can hoan thanh trong cac bai tap
        
        // Bai tap 1: Them phan tu
        int countElements(){
            // TODO: Dem so phan tu trong danh sach
            return 0;
        }
        
        // Bai tap 2: Tim kiem
        bool search(int value){
            // TODO: Tim kiem phan tu trong danh sach
            return false;
        }
        
        int findPosition(int value){
            // TODO: Tim vi tri cua phan tu
            return -1;
        }
        
        int countOccurrences(int value){
            // TODO: Dem so lan xuat hien
            return 0;
        }
        
        int findMax(){
            // TODO: Tim phan tu lon nhat
            return -1;
        }
        
        int findMin(){
            // TODO: Tim phan tu nho nhat
            return -1;
        }
        
        // Bai tap 3: Xoa phan tu
        bool deleteHead(){
            // TODO: Xoa phan tu dau tien
            return false;
        }
        
        bool deleteTail(){
            // TODO: Xoa phan tu cuoi cung
            return false;
        }
        
        bool deleteValue(int value){
            // TODO: Xoa phan tu co gia tri value
            return false;
        }
        
        int deleteAllValue(int value){
            // TODO: Xoa tat ca phan tu co gia tri value
            return 0;
        }
        
        bool deleteAt(int position){
            // TODO: Xoa phan tu tai vi tri position
            return false;
        }
        
        // Bai tap 4: Dao nguoc
        void reverse(){
            // TODO: Dao nguoc danh sach
        }
        
        LinkedList createReverseCopy(){
            // TODO: Tao ban sao dao nguoc
            LinkedList result;
            return result;
        }
        
        bool isPalindrome(){
            // TODO: Kiem tra doi xung
            return false;
        }
        
        // Bai tap 5: Sap xep
        void bubbleSort(){
            // TODO: Sap xep bang Bubble Sort
        }
        
        void bubbleSortDescending(){
            // TODO: Sap xep giam dan bang Bubble Sort
        }
        
        void selectionSort(){
            // TODO: Sap xep bang Selection Sort
        }
        
        bool isSorted(){
            // TODO: Kiem tra danh sach co tang dan khong
            return false;
        }
        
        void insertSorted(int value){
            // TODO: Chen phan tu vao danh sach da sap xep
        }
        
        // Ham tao danh sach mau
        void createSampleList(){
            addTail(10);
            addTail(25);
            addTail(15);
            addTail(25);
            addTail(30);
            addTail(25);
            addTail(5);
        }
        
        void createRandomList(){
            addTail(64);
            addTail(34);
            addTail(25);
            addTail(12);
            addTail(22);
            addTail(11);
            addTail(90);
        }
        
        void createSortedList(){
            addTail(10);
            addTail(20);
            addTail(30);
            addTail(40);
            addTail(50);
        }
};

int main(){
    LinkedList list;
    
    cout << "=== TONG HOP CAC BAI TAP DANH SACH LIEN KET DON ===" << endl;
    cout << "1. bai_tap1.cpp - Them phan tu vao dau/cuoi danh sach" << endl;
    cout << "2. bai_tap2.cpp - Tim kiem phan tu trong danh sach" << endl;
    cout << "3. bai_tap3.cpp - Xoa phan tu khoi danh sach" << endl;
    cout << "4. bai_tap4.cpp - Dao nguoc danh sach lien ket" << endl;
    cout << "5. bai_tap5.cpp - Sap xep danh sach lien ket" << endl;
    cout << "6. bai2.cpp - File goc da sua loi" << endl;
    cout << endl;
    
    cout << "=== HUONG DAN SU DUNG ===" << endl;
    cout << "1. Mo tung file bai_tapX.cpp de lam bai tap" << endl;
    cout << "2. Hoan thanh cac ham co ghi chu TODO" << endl;
    cout << "3. Chay chuong trinh de kiem tra ket qua" << endl;
    cout << "4. Su dung file danh_sach_bai_tap.cpp de xem tong quan" << endl;
    cout << endl;
    
    cout << "=== CAC KHAI NIEM CAN NAM ===" << endl;
    cout << "- Node: Phan tu trong danh sach lien ket" << endl;
    cout << "- Head: Con tro tro den phan tu dau tien" << endl;
    cout << "- Tail: Con tro tro den phan tu cuoi cung" << endl;
    cout << "- Next: Con tro tro den phan tu tiep theo" << endl;
    cout << "- NULL: Con tro rong, ket thuc danh sach" << endl;
    cout << endl;
    
    cout << "=== CAC THAO TAC CO BAN ===" << endl;
    cout << "- Them phan tu: Tao Node moi va cap nhat con tro" << endl;
    cout << "- Xoa phan tu: Cap nhat con tro va giai phong bo nho" << endl;
    cout << "- Duyet danh sach: Su dung vong lap voi con tro" << endl;
    cout << "- Tim kiem: Duyet va so sanh gia tri" << endl;
    cout << "- Sap xep: So sanh va doi cho cac phan tu" << endl;
    
    return 0;
}

/*
=== DANH SACH CAC FILE BAI TAP ===

1. bai_tap1.cpp - Them phan tu vao dau/cuoi danh sach
   - addHead(), addTail(), printList(), countElements()
   - Test cac truong hop them phan tu

2. bai_tap2.cpp - Tim kiem phan tu trong danh sach
   - search(), findPosition(), countOccurrences()
   - findMax(), findMin()

3. bai_tap3.cpp - Xoa phan tu khoi danh sach
   - deleteHead(), deleteTail(), deleteValue()
   - deleteAllValue(), deleteAt()
   - Luu y giai phong bo nho

4. bai_tap4.cpp - Dao nguoc danh sach lien ket
   - reverse(), createReverseCopy(), isPalindrome()
   - Su dung con tro prev, current, next

5. bai_tap5.cpp - Sap xep danh sach lien ket
   - bubbleSort(), selectionSort(), isSorted()
   - insertSorted(), bubbleSortDescending()

6. bai2.cpp - File goc da sua loi
   - Sua loi ten class va khai bao bien
   - Them cac ham co ban

=== CAC LUA Y QUAN TRONG ===

1. Luon kiem tra danh sach rong truoc khi thao tac
2. Cap nhat head va tail khi can thiet
3. Giai phong bo nho bang delete sau khi xoa node
4. Su dung con tro tam thoi de luu tru gia tri
5. Kiem tra con tro NULL truoc khi truy cap
6. Test cac truong hop dac biet (rong, 1 phan tu, etc.)

=== CAC THUAT TOAN QUAN TRONG ===

1. Bubble Sort: So sanh va doi cho cac phan tu lien ke
2. Selection Sort: Tim phan tu nho nhat va doi cho
3. Dao nguoc: Su dung 3 con tro prev, current, next
4. Tim kiem: Duyet qua danh sach va so sanh
5. Xoa phan tu: Tim phan tu truoc va cap nhat con tro

=== BAI TAP MO RONG ===

1. Them phan tu tai vi tri k bat ky
2. Xoa phan tu tai vi tri k bat ky
3. Sap xep bang Insertion Sort
4. Sap xep bang Merge Sort (de quy)
5. Kiem tra danh sach co giam dan hay khong
6. Dao nguoc n phan tu dau tien
7. Tim phan tu thu k (tinh tu dau/cuoi)
8. Xoa cac phan tu trung lap
9. Noi hai danh sach lien ket
10. Tach danh sach thanh hai phan
*/

