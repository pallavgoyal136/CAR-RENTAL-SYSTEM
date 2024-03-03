#include <bits/stdc++.h>
using namespace std;
class Car {
private:
    bool available;
    string registrationNumber;
    string name;
    int rating;
    double rate;
    string owner;
    int days;
public:
    Car( const string& registrationNumber, const string& name, int rating, double rate, const string& owner, int days,bool available)
        : registrationNumber(registrationNumber), name(name), rating(rating), rate(rate), owner(owner), days(days),available(available) {}
 void displayDetailsIfAvailable() const {
        if (available==1) {
            cout << "Model: " << name << "\n";
            cout << "Registration Number: " << registrationNumber << "\n";
            cout << "Rating: " << rating << "\n";
            cout << "Rent Cost: " << rate << "\n";
            cout << "-------------------------\n";
        }
    }
     void displayDetails() const {      
            cout << "Model: " << name << "\n";
            cout << "Registration Number: " << registrationNumber << "\n";
            cout<< "Days: " << days<< "\n";
            cout << "-------------------------\n";       
    }
    void displayDetailsToManager() const{
            cout << "Model: " << name << "\n";
            cout << "Registration Number: " << registrationNumber << "\n";
            cout << "Rating: " << rating << "\n";
            cout << "Rent Cost: " << rate << "\n";
            cout << "Rented to: " << owner << "\n";
            cout<< "Days: " << days<< "\n";
            cout << "-------------------------\n";
    }
    bool isAvailable() const { return available; }
    const string& getRegistrationNumber() const { return registrationNumber; }
    const string& getName() const { return name; }
    int getRating() const { return rating; }
    double getRate() const { return rate; }
    const string& getOwner() const { return owner; }
    int getDays() const { return days; }  
    void setAvailable(bool newAvailable) { available = newAvailable; }
    void setRegistrationNumber(const string& newRegNumber) { registrationNumber = newRegNumber; }
    void setName(const string& newName) { name = newName; }
    void setRating(int newRating) { rating = newRating; }
    void setRate(double newRate) { rate = newRate; }
    void setOwner(const string& newOwner) { owner = newOwner; }
    void setDays(int newDays) { days = newDays; }
    static vector<Car> readCarData() {
    vector<Car> cars;
    ifstream file("Car_database.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string mdl, regNum,owner;
        int rate, available, days,rating;
        getline(ss,regNum, ',');
        getline(ss,mdl , ',');
        char comma;
        ss>>rating>>comma>>rate>>comma;
        getline(ss, owner, ',');
        ss>>days>>comma>>available;
        Car car(regNum,mdl,rating,rate,owner,days,available);
        cars.push_back(car);
    }
    file.close();
    return cars;
}
static void writeCarData(const vector<Car>& cars) {
    ofstream file("Car_database.txt");
    if (file.is_open()) {
        for (const Car& car : cars) {
            file << car.registrationNumber << ","
                 << car.name << ","
                 << car.rating << ","
                 << car.rate << ","
                 << car.owner << ","
                 << car.days << ","
                 << car.available << "\n";
        }
        file.close();
        //cout << "Car data written to car_database.txt successfully.\n";
    } else {
        cout << "Unable to open car_database.txt for writing.\n";
    }
}
};
class User {
protected:
    string name;
    string id;
    string password;

public:
    // Constructor
    User(const string& name,const string& id, const string& password)
        : name(name), id(id), password(password) {}
User(){}
    // Getters
    const string& getName() const { return name; }
    string getID() const { return id; }
    const string& getPassword() const { return password; }
    void setName(const string& newName) { name = newName; }
    void setID(const string& newID) { id = newID; }
    void setPassword(const string& newPassword) { password = newPassword; }
};
class Customer : public User {
private:
    int rating;
    int rentedCars;
    double normalDues;
    double fineDues;

public:
    Customer(const string& name, string id, const string& password, int rating, int rentedCars, double normalDues, double fineDues)
        : User(name, id, password), rating(rating), rentedCars(rentedCars), normalDues(normalDues), fineDues(fineDues) {}
Customer(){}
    void setRating(int newRating) { rating = newRating; }
    void setRentedCars(int newRentedCars) { rentedCars = newRentedCars; }
    void setNormalDues(double newNormalDues) { normalDues = newNormalDues; }
    void setFineDues(double newFineDues) { fineDues = newFineDues; }
    int getRating() const { return rating; }
    int getRentedCars() const { return rentedCars; }
    double getNormalDues() const { return normalDues; }
    double getFineDues() const { return fineDues; }
     bool authenticate(const string& enteredPassword) const {
        return (password == enteredPassword);
    }
    void displayCustomerDetails() const {
    cout << "Customer ID: " << id << "\n";
    cout << "Name: " << name << "\n";
    cout << "Rating: " << rating << "\n";
    cout << "Rented Cars: " << rentedCars << "\n";
    cout << "Normal Dues: " << normalDues << "\n";
    cout << "Fine Dues: " << fineDues << "\n";
    cout << "-------------------------\n";
}
    static vector<Customer> readCustomerData() {
        vector<Customer> customers;
        ifstream file("Customer_database.txt");
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Customer customer;
            getline(ss, customer.id, ',');
            getline(ss, customer.name, ',');
            getline(ss, customer.password, ',');        
            char comma;
            ss >> customer.rating >>comma>>customer.rentedCars>>comma>>customer.normalDues>>comma>>customer.fineDues ;
            customers.push_back(customer);
        }
        file.close();
        return customers;
    }
    static void writeCustomerData(const vector<Customer>& customers) {
    ofstream file("Customer_database.txt");
    if (file.is_open()) {
        for (const Customer& customer : customers) {
            file << customer.id << ","
                 << customer.name << ","
                 << customer.password << ","
                 << customer.rating << ","
                 << customer.rentedCars << ","
                 << customer.normalDues << ","
                 << customer.fineDues << "\n";
        }

        file.close();
        //cout << "Customer data written to customer_database.txt successfully.\n";
    } else {
        cout << "Unable to open customer_database.txt for writing.\n";
    }
}
};
class Employee : public User {
private:
    int rating;
    int rentedCars;
    double normalDues;
    double fineDues;
public:
    Employee(const string& name, string id, const string& password, int rating, int rentedCars, double normalDues, double fineDues)
        : User(name, id, password), rating(rating), rentedCars(rentedCars), normalDues(normalDues), fineDues(fineDues) {}
    Employee(){}
    int getRating() const { return rating; }
    int getRentedCars() const { return rentedCars; }
    double getNormalDues() const { return normalDues; }
    double getFineDues() const { return fineDues; }
    void setRating(int newRating) { rating = newRating; }
    void setRentedCars(int newRentedCars) { rentedCars = newRentedCars; }
    void setNormalDues(double newNormalDues) { normalDues = newNormalDues; }
    void setFineDues(double newFineDues) { fineDues = newFineDues; }
    bool authenticate(const string& enteredPassword) const {
        return (password == enteredPassword);
    }
    void displayEmployeeDetails() const {
    cout << "Employee ID: " << id << "\n";
    cout << "Name: " << name << "\n";
    cout << "Rating: " << rating << "\n";
    cout << "Rented Cars: " << rentedCars << "\n";
    cout << "Normal Dues: " << normalDues << "\n";
    cout << "Fine Dues: " << fineDues << "\n";
    cout << "-------------------------\n";
}
    static vector<Employee> readEmployeeData() {
        vector<Employee> employees;
        ifstream file("Employee_database.txt");
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Employee employee;
            getline(ss, employee.id, ',');
            getline(ss, employee.name, ',');
            getline(ss, employee.password, ',');
            char comma;
            ss >> employee.rating >>comma>>employee.rentedCars>>comma>>employee.normalDues>>comma>>employee.fineDues ;
            employees.push_back(employee);
        }
        file.close();
        return employees;
    }
    static void writeEmployeeData(const vector<Employee>& employees) {
    ofstream file("Employee_database.txt");
    if (file.is_open()) {
        for (const Employee& employee : employees) {
            file << employee.id << ","
                 << employee.name << ","
                 << employee.password << ","
                 << employee.rating << ","
                 << employee.rentedCars << ","
                 << employee.normalDues << ","
                 << employee.fineDues << "\n";
        }
        file.close();
        //cout << "Employee data written to customer_database.txt successfully.\n";
    } else {
        cout << "Unable to open Employee_database.txt for writing.\n";
    }
}
};

