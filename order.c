#include "order.h"
#include <stdio.h>

int loadData(Menu *p[]) {
	int count = 0, i = 0;
        FILE *file;

        file = fopen("order.txt", "rt");
        for(i = 0; i < 100; i++) {
                if(feof(file)) {
                        break;
                }
                p[i]=(Menu*)malloc(sizeof(Menu));
		fscanf(file,"%d", &p[i]->day);
		fscanf(file,"%d", &p[i]->price);
                fgets(p[i]->name, 100, file);
                p[i]->name[strlen(s[i]->name) - 1] = '\0';
        }
        fclose(file);
        return i;
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
	char nday[5][5] = {"월","화","수","목","금"} 
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
	printf("-%s %5d원\n", s.name, s.price);
}

int updateMenu(Menu *p) {
	printf("음식 이름은? ");
        getchar();
        fgets(s->name, 100, stdin);
        s->name[strlen(s->name) - 1] = '\0';
        printf("가격은? ");
        scanf("%d", &s->price);
        printf("요일은? (월:0, 화:1, 수:2, 목:3, 금:4)");
        scanf("%s", s->day);
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
        if (i != count - 1)
                fprintf(file, "\n");
        }
        fclose(file);
        printf("=> 저장됨!\n");
}

