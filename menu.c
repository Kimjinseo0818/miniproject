#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"

int loadOrder(Order *p[], int ncount) {
	int count = 0, i = 0;
        FILE *file;

        file = fopen("menu.txt", "rt");
        for(i = 0; i < 100; i++) {
                if(feof(file)) {
                        break;
                }
                p[i]=(Order*)malloc(sizeof(Order));
		fscanf(file, "%s", p[i]->name);
		fscanf(file, "%d", &p[i]->price);
		for (int j = 0; j < ncount; j++) {
			fscanf(file, "%d", &p[i]->count[j]);
		}
                fgets(p[i]->add, 100, file);
                p[i]->add[strlen(p[i]->add) - 1] = '\0';
        }
        fclose(file);
        return i;
}

int addOrder(Order *p, Menu *s[], int count, int day) {
	int j = 0;
	int k = 0;
	p->price = 0;
	printf("주문자 이름?  ");
	scanf("%s", p->name);
	printf("주문? (| ");
	for (int i = 0; i < count; i++) {
		if (s[i]->day == day) {
			printf("(%d) : %s | ", j + 1, s[i]->name);
			j++;
		}
	}
	printf(") ");	
	for (int i = 0; i < j; i++) {
		scanf("%d ", &p->count[i]);
	}
	printf("요청사항은? ");
	getchar();
	fgets(p->add, 100, stdin);
	p->add[strlen(p->add) - 1] = '\0';
	for (int i = 0; i < count; i++) {
		if (s[i]->day == day) {
			p->price += s[i]->price * p->count[k];
			k++;
		}
	}
	return 1;
}

void listOrder(Order *p[], int count) {
	printf("주문 번호 이름\t주문\t요청 사항\n");
        printf("=========================================\n");
	for(int i = 0; i < count ; i++) {
                if (p[i] == NULL) {
                        continue;
                }
                printf("%2d   ", i+1);

                readOrder(*p[i]);
        }
        printf("\n");
}

void readOrder(Order p) {
	printf("%s %d %d %s\n", p.name, p.count[0], p.price, p.add);
}

int updateOrder(Order *p, Menu *s[], int count, int day) {
	int j = 0;
	int k = 0;
	p->price = 0;
	printf("주문자 이름?  ");
	scanf("%s", p->name);
	printf("주문? (| ");
	for (int i = 0; i < count; i++) {
		if (s[i]->day == day) {
			printf("(%d) : %s | ", j + 1, s[i]->name);
			j++;
		}
	}
	printf(") ");	
	for (int i = 0; i < j; i++) {
		scanf("%d ", &p->count[i]);
	}
	printf("요청사항은? ");
	getchar();
	fgets(p->add, 100, stdin);
	p->add[strlen(p->add) - 1] = '\0';
	for (int i = 0; i < count; i++) {
		if (s[i]->day == day) {
			p->price += s[i]->price * p->count[k];
			k++;
		}
	}
        return 0;	
}

void deleteOrder(Order *p[], int num) {
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

void saveOrder(Order *p[], int count, int ncount) {
	FILE *file;
        file = fopen("menu.txt", "wt");
        for (int i = 0; i < count; i++) {
                if (p[i] == NULL) {
                         continue;
                }
		fprintf(file, "%s %d ", p[i]->name, p[i]->price);
                for (int j = 0; j < ncount; j++) {
                        fprintf(file, "%d ", p[i]->count[j]);
                }
                fprintf(file, "%s\n", p[i]->add);		
        	
		fprintf(file,"\n");
        }
        fclose(file);
        printf("=> 저장됨!\n");
}

