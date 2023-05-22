#include <stdio.h>
<<<<<<< HEAD
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
	
	printf("\n%d", acount);

	printf("\n%d", ncount);

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
	printf("\n%d", count);
	/*
	FILE *file1;
	file = fopen("day.txt", "wt");
	fprintf(file1, "%d", nday);
	fclose(file1);
	*/
	while(1) {	
  		printf("\n*** 재고 확인 ***\n");
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
                                listOrder(p, index, s);
                        } else {
                                printf("주문 내역이 없습니다.\n");
                        }
                } else if (menu == 2) {
			listMenu(s, acount, day);
                        p[index] = (Order *)malloc(sizeof(Order));
                        count += addOrder(p[index++], s, ncount, day);
                } else if (menu == 3) {
                        listOrder(p, index, s);
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
                        listOrder(p, index, s);
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
=======
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int main(void) {
    Menu *p[100];
    int count = 0, menu;
    count = readfile("menu.txt", p) - 1;
    if (count == -1) {
        count += 1;
    }
    while (1) {
        menu = selectMenu();
        if (menu == 0) {
            break;
        }
        if (menu == 1) {
            char input[100];
            printf("원하는 음식점 이름은?");
            getchar();
            fgets(input, 100, stdin);
            if (input[strlen(input) - 1] == '\n') {
                input[strlen(input) - 1] = '\0';
            }
            printRestaurantMenu(input, p, count);


        } else if (menu == 2) {
            int input;
            printf("원하는 요일은?(일요일 0, 월요일 1, 화요일 2, 수요일 3, 목요일 4, 금요일 5, 토요일 6)");
            scanf("%d", &input);
            printDayMenu(input, p, count);
        } else if (menu == 3) {
            int num = 0;
            printf("No. 요일    음식점  가격    메뉴명\n");
            for (int i = 0; i < count; i++) {
                if(p[i]->price > 0){
                    printf("%d %d  %s  %d  %s\n", i + 1, p[i]->day, p[i]->restaurant, p[i]->price, p[i]->foodname);
                }

            }
            printf("\n번호는 (취소 :0)? ");
            scanf("%d", &num);
            if (num != 0) {
                deleteMenu(p[num - 1]);
            }
        } else if (menu == 4) {
            p[count] = (Menu *)malloc(sizeof(Menu));
            add(p[count]);
            count++;
        }
    }
    printf("종료됨!\n");
    return 0;
>>>>>>> 2fb41dd (commit)
}
