#include"read.h"
borrow *read(FILE *fp,int *count)
{
    borrow temp,*ptr=NULL;
    *count = 0;                   
    fseek(fp, 0, SEEK_SET);       
    while(fread(&temp,sizeof(borrow),1,fp)==1)
    {
        (*count)++;
        ptr = (borrow*)realloc(ptr,(*count)*sizeof(borrow));
        if(ptr==NULL)
        {
            printf("ƒ⁄¥Ê…Í«Î ß∞‹");
            free(ptr);
            fclose(fp);
            exit(1);
        }
        ptr[(*count)-1] = temp;
    }
    return ptr;
}