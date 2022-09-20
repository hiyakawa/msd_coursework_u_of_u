//
//  main.cpp
//  SnakeGame
//
//  Group members: Muyuan Zhang, Mark Hale
//

#include "Fruit.hpp"

#include <curses.h>
#include <iostream>

using namespace std;

//#define KEY_UP 72
//#define KEY_DOWN 80
//#define KEY_LEFT 75
//#define KEY_RIGHT 77

int main( int argc, const char * argv[] ) {
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
    

    
    //code from Day18 lab:
    
    //create the window
    sf::RenderWindow window( sf::VideoMode( 800, 600 ), "My window" );
    //run the program as long as the window is open
    while ( window.isOpen( ) )
    {
        //check all the window's events that were triggered since the
        //last
        //iteration of the loop
        sf::Event event;
        while ( window.pollEvent( event ) )
        {
            //"close requested" event: we close the window
            if ( event.type == sf::Event::Closed )
                window.close( );
        }
        //clear the window with black color
        window.clear( sf::Color::Black );
        Snake snake( 50.f );
        //set the shape color to green
        snake.setFillColor( sf::Color( 100, 250, 50 ) );
        
        //Code added here:
        //event listener that listens for keystrokes
        if( event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Left ){
            
            //snake.moveLeft(window);
            
        }
        
        window.draw( snake );
        //end the current frame
        window.display( );
    }
    
    return 0;
}





/*Bells and Whistles to consider if we have time:

1. maybe the fruit/apples are different colors and when snake eats them the part of him that grows changes to that color so he turns into a rainbow snake
2. snake's speed increases over increments of time
3. add music/speed up music as game progresses
4. add maze objects that are kill spots to avoid or bad fuit/appples that are kill events
5. add a 2d avatar/stencil to snake body or head or objects eaten
 */


