#include "../include/chao.hpp"
#include "../include/textura.hpp"



void teste(double tam){
    Textura teste("../texturas/astah.png");

    GLfloat largura = static_cast<GLfloat>(tam);

    GLfloat vertices[]{
        0,0,0,
        largura,0,0,
        largura,largura,0,
        0,largura,0
    };

    GLfloat ver_text[]{
        0,0,
        1,0,
        1,1,
        0,1
    };

    // Ativar o mapeamento de textura
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, teste.get_textureID());

    glBegin(GL_QUADS);
    for (int i = 0; i < 4; i++) {
        //glColor3f(0.0, 1.0, 0.0);  // Verde para o lado positivo
        glTexCoord2fv(ver_text + i * 2);
        glVertex3fv(vertices + i * 3);
    }
    glEnd();

    // Desativar o mapeamento de textura
    glDisable(GL_TEXTURE_2D);

    teste.~Textura();
}

Chao::Chao(double largura, double especura){
    this->largura = largura;
    this->especura = especura;
}

void Chao::desenha(){
    /*glBegin(GL_TRIANGLE_FAN);
        glVertex3f(largura, 0.0, largura);
        glVertex3f(-largura, 0.0, largura);

        glVertex3f(-largura, 0.0, largura);
        glVertex3f(-largura, 0.0, -largura);

        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(largura, 0.0, -largura);

        glVertex3f(largura, 0.0, -largura);
        glVertex3f(largura, 0.0, largura);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(largura, -0.5, largura);
        glVertex3f(-largura, -0.5, largura);

        glVertex3f(-largura, -0.5, largura);
        glVertex3f(-largura, -0.5, -largura);

        glVertex3f(-largura, -0.5, -largura);
        glVertex3f(largura, -0.5, -largura);

        glVertex3f(largura, -0.5, -largura);
        glVertex3f(largura, -0.5, largura);

    glEnd();*/
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(largura, 0.0, largura);
        glVertex3f(-largura, 0.0, largura);
        glVertex3f(largura, -especura, largura);
        glVertex3f(-largura, -especura, largura);

        glVertex3f(-largura, 0.0, largura);
        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(-largura, -especura, largura);
        glVertex3f(-largura, -especura, -largura);

        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(largura, 0.0, -largura);
        glVertex3f(-largura, -especura, -largura);
        glVertex3f(largura, -especura, -largura);

        glVertex3f(largura, 0.0, -largura);
        glVertex3f(largura, 0.0, largura);
        glVertex3f(largura, -especura, -largura);
        glVertex3f(largura, -especura, largura);

    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        glVertex3f(largura, 0.0, largura);
        glVertex3f(-largura, 0.0, largura);
        glVertex3f(largura, -especura, largura);
        glVertex3f(-largura, -especura, largura);

        glVertex3f(-largura, 0.0, largura);
        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(-largura, -especura, largura);
        glVertex3f(-largura, -especura, -largura);

        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(largura, 0.0, -largura);
        glVertex3f(-largura, -especura, -largura);
        glVertex3f(largura, -especura, -largura);

        glVertex3f(largura, 0.0, -largura);
        glVertex3f(largura, 0.0, largura);
        glVertex3f(largura, -especura, -largura);
        glVertex3f(largura, -especura, largura);

        glVertex3f(largura, 0.0, largura);
        glVertex3f(largura, -especura, largura);

        glVertex3f(-largura, 0.0, largura);
        glVertex3f(-largura, -especura, largura);

        glVertex3f(-largura, 0.0, -largura);
        glVertex3f(-largura, -especura, -largura);

        glVertex3f(largura, 0.0, -largura);
        glVertex3f(largura, -especura, -largura);

    glEnd();

    glPushMatrix();
    //glTranslated(3, 5, 3);
    //glRotatef(-45, 0, 1, 0);
    //teste(largura);
    glPopMatrix();
}

