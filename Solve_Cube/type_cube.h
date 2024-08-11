struct Cube {
    char color[6][8];
};

struct StandardCube {
    int concer[8];
    int edge[12];
};

int Color_To_Int(char ch);
int Power_Two(int element);
StandardCube Cube_To_Standard(Cube bcube);
Cube Rotate_Clockwise(Cube bcube, int element);