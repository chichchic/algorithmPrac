// 구멍, 블럭의 형태를 배열로 반환해주는 함수
function findForm(game_board, visit, x, y, type) {
    const queue = [];
    const len = game_board.length
    let queIdx = 0;
    const mx = [1,-1,0,0];
    const my = [0,0,1,-1];
    queue.push([x, y]);
    const output = [];
    while(queue.length > queIdx) {
        const [curX, curY] = queue[queIdx++];
        output.push([curX - x, curY - y]);
        for(let i = 0; i < 4; ++i) {
            const nextX = curX + mx[i];
            const nextY = curY + my[i];
            if(nextX < 0 || nextX >= len || nextY < 0 || nextY >= len || visit[nextX][nextY]) continue;
            visit[nextX][nextY] = true;
            if(game_board[nextX][nextY] === type) {
                queue.push([nextX, nextY]);
            }
        }
    }
    return output
}
// 2차원 배열 90도 회전해주는 함수
function rotate90(board) {
    const len = board.length;
    const output = Array.from(Array(len), () => Array(len))
    for(let i = 0; i < len; ++i) {
        for(let j = 0; j < len; ++j) {
            output[j][len - i - 1] = board[i][j];
        }
    }
    return output;
}
// 두가지 형태가 동일한 형태인지 확인해주는 함수
function isSame(hole, block) {
    if(hole.length !== block.length) {
        return false;
    }
    for(let i = 0; i < hole.length; i++) {
        if(hole[i][0] !== block[i][0] || hole[i][1] !== block[i][1]) {
            return false;
        }
    }
    return true;
}

function solution(game_board, table) {
    var answer = 0;
    const len = game_board.length
    const visit_board = Array.from(Array(len), () => Array(len).fill(false))
    const holes = [];
    // 구멍 형태 찾기
    for(let i = 0; i < len; ++i) {
        for(let j = 0; j < len; ++j) {
            if(!visit_board[i][j] && game_board[i][j] === 0) {
                visit_board[i][j] = true;
                const hole = findForm(game_board, visit_board, i, j, 0);
                hole.sort((a, b) => {
                    if(a[0] === b[0]) return a[1] - b[1];
                    return a[0] - b[0]
                })
                holes.push(hole)
            }
        }
    }
    const isFill = Array(holes.length).fill(false)
    for(let rotate = 0; rotate < 4; rotate++) {
        const visit_table = Array.from(Array(len), () => Array(len).fill(false))
        for(let i = 0; i < len; ++i) {
            for(let j = 0; j < len; ++j) {
                if(!visit_table[i][j] && table[i][j] === 1) {
                    visit_table[i][j] = true;
                    const block = findForm(table, visit_table, i, j, 1);
                    block.sort((a, b) => {
                        if(a[0] === b[0]) return a[1] - b[1];
                        return a[0] - b[0]
                    })
                    for(let index = 0; index < holes.length; index++) {
                        const hole = holes[index];
                        if(!isFill[index] && isSame(hole, block)) {
                            isFill[index] = true; // 채워진 구멍 제거
                            answer += block.length;
                            // 사용된 블럭 삭제
                            block.forEach(([mx, my]) => table[i+mx][j+my] = 0)
                            break;
                        }
                    }
                }
            }
        }
        table = rotate90(table)
    }
    return answer;
}