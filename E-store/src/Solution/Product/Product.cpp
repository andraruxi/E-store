#include "Product.h"
using namespace std;

Product::~Product() {}

bool Product::checkQuantity(int requestedQuantity)
{
    if(quantity==requestedQuantity)
        return true;
    else return false;//verific daca cantitatea e egala cu request daca da imi retuneaza true daca nu da false
}

Product::Product(const string &category, int id, const string &name, int quantity)

{
    this->name=name;
    this->quantity=quantity;
    this->category=category;
    this->id=id;
//construcotr cu parametrii
}

Product::Product(const Product &p):name(p.name), quantity(p.quantity), category(p.category), id(p.id)
{
//constructor de copiere
}

Product::Product():name(""),quantity(0),category(""),id(0)
{
//constru fara parametrii
}

void Product::decreaseQuantity(int requestedQuantity)
{
    quantity=quantity-requestedQuantity;
    if(quantity<0)
        quantity=0;
        //scad cantitatea ,iar daca ajunge catntitatea e mai mica decat zero ia valoare zero
}

void Product::increaseQuantity(int requestedQuantity)
{
	quantity=quantity+requestedQuantity;
	//creste cantitatea cu requst
}

void Product::setCategory(const string &category)
{
	this->category=category;
}

void Product::setId(int id)
{
	this->id=id;
}

void Product::setQuantity(int quantity)
{
	this->quantity=quantity;
}

void Product::setName(const string &name)
{
	this->name=name;
}

string &Product::getCategory()
{
	return category;
}

int Product::getQuantity()
{
	return quantity;
}

int Product::getId()
{
    return id;
}

string &Product::getName()
{
	return name;
}
//pana aici au fost gettri si setteri

const Product &Product::operator=(const Product &a)
{
	name=a.name;
	category=a.category;
	quantity=a.quantity;
	id=a.id;
	return *this;
}


json Product::toJSON()
{
	return json(*this);
}
