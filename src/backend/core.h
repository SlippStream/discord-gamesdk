#include <napi.h>
#include <assert.h>
#include <iostream>
#ifndef DISCORD
#define DISCORD
#include "include/discord.h"
#endif

using namespace std;

extern discord::Core *core;

namespace Discord
{
    void runCallbacksWrapped(Napi::CallbackInfo const &);
    Napi::Number createWrapped(Napi::CallbackInfo const &);
    Napi::Number getVersionWrapped(Napi::CallbackInfo const &);
}

Napi::Object Init(Napi::Env env, Napi::Object exports);