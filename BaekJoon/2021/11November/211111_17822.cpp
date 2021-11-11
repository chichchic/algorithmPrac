#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n, m, t;
int diskCnt = 0;
int getDiskTotal(vector<vector<int>> &disk)
{
  int ret = 0;
  int cnt = 0;
  for (int i = 1; i < disk.size(); i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (disk[i][j] == 0)
      {
        continue;
      }
      cnt++;
      ret += disk[i][j];
    }
  }
  diskCnt = cnt;
  return ret;
}

void rotateDisk(int x, int d, int k, vector<vector<int>> &disk)
{
  int direction = d ? -1 : 1;

  for (int j = 1; j * x < disk.size(); j++)
  {
    int diskIdx = j * x;
    pair<int, int> resultIdx[m];
    for (int i = 0; i < m; i++)
    {
      resultIdx[i] = make_pair((m + i + direction * k) % m, disk[diskIdx][i]);
    }
    for (int i = 0; i < m; i++)
    {
      disk[diskIdx][resultIdx[i].first] = resultIdx[i].second;
    }
  }
  getDiskTotal(disk);
}
void changeDiskNum(vector<vector<int>> &disk)
{
  vector<vector<bool>> visited(disk.size(), vector<bool>(m, false));
  bool hasSame = false;
  for (int i = 1; i < disk.size(); i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (disk[i][j] == 0)
      {
        continue;
      }
      if (visited[i][j])
      {
        continue;
      }
      queue<pair<int, int>> que;
      que.push({i, j});
      visited[i][j] = true;
      int targetNum = disk[i][j];
      while (!que.empty())
      {
        int curX = que.front().first;
        int curY = que.front().second;
        que.pop();
        pair<int, int> nextPos[4] = {{curX - 1, curY}, {curX + 1, curY}, {curX, (m + curY + 1) % m}, {curX, (m + curY - 1) % m}};
        for (int i = 0; i < 4; i++)
        {
          int nextX = nextPos[i].first;
          int nextY = nextPos[i].second;
          if (nextX >= disk.size() || visited[nextX][nextY] || disk[nextX][nextY] != targetNum)
          {
            continue;
          }
          visited[nextX][nextY] = true;
          disk[curX][curY] = 0;
          disk[nextX][nextY] = 0;
          hasSame = true;
          que.push({nextX, nextY});
        }
      }
    }
  }
  if (!hasSame)
  {
    int total = getDiskTotal(disk);
    double avg = (float)total / (float)diskCnt;
    for (int i = 1; i < disk.size(); i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (disk[i][j] == 0)
          continue;
        if (disk[i][j] < avg)
        {
          disk[i][j]++;
        }
        else if (disk[i][j] > avg)
        {
          disk[i][j]--;
        }
      }
    }
  }
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> t;
  vector<vector<int>> disk(n + 1, vector<int>(m));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> disk[i][j];
    }
  }
  while (t--)
  {
    int x, d, k;
    cin >> x >> d >> k;
    rotateDisk(x, d, k, disk);
    changeDiskNum(disk);
  }
  cout << getDiskTotal(disk);
  return 0;
}