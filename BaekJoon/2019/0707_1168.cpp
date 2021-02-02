//TODO: 틀렸습니다.
// 재채점 - 시간초과

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

typedef pair<int, int> pii;

using namespace std;

int init(vector<int> &a, vector<pii> &tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = make_pair(1, a[start]);
        return tree[node].first;
    }
    else
    {
        tree[node] = make_pair(init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end), -1);
        return tree[node].first;
    }
}

void update(vector<pii> &tree, int node, int start, int end, int index)
{
    if (index < start || index > end)
        return;
    tree[node].first -= 1;
    if (tree[node] == 1)
    {
        //TODO:한개 남았을 경우 두 자식중 살아있는 애를 대체함
        return
    }
    if (start != end)
    {
        update(tree, node * 2, start, (start + end) / 2, index);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index);
    }
}

//TODO: 위에서부터 찾는 행동을 반복하도록 함(재귀)
//TODO: 나머지 연산을 통해서 반복적으로 찾을 필요 없도록 할수 있을듯함
void find(vector<pii> &tree, int cnt) {}
int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    int h = (int)ceil(log2(n));
    vector<pii> tree(1 << (h + 1));
    return 0;
}
