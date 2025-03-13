# Module 07 - C++ Templates

Bienvenue dans le **Module 07** du cursus C++ de 42. Ce module se concentre sur l'utilisation des templates en C++, un concept puissant qui permet de créer des fonctions et des classes génériques.

---

## Objectifs pédagogiques

Dans ce module, vous apprendrez à :

- Utiliser les templates pour créer des fonctions et des classes génériques.
- Comprendre la syntaxe et les capacités des templates.
- Implémenter des fonctions utilitaires avec des templates.
- Gérer les tableaux et les itérations avec des templates.
- Créer des classes de tableaux génériques avec des fonctionnalités avancées.

---

## Concept de Templates en C++

Les templates en C++ permettent de définir des fonctions et des classes qui peuvent fonctionner avec des types de données génériques. Cela permet d'écrire du code réutilisable et flexible, capable de manipuler différents types de données sans duplication de code.

### Exemple de Fonction Template

Voici un exemple simple d'une fonction template qui échange deux valeurs :

```cpp
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
```
Cette fonction peut être utilisée avec n'importe quel type de données, tant que les opérations effectuées sont supportées par ce type.

---

## Contenu du module

Le module 07 contient les exercices suivants :

### 1. **Exercice 00 : Start with a few functions**
   - **Description :** Implémentation de fonctions templates pour échanger, trouver le minimum et le maximum de deux valeurs.
   - **Concepts abordés :**
     - Création de fonctions templates.
     - Utilisation des opérateurs de comparaison.
     - Manipulation de différents types de données.

### 2. **Exercice 01 : Iter**
   - **Description :** Création d'une fonction template `iter` qui applique une fonction à chaque élément d'un tableau.
   - **Concepts abordés :**
     - Utilisation de templates avec des tableaux.
     - Application de fonctions sur des collections de données.

### 3. **Exercice 02 : Array**
   - **Description :** Développement d'une classe template `Array` pour gérer des tableaux génériques avec des fonctionnalités avancées.
   - **Concepts abordés :**
     - Création de classes templates.
     - Gestion de la mémoire avec `new[]` et `delete[]`.
     - Accès sécurisé aux éléments du tableau.

---

## Instructions pour compiler et exécuter

1. Accédez au dossier du Module 07 :
   ```bash
   cd modules/module-07

2. Pour compiler les exercices d'un module, rendez-vous dans le dossier du module souhaité :
   ```bash
   cd modules/module-07/exXX
   make

3. Exécutez le programme généré, par exemple :
   ```bash
   ./template_example

---

## Ressources supplémentaires

- [Documentation sur les templates en C++](https://en.cppreference.com/w/cpp/language/templates)
- [Tutoriel sur les fonctions templates](https://www.learncpp.com/cpp-tutorial/function-templates/)
- [Introduction aux classes templates](https://www.learncpp.com/cpp-tutorial/class-templates/)