// 보다 간결한 방식 https://www.acmicpc.net/source/23128406
// 구슬의 선후 관계를 파악하는 방식을 좀더 효율적이게 계산하여 좀더 짧고 보기 좋게 만든 사례

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

typedef pair<int, int> pii;

int n, m;

int mx[4] = {-1, 1, 0, 0};
int my[4] = {0, 0, -1, 1};

int ans = 999999999;

pii rollBall(pii ball, vvc &map, int vecX, int vecY, char type)
{
  map[ball.first][ball.second] = '.';
  while (true)
  {
    int x = ball.first + vecX;
    int y = ball.second + vecY;
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
      break;
    }
    if (map[x][y] == 'O')
    {
      return make_pair(-1, -1);
    }
    if (map[x][y] != '.')
    {
      break;
    }
    ball.first = x;
    ball.second = y;
  }
  map[ball.first][ball.second] = type;
  return ball;
}

bool isBFirst(int i, pii blueBall, pii redBall)
{
  int curBX = blueBall.first;
  int curBY = blueBall.second;
  int curRX = redBall.first;
  int curRY = redBall.second;

  switch (i)
  {
  case 0:
    if (curBX < curRX)
    {
      return true;
    }
    else
    {
      return false;
    }
    break;
  case 1:
    if (curBX > curRX)
    {
      return true;
    }
    else
    {
      return false;
    }
    break;
  case 2:
    if (curBY < curRY)
    {
      return true;
    }
    else
    {
      return false;
    }
    break;
  case 3:
    if (curBY > curRY)
    {
      return true;
    }
    else
    {
      return false;
    }
    break;
  default:
    return false;
  }
}

void moveBoard(pii blueBall, pii redBall, vvc &map, int depth)
{
  if (depth == 11)
  {
    return;
  }
  int curBX = blueBall.first;
  int curBY = blueBall.second;
  int curRX = redBall.first;
  int curRY = redBall.second;

  int i = 0;

  for (int i = 0; i < 4; i++)
  {
    bool bFirst = isBFirst(i, blueBall, redBall);

    pii nextB, nextR;
    if (bFirst)
    {
      nextB = rollBall(blueBall, map, mx[i], my[i], 'B');
      nextR = rollBall(redBall, map, mx[i], my[i], 'R');
    }
    else
    {
      nextR = rollBall(redBall, map, mx[i], my[i], 'R');
      nextB = rollBall(blueBall, map, mx[i], my[i], 'B');
    }
    if (nextB.first != -1)
    {
      if (nextR.first == -1)
      {
        ans = min(ans, depth);
      }
      else
      {
        moveBoard(nextB, nextR, map, depth + 1);
      }
    }
    if (nextB.first != -1)
    {
      map[nextB.first][nextB.second] = '.';
    }
    if (nextR.first != -1)
    {
      map[nextR.first][nextR.second] = '.';
    }
    map[curBX][curBY] = 'B';
    map[curRX][curRY] = 'R';
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  vvc map(n, vc(m));
  pii redBall;
  pii blueBall;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> map[i][j];
      if (map[i][j] == 'B')
      {
        blueBall = make_pair(i, j);
      }
      if (map[i][j] == 'R')
      {
        redBall = make_pair(i, j);
      }
    }
  }
  moveBoard(blueBall, redBall, map, 1);
  if (ans == 999999999)
  {
    cout << -1;
  }
  else
  {
    cout << ans;
  }
  return 0;
}