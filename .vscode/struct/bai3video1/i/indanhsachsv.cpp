#include<stdio.h>
#include<string.h>
#include<math.h>
struct SV{
  char ten[100];
  char ns[100];
  char dc [100];
  int toan, ly, hoa;
};
typedef struct SV SV;
void in(SV a){
  printf("%s %s %s %d",a.ten, a.ns, a.dc, a.toan + a.ly + a.hoa);
}
int main(){
  int n;
  scanf("%d", &n);
  SV a[n];
  int max_diem = 0;
  for(int i = 0;i<n;i++){
    getchar();
    fgets(a[i].ten, 100,stdin); a[i].ten[strlen(a[i].ten)-1] = '\0';
    fgets(a[i].ns, 100, stdin); a[i].ns[strlen(a[i].ns)-1 ] = '\0';
    fgets(a[i].dc,100, stdin); a[i].dc[strlen(a[i].dc) -1] = '\0';
    scanf("%d%d%d", &a[i].toan, &a[i].ly, &a[i].hoa);
    max_diem = fmax(max_diem, a[i].toan + a[i].ly+ a[i].hoa);
  }
  printf("Danh sach thu khoa:\n");
  for(int i = 0;i<n;i++){
    if(a[i].toan + a[i].ly + a[i].hoa == max_diem){
      in(a[i]);
      printf("\n");
    }
  }
  printf("KET QUA XET TUYEN\n");
  for(int i = 0;i<n;i++){
    in(a[i]);
    if(a[i].toan + a[i].ly + a[i].hoa >= 24)
            printf("DO\n");
     else
               printf("truot\n");    
  }
  return 0;

}