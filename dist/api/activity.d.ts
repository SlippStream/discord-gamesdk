type Int32 = number;
type Int64 = bigint;
export declare enum ActivityType {
    playing = 0,
    streaming = 1,
    listening = 2,
    watching = 3,
    custom = 4,
    competing = 5
}
export declare enum ActivityActionType {
    join = 1,
    spectate = 2
}
export declare enum ActivityJoinRequestReply {
    no = 0,
    yes = 1,
    ignore = 2
}
export type ActivitySecrets = {
    match?: string;
    join?: string;
    spectate?: string;
};
export type ActivityParty = {
    id?: string;
    size?: PartySize;
};
export type PartySize = {
    currentSize?: Int32;
    maxSize?: Int32;
};
export type ActivityAssets = {
    largeImage?: string;
    largeText?: string;
    smallImage?: string;
    smallText?: string;
};
export type ActivityTimestamps = {
    start?: Int64;
    end?: Int64;
};
export type Activity = {
    state?: string;
    details?: string;
    timestamps?: ActivityTimestamps;
    assets?: ActivityAssets;
    party?: ActivityParty;
    secrets?: ActivitySecrets;
    instance?: boolean;
};
export declare function updateActivity(activity: Activity): void;
export {};
