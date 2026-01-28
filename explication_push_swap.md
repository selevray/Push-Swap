# 📚 Explication Simple : Push Swap

## 🎯 L'objectif

Trier une pile de nombres en utilisant **2 piles** (A et B) et des opérations limitées :
- `pa` / `pb` : pousser un élément d'une pile à l'autre
- `ra` / `rb` : rotation vers le haut
- `rra` / `rrb` : rotation vers le bas
- `rr` / `rrr` : rotation simultanée des deux piles

---

## 🔄 Comment ça fonctionne ? (Étape par étape)

### **Étape 1 : Indexation** 📊
*Fichier : `sort_and_index.c`*

Avant de commencer à trier, on donne un **numéro d'ordre** à chaque nombre.

**Exemple :**
```
Pile initiale : [5, 2, 8, 1, 4]
Après indexation : 
  5 → index 3
  2 → index 1
  8 → index 4
  1 → index 0
  4 → index 2
```

On calcule aussi la **médiane** (la valeur du milieu quand tout est trié).

---

### **Étape 2 : Répartition dans pile B** 🎲
*Fichier : `insertion.c` → fonction `insertion_sort`*

On garde seulement **3 éléments** dans la pile A, le reste va dans la pile B.

**Astuce intelligente** : Les nombres **plus petits que la médiane** sont poussés vers le bas de pile B avec `rb`. Cela prépare un ordre optimal pour la suite.

```
Pile A : [5, 2, 8, 1, 4]  →  Pile A : [5, 2, 8]
Pile B : []                    Pile B : [1, 4] (1 est en bas)
```

---

### **Étape 3 : Tri des 3 derniers** 🔢
*Fichier : appelé via `sort_three`*

On trie les 3 éléments restants dans la pile A (c'est simple avec 3 éléments !).

---

### **Étape 4 : Réinsertion intelligente** 🧠
*Fichiers : `insertion_utils.c` et `insertion_exec.c`*

Pour chaque élément de la pile B, on fait :

1. **Trouver sa position cible** dans la pile A
   - On cherche le plus petit nombre qui est **plus grand** que notre élément
   - Si aucun n'existe, on le place avant le minimum

2. **Calculer le coût** de chaque possibilité
   - Combien de rotations faut-il pour amener l'élément de B en haut ?
   - Combien de rotations pour préparer la position dans A ?
   - **Bonus** : Si on doit tourner les deux piles dans le même sens, on peut faire `rr` ou `rrr` pour économiser des mouvements !

3. **Choisir le mouvement le moins coûteux** et l'exécuter

**Exemple de calcul de coût :**
```
Pile B : [4, 1, 3]  (on veut insérer 4)
Pile A : [2, 5, 8]

Position de 4 dans B : 0 (déjà en haut) → coût = 0
Position cible dans A : avant 5 (position 1) → coût = 1
Coût total : 0 + 1 = 1 ✅
```

---

### **Étape 5 : Alignement final** 🎯
*Fichier : `insertion.c` → fonction `final_rotate`*

Une fois tous les éléments réinsérés, on fait tourner la pile A pour placer le **minimum en haut**.

```
Pile A : [8, 1, 2, 3, 4, 5]
         ↓ rotation
Pile A : [1, 2, 3, 4, 5, 8] ✅ TRIÉ !
```

---

## 💡 Les points clés de l'optimisation

### 1. **Rotation combinée** 
Si pile A et pile B doivent tourner dans le même sens, on utilise `rr` ou `rrr` pour gagner des mouvements.

### 2. **Choix intelligent**
À chaque itération, on calcule **tous les coûts possibles** et on choisit le meilleur (algorithme glouton).

### 3. **Stratégie de la médiane**
En poussant les petits nombres vers le bas de pile B, on optimise l'ordre de réinsertion.

---

## 📂 Résumé des fichiers

| Fichier | Rôle |
|---------|------|
| `sort_and_index.c` | Donne un index à chaque nombre et calcule la médiane |
| `insertion.c` | Orchestre l'algorithme principal |
| `insertion_utils.c` | Calcule les positions cibles et les coûts |
| `insertion_exec.c` | Exécute les rotations optimales |

---

## 🎓 Analogie simple

Imagine que tu tries des cartes :
1. Tu **numérotes** chaque carte (indexation)
2. Tu gardes 3 cartes dans ta main gauche, le reste va à droite
3. Tu **tries les 3 cartes** dans ta main gauche
4. Pour chaque carte à droite, tu cherches **où la glisser** dans ta main gauche
5. Tu choisis toujours l'option qui demande **le moins de mouvements**
6. À la fin, tu ajustes ta main pour que la plus petite carte soit devant

Et voilà ! Tes cartes sont triées ! 🎉
