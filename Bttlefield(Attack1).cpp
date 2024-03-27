#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <chrono> 
#include <thread> 
#include<conio.h>//for sound of error
#include<windows.h>//for sound of error
#include <ctime>
using namespace std;

//clear the console screen 
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

//for color of text
#define RESET   "\033[0m"
#define ORANGE    "\033[38;5;208m"
#define GRAY    "\033[38;5;8m"
#define BLUE    "\033[94m"
#define RED		"\033[31m"

class Weapon{
public:
    string name;
    int price;
    int damage;

    Weapon(string _name , int _price , int _damage) : name(_name) , price(_price) , damage(_damage){}
};
class BackPack{
private:
    vector<pair<string , int>> BPWeapons;//vector for weapons
public:
    void AddWeapon(string name , int damage)
    {
        BPWeapons.push_back(make_pair(name , damage));
    }
    void InsideTheBackpack()//show of weapons in the backpack
    {
        cout << "Weapons In Your Backpack :" << endl;
        int i = 1;
        for(const auto& weapon : BPWeapons)
        {
            cout <<"(" << i << ") " << weapon.first << " [Damage = " << weapon.second << "]" << endl;
            i++;
        }
        cout << "(" << i + 1 << ") Back" << endl;
        cout << endl;
        cout << "Which One Do You Want To Choose?" << endl;
        int number;
        while(true)
        {
            cin >> number;
            cout << endl;
        	if(number < 1 || number > i + 1)
        	{
        		cout << RED << "Please Enter A Valid Number(1-" << i + 1 << ") :" << RESET << endl;
				Beep(500 , 800); //error
			}
			else if(number == i + 1)
				break;
			//else
				//bardashtane selah***********
		}
    }
    const vector<pair<string, int>>& getWeapons() 
    {
        return BPWeapons;
    }
};
class characters;

void SavePlayer(characters*, BackPack*);
void ChoosingChar();
void clearConsole();

class characters{
private:
    string Name;
    int Age;
    string Gender;

protected:
    string Type;
    int Level;
    int Stamina;
    int HP;
public:
    int Money;
    characters() = default;
    characters(string name, int age, string gender, int level, int stamina, int hp, int money)
    :Name(name), Age(age), Gender(gender), Level(level), Stamina(stamina), HP(hp), Money(money){}

    string getName() {return Name;}
    void setName(string name) {Name = name;}
    int getAge() {return Age;}
    void setAge(int age) {Age = age;}
    string getGender() {return Gender;}
    void setGender(string gender) {Gender = gender;}
    string getType() {return Type;}
    int getLevel() { return Level; }
    double getHP() { return HP; }
    void setHP(double hp1) { HP = hp1; }
    int getStamina() { return Stamina; }
    void setStamina(int stam1) { Stamina = stam1; }
    void levelUp() {Level += 1;}
    virtual double attack() { return 8; } //DEFINITION NEEDED!!!!
    void damage(double enemyWeapon) { HP = HP - enemyWeapon; } // the parameter is the member function of Enemy

    void ShowInfo()
    {
        cout << "Level|" << Level << "|   " << "HP|" << HP << "|   "<< "Stamina|" << Stamina << "|   " << "Money|" << Money << "|   " << endl;
    }
    void ShowMoney()
    {
        cout << "Your Money: " << Money << "$";
    }
    virtual void ShowShop(characters*&) = 0;
    virtual void BuyWeapon(characters*&, BackPack*&) = 0;
    //virtual void Attack() = 0;*******
    void showInventory(BackPack*& charInventory) { charInventory->InsideTheBackpack(); }
    virtual double Damege(string name,int damege) { return 0; }
    virtual double IncreaseStamina(string name,int damege) { return 0; }
    virtual double IncreaseHp(string name,int damege) { return 0; }
};

