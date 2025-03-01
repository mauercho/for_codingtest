function solution(want, number, discount) {
    var answer = 0;
    obj = {};
    for (let idx = 0; idx < want.length; idx++){
        obj[want[idx]] = number[idx];
    }
    for (let cnt = 0; cnt <= discount.length - 10; cnt++){
        const tempObj = {...obj};
        for (let i = cnt; i < cnt + 10; i++){
            if (tempObj[discount[i]] !== undefined) tempObj[discount[i]]--;
        }
        if (Object.values(tempObj).every((v) => v === 0)) answer += 1;
    }
    return answer;
}