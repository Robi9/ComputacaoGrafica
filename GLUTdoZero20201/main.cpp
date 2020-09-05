#include <iostream>
#include "objeto.h"
#include <gui.h>
#include "pc.h"
#include <vector>
#include "mesa.h"
#include "leque.h"
#include "cadeira.h"
#include "ojeto3ds.h"
#include "mesac.h"

using namespace std;

#define TRANSLATE_CONST (0.1)
#define ANGLE_CONST     (2)
#define SCALE_CONST     (0.05)

#define EIXO_X (0)
#define EIXO_Y (1)
#define EIXO_Z (2)

#define TRANSLATE   (0)
#define ANGLE       (1)
#define SCALE      (2)

int indice;
std::vector<objeto*> vetorObjetos;
bool desenhaObjeto = false;

void atualizaVetorObjetos();
void desenhaVetorObjetos();
void selecionaProxObj();
void selecionaAntObj();
void sistCoord(bool sc);
void apagarObj(bool f);
void desenha();
void teclado(unsigned char tecla, int x, int y);
void mouse(int button, int state, int x, int y);
objeto* addObjeto(int obj);

void camera0();
void camera1();
void camera2();
void camera3();
void camera4();
void camera5();
void camera6();

void cena();

ifstream in;
ofstream out;

int EIXO_TRANSLATE_SELECTED = EIXO_X;
int EIXO_ANGLE_SELECTED = EIXO_X;
int EIXO_SCALE_SELECTED = EIXO_X;
int last_pick = TRANSLATE;


Model3DS modelo3ds = Model3DS("../3ds/cartest.3DS");
Model3DS mesaC = Model3DS("../3ds/mesaC/mesaC/mesaC.3ds");

void desenha() {
    GUI::displayInit();

    glPushMatrix();
        glScalef(0,0,0);
        GUI::draw3ds(modelo3ds);
    glPopMatrix();
   // GUI::draw3ds(mesaC);
    GUI::setLight(0, 0,2,0, true, false);

    //referencia (sistema de coordenadas global)    
    glPushMatrix();
            GUI::drawOrigin(0.5);
            GUI::setColor(1,0,0);
            GUI::drawFloor();
        glPopMatrix();

    if(!vetorObjetos.empty()){
         atualizaVetorObjetos();
         desenhaVetorObjetos();
        }

    GUI::displayEnd();
}

