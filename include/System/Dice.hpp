#include <vector>
#include <stdlib.h>

namespace rpgdie
{

int explosive_roll(int d)
{
    int r = rand() % d;
    if (r == d)
    {
        r += explosive_roll(d);
    }
    return r;
}

std::vector<int> explosive_roll(int d, int num)
{
    std::vector<int> v;
    for (int i = 0; i < num; i++)
    {
        v.push_back(explosive_roll(d));
    }
    return v;
}

std::vector<int> explosive_roll_list(int d)
{
    std::vector<int> v;
    do
    {
        v.push_back(rand() % d);
    } while (v[v.size()] == d);
    return v;
}

std::vector<std::vector<int>> explosive_roll_list(int d, int num)
{
    std::vector<std::vector<int>> v;
    for (int i = 0; i < num; i++)
    {
        v.push_back(explosive_roll_list(d));
    }
    return v;
}
}; // namespace rpgdie