#include "core.h"
#include "activity.h"

extern discord::Core *core{};

void Discord::runCallbacksWrapped(Napi::CallbackInfo const &info)
{
    ::core->RunCallbacks();
}

/**
 * @param info clientId: BigInt, createFlags?: Discord.CreateFlags
 */
Napi::Number Discord::createWrapped(Napi::CallbackInfo const &info)
{
    std::cout << "Creating wrapped client...\n";
    auto env = info.Env();
    bool lossless = false;
    discord::ClientId clientId;
    discord::CreateFlags createFlags;

    if (info.Length() < 2)
    {
        if (info.Length() < 1)
            Napi::Error::New(env, "Too few arguments!").ThrowAsJavaScriptException();

        createFlags = discord::CreateFlags::Default;
    }
    else
    {
        assert(info[1].IsNumber());

        createFlags = (discord::CreateFlags)info[1].As<Napi::Number>().Int64Value();
    }
    assert(info[0].IsBigInt());

    clientId = (discord::ClientId)info[0].As<Napi::BigInt>().Uint64Value(&lossless);

    std::cout << "Client #" << clientId << " wrapping complete! Result: " << (uint64_t)createFlags << "\n";
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
    Napi::Object obj;
    std::cout << "Initializing Core...\n";
    Napi::Function getVersion = Napi::Function::New(env, Discord::getVersionWrapped);
    exports.Set("getVersion", getVersion);
    exports.Set("discordCreate", Napi::Function::New(env, Discord::createWrapped));
    exports.Set("runCallbacks", Napi::Function::New(env, Discord::runCallbacksWrapped));
    obj = Activity::Init(env, exports);
    std::cout << "Core Init successful!\n";
    return exports;
}

NODE_API_MODULE(discordgamesdk, Init)
