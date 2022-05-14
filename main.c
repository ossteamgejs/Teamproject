#include "product.h"

int main(void){
    Product slist[100];
    int curcount=0;

    int count=0,menu;
    count=loadData(slist);
    curcount=count;

    while(1){
        menu=selectMenu();
        if(menu==0)break;
        if(menu == 1 || menu == 3 || menu == 4){
                if(count == 0) continue;
        }
        if(menu==1){
                if(count>0){
                        listProduct(slist, curcount);
                }else{
                        printf("데이터가 없습니다!\n");
                }
        }
        else if(menu==2){
                count+=addProduct(&slist[curcount++]);
        }
        else if(menu==3){
                int no = selectNumber(slist, curcount);
                        if(no == 0){
                                printf("=>취소됨!\n");
                                continue;
                        }
                        updateProduct(&slist[no-1]);

        }
        else if(menu==4){
                int no = selectNumber(slist,curcount);
                        if(no == 0){
                                printf("=>취소됨!\n");
                                continue;
                        }
                        int del;
                        printf("삭제하시겠습니까?(삭제:1)");
                        scanf("%d",&del);
                        if (del == 1){
                                if(deleteProduct(&slist[no-1])) count--;
                                printf("=> 삭제됨!\n");
                        }
        }
        else if(menu==5){
                saveData(slist, curcount);
        }
	else if(menu==6){
                if(count==0)
                        printf("=>데이터 없음!\n");
                else
                        searchName(slist,curcount);
        }
        else if(menu==7){
                if(count==0)
                        printf("=>데이터 없음!\n");
                else
                        searchPrice(slist,curcount);
        }
        else if(menu==8){
                if(count==0)
                        printf("=>데이터 없음!\n");
                else
                        searchWeight(slist,curcount);
        }
        else if(menu==9){
                if(count==0)
                        printf("=>데이터 없음!\n");
                else
                        searchCategory(slist,curcount);
        }
        count++;
     }
    printf("종료됨!\n");
    return 0;
}

