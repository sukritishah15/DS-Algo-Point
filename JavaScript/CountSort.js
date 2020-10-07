function countSort(array){
    return Object.entries(array.reduce((acc,val) => {
        if(!acc[val]){
            acc[val] = 0;
        }
        acc[val]++; 
        return acc;
    },{}))
    .reduce((acc, val) => {
        return acc.concat(Array.from({length:val[1]}).map(x => parseInt(val[0])));
    }, []);
}
