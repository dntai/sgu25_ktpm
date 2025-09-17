#include "logger.h"

ILogger::ILogger() : level_(DEBUG), outstream_(&std::cout) {}

ILogger::~ILogger() = default;

void ILogger::setLevel(LogLevel level) { level_ = level; }

void ILogger::write(const std::string &content) const
{
    outstream_->write(content.c_str(), content.size());
}

FileLogger::FileLogger(const std::string &filename, SINK sink) : sink_(sink)
{
    if (sink == FILE)
        outstream_ = new std::ofstream(filename);
    else
        outstream_ = &std::cout;
}

FileLogger::~FileLogger()
{
    if (sink_ == FILE)
        delete outstream_;
}

void FileLogger::info(const std::string &content) const
{
    if (level_ < LogLevel::INFO)
        return;
    *outstream_ << "Info::";
    write(content);
}

void FileLogger::error(const std::string &content) const
{
    *outstream_ << "Error::";
    write(content);
}

void FileLogger::debug(const std::string &content) const
{
    if (level_ < LogLevel::DEBUG)
        return;
    *outstream_ << "Debug::";
    write(content);
}