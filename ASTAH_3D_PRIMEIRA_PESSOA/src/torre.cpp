#include "../include/torre.hpp" 
#include <GL/glut.h>
#include <cmath>
#include <string>

void predio_principal(double largura, double altura);
void bandeiras(double largura, double altura, int bandeira);

void Torre::desenha(){
    //desenha predio principal
    predio_principal(largura, altura);

    // desenha predios auxiliares
    glPushMatrix();
        glTranslated(largura,0.0,largura);
        predio_principal(largura/2, altura/2);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-largura,0.0,largura);
        predio_principal(largura/2, altura/2);
    glPopMatrix();
    glPushMatrix();
        glTranslated(largura,0.0,-largura);
        predio_principal(largura/2, altura/2);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-largura,0.0,-largura);
        predio_principal(largura/2, altura/2);
    glPopMatrix();

    // desenha as bandeiras
    glPushMatrix();
        glTranslated(largura, altura, largura);
        bandeiras(largura, altura, 1);
    glPopMatrix();

}

void predio_principal(double largura, double altura){
    glBegin(GL_TRIANGLE_STRIP);

        // lado z+
        glColor3f(1.0, 0.0, 1.0); 
        glVertex3f(largura, 0.0, largura);
        glVertex3f(-largura, 0.0, largura);

        glColor3f(0.0, 0.0, 0.0); 
        glVertex3f(largura, altura, largura);
        glVertex3f(-largura, altura, largura);

        // lado x+
        glColor3f(1.0, 0.0, 1.0); 
        glVertex3f(largura, 0.0, largura);
        glVertex3f(largura, 0.0, -largura);

        glColor3f(0.0, 0.0, 0.0); 
        glVertex3f(largura, altura, largura);
        glVertex3f(largura, altura, -largura);

        // lado z-
        glColor3f(1.0, 0.0, 1.0); 
        glVertex3f(largura, 0.0, -largura);
        glVertex3f(-largura, 0.0, -largura);

        glColor3f(0.0, 0.0, 0.0); 
        glVertex3f(largura, altura, -largura);
        glVertex3f(-largura, altura, -largura);

        // lado x-
        glColor3f(1.0, 0.0, 1.0); 
        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(-largura, 0.0, largura);

        glColor3f(0.0, 0.0, 0.0); 
        glVertex3f(-largura, altura, -largura);
        glVertex3f(-largura, altura, largura);

        //tampa
        glColor3f(0.0, 0.0, 0.0); 
        glVertex3f(largura, altura, largura);
        glVertex3f(-largura, altura, largura);
        glVertex3f(largura, altura, -largura);
        glVertex3f(-largura, altura, -largura);


    glEnd();

    glBegin(GL_LINES);

        glColor3f(1.0, 1.0, 1.0);

        //alturas
        glVertex3f(largura, 0.0, largura);
        glVertex3f(largura, altura, largura);
        
        glVertex3f(-largura, 0.0, largura);
        glVertex3f(-largura, altura, largura);

        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(-largura, altura, -largura);

        glVertex3f(largura, 0.0, -largura);
        glVertex3f(largura, altura, -largura);

        //larguras
            //bases
        glVertex3f(largura, 0.0, largura);
        glVertex3f(-largura, 0.0, largura);

        glVertex3f(-largura, 0.0, largura);
        glVertex3f(-largura, 0.0, -largura);

        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(largura, 0.0, -largura);

        glVertex3f(largura, 0.0, -largura);
        glVertex3f(largura, 0.0, largura);

            //topos
        glVertex3f(largura, altura, largura);
        glVertex3f(-largura, altura, largura);

        glVertex3f(-largura, altura, largura);
        glVertex3f(-largura, altura, -largura);

        glVertex3f(-largura, altura, -largura);
        glVertex3f(largura, altura, -largura);

        glVertex3f(largura, altura, -largura);
        glVertex3f(largura, altura, largura);
    glEnd();
}



void bandeiras(double largura, double altura, int bandeira){
    if(bandeira == 0){
        glBegin(GL_LINES);
            glVertex3f(0.0,0.0,0.0);
            glVertex3f(0.0,largura,0.0);
        glEnd();

        glPushMatrix();
        glTranslated(0.0,(2*largura)/3,0.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLE_STRIP);
            glVertex3f(0.0,0.0,0.0);
            glVertex3f(largura/2,0.0,0.0);
            glVertex3f(0.0,largura/3,0.0);
            glVertex3f(largura/2,largura/3,0.0);
        glEnd();
        glPopMatrix();

    }
    else if(bandeira == 1){
        glBegin(GL_LINES);
            glVertex3f(0.0,0.0,0.0);
            glVertex3f(0.0,largura,0.0);
        glEnd();

        glPushMatrix();
            glTranslated(0.0,(2*largura)/3,0.0);
            glColor3f(0.0, 0.7, 0.0);
            glBegin(GL_TRIANGLE_STRIP);
                glVertex3f(0.0,0.0,0.0);
                glVertex3f(largura/2,0.0,0.0);
                glVertex3f(0.0,largura/3,0.0);
                glVertex3f(largura/2,largura/3,0.0);
            glEnd();
        glPopMatrix();
    }
}

Torre::Torre(double largura, double altura){
    this->largura = largura;
    this->altura = altura;
}

double Torre::get_altura(){
    return altura;
}