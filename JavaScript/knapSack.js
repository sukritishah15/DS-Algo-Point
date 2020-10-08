const knapSackSolution = (items, totalCapacity) => {
    var singleItem = 0,
        singleItemWeight = 0,
        oldMax = 0,
        newMax = 0,
        numItems = items.length,
        weightMatrix = new Array(numItems + 1),
        tempMatrix = new Array(numItems + 1),
        solutionSet = [];

    for (singleItem = 0; singleItem < numItems + 1; singleItem++)
    {
        weightMatrix[singleItem] = new Array(totalCapacity + 1);
        tempMatrix[singleItem] = new Array(totalCapacity + 1);
    }


    for (singleItem = 0; singleItem <= numItems; singleItem++)
    {
        for (singleItemWeight = 0; singleItemWeight <= totalCapacity; singleItemWeight++)
        {

            if (singleItem === 0 || singleItemWeight === 0)
            {
                weightMatrix[singleItem][singleItemWeight] = 0;
            }


            else if (items[singleItem - 1].weight <= singleItemWeight)
            {
                newMax = items[singleItem - 1].index + weightMatrix[singleItem - 1][singleItemWeight - items[singleItem - 1].weight];
                oldMax = weightMatrix[singleItem - 1][singleItemWeight];


                if (newMax > oldMax)
                {
                    weightMatrix[singleItem][singleItemWeight] = newMax;
                    tempMatrix[singleItem][singleItemWeight] = 1;
                }
                else
                {
                    weightMatrix[singleItem][singleItemWeight] = oldMax;
                    tempMatrix[singleItem][singleItemWeight] = 0;
                }
            }

            else
            {
                weightMatrix[singleItem][singleItemWeight] = weightMatrix[singleItem - 1][singleItemWeight];
            }
        }
    }

    // creating solution set
    singleItemWeight = totalCapacity;
    singleItem = numItems;
    for (singleItem; singleItem > 0; singleItem--)
    {
        if (tempMatrix[singleItem][singleItemWeight] === 1)
        {
            solutionSet.push(items[singleItem - 1]);
            singleItemWeight = singleItemWeight - items[singleItem - 1].weight;
        }
    }
    return { "Maximum Value": weightMatrix[numItems][totalCapacity], "Solution Set": solutionSet };
}


/*  Name of Algorithm : Kadane's Algorithm
Time Complexity : O(n)
Space Complexity : O(1)
The first argument is the array of objects with weight and items, second argument is
the total capacity of the bag.


const items = [{
    "weight": 5,
    "index": 1,

},
{
    "weight": 10,
    "index": 2,
},
{
    "weight": 15,
    "index": 3,
}
]
let value = knapSackSolution(items, 15);
console.log(value);

Output: {
    Maximum Value: 3,
    Solution Set: [{
    index: 2,
    weight: 10
  }, {
    index: 1,
    weight: 5
  }]
  }  */