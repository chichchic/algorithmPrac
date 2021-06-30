function canDrop(board, x, y) {
  for(; x>=0; --x) {
      if(board[x][y] !== 0) {
          return false;
      }
  }
  return true;
}

function isPromising(board, x, y) {
  const N = board.length;
  const promiseBlock = [
      [[0,0], [1,0], [1,1], [1,2]],
      [[0,0], [1,0], [1,-1], [1,-2]],
      [[0,0], [1,0], [2,0], [2,1]],
      [[0,0], [1,0], [2,0], [2,-1]],
      [[0,0], [1,0], [1,1], [1,-1]]
  ]
  const reqBlack = [
      [[0,1], [0, 2]],
      [[0, -1], [0, -2]],
      [[1, 1]],
      [[1, -1]],
      [[0,-1], [0,1]]
  ]
  const num = board[x][y];
  for(let i = 0; i < 5; ++i) {
      let isPromise = true;
      for(let j = 0; j < 4; ++j) {
          const nx = x + promiseBlock[i][j][0];
          const ny = y + promiseBlock[i][j][1];
          if(nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny] !== num) {
              isPromise = false;
              break;
          }
      }
      if(isPromise) {
          const isBlank = reqBlack[i].filter(([mx, my]) => !canDrop(board, x + mx, y + my))
          if(isBlank.length === 0) {
              for(let j = 0; j < 4; ++j) {
                  const nx = x + promiseBlock[i][j][0];
                  const ny = y + promiseBlock[i][j][1];
                  board[nx][ny] = 0;
              }
              return true;
          }
      }
  }
  return false;
}

function canDelete(board) {
  const N = board.length;
  let removedBlock = 0;
  for(let i = 0; i < N; ++i) {
      for(let j = 0; j < N; ++j) {
          if(board[i][j] !== 0 && isPromising(board, i, j)) {
              ++removedBlock;
          }
      }
  }
  if(removedBlock > 0) {
      removedBlock += canDelete(board);
  }
  return removedBlock;
}

function solution(board) {
  return canDelete(board);
}