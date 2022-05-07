#include <stdio.h>

typedef struct {
	char name[20];
	char explain[50];
	char category[30];
	char date[20];
	char weight[20];
	int price;
}Product;

int addProduct(Product *s);//제품추가함수
void readProduct(Product s);//제품조회함수
int selectMenu();//메뉴선택함수
int updateProduct(Product *s);//제품수정함수
int deleteProduct(Product *s);//제품삭제함수
