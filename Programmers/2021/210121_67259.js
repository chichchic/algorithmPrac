function solution(board) {
  var answer = 0;
  const len = board.length;
  const cost = Array.from(Array(len), () => Array(len).fill([Infinity, -1]));
  cost[0][0] = [0, -1];
  // 0 = horizontal, 1 = vertical

  const mx = [1, -1, 0, 0];
  const my = [0, 0, 1, -1];

  const queue = [];
  let queIdx = 0;
  queue.push([0, 0]);

  function makeRoad(nextX, nextY, preDir, dir, budget) {
    if (nextX < 0 || nextY < 0 || nextX >= len || nextY >= len) return;
    if (board[nextX][nextY] === 1) return;
    if ((preDir === 1 && dir === 0) || (preDir === 0 && dir === 1)) {
      budget += 600;
    } else {
      budget += 100;
    }
    if (cost[nextX][nextY][0] < budget) return;
    if (cost[nextX][nextY][0] === budget) {
      if (cost[nextX][nextY][1] === dir || cost[nextX][nextY][1] === -1) return;
      cost[nextX][nextY][1] = -1;
    } else {
      cost[nextX][nextY] = [budget, dir];
    }
    queue.push([nextX, nextY]);
  }

  while (queue.length > queIdx) {
    const [curX, curY] = queue[queIdx++];
    const [budget, dir] = cost[curX][curY];

    for (let i = 0; i < 2; i++) {
      makeRoad(curX + mx[i], curY + my[i], dir, 1, budget);
    }
    for (let i = 2; i < 4; i++) {
      makeRoad(curX + mx[i], curY + my[i], dir, 0, budget);
    }
  }
  return cost[len - 1][len - 1][0];
}
