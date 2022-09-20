#pragma once

#ifndef SnakeGame_hpp
#define SnakeGame_hpp

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

struct Location {
    unsigned int x_coo, y_coo;
};

class Border {
private:
    unsigned int _width, _height;
    unsigned int _left_bound,
                 _right_bound,
                 _top_bound,
                 _bottom_bound;
    
public:
    Border() {
        _width = 30;
        _height = 30;
        _left_bound = 0;
        _right_bound = 30;
        _top_bound = 30;
        _bottom_bound = 0;
    }
    
    bool isOutOfBound();
};

class Player {
private:
    unsigned int _score;
    unsigned int _level;
    unsigned int _lives_left;
    std::string _name;
    
};

enum Results {
    OutOfBound = 1,
    SelfCollision = 2,
    ReachMaxLength = 0,
};

// press Q to quit the game
// press N to start a new game

#endif /* SnakeGame_hpp */
