//
//  main.cpp
//  SnakeGame
//
//  Group members: Muyuan Zhang, Mark Hale
//

#include "Snake.hpp"
#include "SnakeGame.hpp"
#include <SFML/Audio.hpp>
#include "Fruit.hpp"
using namespace std;
#include <iostream>

int main( int argc, const char * argv[] ) {
    
    const float wWidth = 1000;
    const float wHeight = 800;
    int score = 0;
    
    //creates a window for displaying game objects
    sf::RenderWindow window( sf::VideoMode( wWidth, wHeight ), "My window" );
    window.setTitle( "S_N_A_K_E G_A_M_E" );
    //creats a snake object that uses a sprite
    Snake snake( "/Users/computer/MSD/cs6010-labs/Day20/SnakeGame/SnakeGame/Sprites/snake.png" );
    sf::Sprite treeSprite;
    std::string treeFile = "/Users/computer/MSD/cs6010-labs/Day20/SnakeGame/SnakeGame/Sprites/tree1.png";
    std::string endGameFile = "/Users/computer/MSD/cs6010-labs/Day20/SnakeGame/SnakeGame/Sprites/gameover.png";
    //sets window for gameplay
    SnakeGame game( treeFile, treeSprite, window );
    std::string appleFile = "/Users/computer/MSD/cs6010-labs/Day20/SnakeGame/SnakeGame/Sprites/app.png";
    Fruit fruit( appleFile );
    //inactive apple generation
    vector<Fruit> basket;
    for( int i = 0; i < 5; i++ ){
        Fruit f;
        f.setPosition( i, window );
        basket.push_back( f );
    }
    
    //inactive soundbuffer for playing game sounds
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
        //checks all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while( window.pollEvent( event ) )
        {
            //player exit for game
            if( event.type == sf::Event::Closed ){
                window.close( );
            }
        }
        //event listener that listens for directional keystrokes
        if( ( event.type == sf::Event::KeyPressed ) &&
           ( event.key.code == sf::Keyboard::Left ) ){
            snake.move( window, 'l' );//left
        }
        else if( ( event.type == sf::Event::KeyPressed ) && ( event.key.code == sf::Keyboard::Right ) ){
            snake.move( window, 'r' );//right
        }
        else if( ( event.type == sf::Event::KeyPressed ) && ( event.key.code == sf::Keyboard::Up ) ){
            snake.move( window, 'u' );//up
        }
        else if( ( event.type == sf::Event::KeyPressed ) && ( event.key.code == sf::Keyboard::Down ) ){
            snake.move( window, 'd' );//down
        }
        else{//keeps snake moving once movement initialized
            snake.move( window );
        }
        //fills the window with cyan color
        window.clear( sf::Color::Cyan );
        
        //inactive functionality of relocating apple objects and keeping score
        if( !eatMe( snake, fruit ) ){
        //draws the fruit object
        fruit.draw( window );
        }
        else{
           
        }
        
        //draws tree object
        window.draw( treeSprite );
        snake.draw( window );
        //shows all objects on screen
        window.display( );
    }
    
    //renders game over screen
    window.clear( sf::Color::Black );
    sf::Sprite newSprite;
    newSprite.setScale( 1.0, 1.0 );
    SnakeGame newGame( endGameFile, newSprite, window );
    
    //listens for key events
    while ( window.isOpen( ) )
    {
        //checks all window events triggered since last iteration of the loop
        sf::Event event;
        while( window.pollEvent( event ) )
        {
            //closes game window
            if( event.type == sf::Event::Closed ){
                window.close( );
            }
            //restarts game by listening for the return key
            if( event.key.code == sf::Keyboard::Return ){
                main( argc, argv );//wanted arguments
            }
            //ends game through listening for the escape key
            if( event.key.code == sf::Keyboard::Escape ){
                window.close( );
            }
        }
        //creates game over window
        window.clear( sf::Color::White );
        window.draw( newSprite );
        window.display( );
    }
    
    return 0;
}
