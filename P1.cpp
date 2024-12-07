#include <iostream>
#include <fstream>
#include <ctime>
#include<tuple>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <chrono> 
#include <thread> 
#include<conio.h>//for sound of error
#include<windows.h>//for sound of error
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
    string type;

    Weapon(string _name , int _price , int _damage , string _type) : name(_name) , price(_price) , damage(_damage) , type(_type){}
};
class BackPack{
private:
    vector<tuple<string , string , int>> BPWeapons;//vector for weapons
public:
    void AddWeapon(string type , string name , int damage)
    {
        BPWeapons.push_back(make_tuple(type , name , damage));
    }
    void InsideTheBackpack()//show of weapons in the backpack
    {
    	if(BPWeapons.size() == 0)
        {
        	cout << "You Don't Have Any Weapons Yet!" << endl;
        	return;
		}
        cout << "Weapons In Your Backpack :" << endl;
        int i = 1;
        for(const auto& weapon : BPWeapons)
        {
            cout <<"(" << i << ") " << get<1>(weapon) << " [Damage = " << get<2>(weapon) << "]" << endl;
            i++;
        }
	}
	void ChooseWeapon()
	{
		if(BPWeapons.size() == 0)
			return;
		cout << "(" << BPWeapons.size() + 1 << ")" << " Back" << endl;
		cout << endl;
        cout << "Whitch One Do You Want To Choose?" << endl;
        int number;
        cin >> number;
        cout << endl;
        while(true)
        {
        	if(number < 1 && number > BPWeapons.size() + 1)
        	{
        		cout << RED << "Please Enter A Valid Number(1-" << BPWeapons.size() + 1 << ") :" << endl;
				Beep(500 , 800); //error
			}
			else if(number == BPWeapons.size() + 1)
				return;
			else
			{
				int YourWeapon = get<2>(BPWeapons[number - 1]);//weapon of character for attack
				break;
			}
				
		}
    }
    vector<tuple<string , string, int>>& getWeapons() 
    {
        return BPWeapons;
    }
    int getWeaponCount()//return size of vector of weapons
    {
    	return BPWeapons.size();
	}
	string getWeaponType(int index)//return type of weapons
	{
		return get<0>(BPWeapons[index]);
	}
	void setWeaponDamage(int NewDamage , int index)
	{
		get<2>(BPWeapons[index]) = NewDamage;
	}
	int getWeaponDamage(int index)
	{
		return get<2>(BPWeapons[index]);
	}
};
class characters;

void SavePlayer(characters*, BackPack*);
void ChoosingChar();
void clearConsole(double);

class characters
{
private:
    string Name;
    int Age;
    string Gender;

protected:
    string Type;
    int Level;
    int Stamina;
    int HP;
    string textColor;
    vector<Weapon> weapons;
    int Strength;
    int Intelligence;
    int Skill;

public:
    int Money;
    characters() = default;
    characters(string name, int age, string gender, int level, int stamina, int hp, int money , int strength , int intelligence , int skill)
    :Name(name), Age(age), Gender(gender), Level(level), Stamina(stamina), HP(hp), Money(money) , Strength(strength) , Intelligence(intelligence) , Skill(skill){}

    string getName() {return Name;}
    void setName(string name) {Name = name;}
    int getAge() {return Age;}
    void setAge(int age) {Age = age;}
    string getGender() {return Gender;}
    void setGender(string gender) {Gender = gender;}
    string getType() {return Type;}
    int getLevel() { return Level; }
    void setLevel(int level) {Level = level;}
    double getHP() { return HP; }
    void setHP(double hp1) { HP = hp1; }
    int getStamina() { return Stamina; }
    void setStamina(int stam1) { Stamina = stam1; }
    string getcolor() {return textColor;}
    void setStrength(int strength)
    {
    	Strength = strength;
	}
	int getStrength()
	{
		return Strength;
	}
	void setIntelligence(int intelligence)
    {
    	Intelligence = intelligence;
	}
	int getIntelligence()
	{
		return Intelligence;
	}
	void setSkill(int skill)
    {
    	Skill = skill;
	}
	int getSkill()
	{
		return Skill;
	}
    void levelUp() {Level += 1;}
    virtual double attack() { return 8; } //DEFINITION NEEDED!!!!
    void damage(double enemyWeapon) { HP = HP - enemyWeapon; } // the parameter is the member function of Enemy

