function solution(stones, k) {
  let answer = 0;
  const len = stones.length;
  function canGo(limit) {
    let cnt = 0;
    for (let i = 0; i < len; i++) {
      if (stones[i] < limit) cnt++;
      else cnt = 0;
      if (cnt >= k) return false;
    }
    return true;
  }

  let start = 0;
  let end = 200000000;

  while (start + 1 < end) {
    let mid = Math.floor((start + end) / 2);
    if (canGo(mid)) {
      answer = Math.max(answer, mid);
      start = mid;
    } else {
      end = mid;
    }
  }
  return answer;
}
