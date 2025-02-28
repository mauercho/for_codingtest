function solution(cards1, cards2, goal) {
    var answer = 'Yes';
    let idx1 = 0;
    let idx2 = 0;
    for (const g of goal){
        if (idx1 < cards1.length && cards1[idx1] === g){
            idx1++;   
        } else if (idx2 < cards2.length && cards2[idx2] === g){
            idx2++;
        } else {
            answer = 'No';
            break;
        }
    }
    return answer;
}