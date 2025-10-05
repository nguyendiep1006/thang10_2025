# HƯỚNG DẪN SỬ DỤNG TEMPLATE<T> TRONG C++

## 1. TEMPLATE LÀ GÌ?

**Template** là một tính năng mạnh mẽ trong C++ cho phép bạn viết code một lần và sử dụng với nhiều kiểu dữ liệu khác nhau.

### Ví dụ đơn giản:
```cpp
// Thay vì viết nhiều class tương tự:
class NodeInt { int data; };
class NodeFloat { float data; };
class NodeString { string data; };

// Chỉ cần viết 1 template class:
template <class T>
class Node { T data; };
```

## 2. LỢI ÍCH CỦA TEMPLATE

### ✅ **Giảm code trùng lặp**
- Viết 1 lần, dùng nhiều kiểu dữ liệu
- Không cần copy-paste code

### ✅ **Type Safety**
- Compiler kiểm tra kiểu dữ liệu tại compile time
- Tránh lỗi runtime

### ✅ **Performance cao**
- Không có overhead như virtual functions
- Code được tối ưu cho từng kiểu dữ liệu

### ✅ **Linh hoạt**
- Có thể dùng với bất kỳ kiểu dữ liệu nào
- Hỗ trợ cả kiểu dữ liệu có sẵn và tùy chỉnh

## 3. CÚ PHÁP CƠ BẢN

### Template Class:
```cpp
template <class T>  // hoặc template <typename T>
class TenClass {
private:
    T data;  // T có thể là int, float, string, SinhVien, v.v.
public:
    TenClass(T d = T()) { data = d; }
    T getData() { return data; }
    void setData(T d) { data = d; }
};
```

### Template Function:
```cpp
template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}
```

## 4. CÁCH SỬ DỤNG

### Khai báo:
```cpp
// Tạo object với các kiểu dữ liệu khác nhau
TenClass<int> objInt(100);
TenClass<float> objFloat(3.14f);
TenClass<string> objString("Hello");
TenClass<SinhVien> objSV(sinhVienObject);
```

### Gọi function:
```cpp
// Function tự động xác định kiểu dữ liệu
int maxInt = getMax(10, 20);           // T = int
float maxFloat = getMax(3.14f, 2.71f); // T = float
char maxChar = getMax('A', 'B');       // T = char
```

## 5. VÍ DỤ THỰC TẾ: TEMPLATE NODE

### Node thông thường (không template):
```cpp
class Node {
private:
    SinhVien data;  // Chỉ có thể chứa SinhVien
    Node* next;
public:
    Node(SinhVien sv) { data = sv; next = nullptr; }
    SinhVien getData() { return data; }
};
```

### Node với template:
```cpp
template <class T>
class Node {
private:
    T data;         // Có thể chứa bất kỳ kiểu nào
    Node<T>* next;
public:
    Node(T d) { data = d; next = nullptr; }
    T getData() { return data; }
};
```

### Sử dụng:
```cpp
Node<int> nodeInt(100);           // Node chứa số nguyên
Node<float> nodeFloat(3.14f);     // Node chứa số thực
Node<string> nodeString("Hello"); // Node chứa chuỗi
Node<SinhVien> nodeSV(sv);        // Node chứa đối tượng SinhVien
```

## 6. CÁC FILE DEMO TRONG DỰ ÁN

### 📁 **node_template.h**
- Template class Node hoàn chỉnh
- Có thể sử dụng với bất kỳ kiểu dữ liệu nào
- Bao gồm tất cả phương thức cần thiết

### 📁 **template_simple_demo.cpp**
- Demo đơn giản, dễ hiểu cho người mới học
- So sánh code có template và không có template
- Minh họa lợi ích của template

### 📁 **demo_template_node.cpp**
- Demo chi tiết với nhiều kiểu dữ liệu
- Các thao tác cơ bản và nâng cao
- Ví dụ thực tế với SinhVien

### 📁 **template_so_demo.cpp** (có sẵn)
- Demo template với các kiểu số khác nhau
- Minh họa tính linh hoạt của template

## 7. LƯU Ý QUAN TRỌNG

### ⚠️ **Template Instantiation**
```cpp
// Compiler tự động tạo code cho mỗi kiểu dữ liệu được sử dụng
Node<int> node1;     // Compiler tạo Node_int
Node<float> node2;   // Compiler tạo Node_float
// Nếu không sử dụng Node<double>, compiler sẽ không tạo Node_double
```

### ⚠️ **Type Requirements**
```cpp
// Một số template function yêu cầu kiểu dữ liệu có operator nhất định
template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;  // T phải có operator>
}
```

### ⚠️ **Include Header**
```cpp
// Template phải được định nghĩa trong header file
// Không thể tách implementation ra file .cpp riêng
```

## 8. KẾT LUẬN

Template<T> là một công cụ mạnh mẽ giúp:
- **Viết code sạch hơn**: Ít trùng lặp, dễ maintain
- **Tăng tính linh hoạt**: Một code, nhiều kiểu dữ liệu
- **Đảm bảo an toàn**: Type checking tại compile time
- **Tối ưu performance**: Không overhead

**Khuyến nghị**: Sử dụng template khi bạn cần viết code tương tự cho nhiều kiểu dữ liệu khác nhau, đặc biệt hữu ích cho các cấu trúc dữ liệu như danh sách liên kết, stack, queue, v.v.

---

*Tạo bởi: AI Assistant - 2025*
