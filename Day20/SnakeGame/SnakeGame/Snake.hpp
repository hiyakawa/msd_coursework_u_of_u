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
    
    void move( sf::RenderWindow& window );
    void move( sf::RenderWindow& window, char direction );
    void gameOver( sf::RenderWindow& window );

};

#endif /* Snake_hpp */
