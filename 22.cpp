#include<iostream>
#include<fstream>
#include<vector>
#include<tuple>
using namespace std;

class Weapon{
public:
    string name;
    int price;
    int damage;

    Weapon(string _name , int _price , int _damage) : name(_name) , price(_price) , damage(_damage){}
};
class ShopOfM;
class BackPack;
class ShopOfJ;
class ShopOfD;
class Player{
protected://property of charactar
    string Name;
    string Gender;
    int Age;
    /*int CalculateLevel(int Level)//calculate of level
    {
        //code
    }*/

public :
	int Level;
    int Stamina;
    int Hp;
    int Money;
    friend void ShowMenue(Player &player , ShopOfM &shopm , ShopOfJ &shopj , ShopOfD &shopd , BackPack& backpack);
    Player(string name , string gender , int age , int level , int hp , int stamina , int money) : Name(name) , Gender(gender) , Age(age) , Level(level) , Hp(hp) , Stamina(stamina) , Money(money){} 
    virtual void information()
    {
        cout << "Name = " << Name << endl;
        cout << "Level = " << Level << endl;
        cout << "Hp = " << Hp << endl;
        cout << "Stamina = " << Stamina << endl;
        cout << "Money = " << Money << endl;
    }
	/*void ChangMoney(int number)
	{
		//code
	}
    virtual void attack() = 0;
    void SaveToFile()//if EXIT choosed and player is not lost save it
    {
        ofstream FileChar("UserInfo");
        FileChar << Name << endl
        << Gender << endl
        << Age << endl
        << Level << endl;
    }*/
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

class Michelangelo : public Player{
public:
    Michelangelo(string name , string gender , int age , int level , int hp , int stamina , int money) : Player(name , gender , age , level , hp , stamina , money){}
    void information() override
    {
        cout << "Information Of Michelangelo :" << endl;
        Player::information(); 
    }
    /*void attack() override
    {
        //code
    }*/

};

class JonSnow : public Player{
public:
 	JonSnow(string name , string gender , int age , int level , int hp , int stamina , int money) : Player(name , gender , age , level , hp , stamina , money){}
    void information() override
    {
        cout << "Information Of JonSnow :" << endl;
        Player::information(); 
    }
    /*void attack() override
    {
        //code
    }*/

};

class Dumbledore : public Player{
public:
	Dumbledore(string name , string gender , int age , int level , int hp , int stamina , int money) : Player(name , gender , age , level , hp , stamina , money){}
    void information() override
    {
        cout << "Information Of Dumbledore :" << endl;
        Player::information(); 
    }
    /*void attack() override
    {
        //code
    }*/
};
class BackPack{
private:
    vector<pair<string , int>> weapons;//vector for  weapons
public:
	friend void ShowMenue(Player &player , ShopOfM &shopm , ShopOfJ &shopj , ShopOfD &shopd , BackPack& backpack);
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
            cout << i << "- " << weapon.first << " [Damage = " << weapon.second << "]" << endl;
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

};
class ShopOfD{
	friend class Player;
private:
    vector<Weapon> weapons;

public:
	friend void ShowMenue(Player &player , ShopOfM &shopm , ShopOfJ &shopj , ShopOfD &shopd , BackPack& backpack);
    ShopOfD()
    {
        weapons.push_back(Weapon("Stupefy : Throw Somthing" , 40 , 20));
        weapons.push_back(Weapon("SecfumSempra : To Injure" , 20 , 20));
        weapons.push_back(Weapon("Crucio : To Torture" , 20 , 20));
        weapons.push_back(Weapon("Incendio : Fire" , 20 , 20));
        weapons.push_back(Weapon("Fiendfyre Curse : Dragon" , 20 , 20));
        weapons.push_back(Weapon("Avada Kedavra : To Kill" , 20 , 20));
        weapons.push_back(Weapon("Redacto : Blow Up" , 20 , 20));
        weapons.push_back(Weapon("In Caeseros : Rope" , 0 , 20));
        weapons.push_back(Weapon("Serpensortia : Snake Throw" , 20 , 20));
        weapons.push_back(Weapon("Draught Og Living Death : Go To Death Mode" , 20 , 20));
        weapons.push_back(Weapon("Felix Felicis : Increas Energy" , 20 , 20));
        weapons.push_back(Weapon("Elixir OF Life : Increas HP" , 20 , 20));
        weapons.push_back(Weapon("Fiantodon : Protect" , 20 , 20));
        weapons.push_back(Weapon("Episci : Prevent Bleeding" , 20 , 20));
    }
    void ShowOfShop(Player& player)
    {
    	cout << "Wellcome To Shop " << player.getName() << " :]"<< endl;
    	cout << "Here You Can Find Weapons To Fight Zombies!" << endl;
    	cout << "Your Money = " << player.Money << "$" << endl;
    	cout << "Cold Weapons :" << endl;
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << i + 1 << "-" << weapons[i].name << " [Price = " << weapons[i].price<< "$" << " , Damage = " << weapons[i].damage << "]" << endl;
    	}

