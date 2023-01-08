#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

//declaration
class item
{
	public:
		//default constructor
		item();
		//create item
		item(std::string str, int back, int front);
		//print details
		void print();
		//set item number
		void set(int num);
		//destructor
		~item() { /*delete(this);*/ std::cout << "destructor" << std::endl; };

	private:
		//name of item
		std::string name;
		//item number of item (local store)
		int item_number;
		//total quantity in the store (backroom + front_store)
		int boh;
		//quantity in the backroom
		int backroom;
		//quantity in the front store
		int front_store;

};
class inventory
{
	public:
		//default constructor
		inventory();
		//display item
		void display();
		//add item
		void add(int num,item *x);
		//destructor
		~inventory() { /*delete(this);*/ };

	private:
		// map to act as inventory
			//first is serial number (global to any store)
			//second is item object
		std::map<int, item> storage;
};

//definition
item::item() : name(""), item_number(0), boh(0), backroom(0), front_store(0) {}
item::item(std::string str, int back, int front)
{
	//fill out details
	name = str;
	item_number = 0;
	backroom = back;
	front_store = front;
	boh = back + front;
}
void item::print() 
{
	std::cout << "NAME: " << name << std::endl;
	std::cout << "Item number: " << item_number << std::endl;
	std::cout << "BOH: " << boh << std::endl;
	std::cout << "Backroom: " << backroom << std::endl;
	std::cout << "Front store: " << front_store << std::endl;

}
void item::set(int num) 
{
	item_number = num;
}

inventory::inventory() : storage({}) {};
void inventory::display()
{
	//iterator for map 
	std::map<int, item>::iterator it = storage.begin();
	//loop through the whole storage
	while (it != storage.end())
	{
		std::cout << "Serial number: " << it->first << std::endl;
		it->second.print();
		++it;
	}
}
void inventory::add(int num, item *x)
{
	//holds number for item number
	int temp;
	//while item number is already in inventory
	while(storage.map::find(num) != storage.map::end())
	{
		std::cout << "Item with " << num << " as a " << "Serial number already exists.Please try again..." << std::endl;
		std::cin >> num;
	}
	storage.map::insert({ num, *x });

		
}




int main()
{
	//input:
		//item number 
	//processes:
		//update backroom
		//update front_store
		//update boh 
		//add new item in inventory(done)
    //remove items in inventory
		//display backroom, front_store, boh of the item(done)

	inventory cvs;

	item* temp = new item("chips", 10, 100);
	cvs.add(65, temp);
	temp = new item("cheetos", 5, 0);
	cvs.add(65, temp);
	cvs.display();


}
