function solution(want, number, discount) {
    var answer = 0;
    obj = {};
    for (let idx = 0; idx < number.length; idx++){
        obj[want[idx]] = number[idx];
    }
    for (let idx = 0; idx < 10; idx++){
        if (obj[discount[idx]] !== undefined){
            obj[discount[idx]] -= 1;   
        }
    }
    answer += 1;
    for (const [key, val] of Object.entries(obj)){
        if (val !== 0){
            answer -= 1;
            break;
        } 
    }
    for (let cnt = 1; cnt <= discount.length - 10; cnt++){
        if (obj[discount[cnt + 9]] !== undefined) {
            obj[discount[cnt + 9]] -= 1;
        } 
        if (obj[discount[cnt - 1]] !== undefined){
            obj[discount[cnt - 1]] += 1;
        }
        answer += 1;
        for (const [key, val] of Object.entries(obj)){
            if (val !== 0){
                answer -= 1;
                break;
            } 
        }
    }
    return answer;
}