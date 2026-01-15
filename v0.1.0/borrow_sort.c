#include"borrow_sort.h"
void borrow_sort(FILE *fp)
{
    borrow *p;
    int count;
    p=read(fp,&count);
    for (int i=0;i<count-1;i++)
    {
        for (int j=i+1;j<count;j++)
        {
            borrow tmp;
            if(p[i].borrow_id<p[j].borrow_id)
            {
                tmp=p[j];
                p[j]=p[i];
                p[i]=tmp;
            }
        }
    }
    for(int i=0;i<count;i++)
    {
        printf("图书名称:%s\n价格:%f\n借阅日期:%s\n",p[i].book_name,p[i].price,p[i].date);
        printf("流水号:%s\n借阅人:%s\n借阅人ID号:%d\n",p[i].borrow_number,p[i].borrow_name,p[i].borrow_id);
        printf("---------------\n");
    }
    free(p);
    printf("按任意键回到主页面\n");
    getch();
    system("cls");
}