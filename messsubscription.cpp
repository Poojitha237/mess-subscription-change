#include <iostream>
#include <string>
#include <unordered_map>

class Hostel {
private:
    std::unordered_map<std::string, std::string> residentMap;  // Map to store residents and their current hostels

public:
    // Constructor to initialize the hostel
    Hostel() {}

    // Method to add a resident to the hostel
    void addResident(const std::string& residentName) {
        residentMap[residentName] = "DefaultHostel";
    }

    // Method to change the hostel for a resident
    void changeHostel(const std::string& residentName, const std::string& newHostel) {
        auto it = residentMap.find(residentName);
        if (it != residentMap.end()) {
            std::cout << "Moving " << residentName << " from " << it->second << " to " << newHostel << " for the current month.\n";
            it->second = newHostel;
        } else {
            std::cout << "Resident " << residentName << " not found.\n";
        }
    }

    // Method to get the current hostel for a resident
    std::string getCurrentHostel(const std::string& residentName) const {
        auto it = residentMap.find(residentName);
        if (it != residentMap.end()) {
            return it->second;
        } else {
            std::cout << "Resident " << residentName << " not found.\n";
            return "NotFound";  // Default value if resident not found
        }
    }

    // Method to print residents in the hostel
    void printResidents() const {
        std::cout << "Residents in this hostel:\n";
        for (const auto& entry : residentMap) {
            std::cout << entry.first << " - " << entry.second << std::endl;
        }
    }
};

class HostelManager {
private:
    std::unordered_map<std::string, Hostel> hostelMap;  // Map to store hostels by name

public:
    // Method to add a hostel to the manager
    void addHostel(const std::string& hostelName) {
        hostelMap[hostelName] = Hostel();
    }

    // Method to add a resident to a specific hostel
    void addResident(const std::string& hostelName, const std::string& residentName) {
        if (hostelMap.find(hostelName) != hostelMap.end()) {
            hostelMap[hostelName].addResident(residentName);
        } else {
            std::cout << "Hostel " << hostelName << " not found.\n";
        }
    }

    // Method to change the hostel for a resident in a specific hostel
    void changeHostel(const std::string& sourceHostel, const std::string& destinationHostel, const std::string& residentName) {
        if (hostelMap.find(sourceHostel) != hostelMap.end() && hostelMap.find(destinationHostel) != hostelMap.end()) {
            std::string currentHostel = hostelMap[sourceHostel].getCurrentHostel(residentName);
            if (currentHostel != "NotFound") {
                hostelMap[sourceHostel].changeHostel(residentName, destinationHostel);
                std::cout << "Successfully moved " << residentName << " from " << sourceHostel << " to " << destinationHostel << " for the current month.\n";
            } else {
                std::cout << "Resident " << residentName << " not found in " << sourceHostel << ".\n";
            }
        } else {
            std::cout << "Either source hostel " << sourceHostel << " or destination hostel " << destinationHostel << " not found.\n";
        }
    }

    // Method to print residents in each hostel
    void printAllResidents() const {
        std::cout << "Residents in all hostels:\n";
        for (const auto& entry : hostelMap) {
            std::cout << "Hostel: " << entry.first << std::endl;
            entry.second.printResidents();
            std::cout << "----------------------\n";
        }
    }
};

int main() {
    HostelManager hostelManager;

    // Adding hostels
    hostelManager.addHostel("Brahma");
    hostelManager.addHostel("Disang");

    // Adding residents to hostels
    hostelManager.addResident("Brahma", "poojitha");
    hostelManager.addResident("Brahma", "ajay");
    hostelManager.addResident("Brahma", "arun");
    hostelManager.addResident("Disang", "Jane Smith");
    hostelManager.addResident("Brahma", "deepika");

    // Changing hostels for residents
    hostelManager.changeHostel("Brahma", "Disang", "poojitha");


    // Printing residents in each hostel
    hostelManager.printAllResidents();

    return 0;
}