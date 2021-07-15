function solution(n, arr1, arr2) {
  const result = []
  for(const idx in arr1) {
      const or = arr1[idx] | arr2[idx];
      let shift = 0;
      const line = [];
      while(shift < n) {
          if(or & 1 << shift) {
              line.push('#')
          } else {
              line.push(' ')
          }
          ++shift;
      }
      result.push(line.reverse().join(''))
  }
  return result;
}