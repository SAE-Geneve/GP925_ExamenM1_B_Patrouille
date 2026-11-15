#include "garde.h"

#include <cmath>
#include <cstddef>

#include <SFML/Graphics.hpp>

namespace {

constexpr float kPi = 3.14159265f;

// Le cone de vision du garde : un demi-angle de 30 degres, sur 200 pixels.
constexpr float kDemiAngleDegres = 30.f;
constexpr float kPortee = 200.f;

constexpr float kRayonDuGarde = 14.f;
constexpr std::size_t kPointsDeLArc = 16;

}  // namespace

Garde::Garde(float x, float y, float direction_x, float direction_y)
    : x_(x), y_(y), direction_x_(direction_x), direction_y_(direction_y) {}

float Garde::X() const { return x_; }

float Garde::Y() const { return y_; }

bool Garde::VoitLeJoueur(float joueur_x, float joueur_y) const {
  const float dx = joueur_x - x_;
  const float dy = joueur_y - y_;
  const float distance = std::sqrt(dx * dx + dy * dy);
  if (distance > kPortee || distance < 1.f) {
    return false;
  }

  // Le produit scalaire divise par la distance donne le cosinus de l'angle entre
  // le regard du garde et le joueur. On le borne pour rester dans le domaine d'acos.
  float cosinus = (dx * direction_x_ + dy * direction_y_) / distance;
  if (cosinus > 1.f) {
    cosinus = 1.f;
  }
  if (cosinus < -1.f) {
    cosinus = -1.f;
  }

  const float angle = std::acos(cosinus);
  return angle <= kDemiAngleDegres;
}

void Garde::Dessiner(sf::RenderWindow& fenetre, bool alerte) const {
  const float demi_angle = kDemiAngleDegres * kPi / 180.f;
  const float direction = std::atan2(direction_y_, direction_x_);

  sf::ConvexShape cone(kPointsDeLArc + 1);
  cone.setPoint(0, sf::Vector2f(x_, y_));
  for (std::size_t i = 0; i < kPointsDeLArc; ++i) {
    const float t = static_cast<float>(i) / static_cast<float>(kPointsDeLArc - 1);
    const float angle = direction - demi_angle + t * 2.f * demi_angle;
    cone.setPoint(i + 1,
                  sf::Vector2f(x_ + std::cos(angle) * kPortee, y_ + std::sin(angle) * kPortee));
  }
  cone.setFillColor(alerte ? sf::Color(255, 120, 120, 90) : sf::Color(255, 220, 140, 70));
  fenetre.draw(cone);

  sf::CircleShape corps(kRayonDuGarde);
  corps.setOrigin({kRayonDuGarde, kRayonDuGarde});
  corps.setPosition({x_, y_});
  corps.setFillColor(alerte ? sf::Color(230, 70, 70) : sf::Color(110, 140, 230));
  fenetre.draw(corps);
}
