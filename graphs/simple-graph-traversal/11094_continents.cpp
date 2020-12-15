#include <cstdio>
#include <algorithm>

#define VISITED '0'

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0, -1 };
int M, N;
char land;

int floodfill (int r, int c, char map[21][21], char color1, char color2) {

  if (r == M || r < 0) { return 0; }
  if (c == N) { c = 0; }
  if (c < 0) { c = N - 1; }

  if (map[r][c] != color1) { return 0; }
  
  map[r][c] = color2;

  int ans = 1;

  for (int i = 0; i < 4; i++) {
    ans += floodfill(r + dr[i], c + dc[i], map, color1, color2);
  }

  return ans;

}

int main () {

  int r, c, ans;
  char map[21][21];

  while (scanf("%d %d", &M, &N) != EOF) {

    ans = 0;

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%c", &map[i][j]); 
        if (map[i][j] == '\n') { scanf("%c", &map[i][j]); }
      }
    }

    scanf("%d %d", &r, &c);

    land = map[r][c];
    floodfill(r, c, map, land, VISITED);

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (map[i][j] == land) {
          ans = std::max(ans, floodfill(i, j, map, land, VISITED));
        }
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}