void showAvailableCars(vector<Car> &cars){
    cout << "Available Cars:\n";
    for (auto& car : cars) {
            if(car.isAvailable())
            car.displayDetailsIfAvailable();   
    }
}
void showSelfRentedCars(vector<Car> &cars,string user){
    cout<<"Self Cars:"<<endl;
    for(auto& car : cars){
        if(car.getOwner()==user) car.displayDetails();
    }
}
void giveManagerOptions(vector<Car> &cars,vector<Customer> &customers, vector<Employee> &employees){
    try{
    cout<<"Enter 1 to go to customers section, 2 to employee section, 3 to go to car section, anything else to exit: "<<endl;
    int option;
    cin>>option;
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
    if(option==1){
        cout<<"Enter 1 to add a new customer, 2 to edit a customer, 3 to delete a customer, 4 to search a customer: "<<endl;
        cin>>option;
            if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
        if(option==1){
            cout<<"Enter customer username: "<<endl;
            string username;
            cin>>username;
            auto it = find_if(customers.begin(), customers.end(),[username](const Customer& c) { return c.getName() == username; });
            if(it==customers.end()){
            cout<<"Enter integer customer id: "<<endl;
            string id;
            cin>>id;
            cout<<"Enter customer password: "<<endl;
            string password;
            cin>>password;
            Customer customer(username,id,password,3,0,0,0);
            customers.push_back(customer);
            cout<<username<<" has been added succesfully"<<endl;
            }
            else{
                cout<<"A customer with this username already exists can't add this username"<<endl;
            }
        }
        else if(option==2){
            cout<<"Enter customer username: "<<endl;
            string username;
            cin>>username;
            auto customer = find_if(customers.begin(), customers.end(),[username](const Customer& c) { return c.getName() == username; });
            if(customer!=customers.end()){
            cout<<"Enter customer's new password: "<<endl;
            string password;
            cin>>password;
            customer->setPassword(password);
            cout<<"Enter customer's new rating: "<<endl;
            int rating;
            cin>>rating;
                if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
            customer->setRating(rating);
            cout<<"Enter Customer's normal dues: "<<endl;
            double normalDues;
            cin>>normalDues;
                if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
            customer->setNormalDues(normalDues);
                        cout<<"Enter Customer's fine dues: "<<endl;
            double fineDues;
            cin>>fineDues;
                if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
            customer->setFineDues(fineDues);
            cout<<"Updated Customer Details"<<endl;
            }
            else{
                cout<<"No such existing customer."<<endl;
            }
        }
        else if(option==3){
            cout<<"Enter customer username whose acount you wish to delete: "<<endl;
            string username;
            cin>>username;
            auto customer = find_if(customers.begin(), customers.end(),[username](const Customer& c) { return c.getName() == username; });
            if(customer==customers.end()){
                cout<<"No such existing customer."<<endl;
            }
            else{
                if(customer->getRentedCars()){
                    cout<<"This customer has some cars with him, can delete only after all cars have been returned"<<endl;
                }
                else if(customer->getFineDues()>0||customer->getNormalDues()>0){
                    cout<<"This customer has not cleared his dues, can delete only after all dues have been cleared"<<endl;
                }
                else{
                    customers.erase(customer);
                    cout<<"Customer deleted succesfully"<<endl;
                }
            }
        }
        else if(option==4){
            cout<<"Enter customer username whose acount you wish to search: "<<endl;
            string username;
            cin>>username;
            auto customer = find_if(customers.begin(), customers.end(),[username](const Customer& c) { return c.getName() == username; });
            if(customer==customers.end()){
                cout<<"No such existing customer."<<endl;
            }
            else{
                customer->displayCustomerDetails();
            }
        }
    }
    else if(option==2){
        cout<<"Enter 1 to add a new employee, 2 to edit a employee, 3 to delete a employee, 4 to search a employee: "<<endl;
        cin>>option;
        if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
        }
        if(option==1){
            cout<<"Enter employee username: "<<endl;
            string username;
            cin>>username;
            auto it = find_if(employees.begin(), employees.end(),[username](const Employee& c) { return c.getName() == username; });
            if(it==employees.end()){
            cout<<"Enter employee id: "<<endl;
            string id;
            cin>>id;
            cout<<"Enter employee password: "<<endl;
            string password;
            cin>>password;
            Employee employee(username,id,password,3,0,0,0);
            employees.push_back(employee);
            cout<<username<<" has been added succesfully"<<endl;
            }
            else{
                cout<<"A employee with this username already exists can't add this username"<<endl;
            }
        }
        else if(option==2){
            cout<<"Enter employee username: "<<endl;
            string username;
            cin>>username;
            auto employee = find_if(employees.begin(), employees.end(),[username](const Employee& c) { return c.getName() == username; });
            if(employee!=employees.end()){
            cout<<"Enter employee's new password: "<<endl;
            string password;
            cin>>password;
            employee->setPassword(password);
            cout<<"Enter employee's new rating: "<<endl;
            int rating;
            cin>>rating;
            if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
            }
            employee->setRating(rating);
             cout<<"Enter Employee's normal dues: "<<endl;
            double normalDues;
            cin>>normalDues;
                if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
            employee->setNormalDues(normalDues);
                        cout<<"Enter Employee's fine dues: "<<endl;
            double fineDues;
            cin>>fineDues;
                if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
            employee->setFineDues(fineDues);
            cout<<"Updated Employee Details"<<endl;
            }
            else{
                cout<<"No such existing employee."<<endl;
            }
        }
        else if(option==3){
            cout<<"Enter employee username whose acount you wish to delete: "<<endl;
            string username;
            cin>>username;
            auto employee = find_if(employees.begin(), employees.end(),[username](const Employee& c) { return c.getName() == username; });
            if(employee==employees.end()){
                cout<<"No such existing employee."<<endl;
            }
            else{
                if(employee->getRentedCars()){
                    cout<<"This employee has some cars with him, can delete only after all cars have been returned"<<endl;
                }
                else if(employee->getFineDues()>0||employee->getNormalDues()>0){
                    cout<<"This employee has not cleared his dues, can delete only after all dues have been cleared"<<endl;
                }
                else{
                    employees.erase(employee);
                    cout<<"Employee deleted succesfully"<<endl;
                }
            }
        }
        else if(option==4){
            cout<<"Enter employee username whose acount you wish to search: "<<endl;
            string username;
            cin>>username;
            auto employee = find_if(employees.begin(), employees.end(),[username](const Employee& c) { return c.getName() == username; });
            if(employee==employees.end()){
                cout<<"No such existing employee."<<endl;
            }
            else{
                employee->displayEmployeeDetails();
            }
        }
    }
    else if(option==3){
        cout << "Enter 1 to add a new car, 2 to edit a car, 3 to delete a car, 4 to search a car: " << endl;
        cin >> option;
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
    if (option == 1) {
        cout << "Enter registration number: " << endl;
        string regNum;
        cin >> regNum;
        auto existingCar = find_if(cars.begin(), cars.end(), [regNum](const Car& c) { return c.getRegistrationNumber() == regNum; });
        if (existingCar != cars.end()) {
            cout << "A car with this registration number already exists. Cannot add the car." << endl;           
        }
        else{
        cout << "Enter car name: " << endl;
        string carName;
        cin >> carName;
        cout << "Enter car rating: " << endl;
        int rating;
        cin >> rating;
        if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
        cout << "Enter rent rate: " << endl;
        double rate;
        cin >> rate;
        if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
        Car car(regNum, carName, rating, rate, "None", 0, true);
        cars.push_back(car);
        cout << carName << " has been added successfully" << endl;
        }
    }
    else if(option==2){
        cout << "Enter registration number of the car you want to edit: " << endl;
        string regNum;
        cin >> regNum;
        auto car = find_if(cars.begin(), cars.end(), [regNum](const Car& c) { return c.getRegistrationNumber() == regNum; });
        if(car==cars.end()){
            cout<<"No car with this registration number exists"<<endl;
        }
        else{
            if(!car->isAvailable()){
                cout<<"Can Update the car only after it has been returned back"<<endl;
            }
            else{
                cout << "Enter updated registration number: " << endl;
                string newRegNum;
                cin >> newRegNum;
                auto existingCar = find_if(cars.begin(), cars.end(), [newRegNum](const Car& c) { return c.getRegistrationNumber() == newRegNum; });
                if (existingCar != cars.end()) {
                    cout << "A car with this registration number already exists. Cannot update the car." << endl;
                }
                else{
                car->setRegistrationNumber(newRegNum);
                cout << "Enter updated car name: " << endl;
                string newName;
                cin >> newName;
                car->setName(newName);
                cout << "Enter updated car rating: " << endl;
                int newRating;
                cin >> newRating;
                if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
                car->setRating(newRating);
                cout << "Enter updated rent rate: " << endl;
                double newRate;
                cin >> newRate;
                if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
                car->setRate(newRate);
                cout << "Updated Car Details" << endl;
                }
            }
        }
    }
    else if(option==3){
        cout << "Enter registration number of the car you want to delete: " << endl;
        string regNum;
        cin >> regNum;
        auto car = find_if(cars.begin(), cars.end(), [regNum](const Car& c) { return c.getRegistrationNumber() == regNum; });
        if (car == cars.end()) {
            cout << "No such existing car." << endl;
        } else {
            if (car->isAvailable()) {
                cars.erase(car);
                cout << "Car deleted successfully" << endl;
            } else {
                cout << "Cannot delete the car. Car is not available." << endl;
            }
        }
    }
    else if(option==4){
         cout << "Enter registration number of the car you want to search: " << endl;
        string regNum;
        cin >> regNum;
        auto car = find_if(cars.begin(), cars.end(), [regNum](const Car& c) { return c.getRegistrationNumber() == regNum; });
        if (car == cars.end()) {
            cout << "No such existing car." << endl;
        }
        else{
            car->displayDetailsToManager();
        }
    }
}
    else return;
    }catch(const exception &e){
        cerr << "Error occurred: " << e.what() << endl;
    }