class Michelangelo : public characters
{
private:
    vector<Weapon> weapons;

public:
    Michelangelo(string name, int age, string gender, int level, int stamina, int hp, int money)
    :characters(name, age, gender, level, stamina, hp, money)
    {
        Type = "Michelangelo";
        weapons.push_back(Weapon("Sword" , 40 , 20));
        weapons.push_back(Weapon("Dagger" , 20 , 20));
        weapons.push_back(Weapon("Nanchiko" , 20 , 20));
        weapons.push_back(Weapon("Colt" , 20 , 20));
        weapons.push_back(Weapon("ShutGun" , 20 , 20));
        weapons.push_back(Weapon("Winchester" , 20 , 20));
        weapons.push_back(Weapon("Bomb" , 20 , 20));
        weapons.push_back(Weapon("Smoker" , 20 , 20));
        weapons.push_back(Weapon("Boomerang" , 20 , 20));
        weapons.push_back(Weapon("ThrowingKnife" , 20 , 20));
        weapons.push_back(Weapon("Pizza" , 20 , 20));
        weapons.push_back(Weapon("FrenchFries" , 20 , 20));
        weapons.push_back(Weapon("Coca" , 20 , 20));
        weapons.push_back(Weapon("IceMonkey" , 20 , 20)); 
    }
    double Damege(string name,int damege) override
    {
        if(name=="Sword")
        return damege*(Level/2);
        if(name=="Dagger")
        return damege*(Level/2.5);
        if(name=="Nanchiko")
        return damege*(Level/3);
        if(name=="Colt")
        return damege*(Level);
        if(name=="ShutGun")
        return damege*(Level/1.5);
        if(name=="Winchester")
        return damege*(Level/2);
        if(name=="Bomb")
        return damege*(Level/1.5);
        if(name=="Smoker")
        return damege*(Level/2);
        if(name=="Boomerang")
        return damege*(Level/2.5);
        if(name=="ThrowingKnife")
        return damege*(Level/3);
    }
    double IncreaseStamina(string name,int damege) override
    {
        if(name=="Coca")
        return damege*(Level/2);
        if(name=="IceMonkey")
        return damege*(Level/2.5);
    }
    double IncreaseHp(string name,int damege) override
    {
        if(name=="Pizza")
        return damege*(Level/2);
        if(name=="FrenchFries")
        return damege*(Level/2.5);
    }

    //shop
    virtual void ShowShop(characters* &player) override
    {
        clearConsole();
    	cout << endl;
    	cout << ORANGE << "'Hi Brave, You've Chosen The Best Shop! Here You Can Find Anything You Need.'" << endl;
        cout << "Your Money: " << player->Money << "$" << endl << endl;
    	cout << "Cold Weapons :" << endl;

        for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << "(" << i + 1 << ") " << weapons[i].name << " [Damage: -" << weapons[i].damage << " , Price: " << weapons[i].price << "$]" << endl;
    	}

