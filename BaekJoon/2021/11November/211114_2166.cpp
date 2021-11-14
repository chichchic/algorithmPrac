#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<long long, long long>> points(n);
  for (int i = 0; i < n; i++)
  {
    cin >> points[i].first >> points[i].second;
  }

  long long sum = 0;
  for (int i = 0; i < n - 1; i++)
  {
    sum += (points[i].first + points[i + 1].first) * (points[i].second - points[i + 1].second);
  }
  sum += (points[n - 1].first + points[0].first) * (points[n - 1].second - points[0].second);
  double answer = abs(sum) * (double)0.5;
  answer = round(answer * 10) / 10;
  printf("%.1lf", answer);
  return 0;
}