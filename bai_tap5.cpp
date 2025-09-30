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
        
        // TODO: Sap xep danh sach theo thu tu tang dan (Bubble Sort)
        void bubbleSort(){
            // Viet code tai day
            
        }
        
        // TODO: Sap xep danh sach theo thu tu giam dan
        void bubbleSortDescending(){
            // Viet code tai day
            
        }
        
        // TODO: Sap xep bang Selection Sort (tang dan)
        void selectionSort(){
            // Viet code tai day
            
        }
        
        // TODO: Kiem tra danh sach co tang dan hay khong
        bool isSorted(){
            // Viet code tai day
            
        }
        
        // TODO: Chen phan tu vao dung vi tri de danh sach van tang dan
        void insertSorted(int value){
            // Viet code tai day
            
        }
        
        // Ham de tao danh sach mau cho test
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
        
        void createDescendingList(){
            addTail(50);
            addTail(40);
            addTail(30);
            addTail(20);
            addTail(10);
        }
};

int main(){
    LinkedList list;
    
    cout << "=== BAI TAP 5: SAP XEP DANH SACH LIEN KET ===" << endl;
    
    // Test Bubble Sort tang dan
    cout << "1. Test Bubble Sort (tang dan):" << endl;
    list.createRandomList();
    cout << "Danh sach ban dau: ";
    list.printList();
    list.bubbleSort();
    cout << "Sau khi sap xep: ";
    list.printList();
    cout << "Danh sach co tang dan khong? " << (list.isSorted() ? "Co" : "Khong") << endl << endl;
    
    // Test Bubble Sort giam dan
    cout << "2. Test Bubble Sort (giam dan):" << endl;
    list.createRandomList();
    cout << "Danh sach ban dau: ";
    list.printList();
    list.bubbleSortDescending();
    cout << "Sau khi sap xep giam dan: ";
    list.printList();
    cout << endl;
    
    // Test Selection Sort
    cout << "3. Test Selection Sort:" << endl;
    list.createRandomList();
    cout << "Danh sach ban dau: ";
    list.printList();
    list.selectionSort();
    cout << "Sau khi Selection Sort: ";
    list.printList();
    cout << "Danh sach co tang dan khong? " << (list.isSorted() ? "Co" : "Khong") << endl << endl;
    
    // Test chen phan tu vao danh sach da sap xep
    cout << "4. Test chen phan tu vao danh sach da sap xep:" << endl;
    list.createSortedList();
    cout << "Danh sach da sap xep: ";
    list.printList();
    list.insertSorted(25);
    cout << "Sau khi chen 25: ";
    list.printList();
    list.insertSorted(5);
    cout << "Sau khi chen 5: ";
    list.printList();
    list.insertSorted(55);
    cout << "Sau khi chen 55: ";
    list.printList();
    cout << "Danh sach van tang dan? " << (list.isSorted() ? "Co" : "Khong") << endl << endl;
    
    // Test danh sach da sap xep
    cout << "5. Test kiem tra danh sach da sap xep:" << endl;
    LinkedList sortedList;
    sortedList.createSortedList();
    cout << "Danh sach tang dan: ";
    sortedList.printList();
    cout << "Co tang dan khong? " << (sortedList.isSorted() ? "Co" : "Khong") << endl;
    
    LinkedList unsortedList;
    unsortedList.createRandomList();
    cout << "Danh sach chua sap xep: ";
    unsortedList.printList();
    cout << "Co tang dan khong? " << (unsortedList.isSorted() ? "Co" : "Khong") << endl;
    
    return 0;
}

/*
YEU CAU BAI TAP:
1. Hoan thanh ham bubbleSort():
   - Sap xep danh sach theo thu tu tang dan
   - Su dung thuat toan Bubble Sort
   - So sanh va doi cho cac phan tu lien ke
   - Lap lai cho den khi khong con phan tu nao can doi cho

2. Hoan thanh ham bubbleSortDescending():
   - Sap xep danh sach theo thu tu giam dan
   - Tuong tu bubbleSort() nhung doi chieu so sanh

3. Hoan thanh ham selectionSort():
   - Sap xep bang Selection Sort
   - Tim phan tu nho nhat va doi cho voi phan tu dau tien
   - Lap lai voi cac phan tu con lai

4. Hoan thanh ham isSorted():
   - Kiem tra danh sach co tang dan hay khong
   - Tra ve true neu tang dan, false neu khong
   - Kiem tra danh sach rong

5. Hoan thanh ham insertSorted(int value):
   - Chen phan tu value vao dung vi tri de danh sach van tang dan
   - Tim vi tri thich hop va chen vao

THUAT TOAN BUBBLE SORT:
- So sanh cac cap phan tu lien ke
- Doi cho neu phan tu truoc lon hon phan tu sau
- Lap lai cho den khi khong con cap nao can doi cho
- Moi lan lap, phan tu lon nhat se "noi bot" len cuoi

THUAT TOAN SELECTION SORT:
- Tim phan tu nho nhat trong danh sach
- Doi cho voi phan tu dau tien
- Lap lai voi danh sach con lai (bo qua phan tu dau tien)

GOI Y:
- Su dung con tro de duyet va so sanh
- Luu y truong hop danh sach rong hoac chi co 1 phan tu
- Co the su dung flag de kiem tra co phan tu nao doi cho khong

CAC BAI TAP MO RONG:
- Sap xep bang Insertion Sort
- Sap xep bang Merge Sort (de quy)
- Sap xep bang Quick Sort (de quy)
- Sap xep danh sach co phan tu trung lap
- Sap xep theo dieu kien khac (gia tri tuyet doi, so chu so, etc.)
*/

