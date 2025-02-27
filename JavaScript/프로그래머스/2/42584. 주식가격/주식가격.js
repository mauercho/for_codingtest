function solution(prices) {
    
    let stack = [];
    const len = prices.length;
    const answer = new Array(len).fill(0);
    for (let i = 0; i < len; i++){
        if (i === len - 1){
            break;
        }
        if (stack.length === 0)
            stack.push([i, prices[i]]); // 위치와 값
        else {
            while (stack.length !== 0 && stack[stack.length - 1][1] > prices[i]){
                const [a, b]  = stack.pop();
                answer[a] = i - a;
            }   
            stack.push([i, prices[i]]);
        }
    }
    while (stack.length !== 0){
        const [a, b] = stack.pop();
        answer[a] = len - 1 - a;
    }
    
    return answer;
}