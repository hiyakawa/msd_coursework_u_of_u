//
//  SnakeGame.hpp
//  SnakeGame
//
//  Group members: Muyuan Zhang, Mark Hale
//

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
