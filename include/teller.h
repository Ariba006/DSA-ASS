#ifndef TELLER_H
#define TELLER_H
#include "customer.h"

typedef struct {
    int id;
    int busy;
    float service_time;
    float idle_time;
} Teller;

void initTeller(Teller *teller, int id);
void serveCustomer(Teller *teller, Customer *cust, float base_service_time);
void addIdleTime(Teller *teller);

#endif
