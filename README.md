# 🏰 L'Aventure du chevalier 🏰

## 📜 Présentation

Ce projet est un jeu en ligne de commande développé en C dans le cadre de la SAÉ S1.02 (Comparaison d'approches algorithmiques) de mon BUT Informatique. Le joueur incarne un chevalier et doit affronter des monstres à travers des combats stratégiques inspirés du jeu "Pierre-Feuille-Ciseaux".

## 🎮 Fonctionnalités

- **Combats en tour par tour** contre des groupes de monstres.
- **Système de points de vie et de dégâts** pour le chevalier et les monstres.
- **Utilisation du principe Pierre-Feuille-Ciseaux** pour les attaques.
- **Deux modes de combat** : un contre un ou attaques simultanées.
- **Gestion des joueurs** : enregistrement des noms et des scores.
- **Sauvegarde et chargement des données** (joueurs et scores).
- **Affichage des classements** par pseudo ou par score.
- Plusieurs niveaux de difficultés avec des boss.

## 🗡️ Règles du Jeu

1. Le joueur choisit une arme parmi : Pierre (P), Feuille (F), Ciseaux (C).
2. Les monstres disposent d'armes selon leur niveau (avec des variantes).
3. Le combat suit les règles classiques de "Pierre-Feuille-Ciseaux" avec des exceptions pour certaines armes spéciales.
4. Chaque victoire rapporte des points en fonction du monstre vaincu.
5. La partie se termine lorsque le chevalier n’a plus de points de vie ou qu'il a vaicu tous les monstres.

## 💾 Sauvegarde et Classements

- Les scores sont automatiquement enregistrés à la fin d'une partie.
- Possibilité d'afficher les joueurs classés par pseudo ou par score.
- Consultation des statistiques d’un joueur (meilleur score, nombre de parties...).

## ⚙️ Compilation et Exécution

## Prérequis

- GCC
- Makefile
```sh
sudo apt install build-essential make
```

## Exécution

```sh
git clone https://github.com/Sams213/Jeu-Monstre-C.git
cd Jeu-Monstre-C

make
./main
```

## 📌 Améliorations Possibles

- Création de nouvelles parties avec des monstres personnalisés.
- Système d’évolution du chevalier en fonction des points gagnés.
- Ajout de nouveaux types d’armes et d’attaques spéciales.
- Sauvegarde avancée avec différents fichiers de progression.


