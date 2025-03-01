function solution(n, k, cmd) {
    var answer = new Array(n).fill('O');
    let selected = k + 1;
    const up = [...new Array(n + 2)].map((_, i) => i - 1);
    const down = [...new Array(n + 2)].map((_, i) => i + 1);
    const deleted = [];
    for (const command of cmd){
        const [action, value] = command.split(' ');
        if (action === 'D'){
            for (let i = 0; i < parseInt(value); i++){
                selected = down[selected];
            }
        } else if (action === 'U'){
            for (let i = 0; i < parseInt(value); i++){
                selected = up[selected];
            }
        } else if (action === 'C'){ // 삭제
            deleted.push(selected);
            up[down[selected]] = up[selected];
            down[up[selected]] = down[selected];
            selected = n < down[selected] ? up[selected]: down[selected];
        } else { // 복구
            if (deleted.length !== 0){
                const idx = deleted.pop();
                up[down[idx]] = idx;
                down[up[idx]] = idx;
            }
        }
    }
    for (const del of deleted){
        answer[del - 1] = 'X';
    }
    return answer.join('');
}