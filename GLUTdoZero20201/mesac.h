#ifndef MESAC_H
#define MESAC_H
#include "ojeto3ds.h"
#include "objeto.h"

class mesac:public objeto,public ojeto3DS{
public:
   mesac();
    mesac(float objtx, float objty, float objtz, float objax, float objay, float objaz, float objex, float objey, float objez, bool sc, bool cor);
    ~mesac();
    virtual void desenha() override;
    virtual void correcao() override;
};

#endif // MESAC_H


