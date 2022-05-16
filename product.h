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
void saveData(Product *s, int count);//파일을 저장하는 함수
int loadData(Product *s);//저장된 파일을 불러오는 함수
int selectNumber(Product *s, int count);//번호 선택 함수
void listProduct(Product *s,int count);//제품 리스트 조회 함수
void searchName(Product *s, int count);//제품 이름을 검색하는 함수
void searchPrice(Product *s, int count);//제품 가격을 검색하는 함수
void searchWeight(Product *s, int count);//제품 중량을 검색하는 함수
void searchCategory(Product *s, int count);//제품 카테고리를 검색하는 함수

