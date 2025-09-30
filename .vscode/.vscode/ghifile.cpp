#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f;
    f = fopen("000.txt", "r");
    if (f == NULL)
    {
        printf("Canot open file !\n");
        return 0;
    }
    else
    {
        fseek(f, 0, SEEK_SEt);
        printf("%d", ftell(f));
    }
fclose(f);
return 0;
}