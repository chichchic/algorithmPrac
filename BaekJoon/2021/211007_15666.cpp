#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void print_seqeunce(vector<int> &numbers_cnt, const int target_size, vector<int> &candidate, int candidate_size, int index)
{
  if (target_size == candidate_size)
  {
    for (int number : candidate)
    {
      cout << number << ' ';
    }
    cout << '\n';
    return;
  }
  for (int i = index; i < numbers_cnt.size(); ++i)
  {
    candidate.push_back(numbers_cnt[i]);
    print_seqeunce(numbers_cnt, target_size, candidate, candidate_size + 1, i);
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
  vector<int> numbers_cnt;
  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }
  sort(numbers.begin(), numbers.end());
  for (int i = 0; i < n; i++)
  {
    if (!numbers_cnt.empty() && numbers_cnt.back() == numbers[i])
    {
      continue;
    }
    numbers_cnt.push_back(numbers[i]);
  }
  vector<int> candidate;
  print_seqeunce(numbers_cnt, m, candidate, 0, 0);
}