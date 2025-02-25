#if defined _SteamWorks_Included
 #endinput
#endif
#define _SteamWorks_Included

/* results from UserHasLicenseForApp */
enum EUserHasLicenseForAppResult
{
	k_EUserHasLicenseResultHasLicense = 0,					// User has a license for specified app
	k_EUserHasLicenseResultDoesNotHaveLicense = 1,			// User does not have a license for the specified app
	k_EUserHasLicenseResultNoAuth = 2,						// User has not been authenticated
};

/* General result codes */
enum EResult
{
	k_EResultOK	= 1,							// success
	k_EResultFail = 2,							// generic failure 
	k_EResultNoConnection = 3,					// no/failed network connection
//	k_EResultNoConnectionRetry = 4,				// OBSOLETE - removed
	k_EResultInvalidPassword = 5,				// password/ticket is invalid
	k_EResultLoggedInElsewhere = 6,				// same user logged in elsewhere
	k_EResultInvalidProtocolVer = 7,			// protocol version is incorrect
	k_EResultInvalidParam = 8,					// a parameter is incorrect
	k_EResultFileNotFound = 9,					// file was not found
	k_EResultBusy = 10,							// called method busy - action not taken
	k_EResultInvalidState = 11,					// called object was in an invalid state
	k_EResultInvalidName = 12,					// name is invalid
	k_EResultInvalidEmail = 13,					// email is invalid
	k_EResultDuplicateName = 14,				// name is not unique
	k_EResultAccessDenied = 15,					// access is denied
	k_EResultTimeout = 16,						// operation timed out
	k_EResultBanned = 17,						// VAC2 banned
	k_EResultAccountNotFound = 18,				// account not found
	k_EResultInvalidSteamID = 19,				// steamID is invalid
	k_EResultServiceUnavailable = 20,			// The requested service is currently unavailable
	k_EResultNotLoggedOn = 21,					// The user is not logged on
	k_EResultPending = 22,						// Request is pending (may be in process, or waiting on third party)
	k_EResultEncryptionFailure = 23,			// Encryption or Decryption failed
	k_EResultInsufficientPrivilege = 24,		// Insufficient privilege
	k_EResultLimitExceeded = 25,				// Too much of a good thing
	k_EResultRevoked = 26,						// Access has been revoked (used for revoked guest passes)
	k_EResultExpired = 27,						// License/Guest pass the user is trying to access is expired
	k_EResultAlreadyRedeemed = 28,				// Guest pass has already been redeemed by account, cannot be acked again
	k_EResultDuplicateRequest = 29,				// The request is a duplicate and the action has already occurred in the past, ignored this time
	k_EResultAlreadyOwned = 30,					// All the games in this guest pass redemption request are already owned by the user
	k_EResultIPNotFound = 31,					// IP address not found
	k_EResultPersistFailed = 32,				// failed to write change to the data store
	k_EResultLockingFailed = 33,				// failed to acquire access lock for this operation
	k_EResultLogonSessionReplaced = 34,
	k_EResultConnectFailed = 35,
	k_EResultHandshakeFailed = 36,
	k_EResultIOFailure = 37,
	k_EResultRemoteDisconnect = 38,
	k_EResultShoppingCartNotFound = 39,			// failed to find the shopping cart requested
	k_EResultBlocked = 40,						// a user didn't allow it
	k_EResultIgnored = 41,						// target is ignoring sender
	k_EResultNoMatch = 42,						// nothing matching the request found
	k_EResultAccountDisabled = 43,
	k_EResultServiceReadOnly = 44,				// this service is not accepting content changes right now
	k_EResultAccountNotFeatured = 45,			// account doesn't have value, so this feature isn't available
	k_EResultAdministratorOK = 46,				// allowed to take this action, but only because requester is admin
	k_EResultContentVersion = 47,				// A Version mismatch in content transmitted within the Steam protocol.
	k_EResultTryAnotherCM = 48,					// The current CM can't service the user making a request, user should try another.
	k_EResultPasswordRequiredToKickSession = 49,// You are already logged in elsewhere, this cached credential login has failed.
	k_EResultAlreadyLoggedInElsewhere = 50,		// You are already logged in elsewhere, you must wait
	k_EResultSuspended = 51,					// Long running operation (content download) suspended/paused
	k_EResultCancelled = 52,					// Operation canceled (typically by user: content download)
	k_EResultDataCorruption = 53,				// Operation canceled because data is ill formed or unrecoverable
	k_EResultDiskFull = 54,						// Operation canceled - not enough disk space.
	k_EResultRemoteCallFailed = 55,				// an remote call or IPC call failed
	k_EResultPasswordUnset = 56,				// Password could not be verified as it's unset server side
	k_EResultExternalAccountUnlinked = 57,		// External account (PSN, Facebook...) is not linked to a Steam account
	k_EResultPSNTicketInvalid = 58,				// PSN ticket was invalid
	k_EResultExternalAccountAlreadyLinked = 59,	// External account (PSN, Facebook...) is already linked to some other account, must explicitly request to replace/delete the link first
	k_EResultRemoteFileConflict = 60,			// The sync cannot resume due to a conflict between the local and remote files
	k_EResultIllegalPassword = 61,				// The requested new password is not legal
	k_EResultSameAsPreviousValue = 62,			// new value is the same as the old one ( secret question and answer )
	k_EResultAccountLogonDenied = 63,			// account login denied due to 2nd factor authentication failure
	k_EResultCannotUseOldPassword = 64,			// The requested new password is not legal
	k_EResultInvalidLoginAuthCode = 65,			// account login denied due to auth code invalid
	k_EResultAccountLogonDeniedNoMail = 66,		// account login denied due to 2nd factor auth failure - and no mail has been sent
	k_EResultHardwareNotCapableOfIPT = 67,		// 
	k_EResultIPTInitError = 68,					// 
	k_EResultParentalControlRestricted = 69,	// operation failed due to parental control restrictions for current user
	k_EResultFacebookQueryError = 70,			// Facebook query returned an error
	k_EResultExpiredLoginAuthCode = 71,			// account login denied due to auth code expired
	k_EResultIPLoginRestrictionFailed = 72,
	k_EResultAccountLockedDown = 73,
	k_EResultAccountLogonDeniedVerifiedEmailRequired = 74,
	k_EResultNoMatchingURL = 75,
	k_EResultBadResponse = 76,					// parse failure, missing field, etc.
	k_EResultRequirePasswordReEntry = 77,		// The user cannot complete the action until they re-enter their password
	k_EResultValueOutOfRange = 78,				// the value entered is outside the acceptable range
	k_EResultUnexpectedError = 79,				// something happened that we didn't expect to ever happen
	k_EResultDisabled = 80,						// The requested service has been configured to be unavailable
	k_EResultInvalidCEGSubmission = 81,			// The set of files submitted to the CEG server are not valid !
	k_EResultRestrictedDevice = 82,				// The device being used is not allowed to perform this action
	k_EResultRegionLocked = 83,					// The action could not be complete because it is region restricted
	k_EResultRateLimitExceeded = 84,			// Temporary rate limit exceeded, try again later, different from k_EResultLimitExceeded which may be permanent
	k_EResultAccountLoginDeniedNeedTwoFactor = 85,	// Need two-factor code to login
	k_EResultItemDeleted = 86,					// The thing we're trying to access has been deleted
	k_EResultAccountLoginDeniedThrottle = 87,	// login attempt failed, try to throttle response to possible attacker
	k_EResultTwoFactorCodeMismatch = 88,		// two factor code mismatch
	k_EResultTwoFactorActivationCodeMismatch = 89,	// activation code for two-factor didn't match
	k_EResultAccountAssociatedToMultiplePartners = 90,	// account has been associated with multiple partners
	k_EResultNotModified = 91,					// data not modified
	k_EResultNoMobileDevice = 92,				// the account does not have a mobile device associated with it
	k_EResultTimeNotSynced = 93,				// the time presented is out of range or tolerance
	k_EResultSmsCodeFailed = 94,				// SMS code failure (no match, none pending, etc.)
	k_EResultAccountLimitExceeded = 95,			// Too many accounts access this resource
	k_EResultAccountActivityLimitExceeded = 96,	// Too many changes to this account
	k_EResultPhoneActivityLimitExceeded = 97,	// Too many changes to this phone
	k_EResultRefundToWallet = 98,				// Cannot refund to payment method, must use wallet
	k_EResultEmailSendFailure = 99,				// Cannot send an email
	k_EResultNotSettled = 100,					// Can't perform operation till payment has settled
	k_EResultNeedCaptcha = 101,					// Needs to provide a valid captcha
	k_EResultGSLTDenied = 102,					// a game server login token owned by this token's owner has been banned
	k_EResultGSOwnerDenied = 103,				// game server owner is denied for other reason (account lock, community ban, vac ban, missing phone)
	k_EResultInvalidItemType = 104				// the type of thing we were requested to act on is invalid
};

