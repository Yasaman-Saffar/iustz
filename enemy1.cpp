#include <iostream>
#include <string>
#include <fstream>
using namespace std;

double Attack; // Attack is a member function of the class "Player" with the returned type double.
               //  It is calculated based on the level, choice of weapon and other factors that
               // impact the HP of the enemy.

class Enemy
{
private:
    int Level;
    double HP;
    int Stamina;
    double e;
    Enemy(ifstream readFile);                        // Opens the respective file and reads level of player from it                                    // coefficient: ordinary=1 and stronger=1.2?
    double sword = 5 * Level * HP * e / 100;         // Level>=5. Level is first derived from a file.
    double knife = 2 * Level * HP * e / 100;         // Level>=2
    double throwingStars = 1 * Level * HP * e / 100; // Level>=1
public:
    Enemy();          // The default constructor which initializes both HP and Stamina to 100.
    double Weapon();  // randomly chooses a weapon between the three above. It is called when the enemy attacks.
    void Damage();    // reduces the HP of the enemy due to damage done by the player. It is called when the player attacks.
    double getHP();   // returns HP.
    int getStamina(); // returns Stamina.
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
double Enemy::Weapon()
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
void Enemy::Damage()
{
    HP = HP - HP * Attack; // Attack is a member function of the class "Player" which returns the percentage
                           // of reduced HP of the enemy based on the level, choice of weapon etc.
}
double Enemy::getHP() { return HP; }
int Enemy::getStamina() { return Stamina; }