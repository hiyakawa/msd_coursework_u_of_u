#pragma once

#ifndef Snake_hpp
#define Snake_hpp

#include "SnakeGame.hpp"

class Snake {
private:
    unsigned int _length;
    const unsigned int k_max_length = 300;
    unsigned int _speed;
    MoveDirection _next_move_direction;
    std::vector<Location> _movement_loc;
    std::vector<Location> _head_loc;
    bool isRunning;
    
    //beginning of a snake obj
    sf::RectangleShape snakeStub;
    
public:
    //default constructor
    Snake();
    
    void getMovement(MoveDirection move_direction);
    unsigned int growSnake(unsigned int fruit_size);
    bool isTouchingItself();
    
    //move functions which take in the sf library class object window via reference
    void moveLeft( sf::RenderWindow& window );
    void moveRight( sf::RenderWindow& window );
    void moveUp( sf::RenderWindow& window );
    void moveDown( sf::RenderWindow& window );
};

enum Directions {
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
}

#endif /* Snake_hpp */
