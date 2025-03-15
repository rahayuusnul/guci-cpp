//Membuat Guci
#include<windows.h>
#include<math.h>
#include<gl/glut.h>
#define PI 3.14

GLint circle_points=300;

void Lingkaran(GLfloat px, GLfloat py, GLfloat pz, GLfloat r){
GLint i;
GLdouble sudut;
glBegin(GL_LINE_STRIP);
for(i=0;i<circle_points;i++){
    sudut=2*PI*i/circle_points;
    glColor3ub(220,218,213);
    glVertex3f(px+r*cos(sudut),py,pz+r*sin(sudut));
    }
    glEnd();
}

void Guci(GLfloat radius1, GLfloat radius2, GLfloat radius3, GLfloat radius4, GLfloat radius5, GLfloat radius6){
GLint i;
GLdouble theta, ntheta, mtheta, otheta, inc = PI/50;
for(i=0;i<circle_points;i++){
    glBegin(GL_POLYGON);
    theta=(2*PI*i/circle_points);
    ntheta=(2*PI*(i+1)/circle_points);
    glVertex3f(0,0,0);
    glVertex3f(radius1*cos(ntheta),0,radius1*sin(ntheta));
    glVertex3f(radius1*cos(ntheta),0.1,radius1*sin(ntheta));
    glVertex3f(radius2*cos(ntheta),0.1,radius2*sin(ntheta));

    glVertex3f(radius2*cos(ntheta),0.8,radius2*sin(ntheta));
    glVertex3f(radius3*cos(ntheta),0.8,radius3*sin(ntheta));

    glVertex3f(radius3*cos(ntheta),1.1,radius3*sin(ntheta));
    glVertex3f(radius1*cos(ntheta),1.3,radius1*sin(ntheta));
    glVertex3f(radius4*cos(ntheta),1.4,radius4*sin(ntheta));

    glVertex3f(radius4*cos(ntheta),1.7,radius4*sin(ntheta));
    glVertex3f(radius1*cos(ntheta),2.2,radius1*sin(ntheta));
    glVertex3f(radius5*cos(ntheta),2.3,radius5*sin(ntheta));

    glVertex3f(radius1*cos(theta)*cos(PI+inc),4.2,radius1*cos(theta)*sin(PI+inc));

    glVertex3f(radius6*cos(theta)*cos(PI+inc),4.3,radius6*cos(theta)*sin(PI+inc));
    glVertex3f(radius5*cos(theta)*cos(PI+inc),4.31,radius5*cos(theta)*sin(PI+inc));



    glEnd();
    }
}

void Display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(220,218,213);
    Guci(0.5,0.4,0.3,0.25,0.2,0.6);
    Lingkaran(0,0,0,0.5);
    Lingkaran(0,0.1,0,0.5);
    Lingkaran(0,0.1,0,0.4);

    Lingkaran(0,0.8,0,0.4);
    Lingkaran(0,0.9,0,0.3);

    Lingkaran(0,1.1,0,0.3);
    Lingkaran(0,1.3,0,0.5);
    Lingkaran(0,1.4,0,0.25);

    Lingkaran(0,1.7,0,0.25);
    Lingkaran(0,2.2,0,0.5);
    Lingkaran(0,2.3,0,0.2);

    glFlush();
}

void reshape(int w, int h){
glViewport(0,0,(GLsizei)w, (GLsizei)h);
glMatrixMode(GL_PROJECTION);
glFrustum(-0.5*(GLfloat)w/h,0.5*(GLfloat)w/h, 0,1,0.6,5);
gluLookAt(0,-1,3,0,5,-100,0,1,0);
}

void init(void){
glClearColor(0,0,0,0);
glPolygonMode(GL_FRONT, GL_LINE);
glPolygonMode(GL_BACK, GL_LINE);
}

int main(int argc, char*argv[]){
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition (550,200);
glutCreateWindow("191110073_SriRahayuUsnulKhotimah");
init();
glutDisplayFunc(Display);
glutReshapeFunc(reshape);
glutMainLoop();
}
