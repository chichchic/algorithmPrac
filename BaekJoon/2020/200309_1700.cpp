#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int n, k, cur, plugedNum = 0, ans = 0;
  cin >> n >> k;
  vector<bool> pluged(k + 1, false);
  vector<int> input(k);
  vector<int> lastIndex(k + 1);
  for (int i = 0; i < k; i++)
  {
    cin >> input[i];
    lastIndex[input[i]] = i;
  }
  for (int i = 0; i < k; i++)
  {
    cur = input[i];
    if (!pluged[cur])
    {
      if (n > plugedNum)
      {
        plugedNum++;
        pluged[cur] = true;
      }
      else
      {
        bool change = false;
        ans++;

        for (int num = 1; num <= k; num++)
        {
          if (pluged[num] && lastIndex[num] < i)
          {
            change = true;
            pluged[num] = false;
            pluged[cur] = true;
            break;
          }
        }
        if (!change)
        {
          int lastUse;
          vector<int> backTrue;
          for (int idx = i + 1; idx < k; idx++)
          {
            int check = input[idx];
            if (pluged[check])
            {
              backTrue.push_back(check);
              pluged[check] = false;
            }
          }
          backTrue.pop_back();
          for (int i = 0; i < backTrue.size(); i++)
          {
            pluged[backTrue[i]] = true;
          }
          pluged[cur] = true;
        }
      }
    }
  }
  cout << ans;
  return 0;
}