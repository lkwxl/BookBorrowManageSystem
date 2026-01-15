#include"borrow_write.h"
void borrow_write(FILE *fp)
{
    char select;
    do{
        borrow data;
        printf("图书名称:");
        scanf("%s",data.book_name);
        printf("价格:");
        scanf("%f",&data.price);
        printf("借阅日期:");
        scanf("%s",data.date);
        printf("流水号:");
        scanf("%s",data.borrow_number);
        printf("借阅人:");
        scanf("%s",data.borrow_name);
        printf("借阅人ID号:");
        scanf("%d",&data.borrow_id);
        getchar();
        printf("是否继续录入(y/n)\n");
        scanf("%c",&select);
        fwrite(&data,sizeof(borrow),1,fp);
    }while(select=='y'||select=='Y');
    system("cls");
}