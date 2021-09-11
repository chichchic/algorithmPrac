// 참조: https://velog.io/@longroadhome/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-LV.3-%EC%B6%94%EC%84%9D-%ED%8A%B8%EB%9E%98%ED%94%BD-JS
function makeMilSec(str) {
  const [date, time, processTime] = str.split(' ');
  const [h, m, s] = time.split(':').map(v => Number(v))
  const processMilSec = processTime.slice(0, processTime.length - 1);
  return [(h * 60 * 60 * 1000) + (m * 60 * 1000) + (s * 1000), Number(processMilSec) * 1000]
}

function solution(lines) {
  let answer = 0;
  const timeLine =
    lines
      .map((str) => makeMilSec(str))
      .map(([end, process]) => [end - process + 1, end + 999])
  const times = timeLine.reduce((acc, cur) => {
    const [start, end] = cur;
    acc.push([start, 'S']);
    acc.push([end, 'E']);
    return acc;
  }, []).sort((a, b) => a[0] === b[0] ? -1 : a[0] - b[0]);

  let cnt = 0;
  for (const [time, type] of times) {
    if (type === 'S') cnt++
    else cnt--;
    answer = Math.max(answer, cnt);
  }
  return answer;
}