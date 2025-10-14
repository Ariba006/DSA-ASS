#include "customer.h"
#include <stdlib.h>

void initCustomer(Customer *cust, int id, float arrival_time, float base_service_time) {
    cust->id = id;
    cust->arrival_time = arrival_time;

    // 🔸 Randomized service time (±50% variation)
    float service_time = base_service_time + ((rand() % 100) / 100.0 - 0.5) * base_service_time;
    if (service_time < 0.1) service_time = 0.1;

    cust->service_time = service_time;
    cust->completion_time = 0.0;
}
