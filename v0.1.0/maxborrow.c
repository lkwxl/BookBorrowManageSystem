#include"maxborrow.h"
void maxborrow(FILE *fp)
{
    int count;
    borrow *p;
    p=read(fp,&count);
    typedef struct bookcounttag
     { 
        char name[50];
        int cnt;
     }BookCount;
    BookCount *arr = NULL;
    int unique=0;
    for (int i=0;i<count;i++)
    {
        int found=-1;
        for(int j=0;j<unique;j++)
        {
            if(strcmp(arr[j].name,p[i].book_name)==0)
            {
                found=j;
                break;
            }
        }
        if(found!=-1) arr[found].cnt++;
        else
        {
            BookCount *tmp = realloc(arr,(unique+1)*sizeof(BookCount));
            if (tmp == NULL) {
                printf("内存分配失败！\n");
                free(arr);
                free(p);
                return;
            }
            arr=tmp;
            strcpy(arr[unique].name,p[i].book_name);
            arr[unique].cnt=1;
            unique++;
        }

    }
    for(int i=0;i<unique-1;i++)
    {
        for(int j=i+1;j<unique;j++)
        {
            if(arr[i].cnt < arr[j].cnt)
            {
                BookCount t;
                t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
    printf("借阅次数最多的三本数:\n");
    for (int i=0;i<3;i++)
    {
        printf("%s  借阅次数:%d\n",arr[i].name, arr[i].cnt);
        printf("---------------\n");
    }
    free(p);
    free(arr);
    printf("按任意键回到主页面\n");
    getch();
    system("cls");
}