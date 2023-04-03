#pragma once

//----------------------------------------------------------------------------/
// Name: Liam Fricker                                                         //
// Student ID: 1126303                                                        //
// Assignment: #4                                                             //
//----------------------------------------------------------------------------//

/*
	This header file holds the class heirarchy of zoo animal classes. Each class has
	its own unique properties representing the animal it takes its name from. Each 
	non-abstract class has a display, calcFoodAmt, and calcVetCost functions that 
	display or return information useful to aspiring Zoo Keepers!
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//Abstract Parent class. Has data members name and food with associating accessors and mutators. 
//Represents animals as a whole.
class Animal {
public:
	Animal();
	Animal(const string &nname, const string &nfood);
	string getName()const;
	string getFood()const;
	void setName(const string &nname);
	void setFood(const string &nfood);
	virtual void display()const = 0;
	virtual double calcFoodAmt()const = 0;
	virtual double calcVetCost()const = 0;

private:
	string name, food;
};

Animal::Animal() : name(""), food("") {}
Animal::Animal(const string &nname, const string &nfood) : name(nname), food(nfood) {}
string Animal::getName()const { return name; }
string Animal::getFood()const { return food; }
void Animal::setName(const string &nname) { name = nname; }
void Animal::setFood(const string &nfood) { food = nfood; }

//Abstract child of Animal. Represents Warm Blooded animals
//Has data member weight with associating accessors/mutators.
class WarmBlooded : public Animal {
public:
	WarmBlooded();
	WarmBlooded(const string &nname, const string &nfood, const double &nweight);
	double getWeight()const;
	void setWeight(const double &nweight);
	virtual double calcFoodAmt()const = 0;
	virtual double calcVetCost()const = 0;
private:
	double weight;
};

WarmBlooded::WarmBlooded(): Animal("", ""), weight(0) {}
WarmBlooded::WarmBlooded(const string &nname, const string &nfood, const double &nweight) :
	Animal(nname, nfood), weight(nweight) {}
double WarmBlooded::getWeight()const { return weight; }
void WarmBlooded::setWeight(const double &nweight) { weight = nweight; }

//Child of WarmBlooded. Has data member age with associating getters/setters.
//Represents a Zoo animal that is an animal.
class Mammal : public WarmBlooded{
public:
	Mammal();
	Mammal(const string &nname, const string &nfood, const int &nage, const double &nweight);
	int getAge()const;
	void setAge(const int &nage);
	virtual void display()const;
	virtual double calcFoodAmt()const;
	virtual double calcVetCost()const;
private:
	int age;
};

Mammal::Mammal() : WarmBlooded("", "", 0), age(0) {}
Mammal::Mammal(const string &nname, const string &nfood, const int &nage, const double &nweight) :
	WarmBlooded(nname, nfood, nweight), age(nage) {}
int Mammal::getAge()const { return age; }
void Mammal::setAge(const int &nage) { age = nage; }
void Mammal::display()const {
	cout << "Name: " << getName() << endl;
	cout << "Type: Mammal\n";
	cout << "Food: " << getFood() << endl;
}
double Mammal::calcFoodAmt()const {
	if (age <= 12) {
		return 1 * getWeight() * 365;
	}
	else if (age <= 24) {
		return 0.8 * getWeight() * 365;
	}
	return 0.6 * getWeight() * 365;
}
double Mammal::calcVetCost()const {
	if (age <= 12) {
		return 200.00;
	}
	else if (age <= 96) {
		return 100.00;
	}
	return 500.00;
}

//Child of WarmBlooded. Represents a Zoo Bird
class Bird : public WarmBlooded {
public:
	Bird();
	Bird(const string &nname, const string &nfood, const double &nweight);
	virtual void display()const;
	virtual double calcFoodAmt()const;
	virtual double calcVetCost()const;
};

Bird::Bird() : WarmBlooded("", "", 0) {}
Bird::Bird(const string &nname, const string &nfood, const double &nweight):
	WarmBlooded(nname, nfood, nweight) {}
void Bird::display()const {
	cout << "Name: " << getName() << endl;
	cout << "Type: Bird\n";
	cout << "Food: " << getFood() << endl;
}
double Bird::calcFoodAmt()const {
	if (getWeight() <= 0.5) {
		return 1.5 * getWeight() * 365;
	}
	return getWeight() * 365;
}
double Bird::calcVetCost()const {
	if (getWeight() <= 0.5) {
		return 100.00;
	}
	return 250.00;
}

//Child of Animal. Represents a Zoo Fish.
class Fish : public Animal {
public: 
	Fish();
	Fish(const string &nname, const string &nfood, const double &nlength);
	double getLength()const;
	void setLength(const double &nlength);
	virtual void display()const;
	virtual double calcFoodAmt()const;
	virtual double calcVetCost()const;
private:
	double length;
};

Fish::Fish() : Animal("", ""), length(0) {}
Fish::Fish(const string &nname, const string &nfood, const double &nlength) :
	Animal(nname, nfood), length(nlength) {}
double Fish::getLength()const { return length; }
void Fish::setLength(const double &nlength) { length = nlength; }
void Fish::display()const {
	cout << "Name: " << getName() << endl;
	cout << "Type: Fish\n";
	cout << "Food: " << getFood() << endl;
}
double Fish::calcFoodAmt()const {
	if (length <= 30) {
		return 3 * 365;
	}
	return 1.5 * 365;
}
double Fish::calcVetCost()const {
	return 0.00;
}

//Child of Animal. Represents a Zoo Reptile.
class Reptile : public Animal {
public:
	Reptile();
	Reptile(const string &nname, const string &nfood);
	virtual void display()const;
	virtual double calcFoodAmt()const;
	virtual double calcVetCost()const;
};

Reptile::Reptile() : Animal("", "") {}
Reptile::Reptile(const string &nname, const string &nfood) :
	Animal(nname, nfood) {}
void Reptile::display()const {
	cout << "Name: " << getName() << endl;
	cout << "Type: Reptile\n";
	cout << "Food: " << getFood() << endl;
}
double Reptile::calcFoodAmt()const {
	return 104.00;
}
double Reptile::calcVetCost()const {
	return 175.00;
}

//Child of Animal. Represents a Zoo Amphibian.
class Amphibian : public Animal {
public:
	Amphibian();
	Amphibian(const string &nname, const string &nfood);
	virtual void display()const;
	virtual double calcFoodAmt()const;
	virtual double calcVetCost()const;
};

Amphibian::Amphibian() : Animal("", "") {}
Amphibian::Amphibian(const string &nname, const string &nfood) :
	Animal(nname, nfood) {}
void Amphibian::display()const {
	cout << "Name: " << getName() << endl;
	cout << "Type: Amphibian\n";
	cout << "Food: " << getFood() << endl;
}
double Amphibian::calcFoodAmt()const {
	return 182.5;
}
double Amphibian::calcVetCost()const {
	return 0.00;
}