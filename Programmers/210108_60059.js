function countLockHole(lock) {
  let cnt = 0;
  lock.forEach((row) => {
    row.forEach((val) => {
      if (val === 0) cnt++;
    });
  });
  return cnt;
}

function rotateKey(key, step) {
  const keySize = key.length;
  const result = Array.from(Array(keySize), () => Array(keySize).fill(null));
  if (step === 1) {
    for (let i = 0; i < keySize; i++) {
      for (let j = 0; j < keySize; j++) {
        result[i][j] = key[keySize - j - 1][i];
      }
    }
  } else if (step === 2) {
    for (let i = 0; i < keySize; i++) {
      for (let j = 0; j < keySize; j++) {
        result[i][j] = key[keySize - i - 1][keySize - j - 1];
      }
    }
  } else if (step === 3) {
    for (let i = 0; i < keySize; i++) {
      for (let j = 0; j < keySize; j++) {
        result[i][j] = key[j][keySize - i - 1];
      }
    }
  }
  return result;
}

function unLock(rowEnd, colEnd, key, lock, lockHoleCnt) {
  const keySize = key.length - 1;
  const lockSize = lock.length - 1;
  let matchCnt = 0;
  let compCnt = 0;
  for (let i = 0; i <= keySize; i++) {
    for (let j = 0; j <= keySize; j++) {
      const lockRow = rowEnd - i;
      const lockCol = colEnd - j;
      if (
        lockRow < 0 ||
        lockCol < 0 ||
        lockRow > lockSize ||
        lockCol > lockSize
      )
        continue;
      const keyHole = key[keySize - i][keySize - j];
      const lockHole = lock[lockRow][lockCol];
      if (keyHole + lockHole !== 1) {
        return false;
      } else if (lockHole === 0) {
        matchCnt++;
      }
    }
  }
  if (matchCnt === lockHoleCnt) return true;
  return false;
}

function solution(key, lock) {
  const keySize = key.length;
  const lockSize = lock.length;
  const lockHoleCnt = countLockHole(lock);
  const key1 = rotateKey(key, 1);
  const key2 = rotateKey(key, 2);
  const key3 = rotateKey(key, 3);
  for (let row = 0; row < lockSize + keySize - 1; row++) {
    for (let col = 0; col < lockSize + keySize - 1; col++) {
      const rotate0 = unLock(row, col, key, lock, lockHoleCnt);
      const rotate1 = unLock(row, col, key1, lock, lockHoleCnt);
      const rotate2 = unLock(row, col, key2, lock, lockHoleCnt);
      const rotate3 = unLock(row, col, key3, lock, lockHoleCnt);
      if (rotate0 || rotate1 || rotate2 || rotate3) {
        return true;
      }
    }
  }
  return false;
}
