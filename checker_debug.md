# Debug checker: log instructions

This file is used to debug why checker returns Error.

## Étapes de debug

1. Ajout d'un print dans execute_instruction pour afficher chaque ligne lue.
2. Si une instruction n'est pas reconnue, afficher la ligne problématique.
3. Relancer la commande :

```sh
./push_swap 1 2 6 8 3 4 | ./checker 1 2 6 8 3 4
```

## À faire
- Vérifier si push_swap génère une instruction inconnue ou une ligne vide.
- Vérifier si la fonction get_next_line lit bien jusqu'à la fin.
- Vérifier si les instructions sont bien terminées par un '\n'.

## Correction
- Si une ligne vide ou inconnue est lue, checker renverra Error.
- Il faut que push_swap ne génère que des instructions valides et bien formatées.
