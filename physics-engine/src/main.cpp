#include <cassert>
#include <iostream>
#include "Vector.h"
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <cstdlib>
#include <ctime>
#include "Collider.h"

std::vector<Entity> entities;


void CreateRectangle(int xposition,int yposition)
{
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(100, 100));

    entities.emplace_back(Entity());

    Entity& entity=entities.back();
    entity.Velocity = sf::Vector2f(rand() % 20, rand() % 20);
	entity.visualPtr = std::make_unique<sf::RectangleShape>(rect);
    entity.setPosition(xposition, yposition);
    /*entity.setPosition(rand() % 1279 + 1, rand() % 719 + 1);*/
}

int main()
{
    //initialize random seed
    srand(time(0));

    // vector stuff
    /*;
	Vector V(42, 69);
    std::cout << V.Normalize().ToString();*/

	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    window.setFramerateLimit(60);

    /*
	// draw circle
	sf::CircleShape circle(100.f);
	circle.setFillColor(sf::Color::Green);
    circle.setPosition(100.f, 100.f);

    // draw line
    sf::RectangleShape line(sf::Vector2f(550.f, 50.f));
    line.setPosition(10.f, 350.f);
    */

    CreateRectangle(rand() % 1230 + 50, rand() % 670 + 50);
    
    CreateRectangle(rand() % 1230 + 50, rand() % 670 + 50);
    
    CreateRectangle(rand() % 1230 + 50, rand() % 670 + 50);


    /*
   // draw rectangle
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(100, 100));
    Entity entity;
    entity.Velocity = sf::Vector2f(3, 3);
    entity.visualPtr = std::make_unique<sf::RectangleShape>(rect);
    entity.setPosition(600, 350);

    // draw rectangle 2
    sf::RectangleShape rect2;
    rect2.setSize(sf::Vector2f(100, 100));
    Entity entity2;
    entity2.Velocity = sf::Vector2f(3, 3);
    entity2.visualPtr = std::make_unique<sf::RectangleShape>(rect2);
    entity2.setPosition(900, 100);*/


	while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            for (auto& _entity : entities)
            {
                _entity.Update();
            }

            //entity.Update();
            //entity2.Update();

			// render
            window.clear();
            for (auto& _entity : entities)
            {
                window.draw(_entity);
            }

			//window.draw(entity);
		    //window.draw(entity2);
            
			
			
            window.display();
        }

    


        return 0;
    
}

