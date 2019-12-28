#include<iostream>
#include<cmath>
using namespace std;

int row,col,mini;
double multiplier;
int start = 1;
int i,j,k,m,n,number = 0;

int minimum(int x,int y)
{
    if (x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
// Get the smaller of row and col
void judge(double x)
{
    if (x > -0.00001 && x < 0.00001)
    {
        x = 0;
    }
}

int main()
{
    cout<<"Input row of matrix:"<<endl;
    cin>>row;
    cout<<"Input column of matrix:"<<endl;
    cin>>col;
    mini = minimum(row,col);
    double matrix[row][col];
    int check[row]; // Check array is used to identify location of all-zero row.
    for (i = 0;i < row;i++)
    {
        check[i] = 1;
    }
    cout<<"Input matrix:"<<endl;
    for (i = 0;i < row;i++)
    {
        for (j = 0;j < col;j++)
        {
            cin>>matrix[i][j];
        }
    }
    // Initiate matrix
    for (k = 0;k < mini;k++) // One large step of processing, process whole column
    {
        for (i = start;i < row;i++) // Process each row below start row
        {
            if (matrix[k][k] == 0)
            {
                break;
            }
            multiplier = (matrix[i][k] / matrix[k][k]); // Get multiplier for each row
            for (m = k;m < col;m++) // Process each element
            {
                matrix[i][m] -= (multiplier * matrix[k][m]);
                judge(matrix[i][m]);
            }
        }
        for (i = 0;i < start - 1;i++) // Process each row above start row
        {
            if (matrix[k][k] == 0)
            {
                break;
            }
            multiplier = (matrix[i][k] / matrix[k][k]); // Get multiplier for each row
            for (m = k;m < col;m++) // Process each element
            {
                if (matrix[i][m] == -multiplier * matrix[k][m])
                {
                    matrix[i][m] = 0;
                    continue;
                }
                matrix[i][m] -= (multiplier * matrix[k][m]);
                judge(matrix[i][m]);
            }
        }
        start++;
    }
    for (i = 0;i < row;i++)
    {
        j = 0; // Reset variable
        while (matrix[i][j] == 0) // Check existence of none-zero element
        {
            j++;
            if (j == col)
            {
                check[i] = 0;
                number++; // Number gets the quantity of zeros in check array
                break;
            }
        }
        if (check[i] != 0)
        {
            multiplier = matrix[i][j];
            for (m = 0;m < col;m++)
            {
                matrix[i][m] = matrix[i][m] / multiplier;
                judge(matrix[i][m]);
                if (matrix[i][m] == -0)
                {
                    matrix[i][m] = 0;
                }
            }
        }
    }
    // Set each row's first none-zero element to 1
    cout<<"Calculation complete."<<endl;
    cout<<"Reduced row echelon matrix: "<<endl;
    for (i = 0;i < row;i++)
    {
        if (check[i] != 0) // Print rows which are not all-zero
        {
            for (j = 0;j < col - 1;j++)
            {
                cout<<matrix[i][j]<<' ';
            }
            cout<<matrix[i][col - 1]<<endl;
        }
    }
    if (number != 0) // Print all-zero rows if exist
    {
        for (i = 0;i < number;i++)
        {
            for (j = 0;j < col - 1;j++)
            {
                cout<<0<<' ';
            }
            cout<<0<<endl;
        }
    }
    // Print matrix
    return 0;
}
