/*
 *    MCCPaymentDetails.h
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
#import "MCCAmount.h"
#import "MCCCryptogram.h"
#import "MCCCardType.h"

/**
 Represents the details required by a single Masterpass transaction. The developer needs to create an instance of this class with valid values & provide it when "Buy With MasterPass" button is clicked.
 */

@interface MCCCheckoutRequest : NSObject

///This property contains checkout id of merchant
@property (nonatomic, strong, nonnull) NSString* checkoutId;

///This property constrains the merchant supported payment network types that the user can select for transaction being performed. MasterCard, Visa etc...
@property (nonatomic, strong, nonnull) NSSet<MCCCardType *>* allowedCardTypes;

///This property constrains totoal and currencyCode.
@property (nonatomic, strong, nonnull) MCCAmount *amount;

///Cart ID. A dynamic identifier fetched from merchant app to identify each checkout.
@property (nonatomic, strong, nonnull) NSString *cartId;

///This property holds supported Cryptogram Type by merchant. The possible values are ICC or MCHIP or both.
@property (nonatomic, strong, nonnull) MCCCryptogram *cryptogramType;

///The property constrains the locations that the merchant can ship the product. If null, 'default' profile id will be used
///For Web checkout - shippingLocationProfiles
@property (nonatomic, strong, nullable) NSString *shippingProfileId;

///This property identifies item need to be shipped or not. There are products which does not require shipping, for example, online music or ebooks.
///For Web checkout - suppressShippingAddress
@property (nonatomic, assign) BOOL isShippingRequired;

///The property used to describe the locale supported by merchant
@property (nonatomic, strong) NSString * _Nullable merchantLocale;

/**
 * Web checkout specific extra optional parameters.
 */

/// The property used to describe the state of 3DS required.
@property (nonatomic, assign) BOOL suppress3DS;

/// The property used to describe the the unpredictableNumber, can be merchant generated or service generated
/// Optional for FPAN Transaction
@property (nonatomic, strong, nullable) NSString *unpredictableNumber;

///The property used to describe the the amountPending
@property (nonatomic, strong, nullable) NSDecimalNumber* amountPending;

///The property used to describe the the extentionPoint
@property (nonatomic, strong, nullable) NSDictionary* extentionPoint;

///The property used for express checkout
@property (nonatomic, strong, nonnull) NSString *userId;

@end
