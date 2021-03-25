function canChange(beginIdx, endIdx, wordTree) {
  const queue = [];
  let queIdx = 0;
  const check = Array(wordTree.length).fill(false);
  check[beginIdx] = true;
  queue.push(beginIdx);
  queue.push(-1);
  let step = 1;
  while (queIdx < queue.length) {
    const cur = queue[queIdx++];
    if (cur === endIdx) {
      return step;
    }
    if (cur === -1) {
      if (queIdx >= queue.length) break;
      step++;
      queue.push(-1);
      continue;
    }
    for (let i = 0; i < wordTree[cur].length; i++) {
      const next = wordTree[cur][i];
      if (!check[next]) {
        check[next] = true;
        queue.push(next);
      }
    }
  }
  return -1;
}

function solution(begin, target, words) {
  var answer = 0;
  const wordTree = Array.from(Array(words.length), () => []);
  const wordsLen = words.length;
  const len = words[0].length;
  const targetIdx = words.findIndex((val) => val === target);
  if (targetIdx === -1) return 0;
  const memo = [];
  for (let i = 0; i < wordsLen; i++) {
    let candi = 0;
    for (let k = 0; k < len; k++) {
      if (words[i][k] !== begin[k]) candi++;
    }
    if (candi === 1) memo.push(i);
    for (let j = i + 1; j < wordsLen; j++) {
      let findDif = 0;
      for (let k = 0; k < len; k++) {
        if (words[i][k] !== words[j][k]) findDif++;
      }
      if (findDif === 1) {
        wordTree[i].push(j);
        wordTree[j].push(i);
      }
    }
  }
  for (let i = 0; i < memo.length; i++) {
    const step = canChange(memo[i], targetIdx, wordTree);
    if (step > 0) return step;
  }
  return 0;
}
