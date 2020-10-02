#include <stdio.h> 

// tranfers represents number of swappings required
int transfers = 0;
int main() { 
    // n represents number of disks
    int n;
    printf("\n Enter number of disks: ");
    scanf("%d", &n); 

     // A, B and C are names of rods 
    towerOfHanoi(n, 'A', 'C', 'B'); 
    printf("\n\n Total number of transfers required: %d", transfers);
    return 0; 
}  

void towerOfHanoi(int n, char source, char destination, char auxilary) {
    transfers += 1;
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", source, destination); 
        return; 
    } 
    towerOfHanoi(n-1, source, auxilary, destination); 
    printf("\n Move disk %d from rod %c to rod %c", n, source, destination); 
    towerOfHanoi(n-1, auxilary, destination, source);
}

/*
    Problem name: Tower of Hanoi
    Number of rods = 3 , namely 'A', 'B', 'C'
    Input:
    Enter number of disks: 3
    Output:
        Move disk 1 from rod A to rod C
        Move disk 2 from rod A to rod B
        Move disk 1 from rod C to rod B
        Move disk 3 from rod A to rod C
        Move disk 1 from rod B to rod A
        Move disk 2 from rod B to rod C
        Move disk 1 from rod A to rod C
        Number of transfers required: 7

    Time Complexity: O(2^n)
    Space Complexity: O(1)
*/
  
