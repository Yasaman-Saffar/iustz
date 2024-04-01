#include <string>
#include <iostream>
#include <vector>
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
#define PURPLE   "\033[94m"

class Weapon
{
public:
    string name;
    int price;
    int priceUp;
    int damage;
    string type;
    int numOfWeas;
    Weapon(string _name , int _price , double _priceUp , int _damage , string _type, int _numofweas) : name(_name) , price(_price) , priceUp(_priceUp) , damage(_damage) , type(_type), numOfWeas(_numofweas){}
};
class BackPack
{
private:
    vector<Weapon> BPWeapons;//vector for weapons
public:
    void AddWeapon(string name , int price , double priceUp , int damage , string type, int numOfWeas)
    {
        bool isNew = true;
        for(int i=0; i<BPWeapons.size(); i++)
        {
            if((BPWeapons[i].name) == name)
            {
                (BPWeapons[i].numOfWeas) += 1;
                isNew = false;
            }
        }
        if(isNew)
            BPWeapons.push_back(Weapon(name , price , priceUp , damage , type, numOfWeas));
    }
    void InsideTheBackpack(bool Bool)//show weapons in the backpack
    {
    	if(BPWeapons.size() == 0)//backpack is empty
        {
        	cout << "You Don't Have Any Weapons Yet!" << endl;
        	return;
		}
		cout << "Weapons In Your Backpack :" << endl;
        int i = 1;
        for(const auto& weapon : BPWeapons)
        {
            cout <<"(" << i << ") " << weapon.name;
            if(weapon.type == "ConsumableHp")//for hp increas
            	cout << " [HP Increase: -" << weapon.damage << "]" << " x" << weapon.numOfWeas << endl;
            else if(weapon.type == "ConsumableStamina")//for stamina increas
            	cout << " [Stamina Increase: -" << weapon.damage << "]" << " x" << weapon.numOfWeas << endl;
            else//for throwing and cold weapons and firearm
            	cout << " [Damage: -" << weapon.damage;
            if(Bool == true)//show of price of update for upgrade
            	cout << " ,Price Of Upgrade: " << weapon.priceUp << "$] x" << weapon.numOfWeas  << endl;
            else//don't show price of update
            	cout << "] x" << weapon.numOfWeas << endl;
            i++;
        }
	}
	int ChooseWeapon()
	{
		if(BPWeapons.size() == 0)//backpack is empty
			return 1;
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
        		cout << "Please Enter A Valid Number(1-" << BPWeapons.size() + 1 << ") :" << endl;
			}
			else if(number == BPWeapons.size() + 1)//exit function
				return 1;
			else
			{
				int YourWeapon = BPWeapons[number - 1].damage;
				return YourWeapon;//damage of weapon for attack
				break;
			}	
		}
    }
    vector<Weapon>& getWeapons()//return all of weapons in backpack
    {
        return BPWeapons;
    }
    int getWeaponCount()//return size of vector of weapon
    {
    	return BPWeapons.size();
	}
	string getWeaponType(int index)//return type of weapon
	{
		return BPWeapons[index].type;
	}
	void setWeaponDamage(int NewDamage , int index)//change damage
	{
		BPWeapons[index].damage = NewDamage;
	}
	int getWeaponDamage(int index)//return damage of weapon
	{
		return BPWeapons[index].damage;
	}
	void setWeaponPriceUp(int NewPriceUp , int index)//change price if update
	{
		BPWeapons[index].priceUp = NewPriceUp;
	}
	double getWeaponPriceUp(int index)//return price of update of weapon
	{
		return BPWeapons[index].priceUp;
	}
	
};

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
    int Strength;
    int Intelligence;
    int Skill;

