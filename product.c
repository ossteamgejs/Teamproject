#include "product.h"
#include <string.h>

int addProduct(Product *s){
    printf("제품명은?: ");
    getchar();
    scanf("%[^\n]s", s->name);
    printf("제품 설명은?: ");
    getchar();
    scanf("%[^\n]s", s->explain);
    printf("중량은?(ex:50ml,1kg): ");
    scanf("%s",s->weight);
    printf("유통기한은?(ex:2022/04/29): ");
    scanf("%s",s->date);
    printf("제품 카테고리?: ");
    getchar();
    scanf("%s",s->category);
    printf("판매 가격은?: ");
    scanf("%d",&s->price);
    printf("=>추가됨!\n");
    return 1;
}

void readProduct(Product s){
    if(s.price==-1) return;
    printf("제품명: %s\n",s.name);
    printf("제품 설명: %s\n",s.explain);
    printf("제품 중량: %s\n",s.weight);
    printf("유통기한 :%s\n",s.date);
    printf("카테고리: %s\n",s.category);
    printf("제품 가격: %d원\n",s.price); 
}

int updateProduct(Product *s){
    printf("제품명은?: ");
    getchar();
    scanf("%[^\n]s", s->name);
    printf("제품 설명은?: ");
    getchar();
    scanf("%[^\n]s", s->explain);
    printf("중량은?(ex:50ml,1kg): ");
    scanf("%s",s->weight);
    printf("유통기한은?(ex:2022/04/29): ");
    scanf("%s",s->date);
    printf("제품 카테고리?: ");
    getchar();
    scanf("%s",s->category);
    printf("판매 가격은?: ");
    scanf("%d",&s->price);
    printf("=>수정됨!\n");
    return 1;
}
int deleteProduct(Product *s){
        s->price = -1;
        return 1;
}
void listProduct(Product *s, int count){
	for(int i=0;i<count;i++){
	if(s[i].price==-1) continue;
       	printf("===============================================\n");
	printf("%d번\n",i+1); readProduct(s[i]);
	}
   printf("\n");
}
int selectNumber(Product *s, int count){
	int number;
	listProduct(s,count); printf("번호는?(취소 :0)");
      	scanf("%d",&number);
	return number;
}
void saveData(Product *s,int count){
       	FILE *fp;
	fp=fopen("product.txt","wt");
       	for(int i=0;i<count-1;i++){
	if(s[i].price==-1) continue;
	fprintf(fp, "%s, %s, %s, %s, %s, %d\n",s[i].name, s[i].explain, s[i].weight,
	s[i].date,s[i].category,s[i].price);
   	 }
	fprintf(fp, "%s, %s, %s, %s, %s, %d",s[count-1].name, s[count-1].explain, s[count-1].weight,
        s[count-1].date,s[count-1].category,s[count-1].price);
	fclose(fp);
	printf("저장됨!\n");
}
int loadData(Product *s){
	FILE *fp;
   	fp=fopen("product.txt","rt");
   	if(fp==NULL){
	printf("=>파일이 없음\n");
	return 0;
       	}
   int count=0;
   for(;;count++){
       const int max=100;
       char line[max];
       if(feof(fp)) break;
       fgets(line,max,fp);
       sscanf(line,"%[^,], %[^,], %[^,], %[^,], %[^,], %d",s[count].name,s[count].explain,s[count].weight,s[count].date, s[count].category,&s[count].price);   }
   fclose(fp);
printf("=>로딩 성공\n");
return count;
}

void searchName(Product *s, int count){
	int scnt=0;
	char search[20];

	printf("원하는 제품은? ");
	getchar();
	scanf("%[^\n]s",search);

	for(int i=0; i<count; i++) {
		if(s[i].price==-1) continue;
		if(strstr(s[i].name,search)){
			printf("===========================================\n");
			printf("%d번\n",i+1);
			readProduct(s[i]);
			scnt++;
		}
	}
	if(scnt==0) printf("=>검색 결과가 없음\n");
}
void searchPrice(Product *s, int count){
	int scnt = 0;
	int search;

	printf("검색할 가격은? ");
   	scanf("%d", &search);

    	for(int i=0; i <count; i++){
        	if(s[i].price == -1) continue;
        	if(search == s[i].price){
			printf("===========================================\n");
			printf("%d번\n",i+1);
			readProduct(s[i]);
         		scnt++;
        	}
    	}
	if(scnt==0) printf("=>검색 결과가 없음\n");
}
void searchWeight(Product *s, int count){
        int scnt = 0;
        char search[20];

        printf("검색할 중량은? ");
        scanf("%s", search);

        for(int i=0; i <count; i++){
                if(s[i].price == -1) continue;
		if(strstr(s[i].weight,search)){
                        printf("===========================================\n");
                        printf("%d번\n",i+1);
                        readProduct(s[i]);
                        scnt++;
                }
        }
        if(scnt==0) printf("=>검색 결과가 없음\n");
}
void searchCategory(Product *s, int count){
	int scnt=0;
	char search[30];

	printf("검색할 카테고리는? ");
	getchar();
	scanf("%[^\n]s",search);

	for(int i=0; i<count; i++) {
		if(s[i].price==-1) continue;
		if(strstr(s[i].category,search)){
			printf("===========================================\n");
			printf("%d번\n",i+1);
			readProduct(s[i]);
			scnt++;
		}
	}
	if(scnt==0) printf("=>검색 결과가 없음\n");
}
int selectMenu(){
        int menu;
        printf("\n===제품===\n");
        printf("1. 제품조회\n");
        printf("2. 제품추가\n");
        printf("3. 제품수정\n");
        printf("4. 제품삭제\n");
	printf("5. 파일저장\n");
	printf("6. 제품이름 검색\n");
        printf("7. 제품가격 검색\n");
	printf("8. 제품중량 검색\n");
	printf("9. 제품카테고리 검색\n");
	printf("0. 종료\n\n");
        printf("=> 원하는 메뉴는?");
        scanf("%d",&menu);
        return menu;
}
