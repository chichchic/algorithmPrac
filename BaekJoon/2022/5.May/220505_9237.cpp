#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> wait(n);
  for (int i = 0; i < n; i++)
  {
    cin >> wait[i];
  }
  sort(wait.begin(), wait.end(), greater<int>());
  int answer = 0;
  for (int i = 0; i < n; i++)
  {
    answer = max(answer, wait[i] + i + 2);
  }
  cout << answer;
  return 0;
}