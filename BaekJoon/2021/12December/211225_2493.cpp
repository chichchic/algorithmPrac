#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> tower(n + 1, vector<int>(2));
  vector<int> answer(n + 1);
  tower[0][0] = 0;
  tower[0][1] = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> tower[i][0];
    int prev = i - 1;
    while (prev != 0)
    {
      if (tower[prev][0] > tower[i][0])
      {
        break;
      }
      prev = answer[prev];
    }
    tower[i][1] = tower[prev][0];
    answer[i] = prev;
  }

  for (int i = 1; i <= n; i++)
  {
    cout << answer[i] << ' ';
  }
  return 0;
}

/*
// NOTE: 다른 풀이
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<pair<int, int>> st;
  for (int i = 1; i <= n; i++)
  {
    int h;
    cin >> h;
    bool getSignal = false;
    while (!st.empty())
    {
      if (st.top().first > h)
      {
        getSignal = true;
        cout << st.top().second << ' ';
        break;
      }
      st.pop();
    }
    if (!getSignal)
    {
      cout << 0 << ' ';
    }
    st.push({h, i});
  }

  return 0;
}
*/