# IUSTZ - Text-Based RPG Game

**Advanced Programming Course - Spring 1403**  
**Department of Mathematics and Computer Science**
**Iran University of Science and Technology**


## About the Project

IUSTZ is a C++ text-based RPG (Role Playing Game) project, designed and implemented using object-oriented principles. The game immerses players in a post-apocalyptic world where they must fight for survival against zombies and hostile humans.

## Gameplay Summary

- Players begin by creating and customizing a character (name, age, gender).
- The game alternates between different **story phases** like battles and visiting the shop.
- All interactions take place through the **terminal/console** using keyboard inputs.
- Save/load system allows resuming a character's journey.

## Key Features

- Turn-based battle system
- 3 main characters to choose from:
  - Jon Snow
  - Dumbledore
  - Michelangelo
- Multiple enemy types:
  - Normal Zombie
  - Strong Zombie
  - Human Enemy with FSM (Finite State Machine) logic
- Skill & Leveling System:
  - Level up by gaining XP
  - Upgrade Strength or Intelligence to boost weapons
- Backpack & Inventory Management:
  - Cold Weapons, Firearms, Consumables, Throwables
  - Weapon upgrade mechanics
- In-game shop for purchasing items and weapons
- Save/Load system (using `.txt` files)

## Project Structure

- `characters/` → Character saves and name list  
- `BackPack` & `Weapon` classes → Inventory system  
- `characters`, `zombie`, `Human`, `EnemyFactory` → All game entities  
- `main()` → Game loop and entry point

## Notes

- Please do **not rename, move or delete** folders/files (e.g., `characters/CharNames.txt`), as this may break the save/load system.
- Built for **Windows OS** (due to `windows.h`, `Beep`, `conio.h`).
- Ensure terminal supports ANSI color codes for colored text.

## Team Members

- Fateme Bakhshi
- Mahshid Rajabirad
- Yasaman Saffar Tabasi
- Parmis Miremadi

---

> Final submission tagged as v1.0 in the Releases section
> This project was developed as the first course project for the "Advanced Programming" class at IUST (Spring 1403).
