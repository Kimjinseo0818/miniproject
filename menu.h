#include <stdio.h>

typedef struct {
        char name[40];
        int price;
        int count[10];
        char add[100];
} Order;

int loadData(Order *p[]);

int addOrder(Order *p);

void listOrder(Order *p[], int count);

void readOrder(Order p);

int updateOrder(Order *p);

void deleteOrder(Order *p[], char fname[100]);

void saveOrder(Order *p[], int count);

