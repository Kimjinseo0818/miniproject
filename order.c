#include <time.h>
#include "order.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int loadData(Menu *p[]) {
	int count = 0, i = 0;
        FILE *file2;
        
	file2 = fopen("order.txt", "rt");
        for(i = 0; i < 100; i++) {
                if(feof(file2)) {
                        break;
                }
                
		p[i]=(Menu*)malloc(sizeof(Menu));
		fscanf(file2,"%d", &p[i]->day);
		fscanf(file2,"%d", &p[i]->price);
                fgets(p[i]->name, 100, file2);
                p[i]->name[strlen(p[i]->name) - 1] = '\0';
        }
	i--;
        fclose(file2);
        return i;
}

int loadMenu(Menu *p[], int day) {
        int count = 0, i;
        FILE *file3;

        file3 = fopen("order.txt", "rt");
        for(i = 0; i < 100; i++) {
                if(feof(file3)) {
                        break;
                }
		p[i]=(Menu*)malloc(sizeof(Menu));
                fscanf(file3,"%d", &p[i]->day);
                fscanf(file3,"%d", &p[i]->price);
                fgets(p[i]->name, 100, file3);
                p[i]->name[strlen(p[i]->name) - 1] = '\0';
		
		if(p[i]->day == day) {
			count++;
		}
        }
        fclose(file3);
	count--;
        return count;
}

int addMenu(Menu *p) {
	printf("음식 이름은? ");
	getchar();
	fgets(p->name, 100, stdin);
	p->name[strlen(p->name) - 1] = '\0';
	printf("가격은? ");
	scanf("%d", &p->price);
	printf("요일은?(월:0, 화:1, 수:2, 목:3, 금:4)");
	scanf("%d", &p->day);
	return 1;
}

void listMenu(Menu *p[], int count, int day) {
	char nday[5][5] = {"월","화","수","목","금"}; 
	printf("\n%s요일 식단\n", nday[day]);
        printf("=========================================\n");
	for(int i = 0; i < count ; i++) {
                if (p[i] == NULL) {
                        continue;
                }
		if (p[i]->day == day) {
                	readMenu(*p[i]);
		}
        }
        printf("\n");
}

void readMenu(Menu p) {
	printf("-%s %5d원\n", p.name, p.price);
}

int updateMenu(Menu *p) {
	printf("음식 이름은? ");
        getchar();
        fgets(p->name, 100, stdin);
        p->name[strlen(p->name) - 1] = '\0';
        printf("가격은? ");
        scanf("%d", &p->price);
        printf("요일은? (월:0, 화:1, 수:2, 목:3, 금:4)");
        scanf("%d", &p->day);
        return 1;
}

void deleteMenu(Menu *p[], int num) {
	int check;
        printf("정말로 삭제하시겠습니까? (삭제: 1) ");
        scanf("%d", &check);
        if(check == 1) {
                free(p[num-1]);
                p[num-1] = NULL;
                printf("삭제되었습니다.\n");
        } else {
                printf("삭제가 취소되었습니다.\n");
        }
}

void saveMenu(Menu *p[], int count) {
	FILE *file;
        file = fopen("order.txt", "wt");
        for (int i = 0; i < count; i++) {
                if (p[i] == NULL) {
                         continue;
                }
        fprintf(file, "%d %d %s", p[i]->day, p[i]->price, p[i]->name);
        
        fprintf(file, "\n");
        fclose(file);
        printf("=> 저장됨!\n");
	}
}

void menuRecommend(Menu *p[], int day, int ncount) {
	int index, i;
	FILE *file4;

        file4 = fopen("order.txt", "rt");
        for(i = 0; i < 100; i++) {
                if(feof(file4)) {
                        break;
                }
		p[i]=(Menu*)malloc(sizeof(Menu));
		printf("1");
                fscanf(file4,"%d", &p[i]->day);
                fscanf(file4,"%d", &p[i]->price);
                fgets(p[i]->name, 100, file4);
                p[i]->name[strlen(p[i]->name) - 1] = '\0';
		
		if(p[i]->day == day) {
			index = i;
		}
        }
        fclose(file4);

	srand(time(0));
	printf("%d",index);
	int random = rand() % ncount + (index - ncount);

	printf("\n%d", random);

	char randomFood[100];
	strcpy(randomFood,p[random]->name);
	int randomPrice = p[random]->price;
	printf("\n-- 오늘의 추천 메뉴 --\n");
	printf("======================\n");
	printf("%s : %d원\n", randomFood, randomPrice);
}

void changeDate(Menu *p[], int day, int count, int index, int ncount) {
	printf("변경 요일은? (월:0, 화:1, 수:2, 목:3, 금:4) ");
	scanf("%d", &day);
	count = 0;
	index = 0;
	ncount = loadMenu(p, day);
}

