simulation:	simulation.cpp Entity.cpp Entity.h Buyer.h Buyer.cpp Seller.h Seller.cpp Retailer.h Retailer.cpp Inventory.h Inventory.cpp Product.h Product.cpp stockInventory.cpp createOrders.cpp Order.h Order.cpp
	g++ -std=c++11 -o simulation simulation.cpp Entity.cpp Buyer.cpp Seller.cpp Retailer.cpp Inventory.cpp Product.cpp stockInventory.cpp createOrders.cpp Order.cpp

testInventory:	Inventory.h Inventory.cpp testInventory.cpp Product.cpp
	g++ -std=c++11 -o testInventory testInventory.cpp Inventory.cpp Product.cpp
testRetailer:	Entity.h Entity.cpp Seller.h Seller.cpp Buyer.h Buyer.cpp Retailer.h Retailer.cpp testRetailer.cpp 
	g++ -std=c++11 -o testRetailer testRetailer.cpp Entity.cpp Seller.cpp Buyer.cpp Retailer.cpp

testBuySell:	Entity.h Entity.cpp Seller.h Seller.cpp Buyer.h Buyer.cpp testBuySell.cpp 
	g++ -std=c++11 -o testBuySell testBuySell.cpp Entity.cpp Seller.cpp Buyer.cpp

testSeller:	Entity.h Entity.cpp Seller.h Seller.cpp Buyer.h Buyer.cpp Product.h Product.cpp Order.h Order.cpp Inventory.h Inventory.cpp stockInventory.cpp createOrders.cpp testSeller.cpp 
	g++ -std=c++11 testSeller.cpp Entity.cpp Seller.cpp Buyer.cpp Product.cpp Order.cpp Inventory.cpp stockInventory.cpp createOrders.cpp -o testSeller 

testBuyer:	Entity.h Entity.cpp testBuyer.cpp Buyer.h Buyer.cpp createOrders.cpp Order.h Order.cpp Product.h Product.cpp Seller.h Seller.cpp Inventory.h Inventory.cpp stockInventory.cpp
	g++ -std=c++11 -o testBuyer testBuyer.cpp Entity.cpp Buyer.cpp createOrders.cpp Order.cpp Product.cpp Seller.cpp Inventory.cpp stockInventory.cpp

testEntity:	Entity.h Entity.cpp testEntity.cpp
	g++ -std=c++11 -o testEntity testEntity.cpp Entity.cpp


clean:	
	rm testEntity testBuyer testSeller testBuySell testRetailer testInventory simulation





