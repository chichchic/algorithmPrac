function solution(n) {
  var answer = [];
  function hanoi(step, from, by, to) {
    if (step == 1) {
      answer.push([from, to]);
    } else {
      hanoi(step - 1, from, to, by);
      answer.push([from, to]);
      hanoi(step - 1, by, from, to);
    }
  }
  hanoi(n, 1, 2, 3);
  return answer;
}