void mouse(int button, int state,int x, int y) {
    GUI::mouseButtonInit(button,state,x,y);

    if(button==0){
            if(state==0){
                if(EIXO_TRANSLATE_SELECTED==EIXO_X){
                    EIXO_TRANSLATE_SELECTED=EIXO_Y;
                }else if(EIXO_TRANSLATE_SELECTED==EIXO_Y){
                    EIXO_TRANSLATE_SELECTED=EIXO_Z;
                }else{
                    EIXO_TRANSLATE_SELECTED=EIXO_X;
                }
                last_pick = TRANSLATE;

            }
        }
        if(button==2){
            if(state==0){
                if(EIXO_ANGLE_SELECTED==EIXO_X){
                    EIXO_ANGLE_SELECTED=EIXO_Y;
                }else if(EIXO_ANGLE_SELECTED==EIXO_Y){
                    EIXO_ANGLE_SELECTED=EIXO_Z;
                }else{
                    EIXO_ANGLE_SELECTED=EIXO_X;
                }
                last_pick = ANGLE;

            }
        }
        if(button==1){
            if(state==0){
                if(EIXO_SCALE_SELECTED==EIXO_X){
                    EIXO_SCALE_SELECTED=EIXO_Y;
                }else if(EIXO_SCALE_SELECTED==EIXO_Y){
                    EIXO_SCALE_SELECTED=EIXO_Z;
                }else{
                    EIXO_SCALE_SELECTED=EIXO_X;
                }
                last_pick = SCALE;

            }
        }
        if(button==3){
            if(state==0){
                switch (last_pick) {
                case TRANSLATE:
                    if(EIXO_TRANSLATE_SELECTED==EIXO_X){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_x_translate(vetorObjetos[indice]->get_x_translate()+TRANSLATE_CONST);
                    }
                    if(EIXO_TRANSLATE_SELECTED==EIXO_Y){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_y_translate(vetorObjetos[indice]->get_y_translate()+TRANSLATE_CONST);
                    }
                    if(EIXO_TRANSLATE_SELECTED==EIXO_Z){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_z_translate(vetorObjetos[indice]->get_z_translate()+TRANSLATE_CONST);
                    }
                    break;
                case ANGLE:
                    if(EIXO_ANGLE_SELECTED==EIXO_X){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_x_angle(vetorObjetos[indice]->get_x_angle()+ANGLE_CONST);
                    }
                    if(EIXO_ANGLE_SELECTED==EIXO_Y){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_y_angle(vetorObjetos[indice]->get_y_angle()+ANGLE_CONST);
                    }
                    if(EIXO_ANGLE_SELECTED==EIXO_Z){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_z_angle(vetorObjetos[indice]->get_z_angle()+ANGLE_CONST);
                    }
                    break;
                case SCALE:
                    if(EIXO_SCALE_SELECTED==EIXO_X){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_x_scale(vetorObjetos[indice]->get_x_scale()+SCALE_CONST);
                    }
                    if(EIXO_SCALE_SELECTED==EIXO_Y){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_y_scale(vetorObjetos[indice]->get_y_scale()+SCALE_CONST);
                    }
                    if(EIXO_SCALE_SELECTED==EIXO_Z){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_z_scale(vetorObjetos[indice]->get_z_scale()+SCALE_CONST);
                    }
                    break;
                }

            }
        }
        if(button==4){
            if(state==0){
                switch (last_pick) {
                case TRANSLATE:
                    if(EIXO_TRANSLATE_SELECTED==EIXO_X){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_x_translate(vetorObjetos[indice]->get_x_translate()-TRANSLATE_CONST);
                    }
                    if(EIXO_TRANSLATE_SELECTED==EIXO_Y){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_y_translate(vetorObjetos[indice]->get_y_translate()-TRANSLATE_CONST);
                    }
                    if(EIXO_TRANSLATE_SELECTED==EIXO_Z){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_z_translate(vetorObjetos[indice]->get_z_translate()-TRANSLATE_CONST);
                    }
                    break;
                case ANGLE:
                    if(EIXO_ANGLE_SELECTED==EIXO_X){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_x_angle(vetorObjetos[indice]->get_x_angle()-ANGLE_CONST);
                    }
                    if(EIXO_ANGLE_SELECTED==EIXO_Y){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_y_angle(vetorObjetos[indice]->get_y_angle()-ANGLE_CONST);
                    }
                    if(EIXO_ANGLE_SELECTED==EIXO_Z){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_z_angle(vetorObjetos[indice]->get_z_angle()-ANGLE_CONST);
                    }
                    break;
                case SCALE:
                    if(EIXO_SCALE_SELECTED==EIXO_X){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_x_scale(vetorObjetos[indice]->get_x_scale()-SCALE_CONST);
                    }
                    if(EIXO_SCALE_SELECTED==EIXO_Y){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_y_scale(vetorObjetos[indice]->get_y_scale()-SCALE_CONST);
                    }
                    if(EIXO_SCALE_SELECTED==EIXO_Z){
                        if (!vetorObjetos.empty()) vetorObjetos[indice]->set_z_scale(vetorObjetos[indice]->get_z_scale()-SCALE_CONST);
                    }
                    break;
                }
            }
        }
    }



void teclado(unsigned char tecla, int x, int y) {
    GUI::keyInit(tecla,x,y);

    switch (tecla) {
    case '0':
        camera0();
        break;
    case '1':
        camera1();
        break;
    case '2':
        camera2();
        break;
    case '3':
        camera3();
        break;
    case '4':
        camera4();
        break;
    case '5':
        camera5();
        break;
    case '6':
        camera6();
        break;
    case 'p':
        addObjeto(1); //chama adição do PC
        break;
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'm':
        addObjeto(2); //chama adição da mesa
        break;
    case 'l':
        addObjeto(3); //chama adição da mesa
        break;
    case 'k':
        addObjeto(4); //chama adição da cadeira
        break;
    case 'u':
        addObjeto(5); // chama adição da mesa de centro
        break;
    case '=':
           selecionaProxObj();
           break;
    case '-':
           selecionaAntObj();
           break;
    case 'c': //add eixo coordenada local
           sistCoord(true);
           break;
    case 'd': //remove eixo coordenada local
           sistCoord(false);
           break;
    case 'e': //remove o obj selecionado
           apagarObj(true);
           break;
    case 'a': //chama cena pronta
          cena();
          break;
    case 'z': //salva coord da cena em um arquivo
        std::cout << "SALVAR"<<endl;
                if(!vetorObjetos.empty()){
                    out.open("vetorObjetos",ios::app);
                    for(int i=0;i<vetorObjetos.size();i++){
                        out<<*vetorObjetos[i];
                        cout<<endl<<typeid(vetorObjetos[i]).name()<<endl;
                    }
                    out.close();
                }
          break;
    case 'x': //limpa vetor de ojetos
         vetorObjetos.clear();
          break;
    default:
        break;
    }
}

