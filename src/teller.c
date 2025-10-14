#include "teller.h"
#include <stdlib.h>

void initTeller(Teller *teller, int id) {
    teller->id = id;
    teller->busy = 0;
    teller->service_time = 0.0;
    teller->idle_time = 0.0;
}

void serveCustomer(Teller *teller, Customer *cust, float base_service_time) {
    // 🔸 Randomize service time around base (±50%)
    float service_time = base_service_time + ((rand() % 100) / 100.0 - 0.5) * base_service_time;
    if (service_time < 0.1) service_time = 0.1;

    teller->busy = 1;
    teller->service_time += service_time;
    teller->busy = 0;
}

void addIdleTime(Teller *teller) {
    // 🔸 Random idle time 0–150 minutes
    teller->idle_time += rand() % 151;
}
