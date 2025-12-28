#include"main.h"
int main()
{
    printf("**********图书借阅信息管理系统**********\n");
    while(1)
    {
        FILE *fp=fopen(file_name,"ab+");
        if(fp==NULL)
        {
            printf("文件无法创建或读取!");
            exit(1);
        }
        printf("1.图书借阅信息录入\n2.图书借阅信息排序输出\n3.按图书名称查询借阅记录\n4.按借阅人姓名查询借阅记录\n");
        printf("5.查询价格最高和最低的图书\n6.统计输出借阅次数最多的三本书\n0.退出系统\n提示:请输入数字序号选择对应的操作!\n");
        int n;
        scanf("%d",&n);
        system("cls");
        switch (n)
        {
        case 1:
            borrow_write(fp);
            break;
        case 2:
            borrow_sort(fp);
            break;
        case 3:
            find_bookname(fp);
            break;
        case 4:
            find_borrowname(fp);
            break;
        case 5:
            mprice(fp);
            break;
        case 6:
            maxborrow(fp);
            break;
        case 0:
            fclose(fp);
            exit(0);
        default:
            printf("请输入正确的序号!\n---------------\n");
            break;
        }
        fclose(fp);
    }
}
