function isInbound(r, c) {
  return r >= 0 && r < 4 && c >= 0 && c < 4;
}

function makeCardIndex(board) {
  const result = {};
  for(let r = 0; r < 4; ++r) {
      for(let c = 0; c < 4; ++c) {
          if(board[r][c] !== 0) {
              const curNum = board[r][c];
              if(!result[curNum]) {
                  result[curNum] = [];
              }
              result[curNum].push({r, c})
          }
      }
  }
  return result
}

function nextPermutaion(keys) {
  const size = keys.length;
  if(size <= 1) {
      return false;
  }
  let i = size - 1;
  for(; i > 0; i--) {
      if(keys[i] > keys[i-1]) {
          break;
      }
  }
  if(i === 0) {
      return false;
  }
  let targetNum = keys[i - 1];
  let j = size - 1;
  while(j >= 0 && keys[j] <= targetNum) {
      j--;
  }
  keys[i - 1] = keys[j];
  keys[j] = targetNum;
  const forward = keys.slice(0, i);
  const backward = keys.slice(i, size).reverse();
  return forward.concat(backward);
}

function selectcard(board, r, c, cardR, cardC) {
  let moveCount = 0;
  let queIndex = 0;
  const que = [[r, c], [-1, -1]];
  const move = [[1, 0], [0, 1], [-1, 0], [0, -1]];
  const check = Array.from(Array(4), () => new Array(4).fill(false))
  check[r][c] = true;
  while(que.length > queIndex) {
      const [curR, curC] = que[queIndex++];
      if(curR === -1) {
          ++moveCount;
          que.push([-1, -1]);
          continue;
      }
      if(curR === cardR && curC === cardC) {
          break;
      }
      move.forEach(([mr, mc]) => {
          let nextC = curC + mc;
          let nextR = curR + mr;
          if(!isInbound(nextR, nextC)) {
              return;
          }
          if(!check[nextR][nextC]) {
              check[nextR][nextC] = true;
              que.push([nextR, nextC]);
          }
          while(isInbound(nextC + mc, nextR + mr) && board[nextR][nextC] === 0) {
              nextC = nextC + mc;
              nextR = nextR + mr;
          }
          if(!check[nextR][nextC]) {
              check[nextR][nextC] = true;
              que.push([nextR, nextC]);
          }
      })
  }
  return moveCount + 1;
}

let answer = Infinity;

function remove(board, cards, cardsPos, depth, r, c, acc) {
  if(depth >= cards.length) {
      answer = Math.min(acc, answer);
      return;
  }
  const index = cards[depth];
  const [first, second] = cardsPos[index];
  const preFirst =
        selectcard(board, r, c, first.r, first.c)
      + selectcard(board, first.r, first.c, second.r, second.c);
  board[first.r][first.c] = 0;
  board[second.r][second.c] = 0;
  remove(board, cards, cardsPos, depth + 1, second.r, second.c, acc + preFirst);
  board[first.r][first.c] = cards[index];
  board[second.r][second.c] = cards[index];
  const preSecond =
        selectcard(board, r, c, second.r, second.c)
      + selectcard(board, second.r, second.c, first.r, first.c);
  board[first.r][first.c] = 0;
  board[second.r][second.c] = 0;
  remove(board, cards, cardsPos, depth + 1, first.r, first.c, acc + preSecond);
  board[first.r][first.c] = cards[index];
  board[second.r][second.c] = cards[index];
}

function solution(board, r, c) {
  const cardsPos = makeCardIndex(board);
  let cards = Object.keys(cardsPos).sort((a, b) => a - b);
  while(cards) {
      remove(board, cards, cardsPos, 0, r, c, 0);
      cards = nextPermutaion(cards)
  }
  return answer;
}