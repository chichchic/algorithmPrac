#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_sequence(vector<int> &numbers, vector<bool> &have_sequence, vector<int> &sequence, const int target_size)
{
  if (sequence.size() == target_size)
  {
    for (auto number : sequence)
    {
      cout << number << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = 0; i < numbers.size(); i++)
  {
    if (have_sequence[i])
      continue;
    have_sequence[i] = true;
    sequence.push_back(numbers[i]);
    print_sequence(numbers, have_sequence, sequence, target_size);
    have_sequence[i] = false;
    sequence.pop_back();
  }
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> numbers(n);
  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }
  sort(numbers.begin(), numbers.end());
  vector<bool> have_sequence(n, false);
  vector<int> sequence;
  print_sequence(numbers, have_sequence, sequence, m);
  return 0;
}