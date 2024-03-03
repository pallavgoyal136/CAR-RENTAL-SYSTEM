
Car Rental System
Welcome to the Car Rental System, a simple application built using C++ for managing car rentals, customers, and employees.

Databases
Car Database (Car_database.txt)
The Car Database (Car_database.txt) contains information about each car. Each row represents a single car with values separated by commas. The fields include:

Registration Number
Model
Car Rating
Price per Day
Owner
Availability (1 for available, 0 for rented)
Operations on cars are performed based on the unique Registration Number. The program warns when adding a new car with an existing Registration Number. Car Rating represents the condition of the car, and Price per Day is the cost for customers to rent the car. The owner field indicates the customer or employee who has rented the car (None if not rented).

Customer Database (Customer_database.txt)
The Customer Database (Customer_database.txt) stores data about each customer. Each row represents a single customer with values separated by commas. The fields include:

ID
Username
Password
Customer Rating
Number of Rented Cars
Normal Dues
Fine Dues
Operations on customers are based on the unique Username. The program warns when adding a new user with an existing username. Customer Rating denotes the customer's record, and the customer can rent cars up to their rating. Dues are updated based on the number of days a car is booked, and fine dues are updated for delays in returning cars.

Employee Database (Employee_database.txt)
The Employee Database (Employee_database.txt) is similar to the Customer Database, but employees receive an extra 15% discount.

Then entire program is the Rental.cpp file. Sample data has been loaded into the customer,employee and car database.
To run the program open the entire directory onto terminal and run, g++ Rental.cpp -o Rental
After this run ./Rental.exe
Operations
Customer/Employee Interface
Firstly enter number as per the customer and employee
Enter username and password for authentication.
To view available cars and rent a new car, enter 1.
To return a car, enter 2.
To clear dues, enter 3.
Press any other key to log out.
Once an operation is done the user is again given all the options which he can do

Manager Interface
There is no username and password for manager he can freely do his operations
Enter 1 to go to the customer section
Enter 2 to go to the employee section.
Enter 3 to go to the car section.
Press any other key to log out.

Assumptions
Inputs are taken using cin, so there should be no spaces in entered strings otherwise program may behave enexpectedly.
Users will provide accurate information about the number of days and car conditions.
When registering a new user, username, ID, and password are required. Default values include 0 dues, 0 rented cars, and an average customer rating of 3.
When registering a new car, the registration number, model, and rate are required, with other default values.
Feel free to explore the functionalities and manage your car rental system efficiently!