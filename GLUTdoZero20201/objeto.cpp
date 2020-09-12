#include "objeto.h"

objeto::objeto(float objtx, float objty, float objtz, float objax, float objay, float objaz, float objex, float objey, float objez, bool sc, bool cor){

    this->objtx = objtx;
    this->objty = objty;
    this->objtz = objtz;
    this->objax = objax;
    this->objay = objay;
    this->objaz = objaz;
    this->objex = objex;
    this->objey = objey;
    this->objez = objez;
    this->sc = sc;
    this->cor = cor;
}
objeto::objeto(){
    this->objtx = 0.0;
    this->objty = 0.0;
    this->objtz = 0.0;
    this->objax = 0.0;
    this->objay = 0.0;
    this->objaz = 0.0;
    this->objex = 1.0;
    this->objey = 1.0;
    this->objez = 1.0;
    this->sc = false;
    this->cor = false;
}
objeto::~objeto(){

}

void objeto::desenha(){
    std::cout<<"Funcionando.."<<endl;
}

void objeto::set_x_translate(float objtx){
    this->objtx = objtx;
}

void objeto::set_y_translate(float objty){
    this->objty = objty;
}

void objeto::set_cor(bool cor){
    this->cor = true;
}

void objeto::set_sisCoord(bool sc){
    this->sc = sc;
}

void objeto::set_z_translate(float objtz){
    this->objtz = objtz;
}

void objeto::set_x_angle(float objax){
    this->objax = objax;
}

void objeto::set_y_angle(float objay){
    this->objay = objay;
}

void objeto::set_z_angle(float objaz){
    this->objaz = objaz;
}

void objeto::set_x_scale(float objex){
    this->objex = objex;
}

void objeto::set_y_scale(float objey){
    this->objey = objey;
}

void objeto::set_z_scale(float objez){
    this->objez = objez;
}
bool objeto::get_sisCoord(){
    return this->sc;
}

bool objeto::get_cor(){
    return this->cor;
}

float objeto::get_x_translate(){
    return this->objtx;
}

float objeto::get_y_translate(){
    return this->objty;
}

float objeto::get_z_translate(){
    return this->objtz;
}

float objeto::get_x_angle(){
    return this->objax;
}

float objeto::get_y_angle(){
    return this->objay;
}

float objeto::get_z_angle(){
    return this->objaz;
}

float objeto::get_x_scale(){
    return this->objex;
}

float objeto::get_y_scale(){
    return this->objey;
}

float objeto::get_z_scale(){
    return this->objez;
}

istream& operator >> (istream& is,objeto& obj){
    is>>obj.objtx;
    is>>obj.objty;
    is>>obj.objtz;
    is>>obj.objax;
    is>>obj.objay;
    is>>obj.objaz;
    is>>obj.objex;
    is>>obj.objey;
    is>>obj.objez;
    return is;
}
ostream& operator << (ostream& os, const objeto& obj){
    os << obj.objtx << " " <<  obj.objty << " " <<  obj.objtz << " " <<  obj.objax << " " << obj.objay << " " <<  obj.objaz << " " <<  obj.objex << " " <<  obj.objey << " " <<  obj.objez<<"\n";
    return os;
}


