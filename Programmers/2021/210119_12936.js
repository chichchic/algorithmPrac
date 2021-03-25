function factorial(n) {
  if (n == 2) return 2;
  return n * factorial(n - 1);
}

function solution(n, k) {
  let answer = [];
  let now = n - 1;
  let bundle = factorial(now);
  const numCard = Array.from(Array(n), (_, idx) => idx + 1);
  while (now > 0) {
    const cursor = Math.floor((k - 1) / bundle);
    k %= bundle;
    if (k === 0) k = bundle;
    answer.push(numCard[cursor]);
    numCard.splice(cursor, 1);
    bundle /= now;
    now--;
  }
  answer.push(...numCard);
  return answer;
}
