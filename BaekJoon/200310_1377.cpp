#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  vector<int> input(n);
  vector<int> sort_input(n);
  map<int, int> m;
  for (int i = 0; i < n; i++)
  {
    cin >> input[i];
    sort_input[i] = input[i];
  }
  sort(sort_input.begin(), sort_input.end());

  for (int i = 0; i < n; i++)
  {
    m.insert(make_pair(sort_input[i], i));
    if (m[sort_input[i]] != i)
      m[sort_input[i]] = i;
  }

  int max = 0;
  for (int i = 0; i < n; i++)
  {
    int idx = i - m[input[i]];
    if (max < idx)
      max = idx;
  }
  cout << max + 1;
  return 0;
}
