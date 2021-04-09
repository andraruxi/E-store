#include "QuerySolver.h"
#include"Max.h"
#include <fstream>


using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver()
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
  if (server != nullptr)
  {
    server = nullptr;
  }
}

list<Product*> QuerySolver::Query_3a(){
    list<Product*>::iterator i;
    list<Product*> redus;
    for(i=server->getProductsList().begin();i!=server->getProductsList().end();i++)
    {
        if((*i)->getProductType()=="DiscountedProduct")
            {
                if((*i)->getCategory()=="espressor")
                {
                    redus.push_back(*i);
                }
            }
    }
    return redus;
    //fac o lista cu de produse unde o sa le bag doar pe cele reduse
    //parcurg lista verific daca produsul meu e redus
    //daca da il pun il lista daca nu nu
    //returnez lista creata
}

list<User*> QuerySolver::Query_3b(){
    list<User*>::iterator i;
    list<User*> basic;
    for(i=server->getUsersList().begin();i!=server->getUsersList().end();i++)
    {
        if((*i)->getUserType()=="Utilizator BASIC")
        {
            if((*i)->getTransportCost()<=11.5)
            {
                basic.push_back(*i);
            }
        }

    }
    return basic;
    //se face asemanator cu 1 dar aici vad daca trasportul este mai mic ca 11.5
}

list<Product*> QuerySolver::Query_3c(){
    list<Product*>::iterator i;
   // list<Product*>::iterator j;
    list<Product*> resigilat;
    for(i=server->getProductsList().begin();i!=server->getProductsList().end();i++)
    {
        if((*i)->getProductType()=="ResealedProduct")
        {
            ResealedProduct *resig=dynamic_cast<ResealedProduct*>(*i);
            if(resig->getReason()=="lipsa_accesorii")
            {
                resigilat.push_back(resig);
            }
        }
    }

    resigilat.sort(Utility::comparePret);
    return resigilat;
    //vrem sa verificam daca in lista noastra exista produse care au lipsa de accesorii
    //pentru a face asta trebuie sa parcurgem lista
    //pentru ca in lista nu exita o functie virtuala getReason() trebuie sa cinvertim iteratorul la clasa resigilate
    //daca indeplineste cond se adauga in lista creata
    //se ord dupa pret si se returneaza
}

list<Product*> QuerySolver::Query_3d(){
    list<Product*>::iterator i;
    list<Product*>alimente;
    for(i=server->getProductsList().begin();i!=server->getProductsList().end();i++)
    {
        if((*i)->getProductType()=="FoodProduct")
        {

            alimente.push_back(*i);
        }
    }
    alimente.sort(Utility::compareFoodProduct);


    return alimente;
    //Asemanator ca la 1 dar aici doar verificam daca produsul este alimentare
    //daca da se pune in lista apoi lista se sorteaza dupa nume,tara si pret si se returneaza

}

list<User*> QuerySolver::Query_3e(){
    list<User*>::iterator i;
    list<User*> utilizatori;

    Max maxJud[1000];

    map<string,int> judete;
    map<string,int>::iterator k;
    pair<string,int> ins;

    int maxim;
    string judetPrincipal;


    for(i=server->getUsersList().begin();i!=server->getUsersList().end();i++)
    {

       if(judete.find((*i)->getDeliveryData().getCounty())==judete.end())
       {
            //ins=((*i)->getDeliveryData().getCounty(),1);
            judete.insert(pair<string,int>((*i)->getDeliveryData().getCounty(),1));

       }
       else
       {
            k=judete.find((*i)->getDeliveryData().getCounty());
           k->second++;
           //judete[k]=judete[k]+1;
       }
    }

    maxim=0;
    for(k=judete.begin();k!=judete.end();k++)
    {
        if(maxim<k->second)//judete[k])
        {
            maxim=k->second;
            judetPrincipal=k->first;
        }
    }


    for(i=server->getUsersList().begin();i!=server->getUsersList().end();i++)
    {
        if((*i)->getDeliveryData().getCounty()== judetPrincipal && (*i)->getDeliveryData().getBlock()=="-"&&(*i)->getDeliveryData().getApartment()==0 &&(*i)->getDeliveryData().getCounty()== judetPrincipal && (*i)->getBillingData().getBlock()=="-" &&
        (*i)->getBillingData().getApartment()==0 && ((*i)->getDeliveryData()==(*i)->getDeliveryData()) )
       {
            utilizatori.push_back(*i);
       }
    }
    utilizatori.sort(Utility::compareID);

    return utilizatori;
    //acesta functie e mai comlexa putin in sensul in care trebuie sa numaram locuitorii dun fiecare judet si apoi sa aflam jud cu cei mai multi loc
    //pentru asta ne ajutam de un map care are ca cheie judetul si ca val nr de locuitori
    //dupa ce se afla jud cu nr max de pers se verifica daca acesta sta la vila indeplinind cerintele din enunt
    //se sorteaza dupa id si se returneaza lista finala


}

list<User*> QuerySolver::Query_3f()
{
    list<User*>::iterator i;
    list<Product*>::iterator j;
    list <User*> listaTelefoane;
    map<int, int> prod;
    map<int,int>::iterator k;
    list<User*>::iterator i2;
    bool flag;

    for(i=server->getUsersList().begin();i!=server->getUsersList().end();i++)
    {
        if((*i)->getUserType()=="Utilizator premium")
        {
            flag=true;

            for(i2=listaTelefoane.begin();i2!=listaTelefoane.end();i2++)
            {
                if((*i)->getUserID()==(*i2)->getUserID())
                {
                    flag=false;
                }
            }

            if(flag==true)
            {
                PremiumUser *prem=dynamic_cast<PremiumUser*>(*i);
                prod=prem->getDiscounts();
                for(k=prod.begin();k!=prod.end();k++)
                {
                    flag=true;
                    for(j=server->getProductsList().begin();j!=server->getProductsList().end();j++)
                    {
                        if((*j)->getId()==(*k).first)
                        {
                                if((*j)->getCategory()=="telefon" || (*j)->getCategory()=="imprimanta")
                                {
                                    listaTelefoane.push_back(*i);
                                    flag=false;
                                    break;
                                }
                         }

                     }
                     if(flag==false)
                     {
                        break;
                     }

                  }
                }
            }
        }
     //listaTelefoane.sort(Utility::compareID);



    return listaTelefoane;
    //acesta functie imi verifica care useri premium au promotie la tel si imprimante
    //am nevoie de un flag pentru ca se repeta id vrem sa eliminam acsta eroare
    //dupa ce vrific rturnez lista finala
    //vom avea nevoie iar de conversia iteratorului deoarece user nu are functia din prmium user getDisc()



}
