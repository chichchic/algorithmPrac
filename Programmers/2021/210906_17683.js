function timeToMin(time) {
  const [hour, min] = time.split(':')
  return parseInt(hour) * 60 + parseInt(min);
}

function splitSheet(sheet) {
  const result = [];
  for (let i = 0; i < sheet.length; ++i) {
    if (i + 1 < sheet.length && sheet[i + 1] === '#') {
      result.push(sheet[i] + sheet[i + 1])
      i++;
    } else {
      result.push(sheet[i])
    }
  }
  return result;
}

function includes(sheet, m) {
  for (let i = 0; i < sheet.length; ++i) {
    let find = true
    for (let j = 0; j < m.length; ++j) {
      if (sheet[i + j] == m[j]) continue;
      find = false;
      break;
    }
    if (find) return true;
  }
  return false;
}

function solution(m, musicinfos) {
  var answer = '(None)';
  let curPlayTime = 0;
  for (const info of musicinfos) {
    const [start, end, name, sheet] = info.split(',')
    const playTime = timeToMin(end) - timeToMin(start)
    let sheetArr = splitSheet(sheet)
    while (sheetArr.length < playTime) {
      sheetArr = sheetArr.concat(sheetArr)
    }
    sheetArr = sheetArr.slice(0, playTime)
    if (includes(sheetArr, splitSheet(m)) && playTime > curPlayTime) {
      answer = name;
      curPlayTime = playTime
    }
  }
  return answer;
}