[![Build Status](https://codefirst.iut.uca.fr/api/badges/ghassan.jabbour/SAE_1.02_Algo/status.svg)](https://codefirst.iut.uca.fr/ghassan.jabbour/SAE_1.02_Algo)  

# SAE_1.02_Algo

# Université Clermont Auvergne - IUT Clermont
## Département Informatique 1ère année 2024

### SAÉ S1.02 : Comparaison d’approches algorithmiques

#### Compétence : Optimiser des applications informatiques (Compétence 2)

**Apprentissage Critique (AC1)** : Analyser un problème avec méthode (découpage en éléments algorithmiques simples, structures de données...)  
**Apprentissage Critique (AC2)** : Comparer des algorithmes pour des problèmes classiques (tris simples, recherche...)

### Thème : Réalisation d’un jeu de combat contre des monstres  
**Date de rendu : 10 janvier 2024**  
**Organisation : Par groupe de 2 (voir avec votre enseignant)**

---

## 1. Sujet du projet

Nous voulons réaliser un jeu de combat de monstres. Dans ce jeu, le joueur, incarnant un chevalier, devra affronter une succession de monstres et gagner des points.

### 1.1 Constitution d’une partie

Une partie du jeu est composée de deux groupes de monstres :

- **Premier groupe de monstres** : Ces monstres affrontent le chevalier l'un après l'autre, dans un ordre séquentiel. Le chevalier doit vaincre chaque monstre avant d'affronter le suivant.
  
- **Deuxième groupe de monstres** : Ces monstres attaquent simultanément ou presque. Chacun d'eux attaque le chevalier dans un ordre précis, et la séquence d'attaques recommence tant que les monstres ne sont pas tués.

### 1.2 Les personnages

- **Le chevalier** : Le joueur, identifié par un pseudo, dispose de 20 points de vie au début de chaque partie. Il inflige 1 point de dégâts à l'adversaire lors d'une attaque, et son score est calculé en fonction des monstres tués.
  
- **Les monstres** : Chaque monstre possède un nom/type, un nombre de points de vie, un nombre de points de dégâts et un nombre d'armes. Les caractéristiques des monstres dépendent de leur niveau :
  - **Niveau 1** : 4 PV, 1 dégât, 4 armes
  - **Niveau 2** : 6 PV, 1 dégât, 3 armes
  - **Niveau 3** : 4 PV, 2 dégâts, 5 armes

### 1.3 Attaque

Les attaques sont réalisées de manière similaire au jeu "Pierre/Feuille/Ciseaux". Le chevalier choisit une arme parmi trois possibles : Pierre (P), Feuille (F), Ciseaux (C). Le monstre choisit une arme au hasard parmi les siennes. Les règles de victoire sont les suivantes :

- Pierre bat Ciseaux
- Feuille bat Pierre
- Ciseaux bat Feuille
- L'arme "bonne à rien" perd contre toutes les autres armes
- L'arme avec un super pouvoir (#) bat toutes les autres armes
- Si les deux armes sont identiques, il n'y a pas de gagnant.

Lorsqu'un combattant perd une attaque, ses points de vie sont réduits du nombre de points de dégâts infligés par l'adversaire. Si ses points de vie tombent à zéro, il meurt. La partie se termine si le chevalier meurt.

### 1.4 Calcul des points

- Le chevalier commence avec un score de 0.
- Pour chaque attaque gagnée, le chevalier gagne 10 points.
- Pour chaque monstre vaincu dans le premier groupe, il gagne 50 points par niveau du monstre (par exemple, 50 points pour un monstre de niveau 1, 150 points pour un monstre de niveau 3).
- Pour chaque monstre vaincu dans le deuxième groupe, il gagne 100 points par niveau du monstre (par exemple, 100 points pour un monstre de niveau 1, 200 points pour un monstre de niveau 2).

### 1.5 Sauvegarde et rechargement

Le système de sauvegarde permet de conserver la liste des joueurs et leurs scores à tout moment. Lorsqu'on lance ou arrête le jeu, les données des joueurs sont sauvegardées automatiquement.

### 1.6 Possibilités du jeu

Au lancement du jeu, il est possible de :

1. Jouer une partie prédéfinie en choisissant un fichier de partie
2. Créer une nouvelle partie avec des monstres personnalisés
3. Afficher la liste des joueurs triée par nom
4. Afficher la liste des joueurs triée par meilleur score
5. Afficher les statistiques d'un joueur

### 1.7 Options optionnelles du jeu

Si le jeu de base est complet, les ajouts suivants sont optionnels :

- Permettre au joueur de créer une partie avec des monstres personnalisés (nom, niveau, ordre).
- Ajouter plusieurs niveaux de joueurs (par exemple, niveau 1 : 20 PV, 1 dégât ; niveau 2 : 30 PV, 2 dégâts, etc.).
- Intégrer des "easter eggs" ou autres fonctionnalités cachées.

---

## 2. Livrables

À la fin du projet, vous devez fournir :

- Le code source de l’application avec sa documentation.
- Un compte-rendu expliquant :
  1. Les fonctionnalités réalisées dans le jeu (en 2 lignes maximum par fonctionnalité).
  2. La structure des fichiers utilisés (texte ou binaire) et l'organisation des données à l'intérieur.
  3. Les structures de données choisies pour stocker les informations (joueurs, scores, monstres, parties, groupes de monstres, etc.) avec un schéma mémoire explicatif.
  4. Une comparaison des algorithmes de tri et de recherche utilisés dans le jeu.

## 3. Évaluation

L'évaluation se basera sur les éléments suivants :

- La qualité et la complexité du code.
- L’utilisation des structures de données appropriées : tableaux, listes, fichiers texte/binaire, piles, files, etc.
- La mise en œuvre de plusieurs algorithmes de tri et de recherche.
- L'intégration de techniques comme la saisie contrôlée, la récursivité, et l'affichage de menus.
- La collaboration efficace au sein du groupe.

---

## Exemple d'exécution du jeu :

```plaintext
------------- Menu -------------
1. Jouer une partie prédéfinie
2. Créer une nouvelle partie
3. Afficher la liste des joueurs triée par nom
4. Afficher la liste des joueurs triée par meilleur score
5. Afficher les statistiques d'un joueur
9. Quitter
--------------------------------
Choix : 1
Nom du fichier correspondant à la partie : partie1.txt
Pseudo joueur : Toto

Contexte : Vous arrivez dans un corridor, bordé par deux falaises. Des monstres arrivent les uns après les autres.

Monstre Chouin-Chouin (4 PV, 1 Att) accourt pour vous attaquer !
Toto (20 PV, 1 Att) : Choisissez votre arme parmi P, F, C : P
Toto (P) attaque Chouin-Chouin (C). Toto (20 PV) gagne l'attaque ! +10 pts
Toto (10 pts), choisissez votre arme parmi P, F, C : P
Toto (P) attaque Chouin-Chouin (O). Toto (20 PV) gagne l'attaque ! +10 pts
Toto (20 pts), choisissez votre arme parmi P, F, C : P
Toto (P) attaque Chouin-Chouin (C). Toto (20 PV) gagne l'attaque ! +10 pts
Toto (30 pts), choisissez votre arme parmi P, F, C : P
Toto (P) attaque Chouin-Chouin (F). Toto (19 PV) perd l'attaque !
Toto (30 pts), choisissez votre arme parmi P, F, C : C
Toto (C) attaque Chouin-Chouin (F). Toto (19 PV) gagne l'attaque ! +10 pts
Chouin-Chouin meurt sous le coup de l'attaque +50 pts
...

Tous les monstres sont morts ! Vous avez gagné 380 points.

------------- Menu -------------
1. Jouer une partie prédéfinie
2. Créer une nouvelle partie
3. Afficher la liste des joueurs triée par nom
4. Afficher la liste des joueurs triée par meilleur score
5. Afficher les statistiques d'un joueur
9. Quitter
--------------------------------
Choix : 9
Au revoir...
