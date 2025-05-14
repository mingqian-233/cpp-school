#include "zoo.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>


using namespace std;

// ===================== Money 类实现 =====================
Money::Money(float val) : amount(val) {}

Money::Money() : amount(0.0f) {}

Money Money::operator+(const Money& other) const {
    return Money(amount + other.amount);
}

Money Money::operator-(const Money& other) const {
    return Money(amount - other.amount);
}

Money Money::operator*(float multiplier) const {
    return Money(amount * multiplier);
}

Money Money::operator/(float divisor) const {
    if (divisor == 0) {
        throw runtime_error("Division by zero");
    }
    return Money(amount / divisor);
}

bool Money::operator<(const Money& other) const {
    return amount < other.amount;
}

bool Money::operator==(const Money& other) const {
    return abs(amount - other.amount) < 0.001f;  // 浮点数比较
}

string Money::toString() const {
    ostringstream oss;
    oss << "$" << fixed << setprecision(2) << amount;
    return oss.str();
}

float Money::getAmount() const {
    return amount;
}

// ===================== AnimalFood 类实现 =====================
AnimalFood::AnimalFood(FoodType t, int qty) : type(t), quantity(qty) {}

AnimalFood::AnimalFood() : type(PEANUTS), quantity(0) {}

FoodType AnimalFood::getType() const {
    return type;
}

int AnimalFood::getQuantity() const {
    return quantity;
}

void AnimalFood::reduceQuantity(int amount) {
    if (amount <= quantity) {
        quantity -= amount;
    } else {
        quantity = 0;
    }
}

bool AnimalFood::isEmpty() const {
    return quantity <= 0;
}

// ===================== Animal 类实现 =====================
Animal::Animal(string n, float w) : name(n), weight(w), foodEaten(0) {}

string Animal::getName() const {
    return name;
}

float Animal::getWeight() const {
    return weight;
}

void Animal::eat(int amount) {
    foodEaten += amount;
    // 若食物超过容量，则重置食物量
    if (foodEaten >= getFoodCapacity()) {
        foodEaten = 0;
    }
}

int Animal::getFoodEaten() const {
    return foodEaten;
}

// ===================== 具体动物类实现 =====================
// Elephant 实现
Elephant::Elephant(string n, float w, float tLength)
    : Animal(n, w), trunkLength(tLength) {}

FoodType Elephant::getPreferredFood() {
    return PEANUTS;
}

int Elephant::getFoodCapacity() {
    return 750;
}

// Giraffe 实现
Giraffe::Giraffe(string n, float w, float nLength)
    : Animal(n, w), neckLength(nLength) {}

FoodType Giraffe::getPreferredFood() {
    return CARROTS;
}

int Giraffe::getFoodCapacity() {
    return 500;
}

// Monkey 实现
Monkey::Monkey(string n, float w, float aLength)
    : Animal(n, w), armLength(aLength) {}

FoodType Monkey::getPreferredFood() {
    return BANANAS;
}

int Monkey::getFoodCapacity() {
    return 300;
}

// ===================== Person 类实现 =====================
Person::Person(string n, int a) : name(n), age(a) {}

string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

// ===================== ZooKeeper 类实现 =====================
ZooKeeper::ZooKeeper(string n, int a) : Person(n, a), cleaningDays(0) {}

void ZooKeeper::cleanEnclosure(AnimalEnclosure& enclosure) {
    enclosure.closeForCleaning();
    cleaningDays++;
    cout << "Zookeeper " << getName() << " cleaned the "
         << enclosure.getEnclosureTypeName() << " enclosure." << endl;
}

int ZooKeeper::getCleaningDays() const {
    return cleaningDays;
}

// ===================== FoodSeller 类实现 =====================
// 静态成员初始化
map<FoodType, float> FoodSeller::prices = {
    {PEANUTS, 0.2f},
    {CARROTS, 0.3f},
    {BANANAS, 0.5f}};

FoodSeller::FoodSeller(string n, int a) : Person(n, a),
                                          peanuts(PEANUTS, 10000),
                                          carrots(CARROTS, 7000),
                                          bananas(BANANAS, 4000),
                                          revenue(0.0f) {}

Money FoodSeller::sellFood(Adult& adult, FoodType type, int units) {
    AnimalFood* targetFood = nullptr;

    switch (type) {
    case PEANUTS:
        targetFood = &peanuts;
        break;
    case CARROTS:
        targetFood = &carrots;
        break;
    case BANANAS:
        targetFood = &bananas;
        break;
    }

    if (!targetFood) {
        return Money(0.0f);
    }

    // 确保不能卖出超过库存的食物
    int actualUnits = min(units, targetFood->getQuantity());
    if (actualUnits <= 0) {
        return Money(0.0f);
    }

    // 计算价格
    Money cost(actualUnits * prices[type]);

    // 更新库存和收入
    targetFood->reduceQuantity(actualUnits);
    revenue = revenue + cost;

    return cost;
}

