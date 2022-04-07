#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  unordered_map<string, bool> table;
  for (int i = 0; i < n; i++)
  {
    string name, status;
    cin >> name >> status;
    if (status == "enter")
    {
      table[name] = true;
    }
    else
    {
      table[name] = false;
    }
  }
  vector<string> remains;
  for (auto a = table.begin(); a != table.end(); a++)
  {
    if (a->second)
    {
      remains.push_back(a->first);
    }
  }
  sort(remains.begin(), remains.end());
  reverse(remains.begin(), remains.end());
  for (auto name : remains)
  {
    cout << name << '\n';
  }
  return 0;
}