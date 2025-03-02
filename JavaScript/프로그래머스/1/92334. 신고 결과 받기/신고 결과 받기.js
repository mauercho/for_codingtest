function solution(id_list, report, k) {
    var answer = [];
    const objId = {};
    for (const ind of report){
        const [a, b] = ind.split(' ');
        if (objId[a]){
            objId[a].add(b);
        } else {
            objId[a] = new Set();
            objId[a].add(b);
        }
    }
    const objCheck = {};
    for (const key of Object.keys(objId)){
       for (const val of objId[key]){
            if (objCheck[val]){
                objCheck[val] += 1;
            } else {
                objCheck[val] = 1;
            }
        }
    }
    // console.log(objId)
    // console.log(objCheck)
    for (const mem of id_list){
        let ans = 0;
        if (objId[mem]){
            for (const m of objId[mem]){
                if (objCheck[m] !== undefined && objCheck[m] >= k) ans += 1;
            }
        }
        answer.push(ans);
    }
    return answer;
}