bool FoodSeller::isFoodSoldOut() const {
    return peanuts.isEmpty() || carrots.isEmpty() || bananas.isEmpty();
}

string FoodSeller::getSoldOutFoodName() const {
    if (peanuts.isEmpty()) return "Peanuts";
    if (carrots.isEmpty()) return "Carrots";
    if (bananas.isEmpty()) return "Bananas";
    return "None";
}

Money FoodSeller::getRevenue() const {
    return revenue;
}

float FoodSeller::getPrice(FoodType type) {
    return prices[type];
}

int FoodSeller::getFoodAmount(FoodType type) const {
    switch (type) {
    case PEANUTS:
        return peanuts.getQuantity();
    case CARROTS:
        return carrots.getQuantity();
    case BANANAS:
        return bananas.getQuantity();
    default:
        return 0;
    }
}

// ===================== Visitor 类实现 =====================
int Visitor::nextID = 1;

Visitor::Visitor(string n, int a) : Person(n, a), passID(nextID++) {}

int Visitor::getPassID() const {
    return passID;
}

// ===================== Adult 类实现 =====================
Adult::Adult(string n, int a) : Visitor(n, a), budget(10.0f + static_cast<float>(rand() % 1001) / 100.0f) {}

Money Adult::getBudget() const {
    return budget;
}

Money Adult::buyTickets(int childCount) {
    Money cost(1.0f + 0.4f * childCount);

    if (budget.getAmount() >= cost.getAmount()) {
        budget = budget - cost;
        return cost;
    }

    return Money(0.0f);
}

void Adult::buyFood(FoodSeller& seller, vector<Child*>& children) {
    if (children.empty() || budget.getAmount() <= 0.0f) {
        return;
    }

    // 将预算均分为三份
    float budgetPerType = budget.getAmount() / 3.0f;

    // 购买三种食物
    int peanutUnits = static_cast<int>(budgetPerType / seller.getPrice(PEANUTS));
    int carrotUnits = static_cast<int>(budgetPerType / seller.getPrice(CARROTS));
    int bananaUnits = static_cast<int>(budgetPerType / seller.getPrice(BANANAS));

    // 扣钱并购买
    Money peanutCost = seller.sellFood(*this, PEANUTS, peanutUnits);
    Money carrotCost = seller.sellFood(*this, CARROTS, carrotUnits);
    Money bananaCost = seller.sellFood(*this, BANANAS, bananaUnits);

    // 更新预算
    budget = budget - peanutCost - carrotCost - bananaCost;

    // 获取实际购买的单位数
    peanutUnits = static_cast<int>(peanutCost.getAmount() / seller.getPrice(PEANUTS));
    carrotUnits = static_cast<int>(carrotCost.getAmount() / seller.getPrice(CARROTS));
    bananaUnits = static_cast<int>(bananaCost.getAmount() / seller.getPrice(BANANAS));

    // 将食物分配给孩子
    giveFood(children, peanutUnits, carrotUnits, bananaUnits);
}

void Adult::giveFood(vector<Child*>& children, int peanuts, int carrots, int bananas) {
    int childCount = children.size();
    if (childCount == 0) return;

    // 计算每个孩子分得的食物数量
    int peanutsPerChild = peanuts / childCount;
    int carrotsPerChild = carrots / childCount;
    int bananasPerChild = bananas / childCount;

    // 余数
    int peanutRemainder = peanuts % childCount;
    int carrotRemainder = carrots % childCount;
    int bananaRemainder = bananas % childCount;

    // 分配食物给每个孩子
    for (int i = 0; i < childCount; i++) {
        int extraPeanuts = (i < peanutRemainder) ? 1 : 0;
        int extraCarrots = (i < carrotRemainder) ? 1 : 0;
        int extraBananas = (i < bananaRemainder) ? 1 : 0;

        children[i]->receiveFood(
            peanutsPerChild + extraPeanuts,
            carrotsPerChild + extraCarrots,
            bananasPerChild + extraBananas);
    }
}

void Adult::feedAnimal(AnimalEnclosure& enclosure) {
    // 成人不喂食动物
}

// ===================== Child 类实现 =====================
Child::Child(string n, int a) : Visitor(n, a),
                                peanutsOwned(0),
                                carrotsOwned(0),
                                bananasOwned(0) {}

void Child::receiveFood(int peanuts, int carrots, int bananas) {
    peanutsOwned += peanuts;
    carrotsOwned += carrots;
    bananasOwned += bananas;
}

