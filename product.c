#include "product.h"

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
void searchName(Product *s, int count){
	int scnt=0;
	char search[20];

	printf("원하는 제품은? ");
	getchar();
	scanf("[^\n]s",search);

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
int selectMenu(){
        int menu;
        printf("\n===제품===\n");
        printf("1. 제품조회\n");
        printf("2. 제품추가\n");
        printf("3. 제품수정\n");
        printf("4. 제품삭제\n");
	printf("5. 파일저장\n");
	printf("6. 제품이름 검색\n");
        printf("0. 종료\n\n");
        printf("=> 원하는 메뉴는?");
        scanf("%d",&menu);
        return menu;
}
int main(void){
    Product slist[100];
    int curcount=0;

    int count=0,menu;
    count=loadData(slist);
    curcount=count;

    while(1){
        menu=selectMenu();
        if(menu==0)break;
        if(menu==1){
        if(count>0){
            readProduct(s);
        }
        else{
            printf("데이터가 없습니다!\n");
        }
        }
        else if(menu==2){
        count+=addProduct(&s);
        }
        else if(menu==3){
            updateProduct(&s);
        }
        else if(menu==4){
            if(deleteProduct(&s)){
             count--;
         }
	printf("=>삭제됨!\n");
        }
	else if(menu==6){
		if(count==0)
			printf("=>데이터 없음!\n");
		else
			searchName(slist,curcount);
	}
     }
    printf("종료됨!\n");
    return 0;
}
