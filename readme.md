Idée de Réalisation du Projet :

Notre équipe a entrepris un projet ambitieux de création d'un dataframe en langage C, visant à gérer efficacement des données tabulaires. Voici une synthèse 
de notre approche :

Structure de la Colonne (column.h) :
Nous avons soigneusement conçu une structure pour représenter une colonne de données. Cette structure est flexible, permettant de stocker soit uniquement des
entiers, soit une variété de types de données. Nous avons également défini les prototypes des fonctions nécessaires pour la gestion de cette colonne.

Structure du CDataframe (cdataframe.h) :
Pour représenter le dataframe global, nous avons opté pour une structure adaptée, qui peut être un tableau de colonnes ou une liste doublement chaînée de 
colonnes, selon les besoins et les performances. Les prototypes cohérents des fonctions pour la gestion du CDataframe sont inclus dans ce fichier.

Gestion des Listes Doublement Chaînées (list.h) :
Pour les équipes qui préfèrent une structure basée sur une liste doublement chaînée, nous avons inclus ce fichier dans le dépôt. Cela facilitera la gestion
des structures de données.

Scénario d'Utilisation (main.c) :
Nous avons fourni un exemple de scénario d'utilisation détaillé des fonctions implémentées dans le projet. Ce scénario démontrera de manière pratique comment
créer, modifier et manipuler les dataframes à l'aide des fonctionnalités développées.

Nous avons choisi d'utiliser Git comme outil de travail collaboratif afin de garantir une gestion efficace des versions du code et de faciliter la 
collaboration entre les membres de l'équipe. Chaque membre sera responsable de pousser ses modifications sur une branche dédiée et de les fusionner une fois 
validées.

Ce dépôt intermédiaire atteste de notre compréhension du sujet du projet et de notre engagement dans le développement initial du dataframe en C.

