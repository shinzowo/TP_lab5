#pragma once
#include<string>
#include<vector>
#include<memory>
#include"SweetLibrary.h"
#include"Logger.h"
#ifdef SWEETLIBRARY_EXPORTS
#define SWEET_API __declspec(dllexport)  // ��� �������� �� DLL
#else
#define SWEET_API __declspec(dllimport)  // ��� ������� � ������ �������
#endif
//Factory methond
class SWEET_API FactorySweet {
public:
    ~FactorySweet() {};
    virtual std::unique_ptr<Sweet> FactoryMethod(const std::string& name, int weight) = 0;
protected:
    int count;
};

class SWEET_API FactoryCandy : public FactorySweet {
public:
    std::unique_ptr<Sweet> FactoryMethod(const std::string& name, const int weight) override;

};

class SWEET_API FactoryChocolateCandy : public FactoryCandy {
public:
    std::unique_ptr<Sweet> FactoryMethod(const std::string& name, const int weight) override;
};

class SWEET_API FactoryCaramelCandy : public FactoryCandy {
public:
    std::unique_ptr<Sweet> FactoryMethod(const std::string& name, const int weight) override;

};

class SWEET_API FactoryChocolateBars : public FactorySweet {
public:
    std::unique_ptr<Sweet> FactoryMethod(const std::string& name, const int weight) override;

};

class SWEET_API FactoryGum : public FactorySweet {
public:
    std::unique_ptr<Sweet> FactoryMethod(const std::string& name, const int weight) override;

};

//end of FM
class SWEET_API PresentBox {
protected:
    unsigned int TotalWeight;
    std::vector<std::shared_ptr<Sweet>>sweets;
    std::shared_ptr<ILogger> logger;
public:
    PresentBox();
    PresentBox(std::unique_ptr<ILogger> logger);
    void addSweet(std::shared_ptr<Sweet> sweet);
    void removeSweet(int index);
    std::shared_ptr<Sweet> getSweet(int index) const;
    void replaceSweetAt(int index, std::shared_ptr<Sweet> newSweet);
    void showSweets() const;
    unsigned int GetTotalWeight();
};