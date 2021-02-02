#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, erase, temp, ans = 0, root;
  cin >> n;
  vector<vi> node(n);
  vector<int> check;

  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    if (temp == -1)
    {
      root = i;
      continue;
    }
    node[temp].push_back(i);
  }
  cin >> erase;

  if (erase == root)
  {
    cout << 0;
    return 0;
  }

  check.push_back(root);

  while (!check.empty())
  {
    int back = check.back();
    bool isEmpty = true;
    check.pop_back();
    // cout << back << ": " << node[back].size() << '\n';

    for (int i = 0; i < node[back].size(); i++)
    {
      if (node[back][i] != erase)
      {
        isEmpty = false;
        check.push_back(node[back][i]);
      }
    }
    if (isEmpty)
      ans++;
  }
  cout << ans;
  return 0;
}