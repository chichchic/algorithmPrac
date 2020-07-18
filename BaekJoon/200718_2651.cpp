#include <iostream>
#include <vector>
/*
못풀었습니다.
*/
using namespace std;
struct item
{
  int dis, time;
  item() {}
  item(int d, int t) : dis(d), time(t) {}
};

int main()
{
  freopen("input.txt", "r", stdin);
  int maxLen, centerNum;
  vector<int> centerDis(centerNum), centerTime(centerNum);
  cin >> maxLen >> centerNum;
  item dp[100][100];
  for (int i = 0; i < centerNum; i++)
  {
    cin >> centerDis[i];
  }
  for (int i = 0; i < centerNum; i++)
  {
    cin >> centerTime[i];
  }
  dp[0][0] = item(0, 0);
  for (int i = 1; i < centerNum; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      dp[i][j] = item(0, 0);
    }
  }

  return 0;
}