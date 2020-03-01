#include <iostream>

using namespace std;

int main()
{
  // freopen("input.txt", "r", stdin);
  int ze[9];
  int temp;
  bool zeW = false;
  int st;
  cin >> ze[0];
  if (ze[0] > 0)
    zeW = true;
  for (int i = 1; i < 9; i++)
  {
    cin >> temp;
    ze[i] = ze[i - 1] + temp;
  }
  cin >> st;
  for (int i = 1; i < 9; i++)
  {
    cin >> temp;
    if (ze[i] > st)
      zeW = true;
    st += temp;
  }
  if (zeW)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}