#include "mesac.h"

mesac::mesac(float objtx, float objty, float objtz, float objax, float objay, float objaz, float objex, float objey, float objez, bool sc, bool cor){
    this->set_x_translate(objtx);
    this->set_y_translate(objty);
    this->set_z_translate(objtz);
    this->set_x_angle(objax);
    this->set_y_angle(objay);
    this->set_z_angle(objaz);
    this->set_x_scale(objex);
    this->set_y_scale(objey);
    this->set_z_scale(objez);
    this->set_sisCoord(sc);
    this->set_cor(cor);
}
mesac::mesac(){

}
mesac::~mesac(){

}
void mesac::desenha(){
    Model3DS mesaC = Model3DS("../3ds/mesaC/mesaC/mesaC.3ds");
    GUI::draw3ds(mesaC);

}
void mesac::correcao(){
    std::cout<<"Correção da Casa 3ds"<<endl;
}
