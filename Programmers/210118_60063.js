function solution(board) {
  var answer = 0;
  const que = [];
  let queIdx = 0;
  const len = board.length;
  const check = Array.from(Array(len), () =>
    Array.from(Array(len), () => Array(2).fill(false))
  );
  const mx = [0, 0, 1, -1];
  const my = [1, -1, 0, 0];
  const rotateRow = [
    [0, -1],
    [1, -1],
    [1, 0],
    [0, 0],
  ];
  const rotateCheckRow = [
    [1, -1],
    [0, -1],
    [0, 1],
    [1, 1],
  ];
  const rotateCol = [
    [0, 0],
    [-1, 0],
    [-1, 1],
    [0, 1],
  ];
  const rotateCheckCol = [
    [1, 1],
    [-1, 1],
    [-1, 0],
    [1, 0],
  ];
  function outBoard(x, y) {
    if (x < 0 || x >= len || y < 0 || y >= len) return true;
    return false;
  }
  function canMove([x, y, s]) {
    let x2, y2;
    if (s === 0) {
      x2 = x + 1;
      y2 = y;
    } else {
      x2 = x;
      y2 = y + 1;
    }

    if (outBoard(x, y) || outBoard(x2, y2)) return false;
    if (check[y][x][s]) return false;
    check[y][x][s] = true;
    if (board[y][x] === 0 && board[y2][x2] === 0) return true;
    return false;
  }

  que.push([0, 0, 0]);
  que.push([-1, -1, -1]);
  check[0][0][0] = true;
  // x, y, status
  while (queIdx < que.length) {
    const [curX, curY, curS] = que[queIdx++];
    if (curS === 0 && curX === len - 2 && curY === len - 1) {
      return answer;
    } else if (curS === 1 && curX === len - 1 && curY === len - 2) {
      return answer;
    }
    if (curX === -1) {
      if (queIdx === que.length) return -1;
      answer++;
      que.push([-1, -1, -1]);
      continue;
    }
    for (let i = 0; i < 4; i++) {
      const next = [curX + mx[i], curY + my[i], curS];
      if (canMove(next)) {
        que.push(next);
      }
    }
    for (let i = 0; i < 4; i++) {
      let checkX, checkY, nextX, nextY, nextS;
      if (curS === 0) {
        [checkX, checkY] = rotateCheckRow[i];
        [nextX, nextY] = rotateRow[i];
        nextS = 1;
      } else {
        [checkX, checkY] = rotateCheckCol[i];
        [nextX, nextY] = rotateCol[i];
        nextS = 0;
      }
      checkX += curX;
      checkY += curY;
      nextX += curX;
      nextY += curY;

      if (
        !outBoard(checkX, checkY) &&
        board[checkY][checkX] === 0 &&
        canMove([nextX, nextY, nextS])
      ) {
        que.push([nextX, nextY, nextS]);
      }
    }
  }
  return answer;
}
