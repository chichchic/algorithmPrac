#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int maxLen, centerNum;
  cin >> maxLen >> centerNum;
  vector<int> centerDis(centerNum + 4, 0), centerTime(centerNum + 4, 0);
  int dpFirst[104] = {};  //beforecenter
  int dpSecond[104] = {}; //time
  for (int i = 1; i <= centerNum + 1; i++)
  {
    cin >> centerDis[i];
  }
  for (int i = 1; i <= centerNum; i++)
  {
    cin >> centerTime[i];
  }
  for (int i = 1; i <= centerNum + 1; i++)
  {
    int runLen = centerDis[i];
    int candiTime = 2147483647;
    int cur;
    for (int j = i - 1; j >= 0; j--)
    {
      if (runLen > maxLen)
        break;
      int curCandiTime = centerTime[i] + dpSecond[j];
      if (curCandiTime < candiTime)
      {
        candiTime = curCandiTime;
        cur = j;
      }
      runLen += centerDis[j];
    }
    dpFirst[i] = cur;
    dpSecond[i] = candiTime;
  }

  vector<int> ans;
  int curpoint = dpFirst[centerNum + 1];
  while (curpoint > 0)
  {
    ans.push_back(curpoint);
    curpoint = dpFirst[curpoint];
  }

  printf("%d\n", dpSecond[centerNum + 1]);
  printf("%lu\n", ans.size());
  for (int i = ans.size() - 1; i >= 0; i--)
    printf("%d ", ans[i]);
  return 0;
}