    	cout << endl;
		cout << "Firearms :" << endl;
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << "(" << i + 4 << ") " << weapons[i + 3].name << " [Damage: -" << weapons[i + 3].damage << " , Price: " << weapons[i + 3].price << "$]" << endl;
    	}

    	cout << endl;
		cout << "Throwing Weapons :" << endl;
    	for(int i = 0 ; i < 4 ; i++)
    	{
        	cout << "(" << i + 7 << ") " << weapons[i + 6].name << " [Damage: -" << weapons[i + 6].damage << " , Price: " << weapons[i + 6].price << "$]" << endl;
    	}

    	cout << endl;
		cout << "Consumable Weapons :" << endl;
    	for(int i = 0 ; i < 2 ; i++)
    	{
        	cout << "(" << i + 11 << ") " << weapons[i + 10].name << " [Stamina: +" << weapons[i + 10].damage << " , Price: " << weapons[i + 10].price << "$]" << endl;
    	}
    	for(int i = 0 ; i < 2 ; i++)
    	{
        	cout << "(" << i + 13 << ") " << weapons[i + 12].name << " [HP: +" << weapons[i + 12].damage << " , Price: " << weapons[i + 12].price << "$]" << endl;
    	}
    	cout << endl;
    	cout << "(15) Nothing (You Will Leave The Shop)" << endl;
		cout << "(16) Leave The Game" << endl;
    	cout << RESET;
    }
    virtual void BuyWeapon(characters* &player , BackPack* &backpack) override
    {
        int number = 0;
        while(true)
        {
            cout << ORANGE << endl;
            if(!(number == 15 || number == 16))
            {
				cout << ORANGE << "'What Do You Want To Buy To Defeat The Zombies?'(Enter The Number)" << endl;
				cin >> number;
				cout << endl;
			}
            if(number == 15)
            {
                cout << "Leaving The Shop..." << endl;
                return;
            }
            if(number == 16) 
            {
                SavePlayer(player, backpack);
            }
            if(!(number >= 1 && number <= 16))
            {
                cout << RED << "'We Don't Have Such Weapon!'" << endl;
				cout << "Please Enter A Valind Number(1-16)" << RESET << endl;
				Beep(500 , 800);
            }
			
                while(true)
                {
                    if(number == 15 || number == 16)
                	    break;

                	cout << ORANGE;	
                    string NameOfWeapon = weapons[number - 1].name;
                    int PriceOfWeapon = weapons[number - 1].price;
                    int DamageOfWeapon = weapons[number - 1].damage;
                    if(player->Money >= PriceOfWeapon)
                    {
                        backpack->AddWeapon(NameOfWeapon , DamageOfWeapon);
                        player->Money -= PriceOfWeapon;
                        cout << NameOfWeapon << " Is Now In Your Backpack." << endl << "Your Money: " << player->Money << "$" << endl ;
                    }
                    else
                    {
                        cout << RED << "Sorry! You Don't Have Enough Money To Buy " << NameOfWeapon << "." << RESET << endl;
                    }
                    cout << ORANGE << "'Do You Want To Buy Something Else?' The Saller Says." << endl;
                    cout << "(1) No.(You Will Leave The Shop)" << endl;
                    cout << "(2) Yes" << endl;
                    while(true)
                    {
                        int num;
                        cin >> num;
                        cout << endl;
                        if(num == 1)
                        {
                            system("cls");
                            cout << "'Thanks For Your Purchase. Good Luck!'" << endl << "Leaving The Shop..." << endl;
                            return;
                        }
                        if(num == 2)
                        {
                            cout << "'What Do You Want To Buy To Defeat The Zombies?'(Enter The Number)" << endl;
                            cin >> number;	
                            cout << endl;
                            break;
                        }
                        else
                        {
                            cout << RED << "Please Enter A Valid Number(1 or 2): " << RESET << endl;
                            cout << ORANGE;
                            Beep(500 , 800);
                        }
				    }
                    cout << RESET;
                }  
	    }
    }
};
class Dumbledore : public characters
{
private:
    vector<Weapon> weapons;
    
public:
    Dumbledore(string name, int age, string gender, int level, int stamina, int hp, int money)
    :characters(name, age, gender, level, stamina, hp, money)
    {
        Type = "Dumbledore";
        weapons.push_back(Weapon("Stupefy (Throwing Somthing)" , 40 , 20));
        weapons.push_back(Weapon("SecfumSempra (To Injure)" , 20 , 20));
        weapons.push_back(Weapon("Crucio (To Torture)" , 20 , 20));
        weapons.push_back(Weapon("Incendio (Fire)" , 20 , 20));
        weapons.push_back(Weapon("Fiendfyre Curse (Dragon)" , 20 , 20));
        weapons.push_back(Weapon("Avada Kedavra (To Kill)" , 5000 , 100));
        weapons.push_back(Weapon("Redacto (Blow Up)" , 20 , 20));
        weapons.push_back(Weapon("In Caeseros (Rope)" , 20 , 20));
        weapons.push_back(Weapon("Serpensortia (Throwing Snake)" , 20 , 20));
        weapons.push_back(Weapon("Draught Og Living Death (Go To Death Mode)" , 20 , 20));
        weapons.push_back(Weapon("Felix Felicis (Increas Energy)" , 20 , 20));
        weapons.push_back(Weapon("Elixir OF Life (Increas HP)" , 20 , 20));
        weapons.push_back(Weapon("Fiantodon (Protect)" , 20 , 20));
        weapons.push_back(Weapon("Episci (Prevent Bleeding)" , 20 , 20));
    }
    double Damege(string name,int damege) override
    {
        if(name=="Stupefy (Throwing Somthing)")
        return damege*(Level/3);
        if(name=="SecfumSempra (To Injure)")
        return damege*(Level/2.5);
        if(name=="Crucio (To Torture)")
        return damege*(Level/2);
        if(name=="Incendio (Fire)")
        return damege*(Level/1.5);
        if(name=="Fiendfyre Curse (Dragon)")
        return damege*(Level);
        if(name=="Avada Kedavra (To Kill)")
        return damege; //hp(enemy)=0
        if(name=="Redacto (Blow Up)")
        return damege*(Level/3);
        if(name=="In Caeseros (Rope)")
        return damege*(Level/2.5);
        if(name=="Serpensortia (Throwing Snake)")
        return damege*(Level/2);
        if(name=="Draught Og Living Death (Go To Death Mode)")
        return damege*(Level/1.5);
    }
    double IncreaseStamina(string name,int damege) override
    {
        if(name=="Felix Felicis (Increas Energy)")
        return damege*(Level/2);
    }
    double IncreaseHp(string name,int damege) override
    {
        if(name=="Elixir OF Life (Increas HP)")
        return damege*(Level/2.5);
        if(name=="Episci (Prevent Bleeding)")
        return damege*(Level/2);
        if(name=="Fiantodon (Protect)")
        return damege*(Level/1.5);
    }

