#include <iostream>
#include <vector>

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
    vector<bool> room(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
      for (int j = 1; j * i <= n; j++)
      {
        room[i * j] = !room[i * j];
      }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
      if (room[i])
      {
        answer++;
      }
    }
    cout << answer << '\n';
  }

  return 0;
}