Car::writeCarData(cars);
Customer::writeCustomerData(customers);
Employee::writeEmployeeData(employees);
giveManagerOptions(cars,customers,employees);
}
void giveCustomerOptions(vector<Car> &cars,vector<Customer> &customers,int position){
    try{
    cout<<"Enter 1 to see available cars and rent a new car, 2 to return car, 3 to clear dues, anything else to logout:"<<endl;
    int option;
    cin>>option;
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
    if(option==1){
        showAvailableCars(cars);
        int moreNumberOfCars=customers[position].getRating()-customers[position].getRentedCars();
        cout<<"You can rent more "<<moreNumberOfCars<<" cars"<<endl;
        if(moreNumberOfCars>0){
            cout<<"Enter Car id:"<<endl;
            string id;
            cin>>id;
            auto it = find_if(cars.begin(), cars.end(),[id](const Car& c) { return c.getRegistrationNumber() == id; });
            if(it->isAvailable()){
                cout<<"Price of Car is "<<it->getRate()<<" per day."<<endl;
                cout<<"Enter valid number of days:"<<endl;
                int numOfDays;
                cin>>numOfDays;
                if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
                cout<<"Total Amount due is"<<numOfDays*it->getRate()<<", Enter 1 to pay this amount right now or 2 to pay later:"<<endl;
                int payNow;
                cin>>payNow;
                if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
                customers[position].setRentedCars(customers[position].getRentedCars()+1);
                it->setAvailable(false);
                it->setDays(numOfDays);
                it->setOwner(customers[position].getName());
                if(payNow==2){
                    customers[position].setNormalDues(customers[position].getNormalDues()+numOfDays*it->getRate());
                }
                cout<<"Enjoy the ride of "<<it->getName()<<endl;
            }
            else{
                cout<<"No such car"<<endl;
            }
        }
    }
    else if(option==2){
        showSelfRentedCars(cars,customers[position].getName());
        string id;
        cout<<"Enter Car registration number: "<<endl;
        cin>>id;
        auto car = find_if(cars.begin(), cars.end(),[id](const Car& c) { return c.getRegistrationNumber() == id; });
        if(car->getOwner()==customers[position].getName()&&!car->isAvailable()){
            cout<<"Enter number of days after which you have returned: "<<endl;
            int numOfDays;
            cin>>numOfDays;
            if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
            if(numOfDays>car->getDays()){
                cout<<"You will have to pay an additional fine of "<<(numOfDays-car->getDays())*1.5*car->getRate()<<endl;
            }
            int carRating;
            cout<<"Enter Car's New Rating: "<<endl;
            cin>>carRating;
            if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
                if(numOfDays>car->getDays()){
                customers[position].setFineDues((numOfDays-car->getDays())*1.5*car->getRate());
            }
            if(carRating>=car->getRating()&&numOfDays<=car->getDays()&&customers[position].getRating()<5) customers[position].setRating(customers[position].getRating()+1);
            else if(carRating<car->getRating()&&numOfDays>car->getDays()&&customers[position].getRating()>1) customers[position].setRating(customers[position].getRating()-1);
            car->setRating(carRating);
            car->setAvailable(true);
            car->setDays(0);
            car->setOwner("None");
            customers[position].setRentedCars(customers[position].getRentedCars()-1);
        }
        else{
            cout<<"You don't have this car"<<endl;
        }
    }
    else if(option==3){
        cout<<"You have normal dues of "<<customers[position].getNormalDues()<<" and fine dues of "<<customers[position].getFineDues()<<endl;
        cout<<"Enter amount to pay: "<<endl;
        double amount;
        cin>>amount;
        if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
        if(amount>customers[position].getFineDues()+customers[position].getNormalDues()){
            cout<<"You cannot pay more than you dues"<<endl;
        }
        else if(amount<=0){
            cout<<"You can only return positive money"<<endl;
        }
        else if(amount<customers[position].getFineDues()){
            customers[position].setFineDues(customers[position].getFineDues()-amount);
            cout<<"Amount has been payed"<<endl;
        }
        else{
            amount-=customers[position].getFineDues();
            customers[position].setFineDues(0);
            customers[position].setNormalDues(customers[position].getNormalDues()-amount);
            cout<<"Amount has been payed"<<endl;
        }
    }
    else return;
    }
    catch(const exception &e){
        cerr << "Error occurred: " << e.what() << endl;
    }
    Car::writeCarData(cars);
    Customer::writeCustomerData(customers);
    giveCustomerOptions(cars,customers,position);
}
void giveEmployeeOptions(vector<Car> &cars,vector<Employee> &employees,int position){
    try{
    cout<<"Enter 1 to see available cars and rent a new car, 2 to return car, 3 to clear dues, anything else to logout:"<<endl;
    int option;
    double discount=15;
    cin>>option;
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
    if(option==1){
        showAvailableCars(cars);
        int moreNumberOfCars=employees[position].getRating()-employees[position].getRentedCars();
        cout<<"You can rent more "<<moreNumberOfCars<<" cars"<<endl;
        if(moreNumberOfCars>0){
            cout<<"Enter Car id:"<<endl;
            string id;
            cin>>id;
            auto it = find_if(cars.begin(), cars.end(),[id](const Car& c) { return c.getRegistrationNumber() == id; });
            if(it->isAvailable()){
                cout<<"Price of Car is "<<it->getRate()*(100-discount)/100<<" per day after adding employee discount."<<endl;
                cout<<"Enter valid number of days:"<<endl;
                int numOfDays;
                cin>>numOfDays;
                    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
                cout<<"Total Amount due is"<<numOfDays*it->getRate()*(100-discount)/100<<", Enter 1 to pay this amount right now or 2 to pay later:"<<endl;
                int payNow;
                cin>>payNow;
                    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
                employees[position].setRentedCars(employees[position].getRentedCars()+1);
                it->setAvailable(false);
                it->setDays(numOfDays);
                it->setOwner(employees[position].getName());
                if(payNow==2){
                    employees[position].setNormalDues(employees[position].getNormalDues()+numOfDays*it->getRate()*(100-discount)/100);
                }
                cout<<"Enjoy the ride of "<<it->getName()<<endl;
            }
            else{
                cout<<"No such car"<<endl;
            }
        }
    }
    else if(option==2){
        showSelfRentedCars(cars,employees[position].getName());
        string id;
        cout<<"Enter Car registration number: "<<endl;
        cin>>id;
        auto car = find_if(cars.begin(), cars.end(),[id](const Car& c) { return c.getRegistrationNumber() == id; });
        if(car->getOwner()==employees[position].getName()&&!car->isAvailable()){
            cout<<"Enter number of days after which you have returned: "<<endl;
            int numOfDays;
            cin>>numOfDays;
                if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
            if(numOfDays>car->getDays()){
                cout<<"You will have to pay an additional fine of "<<(numOfDays-car->getDays())*1.5*car->getRate()*(100-discount)/100<<endl;
            }
            int carRating;
            cout<<"Enter Car's New Rating: "<<endl;
            cin>>carRating;
                if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
              if(numOfDays>car->getDays()){
                employees[position].setFineDues((numOfDays-car->getDays())*1.5*car->getRate()*(100-discount)/100);
            }
            if(carRating>=car->getRating()&&numOfDays<=car->getDays()&&employees[position].getRating()<5) employees[position].setRating(employees[position].getRating()+1);
            else if(carRating<car->getRating()&&numOfDays>car->getDays()&&employees[position].getRating()>1) employees[position].setRating(employees[position].getRating()-1);
            car->setRating(carRating);
            car->setAvailable(true);
            car->setDays(0);
            car->setOwner("None");
            employees[position].setRentedCars(employees[position].getRentedCars()-1);
        }
        else{
            cout<<"You don't have this car"<<endl;
        }
    }
    else if(option==3){
        cout<<"You have normal dues of "<<employees[position].getNormalDues()<<" and fine dues of "<<employees[position].getFineDues()<<endl;
        cout<<"Enter amount to pay: "<<endl;
        double amount;
        cin>>amount;
            if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        throw invalid_argument("Invalid input. Please enter a valid option.");
    }
        if(amount>employees[position].getFineDues()+employees[position].getNormalDues()){
            cout<<"You cannot pay more than you dues"<<endl;
        }
        else if(amount<=0){
            cout<<"You have to return positive money"<<endl;
        }
        else if(amount<employees[position].getFineDues()){
            employees[position].setFineDues(employees[position].getFineDues()-amount);
            cout<<"Amount has been payed"<<endl;
        }
        else{
            amount-=employees[position].getFineDues();
            employees[position].setFineDues(0);
            employees[position].setNormalDues(employees[position].getNormalDues()-amount);
            cout<<"Amount has been payed"<<endl;
        }
    }
    else return;
    }
    catch(const exception &e){
        cerr << "Error occurred: " << e.what() << endl;
    }
    Car::writeCarData(cars);
    Employee::writeEmployeeData(employees);
    giveEmployeeOptions(cars,employees,position);
}
void openLoginInterface(){
    vector<Car> cars = Car::readCarData();
    string username,password,typeOfUser;
    int index;
    cout<<"Enter 1 for Customer, 2 for Employee, 3 for Manager, anything else to exit application:"<<endl;
    cin>>index;
    if(index==1||index==2){
    cout<<"Enter your username:"<<endl;
    cin>>username;
    
    cout<<"Enter your password:"<<endl;
    cin>>password;
    }
    if(index==1){
        typeOfUser="Customer";
        vector<Customer> customers = Customer::readCustomerData();
            auto customer = find_if(customers.begin(), customers.end(),[username](const Customer& c) { return c.getName() == username; });
            if (customer->authenticate(password)) {
            cout << "Login successful! Welcome, " << customer->getName() << "!\n";
            int position=distance(customers.begin(),customer);
            giveCustomerOptions(cars,customers,position);
           }
           else{
            cout<<"Incorrect Credentials"<<endl;
            customers.clear();
            cars.clear();
           }
    }
    else if(index==2){
        typeOfUser="Employee";
        vector<Employee> employees = Employee::readEmployeeData();
            auto employee = find_if(employees.begin(), employees.end(),[username](const Employee& c) { return c.getName() == username; });
            if (employee->authenticate(password)) {
            cout << "Login successful! Welcome, " << employee->getName() << "!\n";
            int position=distance(employees.begin(),employee);
            giveEmployeeOptions(cars,employees,position);
           }
           else{
            cout<<"Incorrect Credentials"<<endl;
            employees.clear();
            cars.clear();
           }
    }
    else if(index==3) {
        vector<Customer> customers = Customer::readCustomerData();
        vector<Employee> employees = Employee::readEmployeeData();
        giveManagerOptions(cars,customers,employees);
    }
    else{
        return;
    }
    cin.ignore();
    openLoginInterface();
}

int main(){
openLoginInterface();
}