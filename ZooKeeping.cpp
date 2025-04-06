#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>

// --- Utility ---
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" ");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" ");
    return str.substr(first, last - first + 1);
}

// --- Base Class ---
class BaseAnimal {
public:
    std::string id, name, age, gender, birthSeason, color, weight, location;
    virtual void print() const = 0;
    virtual std::string getType() const = 0;
    virtual std::string getFormattedString() const = 0;
    virtual ~BaseAnimal() = default;
};

// --- Hyena ---
class Hyena : public BaseAnimal {
public:
    std::string getType() const override { return "Hyena"; }
    void print() const override {
        std::cout << getFormattedString();
    }
    std::string getFormattedString() const override {
        std::ostringstream oss;
        oss << "Hyena ID: " << id << "\n"
            << "Name: " << name << "\n"
            << "Age: " << age << "\n"
            << "Gender: " << gender << "\n"
            << "Birth Season: " << birthSeason << "\n"
            << "Color: " << color << "\n"
            << "Weight: " << weight << "\n"
            << "Location: " << location << "\n"
            << "-----------------------------\n";
        return oss.str();
    }
};

// --- Lion ---
class Lion : public BaseAnimal {
public:
    std::string getType() const override { return "Lion"; }
    void print() const override {
        std::cout << getFormattedString();
    }
    std::string getFormattedString() const override {
        std::ostringstream oss;
        oss << "Lion ID: " << id << "\n"
            << "Name: " << name << "\n"
            << "Age: " << age << "\n"
            << "Gender: " << gender << "\n"
            << "Birth Season: " << birthSeason << "\n"
            << "Color: " << color << "\n"
            << "Weight: " << weight << "\n"
            << "Location: " << location << "\n"
            << "-----------------------------\n";
        return oss.str();
    }
};

// --- Tiger ---
class Tiger : public BaseAnimal {
public:
    std::string getType() const override { return "Tiger"; }
    void print() const override {
        std::cout << getFormattedString();
    }
    std::string getFormattedString() const override {
        std::ostringstream oss;
        oss << "Tiger ID: " << id << "\n"
            << "Name: " << name << "\n"
            << "Age: " << age << "\n"
            << "Gender: " << gender << "\n"
            << "Birth Season: " << birthSeason << "\n"
            << "Color: " << color << "\n"
            << "Weight: " << weight << "\n"
            << "Location: " << location << "\n"
            << "-----------------------------\n";
        return oss.str();
    }
};

// --- Bear ---
class Bear : public BaseAnimal {
public:
    std::string getType() const override { return "Bear"; }
    void print() const override {
        std::cout << getFormattedString();
    }
    std::string getFormattedString() const override {
        std::ostringstream oss;
        oss << "Bear ID: " << id << "\n"
            << "Name: " << name << "\n"
            << "Age: " << age << "\n"
            << "Gender: " << gender << "\n"
            << "Birth Season: " << birthSeason << "\n"
            << "Color: " << color << "\n"
            << "Weight: " << weight << "\n"
            << "Location: " << location << "\n"
            << "-----------------------------\n";
        return oss.str();
    }
};

// --- Parser ---
std::shared_ptr<BaseAnimal> parseLine(const std::string& line, const std::string& type) {
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;
    while (std::getline(ss, token, ',')) tokens.push_back(trim(token));

    std::shared_ptr<BaseAnimal> animal;
    if (type == "Hyena") animal = std::make_shared<Hyena>();
    else if (type == "Lion") animal = std::make_shared<Lion>();
    else if (type == "Tiger") animal = std::make_shared<Tiger>();
    else if (type == "Bear") animal = std::make_shared<Bear>();
    else return nullptr;

    if (tokens.size() < 8) return nullptr;
    animal->id = tokens[0];
    animal->name = tokens[1];
    animal->age = tokens[2];
    animal->gender = tokens[3];
    animal->birthSeason = tokens[4];
    animal->color = tokens[5];
    animal->weight = tokens[6];
    animal->location = tokens[7];

    return animal;
}

// --- Main ---
int main() {
    std::vector<std::pair<std::string, std::string>> allData = {
        {"Hyena", "Hy01, Zig, 4 year old, female, born in spring, tan color, 70 pounds, from Friguia Park, Tunisia"},
        {"Hyena", "Hy02, Ed, 12 years old, male, born in fall, brown color, 150 pounds, from Friguia park, tunisia"},
        {"Hyena", "Hy03, Bud, 4 year old, male, born in spring, black color, 120 pounds, from Friguia Park, Tunisia"},
        {"Hyena", "Hy04, Shenzi, 8 year old, female , unknown birth season, black and tan striped color, 105 pounds, from Friguia Park, Tunisia"},

        {"Lion", "Ln01, Kiara, 6 year old, female, born in spring, tan color, 300 pounds, from Zanzibar, Tanzania"},
        {"Lion", "Ln02, Kimba, 12 year old, female, born in winter, dark tan color, 375 pounds, from KopeLion, Tanzania"},
        {"Lion", "Ln03, Scar, 22 year old, male, born in fall, golden color, 450 pounds, from Zanzibar, Tanzania"},
        {"Lion", "Ln04, Nala, 4 year old, female, born in spring, tan and brown color, 275 pounds, from KopeLion, Tanzania"},

        {"Tiger", "Tg01, Tony, 2 year old, male, born in spring, gold and tan stripes color, 270 pounds, from Dhaka, Bangladesh"},
        {"Tiger", "Tg02, Amber, 4 year old, female, born in spring, black stripes color, 400 pounds, from Dhaka, Bangladesh"},
        {"Tiger", "Tg03, Dave, 18 year old, male, born in fall, gold and tan color, 300 pounds, from Bardia, Nepal"},
        {"Tiger", "Tg04, Cuddles, 3 year old, female, born in spring, black stripes color, 285 pounds, from Bardia, Nepal"},

        {"Bear", "Br01, Yogi, 7 year old, male, born in spring, brown color, 320 pounds, from Alaska Zoo, Alaska"},
        {"Bear", "Br02, Bungle, 25 year old, female, born in spring, black color, 425 pounds, from Woodland park Zoo, Washington"},
        {"Bear", "Br03, Snuggles,4 year old, female, born in fall, black color, 355 pounds, from Woodland park Zoo, Washington"},
        {"Bear", "Br04, Paddington,4 year old, male, born in spring, brown color, 405 pounds, from Alaska Zoo, Alaska"}
    };

    std::vector<std::shared_ptr<BaseAnimal>> animals;
    for (const auto& [type, line] : allData) {
        auto animal = parseLine(line, type);
        if (animal) animals.push_back(animal);
    }

    std::sort(animals.begin(), animals.end(), [](const auto& a, const auto& b) {
        return a->id < b->id;
    });

    std::ofstream outFile("habitats.txt");
    if (!outFile) {
        std::cerr << "Error opening file for output.\n";
        return 1;
    }

    std::vector<std::string> printOrder = {"Hyena", "Lion", "Tiger", "Bear"};

    for (const std::string& type : printOrder) {
        std::cout << "\n=== " << type << " Habitat ===\n\n";
        outFile << "=== " << type << " Habitat ===\n\n";

        for (const auto& animal : animals) {
            if (animal->getType() == type) {
                animal->print();
                outFile << animal->getFormattedString();
            }
        }
    }

    outFile.close();
    return 0;
}
