//
//  main.cpp
//  SnakeGame
//
//  Group members: Muyuan Zhang, Mark Hale
//

#include "Snake.hpp"
#include "SnakeGame.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>//necessary?

//#include <iostream>
//#include "Fruit.hpp"
//#include <curses.h>

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
    
    const float wWidth = 1000;
    const float wHeight = 800;
    
    //creates a window
    sf::RenderWindow window( sf::VideoMode( wWidth, wHeight ), "My window" );
    window.setTitle( "S_N_A_K_E G_A_M_E" );
    //Fruit fruit;
    Snake snake( "/Users/computer/MSD/cs6010-labs/Day20/SnakeGame/SnakeGame/Sprites/snake.png" );
    //snake.setPosition( );
    sf::Sprite sprite;
    std::string mainFile = "/Users/computer/MSD/cs6010-labs/Day20/SnakeGame/SnakeGame/Sprites/tree1.png";
    std::string endFile = "/Users/computer/MSD/cs6010-labs/Day20/SnakeGame/SnakeGame/Sprites/gameover.png";
    SnakeGame game( mainFile, sprite, window );
    
    //throwing error don't know why
//    sf::SoundBuffer buffer;
//
//    if( !buffer.loadFromFile( "/Users/computer/MSD/cs6010-labs/Day20/SnakeGame/SnakeGame/Sprites/Ball.wav" ) ){
//        return -1;
//    }
//
//    sf::Sound sound;
//    sound.setBuffer( buffer );
    
    
    //runs the program as long as the window is open
    while ( window.isOpen( ) && !snake.gameOver( window ) )
    {
        //checks all the window's events that were triggered since the
        //last iteration of the loop
        sf::Event event;
        while( window.pollEvent( event ) )
        {
            //"close requested" event: we close the window
            if( event.type == sf::Event::Closed ){
                window.close( );
            }
        }
        
        //event listener that listens for keystrokes
        if( ( event.type == sf::Event::KeyPressed ) &&
           ( event.key.code == sf::Keyboard::Left ) ){
            snake.move( window, 'l' );
        }
        else if( ( event.type == sf::Event::KeyPressed ) && ( event.key.code == sf::Keyboard::Right ) ){
            snake.move( window, 'r' );
        }
        else if( ( event.type == sf::Event::KeyPressed ) && ( event.key.code == sf::Keyboard::Up ) ){
            snake.move( window, 'u' );
        }
        else if( ( event.type == sf::Event::KeyPressed ) && ( event.key.code == sf::Keyboard::Down ) ){
            snake.move( window, 'd' );
        }
        else{
            snake.move( window );
        }
        
        //clear the window with black color
        window.clear( sf::Color::White );
        //set the shape color to green
        //snake.setColor( );
        window.draw( sprite );
        snake.draw( window );
        //end the current frame
        window.display( );
    }
    window.clear( sf::Color::Black );
    sf::Sprite newSprite;
    newSprite.setScale( 1.0, 1.0 );
    SnakeGame newGame( endFile, newSprite, window );
    
    while ( window.isOpen( ) )
    {
        //checks all the window's events that were triggered since the
        //last iteration of the loop
        sf::Event event;
        while( window.pollEvent( event ) )
        {
            //"close requested" event: we close the window
            if( event.type == sf::Event::Closed ){
                window.close( );
            }
        }
        window.clear( sf::Color::Black );
        window.draw( newSprite );
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
