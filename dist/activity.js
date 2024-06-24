"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Activity = void 0;
const core_1 = require("./core");
var Activity;
(function (Activity) {
    let ActivityType;
    (function (ActivityType) {
        ActivityType[ActivityType["playing"] = 0] = "playing";
        ActivityType[ActivityType["streaming"] = 1] = "streaming";
        ActivityType[ActivityType["listening"] = 2] = "listening";
        ActivityType[ActivityType["watching"] = 3] = "watching";
        ActivityType[ActivityType["custom"] = 4] = "custom";
        ActivityType[ActivityType["competing"] = 5] = "competing";
    })(ActivityType = Activity.ActivityType || (Activity.ActivityType = {}));
    let ActivityActionType;
    (function (ActivityActionType) {
        ActivityActionType[ActivityActionType["join"] = 1] = "join";
        ActivityActionType[ActivityActionType["spectate"] = 2] = "spectate";
    })(ActivityActionType = Activity.ActivityActionType || (Activity.ActivityActionType = {}));
    let ActivityJoinRequestReply;
    (function (ActivityJoinRequestReply) {
        ActivityJoinRequestReply[ActivityJoinRequestReply["no"] = 0] = "no";
        ActivityJoinRequestReply[ActivityJoinRequestReply["yes"] = 1] = "yes";
        ActivityJoinRequestReply[ActivityJoinRequestReply["ignore"] = 2] = "ignore";
    })(ActivityJoinRequestReply = Activity.ActivityJoinRequestReply || (Activity.ActivityJoinRequestReply = {}));
})(Activity || (exports.Activity = Activity = {}));
const ac = {
    state: "pongo",
    details: "bongo"
};
core_1._DiscordInternal.create("1248068953184534549", 0);
core_1._DiscordInternal.updateActivity(ac);
