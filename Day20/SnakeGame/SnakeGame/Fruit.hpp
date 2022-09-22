//
//  Fruit.hpp
//  SnakeGame
//
//  Created by Laura Zhang on 9/21/22.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>

class Fruit {
private:
    sf::RectangleShape fruit;
    
public:
    Fruit();
    void setColor();
    void setPosition() ;
    void draw( sf::RenderWindow& window );
};
