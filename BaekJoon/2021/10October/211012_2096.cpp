#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
  if (a > b)
    return a;
  return b;
}

int max3(int a, int b, int c)
{
  return max(max(a, b), max(b, c));
}

int min(int a, int b)
{
  if (a < b)
    return a;
  return b;
}

int min3(int a, int b, int c)
{
  return min(min(a, b), min(b, c));
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> min_lines(2, vector<int>(3, 0));
  vector<vector<int>> max_lines(2, vector<int>(3, 0));
  for (int i = 0; i < n; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    max_lines[i % 2][0] = a + max(max_lines[(i + 1) % 2][0], max_lines[(i + 1) % 2][1]);
    max_lines[i % 2][1] = b + max3(max_lines[(i + 1) % 2][0], max_lines[(i + 1) % 2][1], max_lines[(i + 1) % 2][2]);
    max_lines[i % 2][2] = c + max(max_lines[(i + 1) % 2][1], max_lines[(i + 1) % 2][2]);

    min_lines[i % 2][0] = a + min(min_lines[(i + 1) % 2][0], min_lines[(i + 1) % 2][1]);
    min_lines[i % 2][1] = b + min3(min_lines[(i + 1) % 2][0], min_lines[(i + 1) % 2][1], min_lines[(i + 1) % 2][2]);
    min_lines[i % 2][2] = c + min(min_lines[(i + 1) % 2][1], min_lines[(i + 1) % 2][2]);
  }
  cout << max3(max_lines[(n - 1) % 2][0], max_lines[(n - 1) % 2][1], max_lines[(n - 1) % 2][2]) << ' ' << min3(min_lines[(n - 1) % 2][0], min_lines[(n - 1) % 2][1], min_lines[(n - 1) % 2][2]);
  ;
  return 0;
}