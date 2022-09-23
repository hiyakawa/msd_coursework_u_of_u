//
//  SnakeGame.cpp
//  SnakeGame
//
//  Group members: Muyuan Zhang, Mark Hale
//

#include "SnakeGame.hpp"
using namespace std;

SnakeGame::SnakeGame( string file, sf::Sprite& sprite, sf::Window& window ){
    background.loadFromFile( file );
    texture.loadFromImage( background );
    sprite.setTexture( texture );
    sprite.setScale( 1.1, 1.0 );
    sprite.setPosition( window.getSize( ).x - sprite.getGlobalBounds( ).width* 1.25, window.getSize( ).y - sprite.getGlobalBounds( ).height* 1.2 );
}
