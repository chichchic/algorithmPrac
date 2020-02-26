#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
vector<string> listened;

bool bf(string compStr)
{
  int start = 0;
  int end = listened.size();
  while (start <= end)
  {
    int mid = (start + end) / 2;
    if (listened[mid] == compStr)
      return true;
    else if (listened[mid] < compStr)
    {
      start = mid + 1;
    }
    else
      end = mid - 1;
  }
  return false;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, m;
  int ans = 0;
  vector<string> ansv;
  cin >> n >> m;
  string temp;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    listened.push_back(temp);
  }
  sort(listened.begin(), listened.end());
  for (int i = 0; i < m; i++)
  {
    cin >> temp;
    if (bf(temp))
    {
      ans++;
      ansv.push_back(temp);
    }
  }
  sort(ansv.begin(), ansv.end());
  cout << ans << '\n';
  for (int i = 0; i < ans; i++)
    cout << ansv[i] << '\n';
  return 0;
}