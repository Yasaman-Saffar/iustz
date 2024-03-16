#include<iostream>
#include<fstream>
#include<vector>
#include<tuple>
using namespace std;

class Player{
protected://property of charactar
    string Name;
    string Gender;
    int Age;

    int CalculateLevel(int Level)//calculate of level
    {
        //code
    }

public :
	int Level;
    int Stamina;
    int Hp;
    int Money;
    Player(string name , string gender , int age , int level = 0 , int hp = 100 , int stamina = 50 , int money = 50) : Name(name) , Gender(gender) , Age(age) , Level(level) , Hp(hp) , Stamina(stamina) , Money(money){} 
    virtual void information()
    {
        cout << "Name = " << Name << endl;
        cout << "Level = " << Level << endl;
        cout << "Hp = " << Hp << endl;
        cout << "Stamina = " << Stamina << endl;
        cout << "Money = " << Money << endl;
    }
    void MoneyOfChar()
    {
    	cout << "Your Money = " << Money << "$" << endl;
	}
	void ChangMoney(int number)
	{
		//code
	}
    virtual void attack() = 0;
    void SaveToFile(string nameFile)
    {
        ifstream FileChar(nameFile);
        if(!FileChar.is_open())
        {
            cerr << "Unable to open your file!" << endl;
            exit(0);
        }
        FileChar >> Name >> Gender >> Age;
    }
    void setName(string name)
	{
		Name = name;
	}
    string getName()
    {
        return Name;
    }

    void setGender(string gender)
	{
		Gender = gender;
	}
    string getGender()
    {
        return Gender;
    }
    void setAge(int age)
	{
		Age = age;
	}
    int getAge()
    {
        return Age;
    }

};
class BackPack{
private:
    vector<pair<string , int>> weapons;//vector for  weapons
public:
    void AddWeapon(string name , int damage)
    {
        weapons.push_back(make_pair(name , damage));
    }
    void InsideTheBackpack()
    {
        cout << "Weapons In Your Backpack :" << endl;
        int i = 1;
        for(const auto& weapon : weapons)
        {
            cout << i << "- " << weapon.first << "[Damage = " << weapon.second << "]" << endl;
            i++;
        }
        cout << i + 1 << "-" << "Back To Fight!" << endl;//zadane code Back
    }
    void ChoosingWeapon()
    {
    	cout << "Wich One Do You Want TO Choose?!" << endl;
    	int number;
    	cin >> number;
    	//code
    	
    	
	}

};
class Shop{
	friend class Player;
private:
    vector<tuple<string , int , int>> weapons;// name , cost , damage

public:
    Shop()
    {
        weapons.push_back(make_tuple("Sword" , 20 , 20));
        weapons.push_back(make_tuple("Dagger" , 20 , 20));
        weapons.push_back(make_tuple("Nanchiko" , 20 , 20));
        weapons.push_back(make_tuple("Colt" , 20 , 20));
        weapons.push_back(make_tuple("ShutGun" , 20 , 20));
        weapons.push_back(make_tuple("Winchester" , 20 , 20));
        weapons.push_back(make_tuple("Bomb" , 20 , 20));
        weapons.push_back(make_tuple("Smoker" , 20 , 20));
        weapons.push_back(make_tuple("Boomerang" , 20 , 20));
        weapons.push_back(make_tuple("ThrowingKnife" , 20 , 20));
        weapons.push_back(make_tuple("Pizza" , 20 , 20));
        weapons.push_back(make_tuple("FrenchFries" , 20 , 20));
        weapons.push_back(make_tuple("Coca" , 20 , 20));
        weapons.push_back(make_tuple("IceMonkey" , 20 , 20));
    }
    void ShowOfShop(Player& player)
    {
    	cout << "Wellcome To Shop Michelangelo :)" << endl;
    	cout << "Your Money = " << player.Money << endl;
    	cout << "Here You Can Find Weapons To Defeat Zombies!!" << endl;
    	cout << "Cold Weapons :" << endl;

    	for(int i = 0 ; i < 2 ; i++)
    	{
        	cout << i + 1 << "-" << get<0>(weapons[i]) << " [Price = " << get<1>(weapons[i])<< "$" << " , Damage = " << get<2>(weapons[i]) << "]" << endl;
    	}

    	cout << "Hot Weapons :" << endl;
    	for(int i = 0 ; i < 2 ; i++)
    	{
        	cout << i + 4 << "-" << get<0>(weapons[i + 3]) << " [Price = " << get<1>(weapons[i + 3])<< "$" << " , Damage = " << get<2>(weapons[i + 3]) << "]" << endl;
    	}

    	cout << "Throwable Weapons :" << endl;
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << i + 7 << "-" << get<0>(weapons[i + 6]) << " [Price = " << get<1>(weapons[i + 6])<< "$" << " , Damage = " << get<2>(weapons[i + 6]) << "]" << endl;
    	}

    	cout << "Consumable Weapons :" << endl;
    	for(int i = 0 ; i < 2 ; i++)
    	{
        	cout << i + 11 << "-" << get<0>(weapons[i + 10]) << " [Price = " << get<1>(weapons[i + 10])<< "$" << " , Hp Increas = " << get<2>(weapons[i + 10]) << "]" << endl;
    	}
    	for(int i = 0 ; i < 2 ; i++)
    	{
        	cout << i + 13 << "-" << get<0>(weapons[i + 12]) << " [Price = " << get<1>(weapons[i + 12])<< "$" << " , Stamina Increas = " << get<2>(weapons[i + 12]) << "]" << endl;
    	}
    	cout << "15-" << "Back." << endl;//tabeee backk nazadam
    }
    int number;
    bool BuyWeapon(int number , Player& player , BackPack& backpack)
    {
    	cout << "Pleas Enter Your Choose.(A Number From 1 to 15)" << endl;
    	while(true)
    	{
    		cin >> number;
    		if(!(number >= 1 && number <= 15))
    		{
    			cout << "Invalid Selection!Pleas Enter The Right Number." << endl;
    			cin >> number;
			}
    		else
    			break;
    	}
    	string NameOfWeapon = get<0>(weapons[number - 1]);
    	int PriceOfWeapon = get<1>(weapons[number - 1]);
    	int DamageOfWeapon = get<2>(weapons[number - 1]);
    	if(player.Money >= PriceOfWeapon)
    	{
    		cout << "Well done! You Could Buy " << NameOfWeapon << " :]" << endl;
    		cout << "I Hope You Can Defeat The Zombie" << endl;
    		backpack.AddWeapon(NameOfWeapon , DamageOfWeapon);
    		player.Money -= PriceOfWeapon;
    		return true;
		}
		else
		{
			cout << "Sorry! You Don't Have Enough Money To Buy The " << NameOfWeapon << " :[" << endl;
			return false;
		}
	}
};
class Michelangelo : public Player{
public:
    Michelangelo(string name , string gender , int age) : Player(name , gender , age , 0 , 100 , 100 , 50){}//base of level,hp , stamina, money
    void information() override
    {
        cout << "Information Of Michelangelo :" << endl;
        Player::information(); 
    }
    void attack() override
    {
        //code
    }

};


int main()
{
    //code
	//Player player("nn" , "malw" , 23 , 0 , 0 , 0);
	Shop shop;
	Shop.ShowOfShop();
    return 0;
}