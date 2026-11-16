# Patrouille

Examen oral du module 1 — sujet **B**. Une salle vue de dessus, en fenêtre SFML.

## Ce que le jeu doit faire

Le joueur est le **carré vert**, en bas à gauche. Il doit atteindre la **porte jaune**, en
haut à droite, sans se faire repérer.

Un garde immobile occupe le milieu de la salle. Il regarde dans une direction fixe et balaie
du regard un **cône de 30° de demi-angle, sur 200 pixels** — le cône est dessiné à l'écran,
c'est exactement ce qu'il voit. Entrer dedans renvoie le joueur au départ ; passer derrière
lui ou rester hors de portée ne coûte rien.

Quand le joueur s'approche à moins de 260 pixels, le jeu prévient qu'on entend le garde
respirer.

## Comment jouer

Lance la cible `patrouille`. Une fenêtre **Patrouille** s'ouvre : c'est là que tout se passe.
**Clique dedans** pour lui donner le focus, sinon le clavier va à la console et rien ne bouge.

| Touche | Action |
|---|---|
| ← → ↑ ↓ | se déplacer |

Le bandeau en haut de la fenêtre rappelle l'objectif et affiche les alertes ; la console tient
le journal.

## Le lancer

Dans **CLion** : ouvrir le dossier, laisser CLion configurer le projet (SFML est déclaré dans
`vcpkg.json`, le panneau *Vcpkg* s'en charge), puis *Build* et *Run* sur la cible
`patrouille`.

En ligne de commande :

```bash
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%/scripts/buildsystems/vcpkg.cmake
cmake --build build
```

## Ce qu'on te demande

**30 minutes seul avec ce dépôt**, puis **20 minutes d'entretien**. Tu prépares quatre
réponses, que tu notes dans `REPONSES.md` :

1. **Que fait ce jeu ?**
2. **Quel problème pose-t-il ? Quelle correction proposes-tu ?**
3. **Quelles améliorations proposes-tu ?**
4. Une question de **théorie**, posée à l'oral, écran fermé.

Ce qui est noté, c'est l'entretien. `REPONSES.md` est une trace, pas un rendu : il ne rapporte
pas de points et ne peut pas t'en coûter. Attends-toi à devoir **dérouler** tes réponses à la
main — reproduire le problème à la demande, refaire un calcul au tableau, dire ce que ta
correction ne couvre pas.

## Ce que tu peux faire

Tout. Compiler, lancer, modifier le code, le casser, le réparer, ajouter des affichages.
**Internet et les assistants IA sont autorisés** pendant les 30 minutes.
