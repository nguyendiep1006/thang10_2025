#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong phan tu N (N <= 1000): ";
    cin >> n;
    
    // Kiểm tra điều kiện N <= 1000
    if (n <= 0 || n > 1000) {
        cout << "N phai la so nguyen duong va <= 1000!" << endl;
        return 1;
    }
    
    stack<int> S;  // Stack cho số chẵn
    queue<int> Q;  // Queue cho số lẻ
    
    cout << "Nhap " << n << " so nguyen:" << endl;
    for (int i = 0; i < n; i++) {
        int num;
        cout << "So thu " << (i + 1) << ": ";
        cin >> num;
        
        if (num % 2 == 0) {
            // Số chẵn -> thêm vào Stack
            S.push(num);
        } else {
            // Số lẻ -> thêm vào Queue
            Q.push(num);
        }
    }
    
    // Xuất các phần tử trong Stack S (số chẵn)
    cout << "\nCac phan tu trong Stack S (so chan): ";
    if (S.empty()) {
        cout << "Stack S rong";
    } else {
        while (!S.empty()) {
            cout << S.top() << " ";
            S.pop();
        }
    }
    
    // Xuất các phần tử trong Queue Q (số lẻ)
    cout << "\nCac phan tu trong Queue Q (so le): ";
    if (Q.empty()) {
        cout << "Queue Q rong";
    } else {
        while (!Q.empty()) {
            cout << Q.front() << " ";
            Q.pop();
        }
    }
    
    cout << endl;
    return 0;
}
