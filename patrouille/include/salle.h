#pragma once

#include <SFML/Graphics.hpp>

// Le sol et la porte de sortie.
class Salle {
 public:
  Salle();

  bool EstSurLaSortie(float joueur_x, float joueur_y) const;
  void Dessiner(sf::RenderWindow& fenetre) const;

 private:
  float sortie_x_;
  float sortie_y_;
  sf::RectangleShape sortie_;
};
