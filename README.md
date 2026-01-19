*This project has been created as part of the 42 curriculum by selevray.*

# Push_swap

## Description
Le projet **Push_swap** est un exercice d'algorithmie consistant à trier une pile de nombres avec un set d'instructions limité. L'enjeu est de trouver la séquence d'instructions la plus courte.

Ma solution repose sur une **liste doublement chaînée circulaire**, une structure de données où chaque nœud pointe vers le suivant et le précédent, et où le dernier élément est relié au premier. Cette architecture est idéale pour simuler le comportement circulaire des piles dans ce sujet (les rotations). 

L'algorithme de tri utilisé est un **Insertion Sort optimisé** par un calcul de coût : pour chaque nombre, le programme calcule le nombre de rotations nécessaires dans les deux piles pour l'insérer à sa place idéale, choisissant toujours l'opération la moins coûteuse.

## Instructions

### Compilation
Le projet se compile via le `Makefile` inclus :
```bash
make```

### Exec