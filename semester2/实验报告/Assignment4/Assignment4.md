# 第四次实验报告

这个任务是一个面向对象编程（C++）的综合模拟题，模拟的是一个虚拟动物园的日常运营。我们需要实现类的继承体系、封装与多态，以及模拟一个动物园每天的活动。由于任务非常复杂，所以先对任务的详细**整理、解释与实现规划**：

---

## 一、**总体目标**

- 使用 C++ 创建一套完整的面向对象系统，模拟动物园每天的运营。
- 使用封装、继承、多态等面向对象设计原则。
- 实现类结构、成员函数、模拟逻辑、状态管理与终止条件。

### **注意事项**

1. 使用三文件架构，包含：`zoo.h`, `zoo.cpp`, `main.cpp`。
2. 题目已给出的数据

**动物食物数据**

| Animal Food | Starting Amount | Price (per unit) |
| ----------- | --------------- | ---------------- |
| Peanuts     | 10,000          | 20 cents         |
| Carrots     | 7,000           | 30 cents         |
| Bananas     | 4,000           | 50 cents         |

**每种动物的食物容量**(指动物在进食多少食物后会造成脏乱)

| Each Animal | Food Capacity (units of food) |
| ----------- | ----------------------------- |
| Elephant    | 750                           |
| Giraffe     | 500                           |
| Monkey      | 300                           |

3. 评分要求中会扣分的情况：
   (a) 内存泄漏。(b) 缺少缩进。(c) 缺少注释。(d) 变量或函数命名不当。(e) 访问修饰符使用不当。(f) 声明和/或实现放置不当（例如全部放在 Main.cpp 中）。

---

## 二、**类设计（包含成员与职责）**

为了让设计更加合理和全面，我们需要考虑每个类的成员和方法，结合真实世界的动物园管理需求，进一步扩展和改进设计。

### **1. Zoo 类 (动物园)**

动物园不仅仅是一个简单的管理者，还应该能协调不同类型的动物、工作人员和游客的交互，支持复杂的模拟。

#### 成员变量：

- **动物围栏：** 存储各个动物的围栏状态，可以使用一个**数组或列表**来管理所有围栏。
  - `AnimalEnclosure[] enclosures;` —— 存储每个动物的围栏。
- **工作人员：** 饲养员和售卖员。
  - `ZooKeeper keeper;`
  - `FoodSeller seller;`
- **访客：** 动物园的访客信息，包括成人和儿童的数量，游玩数据等。
  - `Visitor[] visitors;`
- **动物数据：** 存储所有动物（每种动物至少有一个实例）。
  - `Animal[] animals;`
- **动物园状态：** 用于统计信息，如动物园开放时长（模拟的天数上限）、当前营业收入等。
  - `int openDays;`
  - `Money totalRevenue;`

#### 方法：

- **simulateDay()：** 模拟动物园的一天活动。
  - 随机生成访客（成人和儿童）。
  - 成人购买通行证和食物。
  - 儿童喂食动物，检查动物的围栏脏乱程度。
  - 检查并更新围栏的状态（是否需要清洁）。
  - 记录每日收入和动物园运行的其他统计数据。
- **runSimulation()：** 启动模拟并逐天运行，直到某个终止条件（如饲养员辞职、食物用完或者达到模拟上限）。
- **displayStatistics()：** 在模拟结束后输出动物园的运行统计信息，包括总收入、访客数量、动物园闭馆原因等。

---

### **2. Money 类 (金钱)**

`Money` 类不仅仅是一个简单的货币表示，还可以加入**更精确的处理**，如金钱格式化、货币计算等。
因为浮点数表示金钱会造成精度损失，所以必须使用类、字符串和高精度等方法处理。

#### 成员变量：

- `string amount;` —— 存储金钱金额。

#### 方法：

- **重载运算符：** `+`、`-`、`*`、`/` 等，允许金钱与金钱之间的运算。
- **formatMoney()：** 格式化金额为标准的“$xx.xx”格式。
- **重载输出流运算符**：
  - `<<` 用于输出金钱。

