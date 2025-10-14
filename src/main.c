#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sim.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <num_customers> <num_tellers> <simulation_time> <avg_service_time>\n", argv[0]);
        return 1;
    }

    int num_customers = atoi(argv[1]);
    int num_tellers = atoi(argv[2]);
    float sim_time = atof(argv[3]);
    float base_service = atof(argv[4]);

    // 🔸 Seed random number generator
    srand(time(NULL));

    printf("=== Simulation with %d tellers, SINGLE common queue ===\n", num_tellers);
    simulate(num_customers, num_tellers, sim_time, base_service, 1);

    printf("\n=== Simulation with %d tellers, SEPARATE queues ===\n", num_tellers);
    simulate(num_customers, num_tellers, sim_time, base_service, 0);

    return 0;
}