    	cout << "Firearms :" << endl;
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << i + 4 << "-" << weapons[i + 3].name << " [Price = " << weapons[i + 3].price<< "$" << " , Damage = " << weapons[i + 3].damage << "]" << endl;
    	}

    	cout << "Throwing Weapons :" << endl;
    	for(int i = 0 ; i < 4 ; i++)
    	{
        	cout << i + 7 << "-" << weapons[i + 6].name << " [Price = " << weapons[i + 6].price<< "$" << " , Damage = " << weapons[i + 6].damage << "]" << endl;
    	}

    	cout << "Consumable Weapons :" << endl;
    	for(int i = 0 ; i < 1 ; i++)
    	{
        	cout << i + 11 << "-" << weapons[i + 10].name << " [Price = " << weapons[i + 10].price << "$" << " , Stamina Increase = " << weapons[i + 10].damage << "]" << endl;
    	}
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << i + 12 << "-" << weapons[i + 11].name << " [Price = " << weapons[i + 11].price<< "$" << " , HP Increase = " << weapons[i + 11].damage << "]" << endl;
    	}
    	cout << "15-" << "Back." << endl;//tabeee backk nazadam
    }
    bool BuyWeapon(Player& player , BackPack& backpack)
    {
    	while(true)
    	{
    		cout << "Please Enter Your Choice." << endl;
    		int number;
    		cin >> number;
    		while(true)
    		{
    			if(!(number >= 1 && number <= 15))
    				cout << "Invalid Choice! Please Enter A Valid Number.(1-15)" << endl;

    			else
    				break;
    		}
    		string NameOfWeapon = weapons[number - 1].name;
    		int PriceOfWeapon = weapons[number - 1].price;
    		int DamageOfWeapon = weapons[number - 1].damage;
    		if(player.Money >= PriceOfWeapon)
    		{
            	backpack.AddWeapon(NameOfWeapon , DamageOfWeapon);
    			player.Money -= PriceOfWeapon;
    			cout << NameOfWeapon << " Is Now In Your Backpack." << endl << "Your Money: " << player.Money << "$" << endl ;
    			break;
			}
			cout << "Sorry! You Don't Have Enough Money To Buy " << NameOfWeapon << "." << endl;
			cout << "Do You Want To Buy Something Else?" << endl;
			cout << "1- No.Leaving The Shop." << endl;
			cout << "2- Yes." << endl;
			int num;
			cin >> num;
			if(num == 1)
				break;
		}
		return true;
	}
};
class ShopOfJ{
	friend class Player;
private:
    vector<Weapon> weapons;

public:
	friend void ShowMenue(Player &player , ShopOfM &shopm , ShopOfJ &shopj , ShopOfD &shopd , BackPack& backpack);
    ShopOfJ()
    {
        weapons.push_back(Weapon("Sword" , 40 , 20));
        weapons.push_back(Weapon("Dagger" , 20 , 20));
        weapons.push_back(Weapon("Chopper" , 20 , 20));
        weapons.push_back(Weapon("Dragon" , 20 , 20));
        weapons.push_back(Weapon("Gun" , 20 , 20));
        weapons.push_back(Weapon("CataPult" , 20 , 20));
        weapons.push_back(Weapon("Shuriken" , 20 , 20));
        weapons.push_back(Weapon("FireBall" , 0 , 20));
        weapons.push_back(Weapon("SnowBall" , 20 , 20));
        weapons.push_back(Weapon("Bomb" , 20 , 20));
        weapons.push_back(Weapon("Fish" , 20 , 20));
        weapons.push_back(Weapon("Meat" , 20 , 20));
        weapons.push_back(Weapon("BluePotion" , 20 , 20));
        weapons.push_back(Weapon("RedPotion" , 20 , 20));
    }
    void ShowOfShop(Player& player)
    {
    	cout << "Wellcome To Shop " << player.getName() << " :]"<< endl;
    	cout << "Here You Can Find Weapons To Fight Zombies!" << endl;
    	cout << "Your Money = " << player.Money << "$" << endl;
    	cout << "Cold Weapons :" << endl;
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << i + 1 << "-" << weapons[i].name << " [Price = " << weapons[i].price<< "$" << " , Damage = " << weapons[i].damage << "]" << endl;
    	}

