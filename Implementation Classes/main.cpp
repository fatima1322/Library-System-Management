// main.cpp
#include <iostream>
#include "IDGenerator.h"
#include "NotificationManager.h"
#include "Validator.h"
#include "Book.h"
#include "Student.h"
#include "LibraryStats.h"
#include "LoanReservation.h"


int main() {
    IDGenerator idGen;

    std::string newResID = idGen.generateResourceID();
    std::string newUserID = idGen.generateUserID();

    std::cout << "Generated Resource ID: " << newResID << std::endl;
    std::cout << "Generated User ID: " << newUserID << std::endl;

    auto book = std::make_shared<Book>("Data Structures", "Mark Allen", 2015, newResID, "978-1234567890", "Pearson");
    auto user = std::make_shared<Student>("Naima", newUserID, "naima@ensia.dz", "Level1", "IT", "CS");

    std::cout << "Valid Resource? " << (Validator::validateResource(book) ? "Yes" : "No") << std::endl;
    std::cout << "Valid User? " << (Validator::validateUser(user) ? "Yes" : "No") << std::endl;

    NotificationManager::send(user->getUserID(), "Welcome to the ENSIA Library!");
    NotificationManager::notifyReservationAvailable(book->getResourceID(), user->getUserID());
    NotificationManager::notifyOverdue(user->getUserID(), book->getResourceID(), 3);


    std::vector<std::shared_ptr<Resource>> resources;
    resources.push_back(std::make_shared<Book>("C++ Guide", "Bjarne", 2011, "RES1", "12345", "Addison"));
    resources.push_back(std::make_shared<Book>("OOP Design", "Grady", 2010, "RES2", "67890", "Pearson", false));

    std::vector<std::shared_ptr<User>> users;
    users.push_back(std::make_shared<Student>("Alice", "user1", "alice@example.com", "Level1", "IT", "CS"));

    std::vector<std::shared_ptr<Loan>> loans;
    std::vector<std::shared_ptr<Reservation>> reservations;

    std::cout << "Total Resources: " << LibraryStats::getTotalResources(resources) << std::endl;
    std::cout << "Available Resources: " << LibraryStats::getAvailableResources(resources) << std::endl;
    std::cout << "Total Users: " << LibraryStats::getTotalUsers(users) << std::endl;
    
    return 0;

}


