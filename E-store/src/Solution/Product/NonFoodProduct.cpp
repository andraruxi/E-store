#include "NonFoodProduct.h"

NonFoodProduct::NonFoodProduct():producer(""),yearsOfWarranty(0),price(0)
{

}

NonFoodProduct::NonFoodProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int quantity) : Product(category, id, name, quantity)

{
    this->producer=producer;
    this->price=price;
    this->yearsOfWarranty=yearsOfWarranty;
}

NonFoodProduct::NonFoodProduct(const NonFoodProduct &pn) : Product(pn)
{
    price=pn.price;
    yearsOfWarranty=pn.yearsOfWarranty;
    producer=pn.producer;
}

void NonFoodProduct::setYearsOfWarranty(int garantieAni)
{
	yearsOfWarranty=garantieAni;
}

void NonFoodProduct::setPrice(float price)
{
	this->price=price;
}

void NonFoodProduct::setProducer(const string &producer)
{
	this->producer=producer;

}

int NonFoodProduct::getYearsOfWarranty()
{
	return yearsOfWarranty;
}

float NonFoodProduct::getPrice()
{
	return price;

}

string &NonFoodProduct::getProducer()
{
	return producer;

}

bool NonFoodProduct::operator==(const NonFoodProduct &obj) const
{
	return ((price==obj.price)&&(producer==obj.producer)&&(yearsOfWarranty==obj.yearsOfWarranty)&&(category==obj.category)&&(name==obj.name)&&(id==obj.id)&&(quantity==obj.quantity));
}//pot sa folosesc fara getter pentru ca am datele protected in poduct

const NonFoodProduct &NonFoodProduct::operator=(const NonFoodProduct &a)
{
	Product::operator=(a);
	price=a.price;
	yearsOfWarranty=a.yearsOfWarranty;
	producer=a.producer;
	return *this;
}

string NonFoodProduct::getProductType()
{
	return "NonFoodProduct";
}

json NonFoodProduct::toJSON()
{
	return json(*this);
}

void NonFoodProduct::display()
{
	cout << "Product Nealimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl
		 << endl;
}

//getteri, setteri , afisare nimic special
