#include"mprice.h"
void mprice(FILE *fp)
{
    int count;
    borrow *p;
    p=read(fp,&count);
    float max,min;
    int ma=0,mi=0;
    if(p[0].price>=p[1].price)
        {
            max=p[0].price;
            min=p[1].price;
        }
        else
        {
            max=p[1].price;
            min=p[0].price;
        }
    for(int i=2;i<count;i++)
    {
        if(p[i].price>=max)
        {
            max=p[i].price;
            ma=i;
        }
        if(p[i].price<=min) 
        {
            min=p[i].price;
            mi=i;
        }
    }
    printf("价格最高的书是  %s,为%.2f元\n",p[ma].book_name,p[ma].price);
    printf("价格最低的书是  %s,为%.2f元\n",p[mi].book_name,p[mi].price);
    free(p);
    printf("按任意键回到主页面\n");
    getch();
    system("cls");
}