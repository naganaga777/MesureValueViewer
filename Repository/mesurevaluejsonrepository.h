#ifndef MESUREVALUEJSONREPOSITORY_H
#define MESUREVALUEJSONREPOSITORY_H
#include "IRepository/imesurevaluerepository.h"
#include "Domain/mesurevalue.h"
#include <vector>
#include <string_view>
#include "string"
#include "/home/user/jsonlib/json.hpp"

class MesureValueJsonRepository: public IMesureValueRepository
{
public:
    MesureValueJsonRepository();
    std::vector<MesureValue>  GetAllMesureValueList() override;
    bool TrySave(MesureValue value) override;

private:
    void createTestDate();

    void to_json(nlohmann::json& j, const MesureValue& mv)
    {

        j = nlohmann::json{{"Tempature", mv.Tempature()},
                           {"Humidity",mv.Humidity()},
                           {"DateTime",Utility::Parse(mv.DateIime())}};

    }

    void to_json(nlohmann::json& j, const std::vector<MesureValue>& datas)
    {
        j = nlohmann::json();
        for(auto const &mv :datas)
        {
            j += nlohmann::json{{"Tempature", mv.Tempature()},
                               {"Humidity",mv.Humidity()},
                               {"DateTime",Utility::Parse(mv.DateIime())}};
        }
    }


    std::vector<MesureValue> from_jsonArray(const nlohmann::json& j)
    {
        std::vector<MesureValue> retArray{};
        for(const nlohmann::json& data :j)
        {
            retArray.push_back(this->from_json(data));
        }
        return  retArray;
    }

    MesureValue from_json(const nlohmann::json& j)
    {
        float tmepature = j.at("Tempature");
        float humidity = j.at("Humidity");
        std::chrono::system_clock::time_point t = Utility::Parse(j.at("DateTime"));
        return MesureValue(tmepature,humidity,t);
    }



private:
    static constexpr std::string_view m_directory {R"(/home/user/TestDatas/MesureValueData/)"};
    static constexpr std::string_view m_fileName {R"(mesurevalus.json)"};

};


#endif // MESUREVALUEJSONREPOSITORY_H
