#include <string>
#include <iostream>
#include <vector>
#include<conio.h>//for sound of error
#include<windows.h>//for sound of error
#include <chrono> 
#include <thread> 
using namespace std;

//clear the console screen 
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

//for color of text
#define RESET   "\033[0m"
#define BLUE    "\033[94m"
#define RED		"\033[31m"
#define GREEN   "\033[32m"

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
    friend class Human;
private:
    string Name;
    int Age;
    string Gender;

protected:
    string Type;
    string textColor;
    int Level;
    int Stamina;
    int maxStamina;
    int HP;
    int maxHp;
    int Strength;
    int Intelligence;
    int Skill;
    vector<Weapon> weapons;

public:
    int Money;
    characters() = default;
    characters(string name, int age, string gender, int level, int stamina, int hp, int money , int strength , int intelligence , int skill)
    :Name(name), Age(age), Gender(gender), Level(level), Stamina(stamina), HP(hp), Money(money) , Strength(strength) , Intelligence(intelligence) , Skill(skill)
    {
        maxStamina = 50;
        maxHp = 100;
    }

    
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
    int getMaxHp() {return maxHp;}
    int getMaxStamina() {return maxStamina;}


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
class Dumbledore : public characters
{
public:
    Dumbledore(string name, int age, string gender, int level, int stamina, int hp, int money , int strength , int intelligence , int skill)
    :characters(name, age, gender, level, stamina, hp, money , strength , intelligence , skill)
    {
        Type = "Dumbledore";
        textColor = BLUE;
        weapons.push_back(Weapon("Stupefy (Throwing Somthing)" , 40 , 20 , 20 , "Cold", 1));//name, price, price of update, damage of weapons and the number of weapons
        weapons.push_back(Weapon("SecfumSempra (To Injure)" , 20, 20 , 20 , "Cold", 1));
        weapons.push_back(Weapon("Crucio (To Torture)" , 20, 20 , 20 , "Cold", 1));
        weapons.push_back(Weapon("Incendio (Fire)" , 20, 20 , 20 , "Firearm", 1));
        weapons.push_back(Weapon("Fiendfyre Curse (Dragon)" , 20, 20 , 20 , "Firearm", 1));
        weapons.push_back(Weapon("Avada Kedavra (To Kill)" , 5000, 20 , 100 , "Firearm", 1));
        weapons.push_back(Weapon("Redacto (Blow Up)" , 20 , 20 , 20 , "Throwing", 1));
        weapons.push_back(Weapon("In Caeseros (Rope)" , 20, 20 , 20 , "Throwing", 1));
        weapons.push_back(Weapon("Serpensortia (Throwing Snake)" , 20, 20 , 20 , "Throwing", 1));
        weapons.push_back(Weapon("Draught Og Living Death (Go To Death Mode)" , 20, 20 , 20 , "Throwing", 1));
        weapons.push_back(Weapon("Felix Felicis (Increas Energy)" , 20, 20 , 20 , "ConsumableStamina", 1));
        weapons.push_back(Weapon("Fiantodon (Protect)" , 20, 20 , 20 , "ConsumableStamina", 1));
        weapons.push_back(Weapon("Elixir OF Life (Increas HP)" , 20, 20 , 20 , "ConsumableHp", 1));
        weapons.push_back(Weapon("Episci (Prevent Bleeding)" , 20, 20 , 20 , "ConsumableHp", 1));
    }
    //double Damege(string name,int damege) override
    //{
    //    if(name=="Stupefy (Throwing Somthing)")
    //    return damege*(Level/3);
    //    if(name=="SecfumSempra (To Injure)")
    //    return damege*(Level/2.5);
    //    if(name=="Crucio (To Torture)")
    //    return damege*(Level/2);
    //    if(name=="Incendio (Fire)")
    //    return damege*(Level/1.5);
    //    if(name=="Fiendfyre Curse (Dragon)")
    //    return damege*(Level);
    //    if(name=="Avada Kedavra (To Kill)")
    //    return damege; //hp(enemy)=0
    //    if(name=="Redacto (Blow Up)")
    //    return damege*(Level/3);
    //    if(name=="In Caeseros (Rope)")
    //    return damege*(Level/2.5);
    //    if(name=="Serpensortia (Throwing Snake)")
    //    return damege*(Level/2);
    //    if(name=="Draught Og Living Death (Go To Death Mode)")
    //    return damege*(Level/1.5);
    //}
    //double IncreaseStamina(string name,int damege) override
    //{
    //    if(name=="Felix Felicis (Increas Energy)")
    //    return damege*(Level/2);
    //}
    //double IncreaseHp(string name,int damege) override
    //{
    //    if(name=="Elixir OF Life (Increas HP)")
    //    return damege*(Level/2.5);
    //    if(name=="Episci (Prevent Bleeding)")
    //    return damege*(Level/2);
    //    if(name=="Fiantodon (Protect)")
    //    return damege*(Level/1.5);
    //}
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
    Enemy(int PlayerLevel ,double E) : Level(PlayerLevel), HP(90), Stamina(40), wea(""), e(E) {} // The default constructor which initializes both HP and Stamina to 100.

    double getHP() { return HP; }
    int getStamina() { return Stamina; }
    string getWeapon() { return wea; }
    int getLevel() {return Level;}
    void damage(double playerAttack) { HP = HP - playerAttack; }
    void levelUp() { Level+=1; }    
    double weapon(characters* Player);//randomly chooses a weapon between the three above. It is called when the enemy attacks and reduces the player's HP.
    virtual string zombieName () = 0;
};

