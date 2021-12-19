#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  cin >> t;
  while (t--)
  {
    cin >> n;
    int answer = 0;
    vector<pair<int, int>> scores(n);
    for (int i = 0; i < n; i++)
    {
      cin >> scores[i].first >> scores[i].second;
    }
    sort(scores.begin(), scores.end());
    int interview = 1e6;
    for (int i = 0; i < n; i++)
    {
      if (scores[i].second < interview)
      {
        answer++;
        interview = scores[i].second;
      }
    }
    cout << answer << '\n';
  }

  return 0;
}