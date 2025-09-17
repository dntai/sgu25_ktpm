#pragma once

#include <fstream>
#include <iostream>
#include <string>

class ILogger
{
public:
    enum LogLevel
    {
        ERROR = 0,
        INFO = 1,
        DEBUG = 2,
    };

    ILogger();
    virtual ~ILogger();

    void setLevel(LogLevel level);
    virtual void info(const std::string &content) const = 0;
    virtual void error(const std::string &content) const = 0;
    virtual void debug(const std::string &content) const = 0;

protected:
    virtual void write(const std::string &content) const;
    LogLevel level_ = DEBUG;
    std::ostream *outstream_;
};

class FileLogger : public ILogger
{
public:
    enum SINK
    {
        FILE,
        COUT
    };
    FileLogger(const std::string &filename = "file.log", SINK sink = FILE);
    virtual ~FileLogger();

    virtual void info(const std::string &content) const override;
    virtual void error(const std::string &content) const override;
    virtual void debug(const std::string &content) const override;

private:
    SINK sink_;
};