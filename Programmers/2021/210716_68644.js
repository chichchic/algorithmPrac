function solution(numbers) {
  const set = new Set()
  const len = numbers.length;
  for(let i = 0; i < len; ++i) {
      for(let j = i + 1; j < len; ++j) {
          set.add(numbers[i] + numbers[j]);
      }
  }
  return [...set].sort((a, b) => a - b);
}