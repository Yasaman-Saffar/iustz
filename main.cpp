#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Weapon{
public:
    string name;
    int price;
    int damage;

    Weapon(string _name , int _price , int _damage) : name(_name) , price(_price) , damage(_damage){}
};
class BackPack
{
    private:
    vector<pair<string , int>> BPWeapons;//vector for  weapons
    public:
    void AddWeapon(string name , int damage)
    {
        BPWeapons.push_back(make_pair(name , damage));
    }
    void InsideTheBackpack()
    {
        cout << "Weapons In Your Backpack :" << endl;
        int i = 1;
        for(const auto& weapon : BPWeapons)
        {
            cout <<"(" << i << ") " << weapon.first << " [Damage = " << weapon.second << "]" << endl;
            i++;
        }
        cout << i + 1 << "-" << "Back To Fight!" << endl;//zadane code Back
    }
    void ChoosingWeapon()
    {
    	cout << "Witch One Do You Want To Choose?" << endl;
    	int number;
    	cin >> number;
    	//code
    	
    	
	}
    const vector<pair<string, int>>& getWeapons() 
    {
        return BPWeapons;
    }
};

class characters;
void SavePlayer(characters*, BackPack*);

class characters
{
    private:
    string Name;
    int Age;
    string Gender;

    protected:
    string Type;

    public:
    int Level;
    int Stamina;
    int HP;
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

    void ShowInfo()
    {
        cout << "Level|" << Level << "|   " << "Hp| = " << HP << "|   "<< "Stamina|" << Stamina << "|   " << "Money|" << Money << "|   " << endl;
    }
    void ShowMoney()
    {
        cout << "Your Money: " << Money << "$";
    }
    virtual void ShowShop(characters*&) = 0;
    virtual void BuyWeapon(characters*&, BackPack*&) = 0;
    //virtual void Attack() = 0;
    //func for save in file
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
        weapons.push_back(Weapon("Stupefy (Throw Somthing)" , 40 , 20));
        weapons.push_back(Weapon("SecfumSempra (To Injure)" , 20 , 20));
        weapons.push_back(Weapon("Crucio (To Torture)" , 20 , 20));
        weapons.push_back(Weapon("Incendio (Fire)" , 20 , 20));
        weapons.push_back(Weapon("Fiendfyre Curse (Dragon)" , 20 , 20));
        weapons.push_back(Weapon("Avada Kedavra (To Kill)" , 20 , 20));
        weapons.push_back(Weapon("Redacto (Blow Up)" , 20 , 20));
        weapons.push_back(Weapon("In Caeseros (Rope" , 0 , 20));
        weapons.push_back(Weapon("Serpensortia (Snake Throw)" , 20 , 20));
        weapons.push_back(Weapon("Draught Og Living Death (Go To Death Mode)" , 20 , 20));
        weapons.push_back(Weapon("Felix Felicis (Increas Energy)" , 20 , 20));
        weapons.push_back(Weapon("Elixir OF Life" , 20 , 20));
        weapons.push_back(Weapon("Fiantodon (Protect)" , 20 , 20));
        weapons.push_back(Weapon("Episci (Prevent Bleeding)" , 20 , 20));  
    }

    //shop
    virtual void ShowShop(characters* &player) override
    {
    	cout << "'Hi Brave, you choosed the best shop! Here you can find anything you need.'" << endl;
        cout << "Your Money: " << player->Money << "$" << endl << endl;
    	cout << "Cold Weapons :" << endl;

        for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << "(" << i + 1 << ") " << weapons[i].name << " [Damage: -" << weapons[i].damage << " , Price: " << weapons[i].price << "$]" << endl;
    	}

    	cout << endl << "Firearms :" << endl;
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << "(" << i + 4 << ") " << weapons[i + 3].name << " [Damage: -" << weapons[i + 3].damage << " , Price: " << weapons[i + 3].price << "$]" << endl;
    	}

    	cout << endl << "Throwing Weapons :" << endl;
    	for(int i = 0 ; i < 4 ; i++)
    	{
        	cout << "(" << i + 7 << ") " << weapons[i + 6].name << " [Damage: -" << weapons[i + 6].damage << " , Price: " << weapons[i + 6].price << "$]" << endl;
    	}

    	cout << endl << "Consumable Weapons :" << endl;
    	for(int i = 0 ; i < 1 ; i++)
    	{
        	cout << "(" << i + 11 << ") " << weapons[i + 10].name << " [Stamina: +" << weapons[i + 10].damage << " , Price: " << weapons[i + 10].price << "$]" << endl;
    	}
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << "(" << i + 12 << ") " << weapons[i + 11].name << " [HP: +" << weapons[i + 11].damage << " , Price: " << weapons[i + 11].price << "$]" << endl;
    	}
    }
    int number;
    virtual void BuyWeapon(characters* &player , BackPack* &backpack) override
    {
        while(true)
        {
            cout << endl << "'What do you want to buy to defeat zombies?'(Enter the number)" << endl
            << "(15) Nothing (You will leave the shop)" << endl << "(16) Leave the game" << endl;
            cin >> number;
            if(number == 15)
            {
                cout << "Leaving the shop..." << endl;
                return;
            }
            if(number == 16) 
            {
                SavePlayer(player, backpack);
                exit(1);
            }
            if(!(number >= 1 && number <= 16))
            {
                cout << "'We don't have such weapon!'" << endl << "Please enter a valind number(1-16)" << endl;
            }
            else
            {
                while(true)
                {
                    string NameOfWeapon = weapons[number - 1].name;
                    int PriceOfWeapon = weapons[number - 1].price;
                    int DamageOfWeapon = weapons[number - 1].damage;
                    if(player->Money >= PriceOfWeapon)
                    {
                        backpack->AddWeapon(NameOfWeapon , DamageOfWeapon);
                        player->Money -= PriceOfWeapon;
                        cout << NameOfWeapon << " is now in your backpack." << endl << "Your Money: " << player->Money << "$" << endl ;
                    }
                    else
                    {
                        cout << "Sorry! You don't have enough money to buy " << NameOfWeapon << "." << endl;
                    }
                    cout << "'Do you want to buy something else?' The saller says." << endl
                    << "1- No.(You will leave the shop)." << endl
                    << "2- Yes." << endl;
                    cin >> number;
                    if(number == 1)
                    {
                        cout << "'Thanks for your purchase. Good luck!'" << endl;
                        return;
                    }
                    if(number == 2)
                    {
                        cout << "'What do you want to buy to defeat zombies?'(Enter the number)" << endl;
                        cin >> number;
                    }
                }
            }
        }
	}
};
class CharFactory
{
    public:
    static characters* createChar(int type, string name, int age, string gender, int level, int stamina, int hp, int money)
    {
        /*if(type == 1)
            return new JonSnow(name, age, gender, level, stamina, hp, money);
        if(type == 2)
            return new Dumbeldore(name, age, gender, level, stamina, hp, money);*/
        if(type == 3)
            return new Michelangelo(name, age, gender, level, stamina, hp, money);
        else
            return nullptr;
    }

};

