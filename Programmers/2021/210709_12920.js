// 참고: https://comyoung.tistory.com/161

function solution(n, cores) {
  const min = Math.min(...cores);
  if(n <= cores.length) return n;
  let start = n / cores.length * min;
  let end = n * min;
  while(true) {
      const mid = Math.floor((start + end) / 2);
      let cnt = cores.length;
      let currentCnt = 0;
      for(const core of cores) {
          cnt += Math.floor(mid / core);
          if(mid % core === 0) {
              --cnt;
              ++currentCnt;
          }
      }
      if(cnt >= n) {
          end = mid - 1;
      } else if(cnt + currentCnt < n) {
          start = mid + 1;
      } else {
          for(const index in cores) {
              if(mid % cores[index] === 0) {
                  ++cnt;
              }
              if(n === cnt) {
                  return Number(index) + 1;
              }
          }
      }
  }
}