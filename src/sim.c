#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sim.h"

void simulate(int num_customers, int num_tellers, float total_time, float base_service_time, int singleQueue) {
    Customer customers[num_customers];


    Teller tellers[num_tellers];

    for (int i = 0; i < num_tellers; i++)

        initTeller(&tellers[i], i);
    float current_time = 0.0;
    for (int i = 0; i < num_customers; i++) {
        if (i == 0)
            current_time = rand() % 3; 
        else
            current_time += rand() % 3 + 1; 

        initCustomer(&customers[i], i, current_time, base_service_time);
    }

    float total_service = 0, total_idle = 0;
    float total_time_in_bank = 0, max_wait = 0;
    float wait_times[num_customers];

    for (int i = 0; i < num_customers; i++) {
        Teller *teller = &tellers[i % num_tellers];

        if (teller->service_time < customers[i].arrival_time)
            addIdleTime(teller);

        float start_time = fmax(customers[i].arrival_time, teller->service_time);
        float completion = start_time + customers[i].service_time;
        customers[i].completion_time = completion;

        teller->service_time = completion;
        float wait = (completion - customers[i].arrival_time) - customers[i].service_time;
        if (wait < 0) wait = 0;

        wait_times[i] = wait;
        total_time_in_bank += (completion - customers[i].arrival_time);
        if (wait > max_wait) max_wait = wait;
    }

    for (int i = 0; i < num_tellers; i++) {
        total_service += tellers[i].service_time;
        total_idle += tellers[i].idle_time;
    }
    float avg_time_in_bank = total_time_in_bank / num_customers;
    float sum_dev = 0;
    for (int i = 0; i < num_customers; i++)
        sum_dev += pow((wait_times[i] - avg_time_in_bank), 2);
    float std_dev = sqrt(sum_dev / num_customers);
    printf("Total customers that were served: %d\n\n", num_customers);
    printf("Total simulation time: %.2f minutes\n\n", total_time);
    printf("Average time in bank: %.2f minutes\n\n", avg_time_in_bank);
    printf("Std deviation of time in bank: %.2f\n\n", std_dev);
    printf("Max wait time: %.2f minutes\n\n", max_wait);
    printf("Total teller service time: %.2f minutes\n\n", total_service);
    printf("Total teller idle time: %.2f minutes\n\n", total_idle);
}
