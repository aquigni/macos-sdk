//
//  GKError.h
//  Game Center
//
//  Copyright 2010-2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GameKit/GKDefines.h>

GK_EXTERN_WEAK NSString * __nonnull GKErrorDomain;

typedef NS_ENUM(NSInteger, GKErrorCode) {
    GKErrorUnknown                              = 1,
    GKErrorCancelled                            = 2,
    GKErrorCommunicationsFailure                = 3,
    GKErrorUserDenied                           = 4,
    GKErrorInvalidCredentials                   = 5,
    GKErrorNotAuthenticated                     = 6,
    GKErrorAuthenticationInProgress             = 7,
    GKErrorInvalidPlayer                        = 8,
    GKErrorScoreNotSet                          = 9,
    GKErrorParentalControlsBlocked              = 10,
    GKErrorPlayerStatusExceedsMaximumLength     = 11,
    GKErrorPlayerStatusInvalid                  = 12,
    GKErrorMatchRequestInvalid                  = 13,
    GKErrorUnderage                             = 14,
    GKErrorGameUnrecognized                     = 15,
    GKErrorNotSupported                         = 16,
    GKErrorInvalidParameter                     = 17,
    GKErrorUnexpectedConnection                 = 18,
    GKErrorChallengeInvalid                     = 19,
    GKErrorTurnBasedMatchDataTooLarge           = 20,
    GKErrorTurnBasedTooManySessions             = 21,
    GKErrorTurnBasedInvalidParticipant          = 22,
    GKErrorTurnBasedInvalidTurn                 = 23,
    GKErrorTurnBasedInvalidState                = 24,
    GKErrorInvitationsDisabled                  = 25,
    GKErrorPlayerPhotoFailure                   = 26,
    GKErrorUbiquityContainerUnavailable         = 27,
    GKErrorMatchNotConnected                    = 28,
    GKErrorGameSessionRequestInvalid            = 29,
    GKErrorRestrictedToAutomatch                = 30
};

// FIXME: do we need to merge this into GKError?

GK_EXTERN_WEAK NSString *__nonnull GKTournamentErrorDomain;

typedef NS_ENUM(NSInteger, GKTournamentErrorCode) {
    GKTournamentErrorUnknown                            = 1,
    GKTournamentErrorInvalidTournament                  = 2,
    GKTournamentErrorRegistrationNotOpen                = 3,
    GKTournamentErrorPlayerNotRegistered                = 4,
    GKTournamentErrorInvalidTournamentState             = 5,
    GKTournamentErrorInvalidParticipantState            = 6,
    GKTournamentErrorAlreadyRegistered                  = 7,
    GKTournamentErrorDeviceConflict                     = 8,
    GKTournamentErrorLocalPlayerCustomTournamentLimit   = 9,
    GKTournamentErrorNotEnoughPlayers                   = 10,      // Tournament could not start because there aren't enough players
    GKTournamentErrorCheatingDetected                   = 11,      // Cheating was detected in this tournament instance
    GKTournamentErrorInvalidTryToken                    = 12,
    GKTournamentErrorNetworkError                       = 13,      // Network error

    // Below are temporary for the CloudKit prototype.
    GKTournamentErrorNotSignedIntoICloud,
    GKTournamentErrorCKServerRecordChanged,
};
