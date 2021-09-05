function dropBlock(m, n, board) {
  for (let i = 0; i < n; ++i) {
    const que = [];
    for (let j = 0; j < m; ++j) {
      if (board[j][i] !== null) {
        que.push(board[j][i]);
      }
    }
    let queIdx = 0
    for (let j = 0; j < m; ++j) {
      if (j >= m - que.length) {
        board[j][i] = que[queIdx++];
      } else {
        board[j][i] = null
      }
    }

  }
}

function solution(m, n, board) {
  for (let i = 0; i < board.length; ++i) {
    board[i] = board[i].split('')
  }

  function remove(x, y, removeArr) {
    const mx = [x + 0, x + 1, x + 1];
    const my = [y + 1, y + 0, y + 1];
    const type = board[x][y];
    for (let i = 0; i < 3; ++i) {
      if (mx[i] >= m || my[i] >= n || type !== board[mx[i]][my[i]]) {
        return;
      }
    }
    removeArr.push([x, y]);
  }
  let again = true;
  while (again) {
    again = false;
    const removeArr = []
    for (let x = 0; x < m; ++x) {
      for (let y = 0; y < n; ++y) {
        if (board[x][y] !== null) {
          remove(x, y, removeArr)
        }
      }
    }
    removeArr.forEach(([x, y]) => {
      const mx = [x + 0, x + 1, x + 1];
      const my = [y + 1, y + 0, y + 1];
      board[x][y] = null;
      for (let i = 0; i < 3; ++i) {
        if (mx[i] < m || my[i] < n) {
          board[mx[i]][my[i]] = null;
        }
      }
    })
    dropBlock(m, n, board)
    if (removeArr.length !== 0) again = true
  }

  return board.reduce((a, c) => a + c.reduce((acc, cur) => cur === null ? acc + 1 : acc, 0), 0);
}