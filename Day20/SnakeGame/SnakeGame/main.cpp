//
//  main.cpp
//  SnakeGame
//
//  Group members: Muyuan Zhang, Mark Hale
//

//#include "SnakeGame.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"

#include <curses.h>
#include <iostream>

using namespace std;

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
    
    //creates a window
    sf::RenderWindow window( sf::VideoMode( 800, 600 ), "My window" );
    
    Snake snake;
    snake.setPosition( );
    
    //runs the program as long as the window is open
    while ( window.isOpen( ) )
    {
        //checks all the window's events that were triggered since the
        //last iteration of the loop
        sf::Event event;
        while ( window.pollEvent( event ) )
        {
            //"close requested" event: we close the window
            if ( event.type == sf::Event::Closed )
                window.close( );
        }
        //clear the window with black color
        window.clear( sf::Color::Black );
        //set the shape color to green
        snake.setColor( );
        
        //event listener that listens for keystrokes
        if( event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Left ){
            snake.moveLeft( window );
        }
        else if( ( event.type == sf::Event::KeyPressed ) && ( event.key.code == sf::Keyboard::Right ) ){
            snake.moveRight( window );
        }
        
        //Up and Down are currently going out of bounds I will continue to troublble shoot this
        else if( ( event.type == sf::Event::KeyPressed ) && ( event.key.code == sf::Keyboard::Up ) ){
            snake.moveUp( window );
        }
        else if( ( event.type == sf::Event::KeyPressed ) && ( event.key.code == sf::Keyboard::Down ) ){
            snake.moveDown( window );
        }
        
        snake.draw( window );
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
