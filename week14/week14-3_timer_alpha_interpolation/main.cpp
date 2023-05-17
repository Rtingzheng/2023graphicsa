#include <GL/glut.h>
float angle=0 ,oldAngle=0,newAngle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void timer(int t)
{
    glutTimerFunc(5,timer,t+1);///�b100���],�U�@�Ӿx��
    float alpha =t/100.0;///float�Ȥ���0.001~1.00��
    angle=newAngle*alpha+(1-alpha)*oldAngle;
    glutPostRedisplay();
}
void motion(int x,int y)
{
    angle=x;
    glutPostRedisplay();
}

void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN) oldAngle=x;
    if(state==GLUT_UP) newAngle=x;
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x,int y)
{
    glutTimerFunc(0,timer,0);
}
int main(int argc ,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///���U��ܰ_�I,��}��ܲ��I
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);


    glutMainLoop();
}
