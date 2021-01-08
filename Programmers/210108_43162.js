function solution(n, computers) {
  var answer = 0;
  const tree = Array.from(Array(n), () => Array());
  const check = {};
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      if (computers[i][j]) {
        tree[i].push(j);
        tree[j].push(i);
      }
    }
  }
  for (let i = 0; i < n; i++) {
    if (check[i]) continue;
    answer++;
    const queue = [];
    let queCur = 0;
    queue.push(i);
    while (queCur < queue.length) {
      const cur = queue[queCur++];
      for (let j = 0; j < tree[cur].length; j++) {
        const next = tree[cur][j];
        if (!check[next]) {
          check[next] = true;
          queue.push(next);
        }
      }
    }
  }
  return answer;
}
