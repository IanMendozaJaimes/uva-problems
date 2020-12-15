#include <cstdio>
#include <utility>
#include <cstring>

#define MAX_K 101
#define MAX_P 220010

pair<int, double> dims[MAX_K];
double dp[MAX_K][MAX_P]; 
int counts[MAX_K][MAX_P]; 

int main () {
    int N, x, T, K, total_n, total_budget;
    int dim_value, dim_favour;
    double mean;
    while (scanf("%d %d %d %d", &N, &x, &T, &K), N != 0) {
        total_n = N + 1;
        total_budget = total_n * (x - T);
        
        for (int i = 0; i < K; i++) {
            scanf("%d", &dim_value);
            mean = 0.0;
            for (int j = 0; j < total_n; j++) {
                scanf("%d", &dim_favour);
                mean += dim_favour;
            }
            mean /= total_n;
            dims[i] = make_pair(dim_value, mean);
        }
        
        if (total_budget < 0) { printf("0.00\n"); continue; }

        for (int i = 0; i < MAX_P; i++) {
            dp[0][i] = 0.0; counts[0][i] = 0;
            if (can_take()) {

            }
        }

        for (int i = 1; i < K; i++) {
            for (int j = 0; j < MAX_P; j++) {

            }
        }
    }

    return 0;
}

