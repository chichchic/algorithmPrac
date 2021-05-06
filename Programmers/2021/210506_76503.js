function solution(a, edges) {
  if (a.reduce((acc, cur) => acc + cur, 0) !== 0) {
    return -1;
  }
  let answer = BigInt(0);
  const visited = Array(a.length - 1).fill(false);
  const tree = edges.reduce((acc, [left, right]) => {
    if (!acc[left]) {
      acc[left] = [];
    }
    if (!acc[right]) {
      acc[right] = [];
    }
    acc[left].push(right);
    acc[right].push(left);
    return acc;
  }, {});
  const stack = [[0, -1]];
  visited[0] = true;
  while (stack.length > 0) {
    const [current, parent] = stack[stack.length - 1];
    let isLeaf = true;
    tree[current].forEach((val) => {
      if (!visited[val]) {
        visited[val] = true;
        isLeaf = false;
        stack.push([val, current]);
      }
    });
    if (isLeaf) {
      stack.pop();
      if (current === 0) {
        break;
      }
      answer += BigInt(Math.abs(a[current]));
      a[parent] += a[current];
    }
  }
  return answer;
}
