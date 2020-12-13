#include <cstdio>
#include <cstring>

#define N 5

int coins[N] = { 1, 5, 10, 25, 50 };
long dp[N][30001];

long solve (int type, int value) {
    if (type == N) { return 0; }
    if (value < 0) { return 0; }
    if (value == 0) { return 1; }
    if (dp[type][value] != -1) { return dp[type][value]; }
    return dp[type][value] = solve(type + 1, value) + solve(type, value - coins[type]);
}

int main () {
    int amount;
    memset(dp, -1, sizeof(dp));
    while (scanf("%d", &amount) != EOF) {
        long s = solve(0, amount);
        if (s == 1) {
            printf("There is only 1 way to produce %d cents change.\n", amount);
        } else {
            printf("There are %ld ways to produce %d cents change.\n", s, amount);
        }
    }
    return 0;
}
