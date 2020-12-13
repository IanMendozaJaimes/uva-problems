#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main () {
	int num;
	int i = 0;
	int lis = 0;
	int end_lis = 0;

	vector<int> A;
	vector<int> L;
	vector<int> L_id;
	vector<int> P;
	stack<int> S;

	while (scanf("%d", &num) != EOF) {
		int pos = lower_bound(L.begin(), L.end(), num) - L.begin();
		A.push_back(num);
		
		if (pos + 1 > lis) {
			lis = pos + 1;
			L.push_back(num);
			L_id.push_back(i);
		} else {
			L[pos] = num;
			L_id[pos] = i;
		}

		end_lis = L_id[lis-1];
		P.push_back(pos ? L_id[pos-1] : -1);

		i++;
	}
	
	printf("%d\n-\n", lis);
	i = end_lis;
	for (; i >= 0; i = P[i]) S.push(A[i]);
	for (; !S.empty(); S.pop()) printf("%d\n", S.top());

	return 0;
}
