#ifndef ISENSORREPOSITORY_H
#define ISENSORREPOSITORY_H

#include "../Domain/mesurevalue.h"

class ISensorRepository{

public:
    virtual MesureValue GetValue();
     ISensorRepository();
};

#endif // ISENSORREPOSITORY_H
