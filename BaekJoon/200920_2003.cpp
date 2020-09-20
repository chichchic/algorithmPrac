#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long n, m;
  cin >> n >> m;

  vector<long long> input(n);

  for (long long i = 0; i < n; i++)
    cin >> input[i];

  long long front = 0, back = 0;
  long long sum = input[front];
  long long ans = 0;
  while (true)
  {
    if (sum == m)
      ans++;
    if (sum > m)
      sum -= input[front++];
    else if (back == n - 1)
      break;
    else
      sum += input[++back];
  }

  cout << ans << endl;
  return 0;
}