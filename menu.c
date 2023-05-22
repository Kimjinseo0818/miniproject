<<<<<<< HEAD
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

void listOrder(Order *p[], int count, Menu *s[]) {
	printf("번호 이름\t주문\t가격\t요청 사항\n");
        printf("=========================================\n");
	for(int i = 0; i < count ; i++) {
                if (p[i] == NULL) {
                        continue;
                }
                printf("%2d   ", i+1);

                readOrder(*p[i], s);
        }
        printf("\n");
}

void readOrder(Order p, Menu *s[]) {
	printf("%s %s:%d개 %d원 %s\n", p.name, s[0]->name , p.count[0], p.price, p.add);
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

=======
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readfile(char filename[100], Menu *p[]){
    int count = 0;
    FILE*file = fopen(filename, "r");
    while(!feof(file)){
        p[count] = (Menu *)malloc(sizeof(Menu));
        fscanf(file, "%d %d %s", &p[count]->day, &p[count]->price, p[count]->foodname);
        if(p[count]->foodname[strlen(p[count]->foodname) - 1] == '\n'){
        p[count]->foodname[strlen(p[count]->foodname) - 1] = '\0';
    }
        fgets(p[count]->restaurant, 100, file);
        if(p[count]->restaurant[strlen(p[count]->restaurant) - 1] == '\n'){
        p[count]->restaurant[strlen(p[count]->restaurant) - 1] = '\0';
    }
        count++;
    
    }
    return count;
    }



void printRestaurantMenu(char input[100], Menu *p[], int count) {
    printf("이번주 %s의 메뉴는\n", input);
    for (int i = 0; i < count; i++) {
        if (strstr(p[i]->restaurant, input) != NULL) {
            if(p[i]->price > 0){
                printf("%s %d %d\n", p[i]->foodname, p[i]->day, p[i]->price);
            }
        }
    }
}


void printDayMenu(int day, Menu *p[], int count){
    if(day == 0){
        printf("일요일 메뉴는\n");
    }
    else if(day == 1){
        printf("월요일 메뉴는\n");
    }
    else if(day == 2){
        printf("화요일 메뉴는\n");
    }
    else if(day == 3){
        printf("수요일 메뉴는\n");
    }
    else if(day == 4){
        printf("목요일 메뉴는\n");
    }
    else if(day == 5){
        printf("금요일 메뉴는\n");
    }
    else if(day == 6){
        printf("토요일 메뉴는\n");
    }

    for(int i = 0; i < count; i++){
        if(day == p[i]->day){
            if(p[i]->price > 0){
                printf("%s  %s  \n", p[i]->restaurant, p[i]->foodname);
            }
        }
    }
}


void deleteMenu(Menu *p){
    int r = 0;
    printf("정말로 삭제하시겠습니까?(삭제 :1)");
    scanf("%d", &r);
    if(r == 1){
        p->price = -1;
        printf("=> 삭제됨!\n");
    }
}


void add(Menu *p){
    printf("음식점 이름은?");
    getchar();
    fgets(p->restaurant, 100, stdin);
    if(p->restaurant[strlen(p->restaurant) - 1] == '\n'){
        p->restaurant[strlen(p->restaurant) - 1] = '\0';
    }
    printf("메뉴 이름은?");
    fgets(p->foodname, 100, stdin);
    if(p->foodname[strlen(p->foodname) - 1] == '\n'){
        p->foodname[strlen(p->foodname) - 1] = '\0';
    }
    printf("요일은?");
    scanf("%d", &p->day);

    printf("가격은?");
    scanf("%d", &p->price);

    printf("=> 추가되었습니다");
}

int selectMenu(){
    int input;
    printf("1 음식점별 메뉴 출력\n");
    printf("2 요일별 메뉴 출력\n");
    printf("3 메뉴 삭제\n");
    printf("4 메뉴 추가\n");
    printf("0 종료\n");
    scanf("%d", &input);
    return input;
}
>>>>>>> 2fb41dd (commit)
