#include<iostream>
#include<cmath>

#define PI 3.14159265

const int W = 60;
const int H = 25;

struct circle {
    int x, y, r;
} circ;

char scr[W * H];

void init()
{
    circ.x = W / 2;
    circ.y = H / 2;
    circ.r = 10;
}

void fill()
{
    for (unsigned int y = 0; y < H; y++) {
        for (unsigned int x = 0; x < W; x++) {
            char c = ' ';

            // screen border
            //if (y == 0 || y == H-1 || x == 0 || x == W-1) c = 'x';

            int dx = x - circ.x;
            int dy = y - circ.y;
            int d = sqrt(dx * dx + dy * dy);

            //if (d < circ.r) c = '0';

            scr[x + W * y] = c;
        }
    }

    for (unsigned int i = 1; i <= 360; i++) {
        float r = i * PI / 180;
        int x = (cos(4 * r)*cos(r) * circ.r) + circ.x;
        int y = (cos(4 * r)*sin(r) * circ.r) + circ.y;
        if (x < 0 || y < 0) continue;
        scr[x + W * y] = 'x';
    }
}

void print()
{
    for (unsigned int y = 0; y < H; y++) {
        for (unsigned int x = 0; x < W; x++) {
            std::cout << scr[x + W * y];
        }
        std::cout << '\n';
    }
}

int main(int argc, char** argv)
{
    init();
    fill();
    print();
    return 0;
}
