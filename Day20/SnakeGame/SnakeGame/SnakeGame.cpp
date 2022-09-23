//
//  SnakeGame.cpp
//  Final Project
//  SnakeGame
//
//  Group members: Muyuan Zhang, Mark Hale
//

#include "SnakeGame.hpp"
#include "Snake.hpp"
#include "Fruit.hpp"
using namespace std;

//empty default constructor
SnakeGame::SnakeGame( ){ }

SnakeGame::SnakeGame( string file, sf::Sprite& sprite, sf::Window& window ){
    background.loadFromFile( file );
    texture.loadFromImage( background );
    sprite.setTexture( texture );
    sprite.setScale( 1.1, 1.0 );
    sprite.setPosition( window.getSize( ).x - sprite.getGlobalBounds( ).width* 1.25, window.getSize( ).y - sprite.getGlobalBounds( ).height* 1.2 );
}

//main snake game functionality
void SnakeGame::MakeGame( ){
    
    const float wWidth = 1000;
    const float wHeight = 800;
    score = 0;
    
    //creates a window for displaying game objects
    sf::RenderWindow window( sf::VideoMode( wWidth, wHeight ), "My window" );
    window.setTitle( "S_N_A_K_E G_A_M_E" );
    //creats a snake object that uses a sprite
    Snake snake( "/Users/computer/MSD/cs6010-labs/Day20/SnakeGame/SnakeGame/Sprites/snake.png" );
    std::string treeFile = "/Users/computer/MSD/cs6010-labs/Day20/SnakeGame/SnakeGame/Sprites/tree1.png";
    
    //sets window for gameplay
    SnakeGame game( treeFile, treeSprite, window );
    std::string appleFile = "/Users/computer/MSD/cs6010-labs/Day20/SnakeGame/SnakeGame/Sprites/app.png";
    Fruit fruit( appleFile );
    
    //incomplete dynamic apple generation
    vector<Fruit> basket;
    for( int i = 0; i < 5; i++ ){
        Fruit f;
        f.setPosition( );
        basket.push_back( f );
    }
    
    //non-functioning soundbuffer for playing game sounds
    //    sf::SoundBuffer buffer;
    //
    //    if( !buffer.loadFromFile( "/Users/computer/MSD/cs6010-labs/Day20/SnakeGame/SnakeGame/Sprites/Ball.wav" ) ){
    //        return -1;
    //    }
    //
    //    sf::Sound sound;
    //    sound.setBuffer( buffer );
    
    //chaining call to help abstract main
    renderWindow( window, snake, fruit );
}
//displaying sprites and listening for key events
void SnakeGame::renderWindow( sf::RenderWindow& window, Snake& snake, Fruit& fruit ){
    //CHANGED FROM A BOOLEAN TO A REPOSITIONIONING OF THE APPLE
    //collision condition
    //bool removeApple = false;
    
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
        //draws tree object
        window.draw( treeSprite );  //MOVED THE TREE BEFORE THE APPLE SO THE APPLE DISPLAYS IN FRONT OF TREE
        //draws and removes apple object
        if( !eatMe( snake, fruit ) /*&& !removeApple */){
            //draws the fruit object
            fruit.draw( window );
        }
        else{
            //INSTEAD OF REMOVING THE APPLE MOVE IT SO IT REAPPEARS ELSEWHERE ON THE SCREEN
//            removeApple = true;
            score++;
            fruit.setPosition( );
        }
        snake.draw( window );
        //shows all objects on screen
        window.display( );
    }
    endGame( window );
}
//game over window generator
void SnakeGame::endGame( sf::RenderWindow& window ){
    std::string endGameFile = "/Users/computer/MSD/cs6010-labs/Day20/SnakeGame/SnakeGame/Sprites/gameover.png";
    //renders game over screen
    window.clear( sf::Color::Black );
    
    //ADDED SCORE PRINTOUT IN GAME OVER WINDOW
    window.setTitle( "G_A_M_E  O_V_E_R     Score: "  + to_string( score ));
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
        }
        
        //MOVED THESE IF STATEMENTS OUTSIDE OF THE WHILE LOOP TO MAKE PLAY FASTER
        //restarts game by listening for the return key
        if( event.key.code == sf::Keyboard::Return ){
            MakeGame();
        }
        //ends game through listening for the escape key
        if( event.key.code == sf::Keyboard::Escape ){
            window.close( );
        }
        //creates game over window
        window.clear( sf::Color::White );
        window.draw( newSprite );
        window.display( );
    }
}
