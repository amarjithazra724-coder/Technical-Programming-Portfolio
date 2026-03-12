#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;

    fp=fopen("message.txt","r+");

    if(fp==NULL)
    {
        printf("File not found");
        return 0;
    }

    while((ch=fgetc(fp))!=EOF)
    {
        fseek(fp,-1,SEEK_CUR);
        fputc(ch+3,fp);
        fseek(fp,0,SEEK_CUR);
    }

    fclose(fp);

    printf("File encrypted!\n");
}