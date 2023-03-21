#include "QuerySolver.h"

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
  list<Product *> myListProducts;
  for (Product* prod: server->getProductsList()){
    if ((prod->getCategory() == "espressor") && (prod->getProductType() == "REDUS")){
      myListProducts.push_back(prod);
    }
  }
  return myListProducts;
}

list<User*> QuerySolver::Query_3b(){
  list<User *> myListUsers;
  for (User * user: server->getUsersList()){
    if ((user->getUserType() == "NONPREMIUM") && (user->getTransportCost() <= 11.5)){
      myListUsers.push_back(user);
    }
  }
  return myListUsers;
}

list<Product*> QuerySolver::Query_3c(){
  list<ResealedProduct*> myNewList;
  list<Product*> myList;
  for (Product *elem: server->getProductsList()){
      ResealedProduct *new_it = dynamic_cast<ResealedProduct*>(elem);
      if ( new_it != nullptr){
         if (((*new_it).getProductType() == "RESIGILAT") && ((*new_it).getReason() == "lipsa_accesorii")){
         myNewList.push_back(new_it);
      }
      }
  }
  myNewList.sort(Utility::compare);
  for (ResealedProduct* elem: myNewList){
    myList.push_back(elem);
  }
  return myList;
}

bool compare_users(User *u1, User *u2){
  if (u1->getUserID() < u2->getUserID()){
    return true;
  } else{
    return false;
  }
}

list<Product*> QuerySolver::Query_3d(){
  list<Product*> myFinalList;
  list<FoodProduct*> myFoodProductsList;
  for (Product *elem: server->getProductsList()){
    FoodProduct *new_elem = dynamic_cast<FoodProduct*>(elem);
    if (new_elem != nullptr){
      if ((*new_elem).getProductType() == "ALIMENTAR"){
        myFoodProductsList.push_back(new_elem);
      }
    }
  }
  myFoodProductsList.sort(Utility::cmp);
  for (FoodProduct *elem: myFoodProductsList){
      myFinalList.push_back(elem);
  }
  return myFinalList;
}

list<User*> QuerySolver::Query_3e(){
  map <string, int> my_map;
  for (User * user: server->getUsersList()){
    map <string, int>:: iterator it = my_map.find(user->getDeliveryData().getCounty());
    if (it != my_map.end()){
      my_map[user->getDeliveryData().getCounty()] += 1;
    } else{
      my_map[user->getDeliveryData().getCounty()] = 1;
    }
  }
  int max = -1;
  string county = "";
  for (auto it = my_map.begin(); it != my_map.end(); ++it){
    if (max < it->second){
      max = it->second;
      county = it->first;
    }
  }
  list<User*> myUsersList;
  for (User* user: server->getUsersList()){
    if (user->getDeliveryData().getCounty() == county && user->getBillingData().getCounty() == county &&
        user->getBillingData().getBlock() == "-" && user->getDeliveryData().getBlock() == "-" && 
        user->getDeliveryData().getApartment() == 0 && user->getBillingData().getApartment() == 0){
      myUsersList.push_back(user);
    }
  }
  myUsersList.sort(compare_users);
  return myUsersList;
}

list<User*> QuerySolver::Query_3f()
{
  list<PremiumUser*> premiumUsers;
  list<User*> myList;
  for (User* user: server->getUsersList()){
    PremiumUser *new_user = dynamic_cast<PremiumUser*>(user);
    if (new_user != nullptr){
      if ((*new_user).getUserType() == "PREMIUM"){
        premiumUsers.push_back(new_user);
      }
    }
  }
  for (PremiumUser* user: premiumUsers){
    for (auto itr = user->getDiscounts().begin(); itr != user->getDiscounts().end(); ++itr){
      for(Product* prod: server->getProductsList()){
        if (prod->getId() == itr->first){
          if (prod->getCategory() == "telefon" || prod->getCategory() == "imprimanta"){
            myList.push_back(user);
            break;
          }
        }
      }
    }   
  }
  myList.unique();
  return myList;
}
