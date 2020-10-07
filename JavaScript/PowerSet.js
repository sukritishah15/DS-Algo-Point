function powerSet(num){

      let result = [];
    
      result.push([]);
    
      for(let i=0; i < num.length;i++){
    
        let currentNum = num[i];
       
    
        for(let j=0; j < result.length; j++){
          let cloneData = result[j].slice();
          cloneData.push(currentNum);
          result.push(cloneData)
        }
      }
    
      return result;
    }
    
    let test = [1,3];
    console.log(powerSet(test))//[ [], [ 1 ], [ 3 ], [ 1, 3 ] ]
    /*
    Time complexity:n2^n
    Space complexity: n
    */