    //shop
    virtual void ShowShop(characters* &player) override
    {
        clearConsole();
    	cout << endl;
    	cout <<	BLUE << "'Hi Brave, You've Chosen The Best Shop! Here You Can Find Anything You Need.'" << endl;
        cout << "Your Money: " << player->Money << "$" << endl << endl;
    	cout << "Cold Weapons :" << endl;

        for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << "(" << i + 1 << ") " << weapons[i].name << " [Damage: -" << weapons[i].damage << " , Price: " << weapons[i].price << "$]" << endl;
    	}

    	cout << endl;
		cout << "Firearms :" << endl;
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << "(" << i + 4 << ") " << weapons[i + 3].name << " [Damage: -" << weapons[i + 3].damage << " , Price: " << weapons[i + 3].price << "$]" << endl;
    	}

    	cout << endl;
		cout << "Throwing Weapons :" << endl;
    	for(int i = 0 ; i < 4 ; i++)
    	{
        	cout << "(" << i + 7 << ") " << weapons[i + 6].name << " [Damage: -" << weapons[i + 6].damage << " , Price: " << weapons[i + 6].price << "$]" << endl;
    	}

    	cout << endl;
		cout << "Consumable Weapons :" << endl;
    	for(int i = 0 ; i < 1 ; i++)
    	{
        	cout << "(" << i + 11 << ") " << weapons[i + 10].name << " [Stamina: +" << weapons[i + 10].damage << " , Price: " << weapons[i + 10].price << "$]" << endl;
    	}
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << "(" << i + 12 << ") " << weapons[i + 11].name << " [HP: +" << weapons[i + 11].damage << " , Price: " << weapons[i + 11].price << "$]" << endl;
    	}
    	cout << endl;
    	cout << "(15) Nothing (You Will Leave The Shop)" << endl;
		cout << "(16) Leave The Game" << endl;
    	cout << RESET;
    }
    virtual void BuyWeapon(characters* &player , BackPack* &backpack) override
    {
        int number = 0;
        while(true)
        {
            cout << BLUE << endl;
            if(!(number == 15 || number == 16))
            {
				cout << BLUE << "'What Do You Want To Buy To Defeat The Zombies?'(Enter The Number)" << endl;
				cin >> number;
				cout << endl;
			}
            if(number == 15)
            {
                cout << "Leaving The Shop..." << endl;
                return;
            }
            if(number == 16) 
            {
                SavePlayer(player, backpack);
            }
            if(!(number >= 1 && number <= 16))
            {
                cout << RED << "'We Don't Have Such Weapon!'" << endl;
				cout << "Please Enter A Valind Number(1-16)" << RESET << endl;
				Beep(500 , 800);
            }
			
                while(true)
                {
                    if(number == 15 || number == 16)
                	    break;

                	cout << BLUE;	
                    string NameOfWeapon = weapons[number - 1].name;
                    int PriceOfWeapon = weapons[number - 1].price;
                    int DamageOfWeapon = weapons[number - 1].damage;
                    if(player->Money >= PriceOfWeapon)
                    {
                        backpack->AddWeapon(NameOfWeapon , DamageOfWeapon);
                        player->Money -= PriceOfWeapon;
                        cout << NameOfWeapon << " Is Now In Your Backpack." << endl << "Your Money: " << player->Money << "$" << endl ;
                    }
                    else
                    {
                        cout << RED << "Sorry! You Don't Have Enough Money To Buy " << NameOfWeapon << "." << RESET << endl;
                    }
                    cout << BLUE << "'Do You Want To Buy Something Else?' The Saller Says." << endl;
                    cout << "(1) No.(You Will Leave The Shop)" << endl;
                    cout << "(2) Yes" << endl;
                    while(true)
                    {
                        int num;
                        cin >> num;
                        cout << endl;
                        if(num == 1)
                        {
                            system("cls");
                            cout << "'Thanks For Your Purchase. Good Luck!'" << endl << "Leaving The Shop..." << endl;
                            return;
                        }
                        if(num == 2)
                        {
                            cout << "'What Do You Want To Buy To Defeat The Zombies?'(Enter The Number)" << endl;
                            cin >> number;	
                            cout << endl;
                            break;
                        }
                        else
                        {
                            cout << RED << "Please Enter A Valid Number(1 or 2): " << RESET << endl;
                            cout << BLUE;
                            Beep(500 , 800);
                        }
				    }
                    cout << RESET;
                }  
	    }
    }
};
class JonSnow : public characters
{
private:
    vector<Weapon> weapons;

public:
    JonSnow(string name, int age, string gender, int level, int stamina, int hp, int money)
    :characters(name, age, gender, level, stamina, hp, money)
    {
        Type = "JonSnow";
        weapons.push_back(Weapon("Sword" , 40 , 20));
        weapons.push_back(Weapon("Dagger" , 20 , 20));
        weapons.push_back(Weapon("Chopper" , 20 , 20));
        weapons.push_back(Weapon("Dragon" , 20 , 20));
        weapons.push_back(Weapon("Gun" , 20 , 20));
        weapons.push_back(Weapon("CataPult" , 20 , 20));
        weapons.push_back(Weapon("Shuriken" , 20 , 20));
        weapons.push_back(Weapon("FireBall" , 20 , 20));
        weapons.push_back(Weapon("SnowBall" , 20 , 20));
        weapons.push_back(Weapon("Bomb" , 20 , 20));
        weapons.push_back(Weapon("Fish" , 20 , 20));
        weapons.push_back(Weapon("Meat" , 20 , 20));
        weapons.push_back(Weapon("BluePotion" , 20 , 20));
        weapons.push_back(Weapon("RedPotion" , 20 , 20));
    }
    double Damege(string name,int damege) override
    {
        if(name=="Sword")
        return damege*(Level/2);
        if(name=="Dagger")
        return damege*(Level/2.5);
        if(name=="Chopper")
        return damege*(Level/3);
        if(name=="Dragon")
        return damege*(Level);
        if(name=="Gun")
        return damege*(Level/1.5);
        if(name=="CataPult")
        return damege*(Level/2);
        if(name=="Shuriken")
        return damege*(Level/1.5);
        if(name=="FireBall")
        return damege*(Level/2);
        if(name=="SnowBall")
        return damege*(Level/2.5);
        if(name=="Bomb")
        return damege*(Level/3);
        
    }
    double IncreaseStamina(string name,int damege) override
    {
        if(name=="BluePotion")
        return damege*(Level/2);
        if(name=="RedPotion")
        return damege*(Level/2.5);
    }
    double IncreaseHp(string name,int damege) override
    {
        if(name=="Fish")
        return damege*(Level/2);
        if(name=="Meat")
        return damege*(Level/2.5);
    }

