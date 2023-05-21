#include <stdio.h>
#include "menu.h"

int loadData(Order *p[]) {
	int count = 0, i = 0;
        FILE *file;

        file = fopen("menu.txt", "rt");
        for(i = 0; i < 100; i++) {
                if(feof(file)) {
                        break;
                }
                p[i]=(Order*)malloc(sizeof(Order));
                fgets(p[i]->name, 100, file);
                p[i]->name[strlen(s[i]->name) - 1] = '\0';
        }
        fclose(file);
        return i;
}

int addOrder(Order *p) {
	printf("주문자 이름?  ");
	getchar();
	fgets(p->name, 100, stdin);
	p->name[strlen(p->name) - 1] = '\0';
	printf("주문? ");
	scanf("%d", &p->count[0]);
	printf("요청사항은? ");
	getchar();
	fgets(p->add, 100, stdin);
	p->add[strlen(p->add) - 1] = '\0';
	return 1;
}

void listOrder(Order *p[], int count) {
	printf("이름\t주문\t요청 사항\n");
        printf("=========================================\n");
	for(int i = 0; i < count ; i++) {
                if (p[i] == NULL) {
                        continue;
                }
                printf("%2d ", i+1);

                readOrder(*p[i]);
        }
        printf("\n");
}

void readOrder(Order p) {
	printf("%s %d %d %s\n", s.name, s.count[0], s.prcie, s.add);
}

int updateOrder(Order *p) {
	printf("주문자 이름?  ");
        getchar();
        fgets(p->name, 100, stdin);
        p->name[strlen(p->name) - 1] = '\0';
        printf("주문? ");
        scanf("%d", &p->count[0]);
        printf("요청사항은? ");
        getchar();
        fgets(p->add, 100, stdin);
        p->add[strlen(p->add) - 1] = '\0';
        return 1;	
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

void saveOrder(Order *p[], int count) {
	FILE *file;
        file = fopen("menu.txt", "wt");
        for (int i = 0; i < count; i++) {
                if (p[i] == NULL) {
                         continue;
                }
        fprintf(file, "");
        if (i != count - 1)
                fprintf(file, "\n");
        }
        fclose(file);
        printf("=> 저장됨!\n");
}
