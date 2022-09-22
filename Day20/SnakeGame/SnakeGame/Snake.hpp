#pragma once

#include <SFML/Graphics.hpp>

class Snake {
private:
    sf::RectangleShape snakeStub;
    bool isGameOver;
    sf::Texture texture;
    sf::Image background;
    sf::Sprite sprite;
    
public:
    Snake( );
    Snake( std::string file );
    
    void setColor( );
    void setPosition( ) ;
    void draw( sf::RenderWindow& window );
    
    void move( sf::RenderWindow& window );
    void move( sf::RenderWindow& window, char direction );
    bool gameOver( sf::RenderWindow& window );

};
