#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k, n;
  cin >> n >> k;
  vector<int> dolls(n);
  int s = 0, e = 0;
  int answer = n + 1;
  for (int i = 0; i < n; i++)
  {
    cin >> dolls[i];
  }
  int counter = 0;
  int len = 0;
  while (1)
  {
    if (counter >= k)
    {
      if (dolls[s] == 1)
        counter--;
      s++;
      len--;
    }
    else if (e == n)
    {
      break;
    }
    else
    {
      if (dolls[e] == 1)
        counter++;
      e++;
      len++;
    }
    if (counter == k)
    {
      answer = min(answer, len);
    }
  }
  if (answer == n + 1)
  {
    cout << -1;
  }
  else
  {
    cout << answer;
  }
  return 0;
}