#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

class Car {
public:
    Car(const std::string& make, const std::string& model, int year)
        : make(make), model(model), year(year), isDamaged(false) {}

    void SetDamage(bool damage) {
        isDamaged = damage;
    }

    bool IsDamaged() const {
        return isDamaged;
    }

    void Repair() {
        isDamaged = false;
    }

    void DisplayInfo() const {
        std::cout << "Make: " << make << ", Model: " << model << ", Year: " << year;
        if (isDamaged) {
            std::cout << " (Damaged)";
        }
        std::cout << std::endl;
    }

private:
    std::string make;
    std::string model;
    int year;
    bool isDamaged;
};

class CarRepairGame {
public:
    CarRepairGame() {
        cars.push_back(Car("Toyota", "Camry", 2020));
        cars.push_back(Car("Honda", "Civic", 2019));
        cars.push_back(Car("Ford", "Focus", 2018));
        cars.push_back(Car("Chevrolet", "Malibu", 2021));
        cars.push_back(Car("Nissan", "Altima", 2022));
        cars.push_back(Car("Hyundai", "Elantra", 2017));
        cars.push_back(Car("Kia", "Optima", 2020));
        cars.push_back(Car("Mazda", "3", 2022));
        cars.push_back(Car("Subaru", "Impreza", 2019));
        cars.push_back(Car("Volkswagen", "Jetta", 2021));
        cars.push_back(Car("BMW", "3 Series", 2022));
        cars.push_back(Car("Mercedes-Benz", "C-Class", 2020));
        cars.push_back(Car("Audi", "A4", 2019));
        cars.push_back(Car("Lexus", "ES", 2021));
        cars.push_back(Car("Tesla", "Model 3", 2022));
    }
    void Run() {
        srand(static_cast<unsigned int>(time(nullptr)));
        while (true) {
            ClearConsole();
            DisplayMenu();
            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    ListCars();
                    PauseAndClear();
                    break;
                case 2:
                    TalkToCustomer();
                    PauseAndClear();
                    break;
                case 3:
                    RepairCar();
                    IntroduceRandomDefects(); // Rastgele arıza ekleme
                    PauseAndClear();
                    break;
                case 4:
                    AddCar(); // Araba ekleme
                    PauseAndClear();
                    break;
                case 5:
                    return;
                default:
                    std::cout << "Invalid choice. Please select a valid option." << std::endl;
                    PauseAndClear();
                    break;
            }
        }
    }

private:
    std::vector<Car> cars;
    std::vector<std::string> customers = {
        "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Helen"
    };

    void SellCar() {
        ListCars();
        std::cout << "Select the index of the car to sell: ";
        int index;
        std::cin >> index;

        if (index >= 0 && index < cars.size()) {
            cars.erase(cars.begin() + index);
            std::cout << "Car sold successfully." << std::endl;
        }
        else {
            std::cout << "Invalid car index." << std::endl;
        }
    }

    void DisplayMenu() const {
        std::cout << "Car Repair Shop" << std::endl;
        std::cout << "1. List Cars" << std::endl;
        std::cout << "2. Talk to Customer" << std::endl;
        std::cout << "3. Repair Car" << std::endl;
        std::cout << "4. Add Car" << std::endl;
        std::cout << "5. Sell Car" << std::endl; // Yeni seçenek eklendi
        std::cout << "6. Quit" << std::endl;
        std::cout << "Select an option: ";
    }

    void Runs() {
        srand(static_cast<unsigned int>(time(nullptr)));
        while (true) {
            ClearConsole();
            DisplayMenu();
            int choice;
            std::cin >> choice;

            switch (choice) {
            case 1:
                ListCars();
                PauseAndClear();
                break;
            case 2:
                TalkToCustomer();
                PauseAndClear();
                break;
            case 3:
                RepairCar();
                IntroduceRandomDefects();
                PauseAndClear();
                break;
            case 4:
                AddCar();
                PauseAndClear();
                break;
            case 5:
                SellCar();
                PauseAndClear();
                break;
            case 6:
                return;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
                PauseAndClear();
                break;
            }
        }
    }

    void ListCars() const {
        if (cars.empty()) {
            std::cout << "No cars available." << std::endl;
        }
        else {
            std::cout << "Available Cars:" << std::endl;
            for (size_t i = 0; i < cars.size(); ++i) {
                std::cout << i << ". ";
                cars[i].DisplayInfo();
            }
        }
    }

    void TalkToCustomer() {
        if (customers.empty()) {
            std::cout << "No customers available." << std::endl;
            return;
        }

        std::cout << "Available Customers:" << std::endl;
        for (size_t i = 0; i < customers.size(); ++i) {
            std::cout << i << ". " << customers[i] << std::endl;
        }

        std::cout << "Select the index of the customer to talk to: ";
        int index;
        std::cin >> index;

        if (index >= 0 && index < customers.size()) {
            std::cout << "Customer " << customers[index] << ": ";
            if (rand() % 100 < 15) {
                std::cout << "You've been scammed by the customer!" << std::endl;
            }
            else {
                std::cout << "No issues reported." << std::endl;
            }
        }
        else {
            std::cout << "Invalid customer index." << std::endl;
        }
    }

    void RepairCar() {
        ListCars();
        std::cout << "Select the index of the car to repair: ";
        int index;
        std::cin >> index;

        if (index >= 0 && index < cars.size()) {
            cars[index].Repair();
            std::cout << "Car repaired successfully." << std::endl;
        }
        else {
            std::cout << "Invalid car index." << std::endl;
        }
    }

    void IntroduceRandomDefects() {
        for (Car& car : cars) {
            if (rand() % 10 == 0) {
                car.SetDamage(true);
            }
        }
    }

    void AddCar() {
        std::string make, model;
        int year;

        std::cout << "Enter car make: ";
        std::cin.ignore();
        std::getline(std::cin, make);

        std::cout << "Enter car model: ";
        std::getline(std::cin, model);

        std::cout << "Enter car year: ";
        std::cin >> year;

        cars.push_back(Car(make, model, year));
        std::cout << "Car added successfully." << std::endl;
    }

    void ClearConsole() {
#ifdef _WIN32
        system("cls"); // Windows için temizleme komutu
#else
        system("clear"); // Linux/Unix için temizleme komutu
#endif
    }

    void PauseAndClear() {
        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        ClearConsole();
    }
};

int main() {
    CarRepairGame game;
    game.Run();

    return 0;
}
