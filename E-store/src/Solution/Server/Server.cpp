#include "Server.h"

using namespace std;

/* NU MODIFICATI */
Server::Server(){}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server;
	}

	return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__()
{

	list<User*>::iterator i;
	for(i=usr.begin();i!=usr.end();i++)
	{

         pair<int, ShoppingCart*> temporar((*i)->getUserID(),new ShoppingCart);

         __UserID__ProductsCart__.insert(temporar);

	}
	//vreau sa adaug pentru fiacreid user un cos gol de aceea am nevoie de un pair care sa pie user si un cos =>
	//cum cosul vreau sa fie nou il initializez cu new iar la cheie ma folosesc de getterul din clasa user
}

list<Product *> &Server::getProductsList()
{
	return prod;

}

list<User *> &Server::getUsersList()
{
	return usr;
}

map<int, ShoppingCart *> Server::get__UserID__ProductsCart__()
{
	return  __UserID__ProductsCart__;
}

bool Server::requestAddProduct(int userID, int productID, int quantity)
{

    list<User*>::iterator usr_id_it;
    list<Product*>::iterator prd_id_it;
    bool usr_flag = false, prd_flag = false;

    //verific daca totul merge
    for(usr_id_it =usr.begin(); usr_id_it !=usr.end(); usr_id_it++)
    {
        if((*usr_id_it)->getUserID()==userID)
        {
            usr_flag=true;
            break;
        }
    }
    if(usr_flag==false)
        return false;

    for(prd_id_it=prod.begin(); prd_id_it!=prod.end(); prd_id_it++)
    {
        if((*prd_id_it)->getId()==productID)
        {
            prd_flag=true;
            break;
        }
    }
    if(prd_flag==false)
        return false;

    if(quantity<=0)
    {
        return false;
    }

    //get user cart
    ShoppingCart* user_cart = __UserID__ProductsCart__.at(userID);
    map<int, int>& user_cart_map = user_cart->getShoppingCart();
    map<int, int>::iterator cart_it = user_cart_map.find(productID);

    if (cart_it != user_cart_map.end())
    {
        //Element gasit
        if((*prd_id_it)->getQuantity()<quantity)
        {
            cart_it->second+=(*prd_id_it)->getQuantity();
            (*prd_id_it)->decreaseQuantity((*prd_id_it)->getQuantity());
        }
        else
        {
            cart_it->second+=quantity;
            (*prd_id_it)->decreaseQuantity(quantity);
        }

    }
    else
    {
        if((*prd_id_it)->getQuantity()<quantity)
        {
            return false;
        }
        else
        {
            user_cart_map.insert(std::pair<int, int>(productID, quantity));
            (*prd_id_it)->decreaseQuantity(quantity);
        }
    }

    return true;
}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
    list<User*>::iterator usr_id_it;
    list<Product*>::iterator prd_id_it;
    bool usr_flag=false, prd_flag=false;

    //verific daca e totul valabil
    for (usr_id_it =usr.begin(); usr_id_it!=usr.end(); usr_id_it++)
    {
        if ((*usr_id_it)->getUserID()==userID)
        {
            usr_flag=true;
            break;
        }
    }
    if (usr_flag==false)
        return false;

    for (prd_id_it=prod.begin(); prd_id_it!=prod.end(); prd_id_it++)
    {
        if ((*prd_id_it)->getId()==productID)
        {
            prd_flag=true;
            break;
        }
    }
    if (prd_flag==false)
        return false;

    if (quantity<=0)
    {
        return false;
    }

    //Get user shopping cart
    ShoppingCart* user_cart = __UserID__ProductsCart__.at(userID);
    map<int, int>& user_cart_map = user_cart->getShoppingCart();
    map<int, int>::iterator cart_it = user_cart_map.find(productID);

    if (cart_it != user_cart_map.end())
    {
        //gasit!!!
        if (cart_it->second<quantity)
        {
            (*prd_id_it)->increaseQuantity(cart_it->second);
            cart_it->second =0;
        }
        else
        {
            (*prd_id_it)->increaseQuantity(quantity);
            cart_it->second-=quantity;
        }
    }
    else
    {
        return false;
    }

    return true;

}

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
	prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
	usr = ObjectFactory::getUserList(input["useri"]);
}
