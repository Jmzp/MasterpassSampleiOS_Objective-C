/*
 *	  MCCConfiguration.h
 *	  MCCMerchant
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
#import "MCCMerchantConstants.h"

/**
 
 Overview:
 
 MCCConfiguration is a model that represents the framework configuration passed by the client app to the framework.
 
 Subclassing Notes:
 
 Do not subclass MCCConfiguration.
 
 */

@interface MCCConfiguration : NSObject

/**
 * (Dis)Enables Analytics for the session
 */
@property (nonatomic, assign) BOOL enableAnalytics;


/**
 *  The merchant URL scheme as redirect address Only the protocol part of the URLScheme
 *  is expected, the framework will do necessary formatting as required.
 *  For example, in "http://mydomain.com", "http" is the protocol, the framework will 
 *  add "://" etc... while using the scheme.
 */
@property (nonatomic, copy, nonnull) NSString *merchantUrlScheme;

/**
 *	Locale Information
 */
@property (nonatomic, copy, nullable) NSLocale *locale;

/**
 *  Returns a string that describes the current configuration state.
 */
@property (nonatomic, readonly, copy) NSString * _Nonnull description;

@end
