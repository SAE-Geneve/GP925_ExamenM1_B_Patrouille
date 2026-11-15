#include "salle.h"

#include <cmath>

#include <SFML/Graphics.hpp>

namespace {

constexpr float kTailleDeLaSortie = 40.f;
constexpr float kRayonDeLaSortie = 24.f;

}  // namespace

Salle::Salle() : sortie_x_(740.f), sortie_y_(60.f), sortie_({kTailleDeLaSortie, kTailleDeLaSortie}) {
  sortie_.setOrigin({kTailleDeLaSortie / 2.f, kTailleDeLaSortie / 2.f});
  sortie_.setPosition({sortie_x_, sortie_y_});
  sortie_.setFillColor(sf::Color(240, 210, 90));
}

bool Salle::EstSurLaSortie(float joueur_x, float joueur_y) const {
  const float dx = joueur_x - sortie_x_;
  const float dy = joueur_y - sortie_y_;
  const float distance = std::sqrt(dx * dx + dy * dy);
  return distance < kRayonDeLaSortie;
}

void Salle::Dessiner(sf::RenderWindow& fenetre) const { fenetre.draw(sortie_); }