void apagarObj(bool f){//terminar apagar objeto
    int fim = vetorObjetos.size();
    if (!vetorObjetos.empty() && f){
        vetorObjetos.erase(vetorObjetos.begin()+indice);
    }else vetorObjetos.erase(vetorObjetos.begin()+fim);
}

void sistCoord(bool sc){
    vetorObjetos[indice]->set_sisCoord(sc);
}

objeto* addObjeto(int obj){
    objeto* add;
    switch (obj) {
    case 1://PC
        add = new pc();
        break;
    case 2://MESA
        add = new mesa();
        break;
    case 3://LEQUE
        add = new leque();
        break;
    case 4://CADEIRA
        add = new cadeira();
        break;
    case 5://mesa de centro 3DS
        add = new mesac();
        break;

    }
    vetorObjetos.push_back(add);
    indice = vetorObjetos.size()-1;
    return add;
}

void selecionaProxObj(){
    indice = indice>=vetorObjetos.size()-1?0:indice+1;
}
void selecionaAntObj(){
    indice = indice<=0?vetorObjetos.size()-1:indice-1;
}

void atualizaVetorObjetos(){
    vetorObjetos[indice]->set_x_translate(vetorObjetos[indice]->get_x_translate()+glutGUI::dtx);
    vetorObjetos[indice]->set_y_translate(vetorObjetos[indice]->get_y_translate()+glutGUI::dty);
    vetorObjetos[indice]->set_z_translate(vetorObjetos[indice]->get_z_translate()+glutGUI::dtz);

    vetorObjetos[indice]->set_x_angle(vetorObjetos[indice]->get_x_angle()+glutGUI::dax);
    vetorObjetos[indice]->set_y_angle(vetorObjetos[indice]->get_y_angle()+glutGUI::day);
    vetorObjetos[indice]->set_z_angle(vetorObjetos[indice]->get_z_angle()+glutGUI::daz);

    vetorObjetos[indice]->set_x_scale(vetorObjetos[indice]->get_x_scale()+glutGUI::dsx);
    vetorObjetos[indice]->set_y_scale(vetorObjetos[indice]->get_y_scale()+glutGUI::dsy);
    vetorObjetos[indice]->set_z_scale(vetorObjetos[indice]->get_z_scale()+glutGUI::dsz);
}

void desenhaVetorObjetos(){
    for(int i=0;i<vetorObjetos.size();i++){
        glPushMatrix();
        glTranslatef(vetorObjetos[i]->get_x_translate(),vetorObjetos[i]->get_y_translate(),vetorObjetos[i]->get_z_translate());
        glRotatef(vetorObjetos[i]->get_x_angle(),1,0,0);
        glRotatef(vetorObjetos[i]->get_y_angle(),0,1,0);
        glRotatef(vetorObjetos[i]->get_z_angle(),0,0,1);
        glScalef(vetorObjetos[i]->get_x_scale(),vetorObjetos[i]->get_y_scale(),vetorObjetos[i]->get_z_scale());
        if(i==indice){
           glScalef(vetorObjetos[i]->get_x_scale()+0.2,vetorObjetos[i]->get_y_scale()+0.2,vetorObjetos[i]->get_z_scale()+0.2);
        }
        if(desenhaObjeto) GUI::drawOrigin(0.2);
        vetorObjetos[i]->desenha();
        glPopMatrix();
    }
}

//camera

