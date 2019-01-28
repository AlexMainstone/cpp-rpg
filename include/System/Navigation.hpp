#pragma once

#include<vector>
#include<SFML/Graphics.hpp>


    struct Node{
        sf::Vector2i pos;
        int cost;
        sf::Vector2i last_node;
        Node() {
            cost = 0;
        }
        Node(int c, sf::Vector2i l, sf::Vector2i pos) {
            cost = c;
            last_node = l;
            this->pos = pos;
        }
    };

    inline std::vector<std::vector<Node>> dijkstra(std::vector<std::vector<int>> area, sf::Vector2i start) {
        std::vector<std::vector<Node>> dijkstra_map(area.size(), std::vector<Node>(area[0].size(), Node()));
        area[start.x][start.y] = -1;

        std::vector<Node> unsorted_nodes;
        unsorted_nodes.push_back(Node(-1, start, start));
        sf::Vector2i current = start;
        int i =0;
        do {
            if(!unsorted_nodes.empty()) {
                current = unsorted_nodes.back().pos;
                unsorted_nodes.pop_back();
            }
            for(int dx = -1; dx <= 1; dx++) {
                for(int dy = -1; dy <= 1; dy++) {
                    if((dx != 0 || dy != 0)) {
                        // if out of bounds
                        if(current.x + dx < 0 || current.x + dx >= dijkstra_map.size() || current.y + dy < 0 || current.y + dy >= dijkstra_map.size()) {
                            continue;
                        }

                        if(area[current.x + dx][current.y + dy] < 0) {
                            continue;
                        }

                        // if cheaper
                        if(dijkstra_map[current.x+dx][current.y+dy].cost == 0 || dijkstra_map[current.x + dx][current.y + dy].cost > dijkstra_map[current.x][current.y].cost + area[current.x + dx][current.y + dy]) {
                            Node n(dijkstra_map[current.x][current.y].cost + area[current.x + dx][current.y + dy], current, current + sf::Vector2i(dx, dy));
                            unsorted_nodes.push_back(n);
                            dijkstra_map[current.x + dx][current.y + dy] = n;
                            continue;
                        }
                    }
                }
            }

        } while(!unsorted_nodes.empty());
        return dijkstra_map;
    }

    // std::vector<std::vector<int>> a_star(std::vector<std::vector<int>> area, sf::Vector2i start, sf::Vector2i end) {

    // }


// #include<iostream>
// int main() {
//     std::vector<std::vector<int>> dijkstra_map(10, std::vector<int>(10, 1));
//     for(int i = 0; i < dijkstra_map.size()-1; i++){
//         dijkstra_map[5][i] = -1;
//     }

//     std::vector<std::vector<nav::Node>> m = nav::dijkstra(dijkstra_map, sf::Vector2i(2, 2));
//     for(auto i : m) {
//         std::cout << std::endl;
//         for(auto j : i) {
//             std::cout << j.cost << ", ";
//         }
//     }
// }