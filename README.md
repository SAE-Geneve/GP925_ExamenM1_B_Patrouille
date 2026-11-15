# Patrouille

Examen oral du module 1 — sujet **B**. Une salle vue de dessus, un garde, une porte à
atteindre, en fenêtre SFML.

## Ce que le jeu doit faire

Le joueur est le **carré vert**, en bas à gauche au départ. Les **flèches** le déplacent
dans les quatre directions.

Le **garde** est le disque bleu au centre de la salle. Il est immobile et **regarde vers la
droite**. Son **cône de vision** est dessiné à l'écran : un demi-angle de **30 degrés** de
part et d'autre de son regard, sur une portée de **200 pixels**. Le cône dessiné est
exactement la zone où le garde voit.

Si le joueur **entre dans ce cône**, il est repéré : le garde et son cône passent au rouge,
la console le signale, et le joueur repart du coin en bas à gauche. Partout ailleurs — hors
du cône, ou trop loin — le garde ne voit rien, même si le joueur lui passe dans le dos.

Quand le joueur s'approche à moins de 260 pixels du garde, la console le prévient qu'il
l'entend respirer. C'est un avertissement, pas une détection.

La partie est gagnée quand le joueur atteint la **porte jaune**, en haut à droite.

## Le lancer

Dans **CLion** : ouvrir le dossier, laisser CLion configurer le projet (SFML est déclaré
dans `vcpkg.json`, le panneau *Vcpkg* s'en charge), puis *Build* et *Run* sur la cible
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

Ce qui est noté, c'est l'entretien. `REPONSES.md` est une trace, pas un rendu : il ne
rapporte pas de points et ne peut pas t'en coûter. Attends-toi à devoir **dérouler** tes
réponses à la main — reproduire le problème à la demande, refaire un calcul au tableau, dire
ce que ta correction ne couvre pas.

## Ce que tu peux faire

Tout. Compiler, lancer, modifier le code, le casser, le réparer, ajouter des affichages.
**Internet et les assistants IA sont autorisés** pendant les 30 minutes.
