// 참고: https://yabmoons.tistory.com/625

function getTree(n, edges) {
  const tree = Array.from(new Array(n + 1), _ => []);
  edges.forEach(([p, c]) => {
      tree[p].push(c);
      tree[c].push(p);
  })
  return tree;
}
function getDepth(tree, root, n) {
  const queue = [root, -1];
  let queIdx = 0;
  let depth = 0;
  let output = [];
  const visited = new Array(n + 1).fill(false);
  visited[root] = true;
  while(queue.length > queIdx) {
      const cur = queue[queIdx++];
      if(cur < 0) {
          if(queue.length === queIdx) {
              break;
          }
          ++depth;
          output = [];
          queue.push(-1);
          continue;
      }
      output.push(cur);
      tree[cur].forEach((next) => {
          if(!visited[next]) {
              visited[next] = true;
              queue.push(next);
          }
      })
  }
  return [output, depth];
}

function solution(n, edges) {
  const tree = getTree(n, edges);
  const aNode = getDepth(tree, 1, n)[0][0];
  const [farNodesB, rB] = getDepth(tree, aNode, n);
  if(farNodesB.length > 1) {
      return rB;
  }
  const [farNodesC, rC] = getDepth(tree, farNodesB[0], n);
  if(farNodesC.length > 1) {
      return rC;
  }
  return rC - 1;
}