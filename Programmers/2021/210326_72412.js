function solution(info, query) {
  const dataBase = {};

  info.forEach((applicant) => {
    const infoArr = applicant.split(" ");
    const applicantInfo = [];
    applicantInfo[0] =
      infoArr[0] === "cpp" ? "1" : infoArr[0] === "java" ? "2" : "3"; // language
    applicantInfo[1] = infoArr[1] === "backend" ? "1" : "2"; // group
    applicantInfo[2] = infoArr[2] === "junior" ? "1" : "2"; // career
    applicantInfo[3] = infoArr[3] === "chicken" ? "1" : "2"; // food

    function makeComb(curKind, index) {
      if (dataBase[curKind]) {
        dataBase[curKind].push(infoArr[4]);
      } else {
        dataBase[curKind] = [infoArr[4]];
      }
      for (let i = index; i < 4; i++) {
        let nextKind = [...curKind];
        nextKind.splice(i, 1, "0");
        makeComb(nextKind.join(""), i + 1);
      }
    }
    const kind = applicantInfo.join("");
    makeComb(kind, 0);
  });

  for (const key in dataBase) {
    dataBase[key].sort((a, b) => b - a);
  }
  const answer = [];
  query.forEach((val) => {
    const queryArr = val.split(" ");
    let kind = [];
    const language = ["-", "cpp", "java", "python"];
    const group = ["-", "backend", "frontend"];
    const career = ["-", "junior", "senior"];
    const food = ["-", "chicken", "pizza"];

    kind[0] = language.findIndex((val) => val === queryArr[0]);
    kind[1] = group.findIndex((val) => val === queryArr[2]);
    kind[2] = career.findIndex((val) => val === queryArr[4]);
    kind[3] = food.findIndex((val) => val === queryArr[6]);

    const infoKey = kind.join("");
    if (dataBase[infoKey]) {
      let start = 0;
      let end = dataBase[infoKey].length;
      while (start < end) {
        const mid = Math.floor((start + end) / 2);
        if (dataBase[infoKey][mid] - queryArr[7] >= 0) {
          start = mid + 1;
        } else {
          end = mid;
        }
      }
      answer.push(start);
    } else {
      answer.push(0);
    }
  });
  return answer;
}
