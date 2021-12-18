#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cage_case(n + 1);
  cage_case[0] = 1;
  cage_case[1] = 3;
  cage_case[2] = 7;
  cage_case[3] = 17;
  cage_case[4] = 41;
  for (int i = 5; i <= n; i++)
  {
    cage_case[i] = (cage_case[i - 1] * 2 % 9901) + cage_case[i - 2];
    cage_case[i] %= 9901;
  }
  cout << cage_case[n];
  return 0;
}