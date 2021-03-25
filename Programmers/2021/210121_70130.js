function solution(a) {
  var answer = 0;
  const len = a.length;
  if (len < 2) return 0;
  const num = Array.from(Array(len), (_, idx) => [idx, 0]);
  a.forEach((val) => {
    num[val][1]++;
  });
  num.sort(([_a, a], [_b, b]) => b - a);
  for (let i = 0; i < len; i++) {
    const [curNum, curCnt] = num[i];
    if (curCnt * 2 <= answer) {
      continue;
    }
    let ansCandi = 0;
    let isNum = false;
    let notNum = false;
    for (let j = 0; j < len; j++) {
      const cur = a[j];
      if (curNum === cur) {
        if (isNum) continue;
        isNum = true;
        if (isNum && notNum) {
          isNum = false;
          notNum = false;
          ansCandi += 2;
        }
      } else {
        if (notNum) continue;
        notNum = true;
        if (isNum && notNum) {
          isNum = false;
          notNum = false;
          ansCandi += 2;
        }
      }
    }
    if (answer < ansCandi) {
      answer = ansCandi;
    }
  }
  return answer;
}
