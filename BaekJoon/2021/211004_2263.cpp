#include <iostream>
#include <stack>
#include <vector>

const int MAX_SIZE = 1e5;
using namespace std;
vector<int> inorder(MAX_SIZE);
vector<int> inorder_position(MAX_SIZE + 1);
stack<int> postorder;

vector<int> find_preorder(int start, int end)
{
  int node = postorder.top();
  postorder.pop();
  if (start == end)
  {
    return vector<int>(1, node);
  }
  vector<int> output;
  output.push_back(node);
  int leftEnd = inorder_position[node] - 1;
  int rightStart = inorder_position[node] + 1;
  vector<int> rightChillren;
  vector<int> leftChillren;
  if (rightStart <= end)
  {
    rightChillren = find_preorder(rightStart, end);
  }
  if (start <= leftEnd)
  {
    leftChillren = find_preorder(start, leftEnd);
  }
  output.insert(output.end(), leftChillren.begin(), leftChillren.end());
  output.insert(output.end(), rightChillren.begin(), rightChillren.end());
  return output;
}

int main()
{
  // freopen("../input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> inorder[i];
    inorder_position[inorder[i]] = i;
  }
  for (int i = 0; i < n; i++)
  {
    int node;
    cin >> node;
    postorder.push(node);
  }
  vector<int> answer = find_preorder(0, n - 1);
  for (auto number : answer)
    cout << number << ' ';
  return 0;
}