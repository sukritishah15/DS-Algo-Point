const knapSack = (items, capacity) => {
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
        weightMatrix[singleItem] = new Array(capacity + 1);
        tempMatrix[singleItem] = new Array(capacity + 1);
    }


    for (singleItem = 0; singleItem <= numItems; singleItem++)
    {
        for (singleItemWeight = 0; singleItemWeight <= capacity; singleItemWeight++)
        {

            if (singleItem === 0 || singleItemWeight === 0)
            {
                weightMatrix[singleItem][singleItemWeight] = 0;
            }


            else if (items[singleItem - 1].w <= singleItemWeight)
            {
                newMax = items[singleItem - 1].b + weightMatrix[singleItem - 1][singleItemWeight - items[singleItem - 1].w];
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
    singleItemWeight = capacity;
    singleItem = numItems;
    for (singleItem; singleItem > 0; singleItem--)
    {
        if (tempMatrix[singleItem][singleItemWeight] === 1)
        {
            solutionSet.push(items[singleItem - 1]);
            singleItemWeight = singleItemWeight - items[singleItem - 1].w;
        }
    }
    return { "Maximum Value": weightMatrix[numItems][capacity], "Solution Set": solutionSet };
}

// Example

const items = [{
    "w": 5,
    "b": 1,

},
{
    "w": 10,
    "b": 2,
},
{
    "w": 15,
    "b": 3,
}
]
let value = knapSack(items, 15);
console.log(value);