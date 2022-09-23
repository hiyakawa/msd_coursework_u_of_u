#include "Test.hpp"
#include "Snake.hpp"
#include "SnakeGame.hpp"
#include "Fruit.hpp"

#include <SFML/Graphics.hpp>

Test::Test() {
    RunTest();
}

void Test::RunTest() {
    sf::Texture texture;
    sf::Image background;
    sf::Sprite treeSprite;
    sf::Sprite newSprite;
    background.loadFromFile( file );
    texture.loadFromImage( background );

    Snake slithers;
    slithers.setTexture( texture );
    slithers.setScale( 1.1, 1.0 );
    Fruit banana;
    banana.setTexture( texture );
    banana.setScale( 1.1, 1.0 );
}
