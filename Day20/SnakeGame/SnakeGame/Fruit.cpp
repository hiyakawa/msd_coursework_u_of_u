//
//  Fruit.cpp
//  SnakeGame
//
//  Created by Laura Zhang on 9/21/22.
//

#include "Fruit.hpp"

Fruit::Fruit(){
    // set the size of the fruit the same as the initial snake
    _size = 15;
    
    shape.setSize({15.f, 15.f});
    
    // set the fruit to be at a random location inside the border
    shape.setPosition((rand() % 800) * 15, (rand() % 600) * 15);
    
    // set the snake to be white
    shape.setFillColor(sf::Color::White);
}

void Fruit::draw(sf::RenderTarget& fruit, sf::RenderStates state) const {
    target.draw(fruit, state);
}
