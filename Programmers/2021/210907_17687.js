function changeNum(num, n, memo) {
  let result = ''
  if (num === 0) return '0'
  while (num) {
    result = memo[(num % n)] + result;
    num = Math.floor(num / n);
  }
  return result
}

function solution(n, t, m, p) {
  const memo = Array.from(({ length: n }), (v, idx) => idx < 10 ? idx : String.fromCharCode(65 + idx - 10))
  let gameStr = ''
  let curNum = 0;
  while (gameStr.length < t * m) {
    gameStr += changeNum(curNum, n, memo)
    curNum++;
  }
  return [...gameStr].filter((v, i) => i % m === p - 1).join('').slice(0, t)
}

/*
// NOTE: 더 좋은 풀이법
function solution(n, t, m, p) {
    var tubeT = Array.apply(null,Array(t)).map((a,i)=>i*m+p-1);
    var line = '';
    var max = m*t + p;
    for (var i =0;line.length <= max; i++) {
        line += i.toString(n); // n진법으로 변환시켜준다.
    }
    return tubeT.map(a=>line[a]).join('').toUpperCase();
}
*/