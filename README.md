# SDL2-Ndk-Opengles-SampleApp

A Sample App to demonstrate integration of SDL2 on OpenGLES with NDK app.

Installation: Android SDK -> SDK tools -> NDK

* Clone the repo to directly jump into the coding in c/c++ for opengl with SDL2 library.
* GO to Build & run instructions to run the app.

OR

* Follow the bellow set up understand how it was done!

Set up:

Hello JNI : Sample from google

* File -> new -> import sample -> type "hello jni" -> select & finish
* Java Native Interface(JNI) compiled with -> Intel or x86 Application Binary Interface (ABI)
* run hello-jni.c

Using Library(SDL):

* SDL(Simple DirectMedia Layer) c/c++ library
* download "Hello JNI" source code from site and import project "android-project" and sync.
* build.gradle(app): add text "sourceSets {main { jni.srcDirs = []}}".
* Symbolic link: given for Windows (x64 or x86)
    * download Visual Studio 2005 redistributable package: contains the necessary prerequisites.
    * Link Shell Extension itself
    * link for both [Link](http://schinagl.priv.at/nt/hardlinkshellext/hardlinkshellext.html#download)
    * actual SDL source code rClick on content "pick link source" & create SDL(jni) folder & rClick "drop -> symbolic link"
* if symbolic link doesn't work then copy the content to SDL

* Android.mk(jni/src): change "YourSourceHere.c" to "main.c"
* Application.mk: App_ABI property to support more platforms (arm64-v8a armeabi armeabi-v7a x86 x86_64 mips mips64)
* Adding support for all the platforms gives the app better reach but will result in a bigger APK.
* add main.c

Build and run:
* open terminal & paste "cd app/src/main/jni"
* run "ndk-build NDK_LIBS_OUT=../jniLibs" or ndk bundle path + "ndk-build ..."
* do gradle sync and run app.
* Modifying Code(c/c++):
	* use instruction *(2). 
	* in case *(2) doesnt work, close the app in emulator then Build -> Make Project & rebuild.


# Disclaimer:

The project is created to help people doing initial set up to work with SDL2 in NDK(C/C++) Opengles app. people can edit or use it in whichever way possible to reach their requirements. 