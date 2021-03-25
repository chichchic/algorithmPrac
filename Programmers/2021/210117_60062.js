function solution(n, weak, dist) {
  const worker = dist.length;
  const weakTotal = weak.length;
  let answer = weakTotal + 1;
  let weakCheck = Array(weakTotal).fill(false);
  let weakCount = 0;

  function check(depth) {
    if (weakCount === weakTotal) {
      answer = Math.min(answer, depth);
      return;
    }
    if (depth >= worker || depth >= answer) return;
    for (let i = 0; i < weakTotal; i++) {
      if (weakCheck[i]) {
        continue;
      }

      const curWeakCheck = weakCheck.slice();
      const curWeakCount = weakCount;

      let endPoint = weak[i] + dist[worker - 1 - depth];
      let startIndex = i;

      while (weak[startIndex] <= endPoint) {
        if (!weakCheck[startIndex]) {
          weakCheck[startIndex] = true;
          weakCount++;
        }
        startIndex++;
        if (startIndex >= weakTotal) {
          startIndex = 0;
          endPoint -= n;
        }
      }

      check(depth + 1);

      weakCheck = curWeakCheck;
      weakCount = curWeakCount;
    }
  }
  check(0);
  if (answer === weakTotal + 1) return -1;
  return answer;
}
