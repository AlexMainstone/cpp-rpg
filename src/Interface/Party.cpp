#include "Interface/Party.hpp"

Party::Party()
{
    turn = 0;
}

void Party::addMember(PlayerCharacter *character)
{
    members.push_back(character);
}

void Party::setCurrent(sf::Vector2i c)
{
    for (PlayerCharacter *m : members)
    {
        m->setCurrent(c);
    }
}

void Party::orderTurns()
{
    for (PlayerCharacter *character : members)
    {
        turn_order.push_back(character);
    }
}

void Party::draw(sf::RenderTarget &target)
{
    for (PlayerCharacter *character : members)
    {
        character->draw(target);
    }
}

void Party::handleEvent(sf::Event &e)
{
    members[turn]->handleEvent(e);
    if (e.type == sf::Event::KeyPressed)
    {
        if (e.key.code == sf::Keyboard::Space)
        {
            turn++;
            if (turn >= members.size())
                turn = 0;

            if (turn == 0)
                members[members.size() - 1]->setControlled(false);
            else
                members[turn - 1]->setControlled(false);
            members[turn]->setControlled(true);
        }
    }
}

void Party::update(float dt)
{
    for (PlayerCharacter *character : members)
    {
        character->update(dt);
    }
}