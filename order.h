#include <stdio.h>
#include <string>

typedef struct {
    char[100] name;
    int price;
    int day;
} Menu;

int loadData(Menu *p[]);

int addMenu(Menu *p);

void listMenu(Menu *p[], int count);

void readMenu(Menu p);

int updateMenu(Menu *p);

void deleteMenu(Menu *p[], char fname[100]);

void saveMenu(Menu *p[], int count);
