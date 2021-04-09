#include "Address.h"

using namespace std;

Address::Address():county(""),locality(""),street(""),number(0),block(""),apartment(0)
{

}

Address::Address(const Address &address):county(address.county),locality(address.locality),street(address.street),number(address.number),block(address.block),apartment(address.apartment)
{

}

Address::Address(const string &jud, const string &loc, const string &str, int nr, const string &bl, int ap):county(jud),locality(loc),street(str),number(nr),block(bl),apartment(ap)
{

}

const Address &Address::operator=(const Address &adr)
{
	county=adr.county;
	locality=adr.locality;
	street=adr.street;
	number=adr.number;
	block=adr.block;
	apartment=adr.apartment;
	return *this;
}

void Address::setStrada(const string &str)
{
	street=str;
}

void Address::setNumber(int nr)
{
	number=nr;
}

void Address::setBlock(const string &bl)
{
	block=bl;
}

void Address::setApartment(int ap)
{
	apartment=ap;
}

void Address::setCounty(const string &jud)
{
	county=jud;
}

void Address::setLocality(const string &loc)
{
	locality=loc;
}

string &Address::getStreet()
{
	return street;
}

int Address::getNumber()
{
	return number;
}
string &Address::getBlock()
{
	return block;
}

int Address::getApartment()
{
	return apartment;
}

string &Address::getCounty()
{
	return county;
}

string &Address::getLocality()
{
	return locality;
}

bool Address::operator==(const Address &address)
{
	return ((county==address.county)&&(locality==address.locality)&&(street==address.street)&&(number==address.number)&&(block==address.block)&&(apartment==address.apartment));
}
//operatorul == care imi retuneaza verificarea egalitatii dintre atributele clasei
bool Address::operator!=(const Address &address)
{
    return (!(*this==address));
}
//operatorul!= care se foloseste de op== sa testeze(reutilizarea codului)
ostream &operator<<(ostream &os, const Address &a)
{
	os<<"Judet:";
	os<<a.county<<endl;
	os<<"Localitate:";
	os<<a.locality<<endl;
	os<<"Strada:";
	os<<a.street<<endl;
	os<<"Numar:";
	os<<a.number<<endl;
	os<<"Bloc:";
	os<<a.block<<endl;
	os<<"Ap:";
	os<<a.apartment<<endl;
	return os;


}

json Address::toJSON()
{
	return json(*this);
}
//in rest clasa doar imi implementeaza getteri setteri si functii clasice
