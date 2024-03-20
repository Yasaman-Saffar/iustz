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
    int Level;
    double HP;
    int Stamina;
    int Money;
    string name;
    int age;

public:
    Player() : Level(1), HP(100), Stamina(100) {} // also, reads userInfo file and sets name, age, money,.. from the file
    string getName() { return name; }
    double getHP() { return HP; }
    int getStamina() { return Stamina; }
    int getMoney() { return Money; }
    int getAge() { return age; }
    int getLevel() { return Level; }
    void levelUp() {Level += 1;}
    virtual double attack() { return 8; }
    void damage(double enemyWeapon) { HP = HP - enemyWeapon; } // the parameter is the member function of Enemy
};

class Enemy
{
private:
    int Level;
    double HP;
    int Stamina;
    

protected:
    string wea;
    double e;

public:
    Enemy() : Level(1), HP(100), Stamina(100), wea(""), e(1) {} // The default constructor which initializes both HP and Stamina to 100.

private:
    // Enemy(ifstream readFile);                        // Opens the respective file and reads level of player from it                                    // coefficient: ordinary=1 and stronger=1.2?
    double sword = 5 * Level * e / 100;              // Level>=5. Level is first derived from a file.
    double knife = 2 * Level * e / 100;              // Level>=2
    double throwingStars = 1 * Level * HP * e / 100; // Level>=1

public:
    double Weapon(); // randomly chooses a weapon between the three above. It is called when the enemy attacks and reduces the player's HP.
    double getHP() { return HP; }
    int getStamina() { return Stamina; }
    string getWeapon() { return wea; }
    void damage(double playerAttack) { HP = HP - playerAttack; }
    void levelUp() {Level+=1;}
};
// Enemy::Enemy(ifstream readFile)
// {
//     // Opens a file and reads level from it.
// }
double Enemy::Weapon() // Needs to be redefined
{
    int Rand = rand() % 100 + 1;
    cout << Rand << endl;
    if (Rand <= 33 && Level >= 1)
    {
        wea = "throwingStar";
        return throwingStars;
    }
    else if (Rand > 33 && Rand <= 66 && Level >= 2)
    {
        wea = "kife";
        return knife;
    }
    else if (Rand > 66 && Level >= 5)
    {
        wea = "sword";
        return sword;
    }
    else
    {
        wea = "throwingStar";
        return throwingStars;
    }
}

//*****//

// class zombie : public Enemy
// {
// public:
//     zombie() : e(1) {} // Initializes e from Enemy to 1
// };

// //*****//

// class strongZombie : public Enemy
// {
//     strongZombie() : e(1.2) {} // Initializes e from Enemy to 1.2(?)
// };

//*****//

int main()
{
    Enemy en;
    Player pl;
    cout << "_____________________________________________" << endl;
    cout << "_____________________________________________" << endl;
    cout << "First Round:" << endl;
    cout << "Player's level: " << pl.getLevel() << endl;
    cout << "Enemy's HP: " << en.getHP() << endl;
    cout << "Enemy's stamina: " << en.getStamina() << endl;
    cout << "Player's HP: " << pl.getHP() << endl;
    cout << "Player's stamina: " << pl.getStamina() << endl;
    double d1 = en.Weapon();
    cout << "Enemy's weapon: " << en.getWeapon() << endl;
    cout << "Enemy's damage on the player: " << d1 << endl;
    pl.damage(d1);
    double d2 = pl.attack();
    cout << "Player's HP after enemy's attack: " << pl.getHP() << " (100)" << endl;
    cout << "_____________________________________________" << endl;
    cout << "Player's damage on enemy: " << d2 << endl; 
    en.damage(d2);
    cout << "Enemy's HP after player's attack: " << en.getHP() << " (100)" << endl;
    cout << "_____________________________________________" << endl;
    cout << "_____________________________________________" << endl;
    cout << "Second Round:" << endl;
    cout << "Player's level: " << pl.getLevel() << endl;
    double d3 = en.Weapon();
    cout << "Enemy's weapon: " << en.getWeapon() << endl;
    cout << "Enemy's damage on the player: " << d3 << endl;
    pl.damage(d3);
    double d4 = pl.attack();
    cout << "Player's HP after enemy's attack: " << pl.getHP() << " (100)" << endl;
    cout << "_____________________________________________" << endl;
    cout << "Player's damage on enemy: " << d4 << endl; 
    en.damage(d4);
    cout << "Enemy's HP after player's attack: " << en.getHP() << " (100)" << endl;
    cout << "_____________________________________________" << endl;
    cout << "_____________________________________________" << endl;
    cout << "Third Round:" << endl;
    cout << "Player's level: " << pl.getLevel() << endl;    
    double d5 = en.Weapon();
    cout << "Enemy's weapon: " << en.getWeapon() << endl;
    cout << "Enemy's damage on the player: " << d5 << endl;
    pl.damage(d5);
    double d6 = pl.attack();
    cout << "Player's HP after enemy's attack: " << pl.getHP() << " (100)" << endl;
    cout << "_____________________________________________" << endl;
    cout << "Player's damage on enemy: " << d6 << endl; 
    en.damage(d6);
    cout << "Enemy's HP after player's attack: " << en.getHP() << " (100)" << endl;
    cout << "_____________________________________________" << endl;
    cout << "_____________________________________________" << endl;
}
