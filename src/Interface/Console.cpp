#include "Interface/Console.hpp"

Console::Console(sf::Vector2f pos)
{
    position = pos;
    font.loadFromFile("../res/fonts/PressStart2P.ttf");
    text.setFont(font);
    print("PRION 0.0.1");
    text.setPosition(pos);
    text.setCharacterSize(12);
}

void Console::draw(sf::RenderTarget &target)
{
    for (int i = 0; i < console_vector.size(); i++)
    {
        text.setString(console_vector[i].text);
        text.setColor(console_vector[i].color);
        text.setPosition(position + sf::Vector2f(0, (text.getGlobalBounds().height + 5) * i));

        sf::RectangleShape back;
        back.setPosition(text.getPosition().x - 2, text.getPosition().y - 2);
        back.setSize(sf::Vector2f(text.getLocalBounds().width + 4, text.getLocalBounds().height + 4));
        back.setFillColor(sf::Color::Black);

        target.draw(back);
        target.draw(text);
    }
}

void Console::print(const char *t, sf::Color color)
{
    console_vector.push_back(ConsoleInput(color, t));
    if (console_vector.size() > 10)
    {
        console_vector.erase(console_vector.begin());
    }
}