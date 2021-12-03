#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> seq(n);
  for (int i = 0; i < n; i++)
  {
    cin >> seq[i];
  }
  sort(seq.begin(), seq.end());
  cout << seq[k - 1];
  return 0;
}