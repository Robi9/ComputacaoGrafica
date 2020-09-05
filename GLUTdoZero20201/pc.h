#ifndef PC_H
#define PC_H
#include "objeto.h"


class pc:public objeto{

public:
    pc();
    pc(float objtx, float objty, float objtz, float objax, float objay, float objaz, float objex, float objey, float objez, bool sc, bool cor);
    ~pc();
    virtual void desenha() override;

};

#endif // PC_H
