function solution(operations) {
  var answer = [];
  operations.forEach((op) => {
    if (op[0] === "I") {
      const num = Number(op.slice(2));
      const idx = answer.findIndex((val) => num < val);
      if (idx === -1) answer.push(num);
      else answer.splice(idx, 0, num);
    } else if (op === "D 1") {
      answer.pop();
    } else if (op === "D -1") {
      answer.shift();
    }
  });
  if (answer.length === 0) return [0, 0];
  return [answer[answer.length - 1], answer[0]];
}