/* This enum is used in client API methods, do not re-number existing values. */
enum EHTTPMethod
{
	k_EHTTPMethodInvalid = 0,
	k_EHTTPMethodGET,
	k_EHTTPMethodHEAD,
	k_EHTTPMethodPOST,
	k_EHTTPMethodPUT,
	k_EHTTPMethodDELETE,
	k_EHTTPMethodOPTIONS,
	k_EHTTPMethodPATCH,

	// The remaining HTTP methods are not yet supported, per rfc2616 section 5.1.1 only GET and HEAD are required for 
	// a compliant general purpose server.  We'll likely add more as we find uses for them.

	// k_EHTTPMethodTRACE,
	// k_EHTTPMethodCONNECT
};


/* HTTP Status codes that the server can send in response to a request, see rfc2616 section 10.3 for descriptions
 of each of these. */
enum EHTTPStatusCode
{
	// Invalid status code (this isn't defined in HTTP, used to indicate unset in our code)
	k_EHTTPStatusCodeInvalid =					0,

	// Informational codes
	k_EHTTPStatusCode100Continue =				100,
	k_EHTTPStatusCode101SwitchingProtocols =	101,

	// Success codes
	k_EHTTPStatusCode200OK =					200,
	k_EHTTPStatusCode201Created =				201,
	k_EHTTPStatusCode202Accepted =				202,
	k_EHTTPStatusCode203NonAuthoritative =		203,
	k_EHTTPStatusCode204NoContent =				204,
	k_EHTTPStatusCode205ResetContent =			205,
	k_EHTTPStatusCode206PartialContent =		206,

