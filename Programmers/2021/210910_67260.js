function solution(n, path, order) {
  const tree = path.reduce((acc, cur) => {
    const [a, b] = cur;
    if (acc[a] === undefined) acc[a] = [];
    if (acc[b] === undefined) acc[b] = [];
    acc[a].push(b);
    acc[b].push(a);
    return acc;
  }, {})
  const needKey = order.reduce((acc, cur) => {
    const [key, room] = cur;
    acc[room] = key;
    return acc;
  }, {})
  const isKey = order.reduce((acc, cur) => {
    const [key, room] = cur;
    acc[key] = room;
    return acc;
  }, {})
  const visited = Array(n).fill(false);
  const que = [0];
  visited[0] = true;
  let visitCnt = 0;
  let queIdx = 0;
  while (que.length > queIdx) {
    const cur = que[queIdx++];
    visited[cur] = true;
    if (needKey[cur] !== undefined) {
      const key = needKey[cur];
      if (!visited[key]) {
        continue;
      }
    }
    if (isKey[cur] !== undefined) {
      const room = isKey[cur];
      if (visited[room]) {
        que.push(room);
      }
    }
    visitCnt++;
    const children = tree[cur] ? tree[cur] : [];
    for (let i = 0; i < children.length; ++i) {
      const next = children[i];
      if (!visited[next])
        que.push(next)
    }
  }
  return visitCnt === n
}