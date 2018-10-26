#include <GL/gl.h>
#include <GL/glut.h>
#include <OBJ_Loader.h>
#include <SOIL.h>

GLfloat wingAngle = 0.0f;
GLfloat wingFactor = 5.0f;

GLuint leftWing_tex;
GLuint rightWing_tex;

GLuint leftWing_tex_list;
GLuint rightWing_tex_list;
GLuint bFlyBody_tex_list;

int cont = 0;

void desenhaBorboleta()
{

    glScalef(0.7, 0.7, 0.7);

    glTranslatef(0.0, 2.0, 0.0);

    if (wingAngle == 35.0)
    {
        wingFactor = -wingFactor;
    }
    else if (wingAngle == -35.0)
    {
        wingFactor = -wingFactor;
    }

    wingAngle = wingAngle + wingFactor;

    glPushMatrix();
    
    glRotatef(wingAngle, 0.0f, 0.0f, 1.0f);

    //chamando list left
    glCallList(leftWing_tex_list);

    glPopMatrix();

    glPushMatrix();

    glRotatef(-wingAngle, 0.0f, 0.0f, 1.0f);

    // chamar lista right wing
    glCallList(rightWing_tex_list);

    glPopMatrix();

    // chamar lista body
    glCallList(bFlyBody_tex_list);

}

void generateBFLists(){

    leftWing_tex_list = glGenLists(1);
    glNewList(leftWing_tex_list, GL_COMPILE);

    objl::Loader loader;

    loader.LoadFile("Assets/leftWing.obj");

    objl::Mesh curMesh = loader.LoadedMeshes[0];

    //if (cont == 0)
    //{
        leftWing_tex = SOIL_load_OGL_texture(
            "Assets/texEsq.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y);
    //}

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, leftWing_tex);

    glBegin(GL_TRIANGLES);
    for (int j = 0; j < curMesh.Indices.size(); j += 3)
    {

        glColor3f(curMesh.MeshMaterial.Kd.X, curMesh.MeshMaterial.Kd.Y, curMesh.MeshMaterial.Kd.Z);
        glTexCoord2d(curMesh.Vertices[curMesh.Indices[j]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j]].TextureCoordinate.Y);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j]].Position.X, curMesh.Vertices[curMesh.Indices[j]].Position.Y, curMesh.Vertices[curMesh.Indices[j]].Position.Z);

        glTexCoord2d(curMesh.Vertices[curMesh.Indices[j + 1]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j + 1]].TextureCoordinate.Y);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j + 1]].Position.X, curMesh.Vertices[curMesh.Indices[j + 1]].Position.Y, curMesh.Vertices[curMesh.Indices[j + 1]].Position.Z);

        glTexCoord2d(curMesh.Vertices[curMesh.Indices[j + 2]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j + 2]].TextureCoordinate.Y);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j + 2]].Position.X, curMesh.Vertices[curMesh.Indices[j + 2]].Position.Y, curMesh.Vertices[curMesh.Indices[j + 2]].Position.Z);
    }
    glEnd();

    glEndList();

    rightWing_tex_list = glGenLists(1);
    glNewList(rightWing_tex_list, GL_COMPILE);

    loader.LoadFile("Assets/rightWing.obj");

    //if (cont == 0)
    //{
        rightWing_tex = SOIL_load_OGL_texture(
            "Assets/texDir.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y);
        cont++;
    //}
    curMesh = loader.LoadedMeshes[0];

    glBindTexture(GL_TEXTURE_2D, rightWing_tex);

    glBegin(GL_TRIANGLES);
    for (int j = 0; j < curMesh.Indices.size(); j += 3)
    {

        glColor3f(curMesh.MeshMaterial.Kd.X, curMesh.MeshMaterial.Kd.Y, curMesh.MeshMaterial.Kd.Z);
        glTexCoord2d(curMesh.Vertices[curMesh.Indices[j]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j]].TextureCoordinate.Y);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j]].Position.X, curMesh.Vertices[curMesh.Indices[j]].Position.Y, curMesh.Vertices[curMesh.Indices[j]].Position.Z);

        glTexCoord2d(curMesh.Vertices[curMesh.Indices[j + 1]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j + 1]].TextureCoordinate.Y);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j + 1]].Position.X, curMesh.Vertices[curMesh.Indices[j + 1]].Position.Y, curMesh.Vertices[curMesh.Indices[j + 1]].Position.Z);

        glTexCoord2d(curMesh.Vertices[curMesh.Indices[j + 2]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j + 2]].TextureCoordinate.Y);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j + 2]].Position.X, curMesh.Vertices[curMesh.Indices[j + 2]].Position.Y, curMesh.Vertices[curMesh.Indices[j + 2]].Position.Z);
    }
    glEnd();

    glEndList();

    bFlyBody_tex_list = glGenLists(1);
    glNewList(bFlyBody_tex_list, GL_COMPILE);

    loader.LoadFile("Assets/bFlyBody.obj");

    curMesh = loader.LoadedMeshes[0];

    glBegin(GL_TRIANGLES);
    for (int j = 0; j < curMesh.Indices.size(); j += 3)
    {

        glColor3f(curMesh.MeshMaterial.Kd.X, curMesh.MeshMaterial.Kd.Y, curMesh.MeshMaterial.Kd.Z);
        //glTexCoord2d(curMesh.Vertices[curMesh.Indices[j]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j]].TextureCoordinate.Y);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j]].Position.X, curMesh.Vertices[curMesh.Indices[j]].Position.Y, curMesh.Vertices[curMesh.Indices[j]].Position.Z);

        //glTexCoord2d(curMesh.Vertices[curMesh.Indices[j + 1]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j + 1]].TextureCoordinate.Y);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j + 1]].Position.X, curMesh.Vertices[curMesh.Indices[j + 1]].Position.Y, curMesh.Vertices[curMesh.Indices[j + 1]].Position.Z);

        //glTexCoord2d(curMesh.Vertices[curMesh.Indices[j + 2]].TextureCoordinate.X, curMesh.Vertices[curMesh.Indices[j + 2]].TextureCoordinate.Y);
        glVertex3f(curMesh.Vertices[curMesh.Indices[j + 2]].Position.X, curMesh.Vertices[curMesh.Indices[j + 2]].Position.Y, curMesh.Vertices[curMesh.Indices[j + 2]].Position.Z);
    }
    glEnd();

    glEndList();

}