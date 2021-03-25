function solution(n, results) {
  var answer = 0;
  // [parent, child] count
  const count = Array.from(Array(n + 1), () => [0, 0]);
  const graph = Array.from(Array(n + 1), () => []);
  results.forEach(([win, lose]) => {
    graph[win].push(lose);
  });
  const check = Array(n + 1).fill(false);
  for (let i = 1; i <= n; i++) {
    const children = new Set();
    const stack = [];
    stack.push(...graph[i]);
    while (stack.length > 0) {
      const cur = stack.pop();
      if (children.has(cur)) continue;
      count[cur][0]++;
      children.add(cur);
      for (const child of graph[cur]) {
        stack.push(child);
      }
    }
    count[i][1] = children.size;
  }
  return count.reduce((acc, cur) => {
    const [parent, child] = cur;
    if (parent + child === n - 1) return acc + 1;
    return acc;
  }, 0);
}
