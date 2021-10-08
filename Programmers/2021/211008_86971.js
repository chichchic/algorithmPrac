function solution(n, wires) {
  const tree = Array.from({ length: n + 1 }, () => []);
  const visited = new Array(n + 1).fill(false);
  const nodeInfo = new Array(n + 1).fill(1);
  const nodeParent = new Array(n + 1).fill(-1);
  for (const [p, c] of wires) {
    tree[p].push(c);
    tree[c].push(p);
  }
  const stack = [1];
  while (stack.length !== 0) {
    let doPush = false;
    const current = stack[stack.length - 1];
    for (let i = 0; i < tree[current].length; i++) {
      const next = tree[current][i];
      if (visited[next] || next === nodeParent[current]) continue;
      stack.push(next);
      nodeParent[next] = current;
      doPush = true;
    }
    if (doPush) {
      continue;
    }
    visited[current] = true;
    for (let i = 0; i < tree[current].length; i++) {
      const next = tree[current][i];
      if (next === nodeParent[current]) continue;
      nodeInfo[current] += nodeInfo[next];
    }
    stack.pop();
  }
  let answer = Infinity;
  let candidate = 1;
  while (true) {
    const remain = nodeInfo[1] - nodeInfo[candidate];
    const dif = Math.abs(remain - nodeInfo[candidate]);
    if (dif >= answer) {
      break;
    } else {
      answer = dif;
      let big = 0;
      let bigCandi = -1;
      for (let i = 0; i < tree[candidate].length; i++) {
        const next = tree[candidate][i];
        if (next === nodeParent[candidate]) continue;
        if (big < nodeInfo[next]) {
          bigCandi = next;
          big = nodeInfo[next];
        }
      }
      candidate = bigCandi;
    }
  }
  return answer;
}