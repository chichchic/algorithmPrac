function solution(progresses, speeds) {
  const due = progresses.map((val, idx) => Math.ceil((100-val) / speeds[idx]));
  let prev = due[0];
  let index = 0;
  const answer = [1];
  for(let i = 1; i < due.length; ++i) {
      if(prev >= due[i]) {
          ++answer[index];
      } else {
          ++index;
          answer[index] = 1;
          prev = due[i];
      }
  }
  return answer;
}