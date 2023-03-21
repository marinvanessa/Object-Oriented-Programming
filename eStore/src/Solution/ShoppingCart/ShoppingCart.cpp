#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const string &payMethod)
{
	this->payMethod = payMethod;
}

string &ShoppingCart::getPayMethod()
{
	return payMethod;
}

void ShoppingCart::setPayMethod(const string &payMethod)
{
	this->payMethod = payMethod;
}

void ShoppingCart::addProduct(int id, int quantity)
{
	// for (auto itr = shoppingCart.begin(); itr != shoppingCart.end(); ++itr){
	// 	if (itr->first != id && itr->second == -1){
			this->shoppingCart.insert(pair<int, int>(id, quantity));
	// 	}
	// }
	
}

void ShoppingCart::raiseQuantity(int id, int quantity)
{
	for (auto itr = shoppingCart.begin(); itr != shoppingCart.end(); ++itr){
		if (itr->first == id){
			itr->second += quantity;
		}
	}
}

void ShoppingCart::lowerQuantity(int id, int quantity)
{
	for (auto itr = shoppingCart.begin(); itr != shoppingCart.end(); ++itr){
		if (itr->first == id){
			itr->second -= quantity;
		}
	}
}

int ShoppingCart::getQuantity(int productID)
{
	for (auto itr = shoppingCart.begin(); itr != shoppingCart.end(); ++itr){
		if (itr->first == productID){
			return itr->second;
		}
	}
	return -1;
}

void ShoppingCart::deleteProduct(int productID)
{
	// for (auto itr = shoppingCart.begin(); itr != shoppingCart.end(); ++itr){
	// 	if (itr->first == productID){
			this->shoppingCart.erase(productID);
	// 	}
	// }
	
}

map<int, int> &ShoppingCart::getShoppingCart()
{
	return this->shoppingCart;
}

void ShoppingCart::displayShoppingCart()
{
	throw("undefined");
}

json ShoppingCart::toJSON()
{
  return json(*this);
}