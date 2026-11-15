#pragma once

#include <SFML/Graphics.hpp>

// Le garde est immobile. Il regarde dans une direction fixe et repere ce qui entre
// dans son cone de vision.
class Garde {
 public:
  Garde(float x, float y, float direction_x, float direction_y);

  float X() const;
  float Y() const;

  bool VoitLeJoueur(float joueur_x, float joueur_y) const;
  void Dessiner(sf::RenderWindow& fenetre, bool alerte) const;

 private:
  float x_;
  float y_;
  float direction_x_;
  float direction_y_;
};
