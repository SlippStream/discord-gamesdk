#include <napi.h>

namespace Activity
{
    discord::Activity *parseActivityFromObject(Napi::Object *);
    void updateActivityWrapped(const Napi::CallbackInfo &);
    Napi::Object Init(Napi::Env env, Napi::Object exports);
}