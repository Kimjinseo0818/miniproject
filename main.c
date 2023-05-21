#include <stdio.h>
#include "order.h"
#include "menu.h"

int main() {
	Order p[100];
	Menu s[20];
	int count, menu;
        int index = 0;
        int num;
	int day;
	int menu;
	printf("오늘 요일은? (월:0, 화:1, 수:2, 목:3, 금:4) ");
	scanf("%d", &day);
	
	count = loadOrder(s);
        index = count;

	while(1) {	
  		printf("\n*** 재고 확인 ***\n");
  		printf("1. 조회 ");
  		printf("2. 추가 ");
  		printf("3. 수정 ");
  		printf("4. 삭제 ");
  		printf("5. 파일저장 ");
  		printf("6. 물품검색 ");
  		printf("7. 사이즈분류 ");
  		printf("0. 종료 >> ");
  		scanf("%d", &menu);

		if (menu == 0)
                        break;
                if (menu == 1) {

                        if(count > 0) {
                                listItem(s, index);
                        } else {
                                printf("데이터가 없습니다.\n");
                        }
                } else if (menu == 2) {
                        s[index] = (Item *)malloc(sizeof(Item));
                        count += addItem(s[index++]);
                } else if (menu == 3) {
                        listItem(s, index);
                        printf("번호는 (취소: 0)? ");
                        scanf("%d", &num);
                        if (num == 0) {
                                printf("=>취소됨!\n");
                                continue;
                        } else {
                                updateItem(s[num-1]);
                        }
                } else if (menu == 4) {
                        listItem(s, index);

                        printf("\n번호는 (취소: 0)? ");
                        scanf("%d", &num);
                        if (num == 0) {
                                continue;
                        }
                        deleteItem(s, num);
                } else if (menu == 5) {
                        saveData(s, count);
                }
	}
	printf("종료!\n");
	return 0;
}
