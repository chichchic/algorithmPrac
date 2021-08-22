function avgScore(scores, index) {
  const indexScores = scores.map(score => score[index])
  const max = Math.max(...indexScores)
  const isOnlyMax = indexScores.filter(val => val == max).length === 1
  const min = Math.min(...indexScores)
  const isOnlyMin = indexScores.filter(val => val == min).length === 1
  let total = 0
  let count = 0
  for (const i in indexScores) {
    if (i == index &&
      (
        (isOnlyMax && max == indexScores[i]) ||
        (isOnlyMin && min == indexScores[i])
      )
    ) {
      continue
    }
    total += indexScores[i]
    ++count;
  }
  return total / count
}

function solution(scores) {
  const table = ['F', 'F', 'F', 'F', 'F', 'D', 'D', 'C', 'B', 'A', 'A']
  return scores
    .map((v, i) => table[Math.floor(avgScore(scores, i) / 10)])
    .join('')
}