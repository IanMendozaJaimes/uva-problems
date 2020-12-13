#include <iostream>

#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <functional>

#define VISITED 1
#define UNVISITED 2

using namespace std;

map<string, int> beverages;
string id2beverage[101];
vector<int> node_visited(101, UNVISITED);
vector<int> node_incoming(101, 0);
priority_queue< int, vector<int>, greater<int> > top_sort;

char beverage[53];
char b1[53], b2[53];

int main () {

    int N, M, case_num = 0;

    while (scanf("%d", &N) != EOF) {

        vector< vector<int> > adjList(N);
        node_visited.assign(N, UNVISITED);
        node_incoming.assign(N, 0);
        beverages.clear();

        for (int i = 0; i < N; i++) {
            scanf("%s", beverage);
            beverages.insert(make_pair(string(beverage), i));
            id2beverage[i] = beverage;
        }

        scanf("%d", &M);

        for (int i = 0; i < M; i++) {
            scanf("%s %s", b1, b2);
            map<string, int>::iterator itr1 = beverages.find(string(b1));
            map<string, int>::iterator itr2 = beverages.find(string(b2));
            adjList[itr1 -> second].push_back(itr2 -> second);
            node_incoming[itr2 -> second] += 1;
        }

        printf("Case #%d: Dilbert should drink beverages in this order: ", ++case_num);

        for (int i = 0; i < N; i++) { if (node_incoming[i] == 0) { top_sort.push(i); } }

        while (!top_sort.empty()) {
            int u = top_sort.top(); top_sort.pop();
            printf("%s", (id2beverage[u]).c_str());
            for (int i = 0; i < adjList[u].size(); i++) {
                int v = adjList[u][i];
                node_incoming[v] -= 1;
                if (node_incoming[v] == 0) { top_sort.push(v); }
            }
            if (!top_sort.empty()) { printf(" "); }
        }
        printf(".\n\n");

    }

    return 0;
}
