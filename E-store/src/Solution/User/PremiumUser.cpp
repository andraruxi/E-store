#include "PremiumUser.h"

using namespace std;

PremiumUser::PremiumUser():User(),premiumSubscriptionCost(0)
{
    //discounts[0]=0;
}

PremiumUser::PremiumUser(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf,
						 const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl,
						 int id, const string &nume, const string &prenume, const string &email, int premiumSubscriptionCost, const map<int, int> &discounts)
	: User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
{
    this->premiumSubscriptionCost=premiumSubscriptionCost;

    this->discounts=discounts;


}

PremiumUser::PremiumUser(const PremiumUser &up) : User(up),premiumSubscriptionCost(up.premiumSubscriptionCost)
{

        discounts=up.discounts;

}

const PremiumUser &PremiumUser::operator=(const PremiumUser &up)
{
	User::operator=(up);
	premiumSubscriptionCost=up.premiumSubscriptionCost;
	discounts=up.discounts;
	return *this;
}

void PremiumUser::displayUser()
{
   map<int,int>::iterator i;
    cout<<"Adresa de facturare:";
	cout<<billingData;
	cout<<"Adresa de livrare:";
	cout<<deliveryData;
	cout<<"Nume:";
	cout<<lastName<<endl;
	cout<<"Prenume:";
	cout<<firstName<<endl;
	cout<<"Email:";
	cout<<email<<endl;
	cout<<"Id user:";
	cout<<UserID<<endl;
    cout<<"Disc:";
    for(i=discounts.begin();i!=discounts.end();i++)
    {
        cout<<i->first<<" ";
        cout<<i->second<<endl;
    }

    cout<<"Cost:";
    cout<<premiumSubscriptionCost<<endl;
}

string PremiumUser::getUserType()
{
	return "Utilizator premium";
}

float PremiumUser::getTransportCost()
{
	return 0;//nu am un camp de transporturi
	//se presupune ca transportul este gratiut pentru userii premium
}

map<int, int> &PremiumUser::getDiscounts()
{
	return discounts;
}

void PremiumUser::setDiscounts(map<int, int> red)
{
	  discounts=red;

}

void PremiumUser::setPremiumSubscriptionCost(int cap)
{
	premiumSubscriptionCost=cap;
}

int PremiumUser::getPremiumSubscriptionCost()
{
	return premiumSubscriptionCost;
}

json PremiumUser::toJSON()
{
	return json(*this);
}
// in rest am constrctorii , getteri , setteri
