#ifndef ZOO_H
#define ZOO_H

#include <map>
#include <string>
#include <vector>


// 枚举定义
enum FoodType {
    PEANUTS,
    CARROTS,
    BANANAS
};

enum AnimalType {
    ELEPHANT_ENCLOSURE,
    GIRAFFE_ENCLOSURE,
    MONKEY_ENCLOSURE
};

enum ExitReason {
    NONE,
    FOOD_SOLD_OUT,
    KEEPER_QUIT
};

// 前向声明
class Animal;
class AnimalEnclosure;
class Visitor;
class Adult;
class Child;

// ===================== Money 类 =====================
class Money {
private:
    float amount;

public:
    Money(float val);
    Money();

    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    Money operator*(float multiplier) const;
    Money operator/(float divisor) const;
    bool operator<(const Money& other) const;
    bool operator==(const Money& other) const;

    std::string toString() const;
    float getAmount() const;
};

// ===================== AnimalFood 类 =====================
class AnimalFood {
private:
    FoodType type;
    int quantity;

public:
    AnimalFood(FoodType t, int qty);
    AnimalFood();

    FoodType getType() const;
    int getQuantity() const;
    void reduceQuantity(int amount);
    bool isEmpty() const;
};

// ===================== Animal 类 (抽象基类) =====================
class Animal {
private:
    std::string name;
    float weight;
    int foodEaten;

public:
    Animal(std::string n, float w);
    virtual ~Animal() {}

    std::string getName() const;
    float getWeight() const;
    void eat(int amount);
    int getFoodEaten() const;

    // 纯虚函数
    virtual FoodType getPreferredFood() = 0;
    virtual int getFoodCapacity() = 0;
};

// ===================== Elephant 类 =====================
class Elephant : public Animal {
private:
    float trunkLength;

public:
    Elephant(std::string n, float w, float tLength);

    FoodType getPreferredFood() override;
    int getFoodCapacity() override;
};

// ===================== Giraffe 类 =====================
class Giraffe : public Animal {
private:
    float neckLength;

public:
    Giraffe(std::string n, float w, float nLength);

    FoodType getPreferredFood() override;
    int getFoodCapacity() override;
};

// ===================== Monkey 类 =====================
class Monkey : public Animal {
private:
    float armLength;

public:
    Monkey(std::string n, float w, float aLength);

    FoodType getPreferredFood() override;
    int getFoodCapacity() override;
};

// ===================== Person 类 (抽象基类) =====================
class Person {
private:
    std::string name;
    int age;

public:
    Person(std::string n, int a);
    virtual ~Person() {}

    std::string getName() const;
    int getAge() const;
};

// ===================== ZooKeeper 类 =====================
class ZooKeeper : public Person {
private:
    int cleaningDays;

public:
    ZooKeeper(std::string n, int a);

    void cleanEnclosure(AnimalEnclosure& enclosure);
    int getCleaningDays() const;
};

// ===================== FoodSeller 类 =====================
class FoodSeller : public Person {
private:
    AnimalFood peanuts;
    AnimalFood carrots;
    AnimalFood bananas;
    Money revenue;

    static std::map<FoodType, float> prices;

public:
    FoodSeller(std::string n, int a);

    Money sellFood(Adult& adult, FoodType type, int units);
    bool isFoodSoldOut() const;
    std::string getSoldOutFoodName() const;
    Money getRevenue() const;
    int getFoodAmount(FoodType type) const;

    static float getPrice(FoodType type);
};

// ===================== Visitor 类 (抽象基类) =====================
class Visitor : public Person {
private:
    int passID;
    static int nextID;

public:
    Visitor(std::string n, int a);
    virtual ~Visitor() {}

    int getPassID() const;
    virtual void feedAnimal(AnimalEnclosure& enclosure) = 0;
};

// ===================== Adult 类 =====================
class Adult : public Visitor {
private:
    Money budget;

public:
    Adult(std::string n, int a);

    Money getBudget() const;
    Money buyTickets(int childCount);
    void buyFood(FoodSeller& seller, std::vector<Child*>& children);
    void giveFood(std::vector<Child*>& children, int peanuts, int carrots, int bananas);
    void feedAnimal(AnimalEnclosure& enclosure) override;
};

// ===================== Child 类 =====================
class Child : public Visitor {
private:
    int peanutsOwned;
    int carrotsOwned;
    int bananasOwned;

public:
    Child(std::string n, int a);

    void receiveFood(int peanuts, int carrots, int bananas);
    void feedAnimal(AnimalEnclosure& enclosure) override;
};

// ===================== AnimalEnclosure 类 =====================
class AnimalEnclosure {
private:
    Animal** animals;
    int animalCount;
    AnimalType type;
    int dirtLevel;
    int daysClosed;

public:
    bool isOpen;  // 公开变量，以便Child类可以直接访问

    AnimalEnclosure(AnimalType t);
    ~AnimalEnclosure();

    void addDirt(int units);
    void closeForCleaning();
    void reopen();
    bool shouldClean() const;
    std::string getEnclosureTypeName() const;
    AnimalType getEnclosureType() const;
    int getDirtLevel() const;
    int getDaysClosed() const;
};

// ===================== Zoo 类 =====================
class Zoo {
private:
    AnimalEnclosure** enclosures;  // 动物围栏数组
    ZooKeeper* keeper;  // 饲养员
    FoodSeller* seller;  // 食物售卖员
    std::vector<Visitor*> visitors;  // 访客列表
    int openDays;  // 开放天数
    Money totalRevenue;  // 总收入
    ExitReason exitReason;  // 退出原因

public:
    Zoo();
    ~Zoo();

    void simulateDay();
    void runSimulation();
    void checkTerminationConditions();
    void printSummary();
};

#endif  // ZOO_H
