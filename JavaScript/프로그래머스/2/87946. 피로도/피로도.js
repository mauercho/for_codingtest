function solution(k, dungeons) {
    var answer = -1;
    const arrayDungeon = new Array(dungeons.length + 1).fill(false);
    function dfs(remain, cnt){
        let flag = false;
        for (let i = 0; i < dungeons.length; i++){
            if (arrayDungeon[i] === false && remain >= dungeons[i][0]){
                arrayDungeon[i] = true;
                flag = true;
                dfs(remain - dungeons[i][1], cnt + 1);
                arrayDungeon[i] = false;
            }
        }
        if (flag === false){
            answer = Math.max(answer, cnt)
            return ;
        }
    }
    dfs(k, 0);
    return answer;
}