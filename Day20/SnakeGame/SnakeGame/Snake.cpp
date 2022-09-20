//
//  Snake.cpp
//  SnakeGame
//
//  Created by Mark Hale on 9/19/22.
//

#include "Snake.hpp"
#include <SFML/Graphics.hpp>

//a default constructor to instantiate the fields of the class member variables
Snake::Snake( ){
    snakeStub.setSize( sf::Vector2f( 50,75 ) );
}



//move functions which take in the sf library class object window via reference
void moveLeft( sf::RenderWindow& window );
void moveRight( sf::RenderWindow& window );
void moveUp( sf::RenderWindow& window );
void moveDown( sf::RenderWindow& window );

