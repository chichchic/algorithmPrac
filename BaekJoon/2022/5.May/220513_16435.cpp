#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  vector<int> fruit(n);
  for (int i = 0; i < n; i++)
  {
    cin >> fruit[i];
  }
  sort(fruit.begin(), fruit.end());

  for (int i = 0; i < n; i++)
  {
    if (fruit[i] > l)
    {
      break;
    }
    l++;
  }
  cout << l;

  return 0;
}