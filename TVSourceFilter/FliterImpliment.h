#ifndef FLITERIMPLIMENT_H
#define FLITERIMPLIMENT_H

#include <string>
#include <vector>
#include <fstream>

typedef struct
{
    std::string name;
    std::string url;
    std::uint32_t ping;
    std::uint32_t index;
    std::uint8_t isvalid;
}TVUrl_t;

class FliterImpliment
{
public:
    FliterImpliment();
    ~FliterImpliment();

    bool LoadText(std::string& filename);
    std::uint32_t GetUrlCount();
    std::vector<TVUrl_t>& GetInputUrl();
    std::vector<TVUrl_t>& CheckURL();
private:
    std::vector<TVUrl_t> m_TVSrcInput;
    std::vector<TVUrl_t> m_TVSrcOutput;

    void GetTVUrl(std::ifstream& ifile);
};

#endif // FLITERIMPLIMENT_H
