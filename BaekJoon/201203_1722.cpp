#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long n, k;
  cin >> n >> k;

  vector<long long> num(n);
  for (long long i = n; i > 0; i--)
  {
    num[n - i] = i;
  }
  vector<long long> orderArr(n);

  long long maxOrder = 1;
  for (long long i = 2; i <= n; i++)
  {
    maxOrder *= i;
  }

  if (k == 1)
  {
    long long order;
    cin >> order;
    for (long long i = 0; i < n; i++)
    {
      maxOrder /= n - i;
      orderArr[i] = (order - 1) / maxOrder;
      order -= orderArr[i] * maxOrder;
    }
    for (long long i = 0; i < n; i++)
    {
      vector<long long> tempStack;
      long long j = 0;
      while (j < orderArr[i])
      {
        tempStack.push_back(num.back());
        num.pop_back();
        j++;
      }
      cout << num.back() << ' ';
      num.pop_back();
      while (!tempStack.empty())
      {
        num.push_back(tempStack.back());
        tempStack.pop_back();
      }
    }
  }
  else
  {
    long long ans = 0;
    long long temp;
    for (long long i = 0; i < n - 2; i++)
    {
      cin >> temp;
      vector<long long> tempStack;
      long long j = 0;
      while (temp != num.back())
      {
        tempStack.push_back(num.back());
        num.pop_back();
        j++;
      }
      num.pop_back();
      while (!tempStack.empty())
      {
        num.push_back(tempStack.back());
        tempStack.pop_back();
      }
      maxOrder /= n - i;
      ans += j * maxOrder;
    }
    long long f, s;
    cin >> f >> s;
    if (f > s)
      ans += 2;
    else
      ans++;
    cout << ans;
  }

  return 0;
}