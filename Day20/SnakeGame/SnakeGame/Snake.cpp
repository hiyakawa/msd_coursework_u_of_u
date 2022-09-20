//
//  Snake.cpp
//  SnakeGame
//
//  Created by Mark Hale on 9/19/22.
//

#include "Snake.hpp"
#include <SFML/Graphics.hpp>

//a default constructor to instantiate the fields of the class member variables
Snake::Snake(){
    snakeStub.setSize(sf::Vector2f(50, 75));
}



//move functions which take in the sf library class object window via reference
void moveLeft( sf::RenderWindow& window );
void moveRight( sf::RenderWindow& window );
void moveUp( sf::RenderWindow& window );
void moveDown( sf::RenderWindow& window );

void changeDirection(char key) {
    switch(key) {
    case KEY_UP:
        cout << endl << "Up" << endl;//key up
        break;
    case KEY_DOWN:
        cout << endl << "Down" << endl;   // key down
        break;
    case KEY_LEFT:
        cout << endl << "Left" << endl;  // key left
        break;
    case KEY_RIGHT:
        cout << endl << "Right" << endl;  // key right
        break;
    default:
        cout << endl << "null" << endl;  // not arrow
        break;
}
