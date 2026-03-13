#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;
    int words=0;

    fp=fopen("text.txt","r");

    while((ch=fgetc(fp))!=EOF)
    {
        if(ch==' '||ch=='\n')
            words++;
    }

    fclose(fp);

    printf("Total words: %d\n",words+1);
}