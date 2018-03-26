/*
 *    MCCMerchant.h
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

#import <UIKit/UIKit.h>
/**
 * Project version number for MCCMerchant.
 */
FOUNDATION_EXPORT double MCCMerchantVersionNumber;

/**
 * Project version string for MCCMerchant.
 */
FOUNDATION_EXPORT const unsigned char MCCMerchantVersionString[];

#import <MCCMerchant/MCCErrors.h>
#import <MCCMerchant/MCCMerchant.h>
#import <MCCMerchant/MCCMerchantConstants.h>
#import <MCCMerchant/MCCMasterpassButton.h>
#import <MCCMerchant/MCCCheckoutRequest.h>
#import <MCCMerchant/MCCCheckoutResponse.h>
#import <MCCMerchant/MCCConfiguration.h>
#import <MCCMerchant/MCCMerchantDelegate.h>
#import <MCCMerchant/MCCBlocks.h>

/**
 MCCMerchant class provides a centralized point of control and coordination for merchant apps integrating with the Masterpass Merchant SDK.
 
 Overview:
 
 This class provides APIs to perform following tasks:
 
 1. To initialize Merchant SDK
 
 2. To get "Pay With Masterpass" button
 
 3. To pass the callback provided through CustomURL Scheme
 
  @Note Do not subclass MCCMerchant.
 */

@interface MCCMerchant : NSObject

/**
 *  Expose the Merchant SDK for configuration from the client. This method is required to initialize the framework.
 *
 *  @param configuration MCCConfiguration object passed by the merchant application
 *  @param status Status callback handler
 *
 *  @Note As a best practices, it is advisable to initialize the framework in didFinishLaunchingWithOptions: app delegate method. It is advisable to provide all values of configuration for better user experience. If an optional parameter is provided in configuration then the SDK validation on the value will be performed.
 *
 */
+ (void) initializeSDKWithConfiguration:(MCCConfiguration *_Nonnull)configuration onStatusBlock:(void(^ __nonnull) (NSDictionary * __nonnull status, NSError * __nullable error))status;

/**
 *  This method will handle customURL scheme callback based on the URL string provided. This check for validility of return URL. It will return false in case of URL callback is not for Masterpass merchant SDK.
 *  @param url URLscheme NSString object
 *  @param merchantDelegate Merchant delegate object to facilitate communication between MCCMerchant SDK and Merchant application
 *
 *  @return True if it is masterpass request otherwise return false.
 */
+ (BOOL) handleMasterpassResponse:(NSString *_Nonnull)url delegate: (id<MCCMerchantDelegate> _Nonnull) merchantDelegate;

#pragma mark -
#pragma mark Checkout Options

/**
 *  Provides "Buy with MasterPass" button UI object that will be rendered on Merchant's user interface view. This method creates the object of MCCMasterpassButton if SDK is successfully initialized, otherwise returns nil.
 *
 *  @param merchantDelegate Merchant delegate object to facilitate communication between MCCMerchant SDK and Merchant application
 *
 *  @Note MCCMasterpassButton is subclass of UIButton
 
 *  @return An instance of MCCMasterpassButton
 */

+ (MCCMasterpassButton * _Nullable) getMasterPassButton:(id<MCCMerchantDelegate> _Nonnull) merchantDelegate;


/**
 * This method initiates Masterpass express checkout pairing to retrieve pairingTransactionId.
 *
 * @param isCheckout boolean, check if express pairing initiate with/without checkout flow
 *
 * @param merchantDelegate Merchant delegate object to facilitate communication between MCCMerchant SDK and Merchant application
 *
 */
+ (void) pairingWithCheckout:(BOOL)isCheckout merchantDelegate:(id<MCCMerchantDelegate> _Nonnull) merchantDelegate;

@end