double Enemy::weapon(characters* Player) 
{
    srand(time(0));
    Stamina -= 3;
    int Rand = rand() % 100 + 1;
    if (Rand <= 33 && Level >= 1)
    {
        wea = "ThrowingStar";
        return (1 * Level * e);
    }
    else if (Rand > 33 && Rand <= 66 && Level >= 2)
    {
        wea = "Kife";
        return (2 * Level * e);
    }
    else if (Rand > 66 && Level >= 5)
    {
        wea = "Sword";
        return (5 * Level * e);
    }
    else
    {
        wea = "ThrowingStar";
        return (1 * Level * e);
    }
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
    int maxStamina;
    int maxHp;
    vector<Weapon> EnWeapons;
    EnemyState currentState;

public:
    int getStrength() {return Strength;}
    int getIntelligence() {return Intelligence;}
    vector<Weapon> getWeapons() {return EnWeapons;}


    Human(int PlayerLevel, double E, characters* Player) : Enemy(PlayerLevel, 1) 
    {
        srand(time(0));
        Strength = 0;
        Intelligence = 0;
        Skill = 5; 
        maxStamina = 50;
        maxHp = 100;
        attack = false;

        int n = rand() % 3;
        string name;
        int booster;
        string type;
        for(int i=0; i<2; i++)//choosing one cold weapon and firearm randomly
        {
            EnWeapons.push_back(Player->weapons[n]);
            n = rand() % 3 + 3;
        }

        int j=0;
        if(PlayerLevel < 6)
            j=2;
        else
            j=5;

        for(int i=0; i<j; i++)//Adding a Hp and stamina booster
        {
            n = rand() % 4 + 10;
            EnWeapons.push_back(Player->weapons[n]);
        }

    }

    string zombieName() override { return "Human"; }

    void Action(characters* Player, EnemyState currentS)//defining actions
    {
        switch(currentS)
        {
            case EnemyState::Increase_HP:
            if(!EnWeapons.empty())
            {
                for(int i=0; i<EnWeapons.size(); i++)
                {
                    if(EnWeapons[i].type == "ConsumableHp" && HP < maxHp)
                    {
                        int preHP = HP;
                        HP += EnWeapons[i].damage;
                        if(HP > maxHp)
                            HP = maxHp;
                        EnWeapons.erase(EnWeapons.begin() + i);
                        cout << GREEN << "Your Enemy Has Increased His HP By " << HP-preHP << "." << Player->getcolor() << endl;
                    }
                }
            }
            break;
            case EnemyState::Increase_Stamina:
            if(!EnWeapons.empty())
            {
                for(int i=0; i<EnWeapons.size(); i++)
                {
                    if(EnWeapons[i].type == "ConsumableStamina" && Stamina < maxStamina)
                    {
                        int preStamina = Stamina;
                        Stamina += EnWeapons[i].damage;
                        if(Stamina > maxStamina)
                            Stamina = maxStamina;
                        EnWeapons.erase(EnWeapons.begin() + i);
                        cout << GREEN << "Your Enemy Has Increased His Stamina By " << Stamina-preStamina << "." << Player->getcolor() << endl;
                    }
                }
            }
            break;
            case EnemyState::Upgrade_Inteligance:
            if(Skill != 0)
            {
                Intelligence += 1;
                EnWeapons[0].damage += 10;
                Skill -= 1;
                cout << GREEN << "Your Enemy Has Increased His Intelligence By 1 And Cold Weapon's Damage By 10."<<  Player->getcolor() << endl;
            }
            break;
            case EnemyState::Upgrade_Strength:
            if(Skill != 0)
            {
                Strength += 1;
                EnWeapons[1].damage += 10;
                Skill -= 1;
                cout << GREEN << "Your Enemy Has Increased His Strength By 1 And Firearm's Damage By 10."<<  Player->getcolor() << endl;
            }
            break;
            default://attack
            attack = true;
            int i = rand() % 2;
            Player->damage(EnWeapons[i].damage);
            cout << GREEN <<  "Enemy Is Attacking" << Player->getcolor() << endl;
            
            break;
        }
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
        return EnemyState::Attack;
    }
    void beforeAttack(characters* Player)
    {
        Stamina -= 3;
        while(!attack)
        {
            currentState = UpdateStates();
            Action(Player, currentState);
            this_thread::sleep_for(chrono::milliseconds(1500));
        }
    }
};
int main()
{
    characters* Player = new Dumbledore("yas", 18, "F", 1, 50, 50, 100, 0, 0, 0);
    Human* human = new Human(1, 1, Player);

    for(auto weapon : human->getWeapons())
        cout << weapon.name << " " << weapon.damage << " " << weapon.type << " "  << endl;

    cout << endl << "BEFORE ATTACK" << endl;
    cout << "HP: " << human->getHP() << endl;
    cout << "Stamina: " << human->getStamina() << endl;
    cout << "Intelligence: " << human->getIntelligence() << endl;
    cout << "Strength: " << human->getStrength() << endl << endl;

    human->beforeAttack(Player);

    cout << "AFTER ATTACK" << endl;
    cout << "HP: " << human->getHP() << endl;
    cout << "Stamina: " << human->getStamina() << endl;
    cout << "Intelligence: " << human->getIntelligence() << endl;
    cout << "Strength: " << human->getStrength() << endl << endl;

    for(auto weapon : human->getWeapons())
        cout << RESET << weapon.name << " " << weapon.damage << " " << weapon.type << " "  << endl;

}
