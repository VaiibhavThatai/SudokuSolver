// & SUDOKU SOLVER USING BACKTRACKING
// & 9 * 9 MATRIX USING SUDOKU RULES

// & BRUTE FORCE - TRY OUT ALL SOLUTION, AND STOP WHEN WE FIND ONE SOLUTION
// & we can go row wise, filling numbers and checking if it is possible to put
// & a number there, if can't be placed we go to previous sub problem and try next number
// & we can go on
// & if sub problem is solved, return true, else return false
// & if false, we go back tracking, else we print the answer

// & Base case: if(j==9) i.e. column becomes 9, we go to next row, i = i+1
// & j = 0

// & if we get no number, for that cell , we go back to previous col
// & and change it and make number 0 on current cell

#include <bits/stdc++.h>
using namespace std;

bool fillValue(int mat[][9], int i, int j, int n, int val)
{
    // for row and column
    for (int k = 0; k < 9; k++)
    {
        if (mat[k][j] == val || mat[i][k] == val)
        {
            return false;
        }
    }
    // for subgrid
    // Sx, Sy be starting point of subgrid
    // Then let x, y be the point to fill, then its sub grid begins from
    // Sx = (x/3)*3, Sy = (y/3)*3

    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;

    for (int x = sx; x < sx + 3; x++)
    {
        for (int y = sy; y < sy + 3; y++)
        {
            if (mat[x][y] == val)
            {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n)
{
    // base case
    if (i == n)
    {
        // print solution later
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    // recursive case
    if (j == n)
    {
        return solveSudoku(mat, i + 1, 0, n);
    }
    if (mat[i][j] != 0)
    {
        return solveSudoku(mat, i, j + 1, n);
    }

    for (int no = 1; no <= n; no++)
    {
        if (fillValue(mat, i, j, n, no))
        {
            mat[i][j] = no;
            bool solveSubproblem = solveSudoku(mat, i, j + 1, n);
            if (solveSubproblem == true)
            {
                return true;
            }
        }
    }
    // back tracking
    mat[i][j] = 0;
    return false;
}

int main()
{
    int n = 9;
    int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (!solveSudoku(mat, 0, 0, n))
    {
        cout << "No Solution for this matrix!!";
    }

    return 0;
}