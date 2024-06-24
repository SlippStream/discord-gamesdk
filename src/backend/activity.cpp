#include "core.h"
#include "activity.h"

/**
 * @param info activity: Discord.Activity
 */
void Activity::updateActivityWrapped(Napi::CallbackInfo const &info)
{
    auto env = info.Env();

    if (info.Length() < 1)
        throw ERROR_BAD_ARGUMENTS;

    assert(info[0].IsObject());

    discord::Activity activity = *Activity::parseActivityFromObject(&info[0].As<Napi::Object>());

    core->ActivityManager().UpdateActivity(
        activity,
        [&info](discord::Result res)
        {
            if (res != discord::Result::Ok)
                cout << "update activity failed!";
            // TODO: Handle Callback?
            // TODO: See Napi's AsyncContext
            // info[1].As<Napi::Function>().MakeCallback();
        });
}

Napi::Object Activity::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("updateActivity", Napi::Function::New(env, Activity::updateActivityWrapped));
    return exports;
}

discord::Activity *Activity::parseActivityFromObject(Napi::Object *obj)
{
    auto activity = new discord::Activity();
    if (obj->Has("state"))
        activity->SetState(obj->Get("state").As<Napi::String>().Utf8Value().c_str());

    if (obj->Has("details"))
        activity->SetDetails(obj->Get("details").As<Napi::String>().Utf8Value().c_str());
    if (obj->Has("instance"))
        activity->SetInstance(obj->Get("instance").As<Napi::Boolean>().Value());

    if (obj->Has("assets"))
    {
        auto newAssets = obj->Get("assets").As<Napi::Object>();
        auto d_assets = activity->GetAssets();
        if (newAssets.Has("largeImage"))
            d_assets.SetLargeImage(newAssets.Get("largeImage").As<Napi::String>().Utf8Value().c_str());
        if (newAssets.Has("smallImage"))
            d_assets.SetSmallImage(newAssets.Get("smallImage").As<Napi::String>().Utf8Value().c_str());
        if (newAssets.Has("largeText"))
            d_assets.SetLargeText(newAssets.Get("largeText").As<Napi::String>().Utf8Value().c_str());
        if (newAssets.Has("smallText"))
            d_assets.SetSmallText(newAssets.Get("smallText").As<Napi::String>().Utf8Value().c_str());
    }

    if (obj->Has("timestamps"))
    {
        auto newTimestamps = obj->Get("timestamps").As<Napi::Object>();
        auto d_timestamps = activity->GetTimestamps();
        if (newTimestamps.Has("start"))
            d_timestamps.SetStart(newTimestamps.Get("start").As<Napi::Number>().Int64Value());
        if (newTimestamps.Has("end"))
            d_timestamps.SetEnd(newTimestamps.Get("end").As<Napi::Number>().Int64Value());
    }

    if (obj->Has("party"))
    {
        auto newParty = obj->Get("party").As<Napi::Object>();
        auto d_party = activity->GetParty();
        if (newParty.Has("id"))
            d_party.SetId(newParty.Get("id").As<Napi::String>().Utf8Value().c_str());
        if (newParty.Has("size"))
        {
            auto newPartySize = newParty.Get("size").As<Napi::Object>();
            auto d_size = d_party.GetSize();
            if (newPartySize.Has("currentSize"))
                d_size.SetCurrentSize(newPartySize.Get("currentSize").As<Napi::Number>().Int32Value());
            if (newPartySize.Has("maxSize"))
                d_size.SetMaxSize(newPartySize.Get("maxSize").As<Napi::Number>().Int32Value());
        }
    }
    if (obj->Has("secrets"))
    {
        auto newSecrets = obj->Get("secrets").As<Napi::Object>();
        auto d_secrets = activity->GetSecrets();
        if (newSecrets.Has("match"))
            d_secrets.SetMatch(newSecrets.Get("match").As<Napi::String>().Utf8Value().c_str());
        if (newSecrets.Has("join"))
            d_secrets.SetJoin(newSecrets.Get("join").As<Napi::String>().Utf8Value().c_str());
        if (newSecrets.Has("spectate"))
            d_secrets.SetSpectate(newSecrets.Get("spectate").As<Napi::String>().Utf8Value().c_str());
    }

    return activity;
}