#include "mesa.h"

mesa::mesa()
{

}

mesa::mesa(float objtx, float objty, float objtz, float objax, float objay, float objaz, float objex, float objey, float objez, bool sc, bool cor){

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

mesa::~mesa(){

}

void mesa::desenha(){
//DESENHO MESA

    glPushMatrix();
     if(sc)GUI::drawOrigin(0.5);
     GUI::setColor(1,0,1);
    glBegin(GL_QUADS);
        glNormal3f(0,1,0);
        glVertex3f(-1.3,0.2,-1.5);//inf esq
        glVertex3f(-1.3,0.2,-2); //sup esq
        glVertex3f(-1,0.2,-2); //sup dir
        glVertex3f(-1,0.2,-1.5); //inf dir
    glEnd();
 glPopMatrix();

 glPushMatrix();

        GUI::setColor(0,0,0);
        glBegin(GL_LINES);
            glNormal3f(0,1,0);
            glVertex3f(-1.3,0.2,-1.5);//inf esq
            glVertex3f(-1.3,0,-1.5);

            glVertex3f(-1.3,0.2,-2); //sup esq
            glVertex3f(-1.3,0,-2);

            glVertex3f(-1,0.2,-2); //sup dir
            glVertex3f(-1,0,-2);

            glVertex3f(-1,0.2,-1.5); //inf dir
            glVertex3f(-1,0,-1.5);
        glEnd();
 glPopMatrix();

}
