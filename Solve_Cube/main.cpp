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

int main() {
    int i;
    Cube result = Rotate_Clockwise(original_Cube, 0);
    //Cube result = Rotate_Anti_Clockwise(original_Cube, 5);
    result = Rotate_Anti_Clockwise(result, 0);
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