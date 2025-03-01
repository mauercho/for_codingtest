function solution(record) {
    var answer = [];
    const action = []
    const nameObj = {};
    for (const str of record) {
        const tempArr = str.split(' ');
        if (tempArr[0][0] === 'E'){
            nameObj[tempArr[1]] = tempArr[2];
            action.push(['E', tempArr[1]]);
        } else if  (tempArr[0][0] === 'L'){
            action.push(['L', tempArr[1]]);
        } else {
            nameObj[tempArr[1]] = tempArr[2];
        }
    }
    for (const [act, id] of action){
        if (act === 'E'){
            answer.push(`${nameObj[id]}님이 들어왔습니다.`);
        } else {
            answer.push(`${nameObj[id]}님이 나갔습니다.`);
        }
    }
    return answer;
}