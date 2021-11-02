#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

bool grid[101][101] = {};

pii rotate(pii p, pii rot)
{
  int rotX = rot.first;
  int rotY = rot.second;
  int pX = p.first - rotX;
  int pY = p.second - rotY;
  return make_pair(-pY + rotX, pX + rotY);
}
void makeNextGeneration(vpii &dragon, pii endPoint, int depth, const int endDepth)
{
  if (depth == endDepth)
  {
    return;
  }
  int len = dragon.size();
  pii newEndPoint;
  // cout << "endPoint: " << endPoint.first << ' ' << endPoint.second << '\n';
  for (int i = 0; i < len; i++)
  {
    pii newPoint = rotate(dragon[i], endPoint);
    if (i == 0)
    {
      newEndPoint = newPoint;
    }
    int newX = newPoint.first;
    int newY = newPoint.second;
    if (newX >= 0 && newX <= 100 && newY >= 0 && newY <= 100)
    {
      // cout << depth + 1 << ' ' << newX << ' ' << newY << '\n';
      grid[newX][newY] = true;
    }
    dragon.push_back(newPoint);
  }

  makeNextGeneration(dragon, newEndPoint, depth + 1, endDepth);
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int curvNum;
  cin >> curvNum;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, -1, 0, 1};
  for (int i = 0; i < curvNum; i++)
  {
    int x, y, d, g;
    vpii dragon;
    cin >> x >> y >> d >> g;
    grid[x][y] = true;
    int endX = x + dx[d];
    int endY = y + dy[d];
    grid[endX][endY] = true;

    dragon.push_back(make_pair(x, y));
    dragon.push_back(make_pair(endX, endY));
    // cout << i << " new dragon\n";
    // cout << 0 << ' ' << x << ' ' << y << '\n';
    // cout << 0 << ' ' << endX << ' ' << endY << '\n';
    makeNextGeneration(dragon, make_pair(endX, endY), 0, g);
    // cout << i << " dragonDot: " << dragon.size() << '\n';
  }
  int ans = 0;
  for (int i = 0; i < 100; i++)
  {
    for (int j = 0; j < 100; j++)
    {
      if (grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1])
      {
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}