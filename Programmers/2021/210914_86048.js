function solution(enter, leave) {
  const length = enter.length;
  const timeline = [];
  const visited = Array(length + 1).fill(false);
  let eIdx = 0, lIdx = 0;
  while (eIdx < length || lIdx < length) {
    if (eIdx < length) {
      timeline.push(enter[eIdx])
      visited[enter[eIdx]] = true;
      eIdx++;
    }
    while (lIdx < length && visited[leave[lIdx]]) {
      timeline.push(leave[lIdx]);
      lIdx++;
    }
  }
  const answer = Array.from({ length: length + 1 }, () => []);
  for (let i = 1; i <= length; i++) {
    const fIdx = timeline.indexOf(i);
    const sIdx = timeline.indexOf(i, fIdx + 1);
    answer[i].push(...timeline.slice(fIdx + 1, sIdx));
    answer[i].forEach(v => answer[v].push(i));
  }
  answer.shift();
  return answer.map(arr => {
    const set = new Set(arr)
    return set.size;
  })
}

/*
//NOTE: 더 좋은 풀이 법
const solution = (enter, leave) => {
    const ans = enter.map(() => 0), room = new Set();
    for (let i = 0, j = 0; j < enter.length; ++j) {
        const a = leave[j];
        while (!room.has(a)) {
            room.add(enter[i++]);
        }
        room.delete(a);
        for (const b of room) {
            ans[a - 1]++;
            ans[b - 1]++;
        }
    }
    return ans;
};
*/