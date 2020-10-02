#include <cstdio>
#include <algorithm>

int main () {
	int N;
	int current;
	while(scanf("%d", &N), N > 0){
		int maxSum = 0;
		int currentSum = 0;
		while(N--){
		    scanf("%d", &current);
		    currentSum += current;
		    if (currentSum < 0) { currentSum = 0; }
		    maxSum = std::max(currentSum, maxSum);
		}
		if(maxSum > 0){
			printf("The maximum winning streak is %d.\n", maxSum);
		} else {
			printf("Losing streak.\n");
		}
	}
	return 0;
}
