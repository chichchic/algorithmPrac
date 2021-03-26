function solution(orders, course) {
  const candidate = {};
  course.forEach((val) => {
    candidate[val] = {};
  });
  function makeCourse(order, index, cur) {
    for (let i = index; i < order.length; i++) {
      const curCourse = [...(cur + order[i])].sort().join("");
      const len = curCourse.length;
      if (course.findIndex((val) => val === len) >= 0) {
        if (!candidate[len][curCourse]) {
          candidate[len][curCourse] = 1;
        } else {
          candidate[len][curCourse]++;
        }
      }
      makeCourse(order, i + 1, curCourse);
    }
  }
  orders.forEach((val) => {
    makeCourse(val, 0, "");
  });

  const answer = [];
  for (const key in candidate) {
    let bestCount = 0;
    for (const candidateCourse in candidate[key]) {
      bestCount = Math.max(bestCount, candidate[key][candidateCourse]);
    }
    if (bestCount < 2) {
      continue;
    }
    for (const candidateCourse in candidate[key]) {
      if (candidate[key][candidateCourse] === bestCount) {
        answer.push(candidateCourse);
      }
    }
  }
  console.log(answer);
  return answer.sort();
}

// 조금 더 빠르게 개선
/*
function solution(orders, course) {
    const candidate = {};
    const candidateCount = {}
    course.forEach(val => {
        candidate[val] = {}
        candidateCount[val] = 0
    })
    orders = orders.map(val => {
        return [...val].sort().join('')
    })
    function makeCourse(order, index, cur) {
        for(let i = index; i < order.length; i++) {
            const curCourse = cur + order[i];
            const len = curCourse.length
            if(course.findIndex(val => val === len) >= 0) {
                if(!candidate[len][curCourse]) {
                    candidate[len][curCourse] = 1
                } else {
                    candidate[len][curCourse]++
                    candidateCount[len] = Math.max(candidateCount[len], candidate[len][curCourse])
                }
            }
            makeCourse(order, i + 1, curCourse);
        }
    }

    orders.forEach(val => {
        makeCourse(val, 0, '')
    })

    const answer = [];
    for(const key in candidate) {
        for(const candidateCourse in candidate[key]) {
            if(candidate[key][candidateCourse] === candidateCount[key]) {
                answer.push(candidateCourse)
            }
        }
    }
    console.log(answer)
    return answer.sort();
}
*/
