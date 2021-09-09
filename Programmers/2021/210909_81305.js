//참고: https://degurii.tistory.com/231

function solution(k, num, links) {
    const length = num.length
    const tree = links.reduce((acc, cur, idx) => {
        const [left, right] = cur;
        acc[idx] = { left, right, cost: num[idx] }
        return acc;
    }, {})
    const root = links.reduce((acc, cur) => {
        const [left, right] = cur;
        if (left > 0) acc -= left;
        if (right > 0) acc -= right;
        return acc
    }, length * (length - 1) / 2)
    function split(limit) {
        const stack = [root];
        const returnValue = {
            '-1': {
                cost: 0,
                cnt: 0
            }
        }
        stack.back = function () { return this[this.length - 1]; };
        while (stack.length) {
            const now = stack.back();
            const { cost, left, right } = tree[now];
            const leftValue = returnValue[left];
            const rightValue = returnValue[right];
            if (!leftValue) {
                stack.push(left)
                continue;
            }
            if (!rightValue) {
                stack.push(right);
                continue;
            }
            stack.pop();
            returnValue[now] = {
                cost,
                cnt: returnValue[left].cnt + returnValue[right].cnt
            }
            const rv = returnValue[now];
            if (rv.cost + leftValue.cost + rightValue.cost <= limit) {
                rv.cost = rv.cost + leftValue.cost + rightValue.cost
            } else if (rv.cost + leftValue.cost <= limit || rv.cost + rightValue.cost <= limit) {
                rv.cost = Math.min(rv.cost + leftValue.cost, rv.cost + rightValue.cost)
                rv.cnt += 1;
            } else {
                rv.cnt += 2;
            }
        }
        return returnValue[root]
    }
    function bianrySearch() {
        let s = Math.max(...num), e = length * 10001;
        let answer = e;
        while (s <= e) {
            const mid = Math.floor((s + e) / 2);
            const { cnt, cost } = split(mid);
            if (cnt <= k - 1) {
                e = mid - 1;
                answer = Math.min(answer, mid);
            } else {
                s = mid + 1;
            }
        }
        return answer;
    }
    return bianrySearch()
}