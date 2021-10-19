#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n = 4;
  cin >> n;
  vector<pair<long long, long long>> lines(n);
  int idx = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> lines[i].first >> lines[i].second;
  }
  sort(lines.begin(), lines.end(), less<pair<long long, long long>>());

  pair<long long, long long> points = lines[0];
  long long answer = 0;
  bool needAdd = false;
  for (int i = 1; i < n; i++)
  {
    if (points.second < lines[i].first)
    {
      answer += points.second - points.first;
      points = lines[i];
      continue;
    }
    points.second = max(points.second, lines[i].second);
  }
  answer += points.second - points.first;
  cout << answer;
  return 0;
}