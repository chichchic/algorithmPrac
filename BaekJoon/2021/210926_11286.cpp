#include <iostream>
#include <queue>
#include <utility>
#include <stdlib.h>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<pair<int, int>> pq;
  int n;
  cin >> n;
  int command;
  while (n--)
  {
    cin >> command;
    if (command)
    {
      pq.push({-abs(command), -command});
    }
    else
    {
      if (pq.empty())
      {
        cout << 0 << '\n';
      }
      else
      {
        cout << -pq.top().second << '\n';
        pq.pop();
      }
    }
  }

  return 0;
}