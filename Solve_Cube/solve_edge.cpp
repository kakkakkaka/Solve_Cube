#include<iostream>
#include"type_cube.h"
#include"method.h"
#include"solve_edge.h"

using namespace std;

int Find_Edge_Loop(Edge (&input_arr)[12][13], Cube original_Cube, Cube input_Cube)
{
    int i, j, k, local, start, total, row, col;
    char lcolor, check1, other_lcolor;
    StandardCube original_StandardCube = Cube_To_Standard(original_Cube);
    StandardCube input_StandardCube = Cube_To_Standard(input_Cube);
    StandardCube check_StandardCube;
    Edge arr_Transfer_Edge[12] = {
        {0, 1, 4, 1},
        {0, 3, 3, 1},
        {0, 5, 2, 1},
        {0, 7, 1, 1},
        {1, 3, 2, 7},
        {2, 3, 3, 7},
        {3, 3, 4, 7},
        {4, 3, 1, 7},
        {5, 1, 2, 5},
        {5, 3, 3, 5},
        {5, 5, 4, 5},
        {5, 7, 1, 5},
    };

    //Initalixe the concer for check
    for (i=0; i<8; i++)
    {
        check_StandardCube.concer[i] = 0;
    }
    //Initalize the edge for check
    for (i=0; i<12; i++)
    {
        check_StandardCube.edge[i] = 0;
    }

    local = 1;
    start = input_StandardCube.edge[1];
    check_StandardCube.edge[1] = 0;
    lcolor = input_Cube.color[0][3];
    other_lcolor = input_Cube.color[3][1];
    total = 1;
    row = 0; col = 0;
    while(total != 0)
    {
        if (check_StandardCube.edge[local] == 2)
        {
            for (i=0; i<12; i++)
            {
                if (check_StandardCube.edge[i] == 0)
                {
                    local = i; start = input_StandardCube.edge[local];
                    check_StandardCube.edge[local] = 0;
                    lcolor = input_Cube.color[arr_Transfer_Edge[i].c1_color][arr_Transfer_Edge[i].c1_location];
                    other_lcolor = input_Cube.color[arr_Transfer_Edge[i].c2_color][arr_Transfer_Edge[i].c2_location];
                    break;
                }
            }
        }
        col = 0;
        while(1)
        {
            if (lcolor == input_Cube.color[arr_Transfer_Edge[local].c1_color][arr_Transfer_Edge[local].c1_location])
            {  
                input_arr[row][col].c1_color = arr_Transfer_Edge[local].c1_color;
                input_arr[row][col].c2_color = arr_Transfer_Edge[local].c2_color;
                input_arr[row][col].c1_location = arr_Transfer_Edge[local].c1_location;
                input_arr[row][col].c2_location = arr_Transfer_Edge[local].c2_location;
            }
            else 
            {
                input_arr[row][col].c1_color = arr_Transfer_Edge[local].c2_color;
                input_arr[row][col].c2_color = arr_Transfer_Edge[local].c1_color;
                input_arr[row][col].c1_location = arr_Transfer_Edge[local].c2_location;
                input_arr[row][col].c2_location = arr_Transfer_Edge[local].c1_location;
            }
            col++;

            for (i=0; i<12; i++)
            {
                if (check_StandardCube.edge[i] < 2 && input_StandardCube.edge[local] == original_StandardCube.edge[i])
                {
                    check1 = original_Cube.color[arr_Transfer_Edge[i].c1_color][arr_Transfer_Edge[i].c1_location];
                    if (check1 == lcolor)
                    {
                        lcolor = input_Cube.color[arr_Transfer_Edge[i].c1_color][arr_Transfer_Edge[i].c1_location];
                        other_lcolor = input_Cube.color[arr_Transfer_Edge[i].c2_color][arr_Transfer_Edge[i].c2_location];
                    }
                    else
                    {
                        lcolor = input_Cube.color[arr_Transfer_Edge[i].c2_color][arr_Transfer_Edge[i].c2_location];
                        other_lcolor = input_Cube.color[arr_Transfer_Edge[i].c1_color][arr_Transfer_Edge[i].c1_location];
                    }
                    check_StandardCube.edge[i]++;
                    local = i;
                    break;
                }
            }
            if (check_StandardCube.edge[local] == 2)
            {
                break;
            }
        }
        input_arr[row][col].c1_color = -1;
        input_arr[row][col].c2_color = -1;
        input_arr[row][col].c1_location = -1;
        input_arr[row][col].c2_location = -1;
        row++;

        for (i=0; i<12; i++)
        {
            if (check_StandardCube.edge[i] == 0)
            {
                total = 1; break;
            }
            total = 0;
        }
    }
    return row;
}

int Apply_Case_Edge(Edge input_case, StepEdge (&pre), StepEdge (&after), int (&num))
{
    int input[4];
    input[0] = input_case.c1_color;
    input[1] = input_case.c1_location;
    input[2] = input_case.c2_color;
    input[3] = input_case.c2_location;
    int compare[22][4] = {
        {0, 1, 4, 1}, {4, 1, 0, 1}, //YO
        {0, 7, 1, 1}, {1, 1, 0, 7}, //YB
        {0, 5, 2, 1}, {2, 1, 0, 5}, //YR
        {1, 3, 2, 7}, {2, 7, 1, 3}, //BR
        {2, 3, 3, 7}, {3, 7, 2, 3}, //RG
        {3, 3, 4, 7}, {4, 7, 3, 3}, //GO
        {4, 3, 1, 7}, {1, 7, 4, 3}, //OB
        {5, 3, 3, 5}, {3, 5, 5, 3}, //WG
        {5, 5, 4, 5}, {4, 5, 5, 5}, //WO
        {5, 7, 1, 5}, {1, 5, 5, 7}, //WB
        {5, 1, 2, 5}, {2, 5, 5, 1}, //WR
    };
    int status, i;
    for (i=0; i<22; i++)
    {
        if (input[0] == compare[i][0] && input[1] == compare[i][1]
             && input[2] == compare[i][2] && input[3] == compare[i][3])
        {
            status = i; break;
        }
    }
    for (i=0; i<4; i++)
    {
        pre.location[i] = -1;
        pre.type[i] = -1;
        after.location[i] = -1;
        after.type[i] = -1;
        num = 0;
    }
    switch (status)
    {
        case 0: break;
    }
    return 0;
}