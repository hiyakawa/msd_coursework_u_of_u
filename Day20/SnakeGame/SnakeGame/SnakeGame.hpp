#pragma once

#include <SFML/Graphics.hpp>

class SnakeGame{
private:
    sf::Texture texture;
    sf::Image background;
    
public:
    SnakeGame( );
    SnakeGame( std::string file, sf::Sprite& sprite, sf::Window& window );
};

// press Q to quit the game
// press N to start a new game
