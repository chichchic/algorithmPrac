#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
int main()
{
  // freopen("input.txt", "r", stdin);
  int n, m, fs, fe, ans = 0;
  cin >> n >> m;
  vector<vi> friendList(n + 1);
  vector<int> stack;
  vector<bool> check(n + 1, false);
  check[1] = true;
  for (int i = 0; i < m; i++)
  {
    cin >> fs >> fe;
    friendList[fs].push_back(fe);
    friendList[fe].push_back(fs);
  }
  for (int i = 0; i < friendList[1].size(); i++)
  {
    int myfriend = friendList[1][i];
    stack.push_back(myfriend);
    if (!check[myfriend])
    {
      check[myfriend] = true;
      // cout << myfriend << ' ';
      ans++;
    }
  }
  for (int i = 0; i < stack.size(); i++)
  {
    int f = stack[i];
    for (int i = 0; i < friendList[f].size(); i++)
    {
      int fFriend = friendList[f][i];
      if (!check[fFriend])
      {
        // cout << fFriend << ' ';
        check[fFriend] = true;
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}