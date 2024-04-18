
# Vera Molnar creator

Pour créer des jolies oeuvres d'art


## Installation

Compile & run project

### Windows
```bash
  cd build && cmake . && make && cd .. && .\veramolnar
```

### Linux
```bash
  cd build && cmake . && make && cd .. && ./veramolnar
```


## File Synthax     

### Formes

Cercle
```
Cercle <centre> <rayon> <couleur>
```

Polygone
```
Polygone <nombre points> <point> ... <couleur>
```

Pour créer des objets complexes écrire chaque objet à une ligne différente selon la même synthaxe.

# Transformations

Pour créer une transformation à appliquer un objet, suivez la synthaxe suivante dans un fichier.txt:

```
[index] [type] [argument] ...
```

Les trois types de transformations possibles sont: dilate, rotate et color. Vous pouvez ajoutez autant de transformations 
que nécessaire mais toutes les transformations d'un object doivent impérativement être sur la même ligne.

## Authors

- REPORT Tanguy
- PRUVOST Benjamin