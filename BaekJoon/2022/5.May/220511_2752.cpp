#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> input(3, -1);
  cin >> input[0];
  cin >> input[1];
  cin >> input[2];
  sort(input.begin(), input.end());
  cout << input[0] << ' ' << input[1] << ' ' << input[2];
  return 0;
}