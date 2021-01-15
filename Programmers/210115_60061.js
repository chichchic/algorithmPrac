function canBuildCol(x, y, building) {
  if (y === 0) return true;
  if (building[x][y - 1][0]) return true;
  if (building[x][y][1] || (x >= 1 && building[x - 1][y][1])) return true;
  return false;
}

function canBuildRow(x, y, building) {
  if (building[x][y - 1][0] || building[x + 1][y - 1][0]) return true;
  if (building[x + 1][y][1] && x >= 1 && building[x - 1][y][1]) return true;
  return false;
}

function RemoveCol(x, y, building, n) {
  building[x][y][0] = false;
  // for(let i = 0; i <= n; i++) {
  //     for(let j = 0; j <= n; j++) {
  //         if(building[i][j][0] && !canBuildCol(i,j,building)) {
  //             building[x][y][0] = true;
  //             return
  //         }
  //         if(building[i][j][1] && !canBuildRow(i,j,building)) {
  //             building[x][y][0] = true;
  //             return
  //         }
  //     }
  // }
  if (building[x][y + 1][0] && !canBuildCol(x, y + 1, building)) {
    building[x][y][0] = true;
  }
  if (
    x > 0 &&
    building[x - 1][y + 1][1] &&
    !canBuildRow(x - 1, y + 1, building)
  ) {
    building[x][y][0] = true;
  }
  if (building[x][y + 1][1] && !canBuildRow(x, y + 1, building)) {
    building[x][y][0] = true;
  }
}

function RemoveRow(x, y, building, n) {
  building[x][y][1] = false;
  // for(let i = 0; i <= n; i++) {
  //     for(let j = 0; j <= n; j++) {
  //         if(building[i][j][0] && !canBuildCol(i,j,building)) {
  //             building[x][y][1] = true;
  //             return
  //         }
  //         if(building[i][j][1] && !canBuildRow(i,j,building)) {
  //             building[x][y][1] = true;
  //             return
  //         }
  //     }
  // }
  if (building[x][y][0] && !canBuildCol(x, y, building)) {
    building[x][y][1] = true;
  }
  if (building[x + 1][y][0] && !canBuildCol(x + 1, y, building)) {
    building[x][y][1] = true;
  }
  if (x > 0 && building[x - 1][y][1] && !canBuildRow(x - 1, y, building)) {
    building[x][y][1] = true;
  }
  if (building[x + 1][y][1] && !canBuildRow(x + 1, y, building)) {
    building[x][y][1] = true;
  }
}

function solution(n, build_frame) {
  var answer = [];
  const building = Array.from(Array(n + 2), () =>
    Array.from(Array(n + 2), () => [false, false])
  );
  for (const [x, y, kind, action] of build_frame) {
    if (action === 1) {
      if (kind === 0) {
        if (canBuildCol(x, y, building)) {
          building[x][y][0] = true;
        }
      } else {
        if (canBuildRow(x, y, building)) {
          building[x][y][1] = true;
        }
      }
    } else {
      if (kind === 0) {
        RemoveCol(x, y, building, n);
      } else {
        RemoveRow(x, y, building, n);
      }
    }
  }
  for (let i = 0; i <= n; i++) {
    for (let j = 0; j <= n; j++) {
      for (let kind = 0; kind < 2; kind++) {
        if (building[i][j][kind]) answer.push([i, j, kind]);
      }
    }
  }
  return answer;
}
