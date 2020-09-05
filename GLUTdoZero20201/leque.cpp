#include "leque.h"

leque::leque(){

}
leque::leque(float objtx, float objty, float objtz, float objax, float objay, float objaz, float objex, float objey, float objez, bool sc, bool cor){

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

leque::~leque(){

}

void leque::desenha(){
    //leque
    glPushMatrix();
           if(sc)GUI::drawOrigin(0.5);
           if(cor)GUI::setColor(255,255,0);
           GUI::setColor(255,255,255);
           glBegin(GL_TRIANGLE_FAN);
               glNormal3f(0,1,0);
               glVertex3f(0,0,0);
               glVertex3f(-0.5,0.5,0);
               glVertex3f(-0.3,0.6,0);
               glVertex3f(0,0.65,0);
               glVertex3f(0.3,0.6,0);
               glVertex3f(0.5,0.5,0);
               glVertex3f(-0.15,-0.15,0);
               glVertex3f(0.15,-0.15,0);
           glEnd();
    glPopMatrix();

    //linhas internas
    glPushMatrix();
        glBegin(GL_LINES);
            GUI::setColor(0,0,0);
            glNormal3f(0,1,0);
            //linha1
            glVertex3f(0,0,0);
            glVertex3f(-0.31,0.6,0.01);
            //linha2
            glVertex3f(0,0,0);
            glVertex3f(0.01,0.65,0.01);
            //linha3
            glVertex3f(0,0,0);
            glVertex3f(0.31,0.6,0.01);
            //glVertex3f(0.5,0.5,0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glBegin(GL_LINES);
            GUI::setColor(0,0,0);
            glNormal3f(0,1,0);
            //linha1
            glVertex3f(0,0,0);
            glVertex3f(-0.31,0.6,-0.01);
            //linha2
            glVertex3f(0,0,0);
            glVertex3f(0.01,0.65,-0.01);
            //linha3
            glVertex3f(0,0,0);
            glVertex3f(0.31,0.6,-0.01);
            //glVertex3f(0.5,0.5,0);
        glEnd();
    glPopMatrix();
}
