//
// Created by ashokr on 8/6/2016.
//
//modification done in jni/src/Android.mk
//changed YourSourceFile.c to main.cpp
//added LOCAL_CFLAGS := -std=c++11
//
//modification done in jni/src/Application.mk
//changed APP_STL := stlport_static to gnustl_static
//

/*Additional Notes:
By default the SDL 2.0 android project is setup to use OpenGL ES 1. Try adding a call to glGenerateMipmap(GL_TEXTURE_2D);
This should cause a build error. To use OpenGL ES 2.0 add the following to your Android.mk file.

LOCAL_CFLAGS += -DGL_GLEXT_PROTOTYPES
LOCAL_LDLIBS := -ldl -lGLESv1_CM -lGLESv2 -llog
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "SDL.h"

//#include "ion/gfx/attributearray.h"

/*header file for openGL*/
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <string>

//for graphics
#include <memory>

using namespace std;

class Graphics {
    /*This method update the screen*/
    public:
        void update(){
            glClearColor((rand() % 256)/256.0f, (rand() % 256)/ 256.0f, (rand() % 256)/ 256.0f, 1 );
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        }
};

int main(int argc, char *argv[])
{
    SDL_Window* window = 0;
    SDL_GLContext gl = 0;

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
      fprintf(stderr,"\nUnable to initialize SDL: %s\n",SDL_GetError());
      return 1;
    }

    //printing a string
    string s = "This is on stl :: string";
    SDL_Log("%s \n", s.c_str());

    shared_ptr<Graphics> graphics;
    graphics = shared_ptr<Graphics>(new Graphics());

    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

    SDL_DisplayMode mode;
    SDL_GetDisplayMode(0,0,&mode);
    int width = mode.w;
    int height = mode.h;

    SDL_Log("Width = %d, Heigh = %d. \n",width,height);

    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL,1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);

    window = SDL_CreateWindow("COLORED SCREEN",0,0,width,height,SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_RESIZABLE);

    if(window == 0)
    {
        SDL_Log("Failed to create window.");
        SDL_Quit();
        return 1;
    }

    //Create an opengl context
    gl = SDL_GL_CreateContext(window);

    /*Main Render Loop*/
    Uint8 done = 0;
    SDL_Event event;
    int count = 0;
    while(!done)
    {
        /*Check for events*/
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT || event.type == SDL_KEYDOWN || event.type == SDL_FINGERDOWN)
            {
                done = 1;
            }
        }

        SDL_Log("%d\n",count++);

        graphics->update();

        SDL_GL_SwapWindow(window);
        SDL_Delay(1000);
    }

    exit(0);
}