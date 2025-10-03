#include<stdio.h>
#include<string.h>
int main(){
    FILE *f;
    f = fopen("000.txt", "r");
    if(f == NULL){
        printf("Canot open file!\n"); return 0;
    }
    char c[1000];
    while(fgets(c,100,f) != NULL){
        printf("%s", c);
    }
    fclose(f);
}