function solution(answers) {
    var answer = [];
    const ans = [0, 0, 0];
    const arr1 = [1,2,3,4,5];
    const arr2 = [2,1,2,3,2,4,2,5];
    const arr3 = [3,3,1,1,2,2,4,4,5,5];
    for (let i = 0; i < answers.length; i++){
        if (answers[i] == (arr1[i % arr1.length])) ans[0]++;
        if (answers[i] == (arr2[i % arr2.length])) ans[1]++;
        if (answers[i] == (arr3[i % arr3.length])) ans[2]++;
    }
    let max_one = Math.max(...ans);
    for (let i = 0; i < 3; i++){
        if (max_one === ans[i])
            answer.push(i + 1);
    }
    return answer;
}