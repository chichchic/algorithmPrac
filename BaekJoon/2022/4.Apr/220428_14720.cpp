#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int cur = 0;
  int answer = 0;
  for (int i = 0; i < n; i++)
  {
    int milk;
    cin >> milk;
    if (milk == cur)
    {
      cur++;
      cur %= 3;
      answer++;
    }
  }
  cout << answer;
  return 0;
}