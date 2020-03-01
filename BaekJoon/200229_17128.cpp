#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  long long n, q;
  cin >> n >> q;
  vector<long long> cow(n);
  vector<long long> result(n);
  long long temp = 1;
  long long sum = 0;
  for (long long i = 0; i <= 3; i++)
  {
    scanf(" %ld", &cow[i]);
    temp *= cow[i];
  }
  sum += temp;
  result[0] = temp;
  for (long long i = 4; i < n; i++)
  {
    scanf(" %ld", &cow[i]);
    temp /= cow[i - 4];
    temp *= cow[i];
    result[i - 3] = temp;
    sum += temp;
  }
  for (long long i = n - 3; i < n; i++)
  {
    temp /= cow[i - 1];
    temp *= cow[i - n + 3];
    result[i] = temp;
    sum += temp;
  }
  long long q_input;
  for (long long i = 0; i < q; i++)
  {
    scanf(" %ld", &q_input);
    q_input--;
    for (long long j = 0; j < 4; j++)
    {
      long long idx = (q_input - j + n) % n;
      sum -= result[idx];
      result[idx] *= -1;
      sum += result[idx];
    }
    cout << sum << '\n';
  }
  return 0;
}