---

### **3. AnimalFood 类 (动物食物)**

动物的食物不仅要记录类型和数量，还要考虑食物的**购买价格**、**库存管理**等问题。

#### 成员变量：

- `FoodType type;` —— 食物类型（例如：Peanut, Carrot, Banana）。
- `int quantity;` —— 当前食物的数量。
- `float price;` —— 食物的单价。

#### 方法：

- **useFood(int amount):** 使用食物，并减少库存。
- **checkAvailability():** 检查食物是否有足够库存。
- **getFoodCost():** 返回该种食物的总花费（即数量 \* 单价）。

---

### **4. AnimalEnclosure 类 (动物围栏)**

动物围栏的管理不仅包括脏乱程度，还要考虑**围栏的开启与关闭**、**动物的状态**（是否正在喂食），以及**清洁管理**。

#### 成员变量：

- `int dirtLevel;` —— 围栏的脏乱程度。
- `bool isOpen;` —— 围栏是否对访客开放。
- `int daysClosed;` —— 围栏关闭的天数。
- `Animal[] animals;` —— 与该围栏相关的动物实例。
- `string enclosureName;` —— 围栏的名称（例如："Elephant Enclosure"）。

#### 方法：

- **addDirt(int amount):** 增加围栏的脏乱程度。
- **clean():** 清洁围栏，重置脏乱程度。
- **shouldClose():** 判断围栏是否需要关闭清洁（如果脏乱程度超过阈值）。
- **openEnclosure():** 开启围栏，允许游客进入。
- **closeEnclosure():** 关闭围栏，停止游客进入。

---

### **5. Animal 类 (动物)**

动物类不仅仅包含体重和食量，还可以加入动物的健康状况、动物是否活跃、是否喂食等其他信息。

#### 成员变量：

- `float weight;` —— 动物体重。
- `int foodEaten;` —— 动物吃的食物总量。
- `bool isActive;` —— 动物是否活跃。
- `string name;` —— 动物的名字。

#### 方法：

- **eatFood(int amount):** 虚函数，喂食动物并更新食物数量，增加脏乱程度。不同的动物吃不同的食物。运行时输出动物种类、动物名字以及使用的食物种类、食物量。
- **getPreferredFood():** 虚函数，返回动物喜欢的食物类型。
- **getHealthStatus():** 返回动物的健康状态（例如：是否生病）。
- **resetFoodEaten():** 重置食量（用于清理时）。
- **makeSound():** 虚函数，让动物发出叫声。在子类中需要个性化定义。
- **move():** 虚函数，实现动物的移动。如，大象和长颈鹿是走(walk)的，猴子是爬(climb)的。实际实现的时候输出字符串，例如：`Xixi（动物名） is climbing towards you!`

---

## **6. Elephant 类 (大象)**

**意义：** `Elephant` 类继承自 `Animal` 类，表示大象。它具有特有的属性和行为（如象鼻长度）。

#### 成员变量：
- `float trunkLength;` —— 象鼻的长度。

#### 方法：
- **getPreferredFood():** 返回大象喜欢的食物类型（ `Peanut`）。
- **resetFoodEaten():** 重写 `Animal` 类中的方法，适应大象的食量重置。

---

## **7. Giraffe 类 (长颈鹿)**

**意义：** `Giraffe` 类继承自 `Animal` 类，表示长颈鹿。它具有特有的属性（如脖长）。

#### 成员变量：
- `float neckLength;` —— 长颈鹿的脖子长度。

#### 方法：
- **getPreferredFood():** 返回长颈鹿喜欢的食物类型（例如 `Carrot`）。
- **resetFoodEaten():** 重写 `Animal` 类中的方法，适应长颈鹿的食量重置。

---

## **8. Monkey 类 (猴子)**

**意义：** `Monkey` 类继承自 `Animal` 类，表示猴子。它具有特有的属性（如手臂长度）。

#### 成员变量：
- `float armLength;` —— 猴子的手臂长度。

