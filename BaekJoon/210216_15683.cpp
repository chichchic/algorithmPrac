#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m;
int ans = 65;
int totalSpace = 0;
vpii cameraPosition;

vvi calcCameraRange(vvi &roomInfo, int x, int y, int dir)
{
  const int mx[4] = {-1, 0, 1, 0};
  const int my[4] = {0, 1, 0, -1};
  int difX = mx[dir];
  int difY = my[dir];

  x += difX;
  y += difY;

  while (x >= 0 && y >= 0 && x < n && y < m)
  {
    if (roomInfo[x][y] == 6)
    {
      break;
    }
    if (roomInfo[x][y] <= 0)
    {
      roomInfo[x][y]--;
    }
    x += difX;
    y += difY;
  }

  return roomInfo;
}

void matchCamera(int depth, vvi &roomInfo)
{
  if (depth == cameraPosition.size())
  {
    int totalCameraRange = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (roomInfo[i][j] < 0)
        {
          totalCameraRange++;
        }
      }
    }
    ans = min(ans, totalSpace - totalCameraRange);
    return;
  }
  vvi cameraInfo(6);
  cameraInfo[1].push_back(0);

  cameraInfo[2].push_back(0);
  cameraInfo[2].push_back(2);

  cameraInfo[3].push_back(0);
  cameraInfo[3].push_back(1);

  cameraInfo[4].push_back(0);
  cameraInfo[4].push_back(1);
  cameraInfo[4].push_back(2);

  cameraInfo[5].push_back(0);
  cameraInfo[5].push_back(1);
  cameraInfo[5].push_back(2);
  cameraInfo[5].push_back(3);

  int curX = cameraPosition[depth].first;
  int curY = cameraPosition[depth].second;
  int cameraNum = roomInfo[curX][curY];

  int rotate[6] = {-1, 4, 2, 4, 4, 1};

  for (int i = 0; i < rotate[cameraNum]; i++)
  {
    vvi temp = roomInfo;
    for (int j = 0; j < cameraInfo[cameraNum].size(); j++)
    {
      int dir = (i + cameraInfo[cameraNum][j]) % 4;
      temp = calcCameraRange(temp, curX, curY, dir);
    }
    matchCamera(depth + 1, temp);
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  vvi roomInfo(n, vi(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> roomInfo[i][j];
      if (roomInfo[i][j] > 0 && roomInfo[i][j] < 6)
      {
        cameraPosition.push_back(make_pair(i, j));
      }
      else if (roomInfo[i][j] == 0)
      {
        totalSpace++;
      }
    }
  }
  matchCamera(0, roomInfo);
  cout << ans;

  return 0;
}