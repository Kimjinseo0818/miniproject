#include <stdio.h>

typedef struct {
    char name[100];
    int price;
    int day;
} Menu;

int loadData(Menu *p[]);

int loadMenu(Menu *p[], int day);

int addMenu(Menu *p);

void listMenu(Menu *p[], int count, int day);

void readMenu(Menu p);

int updateMenu(Menu *p);

void deleteMenu(Menu *p[], int num);

void saveMenu(Menu *p[], int count);

void menuRecommend(Menu *p[], int day, int ncount, int count);

void changeDate(Menu *p[], int *day, int *count, int *index, int *ncount);
