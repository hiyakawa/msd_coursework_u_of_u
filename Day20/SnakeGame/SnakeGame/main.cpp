//
//  main.cpp
//  SnakeGame
//
//  Created by Laura Zhang on 9/19/22.
//

#include "SnakeGame.hpp"

#include <curses.h>
#include <iostream>
#include <SFML/Graphics.hpp>

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
    
    //Laura, this is code from Day18 lab:
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the
        //last
        //iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // clear the window with black color
        window.clear(sf::Color::Black);
        sf::CircleShape shape(50.f);
        // set the shape color to green
        shape.setFillColor(sf::Color(100, 250, 50));
        window.draw(shape);
        // end the current frame
        window.display();
    }
    
    return 0;
}

// press Q to quit the game
// press N to start a new game
