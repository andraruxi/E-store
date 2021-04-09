#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->payMethod = "-";
	//shoppingCart[0]=0;
}

ShoppingCart::ShoppingCart(const string &payMethod)
{
    this->payMethod=payMethod;

	//shoppingCart[0]=0;
}

string &ShoppingCart::getPayMethod()
{
	return payMethod;
}

void ShoppingCart::setPayMethod(const string &payMethod)
{
	this->payMethod=payMethod;
}

void ShoppingCart::addProduct(int id, int quantity)
{
	pair<int,int> produs(id,quantity);
    shoppingCart.insert(produs);
    //pentru a adauga intr un map avem nevoie de pair
    //creez o pereche de tip produs cu id si cantitate si o pun in map
    //se aranjeaza singura dupa id
}

void ShoppingCart::raiseQuantity(int id, int quantity)
{
	shoppingCart[id]=shoppingCart[id]+quantity;
	//pentru ca exista operatorul [] suprascis in map deci putem sa ne folosim de cheie sa returnam valoarea si sa o crestem
}

void ShoppingCart::lowerQuantity(int id, int quantity)
{
	shoppingCart[id]=shoppingCart[id]-quantity;
	//Analog ca la increse dar aici scadem val in loc sa o crestem
}

int ShoppingCart::getQuantity(int productID)
{
	if(shoppingCart[productID]!=0)
        return shoppingCart[productID];
    else return -1;//aici verific daca am vreau id cu valoarea 0 daca da returnez -1 pentru ca insemna ca producul a fost sters
}

void ShoppingCart::deleteProduct(int productID)
{
    shoppingCart.erase(productID);
    //sterg produsul

}



map<int, int> &ShoppingCart::getShoppingCart()
{
	return shoppingCart;
}

void ShoppingCart::displayShoppingCart()
{
    map<int,int>::iterator i;
    cout<<"Metoda de plata:";
    cout<<payMethod<<endl;
    cout<<"Cosul de cumparaturi:";
    for(i=shoppingCart.begin();i!=shoppingCart.end();i++)
    {
        cout<<i->first<<" ";
        cout<<i->second <<endl;

    }

}

json ShoppingCart::toJSON()
{
  return json(*this);
}

