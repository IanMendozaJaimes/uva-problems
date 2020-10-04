#include <cstdio>
#include <algorithm>

int main () {
  int testCases;
  int N;
  int temp;
  int SIZE = 2 * 75 + 1;
  int m[SIZE][SIZE];
  int maxValue;
  scanf("%d", &testCases);
  while (testCases--) {
    scanf("%d", &N);
    maxValue = -999999999;
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
	scanf("%d", &temp);
	m[i][j] = temp;
	m[i+N][j] = temp;
	m[i][j+N] = temp;
	m[i+N][j+N] = temp;
      }
    }

    for (int i = 0; i < 2*N; i++) {
      for (int j = 0; j < 2*N; j++) {
	if (i > 0) m[i][j] += m[i-1][j];
	if (j > 0) m[i][j] += m[i][j-1];
	if (i > 0 && j > 0) m[i][j] -= m[i-1][j-1];
      }
    }

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
      for (int k = i; k < i+N; k++) for (int l = j; l < j+N; l++) {
      	temp = m[k][l];
	if (i > 0) temp -= m[i-1][l];
	if (j > 0) temp -= m[k][j-1];
	if (i > 0 && j > 0) temp += m[i-1][j-1];
	maxValue = std::max(temp, maxValue);
      }

    printf("%d\n", maxValue);
  }
  return 0;
}
