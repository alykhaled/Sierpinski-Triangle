#include <vector>
#include <iostream>
#include <utility>
#include <stdlib.h>    
#include <GL/glut.h>
using namespace std;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT, GL_LINE);
    vector<pair<int, int>> vertices(3);
    vertices[0] = { 0,0 };      //First  Vertix coordinates
    vertices[1] = { 300,0 };    //Second Vertix coordinates
    vertices[2] = { 150,300 };  //Third  Vertix coordinates

    glBegin(GL_POINTS);
    glPointSize(10.0f);
    glVertex2i(vertices[0].first, vertices[0].second); //Draw First  Vertix
    glVertex2i(vertices[1].first, vertices[1].second); //Draw Second Vertix
    glVertex2i(vertices[2].first, vertices[2].second); //Draw Third  Vertix
    
    glVertex2i((vertices[0].first + vertices[1].first) / 2, (vertices[0].second + vertices[1].second) / 2); //Draw Midpoint between First vertix and second verix 
    
    pair<int, int> lastPoint = { (vertices[0].first + vertices[1].first) / 2, (vertices[0].second + vertices[1].second) / 2 }; //Store the last point
    for (int i = 0; i < 10000; i++)
    {
        int randomIndex = rand() % 3; //Get random number between 0 and 2
        glVertex2i((vertices[randomIndex].first + lastPoint.first) / 2, (vertices[randomIndex].second + lastPoint.second) / 2); //Draw Midpoint between random vertix and the last point
        lastPoint.first = (vertices[randomIndex].first + lastPoint.first) / 2;      //Store the new last point X
        lastPoint.second = (vertices[randomIndex].second + lastPoint.second) / 2;   //Store the new last point Y
    }
    glEnd();
    glFlush();  
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("The Sierpinski Triangle");
    glOrtho(0, 300, 0, 300, -1, 1);  
    glutInitWindowSize(800, 800);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}