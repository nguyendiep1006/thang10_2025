#include<iostream>
using namespace std;

class Node{
    private:
        int elem; // Đổi tên từ data thành elem theo yêu cầu
        Node* next;
    public:
        Node(int value): elem(value), next(NULL){
        }
        Node* getNext(){
            return next;
        }
        int getElem(){ // Đổi tên từ getData thành getElem
            return elem;
        }
        void setNext(Node* n){
            next = n;
        }
        void setElem(int value){ // Đổi tên từ setData thành setElem
            elem = value;
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
                cout << p->getElem() << " "; // Sử dụng getElem thay vì getData
            }
            cout << endl;
        }
        
        // Hàm xóa phần tử đầu tiên của danh sách
        // Trả về true nếu xóa thành công, false nếu danh sách rỗng
        bool deleteHead(){
            if (head == NULL) { // Kiểm tra danh sách rỗng
                return false;
            }
            
            Node* temp = head; // Lưu lại node đầu để giải phóng bộ nhớ
            head = head->getNext(); // Cập nhật head thành node kế tiếp
            
            if (head == NULL) { // Nếu sau khi xóa danh sách rỗng
                tail = NULL; // Cập nhật tail = NULL
            }
            
            delete temp; // Giải phóng bộ nhớ của node cũ
            return true;
        }
        
        // Hàm xóa phần tử cuối cùng của danh sách
        // Trả về true nếu xóa thành công, false nếu danh sách rỗng
        bool deleteTail(){
            if (head == NULL) { // Kiểm tra danh sách rỗng
                return false;
            }
            
            if (head == tail) { // Nếu danh sách chỉ có 1 phần tử
                delete head;
                head = tail = NULL;
                return true;
            }
            
            Node* current = head;
            // Tìm node trước tail
            while (current->getNext() != tail) {
                current = current->getNext();
            }
            
            delete tail; // Giải phóng bộ nhớ của tail cũ
            tail = current; // Cập nhật tail mới
            tail->setNext(NULL);
            return true;
        }
        
        // Hàm xóa phần tử đầu tiên có giá trị value
        // Trả về true nếu tìm thấy và xóa thành công, false nếu không tìm thấy
        bool deleteValue(int value){
            if (head == NULL) { // Kiểm tra danh sách rỗng
                return false;
            }
            
            if (head->getElem() == value) { // Nếu phần tử cần xóa ở đầu
                return deleteHead();
            }
            
            Node* current = head;
            // Tìm node trước node cần xóa
            while (current->getNext() != NULL && current->getNext()->getElem() != value) {
                current = current->getNext();
            }
            
            if (current->getNext() == NULL) { // Không tìm thấy giá trị
                return false;
            }
            
            Node* temp = current->getNext(); // Node cần xóa
            current->setNext(temp->getNext()); // Cập nhật liên kết
            
            if (temp == tail) { // Nếu xóa node cuối
                tail = current;
            }
            
            delete temp; // Giải phóng bộ nhớ
            return true;
        }
        
        // Hàm xóa tất cả các phần tử có giá trị value
        // Trả về số lượng phần tử đã xóa
        int deleteAllValue(int value){
            int count = 0;
            while (deleteValue(value)) { // Xóa cho đến khi không còn value
                count++;
            }
            return count;
        }
        
        // Hàm xóa phần tử tại vị trí position (đếm từ 0)
        // Trả về true nếu xóa thành công, false nếu vị trí không hợp lệ
        bool deleteAt(int position){
            if (head == NULL || position < 0) { // Kiểm tra điều kiện
                return false;
            }
            
            if (position == 0) { // Nếu xóa phần tử đầu
                return deleteHead();
            }
            
            Node* current = head;
            int currentPos = 0;
            
            // Tìm node trước vị trí cần xóa
            while (current != NULL && currentPos < position - 1) {
                current = current->getNext();
                currentPos++;
            }   
            
            if (current == NULL || current->getNext() == NULL) { // Vị trí không hợp lệ
                return false;
            }
            
            Node* temp = current->getNext(); // Node cần xóa
            current->setNext(temp->getNext()); // Cập nhật liên kết
            
            if (temp == tail) { // Nếu xóa node cuối
                tail = current;
            }
            
            delete temp; // Giải phóng bộ nhớ
            return true;
        }
        
        // Hàm tạo danh sách mẫu để test
        void createSampleList(){
            addTail(10);
            addTail(25);
            addTail(15);
            addTail(25);
            addTail(30);
            addTail(25);
            addTail(5);
        }