	// Redirection codes
	k_EHTTPStatusCode300MultipleChoices =		300,
	k_EHTTPStatusCode301MovedPermanently =		301,
	k_EHTTPStatusCode302Found =					302,
	k_EHTTPStatusCode303SeeOther =				303,
	k_EHTTPStatusCode304NotModified =			304,
	k_EHTTPStatusCode305UseProxy =				305,
	//k_EHTTPStatusCode306Unused =				306, (used in old HTTP spec, now unused in 1.1)
	k_EHTTPStatusCode307TemporaryRedirect =		307,

	// Error codes
	k_EHTTPStatusCode400BadRequest =			400,
	k_EHTTPStatusCode401Unauthorized =			401, // You probably want 403 or something else. 401 implies you're sending a WWW-Authenticate header and the client can sent an Authorization header in response.
	k_EHTTPStatusCode402PaymentRequired =		402, // This is reserved for future HTTP specs, not really supported by clients
	k_EHTTPStatusCode403Forbidden =				403,
	k_EHTTPStatusCode404NotFound =				404,
	k_EHTTPStatusCode405MethodNotAllowed =		405,
	k_EHTTPStatusCode406NotAcceptable =			406,
	k_EHTTPStatusCode407ProxyAuthRequired =		407,
	k_EHTTPStatusCode408RequestTimeout =		408,
	k_EHTTPStatusCode409Conflict =				409,
	k_EHTTPStatusCode410Gone =					410,
	k_EHTTPStatusCode411LengthRequired =		411,
	k_EHTTPStatusCode412PreconditionFailed =	412,
	k_EHTTPStatusCode413RequestEntityTooLarge =	413,
	k_EHTTPStatusCode414RequestURITooLong =		414,
	k_EHTTPStatusCode415UnsupportedMediaType =	415,
	k_EHTTPStatusCode416RequestedRangeNotSatisfiable = 416,
	k_EHTTPStatusCode417ExpectationFailed =		417,
	k_EHTTPStatusCode4xxUnknown = 				418, // 418 is reserved, so we'll use it to mean unknown
	k_EHTTPStatusCode429TooManyRequests	=		429,

