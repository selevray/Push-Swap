*This project has been created as part of the 42 curriculum by selevray.*

# Push_swap

## Description
Le projet **Push_swap** est un exercice d'algorithmie consistant à trier une pile de nombres avec un set d'instructions limité. L'enjeu est de trouver la séquence d'instructions la plus courte.

Ma solution repose sur une **liste doublement chaînée circulaire**, une structure de données où chaque nœud pointe vers le suivant et le précédent, et où le dernier élément est relié au premier. Cette architecture est idéale pour simuler le comportement circulaire des piles (les rotations `ra`, `rb`, `rra`, `rrb`).



L'algorithme de tri utilisé est un **Insertion Sort optimisé** par un calcul de coût : pour chaque nombre, le programme calcule le nombre de rotations nécessaires dans les deux piles pour l'insérer à sa place idéale, choisissant toujours l'opération la moins coûteuse (souvent appelé "Turk Algorithm").

---

### 📊 Performances

Mon algorithme dépasse largement les exigences du barème de 42 :

| Nombre d'éléments | Performance (Moyenne) | Objectif 42 (Max) |
| :--- | :---: | :---: |
| **3 nombres** | `2 coups` | 3 coups |
| **5 nombres** | `8 coups` | 12 coups |
| **100 nombres** | `577 coups` | 700 coups |
| **500 nombres** | `4588 coups` | 5500 coups |

> _Les tests ont été effectués avec des listes générées aléatoirement sur 100 itérations._

---

## Instructions

### Compilation
Le projet se compile via le `Makefile` :
```bash
make          # Compile push_swap
make bonus    # Compile le checker
make clean    # Supprime les objets
make fclean   # Supprime toutW
```

### Exec
```bash 
ARG="4 67 3 1 23"; ./push_swap $ARG
ARG="4 1 2"; ./push_swap $ARG | ./checker $ARG
# Résultat attendu : OK
```

## Resources

### 🧠 Algorithmes
* **[Insertion Sort (Explications)](https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/)** : Pour comprendre le tri par base si tu as choisi une approche binaire.

### 🛠️ Outils & Testeurs
* **[Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)** : Indispensable pour voir ton algorithme "réfléchir" en temps réel.
* **[Push_swap Tester](https://github.com/SimonCROS/push_swap_tester)** : Pour tester les performances.

### 🛠️ AI as fait 
* **Aide au Debugging :** Analyse de segments de code spécifiques pour identifier des fuites de mémoire (leaks) ou des erreurs de segmentation.
* **Exercice de Comprehension:** Exercice pour comprendre le projet (comme faire plusieur algo de tri).
* **Explication de Concepts :** Clarification des algorithmes complexes (comme le tri par coût).
* **Optimisation du README :** Aide à la mise en page et à la structuration de cette documentation.

### 🚫 Ce que l'IA n'a PAS fait :
* **Logique de l'Algorithme :** La stratégie de tri et le choix des mouvements ont été pensés et implémentés manuellement.
* **Architecture du Code :** La structure des listes chaînées et la gestion des piles sont de ma propre conception.

> **Note :** L'IA a été utilisée pour accélérer la compréhension de certains concepts mathématiques et pour gagner du temps sur le formatage, tout en garantissant que chaque ligne de code poussée a été comprise et réécrite par mes soins.