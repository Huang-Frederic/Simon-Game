# Simon Game - Projet Arduino

## Sommaire

- ## Sujet
- ## Matériel
- ## Code
- ## Difficultés Rencontrées
- ## Améliorations Possibles
- ## Conclusion

## Sujet

Notre projet consiste à la création d'un jeu pour enfant en Arduino. Nous avons donc crée une réplique du jeu "Simon" populaire chez les enfants. Le projet utilise donc principalement des boutons et des LEDs pour interargir avec le joueur. Le jeu fonctionne comme tel:

Pour commencer une partie : Appuyer sur le bouton start
Déroulé d'une partie : La carte va produire une combinaison, qu'il faudra reproduire à la perfection. La combinaison se verra composé en premier lieu d'une seule couleur, puis augmentera de 1 à chaque tour passé, le but est d'arriver le plus loin possible, le score sera affiché à la fin sur l'écran de Série.

## Matériel

- 6 Boutons (1 pour chaque couleurs et 1 pour démarrer le jeu)
- 5 LEDs (1 de chaque couleur)
- 5 Résistances (10K Ohms pour contrôler la puissance de la LED)
- 1 Buzzer
- 13 long câbles (pour les relier à la carte)
- 13 petits câbles (pour connecter à la multiprise GND)

Nous avons donc choisi d'utiliser 5 LEDs de couleurs différentes ainsi qu'un bouton chacuns permettant au joueur d'intérargir. Le buzzer est ici utilisé pour émettre une mélodie en fonction de si on gagne, perd ou lorsque l'on commence une partie.

## Code

Nous avons segmentés notre code en plusieurs fonctions pour faciliter la lisibilité et la compréhension du code. De ce fait, la fonction loop ne fait que vérifier si le bouton start est activé ou non.

La fonction principale "game()" gère la partie, elle initialise les compteurs et génère les combinaisons de couleurs de manière aléatoires et à difficulté croissante. lorsque la combinaison a été généré et retransmite au joueur, on appelle la fonction "game_check_if_correct(tab, count)" qui prend en argument le tab (la combinaison) et count (la taille de la combinaison).

Cette fonction va vérifier lorsqu'un bouton est clické si celle-ci correspond bien à la combinaison. Si toute les couleurs ont été rendu, la fonction retourne 1, si le joueur se trompe, il sort immédiatement de la fonction et retourne 0.

La fonction main interprete ensuite la réponse et déterminera si le joueur passe au prochain tour ou arrête le jeu.

Un son accompagne la victoire ou la défaite du joueur en appelant les fonctions "buzz_win()" et "buzz_lose()". Un compte à rebours est aussi émit lorsque l'on lance une partie grâce à la fonction "buzz_count()".

## Difficultés Rencontrées

L'une des premières difficultés rencontrés était la gestion du random, qui ne marchait pas correctement. En dehors de ça, tout s'est bien déroulé jusqu'à l'implémentation des sons, qui devaient à l'origine être tous réunis dans une seule et même fonction mais ayant rencontrés divers problèmes, nous avons décidés de les séparer en différentes fonctions.

## Améliorations Possibles

L'ajout d'un écran intégré pour l'affichage du tour en temps réel pourrait être un plus, une plus grande bread board pourrait-être envisagé pour avoir plus d'espaces entre les boutons.

## Conclusion

Ce projet nous a permis de se familiariser avec l'univers arduino de manière ludique et agréable. Elle offre un avant goût des possibilités d'Arduino avec le matériel de base.
