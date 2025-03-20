function solution(enroll, referral, seller, amount) {
    var answer = [];
    const objCost = {};
    const objParent = {};
    for (const mem of enroll){
        objCost[mem] = 0;
    }
    for (const [idx, mem] of referral.entries()){
        if (mem[0] === '-') continue;
        objParent[enroll[idx]] = mem; // 부모 정해줌. 부모는 하나임.
    }
    for (let i = 0; i < seller.length; i++){
        let value = amount[i] * 100;
        let member = seller[i];
        while (member !== undefined && value > 0){
            let tenPercent = Math.floor(value * 0.1);
            objCost[member] += (value - tenPercent);
            member = objParent[member];
            value = tenPercent;
        }
    }
    for (let mem of enroll){
        answer.push(objCost[mem]);
    }
    return answer;
}