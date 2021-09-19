#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

double getDistance(pair<double, double> dot1, pair<double, double> dot2)
{
  double x1 = dot1.first;
  double y1 = dot1.second;
  double x2 = dot2.first;
  double y2 = dot2.second;
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<double, double>> signals(n);
  vector<double> dp(n, 0);
  double answer = 0;
  for (int i = 0; i < n; i++)
  {
    double x, y;
    cin >> x >> y;
    signals[i] = make_pair(x, y);
  }
  sort(signals.begin(), signals.end());
  for (int i = 0; i < n; i++)
  {
    double curDist = dp[i];
    for (int j = i + 1; j < n; j++)
    {
      if (signals[j].first <= signals[i].first)
      {
        continue;
      }
      dp[j] = max(dp[j], curDist + getDistance(signals[i], signals[j]));
      answer = max(dp[j], answer);
    }
  }
  printf("%.8lf", answer);
  return 0;
}