    //shop
    virtual void ShowShop(characters* &player) override
    {
        clearConsole();
    	cout << endl;
    	cout << GRAY << "'Hi Brave, You've Chosen The Best Shop! Here You Can Find Anything You Need.'" << endl;
        cout << "Your Money: " << player->Money << "$" << endl << endl;
    	cout << "Cold Weapons :" << endl;

        for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << "(" << i + 1 << ") " << weapons[i].name << " [Damage: -" << weapons[i].damage << " , Price: " << weapons[i].price << "$]" << endl;
    	}

    	cout << endl;
		cout << "Firearms :" << endl;
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << "(" << i + 4 << ") " << weapons[i + 3].name << " [Damage: -" << weapons[i + 3].damage << " , Price: " << weapons[i + 3].price << "$]" << endl;
    	}

    	cout << endl;
		cout << "Throwing Weapons :" << endl;
    	for(int i = 0 ; i < 4 ; i++)
    	{
        	cout << "(" << i + 7 << ") " << weapons[i + 6].name << " [Damage: -" << weapons[i + 6].damage << " , Price: " << weapons[i + 6].price << "$]" << endl;
    	}

    	cout << endl;
		cout << "Consumable Weapons :" << endl;
    	for(int i = 0 ; i < 2 ; i++)
    	{
        	cout << "(" << i + 11 << ") " << weapons[i + 10].name << " [Stamina: +" << weapons[i + 10].damage << " , Price: " << weapons[i + 10].price << "$]" << endl;
    	}
    	for(int i = 0 ; i < 2 ; i++)
    	{
        	cout << "(" << i + 13 << ") " << weapons[i + 12].name << " [HP: +" << weapons[i + 12].damage << " , Price: " << weapons[i + 12].price << "$]" << endl;
    	}
    	cout << endl;
    	cout << "(15) Nothing (You Will Leave The Shop)" << endl;
		cout << "(16) Leave The Game" << endl;
		cout << RESET;
    }
    virtual void BuyWeapon(characters* &player , BackPack* &backpack) override
    {
        int number = 0;
        while(true)
        {
            cout << GRAY << endl;
            if(!(number == 15 || number == 16))
            {
				cout << GRAY << "'What Do You Want To Buy To Defeat The Zombies?'(Enter The Number)" << endl;
				cin >> number;
				cout << endl;
			}
            if(number == 15)
            {
                cout << "Leaving The Shop..." << endl;
                return;
            }
            if(number == 16) 
            {
                SavePlayer(player, backpack);
            }
            if(!(number >= 1 && number <= 16))
            {
                cout << RED << "'We Don't Have Such Weapon!'" << endl;
				cout << "Please Enter A Valind Number(1-16)" << RESET << endl;
				Beep(500 , 800);
            }
			
                while(true)
                {
                    if(number == 15 || number == 16)
                	    break;

                	cout << GRAY;	
                    string NameOfWeapon = weapons[number - 1].name;
                    int PriceOfWeapon = weapons[number - 1].price;
                    int DamageOfWeapon = weapons[number - 1].damage;
                    if(player->Money >= PriceOfWeapon)
                    {
                        backpack->AddWeapon(NameOfWeapon , DamageOfWeapon);
                        player->Money -= PriceOfWeapon;
                        cout << NameOfWeapon << " Is Now In Your Backpack." << endl << "Your Money: " << player->Money << "$" << endl ;
                    }
                    else
                    {
                        cout << RED << "Sorry! You Don't Have Enough Money To Buy " << NameOfWeapon << "." << RESET << endl;
                    }
                    cout << GRAY << "'Do You Want To Buy Something Else?' The Saller Says." << endl;
                    cout << "(1) No.(You Will Leave The Shop)" << endl;
                    cout << "(2) Yes" << endl;
                    while(true)
                    {
                        int num;
                        cin >> num;
                        cout << endl;
                        if(num == 1)
                        {
                            system("cls");
                            cout << "'Thanks For Your Purchase. Good Luck!'" << endl << "Leaving The Shop..." << endl;
                            return;
                        }
                        if(num == 2)
                        {
                            cout << "'What Do You Want To Buy To Defeat The Zombies?'(Enter The Number)" << endl;
                            cin >> number;	
                            cout << endl;
                            break;
                        }
                        else
                        {
                            cout << RED << "Please Enter A Valid Number(1 or 2): " << RESET << endl;
                            cout << GRAY;
                            Beep(500 , 800);
                        }
				    }
                    cout << RESET;
                } 
	    }
    }
};

