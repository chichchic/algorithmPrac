#include <iostream>
#include <vector>
#include <iomanip>
#include <iomanip>

using namespace std;

typedef vector<int> vi;

int n;
// e0 w1 s2 n3
double dirPercent[4];

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

double ans = 0;

void backTracking(int x, int y, vector<vi> &isVisited, double percent, int depth)
{
  if (isVisited[x][y])
    return;
  if (depth == n)
  {
    ans += percent;
    return;
  }
  isVisited[x][y] = true;
  // e0 w1 s2 n3
  for (int i = 0; i < 4; i++)
  {
    int nextX = x + mx[i];
    int nextY = y + my[i];
    backTracking(nextX, nextY, isVisited, percent * dirPercent[i], depth + 1);
  }
  isVisited[x][y] = false;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> dirPercent[0] >> dirPercent[1] >> dirPercent[2] >> dirPercent[3];
  dirPercent[0] /= 100;
  dirPercent[1] /= 100;
  dirPercent[2] /= 100;
  dirPercent[3] /= 100;

  vector<vi> isVisited(29, vector<int>(29, false));
  backTracking(14, 14, isVisited, 1, 0);

  cout.precision(11);
  cout << fixed;
  cout << ans;

  return 0;
}