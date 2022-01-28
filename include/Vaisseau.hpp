#ifndef VAISSEAU_HPP_INCLUDED
#define VAISSEAU_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Vaisseau{
    public:
        Vaisseau(sf::Color const& couleur);
        ~Vaisseau();
        void avancer();
        void afficher(sf::RenderWindow& fenetre) const;
        void actualiserEtat(sf::Event const& evenement);
        void mettreAJour(sf::RenderWindow& fenetre, float temps);
    private:
        sf::Texture texture{};
        sf::Sprite sprite{};
        float vitesse{0.f};
        bool accelerationEnCour{false};
        static constexpr float ACCELERATION{700.f};
        static constexpr float COEF_FROTTEMENT{2.f};
};


#endif // VAISSEAU_HPP_INCLUDED
