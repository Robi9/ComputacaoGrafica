#include "pc.h"

pc::pc(){

}

pc::pc(float objtx, float objty, float objtz, float objax, float objay, float objaz, float objex, float objey, float objez, bool sc, bool cor){

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

pc::~pc(){

}

void pc::desenha(){
//DESENHO PC
        //gabinete

        glPushMatrix();
            if(sc)GUI::drawOrigin(0.5);
            if(cor)GUI::setColor(255,255,0);
            GUI::setColor(2,1,1);
            GUI::drawBox(1.6,0,0,2,1.2,1,false);
            GUI::setColor(255,255,255);
            GUI::drawBox(1.63,1,1,1.97,1.08,1.02,false);
            glTranslatef(0,-0.15,0);
            GUI::drawBox(1.63,1,1,1.97,1.08,1.02,false);
        glPopMatrix();

        //monitor
        glPushMatrix();
            GUI::setColor(2,1,1);
            GUI::drawBox(0.5,0,0,0.7,0.2,0.2,false);
            GUI::drawBox(0.3,0,0,0.9,0.01,0.3,false);
            GUI::setColor(2,1,1);
            glTranslatef(0,0.2,0);
            GUI::drawBox(0,0,0,1.2,1,0.2,false);
            GUI::setColor(0,0,0);
            GUI::drawBox(0.1,0.1,0.25,1.1,0.9,0.2,true);
        glPopMatrix();

        //teclado
        glPushMatrix();
            GUI::setColor(2,1,1);
            GUI::drawBox(0.1,0,0.5,1.4,0.05,1,false);
        glPopMatrix();
}
