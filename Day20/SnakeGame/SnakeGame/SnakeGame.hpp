//
//  SnakeGame.hpp
//  SnakeGame
//
//  Created by Laura Zhang on 9/19/22.
//

#ifndef SnakeGame_hpp
#define SnakeGame_hpp

#include <string>
#include <vector>

enum MoveDirection {
    Up,
    Down,
    Left,
    Right,
};

enum Color {
    
};

enum Results {
    OutOfBound = 1,
    SelfCollision = 2,
    ReachMaxLength = 0,
};

struct Location {
    unsigned int x_coo, y_coo;
};

class Snake {
private:
    unsigned int _length;
    const unsigned int k_max_length = 300;
    unsigned int _speed;
    MoveDirection _next_move_direction;
    std::vector<Location> _movement_loc;
    std::vector<Location> _head_loc;
    bool isRunning;
    
public:
    Snake() {
        _length = 5;
    }
    
    void getMovement(MoveDirection move_direction);
    unsigned int growSnake(unsigned int fruit_size);
    bool isTouchingItself();
};

class Fruit {
private:
    unsigned int _size;
    std::vector<Location> _location;
    
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

#endif /* SnakeGame_hpp */
