#include <SFML/Graphics.hpp>
#include <iostream>

class Sun {
public:
    Sun();
    void initialize(float startX, float startY);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getGlobalBounds() const;

private:
    sf::Texture sunTexture;
    sf::Sprite sunSprite;
    float speed;
};