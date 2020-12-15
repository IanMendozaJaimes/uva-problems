#include <cstdio>
#include <algorithm>

#define MAX_N 2001

int L[MAX_N];

int lower_bound_reverse (int * array, int size, int element) {
    int first_pos = 0;
    int last_pos = size - 1;
    int end_pos = -1;
    while (first_pos <= last_pos) {
        int middle = first_pos + (last_pos - first_pos) / 2;
        if (array[middle] > element) {
            end_pos = middle;
            first_pos = middle + 1;
        } else {
            last_pos = middle - 1;
        }
    }
    return end_pos;
}

int lis_conditioned (int * A, int size, int first_pos) {
    int lis_size = 0;
    int first_element = A[first_pos];
    for (int i = first_pos + 1; i < size; i++) {
        if (A[i] <= first_element) { continue; }
        int pos = std::lower_bound(L, L+lis_size, A[i]) - L;
        L[pos] = A[i];
        if (pos + 1 > lis_size) {
            lis_size += 1;
        }
    }
    return lis_size + 1;
}

int lds_conditioned (int * A, int size, int first_pos) {
    int lds_size = 0;
    int first_element = A[first_pos];
    for (int i = first_pos + 1; i < size; i++) {
        if (A[i] >= first_element) { continue; }
        int pos = lower_bound_reverse(L, lds_size, A[i]) + 1;
        L[pos] = A[i];
        if (pos + 1 > lds_size) {
            lds_size += 1;
        }
    }
    return lds_size + 1;
}

int main () {
    int A[MAX_N];
    int testCases, n;
    scanf("%d", &testCases);
    while (testCases--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", A + i);
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            answer = std::max(answer, lis_conditioned(A, n, i) + lds_conditioned(A, n, i) - 1);
        }
        printf("%d\n", answer);
    }
    return 0;
}
