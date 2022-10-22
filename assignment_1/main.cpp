#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display();

void init(){glClearColor(0,0,10,0);}

void reshape(int, int);


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200,200);
    glutInitWindowSize(500,250);

    glutCreateWindow("First Program");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glutMainLoop();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    //glPointSize(1.0);

    glBegin(GL_LINES);

    //glLineWidth(5.0);
    glVertex2f(-6.0,0.0);
    glVertex2f(6.0,0.0);

    int i;

   for(i=-6;i<=5;i++)
    {
        glVertex3f(i,-1.0,0.0);
        glVertex3f(i+1,-1.0,-1.1);

    }



    glVertex2f(-6.0,-2.0);
    glVertex2f(6.0,-2.0);




    glEnd();

    glFlush();

}

void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);



}
