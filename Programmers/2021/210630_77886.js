// 참고: https://velog.io/@longroadhome/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-LV.3-110-%EC%98%AE%EA%B8%B0%EA%B8%B0-JS
function pick_ooz(strArr) {
  const stack = [];
  let count = 0;
  for(let i = 0; i < strArr.length; ++i) {
      const third = strArr[i];
      if(stack.length < 2) {
          stack.push(third);
          continue;
      }
      const second = stack.pop();
      const first = stack.pop();
      if(first === '1' && second === '1' && third === '0') {
          ++count;
          continue;
      } else {
          stack.push(first, second, third);
      }
  }
  return { stack, count };
}

function converter(str) {
  let { stack, count } = pick_ooz([...str]);
  const zoo = ['0', '1', '1'];
  const list = [];

  while(stack.length) {
      const last = stack.pop();
      if(last === '0') {
          stack.push(last);
          break;
      }
      list.push(last);
  }

  while(count) {
      list.push(...zoo)
      --count;
  }

  while(stack.length) {
      const last = stack.pop();
      list.push(last);
  }
  return list.reverse().join('');
}

function solution(s) {
  return s.map(val => converter(val));
}