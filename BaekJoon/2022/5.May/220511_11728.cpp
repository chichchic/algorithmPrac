#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  a.insert(a.end(), b.begin(), b.end());
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << ' ';
  }

  return 0;
}