    void ShowInfo()
    {
        cout << textColor << "Your Character: " << RED << "Level|" << Level << "|   " << "HP(50)|" << HP << "|   "<< "Stamina(50)|" << Stamina << "|   " << "Money|" << Money << "|   " << textColor << endl;
    }
    void ShowMoney()
    {
        cout << "Your Money: " << Money << "$";
    }
    void ShowShop(characters* &player)
    {
        clearConsole(2);
    	cout << endl;
    	cout << textColor << "'Hi Brave, You Chose The Best Shop! Here You Can Find Anything You Need.'" << endl;
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
    	cout << player->getcolor();
    }
    void BuyWeapon(characters* &player , BackPack* &backpack)
    {
        int number = 0;
        while(true)
        {
            cout << textColor << endl;
            if(!(number == 15 || number == 16))
            {
				cout << textColor << "'What Do You Want To Buy To Defeat The Zombies?'(Enter The Number)" << endl;
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
				cout << "Please Enter A Valind Number(1-16)" << textColor << endl;
				Beep(500 , 800);
            }
			
                while(true)
                {
                    if(number == 15 || number == 16)
                	    break;

                	cout << textColor;	
                    string NameOfWeapon = weapons[number - 1].name;
                    int PriceOfWeapon = weapons[number - 1].price;
                    int DamageOfWeapon = weapons[number - 1].damage;
                    string TypeOfWeapon = weapons[number - 1].type;
                    if(player->Money >= PriceOfWeapon)
                    {
                        backpack->AddWeapon(TypeOfWeapon , NameOfWeapon , DamageOfWeapon);
                        player->Money -= PriceOfWeapon;
                        cout << NameOfWeapon << " Is Now In Your Backpack." << endl << "Your Money: " << player->Money << "$" << endl ;
                    }
                    else
                    {
                        cout << RED << "Sorry! You Don't Have Enough Money To Buy " << NameOfWeapon << "." << textColor << endl;
                    }
                    cout << textColor << "'Do You Want To Buy Something Else?' The Saller Says." << endl;
                    cout << "(1) No.(You Will Leave The Shop)" << endl;
                    cout << "(2) Yes" << endl;
                    while(true)
                    {
                        int num;
                        cin >> num;
                        cout << endl;
                        if(num == 1)
                        {
                            system(CLEAR);
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
                            cout << RED << "Please Enter A Valid Number(1 or 2): " << textColor << endl;
                            Beep(500 , 800);
                        }
				    }
                    cout << textColor;
                }  
	    }
    }
};
class Michelangelo : public characters
{
public:
    Michelangelo(string name, int age, string gender, int level, int stamina, int hp, int money , int strength , int intelligence , int skill)
    :characters(name, age, gender, level, stamina, hp, money , strength , intelligence , skill)
    {
        Type = "Michelangelo";
        textColor = ORANGE;
        weapons.push_back(Weapon("Sword" , 40 , 20 , "Cold"));
        weapons.push_back(Weapon("Dagger" , 20 , 20 , "Cold"));
        weapons.push_back(Weapon("Nanchiko" , 20 , 20 , "Cold"));
        weapons.push_back(Weapon("Colt" , 20 , 20 , "Firearm"));
        weapons.push_back(Weapon("ShutGun" , 20 , 20 , "Firearm"));
        weapons.push_back(Weapon("Winchester" , 20 , 20 , "Firearm"));
        weapons.push_back(Weapon("Bomb" , 20 , 20 , "Throwing"));
        weapons.push_back(Weapon("Smoker" , 20 , 20 , "Throwing"));
        weapons.push_back(Weapon("Boomerang" , 20 , 20 , "Throwing"));
        weapons.push_back(Weapon("ThrowingKnife" , 20 , 20 , "Throwing"));
        weapons.push_back(Weapon("Pizza" , 20 , 20 , "Consumable"));
        weapons.push_back(Weapon("FrenchFries" , 20 , 20 , "Consumable"));
        weapons.push_back(Weapon("Coca" , 20 , 20 , "Consumable"));
        weapons.push_back(Weapon("IceMonkey" , 20 , 20 , "Consumable")); 
    }

};
class Dumbledore : public characters
{
public:
    Dumbledore(string name, int age, string gender, int level, int stamina, int hp, int money , int strength , int intelligence , int skill)
    :characters(name, age, gender, level, stamina, hp, money , strength , intelligence , skill)
    {
        Type = "Dumbledore";
        textColor = BLUE;
        weapons.push_back(Weapon("Stupefy (Throwing Somthing)" , 40 , 20 , "Cold"));
        weapons.push_back(Weapon("SecfumSempra (To Injure)" , 20 , 20 , "Cold"));
        weapons.push_back(Weapon("Crucio (To Torture)" , 20 , 20 , "Cold"));
        weapons.push_back(Weapon("Incendio (Fire)" , 20 , 20 , "Firearm"));
        weapons.push_back(Weapon("Fiendfyre Curse (Dragon)" , 20 , 20 , "Firearm"));
        weapons.push_back(Weapon("Avada Kedavra (To Kill)" , 5000 , 100 , "Firearm"));
        weapons.push_back(Weapon("Redacto (Blow Up)" , 20 , 20 , "Throwing"));
        weapons.push_back(Weapon("In Caeseros (Rope)" , 20 , 20 , "Throwing"));
        weapons.push_back(Weapon("Serpensortia (Throwing Snake)" , 20 , 20 , "Throwing"));
        weapons.push_back(Weapon("Draught Og Living Death (Go To Death Mode)" , 20 , 20 , "Throwing"));
        weapons.push_back(Weapon("Felix Felicis (Increas Energy)" , 20 , 20 , "Consumable"));
        weapons.push_back(Weapon("Fiantodon (Protect)" , 20 , 20 , "Consumable"));
        weapons.push_back(Weapon("Elixir OF Life (Increas HP)" , 20 , 20 , "Consumable"));
        weapons.push_back(Weapon("Episci (Prevent Bleeding)" , 20 , 20 , "Consumable"));
        
    }
};
class JonSnow : public characters
{
public:
    JonSnow(string name, int age, string gender, int level, int stamina, int hp, int money , int strength , int intelligence , int skill)
    :characters(name, age, gender, level, stamina, hp, money , strength , intelligence , skill)
    {
        Type = "JonSnow";
        textColor = GRAY;
        weapons.push_back(Weapon("Sword" , 40 , 20 , "Cold"));
        weapons.push_back(Weapon("Dagger" , 20 , 20 , "Cold"));
        weapons.push_back(Weapon("Chopper" , 20 , 20 , "Cold"));
        weapons.push_back(Weapon("Dragon" , 20 , 20 , "Firearm"));
        weapons.push_back(Weapon("Gun" , 20 , 20 , "Firearm"));
        weapons.push_back(Weapon("CataPult" , 20 , 20 , "Firearm"));
        weapons.push_back(Weapon("Shuriken" , 20 , 20 , "Throwing"));
        weapons.push_back(Weapon("FireBall" , 0 , 20 , "Throwing"));
        weapons.push_back(Weapon("SnowBall" , 20 , 20 , "Throwing"));
        weapons.push_back(Weapon("Bomb" , 20 , 20 , "Throwing"));
        weapons.push_back(Weapon("Fish" , 20 , 20 , "Consumable"));
        weapons.push_back(Weapon("Meat" , 20 , 20 , "Consumable"));
        weapons.push_back(Weapon("BluePotion" , 20 , 20 , "Consumable"));
        weapons.push_back(Weapon("RedPotion" , 20 , 20 , "Consumable"));
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
    void levelUp() { Level+=1;}    
    double Weapon(); // randomly chooses a weapon between the three above. It is called when the enemy attacks and reduces the player's HP.

};
double Enemy::Weapon() 
{
    Stamina -= 3;
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
};


class strongZombie : public Enemy
{
    strongZombie(int PlayerLevel, double E) : Enemy(PlayerLevel, 1.2) {} // Initializes e from Enemy to 1.2
};

//*****//

class CharFactory{
public:
    static characters* createChar(int type, string name, int age, string gender, int level, int stamina, int hp, int money , int strength , int intelligence , int skill)
    {
        if(type == 1)
            return new JonSnow(name, age, gender, level, stamina, hp, money , strength , intelligence , skill);
        if(type == 2)
            return new Dumbledore(name, age, gender, level, stamina, hp, money , strength , intelligence , skill);
        if(type == 3)
            return new Michelangelo(name, age, gender, level, stamina, hp, money , strength , intelligence , skill);
        else
            return nullptr;
    }

};

void clearConsole(double seconds) 
{
    this_thread::sleep_for(chrono::duration<double>(seconds));
    system(CLEAR);
}
bool isDupName(string name)
{
    ifstream names("characters/CharNames.txt");
    string line;
    while(getline(names, line))
    {
        if(line == name)
	{
	    names.close();
            return false;
	}
    }
    names.close();
    return true;
}
void Turn(characters* Player, BackPack* &backpack);
void Game(characters* Player, BackPack* &backpack)
{
    srand(time(0));
    while(true)
    {
        clearConsole(2);
        int RandNum = rand() % 2;
        switch (RandNum)
        {
       	case 0:
            	cout << "There is an enemy against you." << endl;
            	cout << endl;
            	Turn(Player, backpack);
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
    string type;
    int num = 1;
    int damage = 0;
    while(getline(PreChar, line)) //Quantification
    {
        if(num == 1)
        {
            if(line == "JonSnow")
                Player = charfactorty.createChar(1, "", 0, "", 0, 0, 0, 0 , 0 , 0 ,0);
            if(line == "Dumbledore")
                Player = charfactorty.createChar(2, "", 0, "", 0, 0, 0, 0 , 0 , 0 ,0);
            if(line == "Michelangelo")
                Player = charfactorty.createChar(3, "", 0, "", 0, 0, 0, 0 , 0 , 0 , 0);
        }
        if(num == 2)
            Player->setName(line);
        if(num == 3)
            Player->setAge(stoi(line));
        if(num == 4)
            Player->setGender(line);
        if(num == 5)
            Player->setLevel(stoi(line));
        if(num == 6)
            Player->setStamina(stoi(line));
        if(num == 7)
            Player->setHP(stoi(line));
        if(num == 8)
            Player->Money = stoi(line);
        if(num == 9)
        	Player->setStrength(stoi(line));
        if(num == 10)
        	Player->setIntelligence(stoi(line));
        if(num == 11)
        	Player->setSkill(stoi(line));
        if(num >= 12)
        {
            if(num % 2 == 1)//First line is the name of weapon
                WName = line;
            else//Second line is the damage of weapon
            {
                damage = stoi(line);
                backpack->AddWeapon(type , WName, damage);//Quantification the weapon
            }
        }
        num += 1;
    }    
    cout << "Welcome back " << Player->getName() << "!" << endl; 
    PreChar.close();
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
                << "(1) JonSnow" << endl << "(2) Dumbeldore" << endl << "(3) Michelangelo" << endl;
                while(!isValid)
                {
                    cin >> choice2;
                    if(choice2 == 1)
                        {
                            player = charfactorty.createChar(1, name, age, gender, 0, 50, 50, 100 , 0, 0, 0);
                            isValid = true;
                        }
                    if(choice2 == 2)
                        {
                            player = charfactorty.createChar(2, name, age, gender, 0, 50, 50, 100 , 0, 0, 0);
                            isValid = true;
                        }
                    if(choice2 == 3)
                        {
                            player = charfactorty.createChar(3, name, age, gender, 0, 50, 50, 100, 0, 0, 0);
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
	exit(1);
        return;
    }
    File << Player->getType() << endl;
    File << Player->getName() << endl;
    File << Player->getAge() << endl;
	File << Player->getGender() << endl;
    File << Player->getLevel() << endl;
    File << Player->getStamina() << endl;
	File << Player->getHP() << endl;
    File << Player->Money << endl;
    File << Player->getStrength() << endl;
    File << Player->getIntelligence() << endl;
    File << Player->getSkill() << endl;
        for(auto weapons : backpack->getWeapons())
            File << get<1>(weapons) << endl << get<2>(weapons) << endl;
	
    if(isDupName(Player->getName()))//To prevent outputting a name twice
        Names << Player->getName() << endl;
    File.close();
    Names.close();
    exit(1);
}
void Upgrade(characters* Player , BackPack* &backpack)
{
	system("cls");
	cout << "Your Character:" << endl;
	cout << " .Name: " << Player->getName() << endl;
	cout << " .Type:" << Player->getType() << endl;
	cout << " .Level:" << Player->getLevel() << endl;
	cout << " .Strength:" << Player->getStrength() << endl;
	cout << " .Inteligence:" << Player->getIntelligence() << endl;
	cout << endl;
	int number;
	while(true)
	{
		cout << "What Do You Want To Upgrade?(Skill Points:" << Player->getSkill() << ")" << endl;
		cout << "[1] Strength(Improving Firearm Proficiency)" << endl;
		cout << "[2] Intelligance(Improving Cold Weapon Proficiency)" << endl;
		cout << "[3] Back" << endl;
		cin >> number;
		cout << endl;
		int skill = Player->getSkill();
		int CountOfWeapons = backpack->getWeaponCount();
		if(number == 1)
		{
			if(skill >= 1)
			{
				if(CountOfWeapons > 0)
				{
					int temp = 0;
					for(int i = 0 ; i < CountOfWeapons ; i++)
					{
						if(backpack->getWeaponType(i) == "Firearm")
						{
							int WeaponDamage = backpack->getWeaponDamage(i);
							WeaponDamage += 10;
							backpack->setWeaponDamage(WeaponDamage , i);
							temp++;
						}
					}
					if(temp != 0)
					{
						skill -= 1;
						Player->setSkill(skill);
						cout << "Your Firearms Have Successfully Upgrade By 10." << endl;
						cout << endl;
						return;
					}
					else
					{
						cout << "Your Weapons Are Cold Weapons.Pleas Select The Intelligence Option." << endl;	
						cout << endl;
						break;	
					}
				}
				else
				{
					cout << "You Don't Have Any Weapons In Your BackPack." << endl;
					cout << endl;
					break;
				}
			}
			else
			{
				cout << RED << "Sorry!You Don't Have Enough Skill Points." << RESET << endl;
				cout << endl;
				break;
			}
		}
		else if(number == 2)
		{
			if(skill >= 1)
			{
				if(CountOfWeapons > 0)
				{
					int temp = 0;
					for(int i = 0 ; i < CountOfWeapons ; i++)
					{
						if(backpack->getWeaponType(i) == "Cold")
						{
							int WeaponDamage = backpack->getWeaponDamage(i);
							WeaponDamage += 10;
							backpack->setWeaponDamage(WeaponDamage , i);
							temp++;
						}
					}
					if(temp != 0)
					{
						skill -= 1;
						Player->setSkill(skill);
						cout << "Your Cold Weapons Have Successfully Upgrade By 10." << endl;
						cout << endl;
						return;
					}
					else
					{
						cout << "Your Weapons Are Firearm.Pleas Select The Strength Option" << endl;
						cout << endl;	
						break;
					}
				}
				else
				{
					cout << "You Don't Have Any Weapons In Your BackPack." << endl;
					cout << endl;
					break;
				}
			}
			else
			{
				cout << RED << "Sorry!You Don't Have Enough Skill Points." << RESET << endl;
				cout << endl;
				break;
			}
		}
		else if(number == 3)
		{
			return;
		}
		else 
		{
			cout << RED << "Please Enter A Valid Number(1-3): " << RESET << endl;
        	Beep(500 , 800);
		}
	}
	
}
void Turn(characters* Player, BackPack* &backpack)
{
	int number;
	system("cls");
    while(true)
    {
    	cout << "What Do You Want To Do?(Attack Ends Your Turn.)" << endl;
    	cout << "[1] Attack" << endl;
    	cout << "[2] BackPack" << endl;
    	cout << "[3] Character" << endl;
    	cout << "[4] End Turn" << endl; 
    	cin >> number;
    	cout << endl;
		if(number == 1)
		{
			//attack();
			return;
		}
		else if(number == 2)
		{
			system("cls");
			backpack-> InsideTheBackpack();
			backpack-> ChooseWeapon();
			cout << endl;
		}
		else if(number == 3)
		{
			system("cls");
			Upgrade(Player , backpack);
		}
		else if(number == 4)
		{
			//turn of enemy
			return;
		}
		else
		{
    		cout << RED << "Please Enter A Valid Number(1-4): " << RESET << endl;
        	Beep(500 , 800);
		}
	}
}
int main()
{
    ChoosingChar();
    
}