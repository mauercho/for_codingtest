function solution(dirs) {
    let answer = 0;
    
    let pos_i = 0;
    let pos_j = 0;
    let ni;
    let nj;
    answer = new Set();
    for (const dir of dirs){
        let ni = pos_i;
        let nj = pos_j;
        if (dir === 'U'){
            ni = pos_i - 1;
        } else if (dir === 'L'){
            nj = pos_j - 1
        } else if (dir === 'R'){
            nj = pos_j + 1;
        } else {
            ni = pos_i + 1;
        }
        if (!(-5 <= ni && ni <= 5 && -5 <= nj && nj <= 5)) continue;
        
        const path1 = `${pos_i}${pos_j},${ni}${nj}`;
        const path2 = `${ni}${nj},${pos_i}${pos_j}`;
        pos_i = ni;
        pos_j = nj;
        answer.add(path1);
        answer.add(path2);
    }
    return answer.size / 2;
}