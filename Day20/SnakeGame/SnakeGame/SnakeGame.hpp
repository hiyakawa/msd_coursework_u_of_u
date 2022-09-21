#pragma once

#ifndef SnakeGame_hpp
#define SnakeGame_hpp

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

struct Location {
    unsigned int x_coo, y_coo;
};
//
//MAY I TAKE THIS CODE OUT? I HAVE A SNAKE OBJECT WITH BASIC FUNCTIONALITY THAT I WILL IMPROVE TOMORROW.
//

//<<<<<<< HEAD
//class Snake {
//private:
//    unsigned int _length;
//    const unsigned int k_max_length = 300;
//    unsigned int _speed;
//    MoveDirection _next_move_direction;
//    std::vector<Location> _movement_loc;
//    std::vector<Location> _head_loc;
//    bool isRunning;
//
//public:
//    Snake() {
//        _length = 5;
//    }
//
//    void getMovement(MoveDirection move_direction);
//    unsigned int growSnake(unsigned int fruit_size);
//    bool isTouchingItself();
//};


//I COMMENTED THIS OUT BECAUSE IT IS STOPPING THE COMPILER. DO YOU THINK YOU WILL HAVE A WORKING RANDOMIZED FRUIT CLASS WEDNESDAY?

//class Fruit {
//private:
//    unsigned int _size;
//    std::vector<Location> _location;
//
//};

//PLEASE RUN AND SEE THE SNAKE AS IS FOR NOW.

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
