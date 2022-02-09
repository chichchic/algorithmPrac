#include <iostream>

using namespace std;

int main()
{
  // freopen("../../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int answer = 0;
  while (true)
  {
    int hole;
    cin >> hole;
    answer += hole;
    if (!(--n))
      break;
    answer--;
  }
  cout << answer;
  return 0;
}