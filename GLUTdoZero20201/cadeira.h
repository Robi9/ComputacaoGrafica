#ifndef CADEIRA_H
#define CADEIRA_H
#include "objeto.h"


class cadeira:public objeto{
public:
    cadeira();
    cadeira(float objtx, float objty, float objtz, float objax, float objay, float objaz, float objex, float objey, float objez, bool sc, bool cor);
   ~cadeira();
   virtual void desenha() override;
};

#endif // CADEIRA_H
