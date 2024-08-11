#include<iostream>
#include"type_cube.h"

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

StandardCube original_StandardCube = Cube_To_Standard(original_Cube);

Cube Rotate_Anti_Clockwise(Cube bcube, int element) {
    Cube result = bcube;
    int arr[4][4]; 
    int i, j;
    for (i=0; i<6; i++)
    {
        result.color[element][i+2] = result.color[element][i];
    }
    result.color[element][0] = bcube.color[element][6];
    result.color[element][1] = bcube.color[element][7];
    switch(element)
    {
        case 0 :    arr[0][0] = 1; arr[1][0] = 2; arr[2][0] = 3; arr[3][0] = 4;
                    arr[0][1] = 0; arr[0][2] = 1; arr[0][3] = 2;
                    arr[1][1] = 0; arr[1][2] = 1; arr[1][3] = 2;
                    arr[2][1] = 0; arr[2][2] = 1; arr[2][3] = 2;
                    arr[3][1] = 0; arr[3][2] = 1; arr[3][3] = 2; break;
        case 1:     arr[0][0] = 0; arr[1][0] = 4; arr[2][0] = 5; arr[3][0] = 3;
                    arr[0][1] = 6; arr[0][2] = 7; arr[0][3] = 0;
                    arr[1][1] = 2; arr[1][2] = 3; arr[1][3] = 4;
                    arr[2][1] = 6; arr[2][2] = 7; arr[2][3] = 0;
                    arr[3][1] = 6; arr[3][2] = 7; arr[3][3] = 0; break;
        case 2 :    arr[0][0] = 0; arr[1][0] = 1; arr[2][0] = 5; arr[3][0] = 3;
                    arr[0][1] = 4; arr[0][2] = 5; arr[0][3] = 6;
                    arr[1][1] = 2; arr[1][2] = 3; arr[1][3] = 4;
                    arr[2][1] = 0; arr[2][2] = 1; arr[2][3] = 2;
                    arr[3][1] = 6; arr[3][2] = 7; arr[3][3] = 0; break;
        case 3:     arr[0][0] = 0; arr[1][0] = 2; arr[2][0] = 5; arr[3][0] = 4;
                    arr[0][1] = 2; arr[0][2] = 3; arr[0][3] = 4;
                    arr[1][1] = 2; arr[1][2] = 3; arr[1][3] = 4;
                    arr[2][1] = 2; arr[2][2] = 3; arr[2][3] = 4;
                    arr[3][1] = 6; arr[3][2] = 7; arr[3][3] = 0; break;
        case 4 :    arr[0][0] = 0; arr[1][0] = 3; arr[2][0] = 5; arr[3][0] = 1;
                    arr[0][1] = 0; arr[0][2] = 1; arr[0][3] = 2;
                    arr[1][1] = 2; arr[1][2] = 3; arr[1][3] = 4;
                    arr[2][1] = 4; arr[2][2] = 5; arr[2][3] = 6;
                    arr[3][1] = 6; arr[3][2] = 7; arr[3][3] = 0; break;
        case 5:     arr[0][0] = 1; arr[1][0] = 4; arr[2][0] = 3; arr[3][0] = 2;
                    arr[0][1] = 4; arr[0][2] = 5; arr[0][3] = 6;
                    arr[1][1] = 4; arr[1][2] = 5; arr[1][3] = 6;
                    arr[2][1] = 4; arr[2][2] = 5; arr[2][3] = 6;
                    arr[3][1] = 4; arr[3][2] = 5; arr[3][3] = 6; break;
    }
    for (i=1; i<4; i++)
    {
        result.color[arr[1][0]][arr[1][i]] = bcube.color[arr[0][0]][arr[0][i]];
        result.color[arr[2][0]][arr[2][i]] = bcube.color[arr[1][0]][arr[1][i]];
        result.color[arr[3][0]][arr[3][i]] = bcube.color[arr[2][0]][arr[2][i]];
        result.color[arr[0][0]][arr[0][i]] = bcube.color[arr[3][0]][arr[3][i]];
    }
    return result;
}

int main() {
    int i;
    Cube result = Rotate_Clockwise(original_Cube, 1);
    result = Rotate_Anti_Clockwise(result, 1);
    int j;
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