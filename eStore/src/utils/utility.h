#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../Solution/Product/NonFoodProduct.h"
#include "../Solution/Product/FoodProduct.h"

class Utility{
    
public:
   static bool compare(NonFoodProduct* p1, NonFoodProduct* p2);
   static bool cmp(FoodProduct* p1, FoodProduct* p2);
};
