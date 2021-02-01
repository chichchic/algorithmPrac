const numberPosition = {
  1: { x: 0, y: 0 },
  2: { x: 1, y: 0 },
  3: { x: 2, y: 0 },
  4: { x: 0, y: 1 },
  5: { x: 1, y: 1 },
  6: { x: 2, y: 1 },
  7: { x: 0, y: 2 },
  8: { x: 1, y: 2 },
  9: { x: 2, y: 2 },
  "*": { x: 0, y: 3 },
  0: { x: 1, y: 3 },
  "#": { x: 2, y: 3 },
};

function solution(numbers, hand) {
  var answer = "";
  let leftPosition = { ...numberPosition["*"] };
  let rightPosition = { ...numberPosition["#"] };

  function changeFingerPosition(handKind, keyPosition) {
    answer += handKind;
    if (handKind === "L") {
      leftPosition = { ...keyPosition };
    } else {
      rightPosition = { ...keyPosition };
    }
  }

  function calcPosition({ x: preX, y: preY }, { x, y }) {
    return Math.abs(preX - x) + Math.abs(preY - y);
  }

  function move(keyNum) {
    const keyPosition = numberPosition[keyNum];
    if (keyNum % 3 === 1) {
      changeFingerPosition("L", keyPosition);
    } else if (keyNum > 0 && keyNum % 3 === 0) {
      changeFingerPosition("R", keyPosition);
    } else {
      const leftLen = calcPosition(leftPosition, keyPosition);
      const rightLen = calcPosition(rightPosition, keyPosition);
      if (leftLen > rightLen) {
        changeFingerPosition("R", keyPosition);
      } else if (leftLen < rightLen) {
        changeFingerPosition("L", keyPosition);
      } else {
        if (hand === "right") {
          changeFingerPosition("R", keyPosition);
        } else {
          changeFingerPosition("L", keyPosition);
        }
      }
    }
  }

  numbers.forEach((val) => move(val));
  return answer;
}
