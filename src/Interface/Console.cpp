#include "Interface/Console.hpp"

Console::Console(sf::Vector2f pos) {
    position = pos;
    font.loadFromFile("../res/fonts/PressStart2P.ttf");
    text.setFont(font);
    print("test");
    text.setPosition(pos);
    text.setCharacterSize(12);
}

void Console::draw(sf::RenderTarget &target) {
    for(int i = 0; i < console_vector.size(); i++) {
        text.setString(console_vector[i]);
        text.setPosition(position + sf::Vector2f(0, (text.getGlobalBounds().height+5) * i));
        target.draw(text);
    }
}

void Console::print(const char *t) {
    console_vector.push_back(t);
    if(console_vector.size() > 10) {
        console_vector.erase(console_vector.begin());
    }
}