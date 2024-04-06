/*  74. Search a 2D Matrix  */

#include <iostream>
#include <vector>
// #include<string>
using namespace std;

void printMatrix(vector<vector<int>> &arr)
{
    cout << "array ele are\n";
    int rows = arr.size();
    int cols = (rows > 0) ? arr[0].size() : 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

// ==== binary search ====
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int start = 0, end = m * n - 1, mid, row, col;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        row = mid / m;
        col = mid % n;
        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (target < matrix[row][col])
        {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return false;
}

bool searchMatrix1(vector<vector<int>> &matrix, int target)
{
    int row = 0;
    int col = matrix[0].size() - 1;
    // cout<<"ele :"<<matrix[row][col];
    while (row < matrix.size() && col >= 0)
    {
        if (target == matrix[row][col])
        {
            return true;
        }
        else if (target < matrix[row][col])
        {
            col--;
        }
        else
            row++;
    }
    return false;
}

int main()
{
    cout << "\n\n=======================\n\n";

    // vector<vector<int>> arr(3, vector<int>(3));
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printMatrix(arr);
    int target = 6;
    cout << "Target ele " << target << " is present? " << searchMatrix1(arr, target);

    cout << "\n\n=======================";

    return 0;
}

/* OPTIMIZE CODE
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid / n][mid % n];

            if (mid_val == target)
                return true;
            else if (mid_val < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
*/