#include <iostream>
#include <string>
#include <exception>
#include <map>
#include <vector>

class Repository
{
    public:
    virtual std::string GetItem(int id) = 0;
    virtual void SaveItem(int id, std::string item) = 0;
    virtual void Sync() = 0;

    virtual ~Repository()
    {

    }
};

class InMemoryRepository : public Repository
{
    public:
    std::string GetItem(int id) override
    {
        return m_storage[id];
    }

    void SaveItem(int id, std::string item) override
    {
        m_storage[id] = item;
    }

    void Sync() override
    {

    }

    private:
    std::vector<std::string> m_storage;
};

class Localizer
{
    using string = std::string;

    public:
    Localizer()
    {
        m_language = "En";

        m_enMap.insert({"WelcomeMessage", "Welcome to smart wallet"});
        m_deMap.insert({"WelcomeMessage", "Wilkommen"});
        m_arMap.insert({"WelcomeMessage", "Mr7ban"});
    }

    void SetLanguage(const string& langauge)
    {
        m_language = langauge;
    }

    string GetString(const string& key)
    {
        if(m_language == "En")
            return m_enMap[key];
        else if(m_language == "De")
            return m_deMap[key];
        else if(m_language == "Ar")
            return m_arMap[key];

        return "";
    }

    private:
    string m_language;
    std::map<std::string, std::string> m_enMap;
    std::map<std::string, std::string> m_arMap;
    std::map<std::string, std::string> m_deMap;
};