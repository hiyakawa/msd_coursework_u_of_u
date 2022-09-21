#pragma once

#ifndef Snake_hpp
#define Snake_hpp
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "SnakeGame.hpp"

class Snake {
private:

    sf::RectangleShape snakeStub;
    
public:
    //default constructor
    Snake( );
    void setColor( );
    void setPosition( ) ;
    void draw( sf::RenderWindow& window );
    
    //move functions which take in the sf library class object window via reference
    void moveLeft( sf::RenderWindow& window );
    void moveRight( sf::RenderWindow& window );
    void moveUp( sf::RenderWindow& window );
    void moveDown( sf::RenderWindow& window );
};

#endif /* Snake_hpp */
