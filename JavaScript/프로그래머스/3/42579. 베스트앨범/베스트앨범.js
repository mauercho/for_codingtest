function solution(genres, plays) {
    var answer = [];
    const objGenres = {};
    const objNum = {};
    for (let i = 0; i < genres.length; i++){
        if (objGenres[genres[i]]){
            objGenres[genres[i]] += plays[i];
        } else {
            objGenres[genres[i]] = plays[i];
        }
        if (objNum[genres[i]]){
            objNum[genres[i]] = {...objNum[genres[i]], [i]: plays[i]};
        } else {
            objNum[genres[i]] = {[i]: plays[i]};
        }
    }
    const array = Object.entries(objGenres).sort(([key, value], [key1, value1]) => value1 - value); 
    // console.log(array)
    // console.log(objNum)
    for (const [genre, val] of array){
        newArr = Object.entries(objNum[genre]).sort(([key, value], [key1, value1]) => value1 - value);
        for (let i = 0 ; i <2; i++){
            if (newArr[i] !== undefined){
                answer = [...answer, parseInt(newArr[i][0])];
            }
        }
    }
    return answer;
}