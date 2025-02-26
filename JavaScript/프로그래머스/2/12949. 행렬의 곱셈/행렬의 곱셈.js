

function solution(arr1, arr2) {
    let n = arr1.length;
    let m = arr2[0].length;
    let answer = [...new Array(n)].map((_,i) => new Array(m).fill(0));
    const calc = (a, b) => {
        let sum_val = 0;
        for (let i = 0; i < arr1[0].length; i++){
            sum_val += arr1[a][i] * arr2[i][b];
        }
        return sum_val;
    }
    for (let i = 0; i < n ; i++){
        for (let j = 0; j < m; j++){
            answer[i][j] = calc(i, j);
        }
    }
    return answer;
}