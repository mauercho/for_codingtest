function solution(n, lost, reserve) {
    
    const deleteObjLost = {};
    const deleteObjReserve = {};
    const array = new Array(31).fill(true); // 1부터 n까지 보면 됨.
    for (let i = 0; i < lost.length; i++){
        for (let j = 0; j < reserve.length; j++){
            if (lost[i] === reserve[j]){
                deleteObjLost[lost[i]] = 1;
                deleteObjReserve[reserve[j]] = 1;
            }
        }
    }
    const newLost = [];
    const newReserve = [];
    const newLostObj = {};
    for (const mem of lost){
        if (deleteObjLost[mem] !== 1){
            array[mem] = false;
            newLost.push(mem);
            newLostObj[mem] = 1;
        }
    }
    for (const mem of reserve){
        if (deleteObjReserve[mem] !== 1){
            newReserve.push(mem);
        }
    }
    let answer = 0;
    function dfs(depth, end){
        if (depth === end){
            let cnt = 0;
            for (let i = 1; i <= n; i++){
                if (array[i] === true) cnt++;
            }
            answer = Math.max(answer, cnt);
            return ;
        }
        dfs(depth + 1, end);
        const up = newReserve[depth] + 1;
        if (up <= n && up >= 1){
            if (newLostObj[up] == 1 && array[up] === false){
                array[up] = true;
                dfs(depth + 1, end);
                array[up] = false;
            }
        }
        const down = newReserve[depth] - 1;
        if (down <= n && down >= 1){
            if (newLostObj[down] == 1 && array[down] === false){
                array[down] = true;
                dfs(depth + 1, end);
                array[down] = false;
            }
        }
    }
    dfs(0, newReserve.length);
    return answer;
}
