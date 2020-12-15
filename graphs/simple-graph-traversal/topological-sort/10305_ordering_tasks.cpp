#include <cstdio>
#include <cstring>
#include <vector>

#define UNVISITED 0
#define VISITED 1

using namespace std;

vector<int> top_sorted;
int dfs_num[101];


void topsort (int u, vector< vector<int> > & graph) {
  dfs_num[u] = VISITED;
  for (int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (dfs_num[v] == UNVISITED) {
      topsort(v, graph);
    }
  }
  top_sorted.push_back(u);
}


int main () {
  int n, m;
  int u, v;

  while (scanf("%d %d", &n, &m) && n != 0) {

    top_sorted.clear();
    memset(dfs_num, UNVISITED, sizeof dfs_num);

    vector< vector<int> > graph(n + 1);

    for (int i = 0; i < m; i++) {
      scanf("%d %d", &u, &v);
      graph[u].push_back(v);
    }

    for (int u = 1; u < graph.size(); u++) {
      if (dfs_num[u] == UNVISITED) {
        topsort(u, graph);
      }
    }

    for (int i = top_sorted.size() - 1; i >= 0; i--) {
      printf("%d", top_sorted[i]);
      if (i > 0) { printf(" "); }
      else { printf("\n"); }
    }

  }

  return 0;
}
