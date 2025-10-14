#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct {
    int id;
    float arrival_time;
    float service_time;
    float completion_time;
} Customer;

void initCustomer(Customer *cust, int id, float arrival_time, float base_service_time);

#endif
