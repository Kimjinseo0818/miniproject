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

void listOrder(Order *p[], int count, Menu *s[], int day);

void readOrder(Order p, int day, Menu *s[], int count);

int updateOrder(Order *p, Menu *s[], int count, int day);

void deleteOrder(Order *p[], int num);

void saveOrder(Order *p[], int count, int ncount);
