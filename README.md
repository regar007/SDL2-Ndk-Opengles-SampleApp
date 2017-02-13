# SDL2-Ndk-Opengles-SampleApp

A Sample App to demonstrate integration of SDL2 on OpenGLES with NDK app.

Installation: Android SDK -> SDK tools -> NDK

Hello JNI : Sample from google

* File -> new -> import sample -> type "hello jni" -> select & finish
* Java Native Interface(JNI) compiled with -> Intel or x86 Application Binary Interface (ABI)
* run hello-jni.c

Using Library(SDL):

* SDL(Simple DirectMedia Layer) c/c++ library
* download source code from site and import project "android-project" and sync
* build.gradle(app): add text "sourceSets {main { jni.srcDirs = []}}".
* Symbolic link: given for Windows (x64 or x86)
    * download Visual Studio 2005 redistributable package: contains the necessary prerequisites.
    * Link Shell Extension itself
    * link for both [Link](http://schinagl.priv.at/nt/hardlinkshellext/hardlinkshellext.html#download)
    * actual SDL source code rClick on content "pick link source" & create SDL(jni) folder & rClick "drop -> symbolic link"
    * if link doesn't work then copy the content to SDL

* Android.mk(jni/src): change "YourSourceHere.c" to "main.c"
* Application.mk: App_ABI property to support more platforms
* add main.c
* add folder asset and add image.bmp image to it.

Build and run:
* open terminal & paste "cd app/src/main/jni"
* run "ndk-build NDK_LIBS_OUT=../jniLibs" or ndk bundle path + "ndk-build ..."
* do gradle sync and run app.
* terminal build & close app in emulator then make project & rebuild to include changes to .c to .cpp files

