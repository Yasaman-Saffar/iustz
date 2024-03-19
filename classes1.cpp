#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>   //baraye seda
#include <windows.h> //baraye seda
#include <string>
using namespace std;
// baraye rangi shodan
#define RESET "\033[0m"
#define ORANGE "\033[38;5;208m"
#define GRAY "\033[38;5;8m"
#define RED "\033[31m" // germez shodan

class Enemy;
class Player
{
private:
    double HP;
    int Stamina;
    int Money;
    string name;
    int age;
public:
    Player() : HP(100), Stamina(100) {} // also, reads userInfo file and sets name, age, money,.. from the file
    string getName() { return name; }
    double getHP() { return HP;}
    int getStamina() { return Stamina; }
    int getMoney() { return Money; }
    int getAge() {return age; }
    void Pdamage(Enemy &enemyObj) { HP = HP - HP * enemyObj.Weapon(); }
    virtual double attack() { return 0; }
    friend void Edamage(Player &playerObj);
};

class Enemy
{
private:
    int Level;
    double HP;
    int Stamina;

    Enemy(ifstream readFile);                        // Opens the respective file and reads level of player from it                                    // coefficient: ordinary=1 and stronger=1.2?
    double sword = 5 * Level * HP * e / 100;         // Level>=5. Level is first derived from a file.
    double knife = 2 * Level * HP * e / 100;         // Level>=2
    double throwingStars = 1 * Level * HP * e / 100; // Level>=1
protected:
    double e;

public:
    Enemy();         // The default constructor which initializes both HP and Stamina to 100.
    double Weapon(); // randomly chooses a weapon between the three above. It is called when the enemy attacks and reduces the player's HP.
    // void Damage();    // reduces the HP of the enemy due to damage done by the player. It is called when the player attacks.
    double getHP();   // returns HP.
    int getStamina(); // returns Stamina.

    friend class Player;
    void Edamage(Player &playerObj) { HP = HP - HP * playerObj.attack(); }
    friend void Pdamage(Enemy &enemyObj);
};
Enemy::Enemy(ifstream readFile)
{
    // Opens a file and reads level from it.
}
Enemy::Enemy()
{
    HP = 100;
    Stamina = 100;
}
double Enemy::Weapon() // Needs to be redefined
{
    int Rand = rand() % 3 + 1;
    if (Rand == 1 && Level >= 1)
    {
        return throwingStars;
    }
    else if (Rand == 2 && Level >= 2)
    {
        return knife;
    }
    else if (Rand == 3 && Level >= 5)
    {
        return sword;
    }
    else
    {
        return throwingStars;
    }
}
// void Enemy::Damage()
// {
//     HP = HP - HP * PlayerAttacks; // PlayerAttacks is a member function of the class "Player" which returns the percentage
//                                   // of reduced HP of the enemy based on the level, choice of weapon etc.
// }
// double Enemy::getHP() { return HP; }
// int Enemy::getStamina() { return Stamina; }

//*****//

class zombie : public Enemy
{
public:
    zombie(); // Initializes e from Enemy to 1
};

zombie::zombie() { e = 1; }

//*****//

class strongZombie : public Enemy
{
    strongZombie(); // Initializes e from Enemy to 1.2(?)
};

strongZombie::strongZombie() { e = 1.2; }

//*****//

int main()
{
    Enemy en;
    Player pl;
    cout << "Enemy's HP: " << en.getHP() << endl;
    cout << "Enemy's stamina: " << en.getStamina() << endl;
    cout << "Player's HP: " << pl.getHP() << endl;
    cout << "Player's stamina: " << pl.getStamina() << endl; 
}