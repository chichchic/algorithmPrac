function solution(n, edge) {
  const tree = Array.from(Array(n + 1), () => Array());
  const check = Array(n + 1).fill(false);
  edge.forEach(([a, b]) => {
    tree[a].push(b);
    tree[b].push(a);
  });
  const queue = [];
  queue.push(1);
  check[1] = true;
  queue.push(-1);
  let queIdx = 0;
  let answer = 0;
  while (queIdx < queue.length) {
    const cur = queue[queIdx++];
    if (cur < 0) {
      if (queIdx >= queue.length) break;
      queue.push(-1);
      answer = 0;
      continue;
    }
    answer++;
    for (let i = 0; i < tree[cur].length; i++) {
      const next = tree[cur][i];
      if (!check[next]) {
        check[next] = true;
        queue.push(next);
      }
    }
  }
  return answer;
}
