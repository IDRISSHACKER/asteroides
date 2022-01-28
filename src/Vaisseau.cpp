#include <iostream>
#include <SFML/Graphics.hpp>
#include "../include/Vaisseau.hpp"

using namespace std;


Vaisseau::Vaisseau(sf::Color const& couleur){
    if(!texture.loadFromFile("ressources/vaisseau.png")){
        cerr << "Error of loading image(.png)" << endl;
    }
    sprite.setTexture(texture);
    sprite.setColor(couleur);
}

Vaisseau::~Vaisseau(){
    cout << "Fermeture du Jeu" << endl;
}


void Vaisseau::afficher(sf::RenderWindow& fenetre) const {
    fenetre.draw(sprite);
}

void Vaisseau::actualiserEtat(sf::Event const& evenement){
    if(evenement.type == sf::Event::KeyPressed && evenement.key.code == sf::Keyboard::Up){
        accelerationEnCour = true;
    }else if(evenement.type == sf::Event::KeyReleased && evenement.key.code == sf::Keyboard::Up){
        accelerationEnCour = false;
    }
}

void Vaisseau::mettreAJour(sf::RenderWindow& fenetre, float temps){
    if(accelerationEnCour){
        vitesse += ACCELERATION*temps;
    }
    vitesse -= vitesse*COEF_FROTTEMENT * temps;
    sprite.move(vitesse*temps, 0.02);
}
