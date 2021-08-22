function solution(price, money, count) {
  let acc = 0
  for (let i = 1; i <= count; ++i) {
    acc += i;
  }
  const answer = (acc * price) - money
  return answer <= 0 ? 0 : answer;
}