void camera0(){ //padrão
    glutGUI::cam->e.x = 0;
    glutGUI::cam->e.y = 1;
    glutGUI::cam->e.z = 10;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 1;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}
void camera1(){
    glutGUI::cam->e.x = 10;
    glutGUI::cam->e.y = 2;
    glutGUI::cam->e.z = 5;
    glutGUI::cam->c.x = 2;
    glutGUI::cam->c.y = 1;
    glutGUI::cam->c.z = 1;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}
void camera2(){
    glutGUI::cam->e.x = -15;
    glutGUI::cam->e.y = 5;
    glutGUI::cam->e.z = 5;
    glutGUI::cam->c.x = 1;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 1;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}
void camera3(){
    glutGUI::cam->e.x = 15;
    glutGUI::cam->e.y = 15;
    glutGUI::cam->e.z = 15;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}
void camera4(){
    glutGUI::cam->e.x = 0;
    glutGUI::cam->e.y = 10;
    glutGUI::cam->e.z = 3;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 1;
    glutGUI::cam->c.z = 1;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 2;
    glutGUI::cam->u.z = 0;
}
void camera5(){
    glutGUI::cam->e.x = -2;
    glutGUI::cam->e.y = 1;
    glutGUI::cam->e.z = 0;
    glutGUI::cam->c.x = 1;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 1;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 2;
    glutGUI::cam->u.z = 0;
}
void camera6(){
    glutGUI::cam->e.x = 0;
    glutGUI::cam->e.y = 13;
    glutGUI::cam->e.z = -6;
    glutGUI::cam->c.x = 0;
    glutGUI::cam->c.y = 0;
    glutGUI::cam->c.z = 0;
    glutGUI::cam->u.x = 0;
    glutGUI::cam->u.y = 1;
    glutGUI::cam->u.z = 0;
}

void cena(){
    objeto* pc1 =  new pc(-2.3, 1.63913e-08, 1.9, -4, 0, 0, 0.7, 0.75, 0.65,false, false);
    objeto* leque1 =  new leque(0.2, 0.2, 0.2, -4 ,-190, -4, 0.65 ,0.7 ,1,false, false);
    objeto* pc2 =  new pc(-2.4, 1.63913e-08, -2.3, 0,0, 0, 0.75, 0.75, 0.7,false, false);
    objeto* pc3 =  new pc(0.8, 1.49012e-09, 1.6, 0, 0, 0, 0.75, 0.75, 0.7,false, false);
    objeto* pc4 =  new pc(0.8, 1.63913e-08, -2.1, 0, 0, 0, 0.75, 0.75, 0.7,false, false);
    objeto* mesa1 =  new mesa(-0.4, 1.3411e-08, 2.5, 0, 0, 0, 1, 1.05, 1.1,false, false);//(1,-2,5,0,0,0,2,2,2,false);
    objeto* cadeira1 =  new cadeira(0.8, 0.2, -1.2, 2, 88, 0, 1, 1, 1,false, false);
    objeto* cadeira3 =  new cadeira(1.6, 1.49012e-09, 0.6, 0, 0, 0, 1, 1, 1,false, false);
    objeto* cadeira2 =  new cadeira(-0.3, 0.2, 1.5, -2, -90, 0, 1, 1, 1,false, false);
    objeto* mesa2 =  new mesa(3.1, 1.49012e-09, 2.5, 0, 0, 0, 1, 1 ,1,false, false);
    objeto* cadeira4 =  new cadeira(-1.2, 1.63913e-08, -0.2, 2, 184, -2, 1, 1, 1,false, false);

    vetorObjetos.push_back(pc1);
    vetorObjetos.push_back(leque1);
    vetorObjetos.push_back(pc2);
    vetorObjetos.push_back(pc3);
    vetorObjetos.push_back(pc4);
    vetorObjetos.push_back(mesa1);
    vetorObjetos.push_back(cadeira1);
    vetorObjetos.push_back(mesa2);
    vetorObjetos.push_back(cadeira2);
    vetorObjetos.push_back(cadeira3);
    vetorObjetos.push_back(cadeira4);


}

int main()
{
    cout << "Hello World!" << endl;

    GUI gui = GUI(800,600,desenha,teclado,mouse);
}

//glutGUI::trans_luz = !glutGUI::trans_luz;