    	cout << "Firearms :" << endl;
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << i + 4 << "-" << weapons[i + 3].name << " [Price = " << weapons[i + 3].price<< "$" << " , Damage = " << weapons[i + 3].damage << "]" << endl;
    	}

    	cout << "Throwing Weapons :" << endl;
    	for(int i = 0 ; i < 4 ; i++)
    	{
        	cout << i + 7 << "-" << weapons[i + 6].name << " [Price = " << weapons[i + 6].price<< "$" << " , Damage = " << weapons[i + 6].damage << "]" << endl;
    	}

    	cout << "Consumable Weapons :" << endl;
    	for(int i = 0 ; i < 2 ; i++)
    	{
        	cout << i + 11 << "-" << weapons[i + 10].name << " [Price = " << weapons[i + 10].price << "$" << " , Hp increase = " << weapons[i + 10].damage << "]" << endl;
    	}
    	for(int i = 0 ; i < 2 ; i++)
    	{
        	cout << i + 13 << "-" << weapons[i + 12].name << " [Price = " << weapons[i + 12].price<< "$" << " , Stamina increase = " << weapons[i + 12].damage << "]" << endl;
    	}
    	cout << "15-" << "Back." << endl;//tabeee backk nazadam
    }
    bool BuyWeapon(Player& player , BackPack& backpack)
    {
    	while(true)
    	{
    		cout << "Please Enter Your Choice." << endl;
    		int number;
    		cin >> number;
    		while(true)
    		{
    			if(!(number >= 1 && number <= 15))
    				cout << "Invalid Choice! Please Enter A Valid Number.(1-15)" << endl;

    			else
    				break;
    		}
    		string NameOfWeapon = weapons[number - 1].name;
    		int PriceOfWeapon = weapons[number - 1].price;
    		int DamageOfWeapon = weapons[number - 1].damage;
    		if(player.Money >= PriceOfWeapon)
    		{
            	backpack.AddWeapon(NameOfWeapon , DamageOfWeapon);
    			player.Money -= PriceOfWeapon;
    			cout << NameOfWeapon << " Is Now In Your Backpack." << endl << "Your Money: " << player.Money << "$" << endl ;
    			break;
			}
			cout << "Sorry! You Don't Have Enough Money To Buy " << NameOfWeapon << "." << endl;
			cout << "Do You Want To Buy Something Else?" << endl;
			cout << "1- No.Leaving The Shop." << endl;
			cout << "2- Yes." << endl;
			int num;
			cin >> num;
			if(num == 1)
				break;
		}
		return true;
	}
};
class ShopOfM{
	friend class Player;
private:
    vector<Weapon> weapons;

public:
	friend void ShowMenue(Player &player , ShopOfM &shopm , ShopOfJ &shopj , ShopOfD &shopd , BackPack& backpack);
    ShopOfM()
    {
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
    void ShowOfShop(Player& player)
    {
    	cout << "Wellcome To Shop " << player.getName() << " :]"<< endl;
    	cout << "Here You Can Find Weapons To Fight Zombies!" << endl;
    	cout << "Your Money = " << player.Money << "$" << endl;
    	cout << "Cold Weapons :" << endl;
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << i + 1 << "-" << weapons[i].name << " [Price = " << weapons[i].price<< "$" << " , Damage = " << weapons[i].damage << "]" << endl;
    	}

    	cout << "Firearms :" << endl;
    	for(int i = 0 ; i < 3 ; i++)
    	{
        	cout << i + 4 << "-" << weapons[i + 3].name << " [Price = " << weapons[i + 3].price<< "$" << " , Damage = " << weapons[i + 3].damage << "]" << endl;
    	}

    	cout << "Throwing Weapons :" << endl;
    	for(int i = 0 ; i < 4 ; i++)
    	{
        	cout << i + 7 << "-" << weapons[i + 6].name << " [Price = " << weapons[i + 6].price<< "$" << " , Damage = " << weapons[i + 6].damage << "]" << endl;
    	}

    	cout << "Consumable Weapons :" << endl;
    	for(int i = 0 ; i < 2 ; i++)
    	{
        	cout << i + 11 << "-" << weapons[i + 10].name << " [Price = " << weapons[i + 10].price << "$" << " , Hp increase = " << weapons[i + 10].damage << "]" << endl;
    	}
    	for(int i = 0 ; i < 2 ; i++)
    	{
        	cout << i + 13 << "-" << weapons[i + 12].name << " [Price = " << weapons[i + 12].price<< "$" << " , Stamina increase = " << weapons[i + 12].damage << "]" << endl;
    	}
    	cout << "15-" << "Back." << endl;//tabeee backk nazadam
    }
    bool BuyWeapon(Player& player , BackPack& backpack)
    {
    	while(true)
    	{
    		cout << "Please Enter Your Choice." << endl;
    		int number;
    		cin >> number;
    		if(number == 15)
    			break;
    		while(true)
    		{
    			if(!(number >= 1 && number <= 15))
    				cout << "Invalid Choice! Please Enter A Valid Number.(1-15)" << endl;

    			else
    				break;
    		}
    		string NameOfWeapon = weapons[number - 1].name;
    		int PriceOfWeapon = weapons[number - 1].price;
    		int DamageOfWeapon = weapons[number - 1].damage;
    		if(player.Money >= PriceOfWeapon)
    		{
            	backpack.AddWeapon(NameOfWeapon , DamageOfWeapon);
    			player.Money -= PriceOfWeapon;
    			cout << NameOfWeapon << " Is Now In Your Backpack." << endl << "Your Money: " << player.Money << "$" << endl ;
    			break;
			}
			cout << "Sorry! You Don't Have Enough Money To Buy " << NameOfWeapon << "." << endl;
			cout << "Do You Want To Buy Something Else?" << endl;
			cout << "1- No.Leaving The Shop." << endl;
			cout << "2- Yes." << endl;
			int num;
			cin >> num;
			if(num == 1)
				break;
		}
		return true;
	}
};
void ShowMenue(Player &player , ShopOfM &shopm , ShopOfJ &shopj , ShopOfD &shopd , BackPack& backpack)
{
	cout << "WELLCOME TO PLAY.IN THIS PLAY WE WILL FIGHT WITH THE ZOMBIZ AND SAVE THE WORLD!WE NEED YOUR HELP TO SAVE THE WORLD.LET'S PLAY!'" << endl;
	cout << "FIRST OF ALL,I WANT TO KHNOW YOUR NAME:]" << endl;
	string name;
	cin >> name;
	player.setName(name);
	cout << "CAN YOU TELL ME YOUR GENDER?" << endl;
	string gender;
	cin >> gender;
	player.setGender(gender);
	int age;
	cout << "HOW OLD ARE YOU " << name << "?" << endl;
	cin >> age;
	player.setAge(age);	
	cout << "CHOOSE ONE OF THE CHARACTERS BELOW:" << endl;
	cout << "1- MichelAngelo" << endl;
	cout << "2- Professor Albus Dumbledore" << endl;
	cout << "3- Jon Snow" << endl;
	int number;
	while(true)
	{
		cin >> number;
		if(number == 1)
		{
			Michelangelo michel(name , gender , age , 1 , 100 , 50 , 20);
			michel.information();
			ShopOfM shopm;
			shopm.ShowOfShop(player);
			BackPack backpack;
			shopm.BuyWeapon(player , backpack);
			//code
			break;
		}
		else if(number == 2)
		{
			Dumbledore dumbledore(name , gender , age , 1 , 100 , 50 , 20);
			dumbledore.information();
			ShopOfD shopd;
			shopd.ShowOfShop(player);
			BackPack backpack;
			shopd.BuyWeapon(player , backpack);
			//code
			break;
		}		
		else if(number == 3)
		{
			JonSnow jon(name , gender , age , 1 , 100 , 50 , 20);
			jon.information();
			ShopOfJ shopj;
			shopj.ShowOfShop(player);
			BackPack backpack;
			shopj.BuyWeapon(player , backpack);
			//code
			break;
		}
		else
		{
			cout << "Invalid Choice! Please Enter A Valid Number.(1-3)" << endl;
		}
	}

}
int main()
{
    //code
    Player player(";kf" , "dk" , 2 , 1 , 100 , 50 , 20);
    ShopOfM shopm;
    ShopOfJ shopj;
    ShopOfD shopd;
	BackPack backpack;
	ShowMenue(player , shopm , shopj, shopd , backpack);
    return 0;
}