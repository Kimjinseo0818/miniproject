#include <stdio.h>
#include "menu.h"
#include <stdlib.h>

int main() {
	Order *p[100];
	Menu *s[50];
	int count, menu;
        int index = 0;
        int num;
	int day;
	int nday;
	int ncount;
	int acount;
	printf("오늘 요일은? (월:0, 화:1, 수:2, 목:3, 금:4) ");
	scanf("%d", &day);
	acount = loadData(s);
	
	printf("1");
	
	ncount = loadMenu(s, day);
	
	printf("1");

	FILE *file;
	file = fopen("day.txt", "rt");
	fscanf(file, "%d", &nday);
	fclose(file);
	
	printf("1");

	if (nday == day) {
		count = loadOrder(p, ncount);
		index = count;
	} else {
		count = 0;
		index = count;
	}
	FILE *file1;
	file = fopen("day.txt", "wt");
	fprintf(file1, "%d", nday);
	fclose(file1);
	while(1) {	
  		printf("\n*** 재고 확인 ***\n");
  		printf("1. 조회 ");
  		printf("2. 추가 ");
  		printf("3. 수정 ");
  		printf("4. 삭제 ");
  		printf("5. 파일저장 ");
  		printf("0. 종료 >> ");
  		scanf("%d", &menu);

		if (menu == 0)
                        break;
                if (menu == 1) {
                        if(count > 0) {
                                listOrder(p, index);
                        } else {
                                printf("주문 내역이 없습니다.\n");
                        }
                } else if (menu == 2) {
			listMenu(s, acount, day);
                        p[index] = (Order *)malloc(sizeof(Order));
                        count += addOrder(p[index++], s, ncount, day);
                } else if (menu == 3) {
                        listOrder(p, index);
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
                        listOrder(p, index);
                        printf("\n취소할 주문의 주문 번호는 (취소: 0)? ");
                        scanf("%d", &num);
                        if (num == 0) {
                                continue;
                        }
                        deleteOrder(p, num);
                } else if (menu == 5) {
                        saveOrder(p, count, ncount);
                }
	}
	printf("종료!\n");
	return 0;
}
