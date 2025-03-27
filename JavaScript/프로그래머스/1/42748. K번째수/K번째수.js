function solution(array, commands) {
    var answer = [];
    for (const command of commands){
        const [i,j,k] = command;
        let tempArr = array.slice(i - 1, j);
        tempArr.sort((a,b) => { return a - b});
        answer.push(tempArr[(k - 1) % tempArr.length])
    }
    return answer;
}