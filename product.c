#include "product.h"

int addProduct(Product *s){
    printf("제품명은?: ");
    getchar();
    scanf("%[^\n]s", s->name);
    printf("제품 설명은?: ");
    getchar();
    scanf("%[^\n]s", s->explain);
    printf("무게는?: ");
    scanf("%s",s->weight);
    printf("유통기한은?(ex:04.29): ");
    scanf("%s",s->date);
    printf("제품 카테고리?: ");
    getchar();
    scanf("%s",s->category);
    printf("판매 가격은?: ");
    scanf("%d",&s->price);
    printf("=>추가됨!\n");
    return 1;
}