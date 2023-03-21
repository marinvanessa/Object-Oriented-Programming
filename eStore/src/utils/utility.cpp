#include "utility.h"

bool Utility::compare(NonFoodProduct* p1,NonFoodProduct* p2){
    if (p1->getPrice() < p2->getPrice()){
        return true;
    }
    return false;
}

bool Utility::cmp(FoodProduct* p1, FoodProduct* p2){
    if (p1->getName() < p2->getName()){
        return true;
    } 
    if (p1->getName() > p2->getName()){
        return false;
    }
    if (p1->getCountryOfOrigin() < p2->getCountryOfOrigin()){
        return true;
    } 
    if (p1->getCountryOfOrigin() > p2->getCountryOfOrigin()){
        return false;
    }
     if (p1->getLeiPerKg() < p2->getLeiPerKg()){
        return true;
    } 
    if (p2->getLeiPerKg() > p2->getLeiPerKg()){
        return false;
    }
}








