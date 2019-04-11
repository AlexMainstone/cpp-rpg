#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Console
{
public:
    Console(sf::Vector2f pos);
    void draw(sf::RenderTarget &target);
    void print(const char *t, sf::Color c = sf::Color::White);

private:
    sf::Vector2f position;
    sf::Font font;
    sf::Text text;
    struct ConsoleInput
    {
        sf::Color color;
        const char *text;
        ConsoleInput(sf::Color color, const char *text)
        {
            this->color = color;
            this->text = text;
        }
    };
    std::vector<ConsoleInput> console_vector;
};