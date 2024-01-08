#include<bits/stdc++.h>
using namespace std;


class Product {
private:
    string name;
    string description;
    double price;
    int stockLevel;


public:
    // constructor
    Product(string name, string description, double price, int stockLevel) {
        this->name = name;
        this->description = description;
        this->price = price;
        this->stockLevel = stockLevel;
    }


    // getters and setters
    const string& getName() const { return name; }
    const string& getDescription() const { return description; }
    double getPrice() const { return price; }
    int getStockLevel() const { return stockLevel; }
    void setName(string name) { this->name = name; }
    void setDescription(string description) { this->description = description; }
    void setPrice(double price) { this->price = price; }
    void setStockLevel(int stockLevel) { this->stockLevel = stockLevel; }


    // operator overloading
    bool operator==(const Product& p) const {
        return (getName() == p.getName() && getDescription() == p.getDescription() && getPrice() == p.getPrice() && getStockLevel() == p.getStockLevel());
    }
};

namespace std {
template<>
struct hash<Product> {
    size_t operator()(const Product& p) const {
        size_t h1 = hash<string>()(p.getName());
        size_t h2 = hash<string>()(p.getDescription());
        size_t h3 = hash<double>()(p.getPrice());
        size_t h4 = hash<int>()(p.getStockLevel());
        return h1 ^ h2 ^ h3 ^ h4;
    }
};

template<>
struct equal_to<Product> {
    bool operator()(const Product& p1, const Product& p2) const {
        return p1 == p2;
    }
};
}

class ShoppingCart {
private:
    std::vector<Product> products;


public:
    // constructor
    ShoppingCart() {}


    // add product to cart
    void addProduct(Product product) { products.push_back(product); }


    // remove product from cart
    void removeProduct(Product product) {
        for (auto it = products.begin(); it != products.end(); it++) {
            if (*it == product) {
                products.erase(it);
                break;
            }
        }
    }


    // calculate total cost of items in cart
    double totalCost(){
        double total = 0;
        for (const Product& p : products) {
            total += p.getPrice();
        }
        return total;
    }
};


class Customer {
private:
    std::string name;
    std::string address;
    std::string email;


public:
    Customer() : name(""), address(""), email("") { }
    Customer(std::string name, std::string address, std::string email) :
        name(name), address(address), email(email) { }


    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getEmail() const { return email; }


    void setName(std::string name) { this->name = name; }
    void setAddress(std::string address) { this->address = address; }
    void setEmail(std::string email) { this->email = email; }


    bool operator==(const Customer& other) const {
        return name == other.name && address == other.address && email == other.email;
    }
};




class Inventory {
    private:
        std::unordered_map<Product, int> products;
    public:
        // constructor
        Inventory(){};
        // method to add a product to the inventory
        void addProduct(Product product, int stock) {
            products[product] = stock;
        }
        // method to update the stock level of a product
        void updateStock(Product product, int stock) {
            products[product] = stock;
        }
        // method to check if a product is in stock
        bool isInStock(Product product) {
            return products[product] > 0;
        }
        // method to restock a product
        void restock(Product product, int quantity) {
            products[product] += quantity;
        }
};




class Payment {
private:
    double amount;
    string paymentMethod;


public:
    // constructor
    Payment() : paymentMethod(""), amount(0) { }
    Payment(double amount, string paymentMethod) {
        this->amount = amount;
        this->paymentMethod = paymentMethod;
    }


    // getters and setters
    double getAmount() const { return amount; }
    string getPaymentMethod() const { return paymentMethod; }
    void setAmount(double amount) { this->amount = amount; }
    void setPaymentMethod(string paymentMethod) { this->paymentMethod = paymentMethod; }


    // payment method functions
    void payWithCreditCard() { /* code to process credit card payment */ }
    void payWithDebitCard() { /* code to process debit card payment */ }
    void payWithNetBanking() { /* code to process net banking payment */ }
};




