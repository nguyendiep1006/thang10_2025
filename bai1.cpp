#include<bits/stdc++.h>
using namespace std;

class Diem{
private:
   double x;
   double y;
public:
   // Cau tu khong doi (mac dinh)
   Diem(): x(0), y(0){}

   // Cau tu co doi day du
   Diem(double hoanhDo, double tungDo): x(hoanhDo), y(tungDo){}

   // Phuong thuc nhap toa do
   void nhap(){
      cout << "Nhap hoanh do x: ";
      cin >> x;
      cout << "Nhap tung do y: ";
      cin >> y;
   }

   // Phuong thuc in toa do
   void in() const{
      cout << "(" << x << ", " << y << ")";
   }
};

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   // Su dung cau tu khong doi va nhap tu ban phim
   Diem A;            // mac dinh (0,0)
   A.nhap();

   // Su dung cau tu co doi day du
   double x, y;
   cout << "Nhap x va y cho diem B: ";
   cin >> x >> y;
   Diem B(x, y);

   cout << "Toa do diem A: ";
   A.in();
   cout << "\nToa do diem B: ";
   B.in();
   cout << "\n";

   return 0;
}