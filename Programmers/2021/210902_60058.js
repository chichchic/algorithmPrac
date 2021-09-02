function splitBalanced(str) {
  let left = 0
  let right = 0
  for (let idx = 0; idx < str.length; ++idx) {
    const c = str[idx];
    if (c === '(') left++;
    else right++;
    if (left !== 0 && left === right) {
      return [str.slice(0, idx + 1), str.slice(idx + 1)]
    }
  }
  return [str, '']

}

function isRight(str) {
  let cnt = 0
  for (const c of str) {
    if (c === '(') {
      cnt++;
    } else if (cnt <= 0) {
      return false
    } else {
      cnt--;
    }
  }
  return true
}

function deleteReverse(str) {
  const result = []
  for (let i = 1; i < str.length - 1; ++i) {
    if (str[i] === ')') result.push('(');
    else result.push(')')
  }
  return result.join('')
}

function makeRight(str) {
  if (str === '') return ''
  const [u, v] = splitBalanced(str)
  if (isRight(u)) return u + makeRight(v)
  return '(' + makeRight(v) + ')' + deleteReverse(u)
}

function solution(p) {
  return makeRight(p)
}