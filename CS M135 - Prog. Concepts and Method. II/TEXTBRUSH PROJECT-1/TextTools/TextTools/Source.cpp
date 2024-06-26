#include <iostream>
#include <string>
#include <fstream>
#include "MyCircle.h"
#include "MyRectangle.h"
#include "MyMouse.h"
#include "Diamond.h"
#include <cmath>

using namespace std;

void main()

{
    //defining vaiables and arrays. names are fairly self-explainatory
    MyMouse m;
    int black = 0;
    int dblue = 1;
    int green = 2;
    int turq = 3;
    int red = 4;
    int purple = 5;
    int gold = 6;
    int silver = 7;
    int gray = 8;
    int lblue = 9;
    int lgreen = 10;
    int cyan = 11;
    int pink = 12;
    int lpurple = 13;
    int tan = 14;
    int white = 15;
    int color = 0;
    int var1 = 0;
    bool fill = true;
    int x1;
    int x2;
    int y1;
    int y2;
    int w;
    int h;
    Coordinates* save[10];
    Coordinates* load[10];
    int counter = 0;
    
    string nnn;

    //creating arrays that will be used to print information that will inform the user of the shape/color currently active
    string shape[] = { "SQUARE","CIRCLE","DIAMOND" };
    string pallet[] = { "BLACK","DBLUE","GREEN","TURQU","RED","PURPLE","GOLD","SILVER","GRAY","LBLUE","LGREEN","CYAN","PINK","LPURP","TAN","WHITE" };

    int screen[] = {
        32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,201.205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,187,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,219,219,219,219,219,32,32,219,219,219,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,219,219,219,219,219,32,219,219,219,219,219,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,219,219,219,219,219,32,32,219,219,219,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,219,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,219,219,219,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,219,219,219,219,219,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,219,219,219,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,219,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,204,205,205,205,205,205,205,205,205,205,205,205,205,205,185,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,204,205,205,205,205,203,205,205,205,205,203,205,205,203,188,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,186,32,32,32,32,186,32,32,186,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,204,205,205,205,205,206,205,205,205,205,185,32,32,186,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,186,32,32,32,32,186,32,32,186,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,204,205,205,205,205,202,205,205,205,205,202,205,205,188,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,203,205,205,205,205,205,205,185,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,186,32,32,32,32,32,32,32,186,32,32,32,32,32,32,186,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,200,205,205,205,205,205,205,205,202,205,205,205,205,205,205,188,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32, };


    //printing the screen
    for (int i = 0; i < 2825; i++)
    {
        cout << char(screen[i]); //printing the chararacter as defined by ASCII code
        if ((i % 113) == 0) { cout << endl; } //the length of the screen is 113, so when i % 113 = 0, it will start a new line
    }
    //startofSquareX/Y are starting points for the color pallet that will be printed
    int startofSquareX = 88;
    int startofSquareY = 15;
    int clr = 0; //default color = 0 (black)

    while (1) { //creating color pallet
        for (int rows = 0; rows < 6; rows++) { //following loop will create a 4x4 color pallet representing the 16 available colors
            {if (color == 16) { break; }
            for (int cols = 0; cols < 4; cols++) { //printing four squares of different color with a width of three which will represent the color pallet
                MyRectangle R(startofSquareX, startofSquareY, 3, 1, 219, false, color); //define the square
                R.Draw(); //print the square
                color++; //increment the color by one
                startofSquareX += 3; //increat the x value by three, therefore printing the next square so it is not overlapping with the previous
            }
            //after a row within the color pallet is printed, the following code will execute
            //the x is reset to the beggining location of the pallet, and the y is incrementd to create room for the next row
            startofSquareX = 88;
            startofSquareY += 1; }
            //the following code is printing information that the user can use to select a function
            //it does not have to be specifically here, however it is not causing any problems so I will leave it
            m.gotoxy(87, 20);
            cout << "WIPE";
            m.gotoxy(87, 22);
            cout << "LOAD";
            m.gotoxy(92, 20);
            cout << "FILL";
            m.gotoxy(92, 22);
            cout << "HLLW";
            m.gotoxy(97, 20);
            cout << "ER";
            m.gotoxy(97, 21);
            cout << "AS";
            m.gotoxy(97, 22);
            cout << "ER";
        }
        while (1) { //beggining an indefinite loop that will house the interactive part of the program
            m.ReadMouseInput(); //reading the mouse's location
            m.coord.X = m.InputRecord.Event.MouseEvent.dwMousePosition.X; //saving the location of the mouse
            m.coord.Y = m.InputRecord.Event.MouseEvent.dwMousePosition.Y;
            //the following two lines are used to inform the user of the location of their mouse on the screen
            m.gotoxy(0, 0);
            cout << m.coord.X << ' ' << m.coord.Y << ' ' << ' ' << ' ';

            switch (m.InputRecord.EventType) {
            case MOUSE_EVENT: //when a 'mouse event' is detected, the following code will execute
                if (m.InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
                   
                    //recording the location of the user's left click
                    m.coord.X = m.InputRecord.Event.MouseEvent.dwMousePosition.X;
                    m.coord.Y = m.InputRecord.Event.MouseEvent.dwMousePosition.Y;
                    //detecting where the user clicked

                    //if user clicked here, shape will change to square and color to black, used to imitate an eraser
                    if (m.coord.X >= 97 && m.coord.Y <= 98 && m.coord.Y >= 20 && m.coord.Y <= 22) {
                        clr = 0;
                        var1 = 0;
                    }
                    //if user clicked here, program will load all previously drawn objects
                    if (m.coord.X >= 87 && m.coord.X <= 90 && m.coord.Y == 22) {
                        ifstream input;
                        input.open("c:\\temp\\data.txt"); //opening the file where the objects are stored
                        while (input.good()) { //while there is something within the file
                            input >> x1 >> y1 >> w >> h >> clr; //assigning values from the txt file to their respective variables
                            MyRectangle S(x1, y1, w, h, 219, fill, clr); //creating a new object as defiend by the values read from the txt file
                            S.Draw(); //drawing the new object
                            
                        }                                            
                        input.close();
                        
                    } 
                    //if user clicked here, program will wip all previously drawn objects
                    if (m.coord.X >= 87 && m.coord.X <= 90 && m.coord.Y == 20) {
                        ofstream output("c:\\temp\\data.txt");
                    }
                    //if the user's mouse location was here, set the fill variable to true/false
                    if (m.coord.X >= 92 && m.coord.X <= 95) {
                        if (m.coord.Y == 20) {
                            fill = !fill;
                        }
                        else if (m.coord.Y == 22) {
                            fill = !fill;
                        }
                    }
                    //if the user's mouse location was here, set shape = 0 (square)
                    if ((m.coord.X >= 88 && m.coord.X <= 92) && (m.coord.Y >= 4 && m.coord.Y <= 6)) {
                        var1 = 0;
                    }
                    //if the user's mouse location was here, set shape = 1 (circle)
                    if ((m.coord.X >= 94 && m.coord.X <= 98) && (m.coord.Y >= 4 && m.coord.Y <= 6)) {
                        var1 = 1;
                    }
                    //if the user's mouse location was here, set shape = 2 (diamond)
                    if (m.coord.X >= 88 && m.coord.X <= 92 && m.coord.Y >= 7 && m.coord.Y <= 12) {
                        var1 = 2;
                    }
                    //if the user's mouse location was here, set the color to what the user selected based on the coordinates
                    if (m.coord.X >= 88 && m.coord.X <= 90) {
                        if (m.coord.Y == 15) {
                            clr = black;
                        }
                        else if (m.coord.Y == 16) {
                            clr = red;
                        }
                        else if (m.coord.Y == 17) {
                            clr = gray;
                        }
                        else if (m.coord.Y == 18) {
                            clr = pink;
                        }
                        else {
                            break;
                        }
                    }
                    //if the user's mouse location was here, set the color to what the user selected based on the coordinates
                    if (m.coord.X >= 91 && m.coord.X <= 93) {
                        if (m.coord.Y == 15) {
                            clr = dblue;
                        }
                        else if (m.coord.Y == 16) {
                            clr = purple;
                        }
                        else if (m.coord.Y == 17) {
                            clr = lblue;
                        }
                        else if (m.coord.Y == 18) {
                            clr = lpurple;
                        }
                        else {
                            break;
                        }
                    }
                    //if the user's mouse location was here, set the color to what the user selected based on the coordinates
                    if (m.coord.X >= 94 && m.coord.X <= 96) {
                        if (m.coord.Y == 15) {
                            clr = green;
                        }
                        else if (m.coord.Y == 16) {
                            clr = gold;
                        }
                        else if (m.coord.Y == 17) {
                            clr = lgreen;
                        }
                        else if (m.coord.Y == 18) {
                            clr = tan;
                        }
                        else {
                            break;
                        }
                    }
                    //if the user's mouse location was here, set the color to what the user selected based on the coordinates
                    if (m.coord.X >= 97 && m.coord.X <= 99) {
                        if (m.coord.Y == 15) {
                            clr = turq;
                        }
                        else if (m.coord.Y == 16) {
                            clr = silver;
                        }
                        else if (m.coord.Y == 17) {
                            clr = cyan;
                        }
                        else if (m.coord.Y == 18) {
                            clr = white;
                        }
                        else {
                            break;
                        }
                    }
                    //if the user's mouse location was here (within the bounds of the canvas), store the x/y variables
                    if (m.coord.X >= 25 && m.coord.X <= 85 && m.coord.Y >= 3 && m.coord.Y <= 23) {
                        x1 = m.coord.X;
                        y1 = m.coord.Y;
                    }

                }

                else if (m.InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
                    fstream output("c:\\temp\\data.txt", ios::app);
                    //if the coordinates of the right click are within the canvas, the system will record the mouse's location
                    if (m.coord.X >= 25 && m.coord.X <= 86 && m.coord.Y >= 3 && m.coord.Y <= 24) {
                        y2 = m.InputRecord.Event.MouseEvent.dwMousePosition.Y;
                        x2 = m.InputRecord.Event.MouseEvent.dwMousePosition.X;
                        w = x2 - x1;
                        h = y2 - y1;
                        //if w or h < 0, the program will be unable to render an object because the variable will not print
                        //the following two 'if' statements are inverting the x1/x2 and y1/y2 values so that w and h will be positive and the object can be printed
                        if (w < 0) {
                            int e = x2;
                            x2 = x1;
                            x1 = e;
                            w = x2 - x1;
                        }
                        if (h < 0) {
                            int e = y2;
                            y2 = y1;
                            y1 = e;
                            h = y2 - y1;
                        }
                        //if var1 = 0, the object is a square/rectangle (four sided polygon), and will print one out
                        if (var1 == 0) {
                            MyRectangle R(x1, y1, w, h, 219, fill, clr, clr); //creating an object with the attributes as defined by the user's interation with the interface
                            R.Draw(); //printing the object

                            //the following two loops will store the value of the object into a text file, saving it for the future
                            if (counter > 9) { //if counter > 9, counter will reset so the object can be stored in array
                                
                                counter = 0;
                                save[counter] = new MyRectangle(x1, y1, w, h, 219, fill, clr, clr); //saving an object of class 'MyRectangle' within the array
                                //the following two lines of code are storing the variables from the MyRectangle Object into the text file defined by 'output'
                                output << " " << ((MyRectangle*)save[counter])->m_x << " "
                                    << ((MyRectangle*)save[counter])->m_y << " " << ((MyRectangle*)save[counter])->m_recColor
                                    << " " << ((MyRectangle*)save[counter])->m_textColor << " "
                                    << ((MyRectangle*)save[counter])->m_h << endl;
                                output.close();
                                counter++; //incrementing counter so the next object does not overwrite the previous
                            }
                            else {
                                save[counter] = new MyRectangle(x1, y1, w, h, 219, fill, clr, clr);//saving an object of class 'MyRectangle' within the array
                                //the following two lines of code are storing the variables from the MyRectangle Object into the text file defined by 'output'                                
                                output << ((MyRectangle*)save[counter])->m_x << " "
                                    << ((MyRectangle*)save[counter])->m_y << " " << ((MyRectangle*)save[counter])->m_w << " "
                                    << ((MyRectangle*)save[counter])->m_h << " " << ((MyRectangle*)save[counter])->m_textColor
                                    << endl;
                                output.close();
                                counter++; //incrementing counter so the next object does not overwrite the previous
                            }




                        }


                        //if var1 = 1, the object is a circle
                        if (var1 == 1) {
                            w /= 5; //reducing the radius of the object to ensure it does not print anything outside of the allocated canvas space
                            MyCircle C; //creating a circle object
                            C.m_x = x1; //assigning m_x
                            C.m_y = y1; //assigning m_y
                            C.m_radius = w; //assigning the radius
                            C.DrawCircle(); //printing the object                            
                        }
                        //if var1 = 2, the object is a diamond
                        if (var1 == 2) {
                            Diamond D; //creating the diamond object
                            m.gotoxy(x1, y1); //going to the starting location the user requested
                            D.DrawD(w, x1, y1, m); //printing the object with attributes as defined by user

                        }
                    }
                }


                //the following four lines of code are used to refresh the area within the interface that informs the user of the shape/color selected
                //this is done to prevent extra characters from staying around
                m.gotoxy(80, 25);
                cout << "      ";
                m.gotoxy(72, 25);
                cout << "       ";
                //if the color is black, the background will be set to white so the characters are visable
                if (clr != 0) {
                    m.setForeGroundAndBackGroundColor(clr, 0);
                }
                //else, set background to black and the characters to the color defined by user
                else {
                    m.setForeGroundAndBackGroundColor(clr, 15);
                }
                //the following four lines of code are displaying the shape and color to the user so they are aware of what they are doing
                m.gotoxy(80, 25);
                cout << pallet[clr];
                m.gotoxy(72, 25);
                cout << shape[var1];


            }
        }
    }
}
