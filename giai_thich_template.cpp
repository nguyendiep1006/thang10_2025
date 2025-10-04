/*
 * GIẢI THÍCH CHI TIẾT VỀ TEMPLATE <class T>
 * 
 * File này giải thích chi tiết về template trong C++ và cách sử dụng
 */

#include <iostream>
#include <string>
using namespace std;

/*
 * TEMPLATE LÀ GÌ?
 * 
 * Template là một tính năng của C++ cho phép viết code một lần
 * và sử dụng với nhiều kiểu dữ liệu khác nhau.
 * 
 * Thay vì viết nhiều hàm/class cho từng kiểu dữ liệu,
 * ta chỉ cần viết một template và compiler sẽ tự động tạo ra
 * các phiên bản phù hợp cho từng kiểu dữ liệu.
 */

/*
 * CÚ PHÁP TEMPLATE
 * 
 * template <class T> hoặc template <typename T>
 * 
 * - template: từ khóa bắt đầu
 * - <class T>: tham số template, T là kiểu dữ liệu
 * - class T và typename T là tương đương
 */

/*
 * VÍ DỤ 1: TEMPLATE HÀM
 * 
 * Thay vì viết nhiều hàm cho từng kiểu dữ liệu:
 * int max(int a, int b) { return (a > b) ? a : b; }
 * float max(float a, float b) { return (a > b) ? a : b; }
 * double max(double a, double b) { return (a > b) ? a : b; }
 * 
 * Ta chỉ cần viết một template:
 */
template <class T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

/*
 * VÍ DỤ 2: TEMPLATE CLASS
 * 
 * Thay vì viết nhiều class cho từng kiểu dữ liệu:
 * class IntNode { int data; ... }
 * class FloatNode { float data; ... }
 * class StringNode { string data; ... }
 * 
 * Ta chỉ cần viết một template class:
 */
template <class T>
class Node {
private:
    T data;
    Node<T> *next;
    
public:
    Node(T d) : data(d), next(nullptr) {}
    
    T getData() { return data; }
    void setData(T d) { data = d; }
    Node<T>* getNext() { return next; }
    void setNext(Node<T>* n) { next = n; }
};

/*
 * VÍ DỤ 3: TEMPLATE VỚI NHIỀU THAM SỐ
 * 
 * Có thể có nhiều tham số template:
 */
template <class T, class U>
class Pair {
private:
    T first;
    U second;
    
public:
    Pair(T f, U s) : first(f), second(s) {}
    
    T getFirst() { return first; }
    U getSecond() { return second; }
    
    void setFirst(T f) { first = f; }
    void setSecond(U s) { second = s; }
};

/*
 * VÍ DỤ 4: TEMPLATE VỚI GIÁ TRỊ MẶC ĐỊNH
 * 
 * Có thể đặt giá trị mặc định cho tham số template:
 */
template <class T = int, int size = 10>
class Array {
private:
    T arr[size];
    
public:
    void set(int index, T value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
    }
    
    T get(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        }
        return T(); // Trả về giá trị mặc định của kiểu T
    }
    
    int getSize() { return size; }
};

/*
 * VÍ DỤ 5: TEMPLATE SPECIALIZATION
 * 
 * Có thể tạo phiên bản đặc biệt cho kiểu dữ liệu cụ thể:
 */
template <class T>
void print(T value) {
    cout << "Generic: " << value << endl;
}

// Specialization cho string
template <>
void print<string>(string value) {
    cout << "String: \"" << value << "\"" << endl;
}

// Specialization cho pointer
template <class T>
void print(T* value) {
    cout << "Pointer: " << *value << endl;
}

/*
 * VÍ DỤ 6: TEMPLATE VỚI CONSTRAINTS
 * 
 * C++20 cho phép thêm constraints:
 */
template <class T>
requires std::integral<T>  // Chỉ chấp nhận kiểu số nguyên
T add(T a, T b) {
    return a + b;
}

/*
 * CÁCH SỬ DỤNG TEMPLATE
 */
void vi_du_su_dung() {
    cout << "=== VÍ DỤ SỬ DỤNG TEMPLATE ===\n\n";
    
    // 1. Sử dụng template hàm
    cout << "1. Template hàm:\n";
    cout << "max(5, 10) = " << max(5, 10) << endl;
    cout << "max(3.14, 2.71) = " << max(3.14, 2.71) << endl;
    cout << "max('a', 'z') = " << max('a', 'z') << endl;
    cout << endl;
    
    // 2. Sử dụng template class
    cout << "2. Template class:\n";
    Node<int> intNode(42);
    Node<string> stringNode("Hello");
    Node<double> doubleNode(3.14159);
    
    cout << "intNode: " << intNode.getData() << endl;
    cout << "stringNode: " << stringNode.getData() << endl;
    cout << "doubleNode: " << doubleNode.getData() << endl;
    cout << endl;
    
    // 3. Sử dụng template với nhiều tham số
    cout << "3. Template với nhiều tham số:\n";
    Pair<int, string> pair1(1, "One");
    Pair<string, double> pair2("Pi", 3.14159);
    
    cout << "pair1: " << pair1.getFirst() << " - " << pair1.getSecond() << endl;
    cout << "pair2: " << pair2.getFirst() << " - " << pair2.getSecond() << endl;
    cout << endl;
    
    // 4. Sử dụng template với giá trị mặc định
    cout << "4. Template với giá trị mặc định:\n";
    Array<> defaultArray;        // Sử dụng giá trị mặc định (int, size=10)
    Array<double, 5> customArray; // Sử dụng giá trị tùy chỉnh
    
    defaultArray.set(0, 100);
    customArray.set(0, 3.14159);
    
    cout << "defaultArray[0] = " << defaultArray.get(0) << endl;
    cout << "customArray[0] = " << customArray.get(0) << endl;
    cout << endl;
    
    // 5. Sử dụng template specialization
    cout << "5. Template specialization:\n";
    print(42);           // Generic
    print(3.14);         // Generic
    print(string("Hello")); // String specialization
    int x = 100;
    print(&x);           // Pointer specialization
    cout << endl;
}

