#include <iostream>

using namespace std;

int solution(int s, int t, int count)
{
  if (s > t)
    return 1e9;
  if (s == t)
    return count;
  return min(solution(s * 2, t + 3, count + 1), solution(s + 1, t, count + 1));
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c, s, t;
  cin >> c;
  while (c--)
  {
    cin >> s >> t;
    cout << solution(s, t, 0) << '\n';
  }

  return 0;
}