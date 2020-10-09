#include <bits/stdc++.h>
using namespace std;

/*
Input Format: as deplayed while running the program
Output Format: The required series
ALgorithm: Mathematical Series
Time Complexity: O(N), N -> number of terms of the series
Space Complexity: O(N), N -> number of terms of the series

**Sample Input and Output**

----------------Menu Driven Program----------------

1. Harmonic Series
2. Arithmatic Series
3. Fibonacci Series
4. Geometric Series
5. Exit

Enter your choice: 1

Enter the first term of the harmonic series: 0.2

Enter the common difference of the harmonic series: 5

Enter the number of terms of the harmonic series: 10

The resulting harmonic sequence is: 0.20000 0.10000 0.06667 0.05000 0.04000 0.03333 0.02857 0.02500 0.02222 0.02000

----------------Menu Driven Program----------------

1. Harmonic Series
2. Arithmatic Series
3. Fibonacci Series
4. Geometric Series
5. Exit

Enter your choice: 2

Enter the first term of the arithmatic series: 5

Enter the common difference of the arithmatic series: 5

Enter the number of terms of the arithmatic series: 10

The resulting arithmatic sequence is: 5 10 15 20 25 30 35 40 45 50

----------------Menu Driven Program----------------

1. Harmonic Series
2. Arithmatic Series
3. Fibonacci Series
4. Geometric Series
5. Exit

Enter your choice: 3

Enter the number of terms of the fibonacci series: 10

The resulting fibonacci series is: 0 1 1 2 3 5 8 13 21 34

----------------Menu Driven Program----------------

1. Harmonic Series
2. Arithmatic Series
3. Fibonacci Series
4. Geometric Series
5. Exit

Enter your choice: 4

Enter the first term of the geometric series: 2

Enter the common ratio of the geometric series: 3

Enter the number of terms of the geometric series: 10

The resulting geometric sequence is: 2.00000 6.00000 18.00000 54.00000 162.00000 486.00000 1458.00000 4374.00000 13122.00000 39366.00000

----------------Menu Driven Program----------------

1. Harmonic Series
2. Arithmatic Series
3. Fibonacci Series
4. Geometric Series
5. Exit

Enter your choice: 6

Wrong choice entered! Try again.

----------------Menu Driven Program----------------

1. Harmonic Series
2. Arithmatic Series
3. Fibonacci Series
4. Geometric Series
5. Exit

Enter your choice: 5
*/

void harmonic()
{
  cout << setprecision(5) << fixed; // setting the number of decimal places after the decimal to 5

  // characteristics of the series
  long double firstTerm, numberOfTerms, commonDifference;
  cout << "\nEnter the first term of the harmonic series: ";
  cin >> firstTerm;
  cout << "\nEnter the common difference of the harmonic series: ";
  cin >> commonDifference;
  cout << "\nEnter the number of terms of the harmonic series: ";
  cin >> numberOfTerms;

  /*
	As harmonic series is arithmatic series when taken reciprocal, 
	We first calculate the resulting arithmatic series and then print
	the reciprocal of it
	*/
  vector<long double> result(numberOfTerms);
  result[0] = 1LL / firstTerm;
  for (int i = 1; i < numberOfTerms; i++)
  {
    result[i] = result[i - 1] + commonDifference;
  }
  cout << "\nThe resulting harmonic sequence is: ";
  for (int i = 0; i < numberOfTerms; i++)
  {
    cout << 1LL / result[i] << " ";
  }
  cout << '\n';
}

void arithmatic()
{

  // characteristics of the series
  long long firstTerm, numberOfTerms, commonDifference;
  cout << "\nEnter the first term of the arithmatic series: ";
  cin >> firstTerm;
  cout << "\nEnter the common difference of the arithmatic series: ";
  cin >> commonDifference;
  cout << "\nEnter the number of terms of the arithmatic series: ";
  cin >> numberOfTerms;

  // generating and printing the series
  cout << "\nThe resulting arithmatic sequence is: ";
  cout << firstTerm << " ";
  for (int i = 1; i < numberOfTerms; i++)
  {
    cout << firstTerm + i * commonDifference << " ";
  }
  cout << '\n';
}

void fibonacci()
{

  // characteristics of the series
  int numberOfTerms;
  cout << "\nEnter the number of terms of the fibonacci series: ";
  cin >> numberOfTerms;
  long long firstTerm = 0, secondTerm = 1;

  // generating and printing the series
  cout << "\nThe resulting fibonacci series is: ";
  cout << firstTerm << " " << secondTerm << " ";
  for (int i = 3; i <= numberOfTerms; i++)
  {
    long long currentElement = firstTerm + secondTerm;
    firstTerm = secondTerm;
    secondTerm = currentElement;
    cout << currentElement << " ";
  }
  cout << '\n';
}

void geometric()
{
  cout << setprecision(5) << fixed; // setting the number of decimal places after the decimal to 5

  // characteristics of the series
  long double numberOfTerms, firstTerm, commonRatio;
  cout << "\nEnter the first term of the geometric series: ";
  cin >> firstTerm;
  cout << "\nEnter the common ratio of the geometric series: ";
  cin >> commonRatio;
  cout << "\nEnter the number of terms of the geometric series: ";
  cin >> numberOfTerms;

  // generating the series
  cout << "\nThe resulting geometric sequence is: ";
  cout << firstTerm << " ";
  for (int i = 1; i < numberOfTerms; i++)
  {
    firstTerm *= commonRatio;
    cout << firstTerm << " ";
  }
  cout << '\n';
}

int main()
{

  // menu driven program
  while (true)
  {
    int choice;
    cout << "\n----------------Menu Driven Program----------------\n";
    cout << "\n1. Harmonic Series";
    cout << "\n2. Arithmatic Series";
    cout << "\n3. Fibonacci Series";
    cout << "\n4. Geometric Series";
    cout << "\n5. Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      harmonic();
      break;

    case 2:
      arithmatic();
      break;

    case 3:
      fibonacci();
      break;

    case 4:
      geometric();
      break;

    case 5:
      exit(0);

    default:
      cout << "\nWrong choice entered! Try again.\n";
    }
  }
}