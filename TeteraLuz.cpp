#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
int b;

double X1=0.329412f, X2=0.223529f, X3=0.027451f, Y1=0.780392f, Y2=0.568627f, Y3=0.113725f, Z1= 0.992157f, Z2=0.941176f, Z3 =0.807843f, S=27.8974f;
void ponermaterial ();
void keyboard(unsigned char key, int x, int y);

void init(void)
{
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0); //Activamos las luces en 0
glDepthFunc(GL_LESS); //comparación de profundidad
glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
}

void reshape(int w, int h)
{
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
glLoadIdentity();
// Usamos proyeccion ortogonal
glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
glLoadIdentity();
}

void display(void)
{
	GLfloat mat_ambient[] = {X1 ,X2 , X3};
	GLfloat mat_diffuse[] = {Z1, Z2 , Z3};
	GLfloat mat_specular[] = {Y1, Y2, Y3};
	GLfloat shine[] = {S};
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode( GL_MODELVIEW_MATRIX );
glLoadIdentity();

// Rotacion de 25 grados en torno al eje x
glRotated(25.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
glRotated(-30.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
glPushMatrix();

glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);

glMaterialfv(GL_FRONT, GL_SHININESS, shine);
//setMaterial
glutSolidTeapot(110.0);
glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    
    {
	case '1': //JADE
	b=1;
			ponermaterial();
			break;
	case '2': //OBSIDIAN
	b=2;
			ponermaterial();
			break;
    case '3' : //PEARL
    b=3;
            ponermaterial();
        break;
    case '4' : //RUBY
    b=4;
          ponermaterial();
        break;
    case '5' : //TURQUOISE
    b=5;
        ponermaterial();
        break;
    }

    glutPostRedisplay(); // actualización de visualización
}

void ponermaterial()
{
	if (b==1) //JADE
	{
		X1=0.135; X2=0.2225; X3=0.1575; Y1=0.54; Y2=0.89; Y3=0.63; Z1=0.316228; Z2=0.316228; Z3=0.316228; S=0.1;
		}
	if (b==2) //OBSIDIAN
	{
		X1=0.05375; X2=0.05; X3=0.06625; Y1=0.18275; Y2=0.17; Y3=0.22525; Z1=0.332741; Z2=0.328634; Z3=0.346435; S=0.3;
		}
		if (b==3) //PEARL
	{
		X1=0.25; X2=0.20725; X3=0.20725; Y1=1.0; Y2=0.829; Y3=0.829; Z1=0.296648; Z2=0.296648; Z3=0.296648; S=0.088;
		}
	if (b==4) //RUBY
	{
		X1=0.1745; X2=0.01175; X3=0.01175; Y1=0.61424; Y2=0.04136; Y3=0.04136; Z1=0.727811; Z2=0.626959; Z3=0.625969; S=0.6;
		}
	if (b==5) //TURQUOISE
	{
		X1=0.1; X2=0.18725; X3=0.01745; Y1=0.396; Y2=0.74151; Y3=0.69102; Z1=0.297254; Z2=0.30829; Z3=0.306678; S=0.1;
		}
	
	}

int main(int argc, char **argv)
{
// Inicializo OpenGL
glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
glutInitWindowSize (800, 600);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
glutInitWindowPosition (0, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
glutCreateWindow ("TETERA LUZ");
// Inicializamos el sistema
init();
glutDisplayFunc(display);
glutKeyboardFunc(keyboard); //invoca funcion de teclado
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
