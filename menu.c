#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"

int loadOrder(Order *p[], int ncount) {
	int count = 0, i = 0;
        FILE *file5;

        file5 = fopen("menu.txt", "rt");
        for(i = 0; i < 100; i++) {
                if(feof(file5)) {
                        break;
                }
                p[i]=(Order*)malloc(sizeof(Order));
		fscanf(file5, "%s", p[i]->name);
		fscanf(file5, "%d", &p[i]->price);
		for (int j = 0; j < ncount; j++) {
			fscanf(file5, "%d", &p[i]->count[j]);
		}
                fgets(p[i]->add, 100, file5);
                p[i]->add[strlen(p[i]->add) - 1] = '\0';
        	
	}
	i--;
        fclose(file5);
        return i;
}

int addOrder(Order *p, Menu *s[], int count, int day) {
	int j = 0;
	int k = 0;
	p->price = 0;
	printf("주문자 이름?  ");
	scanf("%s", p->name);
	printf("주문? \n");
	for (int i = 0; i < count; i++) {
		if (s[i]->day == day) {
			printf("(%d) : %s | ", i + 1, s[i]->name);
			//scanf("%d", &p->count[i]);
		}
	}
	printf("요청사항은? ");
	getchar();
	fgets(p->add, 100, stdin);
	p->add[strlen(p->add) - 1] = '\0';
	for (int i = 0; i < count; i++) {
		if (s[i]->day == day) {
			p->price += s[i]->price * p->count[i];
		}
	}
	return 1;
}

void listOrder(Order *p[], int count, Menu *s[], int day) {
	printf("번호 이름\t주문\t가격\t요청 사항\n");
        printf("=========================================\n");
	for(int i = 0; i < count ; i++) {
                if (p[i] == NULL) {
                        continue;
                }
                printf("%2d   ", i+1);

                readOrder(*p[i], day, s, count);
        }
        printf("\n");
}

void readOrder(Order p, int day, Menu *s[], int count) {
	int j = 0;
	printf("%s", p.name);
	for(int i = 0; i < count; i++) {
		if (s[i]->day == day) {
			if (p.count[j] != 0) {
				printf("%s:%d개", s[i]->name, p.count[j]);
			}
			j++;
		}
	}
        printf("%d원 %s\n", p.price, p.add);
}

int updateOrder(Order *p, Menu *s[], int count, int day) {
	int j = 0;
	int k = 0;
	p->price = 0;
	printf("주문자 이름?  ");
	scanf("%s", p->name);
	printf("주문? \n");
	for (int i = 0; i < count; i++) {
		if (s[i]->day == day) {
                        printf("(%d) : %s | ", i + 1, s[i]->name);
                        scanf("%d", &p->count[i]);
                }
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
