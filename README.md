# TP - Structure de données

## Description

### Objectifs

L'objectif de ce TP est de concevoir une librairie simulant le comportement de la classe vector en C++.

### Réalisation

Dans un premier temps, il a été demandé de réaliser une structure contenant uniquement le type double et une structure de type tableau dynamique (un tableau dont la taille est réallouer lors d'un ajout et une suppression).

Ensuite, nous avons ajouté un champ 'capacity' ayant pour but d'allouer la mémoire de manière optimisée et donc de réduire le nombre d'appels système.

Enfin, nous avons fait en sorte que notre structure puisse prendre en charge n'importe quel type de données (du simple entier à une structure complexe en passant par une chaîne de caractère.). Pour cela, c'est à l'utilisateur de préciser comment les données seront allouées, copier et libérer avec des pointeurs sur fonctions. 

### Auteurs

* Barberet Rémy
* Buczko Mélissa
* François Gwennaël
