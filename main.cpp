#include <iostream>
#include <SFML/Graphics.hpp>
#include "include/Vaisseau.hpp"

using namespace std;

int main()
{
    Vaisseau vaisseau = Vaisseau{sf::Color::Green};
    sf::RenderWindow fenetre{sf::VideoMode{800, 500}, "Asteroid"};
    sf::Clock chrono = sf::Clock{};
    while(fenetre.isOpen()){
        auto evenment = sf::Event();
        while(fenetre.pollEvent(evenment)){
            if(evenment.type == sf::Event::Closed){
                fenetre.close();
            }
            vaisseau.actualiserEtat(evenment);
        }

        vaisseau.mettreAJour(fenetre, chrono.restart().asSeconds());
        fenetre.clear();
        vaisseau.afficher(fenetre);
        fenetre.display();
    }
    return 0;
}
