#include <stdio.h>
#include "menu.h"
#include <stdlib.h>
#include <time.h>

int main() {
	Order *p[100];
	Menu *s[100];
	int count, menu;
        int index = 0;
        int num;
	int day;
	int nday;
	int ncount = 0;
	int acount = 0;
	printf("오늘 요일은? (월:0, 화:1, 수:2, 목:3, 금:4) ");
	scanf("%d", &day);

	ncount = loadMenu(s, day);
	acount = loadData(s);

	FILE *file;
	file = fopen("day.txt", "rt");
	fscanf(file, "%d", &nday);
	fclose(file);
	
	if (nday == day) {
		count = loadOrder(p, ncount);
		index = count;
	} else {
		count = 0;
		index = count;
	}
	/*
	FILE *file1;
	file = fopen("day.txt", "wt");
	fprintf(file1, "%d", nday);
	fclose(file1);
	*/
	while(1) {	
  		printf("\n*** 주문하기 ***\n");
  		printf("1. 조회 \n");
  		printf("2. 추가 \n");
  		printf("3. 수정 \n");
  		printf("4. 삭제 \n");
  		printf("5. 파일저장 \n");
		printf("6. 메뉴 추천 \n");
		printf("7. 요일 변경 \n");
  		printf("0. 종료\n");
		printf("선택 >> ");
  		scanf("%d", &menu);

		if (menu == 0) {
			if (menu == 0) {
			int off;
			printf("종료된 후 요일이 바뀌면 주문이 초기화됩니다.\n 정말 종료하겠습니까? (0:취소, 1:종료) ");
			scanf("%d", &off);
			if (off == 1 ) { 
                        	break;
			} else {
				continue;
			}
		}
		}               
		if (menu == 1) {
                        if(count > 0) {
                                listOrder(p, index, s, day);
                        } else {
                                printf("주문 내역이 없습니다.\n");
                        }
                } else if (menu == 2) {
			listMenu(s, acount, day);
                        p[index] = (Order *)malloc(sizeof(Order));
                        count += addOrder(p[index++], s, ncount, day);
                } else if (menu == 3) {
                        listOrder(p, index, s, day);
                        printf("주문 번호는 (취소: 0)? ");
                        scanf("%d", &num);
                        if (num == 0) {
                                printf("=>취소됨!\n");
                                continue;
                        } else {
				listMenu(s, acount, day);
                                updateOrder(p[num-1], s, ncount, day);
                        }
                } else if (menu == 4) {
                        listOrder(p, index, s, day);
                        printf("\n취소할 주문의 주문 번호는 (취소: 0)? ");
                        scanf("%d", &num);
                        if (num == 0) {
                                continue;
                        }
                        deleteOrder(p, num);
                } else if (menu == 5) {
                        saveOrder(p, count, ncount);
                } else if (menu == 6) {
			menuRecommend(s, day, ncount, count);
		} else if (menu == 7) {
			int change;
			printf("요일이 바뀌면 주문이 초기화됩니다.\n 정말 종료하겠습니까? (0:취소, 1:변경) ");
			scanf("%d", &change);
			if (change == 1) {
				changeDate(s, &day, &count, &index, &ncount);
			} else {
				continue;
			}
		}
	}
	printf("종료!\n");
	return 0;
}
