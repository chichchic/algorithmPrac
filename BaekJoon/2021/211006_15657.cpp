#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_answer_sequence(vector<int> &numbers, const int target_size, vector<int> candidate, int index)
{
  if (candidate.size() == target_size)
  {
    for (auto number : candidate)
    {
      cout << number << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = index; i < numbers.size(); i++)
  {
    candidate.push_back(numbers[i]);
    print_answer_sequence(numbers, target_size, candidate, i);
    candidate.pop_back();
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
  print_answer_sequence(numbers, m, vector<int>(0), 0);
  return 0;
}