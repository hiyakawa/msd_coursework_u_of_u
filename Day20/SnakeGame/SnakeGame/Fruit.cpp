//
//  Fruit.cpp
//  SnakeGame
//
//  Group members: Muyuan Zhang, Mark Hale
//

#include "Fruit.hpp"
#include <SFML/Graphics.hpp>

//default constructor for fruit object
Fruit::Fruit( ){
    fruit.setSize( sf::Vector2f( 15, 15 ) );
}
//constructor for fruit object
Fruit::Fruit( std:: string file ){
    background.loadFromFile( file );
    texture.loadFromImage( background );
    apple.setTexture( texture );
    apple.setScale( 0.015, 0.015 );
    apple.setPosition( 200.0, 300.0 );
}
//draws the snake object to the window
void Fruit::draw( sf::RenderWindow& window ){
    window.draw( apple );
}
//sets the initial position of the snake
void Fruit::setPosition( ){
    // set random coordinate for fruit // not working
    unsigned int x_coo = ( rand( ) % 985 + 15 );
    unsigned int y_coo = ( rand( ) % 785 + 15 );

    if( x_coo < 10 || x_coo > 990 ){
        x_coo = rand( ) % 985 + 15;
    }
    if( y_coo < 10 || y_coo > 750 ){
        y_coo = rand( ) % 785 + 15;
    }
    
    apple.setPosition( x_coo, y_coo );
}
//returns the apple sprite used in setPosition()
sf::Sprite Fruit::getSprite( ){
    return apple;
}
//returns the apple perimeter used in setPosition()
sf::Rect<float> Fruit::getGlobalBounds( ){
    return apple.getGlobalBounds();
}
