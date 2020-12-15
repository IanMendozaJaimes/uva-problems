#include<cstdio>
#include<cstring>

#define MAX_N 101
#define MAX_M 101

#define NORTH 'N'
#define SOUTH 'S'
#define EAST 'L'
#define WEST 'O'

#define NORMAL '.'
#define STICKER '*'
#define PILLAR '#'

typedef struct robot_info {
  int row;
  int column;
  char orientation;
  int move_row;
  int move_column;
} roboInfo;

void change_orientation (roboInfo * info, char orientation) {
  info -> orientation = orientation;
  if (orientation == NORTH) {
    info -> move_row = -1;
    info -> move_column = 0;
  } else if (orientation == SOUTH) {
    info -> move_row = 1;
    info -> move_column = 0;
  } else if (orientation == EAST) {
    info -> move_row = 0;
    info -> move_column = 1;
  } else if (orientation == WEST) {
    info -> move_row = 0;
    info -> move_column = -1;
  }
}

void move_forward(roboInfo * info, char (&grid)[MAX_N][MAX_M], int & N, int & M) {
  int new_row = info -> row + info -> move_row;
  int new_column = info -> column + info -> move_column;

  if (new_row < 0 || new_row == N) { return; }
  if (new_column < 0 || new_column == M) { return; }
  if (grid[new_row][new_column] == PILLAR) { return; }

  info -> row = new_row;
  info -> column = new_column;
}

void turn_left (roboInfo * info) {
  char orientation = info -> orientation;

  if (orientation == NORTH) {
    change_orientation(info, WEST);
  } else if (orientation == SOUTH) {
    change_orientation(info, EAST);
  } else if (orientation == EAST) {
    change_orientation(info, NORTH);
  } else {
    change_orientation(info, SOUTH);
  }

}

void turn_right (roboInfo * info) {
  char orientation = info -> orientation;

  if (orientation == NORTH) {
    change_orientation(info, EAST);
  } else if (orientation == SOUTH) {
    change_orientation(info, WEST);
  } else if (orientation == EAST) {
    change_orientation(info, SOUTH);
  } else {
    change_orientation(info, NORTH);
  }
}

int main () {

  int N, M, S;
  int stickerCount;
  char c;
  char grid[MAX_N][MAX_M];

  while (true) {
    scanf("%d %d %d", &N, &M, &S);
    if (N == 0) { return 0; }

    roboInfo info;
    stickerCount = 0;
    memset(grid, 0, sizeof(grid));

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {

        scanf("%c", &c);
        if (c == '\n') {
          scanf("%c", &c);
        }

        grid[i][j] = c;

        if (c == NORTH || c == SOUTH || c == EAST || c == WEST) {
          info.row = i;
          info.column = j;
          change_orientation(&info, c);
        }

      }
    }

    for (int i = 0; i < S; i++) {
      scanf("%c", &c);
      if (c == '\n') {
        scanf("%c", &c);
      }

      if (c == 'D') {
        turn_right(&info);
      } else if (c == 'E') {
        turn_left(&info);
      } else {
        move_forward(&info, grid, N, M);
      }
      if (grid[info.row][info.column] == STICKER) {
        stickerCount++;
        grid[info.row][info.column] = NORMAL;
      }
    }

    printf("%d\n", stickerCount);

  }

  return 0;
}
