function playerInfo(number, weights, str) {
  let totalGame = 0
  let winCount = 0
  let winOverWeight = 0
  for (let i = 0; i < str.length; ++i) {
    if (str[i] === 'N') continue;
    if (str[i] === 'W') {
      winCount++;
      if (weights[number] < weights[i]) {
        winOverWeight++;
      }
    }
    totalGame++;
  }
  return {
    number,
    weight: weights[number],
    winRate: totalGame === 0 ? 0 : winCount / totalGame,
    winOverWeight
  }
}

function solution(weights, head2head) {
  return head2head
    .map((str, number) => playerInfo(number, weights, str))
    .sort((a, b) => {
      if (a.winRate !== b.winRate) {
        return b.winRate - a.winRate;
      }
      if (a.winOverWeight !== b.winOverWeight) {
        return b.winOverWeight - a.winOverWeight;
      }
      if (a.weight !== b.weight) {
        return b.weight - a.weight
      }
      return a.number - b.number
    })
    .map(({ number }) => number + 1)
}