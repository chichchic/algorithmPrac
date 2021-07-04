function comp(a, b) {
  if(a === b) {
      return 0;
  }
  if(a+b < b+a) {
      return 1
  }
  return -1;
}

function solution(numbers) {
  const answer = numbers.map(val => '' + val).sort(comp).join('');
  return answer[0] === '0' ? '0' : answer
}