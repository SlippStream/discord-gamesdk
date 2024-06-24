#include "core.h"

extern discord::Core *core{};

void Discord::runCallbacksWrapped(Napi::CallbackInfo const &info)
{
    ::core->RunCallbacks();
}

/**
 * @param info clientId: Number, createFlags?: Number
 */
Napi::Number Discord::createWrapped(Napi::CallbackInfo const &info)
{
    auto env = info.Env();
    discord::ClientId clientId;
    discord::CreateFlags createFlags;

    if (info.Length() < 2)
    {
        if (info.Length() < 1)
            throw ERROR_BAD_ARGUMENTS;

        assert(info[0].IsNumber());
        createFlags = discord::CreateFlags::Default;
    }
    else
    {
        assert(info[0].IsNumber());
        assert(info[1].IsNumber());

        createFlags = (discord::CreateFlags)info[1].As<Napi::Number>().Int64Value();
    }
    clientId = (discord::ClientId)info[0].As<Napi::Number>().Int64Value();

    return Napi::Number::New(env,
                             (double)discord::Core::Create(
                                 clientId,
                                 (uint64_t)createFlags,
                                 &core));
}

Napi::Number Discord::getVersionWrapped(Napi::CallbackInfo const &info)
{
    return Napi::Number::New(info.Env(), DISCORD_VERSION);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("getVersion", Napi::Function::New(env, Discord::getVersionWrapped));
    exports.Set("create", Napi::Function::New(env, Discord::createWrapped));
    exports.Set("runCallbacks", Napi::Function::New(env, Discord::runCallbacksWrapped));
    return exports;
}

NODE_API_MODULE(discordgamesdk, Init)