function split(str) {
  const result = []
  for (let i = 1; i < str.length; ++i) {
    const alphaPattern = /[A-Z]/
    if (!alphaPattern.test(str[i - 1]) || !alphaPattern.test(str[i])) {
      continue;
    }
    result.push(`${str[i - 1]}${str[i]}`);
  }
  return result
}

function countWord(group) {
  const result = {};
  for (const word of group) {
    if (result[word] === undefined) result[word] = 0
    ++result[word];
  }
  return result
}

function countIntersection(g1, g2) {
  let result = 0;
  for (const word in g1) {
    if (g2[word] !== undefined) {
      result += Math.min(g1[word], g2[word]);
    }
  }
  return result
}

function countUnion(g1, g2) {
  let result = 0;
  let union = { ...g1 }
  for (const word in g2) {
    if (g1[word] !== undefined) {
      union[word] = Math.max(g2[word], g1[word])
    } else {
      union[word] = g2[word]
    }
  }
  for (const word in union) {
    result += union[word]
  }
  return result
}

function solution(str1, str2) {
  str1 = str1.toUpperCase()
  str2 = str2.toUpperCase()
  const group1 = countWord(split(str1))
  const group2 = countWord(split(str2))
  const inter = countIntersection(group1, group2);
  const union = countUnion(group1, group2);
  if (union === 0) return 65536
  return Math.floor((inter / union) * 65536)
}