void Game(characters* Player, BackPack* &backpack)
{
    srand(time(0));
    while(true)
    {
        int RandNum = rand() % 2;
        switch (RandNum)
        {
        case 0:
            //cout << "There is an enemy against you.";
            break;
        case 1:
            cout << "You are entering the shop..." << endl;
            Player->ShowShop(Player);
            Player->BuyWeapon(Player, backpack);
            break;
        default:
            break;
        }
    }
}
characters* PreChar(characters* Player, CharFactory charfactorty)
{
    bool isValidName = false;
    ifstream PreChar;
    while(!isValidName) //openning the file
    {
        cout << "Please enter the name you made your character with: " << endl;
        string name;
        cin >> name;
        PreChar.open("characters/" + name + ".txt");
        if(!(PreChar.is_open()))
            cout << "Sorry, No character exists with this name." << endl;
        if(PreChar.is_open())
            isValidName = true;
    }

    string line;
    int num = 1, damage;
    BackPack* backpack = new BackPack;
    while(getline(PreChar, line)) //quantification
    {
        istringstream iss(line);
        if(num == 1)
        {
            /*if(line == "JonSnow")
                Player = charfactorty.createChar(1, "", 0, "", 0, 0, 0, 0);
            if(line == "Dumbeldore")
                Player = charfactorty.createChar(2, "", 0, "", 0, 0, 0, 0);*/
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
            Player->Stamina = stoi(line);
        if(num == 6)
            Player->HP = stoi(line);
        if(num == 7)
            Player->Money = stoi(line);
        if(num >= 8)
        {
            iss >> line >> damage;
            backpack->AddWeapon(line, damage);
        }
        num += 1;
    }   
    cout << "Welcome back " << Player->getName() << "!" << endl; 
    return Player;
}
void ChoosingChar()
{
    cout << "Hello there! Welcome to this game." << endl;

    int choice1;
    int choice2;
    int age;
    string name;
    string gender;
    bool isValid = false;
    characters* player;
    BackPack* backpack = new BackPack;
    CharFactory charfactorty;

    while(!isValid) //creating new characters
                    // or utilizing existing ones
    {
        cout << "Do you want to: " << endl <<
        "(1) Create a new character?" << endl 
        << "or" << endl <<
        "(2) Continue with previous characters?"  << endl;
        cin >> choice1;

        if(choice1 == 1)
        {
            cout << "Enter your name: " << endl;
            cin >> name;
            cout << "Enter your age: " << endl;
            cin >> age;
            cout << "Enter your gender(male/female): " << endl;
            cin >> gender;
            
            cout << "The end of time has come and every being is in a battle for existence." << endl 
            << "The greatest heroes from across the world have risen to defend it." << endl 
            << "Which hero would you choose to join in safeguarding our world?" << endl
            << "(1) JonSnow" << endl << "(2) Dumbeldore" << endl << "(3) Michelangelo" << endl;
            cin >> choice2;
            if(choice2 == 1)
               {/*player = new JonSnow(name, age, gender)*/;}
            if(choice2 == 2)
                {/*player = new Dumbeldore(name, age, gender);*/}
            if(choice2 == 3)
                player = charfactorty.createChar(3, name, age, gender, 0, 50, 50, 100);

            isValid = true;
        }
        if(choice1 == 2)
        {
            player = PreChar(player, charfactorty);
            isValid = true;
        }
        if(!(choice1 == 1 || choice1 == 2))
        {
            cout << "Please enter a valid number(1 or 2): " << endl;
            isValid = false;
        }
        if(isValid)
            Game(player, backpack);
    }
}
void SavePlayer(characters* Player, BackPack* backpack)
{
    ofstream File("characters/" + Player->getName() + ".txt");
    if(!(File.is_open()))
    {
        cerr << "An issue occurred while saving this character.";
        return;
    }
    File << Player->getType() << endl
         << Player->getName() << endl
         << Player->getAge() << endl
         << Player->getGender() << endl 
         << Player->Stamina << endl
         << Player->HP << endl
         << Player->Money << endl;
        for(auto weapons : backpack->getWeapons())
            File << weapons.first << " " << weapons.second << endl;
         
    exit(1);
}
int main()
{
    ChoosingChar();
}