public:
    vector<Weapon> weapons;
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
    int getStrength() { return Strength; }
    void setStrength(int strength) { Strength = strength; }
    int getIntelligence() {	return Intelligence; }
	void setIntelligence(int intelligence) { Intelligence = intelligence; }
	int getSkill() { return Skill; }
	void setSkill(int skill) { Skill = skill; }


    void levelUp() {Level += 1;}
    virtual double attack() { return 8; }//DEFINITION NEEDED!!!!
    void damage(double enemyWeapon) { HP = HP - enemyWeapon; }//the parameter is the member function of Enemy
    void ShowInfo()
    {
        cout << textColor << "Your Character: " << RED << "Level|" << Level << "|   " << "HP(50)|" << HP << "|   "<< "Stamina(50)|" << Stamina << "|   " << "Money|" << Money << "|   " << textColor << endl;
    }
    void ShowMoney()
    {
        cout << "Your Money: " << Money << "$" << endl;
    }
    void ShowShop(characters* &player)//shop for all characters
    {
        //clearConsole(2);
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
                //SavePlayer(player, backpack);
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
                int PriceUpOFWeapon = weapons[number - 1].priceUp;
                int DamageOfWeapon = weapons[number - 1].damage;
                string TypeOfWeapon = weapons[number - 1].type;
                if(player->Money >= PriceOfWeapon)
                {
                    backpack->AddWeapon(NameOfWeapon ,PriceOfWeapon, PriceUpOFWeapon , DamageOfWeapon ,TypeOfWeapon, 1);
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
   // virtual double Damege(string name,int damege) { return 0; }
   // virtual double IncreaseStamina(string name,int damege) { return 0; }
   // virtual double IncreaseHp(string name,int damege) { return 0; }
};
class Enemy
{
protected:
    int Level;
    double HP;
    int Stamina;
    string wea;
    double e;
public:
    Enemy(int PlayerLevel ,double E) : Level(PlayerLevel), HP(100), Stamina(50), wea(""), e(E) {} // The default constructor which initializes both HP and Stamina to 100.

    double getHP() { return HP; }
    int getStamina() { return Stamina; }
    string getWeapon() { return wea; }
    int getLevel() {return Level;}
    void damage(double playerAttack) { HP = HP - playerAttack; }
    void levelUp() { Level+=1; }    
    double Weapon(characters* Player);//randomly chooses a weapon between the three above. It is called when the enemy attacks and reduces the player's HP.
    virtual string zombieName () = 0;
};

double Enemy::Weapon(characters* Player) 
{
    Stamina += 3;
    int Rand = rand() % 6;
    wea = Player->weapons[Rand].name;

    if (Level >= 1)  
        return (1 * Level * e);
    if (Level >= 2)  
        return (2 * Level * e);
    if (Level >= 5)  
        return (5 * Level * e);
    else 
        return (1 * Level * e);
}

enum class EnemyState
{
    Increase_HP,
    Increase_Stamina,
    Upgrade_Inteligance,
    Upgrade_Strength,
    Attack
};
class Human : public Enemy
{
private:
    int Strength;
    int Intelligence;
    int Skill;
    bool attack;
    vector<tuple <string,int, string>> weapons;
    EnemyState currentState;

public:
    Human(int PlayerLevel, double E, characters* Player) : Enemy(PlayerLevel, 1) 
    {
        Strength = 0;
        Intelligence = 0;
        Skill = 0;
        bool attack = false;

        int n = rand() % 3;
        string name;
        int booster;
        string type;
        for(int i=0; i<2; i++)//choosing one cold weapon and firearm randomly
        {
            name = Player->weapons[n].name;
            booster = Player->weapons[n].damage;
            type = Player->weapons[n].type;
            weapons.push_back(make_tuple(name,booster,type));
            n = rand() % 3 + 3;
        }

        int j=0;
        if(Player->getLevel() < 4)
            j=2;
        else
            j=4; 

        for(int i=0; i<j; i++)//Adding a health and stamina booster
        {
            n = rand() % 4 + 11;
            name = Player->weapons[n].name;
            booster = Player->weapons[n].damage;
            type = Player->weapons[n].type;
            weapons.push_back(make_tuple(name,booster,type));
        }

    }

    string zombieName() override { return "Human"; }

    void Action(characters* Player)
    {
        switch(currentState)
        {
            case EnemyState::Increase_HP:
            if(!weapons.empty())
            {
                for(int i=0; i<weapons.size(); i++)
                {
                    if(get<2>(weapons[i]) == "ConsumableHp")
                    {
                        HP += get<1>(weapons[i]);
                        weapons.erase(weapons.begin() + i);
                        cout << PURPLE << "Your Enemy Has Increased His HP By " << get<1>(weapons[i]) <<  Player->getcolor() << endl;
                    }
                }
            }
            break;
            case EnemyState::Increase_Stamina:
            if(!weapons.empty())
            {
                for(int i=0; i<weapons.size(); i++)
                {
                    if(get<2>(weapons[i]) == "ConsumableStamina")
                    {
                        HP += get<1>(weapons[i]);
                        weapons.erase(weapons.begin() + i);
                        cout << PURPLE << "Your Enemy Has Increased His Stamina By " << get<1>(weapons[i]) <<  Player->getcolor() << endl;
                    }
                }
            }
            break;
            case EnemyState::Upgrade_Inteligance:
            if(Skill != 0)
            {
                Intelligence += 1;
                get<1>(weapons[1]) += 10;
                Skill -= 1;
                cout << PURPLE << "Your Enemy Has Increased His Intelligence By 1 And Firearm's Damage By 10."<<  Player->getcolor() << endl;
            }
            break;
            case EnemyState::Upgrade_Strength:
            if(Skill != 0)
            {
                Strength += 1;
                get<1>(weapons[0]) += 10;
                Skill -= 1;
                cout << PURPLE << "Your Enemy Has Increased His Strength By 1 And Firearm's Damage By 10."<<  Player->getcolor() << endl;
            }
            break;
            default://attack
            attack = true;
            int i = rand() % 2;
            Player->damage(get<1>(weapons[i]));
            break;
        }
    } 

    bool isHungry() {return rand() % 2 == 0;}
    bool isWeak() {return rand() % 2 == 0;}
    bool needsInteligance() {return rand() % 2 == 0;}
    bool needsStrength() {return rand() % 2 == 0;}
    bool attack() 
    {
        int remainder = rand() % 3; 
        return (remainder == 1 || remainder == 2 || remainder == 3);
    }

    EnemyState UpdateStates()
    {
        int random = rand() % 6;
        if(random == 0)
            return EnemyState::Attack;
        if(random == 5)
            return EnemyState::Attack;
        if(random == 1)
            return EnemyState::Increase_HP;
        if(random == 2)
            return EnemyState::Increase_Stamina;
        if(random == 3)
            return EnemyState::Upgrade_Inteligance;
        if(random == 4)
            return EnemyState::Upgrade_Strength;
    }
    void beforeAttack(characters* Player)
    {
        int n = 0;
        while(!attack)
        {
            UpdateStates();
            Action(Player);
        }
    }
};
