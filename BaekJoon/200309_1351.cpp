#include <iostream>
#include <map>

using namespace std;

long long n, p, q;
map<long long, long long> memo;

long long npq(long long cur)
{
  if (cur == 0)
  {
    return 1;
  }
  map<long long, long long>::iterator itr = memo.find(cur);
  if (itr == memo.end())
  {
    memo.insert(pair<long long, long long>(cur, npq(cur / p) + npq(cur / q)));
    return (*memo.find(cur)).second;
  }
  else
    return (*itr).second;
}

int main()
{
  freopen("input.txt", "r", stdin);
  cin >> n >> p >> q;
  cout << npq(n);
  return 0;
}