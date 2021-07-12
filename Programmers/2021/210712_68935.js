function solution(n) {
  let trit = '';
  while(n) {
      trit += n % 3;
      n = Math.floor(n / 3);
  }
  let result = 0;
  let placeValue = 1;
  for(let i = trit.length - 1; i >= 0; --i) {
      result += placeValue * parseInt(trit[i]);
      placeValue *= 3;
  }
  return result
}