#include <iostream>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int exam_class[1000000];
  for (int i = 0; i < n; i++)
  {
    cin >> exam_class[i];
  }
  int b, c;
  cin >> b >> c;

  long long ans = n;

  for (int i = 0; i < n; i++)
  {
    exam_class[i] -= b;
    if (exam_class[i] <= 0)
      continue;
    ans += exam_class[i] / c;
    if (exam_class[i] % c != 0)
      ans++;
  }

  cout << ans;
  return 0;
}