//ENEMY CLASS
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
    Enemy(int PlayerLevel ,double E) : Level(PlayerLevel), HP(100), Stamina(50), wea(""), e(E) {} // The default constructor which initializes both HP and Stamina to 100.

public:
    double getHP() { return HP; }
    int getStamina() { return Stamina; }
    string getWeapon() { return wea; }
    void damage(double playerAttack) { HP = HP - playerAttack; }
    void levelUp() { Level+=1; }    
    double Weapon(); // randomly chooses a weapon between the three above. It is called when the enemy attacks and reduces the player's HP.
    virtual string zombieName () { return "no name"; }

};
double Enemy::Weapon() 
{
    Stamina += 3;
    int Rand = rand() % 100 + 1;
    if (Rand <= 33 && Level >= 1)
    {
        wea = "throwingStar";
        return (1 * Level * e);
    }
    else if (Rand > 33 && Rand <= 66 && Level >= 2)
    {
        wea = "kife";
        return (2 * Level * e);
    }
    else if (Rand > 66 && Level >= 5)
    {
        wea = "sword";
        return (5 * Level * e);
    }
    else
    {
        wea = "throwingStar";
        return (1 * Level * e);
    }
}

//*****//

class zombie : public Enemy
{
public:
    zombie(int PlayerLevel, double E) : Enemy(PlayerLevel, 1) {} // Initializes e from Enemy to 1
    string zombieName() override { return "Zombie"; }
};


class strongZombie : public Enemy
{
public:
    strongZombie(int PlayerLevel, double E) : Enemy(PlayerLevel, 1.2) {} // Initializes e from Enemy to 1.2
    string zombieName() override { return "Strong Zombie"; }
};

//*****//

class CharFactory{
public:
    static characters* createChar(int type, string name, int age, string gender, int level, int stamina, int hp, int money)
    {
        if(type == 1)
            return new JonSnow(name, age, gender, level, stamina, hp, money);
        if(type == 2)
            return new Dumbledore(name, age, gender, level, stamina, hp, money);
        if(type == 3)
            return new Michelangelo(name, age, gender, level, stamina, hp, money);
        else
            return nullptr;
    }

};

