//
//  main.cpp
//  SnakeGame
//
//  Created by Laura Zhang on 9/19/22.
//

#include "SnakeGame.hpp"

#include <curses.h>
#include <iostream>

using namespace std;

#define KEY_UP 38
#define KEY_DOWN 40
#define KEY_LEFT 37
#define KEY_RIGHT 39


//    left arrow: 37
//    up arrow: 38
//    right arrow: 39
//    down arrow: 40

//#define KEY_UP 72
//#define KEY_DOWN 80
//#define KEY_LEFT 75
//#define KEY_RIGHT 77

int main(int argc, const char * argv[]) {
    /*
     -------
            |
            |
            ------------
     head x1, y1
     angle1 x2, y1
     x1 - x2
     
     angle2 x2, y2
     y2 - y1
     
     - length + x1 + y2 - y1
     x1 - y1 + y2 -length
     
     tail (x1 - y1 + y2 -length, y2)
     
     */
    
    /*
    cout << "running" << endl;
    
    int c = getchar();
    
    switch((c = getchar())) {
    case KEY_UP:
        cout << endl << "Up" << endl;//key up
        break;
    case KEY_DOWN:
        cout << endl << "Down" << endl;   // key down
        break;
    case KEY_LEFT:
        cout << endl << "Left" << endl;  // key left
        break;
    case KEY_RIGHT:
        cout << endl << "Right" << endl;  // key right
        break;
    default:
        cout << endl << "null" << endl;  // not arrow
        break;
    }
     */
    
    return 0;
}

// press Q to quit the game
// press N to start a new game
