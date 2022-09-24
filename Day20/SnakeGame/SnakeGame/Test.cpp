#pragma once
#include "Test.hpp"
#include "Snake.hpp"
#include "SnakeGame.hpp"
#include "Fruit.hpp"
#include <SFML/Graphics.hpp>

// (test files and SFML/Audio library) currently not being seen (had same problem with Fruit class)
Test::Test(){
    RunTest();
}
//tests the constructors of each class
void Test::RunTest(){
    //test set-up
    sf::Texture texture;
    sf::Image background;
    sf::Sprite treeSprite;
    sf::Sprite newSprite;
    background.loadFromFile( file );
    texture.loadFromImage( background );
    //object tests
    Snake slithers;
    slithers.setTexture( texture );
    slithers.setScale( 1.1, 1.0 );
    Fruit banana;
    banana.setTexture( texture );
    banana.setScale( 1.1, 1.0 );
}
