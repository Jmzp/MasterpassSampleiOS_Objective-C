/*
 *    MCCMerchantConstants.h
 *    MCCMerchant
 *
 * 	  Copyright © 2015-2017, Mastercard International Incorporated and/or its
 *    affiliates. All rights reserved.
 *
 *    TO THE EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS", WITHOUT
 *    WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 *    WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *    NON INFRINGEMENT. TO THE EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 *    MASTERCARD OR ITS AFFILIATES BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 *    IN THE SOFTWARE.
 *
 */
#import <Foundation/Foundation.h>

#ifndef MCCMerchantConstants_h
#define MCCMerchantConstants_h

/**
 * Constant for open URL notification name
 *
 * Merchant app needs to post this notification from AppDelegate method-
 *
 * func application(app: UIApplication, openURL url: NSURL, options: [String : AnyObject]) -> Bool
 */
extern NSString *const kOpenURLNotification;

/// Key name for notification userInfo dictionary which contains URL received in openURL AppDelegate method
extern NSString *const kURLKey;

/// Key name for Initialization state status in initialization status callback, to be used by Wallet App and Wallet SDK
extern NSString *const kInitializeStateKey;

/// Transaction Response Dictionary Keys
extern NSString * const kTransactionResponseStatusKey;
extern NSString * const kTransactionResponseOperationNameKey;
extern NSString * const kTransactionResponseRequestTokenKey;
extern NSString * const kTransactionResponseErrorMessageKey;
extern NSString * const kTransactionResponseCheckoutIdKey;
extern NSString * const kTransactionResponseVerifierTokenKey;
extern NSString * const kTransactionResponseSuccessStatus;
extern NSString * const kTransactionResponseFailStatus;

/// Extension Point key
extern NSString * const kAllowedShipToCountries;

/// merchant URL scheme
extern NSString * const kMerchantUrlScheme;

/**
 * This enumeration defines various initialization states of Merchant SDK
 */
typedef NS_ENUM(NSInteger, MCCInitializationState) {
    
    /// Initialization process status as started
    MCCInitializationStateStarted = 1,
    
    /// Initialization process status as completed
    MCCInitializationStateCompleted = 2,
    
    ///Configuration fails
    MCCInitializationStateFail = 3
};

/**
 *  This enumerations define types of specific Cryptogram type
 */
typedef NS_ENUM (NSInteger, MCCCryptogramType) {
    
    MCCCryptogramICC,
    MCCCryptogramUCAF,
    MCCCryptogramUCAFAndICC,
    MCCCryptogramNone
};

/**
 *  This enumerations define types of specific card type
 */
typedef NS_ENUM (NSInteger, MCCCard) {
    
    MCCCardMASTER,
    MCCCardVISA,
    MCCCardAMEX,
    MCCCardDISCOVER,
    MCCCardDINERS
};

/**
 *  Enumeration define the list of supported Masterpass merchant SDK response type.
 */
typedef NS_ENUM(NSInteger, MCCMerchantCheckoutResponse) {
    
    MCCMerchantCheckoutResponseUnrecognized = -1,
    MCCMerchantCheckoutResponseWebCheckout = 0,
    MCCMerchantCheckoutResponseError = 1,
};

/**
 * This enumeration defines the type of response type for MCCCheckoutResponse object
 */
typedef NS_ENUM(NSInteger, MCCResponseType)
{
    MCCResponseTypeWebCheckout                  = 2,
    MCCResponseTypePairing                      = 3,
    MCCResponseTypePairingWithCheckout          = 4
    
};

/**
 *  This enumerations define types of Web Checkout
 */

typedef NS_ENUM(NSInteger, MCCWebCheckoutType)
{
    MCCWebCheckoutOnly              = 1001,
    MCCWebPairingOnly               = 1002,
    MCCWebCheckoutWithPairing       = 1003
};

#endif /* MCCMerchantConstants_h */
