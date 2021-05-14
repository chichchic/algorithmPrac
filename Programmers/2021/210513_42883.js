function solution(number, k) {
  const stack = [];
  [...number].forEach((n) => {
    while (stack.length > 0 && stack[stack.length - 1] < n && k > 0) {
      stack.pop();
      k--;
    }
    stack.push(n);
  });
  return stack.slice(0, stack.length - k).join("");
}
