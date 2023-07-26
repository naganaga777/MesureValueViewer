#include "mesurevaluejsonrepository.h"
#include "/home/user/jsonlib/json.hpp"
#include "filesystem"
#include <cstdio>
#include <fstream>
#include "chrono"

MesureValueJsonRepository::MesureValueJsonRepository()
{
    createTestDate();
}

 std::vector<MesureValue>  MesureValueJsonRepository::GetAllMesureValueList()
 {

     return std::vector<MesureValue>{};
 }

 bool MesureValueJsonRepository::TrySave(MesureValue value)
 {
     std::string filePath = std::string(MesureValueJsonRepository::m_directory) + std::string(MesureValueJsonRepository::m_fileName);

     if(!std::filesystem::exists(filePath))
     {
         return false;
     }
//     auto jString = std::fstream::read(filePath.c_str());
     auto fileP = std::fopen(filePath.c_str(),"r");
     auto j =  nlohmann::json::parse(fileP);
     std::vector<MesureValue> saveDatas =  this->from_jsonArray(j);
     fclose(fileP);

     saveDatas.push_back(value);
     nlohmann::json newJsonString;
     this->to_json(newJsonString,saveDatas);

     //ファイル書き込み
     std::ofstream outfile(filePath.c_str(),std::ios::out);
     outfile<<newJsonString;
     outfile.close();

     return true;
 }

 void MesureValueJsonRepository::createTestDate()
 {
     std::string filePath = std::string(MesureValueJsonRepository::m_directory) + std::string(MesureValueJsonRepository::m_fileName);

     if(std::filesystem::exists(filePath))
     {
         return;
     }

     if(!std::filesystem::exists(MesureValueJsonRepository::m_directory))
     {
         std::filesystem::create_directory(MesureValueJsonRepository::m_directory);
     }

     std::ofstream outfile(filePath.c_str(),std::ios::app);
     auto time = std::chrono::system_clock::now();
     MesureValue data1(1.0,1.2,time);
     MesureValue data2(2.0,3.2,time);
     std::vector<MesureValue> datas{data1,data2};
     nlohmann::json jString;
     this->to_json(jString,datas);
     outfile<<jString;
     outfile.close();
 }
