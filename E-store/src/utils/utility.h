#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../Solution/Product/NonFoodProduct.h"
#include "../Solution/Product/FoodProduct.h"
#include"../Solution/User/BasicUser.h"
#include"../Solution/User/PremiumUser.h"

class Utility{

public:
	static bool compareFoodProduct( Product *p1,Product *p2);
	static bool compareID(User *u1,  User *u2);
	static bool comparePret(Product*p1, Product *p2);

};
