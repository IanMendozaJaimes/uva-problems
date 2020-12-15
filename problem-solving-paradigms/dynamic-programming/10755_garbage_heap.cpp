#include <cstdio>
#include <algorithm>

int main () {
	int testCases;
	long m[21][21][21];
	long maxValue; //-(2^31 * 20^3 + 1)
	long temp;
	int a, b, c;
	long tempValue;
	scanf("%d", &testCases);
	while (testCases--) {
		maxValue = -17179869184001;
		scanf("%d %d %d", &a, &b, &c);
		
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				for (int k = 0; k < c; k++) {
					scanf("%ld", &tempValue);
					m[i][j][k] = tempValue;
					if (i > 0) m[i][j][k] += m[i-1][j][k];
					if (j > 0) m[i][j][k] += m[i][j-1][k];
					if (i > 0 && j > 0) m[i][j][k] -= m[i-1][j-1][k];
				}
			}
		}

		for (int i = 0; i < a; i++) for (int j = 0; j < b; j++)
		for (int w = i; w < a; w++) for (int q = j; q < b; q++) {
			long currentSum = 0;
			for (int k = 0; k < c; k++) {
				temp = m[w][q][k];
				if (i > 0) temp -= m[i-1][q][k];
				if (j > 0) temp -= m[w][j-1][k];
				if (i > 0 && j > 0) temp += m[i-1][j-1][k];
				currentSum += temp;
				maxValue = std::max(currentSum, maxValue);
				if (currentSum < 0) currentSum = 0;
			}
		}
		printf("%ld\n", maxValue);
		if (testCases) printf("\n");
	}
	return 0;
}
