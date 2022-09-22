//
//  Fruit.cpp
//  SnakeGame
//
//  Created by Laura Zhang on 9/21/22.
//

#include "Fruit.hpp"

Fruit::Fruit( ){
    fruit.setSize(sf::Vector2f(15, 15));
}

void Fruit::setColor( ){
    fruit.setFillColor(sf::Color(250, 0, 0));
}

//draws the snake object to the window
void Fruit::draw( sf::RenderWindow& window ){
    window.draw(fruit);
}

//sets the initial position of the snake
void Fruit::setPosition(){
    // set random coordinate for fruit
    unsigned int x_coo = rand() % 985 + 15;
    unsigned int y_coo = rand() % 785 + 15;
    
    fruit.setPosition(x_coo, y_coo);
}
