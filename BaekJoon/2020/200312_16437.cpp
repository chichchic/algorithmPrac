#include <iostream>
#include <vector>

using namespace std;

typedef vector<long long> vll;

vector<vll> bridge(123457);
vector<long long> animal(123457);

long long find(long long island)
{
  long long ans = 0;
  for (int i = 0; i < bridge[island].size(); i++)
  {
    ans += find(bridge[island][i]);
  }
  ans += animal[island];
  if (ans > 0)
    return ans;
  else
    return 0;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  long long n, a, p;
  char t;
  scanf(" %lld", &n);
  for (int i = 2; i <= n; i++)
  {
    scanf(" %c %lld %lld", &t, &a, &p);
    int sign = 1;
    if (t == 'W')
      sign = -1;
    bridge[p].push_back(i);
    animal[i] = a * sign;
  }
  cout << find(1);
  return 0;
}