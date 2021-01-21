function makeMin(str) {
  return Number(str.substring(0, 2)) * 60 + Number(str.substring(3));
}

function makeTime(num) {
  let result = "";
  const hour = Math.floor(num / 60);
  const min = Math.floor(num % 60);
  let hourStr = hour === 0 ? "00" : String(hour);
  let minStr = min === 0 ? "00" : String(min);
  if (hourStr.length === 1) hourStr = "0" + hourStr;
  if (minStr.length === 1) minStr = "0" + minStr;
  return hourStr + ":" + minStr;
}
function solution(n, t, m, timetable) {
  var answer = "";
  const startShuttle = 540;
  const lastShuttle = startShuttle + (n - 1) * t;
  const shuttleTime = [];
  timetable = timetable.map((val) => {
    return makeMin(val);
  });
  timetable.sort((a, b) => a - b);
  let idx = 0;
  for (let i = 0; i < n; i++) {
    const curShuttle = startShuttle + t * i;
    let stanby = 0;
    while (stanby < m && timetable[idx + stanby] <= curShuttle) {
      stanby++;
    }
    const lastIdx = idx + stanby;
    if (curShuttle === lastShuttle) {
      if (stanby < m) {
        return makeTime(lastShuttle);
      }
      return makeTime(timetable[lastIdx - 1] - 1);
    }
    idx = lastIdx;
  }
  return makeTime(lastShuttle);
}
