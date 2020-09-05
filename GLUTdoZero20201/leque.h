#ifndef LEQUE_H
#define LEQUE_H
#include "objeto.h"


class leque:public objeto{
public:
    leque();
    leque(float objtx, float objty, float objtz, float objax, float objay, float objaz, float objex, float objey, float objez, bool sc, bool cor);
    ~leque();
    virtual void desenha() override;

};

#endif // LEQUE_H