int main(){
    LinkedList list;
    
    cout << "=== BAI TAP 3: XOA PHAN TU KHOI DANH SACH LIEN KET ===" << endl;
    
    // Test xoa dau
    cout << "1. Test xoa phan tu dau tien:" << endl;
    list.createSampleList();
    list.printList();
    cout << "Xoa dau: " << (list.deleteHead() ? "Thanh cong" : "That bai") << endl;
    list.printList();
    cout << endl;
    
    // Test xoa cuoi
    cout << "2. Test xoa phan tu cuoi cung:" << endl;
    list.createSampleList();
    list.printList();
    cout << "Xoa cuoi: " << (list.deleteTail() ? "Thanh cong" : "That bai") << endl;
    list.printList();
    cout << endl;
    
    // Test xoa gia tri
    cout << "3. Test xoa phan tu co gia tri 25 (lan dau tien):" << endl;
    list.createSampleList();
    list.printList();
    cout << "Xoa gia tri 25: " << (list.deleteValue(25) ? "Thanh cong" : "Khong tim thay") << endl;
    list.printList();
    cout << endl;
    
    // Test xoa tat ca gia tri
    cout << "4. Test xoa tat ca phan tu co gia tri 25:" << endl;
    list.createSampleList();
    list.printList();
    int deleted = list.deleteAllValue(25);
    cout << "Da xoa " << deleted << " phan tu co gia tri 25" << endl;
    list.printList();
    cout << endl;
    
    // Test xoa tai vi tri
    cout << "5. Test xoa phan tu tai vi tri 2:" << endl;
    list.createSampleList();
    list.printList();
    cout << "Xoa tai vi tri 2: " << (list.deleteAt(2) ? "Thanh cong" : "Vi tri khong hop le") << endl;
    list.printList();
    cout << endl;
    
    // Test truong hop dac biet
    cout << "6. Test xoa tu danh sach rong:" << endl;
    LinkedList emptyList;
    cout << "Xoa dau tu danh sach rong: " << (emptyList.deleteHead() ? "Thanh cong" : "That bai") << endl;
    
    return 0;
}

/*
YEU CAU BAI TAP:
1. Hoan thanh ham deleteHead():
   - Xoa phan tu dau tien trong danh sach
   - Cap nhat lai head va tail neu can
   - Giai phong bo nho cua node bi xoa
   - Tra ve true neu xoa thanh cong, false neu danh sach rong

2. Hoan thanh ham deleteTail():
   - Xoa phan tu cuoi cung trong danh sach
   - Cap nhat lai tail
   - Giai phong bo nho cua node bi xoa
   - Tra ve true neu xoa thanh cong, false neu danh sach rong

3. Hoan thanh ham deleteValue(int value):
   - Tim va xoa phan tu dau tien co gia tri value
   - Giai phong bo nho
   - Tra ve true neu xoa thanh cong, false neu khong tim thay

4. Hoan thanh ham deleteAllValue(int value):
   - Xoa tat ca cac phan tu co gia tri value
   - Dem va tra ve so luong phan tu da xoa

5. Hoan thanh ham deleteAt(int position):
   - Xoa phan tu tai vi tri position (bat dau tu 0)
   - Tra ve true neu xoa thanh cong, false neu vi tri khong hop le

LUU Y QUAN TRONG:
- Luon giai phong bo nho bang delete sau khi xoa node
- Cap nhat lai head va tail khi can thiet
- Kiem tra truong hop danh sach rong
- Kiem tra truong hop danh sach chi co 1 phan tu
- Su dung con tro truoc (previous) khi can thiet

CAC BAI TAP MO RONG:
- Xoa phan tu tai vi tri k (tinh tu cuoi)
- Xoa cac phan tu trung lap (giu lai 1 phan tu)
- Xoa phan tu co gia tri lon nhat/nho nhat
- Xoa toan bo danh sach
*/
