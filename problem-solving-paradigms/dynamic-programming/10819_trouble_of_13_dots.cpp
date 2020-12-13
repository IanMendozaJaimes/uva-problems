#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define MAX_SIZE 101

using namespace std;

int price[MAX_SIZE];
int favour[MAX_SIZE];
int dp[MAX_SIZE][10001][2];
int dpPrice[MAX_SIZE][10001][2];
int n;
int money;

int solve (int id, int remMoney, int r) {
    // printf("solve(%d, %d, %d)\n", id, remMoney, r);
    
    if (id == n) { return 0; }
    if (r == 1 && remMoney == 0) {
        dpPrice[id][remMoney][r] = 0;
        return 0; 
    }

    if (dp[id][remMoney][r] != -1) { return dp[id][remMoney][r]; }
    
    int nextId = id + 1;
    if (
        (r == 1 && remMoney < price[id]) || 
        (r == 0 && remMoney + 200 < price[id])
    ) {
        dp[id][remMoney][r] = solve(nextId, remMoney, r);
        dpPrice[id][remMoney][r] = dpPrice[nextId][remMoney][r];
        return dp[id][remMoney][r];
    }

    if (r == 1 || remMoney >= price[id]) {
        int rmoney = remMoney - price[id];
        int s1 = solve(nextId, remMoney, r);
        int s2 = favour[id] + solve(nextId, rmoney, r);

        if (s1 > s2) {
            dp[id][remMoney][r] = s1;
            dpPrice[id][remMoney][r] = dpPrice[nextId][remMoney][r];
        } else {
            dp[id][remMoney][r] = s2;
            dpPrice[id][remMoney][r] = dpPrice[nextId][rmoney][r] + price[id];
        }
        return dp[id][remMoney][r];
    }

    int rmoney = remMoney + 200 - price[id];
    int s1 = solve(nextId, remMoney, 0);
    int s2 = favour[id] + solve(nextId, rmoney, 1);
    int totalExpenses =  (money - remMoney) + price[id] + dpPrice[nextId][rmoney][1];

    // printf("\nmoney = %d, remMoney = %d, price[%d] = %d, dpPrice[%d][%d][%d] = %d\n", 
    //     money, remMoney, id, price[id], nextId, rmoney, 1, dpPrice[nextId][rmoney][1]);
    // printf("\nBifurcacion: s1 = %d, price1 = %d; s2 = %d, price2 = %d, totalExpenses = %d\n", 
    //     s1, dpPrice[nextId][remMoney][r], s2, dpPrice[nextId][rmoney][1] + price[id], totalExpenses);

    if (s2 > s1 && totalExpenses > 2000) {
        dp[id][remMoney][r] = s2;
        dpPrice[id][remMoney][r] = dpPrice[nextId][rmoney][1] + price[id];
    } else {
        dp[id][remMoney][r] = s1;
        dpPrice[id][remMoney][r] = dpPrice[nextId][remMoney][r];
    }

    return dp[id][remMoney][r];
}

int main () {
    while (scanf("%d %d", &money, &n) != EOF) {
        memset(dp, -1, sizeof(dp));
        memset(dpPrice, 0, sizeof(dpPrice));
        for (int i = 0; i < n; i++) {
            scanf("%d %d", price+i, favour+i);
            // printf("\nprice[i] = %d, favour[i] = %d\n", price[i], favour[i]);
        }
        printf("%d\n", solve(0, money, 0));
    }
    return 0;
}
