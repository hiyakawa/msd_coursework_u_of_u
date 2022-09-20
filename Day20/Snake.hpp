//
//  Snake.hpp
//  SnakeGame
//
//  Created by Mark Hale on 9/19/22.
//

#ifndef Snake_hpp
#define Snake_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Snake{
    
private:
    //beginning of a snake obj
    sf::RectangleShape snakeStub;

public:
    //default constructor
    Snake( );
    
    //move functions which take in the sf library class object window via reference
    void moveLeft( sf::RenderWindow& window );
    void moveRight( sf::RenderWindow& window );
    void moveUp( sf::RenderWindow& window );
    void moveDown( sf::RenderWindow& window );
};

#endif /* Snake_hpp */
