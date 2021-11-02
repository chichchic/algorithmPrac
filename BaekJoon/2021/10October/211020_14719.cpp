#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int heighest;
  int h, w;
  cin >> h >> w;
  vector<int> floor(w);
  for (int i = 0; i < w; i++)
  {
    cin >> floor[i];
  }
  int answer = 0;
  int leftMax = -1;
  int rightMax = -1;
  for (int i = 0; i < w; i++)
  {
    int lm = 0, rm = 0;
    for (int j = 0; j <= i; j++)
    {
      lm = max(lm, floor[j]);
    }
    for (int j = w - 1; j >= i; j--)
    {
      rm = max(rm, floor[j]);
    }
    answer += min(lm, rm) - floor[i];
  }
  cout << answer;
  return 0;
}