#include<stdio.h>
#include<string.h>
int main(){
    FILE *f;
    f = fopen("28tech_demo.txt", "w");
    char c[] = "28tech c programing!";
    for(int i = 0;i<strlen(c);i++){
        fputc(c[i], f);
    }
    fclose(f);
}
