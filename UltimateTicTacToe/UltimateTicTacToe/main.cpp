#ifdef _WIN32
  #include "glut.h"
#else
  #ifdef __APPLE__
    #include <GLUT/glut.h>
  #else
    #include <GL/glut.h>
  #endif
#endif

#include <cstdlib>
#include "Game.h"

int screen_x = 810, screen_y = 810;
Game * game;

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
    
  game->draw();

  glutSwapBuffers();
}


void keyboard(unsigned char c, int x, int y)
{
  switch (c) 
    {
    case 'q':
    case 27: // escape character means to quit the program
      exit(0);
      break;
    case 'r':
        // restart the game
        delete game;
        game = new Game(5, 5, 800);
        break;
    default:
      return; // if we don't care, return without glutPostRedisplay()
    }

  glutPostRedisplay();
}

void reshape(int w, int h)
{
  // Reset our global variables to the new width and height.
  screen_x = w;
  screen_y = h;

  // Set the pixel resolution of the final picture (Screen coordinates).
  glViewport(0, 0, w, h);

  // Set the projection mode to 2D orthographic, and set the world coordinates:
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, 0, h);
  glMatrixMode(GL_MODELVIEW);

}

void mouse(int mouse_button, int state, int x, int y)
{
    if(mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(game->click(x, screen_y - y))
        {
            glutPostRedisplay();
        }
    }
    else if(mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        
    }
    else if(mouse_button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        
    }
    else if(mouse_button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
    {
        
    }
}


int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(810, 810);
  glutInitWindowPosition(50, 50);

  int fullscreen = 0;
  if (fullscreen) 
    {
      glutGameModeString("800x600:32");
      glutEnterGameMode();
    } 
  else 
    {
      glutCreateWindow("Ultimate Tic Tac Toe");
    }

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);

  glClearColor(1, 1, 1, 0); // background color
    
    game = new Game(5, 5, 800);

  glutMainLoop();

  return 0;
}
