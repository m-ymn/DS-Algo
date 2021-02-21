
/*

Task description

You are given an N × N matrix in which every cell is colored black or white. Columns are numbered from 0 to N-1 (from left to right). 
This coloring is represented by a non-empty array of integers A. If the K-th number in the array is equal to X then the X lowest cells in the K-th column of the matrix are black. 
The rest of the cells in the K-th column are white. The task is to calculate the side length of the biggest black square (a square containing only black cells).

Write a function:

    int solution(int A[], int N);

that, given an array of integers A of length N representing the coloring of the matrix, returns the side length of the biggest black square.

Examples:

1. Given A = [1, 2, 5, 3, 1, 3], the function should return 2. 
For example, the black square of side 2 contains the two lowest rows of the 1st and 2nd columns (counting from 0).

The picture describes the first example test [1, 2, 5, 3, 1, 3].

2. Given A = [3, 3, 3, 5, 4], the function should return 3. 
For example, the biggest black square has side 3 and contains the three lowest rows of the last three columns.

The picture describes the second example test [3, 3, 3, 5, 4].

3. Given A = [6, 5, 5, 6, 2, 2], the function should return 4. 
The biggest black square has side 4 and contains the four lowest rows of the first four columns.

The picture describes the third example test [6, 5, 5, 6, 2, 2].

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [1..N].


*/


int solution(int A[], int N) {
    
    int i ;
    for(i=N;i>0;i--)
    {
        if(find_sq(A,i,N) == 1)
        {
            return i ;
        }
        
    }
    return 1 ;


/*
    int n = 
    printf("%d, " , n);
    n = find_sq(A,3,N);
    printf("%d, " , n);
    n = find_sq(A,4,N);
    printf("%d, " , n);
    n = find_sq(A,5,N);
    printf("%d, " , n);
*/
    // write your code in C99 (gcc 6.2.0)
}


int find_sq(int A[],int Len, int N)
{
    unsigned int i,j=0 ;
    for(i=0;i<N;i++)
    {
        if(A[i] >= Len )
        {
            j++;
        }
        if(A[i] < Len )
        {
            j=0;
        }
        if(j == Len)
        {
            return 1 ;
        }
    }
    return 0;
}