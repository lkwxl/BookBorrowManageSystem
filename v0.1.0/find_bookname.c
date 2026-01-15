#include"find_bookname.h"
void find_bookname(FILE *fp)
{
    int count;
    borrow *p;
    p=read(fp,&count);
    char name[50];
    printf("请输入图书名称:");
    scanf("%s",name);
    int found=0;
    for(int i=0;i<count;i++)
    {
        if(strcmp(p[i].book_name,name)==0)
        {
            found++;
            printf("图书名称:%s\n价格:%f\n借阅日期:%s\n",p[i].book_name,p[i].price,p[i].date);
            printf("流水号:%s\n借阅人:%s\n借阅人ID号:%d\n",p[i].borrow_number,p[i].borrow_name,p[i].borrow_id);
            printf("---------------\n");
        }
    }
    if(found==0) printf("未找到对应记录\n");
    free(p);
    printf("按任意键回到主页面\n");
    getch();
    system("cls");
}