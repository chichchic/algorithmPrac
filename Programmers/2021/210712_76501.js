function solution(absolutes, signs) {
  let answer = 0;
  for(const idx in absolutes) {
      const sign = signs[idx] ? 1 : -1;
      answer += sign * absolutes[idx];
  }
  return answer;
}