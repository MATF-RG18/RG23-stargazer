/*
* Autor: Bogdan Djuric
* Indeks: 334/2012
* Projekat: Stargazer, RG23
* email: bole1206@gmail.com
* github: https://github.com/l1ng1206
* Verzija: 0.2
*/

#include <stdio.h>
#include <GL/glut.h>

int spaceshipX = 200, spaceshipY = 70;
static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);
void draw_space(void);
void draw_spaceship(void);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize(800, 500);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-800)/2,
                        (glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow("Stargazer");

    glutDisplayFunc(on_display);
    glutKeyboardFunc(on_keyboard);
    
    glClearColor(0,0,0,0);

    glutMainLoop();

    return 0;

}

void draw_space(void)
{
    glBegin(GL_POLYGON);
        glColor3f(0.5,0.5,0.5);
        glVertex2f(50,500);
        glVertex2f(50,0);
        glVertex2f(450,0);
        glVertex2f(450,500);
    glEnd();
    
}

void draw_spaceship(void)
{
    glPointSize(10.0);

    glBegin(GL_POINTS);//front shooter
    glColor3f(1,1,1);//111
    glVertex2f(spaceshipX, spaceshipY + 40);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.137255,0.419608,0.556863);//middle body
        glVertex2f(spaceshipX - 25, spaceshipY + 25);
        glVertex2f(spaceshipX - 25, spaceshipY - 25);
        glVertex2f(spaceshipX + 25, spaceshipY - 25);
        glVertex2f(spaceshipX + 25, spaceshipY + 25);
    glEnd();

    glBegin(GL_POINTS);//design on middle
        glColor3f(0.90,0.91,0.98);
        glVertex2f(spaceshipX - 10,spaceshipY - 5);
        glVertex2f(spaceshipX + 10,spaceshipY - 5);
    glEnd();

    glBegin(GL_POINTS);//thrusters
        glColor3f(1, 1, 1);
        glVertex2f(spaceshipX - 10,spaceshipY - 30);
        glVertex2f(spaceshipX + 10,spaceshipY - 30);
    glEnd();

    glBegin(GL_TRIANGLES);//right wing
        glColor3f(0.196078, 0.8, 0.196078);
        glVertex2f(spaceshipX + 25,spaceshipY + 25);
        glVertex2f(spaceshipX + 25,spaceshipY - 25);
        glVertex2f(spaceshipX + 45,spaceshipY - 35);
    glEnd();

    glBegin(GL_TRIANGLES);//left wing
        glColor3f(0.196078, 0.8, 0.196078);
        glVertex2f(spaceshipX - 25,spaceshipY + 25);
        glVertex2f(spaceshipX - 25,spaceshipY - 25);
        glVertex2f(spaceshipX - 45,spaceshipY - 35);
    glEnd();


    glBegin(GL_QUADS);//up body
        glColor3f(0.99609, 0.83984, 0);
        glVertex2f(spaceshipX - 25, spaceshipY + 25);
        glVertex2f(spaceshipX - 18, spaceshipY + 40);
        glVertex2f(spaceshipX + 18, spaceshipY + 40);
        glVertex2f(spaceshipX + 25, spaceshipY + 25);
    glEnd();

}

static void on_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //draw_space();
    //draw_spaceship();
    glColor3f(0.5,0.5,0.5);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON);
        glColor3f(0.6,0.3,0.5);
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
        exit(EXIT_SUCCESS);
        break;

    case 'a':
    case 'A':
        //TODO: counter clockwise movement
        break;

    case 'd':
    case 'D':
        //TODO: clockwise movement
        break;

    case 's':
    case 'S':
        //TODO: ship rotation
        break;
    default:
        break;

    }
}