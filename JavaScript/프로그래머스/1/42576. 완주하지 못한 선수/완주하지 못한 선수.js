function solution(participant, completion) {
    let answer;
    obj = {};
    for (let s of completion){
        if (obj[s]) {
            obj[s] += 1;
        } else {
            obj[s] = 1;
        }
    }
    for (let mem of participant){
        if (obj[mem]){
            obj[mem] -= 1;
        } else {
            answer = mem;
        }
    }
    return answer;;
}