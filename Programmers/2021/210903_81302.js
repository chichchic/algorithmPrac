function findPosition(room) {
  const result = []
  for (let i = 0; i < 5; ++i) {
    for (let j = 0; j < 5; ++j) {
      if (room[i][j] === 'P') {
        result.push([i, j])
      }
    }
  }
  return result;
}

function isRight(room, position) {
  const mx = [0, 0, 1, -1];
  const my = [1, -1, 0, 0];
  const tables = []
  for (const [x, y] of position) {
    for (let i = 0; i < 4; ++i) {
      const nx = x + mx[i];
      const ny = y + my[i];
      if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
        if (room[nx][ny] === 'P') return 0
        if (room[nx][ny] === 'O') {
          for (let j = 0; j < 4; ++j) {
            const nx2 = nx + mx[j];
            const ny2 = ny + my[j];
            if (nx2 === x && ny2 === y) continue;
            if (nx2 >= 0 && nx2 < 5 && ny2 >= 0 && ny2 < 5) {
              if (room[nx2][ny2] === 'P') return 0
            }
          }
        }
      }
    }
  }
  return 1
}

function solution(places) {
  return places.map(place => isRight(place, findPosition(place)))
}