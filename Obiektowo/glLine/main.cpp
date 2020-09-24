#include <windows.h>
#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/glut.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Plot {
public:
    void init();
    void display();
};

void Plot::init() {
    glClearColor(0.5, 0.5, 0.5, 0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 40, 0, 40, 0, 20);
}

void Plot::display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(2.0, 4.0, 0.0);
    glVertex3f(10.0, 10.0, 0.0);

    glVertex3f(16.0, 16.0, 0.0);
    glVertex3f(19.0, 25.0, 0.0);

    glEnd();
    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(400, 300);
    glutCreateWindow("simple line using opengl");
    
    Plot p;

    p.init();



    auto glutDisplayFunc = [](Plot& obj) { obj.display(); };

    glutDisplayFunc(p);


    glutMainLoop();

    return 0;
}