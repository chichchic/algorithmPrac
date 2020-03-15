#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define closedint <int>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int t;
  scanf(" %d", &t);
  while (t--)
  {
    int k, n, cnt = 0;
    char c;
    priority_queue<int, vector<int>, less closedint> lpq;
    priority_queue<int, vector<int>, greater closedint> gpq;
    map<int, int> min_delet;
    map<int, int> max_delet;
    map<int, int>::iterator itr;
    scanf(" %d", &k);
    while (k--)
    {
      scanf(" %c %d", &c, &n);
      if (c == 'I')
      {
        cnt++;
        lpq.push(n);
        gpq.push(n);
      }
      else
      {
        if (n != 1)
        {
          while (!gpq.empty())
          {
            int top = gpq.top();
            gpq.pop();
            itr = min_delet.find(top);
            if (itr != min_delet.end())
            {
              // cout << '!' << top << '\n';

              if (itr->second == 1)
                min_delet.erase(itr);
              else
                itr->second--;
            }
            else
            {
              // cout << '?' << top << '\n';

              itr = max_delet.find(top);
              if (itr != max_delet.end())
                itr->second++;
              else
                max_delet.insert(make_pair(top, 1));
              cnt--;
              break;
            }
          }
        }
        else
        {
          while (!lpq.empty())
          {
            int top = lpq.top();
            lpq.pop();
            itr = max_delet.find(top);
            if (itr != max_delet.end())
            {
              // cout << '!' << top << '\n';

              if (itr->second == 1)
                max_delet.erase(itr);
              else
                itr->second--;
            }
            else
            {
              // cout << '?' << top << '\n';

              itr = min_delet.find(top);
              if (itr != min_delet.end())
                itr->second++;
              else
                min_delet.insert(make_pair(top, 1));
              cnt--;
              break;
            }
          }
        }
      }
    }
    if (cnt == 0)
      cout << "EMPTY" << '\n';
    else
    {
      int max_val, min_val;
      while (!gpq.empty())
      {
        int top = gpq.top();
        gpq.pop();
        itr = min_delet.find(top);
        if (itr != min_delet.end())
        {
          if (itr->second == 1)
            min_delet.erase(itr);
          else
            itr->second--;
        }
        else
        {
          max_val = top;
          break;
        }
      }
      while (!lpq.empty())
      {
        int top = lpq.top();
        lpq.pop();
        itr = max_delet.find(top);
        if (itr != max_delet.end())
        {
          if (itr->second == 1)
            max_delet.erase(itr);
          else
            itr->second--;
        }
        else
        {
          min_val = top;
          break;
        }
      }
      cout << max_val << ' ' << min_val << '\n';
    }
  }
  return 0;
}