void Child::feedAnimal(AnimalEnclosure& enclosure) {
    if (!enclosure.isOpen) {
        return;  // 围栏关闭则不喂食
    }

    // 获取围栏内动物喜欢的食物类型
    FoodType preferredFood = PEANUTS;  // 默认值

    // 根据围栏类型确定动物喜欢的食物
    switch (enclosure.getEnclosureType()) {
    case ELEPHANT_ENCLOSURE:
        preferredFood = PEANUTS;
        break;
    case GIRAFFE_ENCLOSURE:
        preferredFood = CARROTS;
        break;
    case MONKEY_ENCLOSURE:
        preferredFood = BANANAS;
        break;
    }

    // 根据食物类型决定喂食数量
    int foodAmount = 0;
    switch (preferredFood) {
    case PEANUTS:
        foodAmount = min(peanutsOwned, 10);  // 最多喂10个单位
        peanutsOwned -= foodAmount;
        break;
    case CARROTS:
        foodAmount = min(carrotsOwned, 10);
        carrotsOwned -= foodAmount;
        break;
    case BANANAS:
        foodAmount = min(bananasOwned, 10);
        bananasOwned -= foodAmount;
        break;
    }

    // 如果有食物可喂，则喂食并增加围栏脏污度
    if (foodAmount > 0) {
        enclosure.addDirt(foodAmount);
        cout << getName() << " fed " << foodAmount << " units of food to animals in the "
             << enclosure.getEnclosureTypeName() << " enclosure." << endl;
    }
}

// ===================== AnimalEnclosure 类实现 =====================
AnimalEnclosure::AnimalEnclosure(AnimalType t) : type(t), dirtLevel(0), isOpen(true), daysClosed(0) {
    // 根据类型初始化动物数组
    switch (type) {
    case ELEPHANT_ENCLOSURE:
        animalCount = 1;
        animals = new Animal*[animalCount];
        animals[0] = new Elephant("Dumbo", 2000.0f, 1.5f);
        break;
    case GIRAFFE_ENCLOSURE:
        animalCount = 2;
        animals = new Animal*[animalCount];
        animals[0] = new Giraffe("Melman", 1200.0f, 2.8f);
        animals[1] = new Giraffe("Gerry", 1300.0f, 3.0f);
        break;
    case MONKEY_ENCLOSURE:
        animalCount = 3;
        animals = new Animal*[animalCount];
        animals[0] = new Monkey("Kong", 80.0f, 0.8f);
        animals[1] = new Monkey("Cheeks", 70.0f, 0.7f);
        animals[2] = new Monkey("Banana", 75.0f, 0.75f);
        break;
    default:
        animalCount = 0;
        animals = nullptr;
        break;
    }
}

AnimalEnclosure::~AnimalEnclosure() {
    // 释放动物对象内存
    for (int i = 0; i < animalCount; i++) {
        delete animals[i];
    }
    delete[] animals;
}

void AnimalEnclosure::addDirt(int units) {
    dirtLevel += units;
}

void AnimalEnclosure::closeForCleaning() {
    if (isOpen) {
        isOpen = false;
        dirtLevel = 0;
        daysClosed++;
    }
}

void AnimalEnclosure::reopen() {
    isOpen = true;
}

bool AnimalEnclosure::shouldClean() const {
    return dirtLevel > 2000;
}

string AnimalEnclosure::getEnclosureTypeName() const {
    switch (type) {
    case ELEPHANT_ENCLOSURE:
        return "Elephant";
    case GIRAFFE_ENCLOSURE:
        return "Giraffe";
    case MONKEY_ENCLOSURE:
        return "Monkey";
    default:
        return "Unknown";
    }
}

AnimalType AnimalEnclosure::getEnclosureType() const {
    return type;
}

int AnimalEnclosure::getDirtLevel() const {
    return dirtLevel;
}

int AnimalEnclosure::getDaysClosed() const {
    return daysClosed;
}

// ===================== Zoo 类实现 =====================
Zoo::Zoo() : openDays(0),
             totalRevenue(0.0f),
             exitReason(NONE) {
    // 创建围栏
    enclosures = new AnimalEnclosure*[3];
    enclosures[0] = new AnimalEnclosure(ELEPHANT_ENCLOSURE);
    enclosures[1] = new AnimalEnclosure(GIRAFFE_ENCLOSURE);
    enclosures[2] = new AnimalEnclosure(MONKEY_ENCLOSURE);

    // 创建工作人员
    keeper = new ZooKeeper("Bob", 35);
    seller = new FoodSeller("Alice", 28);
}

