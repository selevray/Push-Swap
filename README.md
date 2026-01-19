*This project has been created as part of the 42 curriculum by selevray.*

# Push_swap

## Description
Le projet **Push_swap** est un exercice d'algorithmie consistant à trier une pile de nombres avec un set d'instructions limité. L'enjeu est de trouver la séquence d'instructions la plus courte.

Ma solution repose sur une **liste doublement chaînée circulaire**, une structure de données où chaque nœud pointe vers le suivant et le précédent, et où le dernier élément est relié au premier. Cette architecture est idéale pour simuler le comportement circulaire des piles dans ce sujet (les rotations). 

L'algorithme de tri utilisé est un **Insertion Sort optimisé** par un calcul de coût : pour chaque nombre, le programme calcule le nombre de rotations nécessaires dans les deux piles pour l'insérer à sa place idéale, choisissant toujours l'opération la moins coûteuse.

### 📊 Performances

Mon algorithme a été optimisé pour minimiser le nombre d'instructions, dépassant largement les exigences du barème de 42 :

| Nombre d'éléments | Performance (Moyenne) | Objectif 42 (Max) | Statut |
| :--- | :---: | :---: | :---: |
| **3 nombres** | `2 coups` | 3 coups | ✅ |
| **5 nombres** | `8 coups` | 12 coups | ✅ |
| **100 nombres** | **577 coups** | 700 coups | ✨ |
| **500 nombres** | **4588 coups** | 5500 coups | ✨ |

> _Les tests ont été effectués avec des listes générées aléatoirement._

## Instructions

### Compilation
Le projet se compile via le `Makefile` inclus :
```bash
# Compilation
make

# Exécution
./push_swap 3 2 5 1 4

# Visualiser le nombre de lignes
./push_swap 3 2 5 1 4 | wc -l
```
et avec bonus
```bash
# Compilation
make bonus

# Exécution
ARG="4 1 2"; ./push_swap $ARG | ./checker $ARG
# Résultat attendu : OK
```
