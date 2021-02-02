#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

struct point
{
  int x, y, step;
  point(int x, int y, int step) : x(x), y(y), step(step) {}
};

typedef vector<int> vi;
typedef vector<bool> vb;

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, m;
  cin >> n >> m;
  vector<bool> tempVecBool(m, false);
  char *A[3010];
  vector<vb> check(n, tempVecBool);
  queue<point> que;

  int initX = 0;
  int initY = 0;

  int mx[4] = {1, -1, 0, 0};
  int my[4] = {0, 0, 1, -1};

  for (int j = 0; j < n; j++)
  {
    A[j] = (char *)malloc(sizeof(char) * 3010);
    scanf("%s", A[j]);
    // printf("%s\n", A[j]);
    for (int i = 0; i < m; i++)
    {
      if (A[j][i] == '2')
      {
        initX = j;
        initY = i;
      }
    }
  }

  check[initX][initY] = true;
  que.push(point(initX, initY, 0));
  bool arrive = false;
  int ans;
  while (!que.empty())
  {
    point cur = que.front();
    que.pop();
    int curx = cur.x;
    int cury = cur.y;
    int curstep = cur.step;
    for (int i = 0; i < 4; i++)
    {
      int nextx = curx + mx[i], nexty = cury + my[i];
      if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && A[nextx][nexty] != '1' && !check[nextx][nexty])
      {
        check[nextx][nexty] = true;
        que.push(point(nextx, nexty, curstep + 1));
        // printf("%d %d %d\n", nextx, nexty, A[nextx][nexty]);

        if (A[nextx][nexty] >= '3' && A[nextx][nexty] <= '5')
        {
          arrive = true;
          ans = curstep + 1;
          break;
        }
      }
    }
    if (arrive)
      break;
  }
  if (arrive)
  {
    printf("TAK\n%d", ans);
    return 0;
  }
  printf("NIE\n");
  return 0;
}