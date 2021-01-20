function solution(n) {
  var answer = 0;
  function makeQuene(yPos, ruld, lurd, depth) {
    if (depth === n) {
      answer++;
      return;
    }
    for (let j = 0; j < n; j++) {
      if (yPos.findIndex((val) => val === j) >= 0) continue;
      if (ruld.findIndex((val) => val === depth + j) >= 0) continue;
      if (lurd.findIndex((val) => val === depth - j) >= 0) continue;
      yPos.push(j);
      ruld.push(depth + j);
      lurd.push(depth - j);
      makeQuene(yPos, ruld, lurd, depth + 1);
      yPos.pop();
      ruld.pop();
      lurd.pop();
    }
  }
  makeQuene([], [], [], 0);
  return answer;
}