Zoo::~Zoo() {
    // 释放内存
    for (int i = 0; i < 3; i++) {
        delete enclosures[i];
    }
    delete[] enclosures;

    delete keeper;
    delete seller;

    // 释放访客内存
    for (auto visitor : visitors) {
        delete visitor;
    }
    visitors.clear();
}

void Zoo::simulateDay() {
    openDays++;
    cout << "\n===== Day " << openDays << " =====" << endl;

    // 清空昨天的访客
    for (auto visitor : visitors) {
        delete visitor;
    }
    visitors.clear();

    // 1. 生成今天的访客
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> adultDistribution(20, 40);
    uniform_int_distribution<> childDistribution(1, 3);

    int adultCount = adultDistribution(gen);

    // 创建成人访客
    vector<Adult*> adults;
    for (int i = 0; i < adultCount; i++) {
        string name = "Adult" + to_string(i + 1);
        Adult* adult = new Adult(name, 25 + rand() % 30);
        adults.push_back(adult);
        visitors.push_back(adult);

        // 每个成人带1-3个孩子
        int childCount = childDistribution(gen);
        vector<Child*> children;

        for (int j = 0; j < childCount; j++) {
            string childName = "Child" + to_string(i + 1) + "-" + to_string(j + 1);
            Child* child = new Child(childName, 5 + rand() % 10);
            children.push_back(child);
            visitors.push_back(child);
        }

        // 2. 成人购票
        Money ticketCost = adult->buyTickets(childCount);
        totalRevenue = totalRevenue + ticketCost;

        // 3. 成人购买食物并分配给孩子
        adult->buyFood(*seller, children);
    }

    // 4. 孩子喂食动物
    for (auto visitor : visitors) {
        Child* child = dynamic_cast<Child*>(visitor);
        if (child) {
            // 随机选择一个围栏喂食
            int enclosureIndex = rand() % 3;
            child->feedAnimal(*enclosures[enclosureIndex]);
        }
    }

    // 5. 检查围栏状态并清洁
    bool keeperCleanedToday = false;
    for (int i = 0; i < 3; i++) {
        if (enclosures[i]->shouldClean() && !keeperCleanedToday) {
            keeper->cleanEnclosure(*enclosures[i]);
            keeperCleanedToday = true;
        } else if (!enclosures[i]->isOpen) {
            // 如果围栏已关闭，则重新开放
            enclosures[i]->reopen();
        }
    }

    // 6. 打印当天状态
    cout << "Visitors today: " << visitors.size() << " ("
         << adults.size() << " adults, "
         << visitors.size() - adults.size() << " children)" << endl;

    cout << "Food remaining: Peanuts=" << seller->getFoodAmount(PEANUTS)
         << ", Carrots=" << seller->getFoodAmount(CARROTS)
         << ", Bananas=" << seller->getFoodAmount(BANANAS) << endl;

    cout << "Zoo revenue today: " << totalRevenue.toString() << endl;

    // 检查终止条件
    checkTerminationConditions();
}

void Zoo::runSimulation() {
    while (exitReason == NONE) {
        simulateDay();
    }

    // 打印总结
    printSummary();
}

void Zoo::checkTerminationConditions() {
    // 检查食物是否售罄
    if (seller->isFoodSoldOut()) {
        exitReason = FOOD_SOLD_OUT;
        cout << "\nSIMULATION ENDED: " << seller->getSoldOutFoodName() << " has been sold out." << endl;
    }

    // 检查饲养员是否辞职
    if (keeper->getCleaningDays() >= 10) {
        exitReason = KEEPER_QUIT;
        cout << "\nSIMULATION ENDED: Zookeeper " << keeper->getName()
             << " has quit after cleaning for " << keeper->getCleaningDays() << " days." << endl;
    }
}

void Zoo::printSummary() {
    cout << "\n====== Zoo Simulation Summary ======" << endl;
    cout << "Days operated: " << openDays << endl;

    cout << "Exit reason: ";
    switch (exitReason) {
    case FOOD_SOLD_OUT:
        cout << "Food sold out (" << seller->getSoldOutFoodName() << ")" << endl;
        break;
    case KEEPER_QUIT:
        cout << "Zookeeper quit after " << keeper->getCleaningDays() << " cleaning days" << endl;
        break;
    default:
        cout << "Unknown" << endl;
    }

    cout << "Total revenue: " << totalRevenue.toString() << endl;
    cout << "Food seller revenue: " << seller->getRevenue().toString() << endl;

    cout << "Enclosure status:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  " << enclosures[i]->getEnclosureTypeName()
             << " enclosure was closed for " << enclosures[i]->getDaysClosed() << " days." << endl;
    }
}
