// Patrouille : traverser la salle jusqu'a la porte sans entrer dans le cone du garde.

#include <cmath>
#include <iostream>
#include <optional>

#include <SFML/Graphics.hpp>

#include "garde.h"
#include "salle.h"

namespace {

constexpr float kPasDeTemps = 1.f / 60.f;
constexpr float kVitesse = 200.f;
constexpr float kTailleDuJoueur = 24.f;

constexpr float kDepartX = 40.f;
constexpr float kDepartY = 540.f;

constexpr float kDistanceOuOnLEntend = 260.f;

}  // namespace

int main() {
  sf::RenderWindow fenetre(sf::VideoMode({800u, 600u}), "Patrouille");
  fenetre.setFramerateLimit(60);

  Salle salle;
  Garde garde(400.f, 300.f, 1.f, 0.f);

  float joueur_x = kDepartX;
  float joueur_y = kDepartY;
  bool on_l_entend = false;

  sf::RectangleShape joueur({kTailleDuJoueur, kTailleDuJoueur});
  joueur.setOrigin({kTailleDuJoueur / 2.f, kTailleDuJoueur / 2.f});
  joueur.setFillColor(sf::Color(90, 200, 130));

  std::cout << "Patrouille -- fleches pour se deplacer, la porte jaune est la sortie."
            << std::endl;

  while (fenetre.isOpen()) {
    while (const std::optional evenement = fenetre.pollEvent()) {
      if (evenement->is<sf::Event::Closed>()) {
        fenetre.close();
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
      joueur_x -= kVitesse * kPasDeTemps;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
      joueur_x += kVitesse * kPasDeTemps;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
      joueur_y -= kVitesse * kPasDeTemps;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
      joueur_y += kVitesse * kPasDeTemps;
    }

    const float dx = joueur_x - garde.X();
    const float dy = joueur_y - garde.Y();
    const float distance = std::sqrt(dx * dx + dy * dy);
    if (distance < kDistanceOuOnLEntend && !on_l_entend) {
      std::cout << "Tu entends le garde respirer." << std::endl;
      on_l_entend = true;
    } else if (distance >= kDistanceOuOnLEntend) {
      on_l_entend = false;
    }

    const bool repere = garde.VoitLeJoueur(joueur_x, joueur_y);
    if (repere) {
      std::cout << "Repere. Retour au depart." << std::endl;
      joueur_x = kDepartX;
      joueur_y = kDepartY;
    }

    if (salle.EstSurLaSortie(joueur_x, joueur_y)) {
      std::cout << "Sorti sans te faire voir." << std::endl;
      fenetre.close();
    }

    joueur.setPosition({joueur_x, joueur_y});

    fenetre.clear(sf::Color(32, 34, 42));
    salle.Dessiner(fenetre);
    garde.Dessiner(fenetre, repere);
    fenetre.draw(joueur);
    fenetre.display();
  }
}
