/*
* Autor: Bogdan Djuric
* Indeks: 334/2012
* Projekat: Stargazer, RG23
* email: bole1206@gmail.com
* github: https://github.com/l1ng1206
* Verzija: 0.1
*/

#include <stdio.h>
#include <GL/glut.h>

static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize(640, 480);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2,
                        (glutGet(GLUT_SCREEN_HEIGHT)-480)/2);
    glutCreateWindow("Stargazer");

    glutKeyboardFunc(on_keyboard);
    glutDisplayFunc(on_display);

    glClearColor(0,0,0,0);

    glutMainLoop();

    return 0;

}

static void on_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f (1.0, 1.0, 1.0);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f (0.40, 0, 0);
        glVertex3f (0.60, 0, 0);
        glVertex3f (0.5, 0.2, 0);
    glEnd();
    glFlush();

    glutSwapBuffers();

}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        /* Zavrsava se program. */
        exit(0);
        break;
    default:
        break;

    }
}