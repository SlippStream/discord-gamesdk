#include <napi.h>

namespace Activity
{
    discord::Activity *unwrapActivityObject(Napi::Object *);
    void updateActivityWrapped(const Napi::CallbackInfo &);
    Napi::Object Init(Napi::Env, Napi::Object);
}