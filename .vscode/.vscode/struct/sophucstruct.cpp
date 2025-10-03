#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct comp{
    int thuc, ao;
};
typedef struct comp comp;
int main(){
    comp a, b;
    scanf("%d%d%d%d", &a.thuc, &a.ao, &b.thuc, &b.ao);
        comp tong, hieu, tich;
        tong.thuc = a.thuc + b.thuc; tong.ao = a.ao + b.ao;
        hieu.thuc = a.thuc - b.thuc; hieu.ao = a.ao  - b.ao;
        tich.thuc = a.thuc * b.thuc - a.ao* b.ao;
        tich.ao = a.thuc * b.ao + a.ao * b.thuc;
        printf("%d %d\n%d %d\n %d\n", tong.thuc, tong.ao, hieu.thuc, hieu.ao, tich.thuc, tich.ao);
    }

