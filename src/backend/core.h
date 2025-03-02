#if NAPI_VERSION <= 5
#define NAPI_VERSION 6
#endif
#include <napi.h>
#include <assert.h>
#include <iostream>

#ifndef DISCORD
#define DISCORD
#include "include/discord.h"
#endif
#include <iostream>

using namespace std;

extern discord::Core *core;

namespace Discord
{
    void runCallbacksWrapped(Napi::CallbackInfo const &);
    Napi::Number createWrapped(Napi::CallbackInfo const &);
    Napi::Number getVersionWrapped(Napi::CallbackInfo const &);
}

Napi::Object Init(Napi::Env env, Napi::Object exports);