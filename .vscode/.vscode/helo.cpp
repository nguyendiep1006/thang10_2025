#include<stdio.h>
#include<string.h>

int main(){
    FILE *f;
    f = fopen("000.txt", "w");
    for(int i = 1;i<=200;i++){
        fprintf(f, "%d\n", i);
    }
    fclose(f);
    he(jslfjskf)