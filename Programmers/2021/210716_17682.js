function solution(dartResult) {
  var answer = 0;
  const matches = dartResult.matchAll(/([0-9]+)([S|D|T])([\*|#]?)/g);
  const bonusValue = {
      'S': 1,
      'D': 2,
      'T': 3
  }
  const scoreArr = [0];
  for(const match of matches) {
      const [_, score, bonus, option] = match;
      const curScore = Math.pow(parseInt(score), bonusValue[bonus]);
      scoreArr.push(curScore);
      const len = scoreArr.length;
      if(option === '*') {
          scoreArr[len - 2] *= 2;
          scoreArr[len - 1] *= 2;
      } else if(option === '#') {
          scoreArr[len - 1] *= -1;
      }
  }
  return scoreArr.reduce((acc, cur) => acc + cur, 0);
}