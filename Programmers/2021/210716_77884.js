function countDivisor(number) {
  const sqrt = Math.sqrt(number);
  let output = 0;
  if(number % sqrt === 0) {
      output++;
  }
  for(let i = 1; i < Math.sqrt(number); ++i ){
      if(number % i === 0) {
          output += 2;
      }
  }
  return output;
}

function solution(left, right) {
  let answer = 0;
  for(let number = left; number <= right; ++number) {
      if(countDivisor(number) % 2 === 0) {
          answer += number;
      } else {
          answer -= number;
      }
  }
  return answer;
}