void clearConsole() 
{
    system("cls");
}
bool isDupName(string name)
{
    ifstream names("characters/CharNames.txt");
    string line;
    while(getline(names, line))
    {
        if(line == name)
            return false;
    }
    return true;
}
//Battlefield functions
void showCharInfo(characters* playerPtr, Enemy* enemyPtr)
{
    system("cls");
    cout << "Your Character\n_______________\n";
    cout << "Name: " << playerPtr->getName() << endl
        << "Age: " << playerPtr->getAge() << endl
        << "Gender: " << playerPtr->getGender() << endl
        << "Character type: " << playerPtr->getType() << endl
        << "Level: " << playerPtr->getLevel() << endl
        << "HP: " << playerPtr->getHP() << endl
        << "Stamina: " << playerPtr->getStamina() << endl;
    cout << endl << GRAY << "Your Enemy\n_______________\n";
    cout << "Enemy type: " << enemyPtr->zombieName() << endl
        << "HP: " << enemyPtr->getHP() << endl
        << "Stamina: " << enemyPtr->getStamina() << RESET << endl;
    cout << "\n1. Back\n";
    int goBack;
    cin >> goBack;
    while (goBack != 1)
    {
        cout << "Please enter 1 to go back.\n";
        cin >> goBack;
    }
    if (goBack == 1) 
    { 
        system("cls");
        return; 
    }
}

void Battlefield (characters* PlayerPtr, BackPack* playerBackpack)
{
    //_____________________________________//
    cout << "You've come to a dangerous place. Beware of the creatures lurking in the shadow.\n";
    cout << "There is an enemy against you!\n";
    //creating an enemy object
    srand ( time(NULL) );
    int rand_1 = rand () % 4 + 1;
    Enemy* zom;
    switch (rand_1)
    {
        case 1: 
            {
                zom = new zombie(PlayerPtr->getLevel(), 1);
                break;
            }
        case 2:
            {
                zom = new zombie(PlayerPtr->getLevel(), 1);
                break;
            }
        case 3:
            {
                zom = new zombie(PlayerPtr->getLevel(), 1);
                break;
            }
        case 4:
            {
                zom = new strongZombie(PlayerPtr->getLevel(), 1.2);
                break;
            }
    }

    int choice1(0);

    // while ( zom->getHP() > 0 && ( PlayerObj.getHP() > 0 || false ) )
    while (choice1 != 4) // Examplary condition
    {
        cout << "What would you like to do? (Attack ends your turn.)\n";
        //options_1
        cout << "1. Attack\n2. Inventory\n3. Character\n4. Exit Battlefield\n5. Exit Game\n";
        cin >> choice1;
        switch(choice1)
        {
            case 1:
            // function to show the options (choose a weapon) and attack
            break;
            case 2:
            // calling a function to show backpack
            PlayerPtr->showInventory(playerBackpack);
            break;
            case 3:
            //calling member functions to show player's name,
            // character, HP, stamina, money and enemy's name, HP and stamina
            showCharInfo(PlayerPtr, zom);
            break;
            case 4:
            //Exit battlefield
            cout << "Exiting battlefield...\n";
            return;
            break;
            case 5:
            //save player's info
            cout << "Exiting the game...\n";
            exit(0);
            break;
            default:
            cout << "Please enter a valid number (1, 2, 3, 4 or 5).\n";
            break;
        }
    }

}
void Game(characters* Player, BackPack* &backpack)
{
    srand(time(0));
    while(true)
    {
        clearConsole();
        int RandNum = rand() % 2;
        switch (RandNum)
        {
       	case 0:
            	Battlefield(Player, backpack);
            break;
        case 1:
            	cout << "You Are Entering The Shop..." << endl;
            	Player->ShowShop(Player);
            	Player->BuyWeapon(Player, backpack);
            break;
        default:
            	break;
        }
    }
}
characters* PreChar(characters* Player, CharFactory charfactorty, BackPack* backpack)
{
    system("cls");
    bool isValidName = false;
    ifstream PreChar;
    while(!isValidName) //Openning the file
    {
        cout << "Please Enter The Name You Made Your Character With: " << endl << "(1) Back" << endl;;
        string name;
        cin >> name;
        PreChar.open("characters/" + name + ".txt");
	    
        if(!(PreChar.is_open()) && name != "1")
            cout << RED << "Sorry, No Character Exists With This Name." << RESET << endl;
        if(PreChar.is_open())
            isValidName = true;
        if(name == "1")
            return nullptr;
    }

    string line;
    string WName;
    int num = 1;
    int damage = 0;
    while(getline(PreChar, line)) //Quantification
    {
        if(num == 1)
        {
            if(line == "JonSnow")
                Player = charfactorty.createChar(1, "", 0, "", 0, 0, 0, 0);
            if(line == "Dumbledore")
                Player = charfactorty.createChar(2, "", 0, "", 0, 0, 0, 0);
            if(line == "Michelangelo")
                Player = charfactorty.createChar(3, "", 0, "", 0, 0, 0, 0);
        }
        if(num == 2)
            Player->setName(line);
        if(num == 3)
            Player->setAge(stoi(line));
        if(num == 4)
            Player->setGender(line);
        if(num == 5)
            Player->setStamina(stoi(line));
        if(num == 6)
            Player->setHP(stoi(line));
        if(num == 7)
            Player->Money = stoi(line);
        if(num >= 8)
        {
            if(num % 2 == 0)//First line is the name of weapon
                WName = line;
            else//Second line is the damage of weapon
            {
                damage = stoi(line);
                backpack->AddWeapon(WName, damage);//Quantification the weapon
            }
        }
        num += 1;
    }    
    cout << "Welcome back " << Player->getName() << "!" << endl; 
    return Player;
}