#### 方法：
- **getPreferredFood():** 返回猴子喜欢的食物类型（例如 `Banana`）。
- **resetFoodEaten():** 重写 `Animal` 类中的方法，适应猴子的食量重置。

---


### **9. Person 类 (人员)**

人员类（如饲养员、售卖员、访客）不仅包含基础的姓名和年龄，还需要记录他们的工作或角色状态。

#### 成员变量：

- `string name;` —— 姓名。
- `int age;` —— 年龄。
- `string role;` —— 角色（例如："ZooKeeper", "FoodSeller", "Visitor"）。

#### 方法：

- **getRole():** 获取当前人员的角色（如"ZooKeeper"）。
- **updateStatus():** 更新人员状态，例如售卖员卖出了食物，或者饲养员完成了清洁任务。

---

### **10. Visitor 类 (游客)**

游客类需要记录每个游客的访问信息，游客的购买行为和喂食行为。

#### 成员变量：

- `int passID;` —— 访客通行证 ID。
- `Money wallet;` —— 游客的钱包，用于购买食物和票。
- `int numChildren;` —— 陪伴的儿童数量。

#### 方法：

- **buyTicket():** 购买通行证（成人 1 美元，儿童 0.4 美元）。
- **buyFood():** 购买食物并更新钱包。
- **feedAnimals():** 让孩子喂动物。自己不能喂。

---

### **11. ZooKeeper 类 (饲养员)**

饲养员不仅仅负责清洁，还应有**动物的健康管理**等功能。

#### 成员变量：

- `int cleaningDays;` —— 清洁天数。
- `int maxCleaning;` —— 最大清洁次数（例如：清洁 20 次后辞职）。

#### 方法：

- **cleanEnclosure(AnimalEnclosure& enclosure):** 清洁围栏。
- **inspectAnimals():** 检查动物健康状况，记录健康数据。

---

### **12. FoodSeller 类 (售卖员)**

售卖员除了卖食物，还需要记录**食物价格**、**收入**、**库存**等管理信息。

#### 成员变量：

- `int peanutsStock, carrotsStock, bananasStock;` —— 各种食物的库存。
- `Money revenue;` —— 销售收入。
- `map<FoodType, float> foodPrices;` —— 食物的价格表。

#### 方法：

- **sellFood(Money amount, FoodType type):** 销售食物，减少库存。
- **checkStock():** 检查是否有足够的食物。

---

## 三、模拟逻辑规划（Zoo::simulateDay）

### 生成访客

- 成人：随机 20–40
- 每个成人带 1–3 个儿童
- 成人预算金钱：10–20 美元（随机）

### 售票 + 买食物

- 成人买通行证（1 美元/成人，0.4 美元/儿童）
- 剩余的钱按照相同比例买`$正在开放的围栏数$`种食物。如果围栏关闭，那么不买。
- 售卖员更新库存与收入
- 食物均匀分配给儿童

### 动物喂食

- 儿童对动物喂食（前提是围栏是开启状态）
- 动物吃食物、脏乱度累加
- 超出阈值 → 围栏变脏，食量重置

### 清洁管理

- 饲养员检查围栏
- 若脏乱度 > 2000 → 关闭围栏进行清洁
- 动物会随机生病，生病的概率由脏乱度决定，越高越容易生病。如果生病就要显示`（动物名）生病了！`。生病的动物会在一周之后自行好转，好转的信息也要输出。
- 饲养员清洁次数+1；超过 10 次则辞职

### 终止条件检查

- 模拟时间达到上限
- 或 饲养员辞职
- 或 某种食物完全用完

---

## 四、模拟结果统计

- 总共营业了多少天
- 关闭原因（时间达到上限 / 饲养员辞职/ 食物用完）
- 总成人数、儿童数
- 售卖员总收入
- 饲养员清洁天数
- 每个围栏关闭了几天
- 动物的生病情况（包含名字、种类、生病的日期等信息）

---

## 五、建议结构拆分

- `zoo.h`: 包含所有类声明与接口
- `zoo.cpp`: 类函数实现、模拟逻辑、main 函数

---

## 六、反思及对比

