#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct robot {
  int x;
  int y;
  int d; //dir
  int s; //step
  robot(int x, int y, int d, int s):x(x), y(y), d(d), s(s){};
};

vector<vector<vector<bool>>> visited(100, vector<vector<bool>>(100, vector<bool>(4, false)));
vector<vector<bool>> factory(100, vector<bool>(100, false));
int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, 1, 0, -1};
int ix, iy, id; //init
int tx, ty, td; //target

int turnLeft(int dir) {
  return (dir + 3) % 4;
}

int turnRight(int dir) {
  return (dir + 1)  % 4;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  int inputDirBind[5] = {-1, 1, 3, 2, 0};
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < n; j++)
    {
      int v;
      cin >> v;
      factory[i][j] = (v ? 1 : 0);
    }
  }

  cin >> ix >> iy >> id >> tx >> ty >> td;
  ix--;
  iy--;
  tx--;
  ty--;
  id = inputDirBind[id];
  td = inputDirBind[td];
  queue<robot> que;
  que.push({ix, iy, id, 0});
  visited[ix][iy][id] = true;
  while(!que.empty())
  {
    robot cur = que.front();
    que.pop();
    // cout << cur.x << ' ' << cur.y << ' ' << cur.d << ' ' << cur.s << '\n';
    if(cur.x == tx && cur.y == ty && cur.d == td) {
      cout << cur.s;
      break;
    }
    for(int k = 1; k <= 3; k++)
    {
      robot next = {cur.x + mx[cur.d] * k, cur.y + my[cur.d] * k, cur.d, cur.s + 1};
      if(next.x < 0 || next.y < 0 || next.x >= m || next.y >= n || factory[next.x][next.y]) {
        break;
      }
      if(!visited[next.x][next.y][next.d]) {
        visited[next.x][next.y][next.d] = true;
        que.push(next);
      }
    }
    //turnLeft
    int tld = turnLeft(cur.d);
    if(!visited[cur.x][cur.y][tld]) {
      visited[cur.x][cur.y][tld] = true;
      que.push({cur.x, cur.y, tld, cur.s + 1});
    }
    //turnRight
    int trd = turnRight(cur.d);
    if(!visited[cur.x][cur.y][trd]) {
      visited[cur.x][cur.y][trd] = true;
      que.push({cur.x, cur.y, trd, cur.s + 1});
    }
  }

  return 0;
}
