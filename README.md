# ft_printf

> Reproduction partielle de la fonction standard `printf` en C, conforme au standard 42.

---

## 🎯 Objectif principal

- Reproduire une version simplifiée mais fidèle de la fonction `printf`.
- Gérer le formatage, l'affichage, et le comptage exact des caractères imprimés.
- Respecter le comportement de la `libc` (GNU printf) au caractère près.

---

## ✨ Objectif bonus

- Gérer les flags complexes (`+`, ` `, `#`, `0`, `-`, `.precision`, `width`)
- Respecter les règles de priorité (entre padding, alignement, précision…)
- Être capable de tester les cas limites, les `NULL`, les `\0`, etc.
- Bonus validé si gestion de plusieurs combinaisons imbriquées (`%0#8.5x`, etc.)

---

## ✅ Fonction demandée

```c
int ft_printf(const char *format, ...)
```

- Imprimer sur la sortie standard (write)
- Interpréter tous les formats supportés
- Retourner le nombre total d’octets écrits (comme printf)

---

## 🔤 Types supportés

| Format      | Description                        | va_arg         |
| ----------- | ---------------------------------- | -------------- |
| `%c`        | Caractère                          | `int`          |
| `%s`        | Chaîne de caractères               | `char *`       |
| `%p`        | Pointeur (affiché en hex, "0x...") | `void *`       |
| `%d` / `%i` | Entier signé                       | `int`          |
| `%u`        | Entier non signé                   | `unsigned int` |
| `%x`        | Hexadécimal (minuscules)           | `unsigned int` |
| `%X`        | Hexadécimal (MAJUSCULES)           | `unsigned int` |
| `%%`        | Affiche un `%` littéral            | —              |

---

## ⚙️ Flags gérés

| Flag     | Effet                                           | Types concernés      |
| -------- | ----------------------------------------------- | -------------------- |
| `-`      | Alignement à gauche                             | Tous sauf `%p`, `%%` |
| `0`      | Padding avec des zéros                          | Tous sauf `%s`, `%p` |
| `.`      | Précision (`.N`)                                | `%s`, numériques     |
| `#`      | Forme alternative (`0x`, `0X`, `0`)             | `%x`, `%X`, `%o`     |
| `+`      | Affiche le `+` pour les entiers positifs        | `%d`, `%i`           |
| (espace) | Préfixe un espace pour positifs (si pas de `+`) | `%d`, `%i`           |
| `width`  | Largeur minimale d'affichage                    | Tous                 |

---

## 📁 Structure du projet

```bash
.
├── srcs/
│ ├── ft_printf.c # Point d’entrée
│ ├── utils.c # Utilitaires
│ ├── parsers/ # Parsing des formats
│ ├── transformers/ # Application des formats sur arguments
│ ├── printers # Impression des composants
│ └── utils.c # Fonctions d’aide
├── Makefile
└── libft/ # Libft 42
```

---

## ⚙️ Utilisation

### Compilation :

```bash
make        # compile la version obligatoire
make bonus  # compile la version avec flags
```

### Example :

Vous pouvez compiler ce fichier de test pour comparer `ft_printf` et `__builtin_printf` :

```c
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    int ret1, ret2;

    // Test %d avec +, width et precision
    ret1 = ft_printf("ft : |%+08.5d|\n", 42);
    ret2 = __builtin_printf("lib: |%+08.5d|\n", 42);
    printf("Return values: ft = %d, libc = %d\n\n", ret1, ret2);

    // Test %s avec precision
    ret1 = ft_printf("ft : |%.3s|\n", "Hello");
    ret2 = __builtin_printf("lib: |%.3s|\n", "Hello");
    printf("Return values: ft = %d, libc = %d\n\n", ret1, ret2);

    // Test %p
    void *ptr = (void *)0x42;
    ret1 = ft_printf("ft : |%p|\n", ptr);
    ret2 = __builtin_printf("lib: |%p|\n", ptr);
    printf("Return values: ft = %d, libc = %d\n\n", ret1, ret2);

    // Test %x avec #
    ret1 = ft_printf("ft : |%#08x|\n", 255);
    ret2 = __builtin_printf("lib: |%#08x|\n", 255);
    printf("Return values: ft = %d, libc = %d\n\n", ret1, ret2);

    // Test %c avec width et char nul
    ret1 = ft_printf("ft : |%5c|\n", '\0');
    ret2 = __builtin_printf("lib: |%5c|\n", '\0');
    printf("Return values: ft = %d, libc = %d\n\n", ret1, ret2);

    return 0;
}
```

---

## 👨‍💻 Auteur

- dcastor – [42 student]
