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
