function getIntersectionPoint([a, b, e], [c, d, f]) {
  if ((a * d - b * c) === 0) return [0.1, 0.1] // trash value
  const x = (b * f - e * d) / (a * d - b * c);
  const y = (e * c - a * f) / (a * d - b * c);
  return [x, y];
}

function isInteger(num) {
  return num % 1 == 0
}

function solution(line) {
  const points = []
  const MAX = 1000000000000000;
  let minX = MAX, minY = MAX, maxX = -MAX, maxY = -MAX;
  for (let i = 0; i < line.length; i++) {
    for (let j = i + 1; j < line.length; j++) {
      let [x, y] = getIntersectionPoint(line[i], line[j])
      if (isInteger(x) && isInteger(y)) {
        points.push([x, y]);
        minX = Math.min(minX, x);
        minY = Math.min(minY, y);
        maxX = Math.max(maxX, x);
        maxY = Math.max(maxY, y);
      }
    }
  }
  const answer = [];
  for (let j = maxY; j >= minY; j--) {
    const line = [];
    for (let i = minX; i <= maxX; i++) {
      if (points.findIndex((v) => v[0] == i && v[1] == j) >= 0) {
        line.push('*');
      } else {
        line.push('.');
      }
    }
    answer.push(line.join(''))
  }
  return answer
}

console.log(solution([[2, -1, 4], [-2, -1, 4], [0, -1, 1], [5, -8, -12], [5, 8, 12]]))