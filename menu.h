<<<<<<< HEAD
#include <stdio.h>
#include "order.h"

typedef struct {
        char name[40];
        int price;
        int count[10];
        char add[100];
} Order;

int loadOrder(Order *p[], int count);

int addOrder(Order *p, Menu *s[], int count, int day );

void listOrder(Order *p[], int count, Menu *s[]);

void readOrder(Order p, Menu *s[]);

int updateOrder(Order *p, Menu *s[], int count, int day);

void deleteOrder(Order *p[], int num);

void saveOrder(Order *p[], int count, int ncount);

=======
#ifndef MENU_H
#define MENU_H

typedef struct {
    char foodname[100];
    int day; // 일요일 0, 월요일 1, 화요일 2, 수요일 3, 목요일 4, 금요일 5, 토요일 6
    char restaurant[100];
    int price;
} Menu;

int readfile(char filename[100], Menu *p[]); // 파일 읽기

void printRestaurantMenu(char input[100], Menu *p[], int count); // 음식점별 메뉴 출력

void printDayMenu(int day, Menu *p[], int count); // 요일별 메뉴 출력

void deleteMenu(Menu *p); // 메뉴 삭제

void add(Menu *p); // 메뉴 추가

int selectMenu();

#endif
>>>>>>> 2fb41dd (commit)
