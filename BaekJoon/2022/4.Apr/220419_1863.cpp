#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> st;
  int x, y;
  int answer = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    while (!st.empty() && st.top() > y)
    {
      answer++;
      st.pop();
    }
    if (st.empty() || st.top() != y)
    {
      st.push(y);
    }
  }
  while (!st.empty())
  {
    if (st.top() > 0)
    {
      answer++;
    }
    st.pop();
  }
  cout << answer;
  return 0;
}