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

void Snake::setColor( ){
    snakeStub.setFillColor( sf::Color( 100, 250, 50 ) );
}

void Snake::draw( sf::RenderWindow& window ){
    window.draw( snakeStub );
}

void Snake::setPosition(){
    snakeStub.setPosition( 100, 50 );
}

//move functions which takes in a RenderWindow object window
void Snake::moveLeft( sf::RenderWindow& window ){
    float xAxis = snakeStub.getPosition( ).x;
    if( xAxis >= 0 ){
        snakeStub.move( sf::Vector2f( -0.1, 0.0 ) );
    }
}

void Snake::moveRight( sf::RenderWindow& window ){
    float xAxis = snakeStub.getPosition( ).x;
    float width = window.getSize( ).x;
    float leftOfHead = snakeStub.getSize().x;
    if( xAxis < ( width - leftOfHead ) ){
        snakeStub.move( sf::Vector2f( 0.1, 0.0 ) );
    }
}
void Snake::moveUp( sf::RenderWindow& window ){
    float xAxis = snakeStub.getPosition( ).x;
    float width = window.getSize( ).x;
    float leftOfHead = snakeStub.getSize().x;
    if( xAxis < ( width - leftOfHead ) ){
        snakeStub.move( sf::Vector2f( 0.0, 0.1 ) );
    }
}
void Snake::moveDown( sf::RenderWindow& window ){
    float xAxis = snakeStub.getPosition( ).x;
    float width = window.getSize( ).x;
    float leftOfHead = snakeStub.getSize().x;
    if( xAxis < ( width - leftOfHead ) ){
        snakeStub.move( sf::Vector2f( 0.0, -0.1 ) );
    }
}
