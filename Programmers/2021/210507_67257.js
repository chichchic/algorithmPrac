function operate(a, operator, b) {
  if (operator === "+") {
    return a + b;
  } else if (operator === "-") {
    return a - b;
  } else if (operator === "*") {
    return a * b;
  }
}

function calc(expression, operator, depth) {
  if (depth === 3) {
    return expression[0];
  }
  let nextOperate = false;
  const nextExpression = expression.reduce((acc, cur) => {
    if (nextOperate) {
      acc[acc.length - 1] = operate(acc[acc.length - 1], operator[depth], cur);
      nextOperate = false;
    } else if (cur === operator[depth]) {
      nextOperate = true;
    } else {
      acc.push(cur);
    }
    return acc;
  }, []);
  return calc(nextExpression, operator, depth + 1);
}

function solution(expression) {
  var answer = 0;
  let number = "";
  const operators = ["-", "+", "*"];
  const expressionArr = [];
  for (let c of expression) {
    if (operators.includes(c)) {
      expressionArr.push(Number(number));
      expressionArr.push(c);
      number = "";
    } else {
      number += c;
    }
  }
  expressionArr.push(Number(number));
  const operateCase = [
    ["-", "+", "*"],
    ["-", "*", "+"],
    ["*", "+", "-"],
    ["*", "-", "+"],
    ["+", "*", "-"],
    ["+", "-", "*"],
  ];

  return Math.max(
    ...operateCase.map((val) => Math.abs(calc(expressionArr, val, 0)))
  );
}
