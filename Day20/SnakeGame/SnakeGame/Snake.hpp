#pragma once

#ifndef Snake_hpp
#define Snake_hpp
#include <stdio.h>
#include <SFML/Graphics.hpp>

class Snake {
private:

    sf::RectangleShape snakeStub;
    bool isGameOver;
    sf::Texture texture;
    sf::Image background;
    sf::Sprite sprite;
    
public:
    //default constructor
    Snake( );
    Snake( std::string file );
    
    void setColor( );
    void setPosition( ) ;
    void draw( sf::RenderWindow& window );
    
    void move( sf::RenderWindow& window );
    void move( sf::RenderWindow& window, char direction );
    bool gameOver( sf::RenderWindow& window );

};

#endif /* Snake_hpp */