/*
 * TEMPLATE VỚI DANH SÁCH LIÊN KẾT
 * 
 * Áp dụng template vào danh sách liên kết:
 */
template <class T>
class LinkedList {
private:
    Node<T> *head;
    int size;
    
public:
    LinkedList() : head(nullptr), size(0) {}
    
    void add(T data) {
        Node<T> *newNode = new Node<T>(data);
        newNode->setNext(head);
        head = newNode;
        size++;
    }
    
    void print() {
        Node<T> *current = head;
        cout << "List: ";
        while (current != nullptr) {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }
    
    int getSize() { return size; }
    
    ~LinkedList() {
        while (head != nullptr) {
            Node<T> *temp = head;
            head = head->getNext();
            delete temp;
        }
    }
};

void vi_du_linked_list() {
    cout << "=== VÍ DỤ TEMPLATE VỚI DANH SÁCH LIÊN KẾT ===\n\n";
    
    // Danh sách liên kết với kiểu int
    LinkedList<int> intList;
    intList.add(1);
    intList.add(2);
    intList.add(3);
    intList.print();
    cout << "Size: " << intList.getSize() << endl;
    cout << endl;
    
    // Danh sách liên kết với kiểu string
    LinkedList<string> stringList;
    stringList.add("World");
    stringList.add("Hello");
    stringList.print();
    cout << "Size: " << stringList.getSize() << endl;
    cout << endl;
    
    // Danh sách liên kết với kiểu double
    LinkedList<double> doubleList;
    doubleList.add(3.14159);
    doubleList.add(2.71828);
    doubleList.print();
    cout << "Size: " << doubleList.getSize() << endl;
    cout << endl;
}

/*
 * LỢI ÍCH CỦA TEMPLATE
 */
void loi_ich_template() {
    cout << "=== LỢI ÍCH CỦA TEMPLATE ===\n\n";
    
    cout << "1. TÁI SỬ DỤNG CODE:\n";
    cout << "   - Viết một lần, sử dụng nhiều lần\n";
    cout << "   - Không cần viết lại code cho từng kiểu dữ liệu\n\n";
    
    cout << "2. TYPE SAFETY:\n";
    cout << "   - Compiler kiểm tra kiểu dữ liệu tại compile time\n";
    cout << "   - Tránh lỗi runtime do sai kiểu dữ liệu\n\n";
    
    cout << "3. HIỆU SUẤT:\n";
    cout << "   - Không có overhead runtime\n";
    cout << "   - Code được tối ưu hóa cho từng kiểu dữ liệu\n\n";
    
    cout << "4. LINH HOẠT:\n";
    cout << "   - Có thể sử dụng với bất kỳ kiểu dữ liệu nào\n";
    cout << "   - Hỗ trợ user-defined types\n\n";
    
    cout << "5. DỄ BẢO TRÌ:\n";
    cout << "   - Chỉ cần sửa một nơi\n";
    cout << "   - Tất cả các phiên bản đều được cập nhật\n\n";
}

/*
 * LƯU Ý QUAN TRỌNG
 */
void luu_y_quan_trong() {
    cout << "=== LƯU Ý QUAN TRỌNG ===\n\n";
    
    cout << "1. TEMPLATE PHẢI ĐƯỢC ĐỊNH NGHĨA TRONG HEADER:\n";
    cout << "   - Template code phải có sẵn tại compile time\n";
    cout << "   - Không thể tách declaration và definition\n\n";
    
    cout << "2. COMPILER TẠO CODE CHO TỪNG KIỂU DỮ LIỆU:\n";
    cout << "   - max<int> tạo code riêng cho int\n";
    cout << "   - max<double> tạo code riêng cho double\n";
    cout << "   - Có thể làm tăng kích thước executable\n\n";
    
    cout << "3. ERROR MESSAGES PHỨC TẠP:\n";
    cout << "   - Thông báo lỗi có thể khó hiểu\n";
    cout << "   - Cần hiểu template để debug\n\n";
    
    cout << "4. COMPILE TIME TĂNG:\n";
    cout << "   - Template được xử lý tại compile time\n";
    cout << "   - Có thể làm chậm quá trình compile\n\n";
}

int main() {
    cout << "GIẢI THÍCH CHI TIẾT VỀ TEMPLATE <class T>\n";
    cout << "========================================\n\n";
    
    vi_du_su_dung();
    vi_du_linked_list();
    loi_ich_template();
    luu_y_quan_trong();
    
    return 0;
}

/*
 * TÓM TẮT:
 * 
 * template <class T> có nghĩa là:
 * - Tạo một template với tham số T
 * - T có thể là bất kỳ kiểu dữ liệu nào
 * - Compiler sẽ tạo code riêng cho từng kiểu dữ liệu được sử dụng
 * 
 * VÍ DỤ:
 * template <class T>
 * class Node {
 *     T data;  // T có thể là int, float, string, ...
 * };
 * 
 * SỬ DỤNG:
 * Node<int> intNode;      // T = int
 * Node<string> strNode;   // T = string
 * Node<double> dblNode;   // T = double
 * 
 * LỢI ÍCH:
 * - Viết một lần, sử dụng nhiều lần
 * - Type safety
 * - Hiệu suất cao
 * - Linh hoạt
 */

