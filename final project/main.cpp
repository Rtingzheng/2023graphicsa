///week12-5_TRT_keyboard_mouse �n�� keyboard mouse �Ӿޱ�
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL; ///step02-2 �@�}�l,�ɮרS���}, NULL
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL; ///step02-2 �nŪ�ɥΪ�����, �@�}�l�]�O NULL
int show[4]={1,1,1,1};
int ID=2;///0:�Y 1:���� 2:�W���u 3:�U���u
void keyboard(unsigned char key,int x,int y){
    if(key=='0') ID = 0;
    if(key=='1') ID = 1;
    if(key=='2') ID = 2;
    if(key=='3') ID = 3;

    ///if(key=='0') show[0] = !show[0];
    ///if(key=='1') show[1] = !show[1];
    ///if(key=='2') show[2] = !show[2];
    ///if(key=='3') show[3] = !show[3];
    glutPostRedisplay();
}
FILE * fout = NULL;
FILE * fin = NULL;
float teapotX=0, teapotY=0; ///���ڭ̬ݲ��ʭ�
float angle=0, angle2=0, angle3=0;///step03-2 �\�ʧ@
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2,0.2,0.2);
        if(body==NULL){
            head = glmReadOBJ("model/head.obj");
            body = glmReadOBJ("model/body.obj");
            uparmR = glmReadOBJ("model/uparmR.obj");
            lowarmR = glmReadOBJ("model/lowarmR.obj");
        }
        if(ID==0) glColor3f(1,0,0);///��w�]����
        else glColor3f(1,1,1);///�S��w�]�զ�
        if(show[0]) glmDraw(head, GLM_MATERIAL);

        if(ID==1) glColor3f(1,0,0);///��w�]����
        else glColor3f(1,1,1);///�S��w�]�զ�
        if(show[1]) glmDraw(body, GLM_MATERIAL);
        glPushMatrix();
            glTranslatef(-1.200000, +0.460000, 0);
            glRotatef(angle,0,0,1);
            glTranslatef(1.200000, -0.460000, 0);

            if(ID==2) glColor3f(1,0,0);///��w�]����
            else glColor3f(1,1,1);///�S��w�]�զ�
            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);

            glPushMatrix();
                glTranslatef(-1.933332, 0.093333, 0);
                glRotatef(angle,0,0,1);
                glTranslatef(1.933332, -0.093333, 0);
                if(ID==3) glColor3f(1,0,0);///��w�]����
                else glColor3f(1,1,1);///�S��w�]�զ�
                if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glColor3f(0,1,0);
    glutSolidTeapot(0.02);
    glutSwapBuffers();
    ///glTranslatef(teapotX, teapotY, 0);
        ///glTranslatef(????); ///step03-2 �\�ʧ@
        ///glRotatef(angle, 0, 0, 1);///step03-2 �\�ʧ@
        ///glTranslatef(0.400000, -0.060000, 0);///step03-2
        ///glTranslatef(teapotX, teapotY, 0);///step03-2 �\�ʧ@
        ///glutSolidTeapot( 0.3 );
}
int oldX=0,oldY=0;
void motion(int x,int y){
    teapotX+=(x-oldX)/150.0;
    teapotY-=(y-oldY)/150.0;
    oldX=x;
    oldY=y;
    angle=x;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
        angle = x;
        ///teapotX = (x-150)/150.0;
        ///teapotY = (150-y)/150.0;
        ///if(fout==NULL) fout = fopen("file4.txt", "w"); ///step02-2 �S�}��,�N�}
        ///fprintf(fout, "%f %f\n", teapotX, teapotY); ///step02-2 �n�A�s�y��
    }
    display();
}
///void keyboard(unsigned char key, int x, int y) ///step02-2 keyboard�禡
///{
   /// if(fin==NULL){ ///step02-2 �p�G�ɮ��٨S fopen(), �N�}��
      ///  fclose(fout); ///�e��mouse�|�}fout����, �ҥH�n����
        ///fin = fopen("file4.txt", "r"); ///step02-2 �S�}��,�N�}
 ///   }
    ///fscanf(fin, "%f %f", &teapotX, &teapotY); ///step02-2 �u��Ū��
    ///display(); ///step02-2 ���e�e��
///}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard); ///step02-2 keyboard�n�����o(�}�ɡBŪ��)

    glutMainLoop();
}
