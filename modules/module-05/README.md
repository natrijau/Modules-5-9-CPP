# Module 05 - Répétition et Exceptions

Bienvenue dans le **Module 05** du cursus C++ de 42. Ce module se concentre sur la gestion des exceptions et la répétition des concepts fondamentaux de la programmation orientée objet (OOP) en C++.

---

## Objectifs pédagogiques

Dans ce module, vous apprendrez à :

- Gérer les exceptions en C++.
- Utiliser les classes et les objets de manière avancée.
- Manipuler les grades et les formulaires dans un contexte bureaucratique.
- Implémenter des classes abstraites et concrètes.
- Utiliser les opérateurs d'insertion pour l'affichage.

---

## Concept d'Exceptions

Les exceptions en C++ sont un mécanisme permettant de gérer les erreurs et les situations exceptionnelles qui peuvent survenir pendant l'exécution d'un programme. Elles permettent de séparer le code de gestion des erreurs du code normal, rendant ainsi le programme plus lisible et plus facile à maintenir.

### Exemple de `try` et `catch`

Voici un exemple simple illustrant l'utilisation des exceptions avec `try` et `catch` :

```cpp
#include <iostream>
#include <stdexcept>

/*	Dans cet exemple, une exception std::runtime_error est levée 
	si une erreur se produit, et elle est capturée dans le bloc catch, où un message d'erreur est affiché. 
*/

void wrongTest()
{
    bool errorOccurred = true;
    if (errorOccurred)
        throw std::runtime_error("An error occurred!");
}

int main() {
    try{
        wrongTest();
    }
	catch (const std::exception &e){
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    return (0);
}
```
- [Documentation sur les exceptions en C++](https://en.cppreference.com/w/cpp/error/exception)
- [... avec exemples](https://www.w3schools.com/cpp/cpp_exceptions.asp)


---

## Contenu du module

Le module 05 contient les exercices suivants :

### 1. **Exercice 00 : Mommy, when I grow up, I want to be a bureaucrat!**
   - **Description :** Création d'une classe `Bureaucrat` avec des grades et gestion des exceptions pour les grades invalides.
   - **Concepts abordés :**
     - Gestion des exceptions.
     - Utilisation des constantes et des getters.
     - Implémentation des opérateurs d'insertion.

### 2. **Exercice 01 : Form up, maggots!**
   - **Description :** Introduction de la classe `Form` et interaction avec la classe `Bureaucrat`.
   - **Concepts abordés :**
     - Gestion des attributs privés.
     - Utilisation des exceptions pour les grades invalides.
     - Signature et exécution des formulaires.

### 3. **Exercice 02 : No, you need form 28B, not 28C...**
   - **Description :** Création de classes concrètes dérivées de la classe abstraite `AForm`.
   - **Concepts abordés :**
     - Classes abstraites et concrètes.
     - Exécution des actions spécifiques aux formulaires.
     - Gestion des exceptions pour les grades invalides.

### 4. **Exercice 03 : At least this beats coffee-making**
   - **Description :** Implémentation de la classe `Intern` pour créer des formulaires.
   - **Concepts abordés :**
     - Utilisation de fonctions pour créer des objets.
     - Gestion des erreurs et des messages d'erreur.

---

## Instructions pour compiler et exécuter

1. Accédez au dossier du Module 05 :
   ```bash
   cd modules/module-05

2. Pour compiler les exercices d'un module, rendez-vous dans le dossier du module souhaité :
   ```bash
   cd modules/module-05/ex00
   make

3. Exécutez le programme généré, par exemple :
   ```bash
   ./bureaucrat

---

## Ressources supplémentaires

- [Documentation sur les exceptions en C++](https://en.cppreference.com/w/cpp/error/exception)
- [Tutoriel sur les classes abstraites en C++](https://www.learncpp.com/cpp-tutorial/abstract-classes/)
- [Introduction aux opérateurs d'insertion en C++](https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/)
