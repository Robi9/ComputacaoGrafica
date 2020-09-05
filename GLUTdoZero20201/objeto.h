#ifndef OBJETO_H
#define OBJETO_H
#include <iostream>
#include <gui.h>
#include <fstream>
#include <sstream>


class objeto{

public:

    float objtx;//translação
    float objty;
    float objtz;
    float objax;//angulo
    float objay;
    float objaz;
    float objex;//escala
    float objey;
    float objez;
    bool sc;
    bool cor;

    objeto(float objtx, float objty, float objtz, float objax, float objay, float objaz, float objex, float objey, float objez,bool sc, bool cor);
    objeto();
    ~objeto();
    virtual void desenha();

    void set_x_translate(float objtx);
    void set_y_translate(float objty);
    void set_z_translate(float objtz);
    void set_x_angle(float objax);
    void set_y_angle(float objay);
    void set_z_angle(float objaz);
    void set_x_scale(float objex);
    void set_y_scale(float objey);
    void set_z_scale(float objez);
    void set_sisCoord(bool sc);
    void set_cor(bool cor);

    bool get_sisCoord();
    bool get_cor();
    float get_x_translate();
    float get_y_translate();
    float get_z_translate();
    float get_x_angle();
    float get_y_angle();
    float get_z_angle();
    float get_x_scale();
    float get_y_scale();
    float get_z_scale();
    void saveInFile();

    objeto* loadFromFile();
};
istream& operator >> (istream& is,objeto& obj);
ostream& operator << (ostream& os, const objeto& obj);
string float_to_string(float number);
#endif // OBJETO_H
