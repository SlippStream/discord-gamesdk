"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.CreateFlags = exports.Result = exports._debug = exports.version = exports._Discord = void 0;
exports.runCallbacks = runCallbacks;
exports.create = create;
const activity_1 = require("./activity");
try {
    exports._Discord = require("../../build/Release/discord_gamesdk.node");
}
catch (e) {
    throw new Error(e + "\nDo you have discord_game_sdk.dll in your project root folder?");
}
exports.version = exports._Discord.getVersion();
/**
 * NOT FOR API USE
 */
exports._debug = false;
function runCallbacks() {
    exports._Discord.runCallbacks();
}
function create(clientId, createFlags = CreateFlags.Default) {
    return exports._Discord.discordCreate(clientId, createFlags);
}
var Result;
(function (Result) {
    Result[Result["Ok"] = 0] = "Ok";
    Result[Result["ServiceUnavailable"] = 1] = "ServiceUnavailable";
    Result[Result["InvalidVersion"] = 2] = "InvalidVersion";
    Result[Result["LockFailed"] = 3] = "LockFailed";
    Result[Result["InternalError"] = 4] = "InternalError";
    Result[Result["InvalidPayload"] = 5] = "InvalidPayload";
    Result[Result["InvalidCommand"] = 6] = "InvalidCommand";
    Result[Result["InvalidPermissions"] = 7] = "InvalidPermissions";
    Result[Result["NotFetched"] = 8] = "NotFetched";
    Result[Result["NotFound"] = 9] = "NotFound";
    Result[Result["Conflict"] = 10] = "Conflict";
    Result[Result["InvalidSecret"] = 11] = "InvalidSecret";
    Result[Result["InvalidJoinSecret"] = 12] = "InvalidJoinSecret";
    Result[Result["NoEligibleActivity"] = 13] = "NoEligibleActivity";
    Result[Result["InvalidInvite"] = 14] = "InvalidInvite";
    Result[Result["NotAuthenticated"] = 15] = "NotAuthenticated";
    Result[Result["InvalidAccessToken"] = 16] = "InvalidAccessToken";
    Result[Result["ApplicationMismatch"] = 17] = "ApplicationMismatch";
    Result[Result["InvalidDataUrl"] = 18] = "InvalidDataUrl";
    Result[Result["InvalidBase64"] = 19] = "InvalidBase64";
    Result[Result["NotFiltered"] = 20] = "NotFiltered";
    Result[Result["LobbyFull"] = 21] = "LobbyFull";
    Result[Result["InvalidLobbySecret"] = 22] = "InvalidLobbySecret";
    Result[Result["InvalidFilename"] = 23] = "InvalidFilename";
    Result[Result["InvalidFileSize"] = 24] = "InvalidFileSize";
    Result[Result["InvalidEntitlement"] = 25] = "InvalidEntitlement";
    Result[Result["NotInstalled"] = 26] = "NotInstalled";
    Result[Result["NotRunning"] = 27] = "NotRunning";
    Result[Result["InsufficientBuffer"] = 28] = "InsufficientBuffer";
    Result[Result["PurchaseCanceled"] = 29] = "PurchaseCanceled";
    Result[Result["InvalidGuild"] = 30] = "InvalidGuild";
    Result[Result["InvalidEvent"] = 31] = "InvalidEvent";
    Result[Result["InvalidChannel"] = 32] = "InvalidChannel";
    Result[Result["InvalidOrigin"] = 33] = "InvalidOrigin";
    Result[Result["RateLimited"] = 34] = "RateLimited";
    Result[Result["OAuth2Error"] = 35] = "OAuth2Error";
    Result[Result["SelectChannelTimeout"] = 36] = "SelectChannelTimeout";
    Result[Result["GetGuildTimeout"] = 37] = "GetGuildTimeout";
    Result[Result["SelectVoiceForceRequired"] = 38] = "SelectVoiceForceRequired";
    Result[Result["CaptureShortcutAlreadyListening"] = 39] = "CaptureShortcutAlreadyListening";
    Result[Result["UnauthorizedForAchievement"] = 40] = "UnauthorizedForAchievement";
    Result[Result["InvalidGiftCode"] = 41] = "InvalidGiftCode";
    Result[Result["PurchaseError"] = 42] = "PurchaseError";
    Result[Result["TransactionAborted"] = 43] = "TransactionAborted";
    Result[Result["DrawingInitFailed"] = 44] = "DrawingInitFailed";
})(Result || (exports.Result = Result = {}));
var CreateFlags;
(function (CreateFlags) {
    CreateFlags[CreateFlags["Default"] = 0] = "Default";
    CreateFlags[CreateFlags["NoRequireDiscord"] = 1] = "NoRequireDiscord";
})(CreateFlags || (exports.CreateFlags = CreateFlags = {}));
create(1248068953184534549n, 0);
(0, activity_1.updateActivity)({
    state: "help",
    details: "testing :)"
});
setInterval(() => {
    runCallbacks();
}, 1000 / 60);
