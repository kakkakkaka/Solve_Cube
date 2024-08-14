#include<iostream>
#include"type_cube.h"
#include"method.h"
#include<stdio.h>

using namespace std;

Cube original_Cube = {
    {
        {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'},
        {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'},
        {'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'},
        {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}
    }
};
Cube input_Cube;

StandardCube original_StandardCube = Cube_To_Standard(original_Cube);

int arr1[20] = {2, -1, 2, -1, 2, -1, -1, 2, 1, 1, 2, 2, 2, 2, -1, -1, -1, 1, -1};
    int arr2[20] = {4,  5, 3,  2, 5,  0,  3, 2, 3, 0, 1, 2, 3, 0,  4,  5,  2, 0,  1};


int main() {
    int i, j, k;
    freopen("test_case/testcase2.txt", "r", stdin);
    for (i=0; i<6; i++)
    {
        for (j=0; j<8; j++)
        {
            cin >> input_Cube.color[i][j];
        }
    }

    Cube result = original_Cube;
    for (i=0; i<20; i++)
    {
        if (arr1[i] == -1)
        {
            result = Rotate_Anti_Clockwise(result, arr2[i]);
        }
        else if (arr1[i] == 1)
        {
            result = Rotate_Clockwise(result, arr2[i]);
        }
        else if (arr1[i] == 2)
        {
            result = Rotate_Clockwise(result, arr2[i]);
            result = Rotate_Clockwise(result, arr2[i]);
        }
    }

    for (i=0; i<6; i++)
    {
        for (j=0; j<8; j++)
        {
            cout << result.color[i][j];
        }
        cout << '\n';
    }
    return 0;
}