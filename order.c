#include <stdio.h>

int loadData(Menu *p[]) {

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

void listMenu(Menu *p[], int count) {
	printf("\n월\t화\t수\t목\t금\t토\t일\n");
        printf("=========================================\n");
	for(int i = 0; i < count ; i++) {
                if (p[i] == NULL) {
                        continue;
                }
                printf("%2d ", i+1);

                readItem(*p[i]);
        }
        printf("\n");
}

void readMenu(Menu p) {
	printf("%s, %d", p.name, p.price);
}

int updateMenu(Menu *p) {

}

void deleteMenu(Menu *p[], char fname[100]) {

}

void saveMenu(Menu *p[], int count) {

}