	// Server error codes
	k_EHTTPStatusCode500InternalServerError =	500,
	k_EHTTPStatusCode501NotImplemented =		501,
	k_EHTTPStatusCode502BadGateway =			502,
	k_EHTTPStatusCode503ServiceUnavailable =	503,
	k_EHTTPStatusCode504GatewayTimeout =		504,
	k_EHTTPStatusCode505HTTPVersionNotSupported = 505,
	k_EHTTPStatusCode5xxUnknown =				599,
};

/* list of possible return values from the ISteamGameCoordinator API */
enum EGCResults
{
	k_EGCResultOK = 0,
	k_EGCResultNoMessage = 1,			// There is no message in the queue
	k_EGCResultBufferTooSmall = 2,		// The buffer is too small for the requested message
	k_EGCResultNotLoggedOn = 3,			// The client is not logged onto Steam
	k_EGCResultInvalidMessage = 4,		// Something was wrong with the message being sent with SendMessage
};

native bool SteamWorks_IsVACEnabled();
native bool SteamWorks_GetPublicIP(int ipaddr[4]);
native int SteamWorks_GetPublicIPCell();
native bool SteamWorks_IsLoaded();
native bool SteamWorks_SetGameData(const char[] sData);
native bool SteamWorks_SetGameDescription(const char[] sDesc);
native bool SteamWorks_SetMapName(const char[] sMapName);
native bool SteamWorks_IsConnected();
native bool SteamWorks_SetRule(const char[] sKey, const char[] sValue);
native bool SteamWorks_ClearRules();
native bool SteamWorks_ForceHeartbeat();
native bool SteamWorks_GetUserGroupStatus(int client, int groupid);
native bool SteamWorks_GetUserGroupStatusAuthID(int authid, int groupid);

native EUserHasLicenseForAppResult SteamWorks_HasLicenseForApp(int client, int app);
native EUserHasLicenseForAppResult SteamWorks_HasLicenseForAppId(int authid, int app);
native int SteamWorks_GetClientSteamID(int client, char[] sSteamID, int length);

native bool SteamWorks_RequestStatsAuthID(int authid, int appid);
native bool SteamWorks_RequestStats(int client, int appid);
native bool SteamWorks_GetStatCell(int client, const char[] sKey, int& value);
native bool SteamWorks_GetStatAuthIDCell(int authid, const char[] sKey, int& value);
native bool SteamWorks_GetStatFloat(int client, const char[] sKey, float& value);
native bool SteamWorks_GetStatAuthIDFloat(int authid, const char[] sKey, float& value);

native Handle SteamWorks_CreateHTTPRequest(EHTTPMethod method, const char[] sUR);
native bool SteamWorks_SetHTTPRequestContextValue(Handle hHandle, any data1, any data2 = 0);
native bool SteamWorks_SetHTTPRequestNetworkActivityTimeout(Handle hHandle, int timeout);
native bool SteamWorks_SetHTTPRequestHeaderValue(Handle hHandle, const char[] sName, const char[] sValue);
native bool SteamWorks_SetHTTPRequestGetOrPostParameter(Handle hHandle, const char[] sName, const char[] sValue);
native bool SteamWorks_SetHTTPRequestUserAgentInfo(Handle hHandle, const char[] sUserAgentInfo);
native bool SteamWorks_SetHTTPRequestRequiresVerifiedCertificate(Handle hHandle, bool bRequireVerifiedCertificate);
native bool SteamWorks_SetHTTPRequestAbsoluteTimeoutMS(Handle hHandle, int unMilliseconds);

#if SOURCEMOD_V_MAJOR >= 1 && SOURCEMOD_V_MINOR >= 9
typeset SteamWorksHTTPRequestCompleted
{
	function void (Handle hRequest, bool bFailure, bool bRequestSuccessful, EHTTPStatusCode eStatusCode);
	function void (Handle hRequest, bool bFailure, bool bRequestSuccessful, EHTTPStatusCode eStatusCode, any data1);
	function void (Handle hRequest, bool bFailure, bool bRequestSuccessful, EHTTPStatusCode eStatusCode, any data1, any data2);
};

typeset SteamWorksHTTPHeadersReceived
{
	function void (Handle hRequest, bool bFailure);
	function void (Handle hRequest, bool bFailure, any data1);
	function void (Handle hRequest, bool bFailure, any data1, any data2);
};

