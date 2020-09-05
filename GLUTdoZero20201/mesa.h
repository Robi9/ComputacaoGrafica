#ifndef MESA_H
#define MESA_H
#include "objeto.h"


class mesa:public objeto
{
public:
    mesa();
    mesa(float objtx, float objty, float objtz, float objax, float objay, float objaz, float objex, float objey, float objez, bool sc, bool cor);
    ~mesa();
    virtual void desenha() override;
};

#endif // MESA_H
