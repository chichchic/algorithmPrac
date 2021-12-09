#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, score, p;
  cin >> n >> score >> p;
  vector<int> scores(n);
  for (int i = 0; i < n; i++)
  {
    cin >> scores[i];
  }
  scores.push_back(score);
  sort(scores.begin(), scores.end(), greater<int>());
  int answer = 1e9;
  for (int i = 0; i < p; i++)
  {
    if (score == scores[i])
    {
      answer = min(answer, i + 1);
    }
  }
  if (p <= n && scores[p - 1] == scores[p])
  {
    answer = -1;
  }
  answer = answer == 1e9 ? -1 : answer;
  cout << answer;
  return 0;
}