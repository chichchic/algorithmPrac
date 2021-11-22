#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> weight;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    weight.push_back(temp);
  }
  sort(weight.begin(), weight.end());
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    if (sum + 1 < weight[i])
    {
      break;
    }
    sum += weight[i];
  }
  cout << sum + 1;
  return 0;
}