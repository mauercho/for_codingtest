function solution(n) {
    var answer = 0;
    const array = String(n).split("");
    array.sort((a, b) => {
       if (a < b) return 1;
        else return -1;
    }) // 오름 차순
    answer = Number(array.join(""));
    return answer;
}