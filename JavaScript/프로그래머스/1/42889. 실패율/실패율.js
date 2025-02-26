function solution(N, stages) {
    let answer = new Array(N + 1).fill(0);
    let num = stages.length;
    for (let i = 1; i <= N; i++){
        let count = 0;
        for (let j = 0; j < stages.length; j++){
            if (stages[j] == i) count += 1;
        }
        if (count === 0){
            answer[i] = 0;
        } else {
            answer[i] = count / num;
        }
        num -= count;
    }
    answer.shift();
    const result = Object.entries(answer).sort((a, b) => b[1] - a[1]);
    
    answer = result.map((a) => parseInt(a[0]) + 1);
    return answer;
}