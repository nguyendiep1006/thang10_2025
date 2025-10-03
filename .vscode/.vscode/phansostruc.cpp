#include<stdio.h>
#include<string.h>
#include<math.h>
struct ps{
   int tu, mau;
};
typedef struct ps ps;
int gcd(int a, int b){
   if(b == 0) return a;
   else return gcd(b, a% b); 
}
int lcm(int a, int b){
   return a * b / gcd(a, b);
}
ps toigian(ps a){
   ps res;
   int uc = gcd(abs(a.tu), abs(a.mau));
   res.tu = a.tu / uc;
   res.mau = a.mau / uc;
   if(res.mau < 0) {
      res.tu = -res.tu;
      res.mau = -res.mau;
   }
   return res;
}
ps tong(ps a, ps b){
   ps res;
   int mc = lcm(a.mau, b.mau);
   res.mau = mc;
   res.tu = mc / a.mau * a.tu + mc / b.mau * b.tu;

   return toigian(res);
}
ps hieu(ps a, ps b){
   ps res;
   int mc = lcm(a.mau, b.mau);

   res.mau = mc;
   res.tu = mc / a.mau * a.tu - mc / b.mau * b.tu;
   return toigian(res);
}
int main(){
   ps a, b;
   printf("Nhap 2 phan so (tu so va mau so cho moi ps): \n");
   scanf("%d%d%d%d", &a.tu, &a.mau, &b.tu, &b.mau);

   if(a.mau == 0 || b.mau == 0){
      printf("Mau so khong the bang 0.\n");
      return 1;
   }
   a = toigian(a);
   b = toigian(b);

   ps t = tong(a, b), h = hieu(a, b);
   printf("Tong: %d/%d\nHieu: %d/%d\n", t.tu, t.mau, h.tu, h.mau);
   return 0;
}

