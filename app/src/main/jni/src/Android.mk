LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL
ION_PATH := ../ION

LOCAL_ION_C_INCLUDES := $(LOCAL_PATH)/$(ION_PATH)
LOCAL_C__INCLUDES := $(LOCAL_PATH)/$(ION_PATH)

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
	main.cpp

LOCAL_SHARED_LIBRARIES := SDL2

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

#comment it for main.c
LOCAL_CFLAGS := -std=c++11

include $(BUILD_SHARED_LIBRARY)
#include $(LOCAL_ION_C_INCLUDES)
