"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.ActivityJoinRequestReply = exports.ActivityActionType = exports.ActivityType = void 0;
exports.updateActivity = updateActivity;
const core_1 = require("./core");
var ActivityType;
(function (ActivityType) {
    ActivityType[ActivityType["playing"] = 0] = "playing";
    ActivityType[ActivityType["streaming"] = 1] = "streaming";
    ActivityType[ActivityType["listening"] = 2] = "listening";
    ActivityType[ActivityType["watching"] = 3] = "watching";
    ActivityType[ActivityType["custom"] = 4] = "custom";
    ActivityType[ActivityType["competing"] = 5] = "competing";
})(ActivityType || (exports.ActivityType = ActivityType = {}));
var ActivityActionType;
(function (ActivityActionType) {
    ActivityActionType[ActivityActionType["join"] = 1] = "join";
    ActivityActionType[ActivityActionType["spectate"] = 2] = "spectate";
})(ActivityActionType || (exports.ActivityActionType = ActivityActionType = {}));
var ActivityJoinRequestReply;
(function (ActivityJoinRequestReply) {
    ActivityJoinRequestReply[ActivityJoinRequestReply["no"] = 0] = "no";
    ActivityJoinRequestReply[ActivityJoinRequestReply["yes"] = 1] = "yes";
    ActivityJoinRequestReply[ActivityJoinRequestReply["ignore"] = 2] = "ignore";
})(ActivityJoinRequestReply || (exports.ActivityJoinRequestReply = ActivityJoinRequestReply = {}));
function updateActivity(activity) {
    core_1._Discord.updateActivity(activity);
}
