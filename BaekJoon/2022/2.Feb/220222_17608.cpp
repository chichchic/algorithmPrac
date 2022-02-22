#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> sticks(100001);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> sticks[i];
  }
  int cur = sticks[n - 1];
  int answer = 1;
  for (int i = n - 2; i >= 0; i--)
  {
    if (sticks[i] > cur)
    {
      cur = sticks[i];
      answer++;
    }
  }
  cout << answer;

  return 0;
}