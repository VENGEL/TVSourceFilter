#include "FliterImpliment.h"

FliterImpliment::FliterImpliment() {

}

FliterImpliment::~FliterImpliment() {

}

bool FliterImpliment::LoadText(std::string& filename) {
    std::ifstream ifile;

    m_TVSrcInput.clear();
    m_TVSrcOutput.clear();

    ifile.open(filename.c_str(), std::ios::in);
    if (ifile.is_open()) {
        GetTVUrl(ifile);
        ifile.close();
        return true;
    }

    return false;
}

void FliterImpliment::GetTVUrl(std::ifstream& ifile) {
    std::int32_t iPos = 0;
    TVUrl_t url;
    std::string stLine;
    std::vector<std::string> UrlTypes;
    UrlTypes.push_back(",http");
    UrlTypes.push_back(",mms");

    while(!ifile.eof()) {
        std::getline(ifile, stLine);

        for(std::vector<std::string>::iterator it = UrlTypes.begin(); it != UrlTypes.end(); it++) {
            iPos = stLine.find(*it, 0);
            if (iPos > 0) {
                break;
            }
        }

        if (iPos > 0)
        {
            url.name = stLine.substr(0, iPos);
            url.url = stLine.substr(iPos + 1, stLine.length());
            m_TVSrcInput.push_back(url);
        }
    }
}

std::vector<TVUrl_t>& FliterImpliment::CheckURL()
{
    for(std::vector::iterator it = m_TVSrcInput.begin(); it != m_TVSrcInput.end(); it++)
    {

    }
    return m_TVSrcOutput;
}

std::vector<TVUrl_t>& FliterImpliment::GetInputUrl()
{
    return m_TVSrcInput;
}

std::uint32_t FliterImpliment::GetUrlCount() {
    return m_TVSrcInput.size();
}
