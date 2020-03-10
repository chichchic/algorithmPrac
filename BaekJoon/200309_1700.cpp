#include <iostream>
#include <vector>
using namespace std;

int main()
{
  freopen("input.txt", "r", stdin);
  int n, k, cur, num = 0, ans = 0;
  cin >> n >> k;
  vector<int> index(k + 1, 9999999);
  vector<int> input(k + 1);
  vector<bool> plug(k + 1, false);
  for (int i = 0; i < k; i++)
  {
    cin >> input[i];
    index[input[i]] = i;
  }
  for (int i = 0; i < k; i++)
  {
    cur = input[i];
    if (!plug[cur])
    {
      if (num < n)
      {
        num++;
        plug[cur] = true;
      }
      else
      {
        ans++;
        bool skip = false;
        for (int j = 1; j <= k; j++)
        {
          if (plug[j])
          {
            if (index[j] < i)
            {
              skip = true;
              plug[j] = false;
              plug[cur] = true;
              // cout << i + 1 << " : " << j << "!\n";
              break;
            }
          }
        }
        if (!skip)
        {
          int candi;
          for (int j = i + 1; j < k; j++)
          {
            if (plug[input[j]])
              candi = input[j];
          }
          // cout << i + 1 << " : " << candi << '\n';
          plug[candi] = false;
          plug[cur] = true;
        }
      }
    }
  }
  cout << ans;
  return 0;
}