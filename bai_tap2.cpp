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
        
        // TODO: Tim kiem phan tu trong danh sach
        // Tra ve true neu tim thay, false neu khong tim thay
        bool search(int value){
            // Viet code tai day
            
        }
        
        // TODO: Tim vi tri cua phan tu trong danh sach
        // Tra ve vi tri (bat dau tu 0) neu tim thay, -1 neu khong tim thay
        int findPosition(int value){
            // Viet code tai day
            
        }
        
        // TODO: Dem so lan xuat hien cua mot gia tri
        int countOccurrences(int value){
            // Viet code tai day
            
        }
        
        // TODO: Tim phan tu lon nhat trong danh sach
        int findMax(){
            // Viet code tai day
            
        }
        
        // TODO: Tim phan tu nho nhat trong danh sach
        int findMin(){
            // Viet code tai day
            
        }
};

int main(){
    LinkedList list;
    
    cout << "=== BAI TAP 2: TIM KIEM TRONG DANH SACH LIEN KET ===" << endl;
    
    // Tao danh sach mau
    list.addTail(10);
    list.addTail(25);
    list.addTail(15);
    list.addTail(25);
    list.addTail(30);
    list.addTail(25);
    list.addTail(5);
    
    list.printList();
    cout << endl;
    
    // Test cac ham tim kiem
    cout << "1. Tim kiem phan tu 25: " << (list.search(25) ? "Tim thay" : "Khong tim thay") << endl;
    cout << "2. Tim kiem phan tu 100: " << (list.search(100) ? "Tim thay" : "Khong tim thay") << endl;
    cout << "3. Vi tri cua phan tu 25: " << list.findPosition(25) << endl;
    cout << "4. Vi tri cua phan tu 30: " << list.findPosition(30) << endl;
    cout << "5. Vi tri cua phan tu 999: " << list.findPosition(999) << endl;
    cout << "6. So lan xuat hien cua 25: " << list.countOccurrences(25) << endl;
    cout << "7. So lan xuat hien cua 10: " << list.countOccurrences(10) << endl;
    cout << "8. Phan tu lon nhat: " << list.findMax() << endl;
    cout << "9. Phan tu nho nhat: " << list.findMin() << endl;
    
    return 0;
}

/*
YEU CAU BAI TAP:
1. Hoan thanh ham search(int value):
   - Tra ve true neu tim thay gia tri trong danh sach
   - Tra ve false neu khong tim thay

2. Hoan thanh ham findPosition(int value):
   - Tra ve vi tri (bat dau tu 0) neu tim thay
   - Tra ve -1 neu khong tim thay
   - Neu co nhieu phan tu cung gia tri, tra ve vi tri dau tien

3. Hoan thanh ham countOccurrences(int value):
   - Dem so lan xuat hien cua gia tri trong danh sach

4. Hoan thanh ham findMax():
   - Tim va tra ve gia tri lon nhat trong danh sach
   - Neu danh sach rong, tra ve -1

5. Hoan thanh ham findMin():
   - Tim va tra ve gia tri nho nhat trong danh sach
   - Neu danh sach rong, tra ve -1

GOI Y:
- Su dung vong lap de duyet qua cac phan tu
- Luu y truong hop danh sach rong
- Co the su dung bien dem de theo doi vi tri

CAC BAI TAP MO RONG:
- Tim tat ca cac vi tri cua mot gia tri
- Tim phan tu thu k (tinh tu dau)
- Tim phan tu thu k (tinh tu cuoi)
- Kiem tra danh sach co tang dan hay khong
*/
