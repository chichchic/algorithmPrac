//NOTE: [ref] https://www.acmicpc.net/board/view/50111

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
  int r, c, s, d, z;
};

int r, c, m;
vector<info> sharks(10000);
int sharkMap[101][101] = {};
vector<int> map_state[101][101];
int mx[5] = {0, -1, 1, 0, 0};
int my[5] = {0, 0, 0, 1, -1};

void setPos(int energy, int idx)
{
  if (sharks[idx].d == 1 || sharks[idx].d == 2)
  {
    energy %= ((r - 1) * 2);
  }
  else
  {
    energy %= ((c - 1) * 2);
  }

  for (int i = 0; i < energy; i++)
  {
    sharks[idx].r += mx[sharks[idx].d];
    sharks[idx].c += my[sharks[idx].d];
    if (sharks[idx].r <= 0)
    {
      sharks[idx].d = 2;
      sharks[idx].r += mx[sharks[idx].d];
      i--;
    }
    if (sharks[idx].r > r)
    {
      sharks[idx].d = 1;
      sharks[idx].r += mx[sharks[idx].d];
      i--;
    }
    if (sharks[idx].c <= 0)
    {
      sharks[idx].d = 3;
      sharks[idx].c += my[sharks[idx].d];
      i--;
    }
    if (sharks[idx].c > c)
    {
      sharks[idx].d = 4;
      sharks[idx].c += my[sharks[idx].d];
      i--;
    }
  }
}

void moveShark()
{
  for (int i = 1; i <= m; i++)
  {
    map_state[sharks[i].r][sharks[i].c].clear();
  }
  for (int i = 1; i <= m; i++)
  {
    sharkMap[sharks[i].r][sharks[i].c] = 0;
    if (sharks[i].z == 0)
    {
      continue;
    }
    setPos(sharks[i].s, i);
    map_state[sharks[i].r][sharks[i].c].push_back(i);
  }
}

void eat()
{
  for (int i = 1; i <= m; i++)
  {
    if (sharks[i].z == 0)
    {
      continue;
    }
    sort(map_state[sharks[i].r][sharks[i].c].begin(), map_state[sharks[i].r][sharks[i].c].end(), [](int a, int b) {
      return sharks[a].z > sharks[b].z;
    });
    for (int j = 1; j < map_state[sharks[i].r][sharks[i].c].size(); j++)
    {
      sharks[map_state[sharks[i].r][sharks[i].c][j]].z = 0;
    }
    sharkMap[sharks[i].r][sharks[i].c] = map_state[sharks[i].r][sharks[i].c][0];
  }
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c >> m;
  for (int i = 1; i <= m; i++)
  {
    cin >> sharks[i].r >> sharks[i].c >> sharks[i].s >> sharks[i].d >> sharks[i].z;
    sharkMap[sharks[i].r][sharks[i].c] = i;
  }
  int answer = 0;
  for (int i = 1; i <= c; i++)
  {
    for (int j = 1; j <= r; j++)
    {
      if (sharkMap[j][i] != 0 && sharks[sharkMap[j][i]].z != 0)
      {
        answer += sharks[sharkMap[j][i]].z;
        sharks[sharkMap[j][i]].z = 0;
        sharkMap[j][i] = 0;
        break;
      }
    }
    moveShark();
    eat();
  }
  cout << answer;
  return 0;
}