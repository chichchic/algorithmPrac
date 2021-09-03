function isCandidate(list) {
  const set = new Set(list)
  return set.size === list.length
}

function solution(relation) {
  const answerList = [];
  const que = Array.from(Array(relation[0].length), (v, i) => [i])
  let queIdx = 0;
  while (queIdx < que.length) {
    const table = Array(relation[0].length).fill(false);
    que[queIdx].forEach(v => table[v] = true);
    const list = relation.map(val => {
      return val.map((v, i) => {
        if (table[i]) return `${i}:${v}`
        else return ''
      }).join('/')
    })
    const queLast = que[queIdx][que[queIdx].length - 1]
    if (isCandidate(list)) {
      answerList.push(que[queIdx].reduce((acc, cur) => acc + (1 << cur), 0))
    }
    for (let idx = queLast + 1; idx < relation[0].length; ++idx)
      que.push([...que[queIdx], idx])
    queIdx++;
  }
  const answer = Array(answerList.length).fill(true);
  for (let i = 0; i < answerList.length; ++i) {
    if (!answer[i]) continue;
    for (let j = i + 1; j < answerList.length; ++j) {
      if ((answerList[i] | answerList[j]) === answerList[j]) answer[j] = false;
    }
  }
  return answer.filter(v => v).length
}