typeset SteamWorksHTTPDataReceived
{
	function void (Handle hRequest, bool bFailure, int offset, int bytesreceived);
	function void (Handle hRequest, bool bFailure, int offset, int bytesreceived, any data1);
	function void (Handle hRequest, bool bFailure, int offset, int bytesreceived, any data1, any data2);
};

typeset SteamWorksHTTPBodyCallback
{
	function void (const char sData[]);
	function void (const char sData[], any value);
	function void (const int data[], any value, int datalen);
};

#else

funcenum SteamWorksHTTPRequestCompleted
{
	public(Handle hRequest, bool bFailure, bool bRequestSuccessful, EHTTPStatusCode eStatusCode),
	public(Handle hRequest, bool bFailure, bool bRequestSuccessful, EHTTPStatusCode eStatusCode, any data1),
	public(Handle hRequest, bool bFailure, bool bRequestSuccessful, EHTTPStatusCode eStatusCode, any data1, any data2)
};

funcenum SteamWorksHTTPHeadersReceived
{
	public(Handle hRequest, bool bFailure),
	public(Handle hRequest, bool bFailure, any data1),
	public(Handle hRequest, bool bFailure, any data1, any data2)
};

funcenum SteamWorksHTTPDataReceived
{
	public(Handle hRequest, bool bFailure, int offset, int bytesreceived),
	public(Handle hRequest, bool bFailure, int offset, int bytesreceived, any data1),
	public(Handle hRequest, bool bFailure, int offset, int bytesreceived, any data1, any data2)
};

funcenum SteamWorksHTTPBodyCallback
{
	public(const char[] sData),
	public(const char[] sData, any value),
	public(const int data[], any value, int datalen)
};

#endif

native bool SteamWorks_SetHTTPCallbacks(Handle hHandle, SteamWorksHTTPRequestCompleted fCompleted = INVALID_FUNCTION, SteamWorksHTTPHeadersReceived fHeaders = INVALID_FUNCTION, SteamWorksHTTPDataReceived fData = INVALID_FUNCTION, Handle hCalling = null);
native bool SteamWorks_SendHTTPRequest(Handle hRequest);
native bool SteamWorks_SendHTTPRequestAndStreamResponse(Handle hRequest);
native bool SteamWorks_DeferHTTPRequest(Handle hRequest);
native bool SteamWorks_PrioritizeHTTPRequest(Handle hRequest);
native bool SteamWorks_GetHTTPResponseHeaderSize(Handle hRequest, const char[] sHeader, int& size);
native bool SteamWorks_GetHTTPResponseHeaderValue(Handle hRequest, const char[] sHeader, char[] sValue, int size);
native bool SteamWorks_GetHTTPResponseBodySize(Handle hRequest, int& size);
native bool SteamWorks_GetHTTPResponseBodyData(Handle hRequest, char[] sBody, int length);
native bool SteamWorks_GetHTTPStreamingResponseBodyData(Handle hRequest, int cOffset, char[] sBody, int length);
native bool SteamWorks_GetHTTPDownloadProgressPct(Handle hRequest, float& percent);
native bool SteamWorks_GetHTTPRequestWasTimedOut(Handle hRequest, bool& bWasTimedOut);
native bool SteamWorks_SetHTTPRequestRawPostBody(Handle hRequest, const char[] sContentType, const char[] sBody, int bodylen);
native bool SteamWorks_SetHTTPRequestRawPostBodyFromFile(Handle hRequest, const char[] sContentType, const char[] sFileName);

native bool SteamWorks_GetHTTPResponseBodyCallback(Handle hRequest, SteamWorksHTTPBodyCallback fCallback, any data = 0, Handle hPlugin = null); /* Look up, moved definition for 1.7+ compat. */
native bool SteamWorks_WriteHTTPResponseBodyToFile(Handle hRequest, const char[] sFileName);

forward int SW_OnValidateClient(int ownerauthid, int authid);
forward int SteamWorks_OnValidateClient(int ownerauthid, int authid);
forward int SteamWorks_SteamServersConnected();
forward int SteamWorks_SteamServersConnectFailure(EResult result);
forward int SteamWorks_SteamServersDisconnected(EResult result);

forward Action SteamWorks_RestartRequested();
forward int SteamWorks_TokenRequested(char[] sToken, int maxlen);

forward int SteamWorks_OnClientGroupStatus(int authid, int groupid, bool isMember, bool isOfficer);

