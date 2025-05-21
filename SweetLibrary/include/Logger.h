#pragma once
#include<string>
#include<memory>
#include<iostream>
#ifdef SWEETLIBRARY_EXPORTS
#define SWEET_API __declspec(dllexport)  // ��� �������� �� DLL
#else
#define SWEET_API __declspec(dllimport)  // ��� ������� � ������ �������
#endif
class SWEET_API ILogger {
public:
    virtual void Log(const std::string& message) = 0;
    virtual ~ILogger() = default;
};

// ������ ��� �������
class SWEET_API ConsoleLogger : public ILogger {
public:
    void Log(const std::string& message) override;
};

// ������ ��� ����� (��������)
class SWEET_API FileLogger : public ILogger {
public:
    void Log(const std::string& message) override;
};

// ������� ��������
class SWEET_API LoggerFactory {
public:
    static std::unique_ptr<ILogger> CreateLogger(int type);
};