void ChoosingChar()
{
    cout << "Hello There! Welcome To This Game." << endl;

    int choice1;
    int choice2;
    int age;
    string name;
    string gender;
    bool isValid = false;
    characters* player;
    BackPack* backpack = new BackPack;
    CharFactory charfactorty;

    while(!isValid)
    {
        cout << "Do You Want To: " << endl <<
        "(1) Create A New Character?" << endl 
        << "or" << endl <<
        "(2) Continue With Previous Characters?" << endl;
        cin >> choice1;
        if(choice1 == 1)//Creating new characters
        {
            system("cls");
            cout << "Enter Your Name: " << endl;
            cin >> name;
            if(!isDupName(name))//To check if a name already contains a character
            {
                cout << RED << "You Have An Unfinished Game " << name << "!" << endl << "Finish It Or Enter Another Name." << RESET << endl << endl;
                isValid = false;
            }
            else
            {
                cout << "Enter Your Age: " << endl;
                cin >> age;
                cout << "Enter Your Gender(Male/Female): " << endl;
                cin >> gender;
                system("cls");

                cout << "The End Of Time Has Come And Every Being Is In A Battle For Existence." << endl 
                << "The Greatest Heroes From Across The World Have Risen To Defend It." << endl 
                << "Which Hero Would You Choose To Join In Safeguarding Our World?" << endl
                << "(1) JonSnow" << endl << "(2) Dumbledore" << endl << "(3) Michelangelo" << endl;
                while(!isValid)
                {
                    cin >> choice2;
                    if(choice2 == 1)
                        {
                            player = charfactorty.createChar(1, name, age, gender, 0, 50, 50, 100);
                            isValid = true;
                        }
                    if(choice2 == 2)
                        {
                            player = charfactorty.createChar(2, name, age, gender, 0, 50, 50, 100);
                            isValid = true;
                        }
                    if(choice2 == 3)
                        {
                            player = charfactorty.createChar(3, name, age, gender, 0, 50, 50, 100);
                            isValid = true;
                        }
                    if(!(choice2 == 1 || choice2 == 2 || choice2 == 3))
                    {
                        cout << RED << "Please Enter A Valid Number(1,2 or 3): " << RESET << endl;
                        Beep(500 , 800);
                        isValid = false;
                    }
                }
            }
	    }
        if(choice1 == 2)//Utilizing existing characters
        {
            player = PreChar(player, charfactorty, backpack);//Chosing 
            if(player != nullptr)
                isValid = true;
        }
        if(!(choice1 == 1 || choice1 == 2))
        {
	    system("cls");
            cout << RED << "Please Enter A Valid Number(1 or 2): " << RESET << endl;
            Beep(500 , 800);
            isValid = false;
        }
        if(isValid)
            Game(player, backpack);
    }
}
void SavePlayer(characters* Player, BackPack* backpack)
{
    ofstream File("characters/" + Player->getName() + ".txt");
    ofstream Names("characters/CharNames.txt", ios::app);
    if(!(File.is_open()))
    {
        cerr << "An Issue Occurred While Saving This Character.\n";
        exit (1);
        return;
    }
    File << Player->getType() << endl
    	 << Player->getName() << endl
    	 << Player->getAge() << endl
	     << Player->getGender() << endl
         << Player->getStamina() << endl
	     << Player->getHP() << endl
         << Player->Money << endl;
        for(auto weapons : backpack->getWeapons())
            File << weapons.first << endl << weapons.second << endl;
	
    if(isDupName(Player->getName()))//To prevent outputting a name twice
        Names << Player->getName() << endl;
    exit(1);
}
//**************************************************************************************//
//*************************************************************************************//


int main()
{
    ChoosingChar();
}

