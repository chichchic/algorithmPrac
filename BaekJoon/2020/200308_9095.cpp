#include <iostream>

using namespace std;

int arr[15] = {0, 1, 2, 4};

int output(int n)
{
  if (arr[n])
    return arr[n];
  return output(n - 1) + output(n - 2) + output(n - 3);
}

int main()
{
  // freopen("input.txt", "r", stdin);
  int t, n;
  cin >> t;
  while (t--)
  {
    cin >> n;
    cout << output(n) << '\n';
  }
  return 0;
}