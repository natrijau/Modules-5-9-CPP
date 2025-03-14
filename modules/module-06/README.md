# Module 06 - C++ Casts

Bienvenue dans le **Module 06** du cursus C++ de 42. Ce module se concentre sur les conversions de types en C++ et la gestion des casts, tout en renforçant les concepts de programmation orientée objet (OOP).

---

## Objectifs pédagogiques

Dans ce module, vous apprendrez à :

- Effectuer des conversions de types en C++.
- Utiliser les casts pour manipuler les types de données.
- Sérialiser et désérialiser des pointeurs.
- Identifier les types réels d'objets à l'aide de méthodes spécifiques.
- Gérer les conversions de types de manière sécurisée.

---

## Concept de Casts en C++

Les casts en C++ permettent de convertir un type de données en un autre. Cela peut être nécessaire dans diverses situations, comme la conversion entre types primitifs ou la gestion des pointeurs. Les casts peuvent être explicites ou implicites, et il est important de les utiliser judicieusement pour éviter les erreurs et les comportements inattendus.

### Types de Casts

1. **C-style cast** : `(type)expression`
2. **Static cast** : `static_cast<type>(expression)`
3. **Dynamic cast** : `dynamic_cast<type>(expression)`
4. **Const cast** : `const_cast<type>(expression)`
5. **Reinterpret cast** : `reinterpret_cast<type>(expression)`

Chaque type de cast a ses propres cas d'utilisation et implications. Par exemple, `dynamic_cast` est utilisé pour les conversions sûres entre types polymorphiques.

---

## Contenu du module

Le module 06 contient les exercices suivants :

### 1. **Exercice 00 : Conversion of scalar types**
   - **Description :** Création d'une classe `ScalarConverter` pour convertir des représentations littérales en différents types scalaires (char, int, float, double).
   - **Concepts abordés :**
     - Conversion de types.
     - Gestion des cas spéciaux (NaN, inf).
     - Manipulation des limites numériques.

### 2. **Exercice 01 : Serialization**
   - **Description :** Implémentation d'une classe `Serializer` pour sérialiser et désérialiser des pointeurs.
   - **Concepts abordés :**
     - Sérialisation et désérialisation.
     - Manipulation des pointeurs et des types uintptr_t.

### 3. **Exercice 02 : Identify real type**
   - **Description :** Identification du type réel d'objets à l'aide de méthodes spécifiques sans utiliser `std::typeinfo`.
   - **Concepts abordés :**
     - Identification dynamique de type.
     - Utilisation de l'héritage et des pointeurs.

---

## Instructions pour compiler et exécuter

1. Accédez au dossier du Module 06 :
   ```bash
   cd modules/module-06

2. Pour compiler les exercices d'un module, rendez-vous dans le dossier du module souhaité :
   ```bash
   cd modules/module-06/ex01
   make

3. Exécutez le programme généré, par exemple :
   ```bash
   ./convert (argument)

---

## Ressources supplémentaires

- [Documentation sur les casts en C++](https://en.cppreference.com/w/cpp/language/explicit_cast)
- [Introduction aux conversions de types en C++](https://www.learncpp.com/cpp-tutorial/type-casting/)
