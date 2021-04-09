#include "utility.h"
bool Utility::compareFoodProduct( Product *p1, Product *p2)
{
	FoodProduct *f1=dynamic_cast<FoodProduct*>(p1);
	FoodProduct *f2=dynamic_cast<FoodProduct*>(p2);
	if(f1->getName()<f2->getName())
    {
        return true;
    }
    else if(f1->getName()>f2->getName())
    {
        return false;
    }
    else if(f1->getName()==f2->getName())
    {
        if(f1->getCountryOfOrigin()<f2->getCountryOfOrigin())
        {
            return true;
        }
        else if(f1->getCountryOfOrigin()>f2->getCountryOfOrigin())
        {
            return false;
        }
        else if(f1->getCountryOfOrigin()==f2->getCountryOfOrigin())
        {
            if(f1->getLeiPerKg()<f2->getLeiPerKg())
            {
                return true;
            }
            else if(f1->getLeiPerKg()>f2->getLeiPerKg())
            {
                return false;
            }
            else if(f1->getLeiPerKg()==f2->getLeiPerKg())
            {
                return false;
            }
         }
     }
	return false;
	//acesta functie vrea sa ma ajute sa compar tara numele si pretul una in funcyie de alta
	//va trebui sa fac conversia la ood produc ca sa pot lucra cu funtiile de acolo
 }

bool  Utility::compareID(User *u1, User *u2)
{
	if(u1->getUserID() < u2->getUserID())
		return true;
	else return false;
	//testez id =>pt sortare
}
bool Utility::comparePret(Product*p1, Product *p2)
{
    NonFoodProduct *n1=dynamic_cast<NonFoodProduct*>(p1);
    NonFoodProduct *n2=dynamic_cast<NonFoodProduct*>(p2);
    if(n1->getPrice()<n2->getPrice())
    {
        return true;


    }
    else return false;
    //sortare dupa pret fac conversia pt a putea lucra cu funtiile
}
