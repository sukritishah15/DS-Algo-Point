// Print collatz series for given input n

function collatz(nextterm) {
    temp = []
    while (nextterm != 1) {
        temp.push(nextterm);
        nextterm = nextterm % 2 == 0 ? nextterm / 2 : nextterm * 3 + 1;
    }
    temp.push(1);
    return temp;
}
n = 7;
console.log(collatz(n).join(', '));


/*
Sample test case 1:
    Input : n = 7
    Output = 7, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1

Sample test case 2:
    Input : n = 3
    Output = 3, 10, 5, 16, 8, 4, 2, 1

Complexity : Unknown

*/

