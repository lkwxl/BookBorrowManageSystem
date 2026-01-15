#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
#include"borrow_write.h"
#include"borrow_sort.h"
#include"find_bookname.h"
#include"find_borrowname.h"
#include "mprice.h"
#include"maxborrow.h"
#define file_name "borrow_records"
void borrow_write(FILE *fp);
void borrow_sort(FILE *fp);
void find_bookname(FILE *fp);
void find_borrowname(FILE *fp);
void mprice(FILE *fp);
void maxborrow(FILE *fp);