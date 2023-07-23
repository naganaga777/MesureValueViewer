#include "mesurevaluerepositoryfactory.h"
#include "Repository/mesurevaluejsonrepository.h"
MesureValueRepositoryFactory::MesureValueRepositoryFactory()
{

}

std::shared_ptr<IMesureValueRepository> MesureValueRepositoryFactory::CreateMesueValueRepository()
{
    return  std::make_shared<MesureValueJsonRepository>();
}
