#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef queue<pii> qpii;

typedef pair<int, char> pic;
typedef queue<pic> qpic;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vvi board_map(n, vi(n, 0));
  for (int i = 0; i < k; i++)
  {
    int x, y;
    cin >> x >> y;
    board_map[x - 1][y - 1] = 2;
  }

  int l;
  cin >> l;
  qpic changeDir;

  for (int i = 0; i < l; i++)
  {
    int x;
    char c;
    cin >> x >> c;
    changeDir.push(make_pair(x, c));
  }

  int mx[4] = {0, 1, 0, -1};
  int my[4] = {1, 0, -1, 0};

  qpii snake;
  snake.push(make_pair(0, 0));
  pii head = make_pair(0, 0);
  board_map[0][0] = 1;
  int time = 0;
  int dir = 0;
  while (true)
  {
    head.first += mx[dir];
    head.second += my[dir];
    int *nextX = &(head.first);
    int *nextY = &(head.second);
    if (*nextX < 0 || *nextX >= n || *nextY < 0 || *nextY >= n || board_map[*nextX][*nextY] == 1)
    {
      break;
    }
    if (board_map[*nextX][*nextY] == 0)
    {
      int tailX = snake.front().first;
      int tailY = snake.front().second;
      board_map[tailX][tailY] = 0;
      snake.pop();
    }
    board_map[*nextX][*nextY] = 1;
    snake.push(make_pair(*nextX, *nextY));
    time++;
    if (time == changeDir.front().first)
    {
      if (changeDir.front().second == 'L')
      {
        dir--;
      }
      else
      {
        dir++;
      }
      changeDir.pop();
      dir = (4 + dir) % 4;
    }
  }
  cout << time + 1;
  return 0;
}