class Shipping {
private:
    string shippingMethod;
    double shippingCost;


public:
    // constructor
    Shipping() : shippingMethod(""), shippingCost(0.0) { }
    Shipping(string shippingMethod, double shippingCost) {
        this->shippingMethod = shippingMethod;
        this->shippingCost = shippingCost;
    }


    // getters and setters
    string getShippingMethod() { return shippingMethod; }
    double getShippingCost() { return shippingCost; }
    void setShippingMethod(string shippingMethod) { this->shippingMethod = shippingMethod; }
    void setShippingCost(double shippingCost) { this->shippingCost = shippingCost; }
};


class Order {
private:
    Customer customer;
    vector<Product> products;
    double totalCost;
    Payment payment;
    Shipping shipping;


public:
    // constructor
    Order(Customer customer, vector<Product> products, double totalCost, Payment payment, Shipping shipping) {
        this->customer = customer;
        this->products = products;
        this->totalCost = totalCost;
        this->payment = payment;
        this->shipping = shipping;
    }


    // getters and setters
    Customer getCustomer() { return customer; }
    vector<Product> getProducts() { return products; }
    double getTotalCost() { return totalCost; }
    Payment getPayment() { return payment; }
    Shipping getShipping() { return shipping; }
    void setCustomer(Customer customer) { this->customer = customer; }
    void setProducts(vector<Product> products) { this->products = products; }
    void setTotalCost(double totalCost) { this->totalCost = totalCost; }
    void setPayment(Payment payment) { this->payment = payment; }
    void setShipping(Shipping shipping) { this->shipping = shipping; }
   
    // operator overloading for comparing two orders
    bool operator==(const Order& o) {
        return (customer == o.customer && products == o.products && totalCost == o.totalCost);
    }
};




class Admin {
private:
    Inventory inventory;
    vector<Product> products;
    vector<Customer> customers;
    vector<Order> orders;


public:
    // constructor
    Admin() {}
    // methods for adding and updating products
    void addProduct(Product product) { products.push_back(product); }
    void updateProduct(Product product) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i] == product) {
                products[i] = product;
                break;
            }
        }
    }


    // methods for managing stock level
    void updateStockLevel(Product product, int stockLevel) {
        for (int i = 0; i < products.size(); i++) {
            if (products[i] == product) {
                products[i].setStockLevel(stockLevel);
                break;
            }
        }
    }


    // methods for managing orders
    void addOrder(Order order) { orders.push_back(order); }
    void updateOrder(Order order) {
        for (int i = 0; i < orders.size(); i++) {
            if (orders[i] == order) {
                orders[i] = order;
                break;
            }
        }
    }


    // methods for managing customer data
    void addCustomer(Customer customer) { customers.push_back(customer); }
    void updateCustomer(Customer customer) {
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i] == customer) {
                customers[i] = customer;
                break;
            }
        }
    }
};




int main() {
    // Create a new product
    Product p1("iPhone", "New iPhone", 999.99, 10);


    // Create a new inventory
    Inventory inventory;


    // Add the product to the inventory
    inventory.addProduct(p1, 10);


    // Create a new customer
    Customer c1("John Smith", "123 Main St", "johnsmith@email.com");


    // Create a new shopping cart
    ShoppingCart cart;


    // Add the product to the cart
    cart.addProduct(p1);


    // Check if the product is in stock
    if (inventory.isInStock(p1)) {
        cout << "Product is in stock" << endl;
    } else {
        cout << "Product is out of stock" << endl;
    }


    // Print the total cost of items in the cart
    cout << "Total cost: Rs" << cart.totalCost() << endl;


    // Create a new payment
    Payment payment(cart.totalCost(), "Credit Card");


    // Print the payment details
    cout << "Payment amount: Rs" << payment.getAmount() << endl;
    cout << "Payment method: " << payment.getPaymentMethod() << endl;


    return 0;
}