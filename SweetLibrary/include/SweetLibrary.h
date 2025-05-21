#pragma once
#include<string>
#include<vector>
#include<memory>
#ifdef SWEETLIBRARY_EXPORTS
#define SWEET_API __declspec(dllexport)  // Для экспорта из DLL
#else
#define SWEET_API __declspec(dllimport)  // Для импорта в другие проекты
#endif

class SWEET_API Sweet {
protected:
    std::string Name;
    unsigned int Weight;
    unsigned int Price;
    std::string ingredients;
public:
    Sweet();
    Sweet(const std::string& name); // Конструктор
    Sweet(const std::string& name, const int weight);
    virtual ~Sweet();           // Деструктор
    virtual void ShowInfo() const;    // Метод, который будет доступен для использования в других проектах
    void setWeight();
    void setPrice();
    std::string getName();
    unsigned int getWeight();
    unsigned int getPrice();
};

class SWEET_API Candy : public Sweet {
protected:
    std::string Filling;
public:
    Candy(const std::string& name, const std::string& fill);
    Candy(const std::string& name, const int weight);
    void ShowInfo() const override;
};

class SWEET_API ChocolateCandy : public Candy {
protected:
    std::string ChocolateType;
public:
    ChocolateCandy(const std::string& name, const std::string& fill, const std::string& chocolateType);
    ChocolateCandy(const std::string& name, const int weight);
    void ShowInfo() const override;
};

class SWEET_API CaramelCandy : public Candy {
protected:
    std::string CaramelType;
public:
    CaramelCandy(const std::string& name, const std::string& fill, const std::string& caramelType);
    CaramelCandy(const std::string& name, const int weight);
    void ShowInfo() const override;
};

class SWEET_API ChocolateBars : public Sweet {
protected:
    unsigned int CountDrops;
public:
    ChocolateBars(const std::string& name, const unsigned int& countDrops);
    ChocolateBars(const std::string& name, const int weight);
    void ShowInfo() const override;
};

class SWEET_API Gum : public Sweet {
protected:
    unsigned int Stickness;
public:
    Gum(const std::string& name, const unsigned int& stickness);
    Gum(const std::string& name, const int weight);
    void ShowInfo() const override;
};