forward EGCResults SteamWorks_GCSendMessage(int unMsgType, const char[] pubData, int cubData);
forward int SteamWorks_GCMsgAvailable(int cubData);
forward EGCResults SteamWorks_GCRetrieveMessage(int punMsgType, const char[] pubDest, int cubDest, int pcubMsgSize);

native EGCResults SteamWorks_SendMessageToGC(int unMsgType, const char[] pubData, int cubData);

public Extension __ext_SteamWorks = 
{
	name = "SteamWorks",
	file = "SteamWorks.ext",
#if defined AUTOLOAD_EXTENSIONS
	autoload = 1,
#else
	autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
	required = 1,
#else
	required = 0,
#endif
};

#if !defined REQUIRE_EXTENSIONS
public __ext_SteamWorks_SetNTVOptional()
{
	MarkNativeAsOptional("SteamWorks_IsVACEnabled");
	MarkNativeAsOptional("SteamWorks_GetPublicIP");
	MarkNativeAsOptional("SteamWorks_GetPublicIPCell");
	MarkNativeAsOptional("SteamWorks_IsLoaded");
	MarkNativeAsOptional("SteamWorks_SetGameData");
	MarkNativeAsOptional("SteamWorks_SetGameDescription");
	MarkNativeAsOptional("SteamWorks_IsConnected");
	MarkNativeAsOptional("SteamWorks_SetRule");
	MarkNativeAsOptional("SteamWorks_ClearRules");
	MarkNativeAsOptional("SteamWorks_ForceHeartbeat");
	MarkNativeAsOptional("SteamWorks_GetUserGroupStatus");
	MarkNativeAsOptional("SteamWorks_GetUserGroupStatusAuthID");

	MarkNativeAsOptional("SteamWorks_HasLicenseForApp");
	MarkNativeAsOptional("SteamWorks_HasLicenseForAppId");
	MarkNativeAsOptional("SteamWorks_GetClientSteamID");

	MarkNativeAsOptional("SteamWorks_RequestStatsAuthID");
	MarkNativeAsOptional("SteamWorks_RequestStats");
	MarkNativeAsOptional("SteamWorks_GetStatCell");
	MarkNativeAsOptional("SteamWorks_GetStatAuthIDCell");
	MarkNativeAsOptional("SteamWorks_GetStatFloat");
	MarkNativeAsOptional("SteamWorks_GetStatAuthIDFloat");

	MarkNativeAsOptional("SteamWorks_SendMessageToGC");

	MarkNativeAsOptional("SteamWorks_CreateHTTPRequest");
	MarkNativeAsOptional("SteamWorks_SetHTTPRequestContextValue");
	MarkNativeAsOptional("SteamWorks_SetHTTPRequestNetworkActivityTimeout");
	MarkNativeAsOptional("SteamWorks_SetHTTPRequestHeaderValue");
	MarkNativeAsOptional("SteamWorks_SetHTTPRequestGetOrPostParameter");

	MarkNativeAsOptional("SteamWorks_SetHTTPCallbacks");
	MarkNativeAsOptional("SteamWorks_SendHTTPRequest");
	MarkNativeAsOptional("SteamWorks_SendHTTPRequestAndStreamResponse");
	MarkNativeAsOptional("SteamWorks_DeferHTTPRequest");
	MarkNativeAsOptional("SteamWorks_PrioritizeHTTPRequest");
	MarkNativeAsOptional("SteamWorks_GetHTTPResponseHeaderSize");
	MarkNativeAsOptional("SteamWorks_GetHTTPResponseHeaderValue");
	MarkNativeAsOptional("SteamWorks_GetHTTPResponseBodySize");
	MarkNativeAsOptional("SteamWorks_GetHTTPResponseBodyData");
	MarkNativeAsOptional("SteamWorks_GetHTTPStreamingResponseBodyData");
	MarkNativeAsOptional("SteamWorks_GetHTTPDownloadProgressPct");
	MarkNativeAsOptional("SteamWorks_SetHTTPRequestRawPostBody");
	MarkNativeAsOptional("SteamWorks_SetHTTPRequestRawPostBodyFromFile");

	MarkNativeAsOptional("SteamWorks_GetHTTPResponseBodyCallback");
	MarkNativeAsOptional("SteamWorks_WriteHTTPResponseBodyToFile");
}
#endif
