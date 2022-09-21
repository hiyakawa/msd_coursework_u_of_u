//
//  Snake.cpp
//  SnakeGame
//
//  Created by Mark Hale on 9/19/22.
//

#include "Snake.hpp"

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

//left movement functionality
void Snake::moveLeft( sf::RenderWindow& window ){
    float xAxis = snakeStub.getPosition( ).x;
    if( xAxis >= 0 ){
        snakeStub.move( sf::Vector2f( -0.1, 0.0 ) );
    }
}

//right movement functionality
void Snake::moveRight( sf::RenderWindow& window ){
    float xAxis = snakeStub.getPosition( ).x;
    float width = window.getSize( ).x;
    float leftOfHead = snakeStub.getSize().x;
    if( xAxis < ( width - leftOfHead ) ){
        snakeStub.move( sf::Vector2f( 0.1, 0.0 ) );
    }
}

//up movement functionality
void Snake::moveUp( sf::RenderWindow& window ){
    float xAxis = snakeStub.getPosition( ).x;
    float width = window.getSize( ).x;
    float leftOfHead = snakeStub.getSize().x;
    if( xAxis < ( width - leftOfHead ) ){
        snakeStub.move( sf::Vector2f( 0.0, 0.1 ) );
    }
}
//down movement functionality
void Snake::moveDown( sf::RenderWindow& window ){
    float xAxis = snakeStub.getPosition( ).x;
    float width = window.getSize( ).x;
    float leftOfHead = snakeStub.getSize().x;
    if( xAxis < ( width - leftOfHead ) ){
        snakeStub.move( sf::Vector2f( 0.0, -0.1 ) );
    }
}
