function findLastDivisor(num) {
  if (num === 1) return 0;
  for (let i = 2; i * i <= num; ++i) {
    if (num % i === 0 && num / i <= 10000000) return num / i;
  }
  return 1;
}
function solution(begin, end) {
  return Array.from(({ length: end - begin + 1 }), (_, index) => findLastDivisor(begin + index));
}