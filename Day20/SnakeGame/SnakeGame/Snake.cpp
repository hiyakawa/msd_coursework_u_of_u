//
//  Snake.cpp
//  SnakeGame
//
//  Created by Mark Hale on 9/19/22.
//

#include "Snake.hpp"
#include "Fruit.hpp"
#include <iostream>

char cardinalDirection;

//a default constructor to instantiate the fields of the class member variables
Snake::Snake( std::string file ){
    background.loadFromFile( file );
    texture.loadFromImage( background );
    sprite.setTexture( texture );
    sprite.setScale( 0.1, 0.1 );
    sprite.setPosition( 200.0, 500.0 );
    //stops the first while loop ie go to new window
    isGameOver = false;
    //resets the cardinal direction upon game restart
    cardinalDirection = ' ';
}

//sets the color of the snake object
void Snake::setColor( ){
    snakeStub.setFillColor( sf::Color( 100, 250, 50 ) );
}

//draws the snake object to the window
void Snake::draw( sf::RenderWindow& window ){
    window.draw( sprite );
}

//sets the initial position of the snake
//void Snake::setPosition( ){
//    snakeStub.setPosition( 100, 50 );
//}

//keeps snake object moving in the direction it was last heading
void Snake::move( sf::RenderWindow& window ){
    Snake::move( window, cardinalDirection );//cardinal ie N,E,S,W
}


//changes snake diretional velocity based upon keystrokes
void Snake::move( sf::RenderWindow& window, char direction ){
    
    float xAxis = sprite.getPosition( ).x;
    float yAxis = sprite.getPosition( ).y;
    float width = window.getSize( ).x;
    float height = window.getSize( ).y;
    cardinalDirection = direction;
    
    if( xAxis < width && xAxis > 0 && yAxis < height && yAxis > 0 ){
        
        if( direction == 'd'){
            
            if( yAxis < height ){
                sprite.move( sf::Vector2f( 0.0, 0.15 ) );
            }
        }
        
        else if( direction == 'u'){
            
            if( yAxis > 0 ){
                sprite.move( sf::Vector2f( 0.0, -0.15 ) );
            }
        }
        
        else if( direction == 'r' ){
            
            if( xAxis < width ){
                sprite.move( sf::Vector2f( 0.15, 0.0 ) );
            }
        }
        
        else if( direction == 'l'){
            
            if( xAxis > 0 ){
                sprite.move( sf::Vector2f( -0.15, 0.0 ) );
            }
        }
    }
    else {
        isGameOver = true;
        gameOver( window );
    }
}

//terminates while loop
bool Snake::gameOver( sf::RenderWindow& window ){
    window.clear( sf::Color::Black );
    //triggers next while loop
    return isGameOver;
}
