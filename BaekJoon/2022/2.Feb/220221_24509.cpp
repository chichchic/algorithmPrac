#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<bool> presented(200001, false);

int getStudent(vector<pair<int, int>> scores)
{
  int i = 0;
  while (presented[scores[i].second])
  {
    i++;
  }
  presented[scores[i].second] = true;
  return scores[i].second;
}

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> aScores(n);
  vector<pair<int, int>> bScores(n);
  vector<pair<int, int>> cScores(n);
  vector<pair<int, int>> dScores(n);
  for (int i = 0; i < n; i++)
  {
    int idx, a, b, c, d;
    cin >> idx >> a >> b >> c >> d;
    aScores[i] = {-a, idx};
    bScores[i] = {-b, idx};
    cScores[i] = {-c, idx};
    dScores[i] = {-d, idx};
  }
  sort(aScores.begin(), aScores.end());
  sort(bScores.begin(), bScores.end());
  sort(cScores.begin(), cScores.end());
  sort(dScores.begin(), dScores.end());

  cout << getStudent(aScores) << ' ' << getStudent(bScores) << ' ' << getStudent(cScores) << ' ' << getStudent(dScores);

  return 0;
}