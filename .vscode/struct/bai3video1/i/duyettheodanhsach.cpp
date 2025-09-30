#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct SV{
    char ten[100];
    char ns[100];
    char dc[100];
    double gpa;
    int stt;  
};
typedef struct SV SV;
void in(SV a){
    printf("%s %s %s %.2lf\n", a.ten, a.ns, a.dc, a.gpa);
}
int cmp(const void *a,const void *b){
    SV *x = (SV*)a;
    SV *y =(SV*)b;
    if(strcmp(x->ten, y->ten) != 0){
        return strcmp(x->ten, y->ten);
    }
    else
        return x->stt - y->stt;
}
int main(){
    int n;
    scanf("%d", &n);
    SV a[n];
    for(int i = 0;i<n;i++){
        getchar();
        fgets(a[i].ten, 100,stdin); a[i].ten[strlen(a[i].ten)-1] = '\0';
        fgets(a[i].ns,100,stdin); a[i].ns[strlen(a[i].ns)-1] = '\0';
        fgets(a[i].dc,100,stdin); a[i].dc[strlen(a[i].dc)-1] = '\0';
        scanf("%lf", &a[i].gpa);
        a[i].stt = i;
    }
    for(int i = 0;i<n;i++){
        if(strcmp(a[i].ten, "NAM DINH") == 0  && a[i].gpa >= 2.5){
            in(a[i]);
        }
    }
}