#include <stdio.h>

typedef struct {
	char name[20];
	char explain[50];
	char category[30];
	int price;
}product;

int addProduct(Product *s);
void readProduct(Product *s);
int selectMenu();
int updateProduct(Product *s);
int deleteProduct(Product *s);
