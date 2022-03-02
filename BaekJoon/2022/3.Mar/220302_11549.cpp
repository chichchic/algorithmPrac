#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, answer = 0;
  cin >> t;
  for (int i = 0; i < 5; i++)
  {
    int tea;
    cin >> tea;
    if (tea == t)
    {
      answer++;
    }
  }
  cout << answer;

  return 0;
}