在本项目中，若不使用面向对象编程（OOP），将会面临以下问题：

1. **功能堆叠**：所有数据和逻辑只能靠全局变量与函数组合，缺乏封装，导致各模块耦合严重。
2. **扩展困难**：新增一种动物、一个角色或功能时，往往需要重写多个函数逻辑而非继承或覆盖。
3. **维护困难**：围栏、动物、食物等行为没有统一抽象，导致代码冗长重复，极易出错。
4. **缺乏多态**：无法优雅处理如动物喂食等行为的差异，只能通过冗长的 `if-else` 分支实现。

### 不使用 OOP 的伪代码示例（C++ 风格）

```cpp
// 定义所有动物的数据结构
struct Animal {
    string name;
    float weight;
    int foodEaten;
    string foodType;
};

Animal elephants[10];
Animal giraffes[5];
Animal monkeys[8];

// 动物喂食函数（非多态）
void feedAnimal(Animal &a, int foodAmount) {
    a.foodEaten += foodAmount;
    if (a.foodEaten > 100) {
        a.weight += 1.5;
    }
}

// 围栏状态用数组和整数表示
int elephantEnclosureDirt = 0;
int giraffeEnclosureDirt = 0;
int monkeyEnclosureDirt = 0;

// 清洁逻辑（重复代码）
void cleanEnclosure(string type) {
    if (type == "elephant") elephantEnclosureDirt = 0;
    else if (type == "giraffe") giraffeEnclosureDirt = 0;
    else if (type == "monkey") monkeyEnclosureDirt = 0;
}

// 售票逻辑（全局处理）
float totalRevenue = 0.0;
void sellTickets(int adults, int children) {
    totalRevenue += adults * 1.0 + children * 0.4;
}

// 动物园模拟主逻辑
void simulateDay() {
    int numAdults = rand() % 20 + 20;
    int numChildren = 0;

    for (int i = 0; i < numAdults; ++i) {
        int c = rand() % 4;
        numChildren += c;
        sellTickets(1, c);
    }

    // 喂食全部动物
    for (int i = 0; i < 10; ++i)
        feedAnimal(elephants[i], 5);
    for (int i = 0; i < 5; ++i)
        feedAnimal(giraffes[i], 3);
    for (int i = 0; i < 8; ++i)
        feedAnimal(monkeys[i], 2);

    elephantEnclosureDirt += 100;
    giraffeEnclosureDirt += 80;
    monkeyEnclosureDirt += 60;

    if (elephantEnclosureDirt > 2000)
        cleanEnclosure("elephant");
    // 其他类似逻辑重复处理...
}
```

### 与面向对象实现对比

| 项目维度       | 非 OOP 实现                | OOP 实现                     |
| -------------- | -------------------------- | ---------------------------- |
| 数据封装       | 全局变量散乱、结构体简单   | 类内封装、成员职责清晰       |
| 功能扩展       | 需手动添加新逻辑到多个函数 | 通过继承/多态重载简化扩展    |
| 行为管理       | `if-else` 或者`switch-case`判断行为分支     | 虚函数和多态机制             |
| 代码维护       | 修改一处易影响其他地方     | 修改封装类时对外部影响较小   |
| 可读性与组织性 | 低，函数混杂，代码重复多   | 高，结构分层明确，易于模块化 |

### 小结

通过上述伪代码对比，我们可以明显看到：

- 面向对象设计让复杂系统更清晰、模块化；
- 非 OOP 实现虽然短期上手容易，但长期维护和扩展代价极高；
- 使用类的封装、继承和多态可以有效地组织和管理逻辑，是大型系统的必要设计。

因此，**本实验强化了我们对面向对象编程优势的理解和实践能力**，尤其在复杂模拟系统中，OOP 能大幅降低代码复杂度与维护成本。

---

## 七、总结

这是一个面向对象模拟系统设计题，主要考察 OOP 的三大特性、类结构设计能力、系统模拟能力以及 C++语言特性（如重载、继承、多态）。代码分层清晰，逻辑严密是关键。
