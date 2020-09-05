#include "cadeira.h"

cadeira::cadeira(){

}
cadeira::cadeira(float objtx, float objty, float objtz, float objax, float objay, float objaz, float objex, float objey, float objez, bool sc, bool cor){

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

cadeira::~cadeira(){

}

void cadeira::desenha(){


    glPushMatrix();
           if(sc)GUI::drawOrigin(0.5);
           if(cor)GUI::setColor(255,255,0);
           GUI::setColor(1,0,1);
           glBegin(GL_QUADS);
               glNormal3f(0,1,0);
               glVertex3f(-1.5,0.2,-1);//inf esq
               glVertex3f(-1.5,0.2,-1.2); //sup esq
               glVertex3f(-1.2,0.2,-1.2); //sup dir
               glVertex3f(-1.2,0.2,-1); //inf dir
           glEnd();
    glPopMatrix();

    //pernas
    glPushMatrix();
           GUI::setColor(0,0,0);
           glBegin(GL_LINES);
               glNormal3f(0,1,0);
               //perna1 frente
               glVertex3f(-1.5,0.2,-1);
               glVertex3f(-1.2,0,-1);
           glEnd();

           glBegin(GL_LINES);
               glNormal3f(0,1,0);
               //perna2 frente
               glVertex3f(-1.2,0.2,-1);
               glVertex3f(-1.5,0,-1);
           glEnd();

           glBegin(GL_LINES);
               glNormal3f(0,1,0);
               //perna3 trás
               glVertex3f(-1.5,0.2,-1.2);
               glVertex3f(-1.2,0,-1.2);
           glEnd();

           glBegin(GL_LINES);
               glNormal3f(0,1,0);
               //perna4 trás
               glVertex3f(-1.2,0.2,-1.2);
               glVertex3f(-1.5,0,-1.2);
          glEnd();

    glPopMatrix();

    //encosto
    glPushMatrix();
           GUI::setColor(0,0,0);
           glBegin(GL_LINES);
               glNormal3f(0,1,0);
               glVertex3f(-1.5,0.2,-1.2);
               glVertex3f(-1.5,0.4,-1.2);
           glEnd();
           glBegin(GL_LINES);
               glNormal3f(0,1,0);
               glVertex3f(-1.2,0.2,-1.2);
               glVertex3f(-1.2,0.4,-1.2);
           glEnd();
    glPopMatrix();

    glPushMatrix();

            GUI::setColor(1,0,1);
            glBegin(GL_QUADS);
                glNormal3f(0,1,0);
                glVertex3f(-1.5,0.3,-1.2);//inf esq
                glVertex3f(-1.5,0.38,-1.2); //sup esq
                glVertex3f(-1.2,0.38,-1.2); //sup dir
                glVertex3f(-1.2,0.3,-1.2); //inf dir
            glEnd();
    glPopMatrix();

    //encosto das pernas
    glPushMatrix();
           GUI::setColor(0,0,0);
           glBegin(GL_LINES);
               glNormal3f(0,1,0);
               glVertex3f(-1.47,0.02,-1);
               glVertex3f(-1.47,0.02,-1.2);
           glEnd();
           glBegin(GL_LINES);
               glNormal3f(0,1,0);
               glVertex3f(-1.23,0.02,-1);
               glVertex3f(-1.23,0.02,-1.2);
           glEnd();
    glPopMatrix();

}
