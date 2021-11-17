#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int students;
    cin >> students;
    int answer = students;
    vector<int> direct(students + 1);
    for (int i = 1; i <= students; i++)
    {
      cin >> direct[i];
    }
    vector<bool> visited(students + 1, false);
    for (int i = 1; i <= students; i++)
    {
      if (visited[i])
      {
        continue;
      }
      stack<int> st;
      st.push(i);
      visited[i] = true;
      int breakPoint = -1;
      while (true)
      {
        int top = st.top();
        int next = direct[top];
        if (visited[next])
        {
          breakPoint = next;
          break;
        }
        visited[next] = true;
        st.push(next);
      }
      int companyCnt = 0;
      bool inStack = false;
      while (!st.empty())
      {
        companyCnt++;
        if (st.top() == breakPoint)
        {
          inStack = true;
          break;
        }
        st.pop();
      }
      if (inStack)
      {
        // cout << i << ' ' << breakPoint << ' ' << companyCnt << " :::\n";
        answer -= companyCnt;
      }
    }
    cout << answer << '\n';
  }
  return 0;
}