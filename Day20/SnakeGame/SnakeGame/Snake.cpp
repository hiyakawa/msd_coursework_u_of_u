//
//  Snake.cpp
//  SnakeGame
//
//  Created by Mark Hale on 9/19/22.
//

#include "Snake.hpp"

char cardinalDirection;

//a default constructor to instantiate the fields of the class member variables
Snake::Snake( ){
    snakeStub.setSize( sf::Vector2f( 15, 15 ) );
}

//sets the color of the snake object
void Snake::setColor( ){
    snakeStub.setFillColor( sf::Color( 100, 250, 50 ) );
}

//draws the snake object to the window
void Snake::draw( sf::RenderWindow& window ){
    window.draw( snakeStub );
}

//sets the initial position of the snake
void Snake::setPosition(){
    snakeStub.setPosition( 100, 50 );
}

//keeps snake object moving in the direction it was last heading
void Snake::move( sf::RenderWindow& window ){
    Snake::move( window, cardinalDirection );//cardinal ie N,E,S,W
}


//changes snake diretional velocity based upon keystrokes
void Snake::move( sf::RenderWindow& window, char direction ){
    
    float xAxis = snakeStub.getPosition( ).x;
    float yAxis = snakeStub.getPosition( ).y;
    float snakeX = snakeStub.getSize().x;
    float snakeY = snakeStub.getSize().y;
    float width = window.getSize( ).x;
    float height = window.getSize( ).y;
    cardinalDirection = direction;
    
    if( direction == 'd'){
        
        if( yAxis < ( height - snakeY ) ){
            snakeStub.move( sf::Vector2f( 0.0, 0.1 ) );
        }
    }
    
    if( direction == 'u'){
        
        if( yAxis > 0 ){
            snakeStub.move( sf::Vector2f( 0.0, -0.1 ) );
        }
    }
    
    if( direction == 'r'){
        
        if( xAxis < ( width - snakeX ) ){
            snakeStub.move( sf::Vector2f( 0.1, 0.0 ) );
        }
    }
    
    if( direction == 'l'){
        
        if( xAxis > 0 ){
            snakeStub.move( sf::Vector2f( -0.1, 0.0 ) );
        }
    }
    
    //else
    
}
