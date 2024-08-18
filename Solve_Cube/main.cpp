#include<iostream>
#include"type_cube.h"
#include"method.h"
#include"solve_edge.h"
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
StandardCube input_StandardCube;

Edge arr[12][13];

int main() {
    int i, j;
    int num_arr_row, num_arr_col;
    freopen("test_case/testcase5.txt", "r", stdin);
    for (i=0; i<6; i++)
    {
        for (j=0; j<8; j++)
        {
            cin >> input_Cube.color[i][j];
        }
    }
    input_StandardCube = Cube_To_Standard(input_Cube);

    num_arr_row = Find_Edge_Loop(arr, original_Cube, input_Cube);
    for (i=0; i<num_arr_row; i++)
    {
        num_arr_col = 0;
        while (arr[i][num_arr_col].c1_color != -1)
        {
            cout << input_Cube.color[arr[i][num_arr_col].c1_color][arr[i][num_arr_col].c1_location];
            cout << input_Cube.color[arr[i][num_arr_col].c2_color][arr[i][num_arr_col].c2_location] << ' ';
            num_arr_col++;
        }
        cout << '\n';
    }

    // cout << "Concer" << '\n';
    // for (i=0; i<8; i++)
    // {
    //     cout << original_StandardCube.concer[i] << '\n';
    // }
    // cout << "Edge" << '\n';
    // for (i=0; i<12; i++)
    // {
    //     cout << original_StandardCube.edge[i] << '\n';
    // }
}